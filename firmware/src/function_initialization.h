#ifndef FUNCTION_INITIALIZATION_H
#define FUNCTION_INITIALIZATION_H

void                    Initialize_PinDefinition(void);

void                    Initialize_Peripherals(void);

void                    Initialize_ParameterTable(void);

void                    Initialize_Variables(unsigned char option);

void                    Initialize_IO(void);

void                    Initialize_Timer2(void);

void                    Initialize_Timer4(void);

void                    Initialize_CAN1(void);

void                    Initialize_CAN2(void);

void                    Initialize_Spi4Master(unsigned int bit_type, unsigned int mode);

void                    Initialize_Spi4Slave(unsigned int bit_type, unsigned int mode);

void Initialize_Spi2(unsigned int bit_type, unsigned int mode);

//void                    Initialize_Spi4Slave(unsigned int bit_type, unsigned int mode);

void                    Initialize_ADC(void);

void                    Initialize_UART1(unsigned int baudRate, unsigned int stop_bit, unsigned int parity_mode);

void                    Initialize_WatchDogTimer(void);

void Initialize_OSSD(void);

extern void GPIO_DIN_TRIS_0(unsigned char dir);
extern void GPIO_DIN_TRIS_1(unsigned char dir);
extern int GPIO_DIN_INIT_CHIP_0(void);
extern int GPIO_DIN_INIT_CHIP_1(void);


#endif