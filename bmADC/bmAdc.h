#pragma once
#include <stdint.h>

#define BV(bit)		(1 << bit)

/*
Initializes the adc.
*/
void adcInit();

/*
    Read analog value from specified pin.
    pin takes value from 0 to 5 (all inclusive).
*/
uint8_t adcRead(uint8_t pin);

/*
    Write analog value (val) to specified pin (pin).
    This basically uses the pulse width modulation technique
    to generate analog value. Hence uses PWM enabled pin
    of atmega328 pin.

    pin is the PWM enabled pin.
    val is the duty cycle of PWM.
*/
void adcWrite(uint8_t pin, uint8_t val);
