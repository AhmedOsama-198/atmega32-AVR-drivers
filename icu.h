/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"


/*******************************************************************************
 *                                 Definitions                                 *
 *******************************************************************************/


#define TIME_OF_CLOCK_CYCLE_ms 0.001
#define FREQUENCY_OF_CLOCK_CYCLE_Hz 1000000


/*******************************************************************************/



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/* to set the ICU working edge */
typedef enum
{
	FALLING_EDGE,RISING_EDGE
}ICU_EDGE_TYPE;


/* to set the ICU clock prescaler */
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_CLOCK_SELECT;


/* structure to store the configurations of the ICU 
 * and pass it as an argument to the init() function*/
typedef struct
{
	ICU_EDGE_TYPE edge;
	ICU_CLOCK_SELECT clock;
}ICU_configure_type;


/*****************************************************************************/



/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/


/* function that initializes the ICU to work with specified configurations*/
void ICU_init(const ICU_configure_type*);

/* function that de-initializes the ICU and resets everything */
void ICU_deinit(void);

/* function that clears the timer clock */
void ICU_clearClock(void);

/* function that configure the call back function */
void ICU_setCallBack(void(*a_ptr)(void));

/* function used to change the edge type */
void ICU_setEdgeDetectionType(const ICU_EDGE_TYPE edgeType);

/* function used to return the value stored in the ICR1 register */
uint16 ICU_getInputCaptureValue(void);


/*****************************************************************************/


#endif /* ICU_H_ */
