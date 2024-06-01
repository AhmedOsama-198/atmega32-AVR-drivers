/*
 * timer0_pwm.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Ahmed
 */

#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_

#include "std_types.h"


/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/


/* defining PWM OC0 pin and port id */
#define TIMER0_PWM_PORT_ID		PORTB_ID
#define TIMER0_PWM_PIN_ID		PIN3_ID


/********************************************************************************/



/*******************************************************************************
 *                             Function Prototypes                             *
 *******************************************************************************/


/* function activates PWM mode in Timer0 with given duty cycle */
void PWM_Timer0_Start(uint8 duty_cycle);


/********************************************************************************/


#endif /* TIMER0_PWM_H_ */
