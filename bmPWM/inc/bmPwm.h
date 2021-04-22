#pragma once

/*
	Prescaler values for timer/counter clock select.
*/
typedef enum PwmPrescaler {
	PS_NO = 1, 
	PS_8, 
	PS_64, 
	PS_256, 
	PS_1024
} PwmPrescaler;

/*
	Initializes the PWM control register to select fast PWM mode and wave generation.
	Enables the timer overflow interrupt.
*/
void pwmInit(PwmPrescaler psv);
