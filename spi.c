#include "spi.h"
#include "avr_registers.h"
#include "gpio.h"


void SPI_initMaster(void)
{

	GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);

	SPCR_REG.Bits.MSTR_bit = 1;
	SPCR_REG.Bits.SPE_bit = 1;
	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPSR_REG.Bits.SPI2X_bit = 0;

}


void SPI_initSlave(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);

	SPCR_REG.Bits.SPE_bit = 1;

	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPSR_REG.Bits.SPI2X_bit = 0;
}

uint8 SPI_sendReceiveByte(uint8 data)
{
	SPDR_REG.Byte = data;

	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(SPSR_REG.Bits.SPIF_bit == 0){}

	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPDR_REG.Byte;
}
void SPI_sendString(const uint8 *string)
{
	uint8 i;
	uint8 received_data = 0;

	for(i = 0; string[i] != '\0';i++)
	{
		received_data = SPI_sendReceiveByte(string[i]);
	}
}
void SPI_receiveString(uint8 *string)
{
	uint8 i = 0;

	string[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	while(string[i] != '#')
	{
		i++;
		string[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	string[i] = '\0';
}
