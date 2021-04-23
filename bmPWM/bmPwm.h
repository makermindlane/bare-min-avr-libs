#pragma once
#include <stdint.h>

/*
	Configure the PWM for specified pin.
*/
void pwmConfig(uint8_t pin);

/*
	Sets the duty cycle for PWM.
*/
void pwmSetDutyCycle(uint8_t val);
