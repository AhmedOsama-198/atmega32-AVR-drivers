/******************************************************************************
 *
 * Module: ULTRASONIC SENSOR
 *
 * File Name: ultrasonic_sensor.h
 *
 * Description: Header file for the ULTRASONIC SENSOR driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_


#include "std_types.h"


/*******************************************************************************
 *                                 Definitions                                 *
 *******************************************************************************/

/* defining sensor rising edge and prescaler */
#define US_SENSOR_ICU_STARTING_EDGE 	RISING_EDGE
#define US_SENSOR_ICU_PRESCALER			F_CPU_8

/* defining ultrasonic sensor echo port and pin id */
#define US_SENSOR_ECHO_PORT_ID			PORTD_ID
#define US_SENSOR_ECHO_PIN_ID			PIN6_ID

/* defining ultrasonic sensor trigger port and pin id */
#define US_SENSOR_TRIGGER_PORT_ID 		PORTB_ID
#define US_SENSOR_TRIGGER_PIN_ID 		PIN6_ID

/* defining ultrasonic sensor buzzer port and pin id */
#define US_SENSOR_BUZZER_PORT_ID		PORTB_ID
#define US_SENSOR_BUZZER_PIN_ID			PIN4_ID

/* defining buzzer/led condition as
 * to make it more configurable due to
 * postive / logic connection*/
#define US_BUZZER_ON					(1u)
#define US_BUZZER_OFF					(0u)


/*******************************************************************************/



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* enum to control trigger logic */
typedef enum
{
	NO_TRIGGER, TRIGGER
}US_TriggerType;


/*******************************************************************************/



/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/


/* function that trigger the trigger pin of
 * ultra sonic for 10us according to its datasheet */
void Ultrasonic_Trigger(void);

/* function that returns the value of
 * distance after calculation of ICU */
uint16 Ultrasonic_readDistance(void);

/* the call back function in control of calculating the distance */
void Ultrasonic_edgeProcessing(void);

/* function in control of alarm system */
void Ultrasonic_alarmSystem(void);


/*******************************************************************************/



#endif /* ULTRASONIC_SENSOR_H_ */
