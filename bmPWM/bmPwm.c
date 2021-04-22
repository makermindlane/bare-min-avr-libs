#include "bmPwm.h"
#include <avr/interrupt.h>


static void setPrescaler(PwmPrescaler psv);


/*
	This is a callback function which is expected to be implemented in main()
	function.
	NOTE: This function is not meant to be and should not be called by any code
	except ISR.
*/
extern void onTimerOverflowIntt();


void pwmInit(PwmPrescaler psv) {
	// Set the Port D pin 6 as output.
	DDRD |= (1 << PORTD6);
	// Set OC0A pin on compare match, clear OC0A pin at BOTTOM (minimum value of 
	// Timer/counter A.
	// See Section 14.7.3 "Fast PWM Mode" on page 80 for more details.
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
	// select clock source. Default with prescaler 8. 
	// Prescaler is nothing but the number to divide the clock with, a divisor.
	setPrescaler(psv);
	// enable timer/counter0 overflow interrupt
	TIMSK0 |= (1 << TOIE0);
}


static void setPrescaler(PwmPrescaler psv) {
	switch (psv) {
		case PS_NO:
			TCCR0B |= PS_NO;
			break;
		case PS_8:
			TCCR0B |= PS_8;
			break;
		case PS_64:
			TCCR0B |= PS_64;
			break;
		case PS_256:
			TCCR0B |= PS_256;
			break;
		case PS_1024:
			TCCR0B |= PS_1024;
			break;
		default:
			TCCR0B = PS_8;
			break;
	}
}

/*
	Interrupt service routine to be executed on timer overflow interrupt.
	NOTE:	Here a function call is made inside the ISR which generally is
	not recommended.
*/
ISR(TIMER0_OVF_vect) {
	onTimerOverflowIntt();
}
