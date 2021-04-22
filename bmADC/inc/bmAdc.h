#pragma once
#include <stdint.h>

#define BV(bit)		(1 << bit)

/*
Initializes the adc.
*/
void adcInit();

/*
Starts the adc conversion
*/
void adcStart();

/*
Selects the adc pin for input. pin = 0 to 5 (inclusive).
*/
void adcSetReadPin(uint8_t pin);
