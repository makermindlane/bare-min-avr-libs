#include "bmAdc.h"
#include <avr/io.h>
#include <avr/interrupt.h>


extern void onAdcConversionComp();


void adcInit() {
	// Selects the reference voltage for adc and makes the result left adjusted
	// by setting ADLAR bit in register ADMUX.
	ADMUX |= BV(REFS0) | BV(ADLAR);
	// Enables the adc.
	// Enable the adc conversion complete interrupt.
	// Selects the prescaler for adc.
	ADCSRA |= BV(ADEN) | BV(ADIE) | BV(ADPS2) | BV(ADPS1) | BV(ADPS0);
}


void adcStart() {
	// This starts the adc conversion.
	ADCSRA |= BV(ADSC);
}


void adcSetReadPin(uint8_t pin) {
	// Check if the pin is between 0 and 5
	if (pin >= 0 && pin <= 5) {
		// Select the appropriate adc pin by setting appropriate bits in ADMUX register.
		ADMUX |= pin;
		// Disable the digital input function of the adc pin to reduce the power and
		// potential adc reading corruption.
		DIDR0 |= BV(pin);
		// Start the adc conversion.
		ADCSRA |= BV(ADSC);
	}
}

/*
Interrupt service routine to be executed when adc conversion is completed.
NOTE: Putting function inside ISR is generally not recommended.
*/
ISR(ADC_vect)  {
	onAdcConversionComp();
}