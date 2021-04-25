#pragma once
#include <stdint.h>
#include "bmPwm.h"

#define BV(bit)		(1 << bit)

typedef enum adcPin {
	ADC_PIN_0 = 0,
	ADC_PIN_1,
	ADC_PIN_2,
	ADC_PIN_3,
	ADC_PIN_4,
	ADC_PIN_5
} ADCPin;

/*
Initializes the adc.
*/
void adcInit();

/*
    Read analog value from specified pin.
    pin takes value from 0 to 5 (all inclusive).
*/
uint8_t adcRead(ADCPin pin);

/*
    Write analog value (val) to specified pin (pin).
    This basically uses the pulse width modulation technique
    to generate analog value. Hence uses PWM enabled pin
    of atmega328 pin.

    pin is the PWM enabled pin.
    val is the duty cycle of PWM.
*/
void adcWrite(PWMPin pin, uint8_t val);
