#include "bmPwm.h"
#include <avr/interrupt.h>

/*
	Prescaler values for timer/counter clock select.
*/
// static typedef enum PwmPrescaler {
// 	PS_NO = 1, 
// 	PS_8, 
// 	PS_64, 
// 	PS_256, 
// 	PS_1024
// } PwmPrescaler;


// static void setPrescaler(PwmPrescaler psv);


// static void setPrescaler(PwmPrescaler psv) {
// 	switch (psv) {
// 		case PS_NO:
// 			TCCR0B |= PS_NO;
// 			break;
// 		case PS_8:
// 			TCCR0B |= PS_8;
// 			break;
// 		case PS_64:
// 			TCCR0B |= PS_64;
// 			break;
// 		case PS_256:
// 			TCCR0B |= PS_256;
// 			break;
// 		case PS_1024:
// 			TCCR0B |= PS_1024;
// 			break;
// 		default:
// 			TCCR0B = PS_8;
// 			break;
// 	}
// }


void pwmConfig(PWMPin pin, uint8_t dutyCycle) {

	switch (pin) {
		case PWM_PD6: {
			// Set the Port D pin 6 as output.
			DDRD |= (1 << PORTD6);
			// Set OC0A pin on compare match, clear OC0A pin at BOTTOM (minimum value of
			// Timer/counter A.
			// See Section 14.7.3 "Fast PWM Mode" on page 80 for more details.
			TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
			TCCR0B |= (1 << CS01);

			OCR0A = dutyCycle;
		}
		break;
		case PWM_PD5: {
			DDRD |= (1 << PORTD5);
			TCCR0A |= (1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00);
			TCCR0B |= (1 << CS01);

			OCR0B |= dutyCycle;
		}
		break;
		case PWM_PB1: {
			DDRB |= (1 << PORTB1);
			TCCR1A |= (1 << COM1A1) | (1 << COM1A0) | (1 << WGM10);
			TCCR1B |= (1 << WGM12) | (1 << CS11);

			OCR1AH = 0;
			OCR1AL = dutyCycle;
		}
		break;
		case PWM_PB2: {
			DDRB |= (1 << PORTB2);
			TCCR1A |= (1 << COM1B1) | (1 << COM1B0) | (1 << WGM10);
			TCCR1B |= (1 << WGM12) | (1 << CS11);

			OCR1BH = 0;
			OCR1BL = dutyCycle;
		}
		break;
		case PWM_PB3: {
			DDRB |= (1 << PORTB3);
			TCCR2A |= (1 << COM2A1) | (1 << COM2A0) | (1 << WGM21) | (1 << WGM20);
			TCCR2B |= (1 << CS21);

			OCR2A = dutyCycle;
		}
		break;
		case PWM_PD3: {
			DDRD |= (1 << PORTD3);
			TCCR2A |= (1 << COM2B1) | (1 << COM2B0) | (1 << WGM21) | (1 << WGM20);
			TCCR2B |= (1 << CS21);

			OCR2B = dutyCycle;
		}
		break;
		default:
		break;
	}
	// // Set the Port D pin 6 as output.
	// DDRD |= (1 << pin);
	// // Set OC0A pin on compare match, clear OC0A pin at BOTTOM (minimum value of
	// // Timer/counter A.
	// // See Section 14.7.3 "Fast PWM Mode" on page 80 for more details.
	// TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
	// // select clock source. Default with prescaler 8.
	// // Prescaler is nothing but the number to divide the clock with, a divisor.
	// setPrescaler(PS_8);
}


// void pwmSetDutyCycle(uint8_t val) {
// 	// Writing this value sets the duty cycle for PWM.
// 	OCR0A = val;
// }
