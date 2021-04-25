#pragma once
#include <stdint.h>

typedef enum pwmPin {
	PWM_PD6 = 1,
	PWM_PD5,
	PWM_PB1,
	PWM_PB2,
	PWM_PB3,
	PWM_PD3
} PWMPin;

/*
	Configure the PWM for specified pin.
*/
void pwmConfig(PWMPin pin);


/*
	Sets the duty cycle of PWM.
*/
void pwmWrite(PWMPin pin, uint8_t dutyCycle);
