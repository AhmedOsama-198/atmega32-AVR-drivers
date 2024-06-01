/******************************************************************************
 *
 * Module: ULTRASONIC SENSOR
 *
 * File Name: ultrasonic_sensor.c
 *
 * Description: Source file for the ULTRASONIC SENSOR driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#include "ultrasonic_sensor.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>


/* variable that stores the distance after being calculated */
uint16 US_distance = 0;


/* function that calibrates and fixes error in reading */
static void Ultrasonic_errorChecking(void)
{
	if(US_distance <= 56)
	{
		US_distance += 1;
	}
	else if(US_distance <= 127)
	{
		US_distance += 2;
	}
	else if(US_distance <= 200)
	{
		US_distance += 3;
	}
	else if(US_distance <= 268)
	{
		US_distance += 4;
	}
	else if(US_distance <= 338)
	{
		US_distance += 5;
	}
	else if(US_distance <= 410)
	{
		US_distance += 6;
	}
	else if(US_distance <= 431)
	{
		US_distance += 7;
	}
}


/*  */
void Ultrasonic_alarmSystem(void)
{
	GPIO_setupPinDirection(US_SENSOR_BUZZER_PORT_ID, US_SENSOR_BUZZER_PIN_ID, PIN_OUTPUT);
	if(US_distance <= 50)
	{
		/* activating alarm system as distance is small */
		GPIO_writePin(US_SENSOR_BUZZER_PORT_ID, US_SENSOR_BUZZER_PIN_ID, US_BUZZER_ON);
	}
	else
	{
		/* disabling alarm system */
		GPIO_writePin(US_SENSOR_BUZZER_PORT_ID, US_SENSOR_BUZZER_PIN_ID, US_BUZZER_OFF);
	}
}



void Ultrasonic_init(void)
{
	/* settin ICU call back function */
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* initializing ICU with specific configurations*/
	ICU_configure_type US_config = {US_SENSOR_ICU_STARTING_EDGE, US_SENSOR_ICU_PRESCALER};
	ICU_init(&US_config);
}

void Ultrasonic_edgeProcessing(void)
{
	static uint16 US_HighTime = 0;
	static uint8 US_EdgesCount = 0;
	US_EdgesCount++;
	if(US_EdgesCount == 1)
	{
		ICU_clearClock();

		/* setting icu edge */
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if(US_EdgesCount == 2)
	{
		/* storing ICR1 value */
		US_HighTime = ICU_getInputCaptureValue();

		ICU_clearClock();

		ICU_setEdgeDetectionType(RISING_EDGE);

		/* calculating distance */
		US_distance = ((34000 * US_HighTime * TIME_OF_CLOCK_CYCLE_sec) / 2);

		/* resetting edges counter variable */
		US_EdgesCount = 0;

		/* deinitializing ICU driver */
		ICU_deinit();
	}
}

void Ultrasonic_Trigger(void)
{
	/* configuring trigger pin as output pin */
	GPIO_setupPinDirection(US_SENSOR_TRIGGER_PORT_ID, US_SENSOR_TRIGGER_PIN_ID, PIN_OUTPUT);

	/* trigger for 10us */
	GPIO_writePin(US_SENSOR_TRIGGER_PORT_ID, US_SENSOR_TRIGGER_PIN_ID, TRIGGER);
	_delay_us(12);
	GPIO_writePin(US_SENSOR_TRIGGER_PORT_ID, US_SENSOR_TRIGGER_PIN_ID, NO_TRIGGER);
}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_init();
	Ultrasonic_Trigger();

	/* checking error before returning distance */
	Ultrasonic_errorChecking();

	return US_distance;
}

