#include <avr/io.h>
#include "bmAdc.h"
#include "bmPwm.h"


void adcInit() {
	// Selects the reference voltage for adc and makes the result left adjusted
	// by setting ADLAR bit in register ADMUX.
	ADMUX |= BV(REFS0) | BV(ADLAR);
	// Enables the adc.
	// Selects the prescaler for adc.
	ADCSRA |= BV(ADEN) | BV(ADPS2) | BV(ADPS1) | BV(ADPS0);
}


uint8_t adcRead(ADCPin pin) {
	// Check if the pin is between 0 and 5
	if (pin >= ADC_PIN_0 && pin <= ADC_PIN_5) {
		// Select the appropriate adc pin by setting appropriate bits in ADMUX register.
		ADMUX |= pin;
		// Disable the digital input function of the adc pin to reduce the power and
		// potential adc reading corruption.
		DIDR0 |= BV(pin);
		// Start the adc conversion.
		ADCSRA |= BV(ADSC);
		// Waiting until the current adc conversion completes.
		// ADSC bit is 1 as long as the conversion is ongoing and becomes 0 on completion.
		while (ADCSRA & BV(ADSC));
		// Return the adc result.
		return ADCH;
	}

	return 0;
}


void adcWrite(PWMPin pin, uint8_t val) {
	// Configure the PWM for specified pin.
	pwmWrite(pin, val);
}