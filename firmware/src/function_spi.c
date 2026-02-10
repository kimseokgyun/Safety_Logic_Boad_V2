#include "system_general_configuration.h"

/*****************************************************************************
 * Write Data through SPI Master Port
 * Spi master is connected to spi peripheral number 2
 * Input : unsigned int : tx data
 * Return : unsgined int : rx buffer data
 *****************************************************************************/
inline unsigned int     Write_SpiMaster(unsigned int data){
    static unsigned int spi_4_dummy;
    spi_4_dummy = SPI4BUF;                  //dummy read of the SPI2BUF register to clear the SPIRBF flag
    SPI4BUF = data;                         // write the data out to the SPI peripheral
    while (!SPI4STATbits.SPIRBF);           // wait for the data to be sent out
	spi_4_dummy = SPI4BUF;
	return spi_4_dummy;
}

/*****************************************************************************
 * Write Data through SPI Slave Port
 * Spi slave is connected to spi peripheral number 4
 * Input : unsigned int : tx data
 * Return : unsgined int : rx buffer data
 *****************************************************************************/
inline unsigned int     Write_SpiSlave(unsigned int data){
    static unsigned int spi_4_dummy;
    spi_4_dummy = SPI4BUF;                  //dummy read of the SPI4BUF register to clear the SPIRBF flag
    SPI4BUF = data;                         // write the data out to the SPI peripheral
    while (!SPI4STATbits.SPIRBF);           // wait for the data to be sent out
	spi_4_dummy = SPI4BUF;
	return spi_4_dummy;
}