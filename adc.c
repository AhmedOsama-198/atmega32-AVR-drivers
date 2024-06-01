/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Ahmed Osama
 *
 *******************************************************************************/


#include "adc.h"
#include "avr_registers.h"
#include "gpio.h"


void ADC_init(ADC_Configure_Type* config)
{
	/* setting ADC voltage refrence selection bits */
	ADMUX_REG.Byte = (ADMUX_REG.Byte & 0b00111111) | ((config ->Vref) << 6);

	/* clearing ADC MUX bits */
	ADMUX_REG.Bits.MUX0_bit = 0;
	ADMUX_REG.Bits.MUX1_bit = 0;
	ADMUX_REG.Bits.MUX2_bit = 0;
	ADMUX_REG.Bits.MUX3_bit = 0;
	ADMUX_REG.Bits.MUX4_bit = 0;

	ADMUX_REG.Bits.ADLAR_bit = 0; 	/* disable ADC left adjust result bit */
	ADCSRA_REG.Bits.ADEN_bit = 1;	/* setting ADC enable bit */
	ADCSRA_REG.Bits.ADATE_bit = 0;	/* disable ADC auto trigger bit */
	ADCSRA_REG.Bits.ADIE_bit = 0;	/* disable ADC interrupt enable bit as we are working with polling technique */

	/* configuring ADC prescaler selection bits */
	ADCSRA_REG.Byte = (ADCSRA_REG.Byte & 0b11111000) | ((config -> Clock));
}


uint16 ADC_readChannel(uint8 ch_num)
{
	/* configuring ADC MUX bits to read specific channel */
	ADMUX_REG.Byte = (ADMUX_REG.Byte & 0B11100000) | (ch_num);

	ADCSRA_REG.Bits.ADSC_bit = 1;	/* beginning conversion */
	while(ADCSRA_REG.Bits.ADIF_bit == 0);	/* empty loop to wait for the conversion done flag */
	ADCSRA_REG.Bits.ADIF_bit = 1;	/* clearing flag for next conversion */
	return ADC_REG.Byte;	/* return digital value converted */
}
