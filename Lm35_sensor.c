/******************************************************************************
 *
 * Module: LM35_SENSOR
 *
 * File Name: lm35_sensor.c
 *
 * Description: Source file for the AVR LM35_SENSOR driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#include "Lm35_sensor.h"


uint8 LM35_getTempreture(void)
{
	uint8 temp_value = 0; /* variable to store tempreture value8 */
	uint16 adc_value = ADC_readChannel(SENSOR_CHANNEL_ID); /* variable to store converted value */

	/* calculations required to get tempreture value from Analog to Digital converted value */
	temp_value=(uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REFRENCE_VOLTAGE)/(SENSOR_MAX_VOLT_VALUE*1023));

	return temp_value;
}
