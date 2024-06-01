/*
 * spi.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"

#define SPI_DEFAULT_DATA_VALUE		0xFF




void SPI_initMaster(void);
void SPI_initSlave(void);
uint8 SPI_sendReceiveByte(uint8 data);
void SPI_sendString(const uint8 *string);
void SPI_receiveString(uint8 *string);


#endif /* SPI_H_ */
