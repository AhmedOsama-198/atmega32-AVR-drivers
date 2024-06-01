/******************************************************************************
 *
 * Module: LM35 SENSOR
 *
 * File Name: lm35_sensor.h
 *
 * Description: Header file for the AVR LM35 SENSOR driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/* include adc.h to define the sensor's channel pin*/
#include "adc.h"



/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/


/* sensor channel pin_id */
#define SENSOR_CHANNEL_ID         ADC2

#define SENSOR_MAX_VOLT_VALUE     1.5

#define SENSOR_MAX_TEMPERATURE    150


/*******************************************************************************/



/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/


/*function that calculate the tempreture using 
 * the correct formula and return it to main() */
uint8 LM35_getTempreture(void);


/********************************************************************************/



#endif /* LM35_SENSOR_H_ */
