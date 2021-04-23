#include "bmPwm.h"
#include <avr/interrupt.h>

/*
	Prescaler values for timer/counter clock select.
*/
static typedef enum PwmPrescaler {
	PS_NO = 1, 
	PS_8, 
	PS_64, 
	PS_256, 
	PS_1024
} PwmPrescaler;


static void setPrescaler(PwmPrescaler psv);


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


void pwmConfig(uint8_t pin) {
	// Set the Port D pin 6 as output.
	DDRD |= (1 << pin);
	// Set OC0A pin on compare match, clear OC0A pin at BOTTOM (minimum value of
	// Timer/counter A.
	// See Section 14.7.3 "Fast PWM Mode" on page 80 for more details.
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
	// select clock source. Default with prescaler 8.
	// Prescaler is nothing but the number to divide the clock with, a divisor.
	setPrescaler(PS_8);
}


void pwmSetDutyCycle(uint8_t val) {
	// Writing this value sets the duty cycle for PWM.
	OCR0A = val;
}
