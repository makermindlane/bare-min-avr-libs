#include "bmPwm.h"
#include <avr/interrupt.h>


void pwmConfig(PWMPin pin) {

	switch (pin) {
		case PWM_PD6: {
			// Set the Port D pin 6 as output.
			DDRD |= (1 << PORTD6);
			// Selects pin PORTD6 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM01) | (1 << WGM00);
			// Selects the prescaler (clk / 8);
			TCCR0B |= (1 << CS01);
		}
		break;
		case PWM_PD5: {
			// Set the port D pin 5 as output.
			DDRD |= (1 << PORTD5);
			// Selects the PORTD5 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR0A |= (1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00);
			// Selects the prescaler (clk / 8);
			TCCR0B |= (1 << CS01);
		}
		break;
		case PWM_PB1: {
			// Set the port B pin 1 as output.
			DDRB |= (1 << PORTB1);
			// Selects the PORTB1 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR1A |= (1 << COM1A1) | (1 << COM1A0) | (1 << WGM10);
			// WGM12 is the bit required to be set for fast PWM mode to be enabled.
			// Selects the prescaler (clk / 8);
			TCCR1B |= (1 << WGM12) | (1 << CS11);
		}
		break;
		case PWM_PB2: {
			// Set the port B pin 2 as output.
			DDRB |= (1 << PORTB2);
			// Selects the PORTB2 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR1A |= (1 << COM1B1) | (1 << COM1B0) | (1 << WGM10);
			// WGM12 is the bit required to be set for fast PWM mode to be enabled.
			// Selects the prescaler (clk / 8);
			TCCR1B |= (1 << WGM12) | (1 << CS11);
		}
		break;
		case PWM_PB3: {
			// Set the port B pin 2 as output.
			DDRB |= (1 << PORTB3);
			// Selects the PORTB3 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR2A |= (1 << COM2A1) | (1 << COM2A0) | (1 << WGM21) | (1 << WGM20);
			// Selects the prescaler (clk / 8);
			TCCR2B |= (1 << CS21);
		}
		break;
		case PWM_PD3: {
			// Set the port B pin 2 as output.
			DDRD |= (1 << PORTD3);
			// Selects the PORTD3 pin for PWM output.
			// Sets wave generation mode in fast PWM mode.
			TCCR2A |= (1 << COM2B1) | (1 << COM2B0) | (1 << WGM21) | (1 << WGM20);
			// Selects the prescaler (clk / 8);
			TCCR2B |= (1 << CS21);
		}
		break;
		default:
		break;
	}
}


void pwmWrite(PWMPin pin, uint8_t dutyCycle) {
	switch (pin) {
		case PWM_PD6: 
			OCR0A = dutyCycle;
		break;
		case PWM_PD5:
			OCR0B = dutyCycle;
		break;
		case PWM_PB1;
			OCR1AH = 0;
			OCR1AL = dutyCycle;
		break;
		case PWM_PB2:
			OCR1BH = 0;
			OCR1BL = dutyCycle;
		break;
		case PWM_PB3:
			OCR2A = dutyCycle;
		break;
		case PWM_PD3:
			OCR2B = dutyCycle;
		break;
		default:
		break;
	}
}
