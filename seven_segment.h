 /******************************************************************************
 *
 * Module: SEVEN SEGMENT
 *
 * File Name: seven_segment.h
 *
 * Description: Header file for the AVR SEVEN SEGMENT driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "std_types.h"


#define NUMBER_OF_SEVEN_SEGMENT 1 //number of seven segments connected


#define SEVEN_SEGMENT_FIRST_ENABLE_PORT_ID PORTC_ID //port of first seven segment
#define SEVEN_SEGMENT_FIRST_ENABLE_PIN_ID PIN6_ID //pin of first seven segment

#if(NUMBER_OF_SEVEN_SEGMENT==2)

#define SEVEN_SEGMENT_SECOND_ENABLE_PORT_ID PORTC_ID //port of second seven segment
#define SEVEN_SEGMENT_SECOND_ENABLE_PIN_ID PIN7_ID //pin of second seven segment

#endif

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW

#define DECODER FALSE //decoder presence or not

#if(DECODER == TRUE)

#define SEVEN_SEGMENT_DECODER_PORT_ID PORTC_ID
#define SEVEN_SEGMENT_DECODER_PIN_ID PIN0_ID

#elif(DECODER == FALSE)

#define SEVEN_SEGMENT_PORT_ID PORTA_ID
#define SEVEN_SEGMENT_PIN_ID PIN1_ID

#endif


/*******************************************************************************/





/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/


/* function that enable the first 7 segment   */
void SEVEN_SEGMENT_enable_First();

/* function that disable the first 7 segment  */
void SEVEN_SEGMENT_disable_First();

/* function that enable the second 7 segment  */
void SEVEN_SEGMENT_enable_Second();

/* function that disable the second 7 segment */
void SEVEN_SEGMENT_disable_Second();

/* function that initialize the 7 segment  */
void SEVEN_SEGMENT_init();

/* function that displays a given number on the first 7 segment   */
void SEVEN_SEGMENT_display_First(uint8 value);

/* function that displays a given number on the second 7 segment  */
void SEVEN_SEGMENT_display_Second(uint8 value);


/*******************************************************************************/


#endif /* SEVEN_SEGMENT_H_ */
