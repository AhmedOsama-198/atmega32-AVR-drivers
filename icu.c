/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.c
 *
 * Description: Source file for the AVR ICU driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#include "icu.h"
#include "avr_registers.h"
#include <avr/interrupt.h>
#include "gpio.h"



/* pointer variable to store the address of the call back function */
static volatile void(*g_callBackPtr)(void) = NULL_PTR;


ISR(TIMER1_CAPT_vect)
{
	/* error checking if the call back function is not set */
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();		/* calling call back function */
	}
}


void ICU_init(const ICU_configure_type *config)
{
	/* setup icu pin as input pin */
	GPIO_setupPinDirection(ICU_PIN_PORT_ID, ICU_PIN_ID, PIN_INPUT);

	/* clearing TIMER1 registers to ensure
	 * correct TIMER1 configuration */
	TCCR1A_REG.Byte = 0;
	TCCR1B_REG.Byte = 0;

	/* setting FOC1A/B as timer1 operating non-PWM mode */
	TCCR1A_REG.Bits.FOC1A_bit = 1;
	TCCR1A_REG.Bits.FOC1B_bit = 1;

	/* confguring edge select in input capture mode */
	TCCR1B_REG.Bits.ICES1_bit = config -> edge;

	/* cofigure prescaler clock select */
	TCCR1B_REG.Byte = (TCCR1B_REG.Byte & 0b11111000) | ((config -> clock) & 0b00000111);

	/* clearing TIMER1 counter and Input capture register */
	TCNT1_REG.Byte = 0;
	ICR1_REG.Byte = 0;

	/* enabling TIMER1 interrupt with input capture mode */
	TIMSK_REG.Bits.TICIE1_bit = 1;
}


void ICU_deinit(void)
{
	/* clearing all TIMER1 registers */
	TCCR1A_REG.Byte = 0;
	TCCR1B_REG.Byte = 0;
	TCNT1_REG.Byte = 0;
	ICR1_REG.Byte = 0;
	TIMSK_REG.Bits.TICIE1_bit = 0;

	/* resetting call back pointer to NULL */
	g_callBackPtr = NULL_PTR;
}


void ICU_clearClock(void)
{
	TCNT1_REG.Byte = 0;		/* clearing TIMER1 counter register */
}


void ICU_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;	/* setting the call back function */
}


void ICU_setEdgeDetectionType(const ICU_EDGE_TYPE edgeType)
{
	/* confguring edge select in input capture mode */
	TCCR1B_REG.Bits.ICES1_bit = edgeType;
}


uint16 ICU_getInputCaptureValue(void)
{
	return ICR1_REG.Byte;
}
