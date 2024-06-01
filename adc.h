/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/

/* defining the reference voltage of ADC */
#define ADC_REFRENCE_VOLTAGE	5

/* defining ADC channels port */
#define ADC_CHANNEL_PORT_ID		PORTA_ID

/* defining ADC channels pins */
#define ADC0	PIN0_ID
#define ADC1	PIN1_ID
#define ADC2	PIN2_ID
#define ADC3	PIN3_ID
#define ADC4	PIN4_ID
#define ADC5	PIN5_ID
#define ADC6	PIN6_ID
#define ADC7	PIN7_ID


/*******************************************************************************/



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


typedef enum
{
	AREF, AVCC, INTERNAL=3
}ADC_Voltage_Reference_Selection;


typedef enum
{
	FACT_2, FACT_4=2, FACT_8, FACT_16, FACT_32, FACT_64, FACT_128
}ADC_Prescaler_Select;


typedef struct
{
	ADC_Voltage_Reference_Selection Vref;
	ADC_Prescaler_Select Clock;
}ADC_Configure_Type;


/*******************************************************************************/



/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/

/* function that initialize ADC */
void ADC_init(ADC_Configure_Type*);

/* function that return the converted value on a specific ADC channel */
uint16 ADC_readChannel(uint8 ch_num);

/********************************************************************************/
#endif /* ADC_H_ */
