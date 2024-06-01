/*
 * timer.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"

typedef enum
{
	TIMER_0, TIMER_1, TIMER_2
}TIMER_SELECT;

typedef enum
{
	PWM, NO_PWM
}TIMER0_PWM;

typedef enum
{
	OVERFLOW, PWM_PHASE_CORRECT, CTC, FAST_PWM
}TIMER0_modeOfOperation;

typedef enum
{
	DISCONNECTED, TOGGLE, CLEAR, SET, NON_INVERTING = 2, INVERTING
}TIMER0_compreOutputMode;

typedef enum
{
	NO_CLOCK, PRESCALER_1, PRESCALER_8, PRESCALER_64, PRESCALER_256, PRESCALER_1024
}TIMER0_prescaler;

typedef enum
{
	TOIE0,OCIE0 = 2
}TIMER0_interrupt;

typedef struct
{
	TIMER0_PWM PWM_mode;
	TIMER0_modeOfOperation mode;
	TIMER0_compreOutputMode	compare_mode;
	TIMER0_prescaler prescaler;
	TIMER0_interrupt interrupt_mask;

	uint8 timerCounterRegister;
	uint8 outputCompareRegister;

}TIMER0_configType;


void TIMER0_init(TIMER0_configType *config);

#endif /* TIMER_H_ */
