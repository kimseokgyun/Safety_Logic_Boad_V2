#ifndef SYSTEM_PIN_MAP_H
#define SYSTEM_PIN_MAP_H

#include <proc/p32mz2048efh100.h>

/*******************************************************************************
 * MCU Port Pin Mapping BOARD V1.01
 ******************************************************************************/
#define             ANSEL_ALL               ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELF = ANSELG
#define             TRIS_ALL                TRISA = TRISB = TRISC = TRISD = TRISE = TRISF = TRISG

// Primary Oscillator Pin
#define             TRIS_POSC               TRISCbits.TRISC12
#define             TRIS_SOSC               TRISCbits.TRISC13


// LED Indicator Pins
#define             TRIS_LED_1              TRISDbits.TRISD13
#define             TRIS_LED_2              TRISDbits.TRISD12
#define             LATS_LED_1              LATDbits.LATD13
#define             LATS_LED_2              LATDbits.LATD12

//// FET Switch Pin
//#define             TRIS_SW_CHARGE          TRISDbits.TRISD10
//#define             TRIS_SW_INRUSH          TRISDbits.TRISD9
//#define             TRIS_SW_5V_POWER        TRISDbits.TRISD5
//#define             LATS_SW_CHARGE          LATDbits.LATD10
//#define             LATS_SW_INRUSH          LATDbits.LATD9
//#define             LATS_SW_5V_POWER        LATDbits.LATD5
//#define             PORT_SW_CHARGE          (int)PORTDbits.RD10
//#define             PORT_SW_INRUSH          (int)PORTDbits.RD9
//#define             PORT_SW_5V_POWER        (int)PORTDbits.RD5


// ADC Pins
#define             TRIS_ADC_48V_CURRENT            TRISBbits.TRISB0
#define             TRIS_ADC_CHARGE_CURRENT         TRISBbits.TRISB1
#define             TRIS_ADC_CONTACT_VOLTAGE        TRISBbits.TRISB2

#define             ANSEL_ADC_CHARGE_VOLTAGE        ANSELBbits.ANSB0
#define             ANSEL_ADC_CHARGE_CURRENT        ANSELBbits.ANSB1
#define             ANSEL_ADC_CONTACT_VOLTAGE       ANSELBbits.ANSB2

#define             REGS_ADC_CHARGE_VOLTAGE         ADCDATA0
#define             REGS_ADC_CHARGE_CURRENT         ADCDATA1
#define             REGS_ADC_CONTACT_VOLTAGE        ADCDATA2


// CAN communication Pins (CAN1)
#define             TRIS_CAN_1_TX           TRISFbits.TRISF4
#define             TRIS_CAN_1_RX           TRISFbits.TRISF5
#define             PPS_CAN_1_TX            RPF4Rbits.RPF4R = 0b1111
#define             PPS_CAN_1_RX            C1RXRbits.C1RXR = 0b0010

// CAN communication Pins (CAN2)
#define             TRIS_CAN_2_TX           TRISFbits.TRISF13
#define             TRIS_CAN_2_RX           TRISFbits.TRISF12
#define             PPS_CAN_2_TX            RPF13Rbits.RPF13R = 0b1111
#define             PPS_CAN_2_RX            C2RXRbits.C2RXR = 0b1001

// UART communication Pins (U3)
#define             TRIS_UART_TX           TRISAbits.TRISA14
#define             TRIS_UART_RX           TRISAbits.TRISA15
#define             PPS_UART_TX            RPA14Rbits.RPA14R = 0b0001
#define             PPS_UART_RX            U3RXRbits.U3RXR = 0b1101


//EMO
#define             TRIS_EMO_1_A            TRISFbits.TRISF1
#define             TRIS_EMO_2_A            TRISDbits.TRISD5
#define             TRIS_EMO_3_A            TRISEbits.TRISE8
#define             TRIS_EMO_4_A            TRISGbits.TRISG9
#define             PORT_EMO_1_A            PORTFbits.RF1
#define             PORT_EMO_2_A            PORTDbits.RD5
#define             PORT_EMO_3_A            PORTEbits.RE8
#define             PORT_EMO_4_A            PORTGbits.RG9

#define             TRIS_EMO_1_B          TRISFbits.TRISF0
#define             TRIS_EMO_2_B          TRISCbits.TRISC3
#define             TRIS_EMO_3_B          TRISBbits.TRISB5
#define             TRIS_EMO_4_B          TRISEbits.TRISE9
#define             PORT_EMO_1_B          PORTFbits.RF0
#define             PORT_EMO_2_B          PORTCbits.RC3
#define             PORT_EMO_3_B          PORTBbits.RB5
#define             PORT_EMO_4_B          PORTEbits.RE9

//BUMPER
#define             PORT_BUMP_1_A           PORTEbits.RE0
#define             PORT_BUMP_1_C           PORTAbits.RA4
#define             PORT_BUMP_1_E           PORTAbits.RA0
#define             PORT_BUMP_1_G           PORTGbits.RG1

#define             PORT_BUMP_2_B           PORTAbits.RA7
#define             PORT_BUMP_2_D           PORTCbits.RC2
#define             PORT_BUMP_2_F           PORTCbits.RC4
#define             PORT_BUMP_2_H           PORTGbits.RG6

// FET
#define             TRIS_MOTOR_PRE_FET_A    TRISEbits.TRISE9
#define             TRIS_MOTOR_MAIN_FET_A   TRISBbits.TRISB5
#define             TRIS_MOTOR_FET_FAULT_A  TRISBbits.TRISB4
#define             PORT_MOTOR_FET_FAULT_A  PORTBbits.RB4
#define             LAT_MOTOR_PRE_FET_A     LATEbits.LATE9
#define             LAT_MOTOR_MAIN_FET_A    LATBbits.LATB5

#define             TRIS_MOTOR_PRE_FET_B    TRISAbits.TRISA6
#define             TRIS_MOTOR_MAIN_FET_B   TRISBbits.TRISB8
#define             TRIS_MOTOR_FET_FAULT_B  TRISBbits.TRISB3
#define             PORT_MOTOR_FET_FAULT_B  PORTBbits.RB3
#define             LAT_MOTOR_PRE_FET_B     LATAbits.LATA6
#define             LAT_MOTOR_MAIN_FET_B    LATBbits.LATB8

#define             TRIS_LIFT_PRE_FET       TRISAbits.TRISA0
#define             TRIS_LIFT_MAIN_FET      TRISGbits.TRISG7
#define             TRIS_LIFT_FET_FAULT     TRISBbits.TRISB10
#define             PORT_LIFT_FET_FAULT     PORTBbits.RB10
#define             LAT_LIFT_PRE_FET        LATAbits.LATA0
#define             LAT_LIFT_MAIN_FET       LATGbits.LATG7

// SPI for EEPROM (SPI1)
#define             TRIS_SPI_EEPROM_SCK        TRISDbits.TRISD1
#define             TRIS_SPI_EEPROM_SDI        TRISDbits.TRISD2
#define             TRIS_SPI_EEPROM_SDO        TRISDbits.TRISD3
#define             TRIS_SPI_EEPROM_CS         TRISDbits.TRISD4
#define             PPS_SPI_EEPROM_SDI         SDI1Rbits.SDI1R = 0b0000
#define             PPS_SPI_EEPROM_SDO         RPD2Rbits.RPD2R = 0b0101
#define             LATS_SPI_EEPROM_CS         LATDbits.LATD4


// SPI Master communication Pins (SPI4)
#define             TRIS_SPI_MAS_SCK        TRISDbits.TRISD10
#define             TRIS_SPI_MAS_SDI        TRISDbits.TRISD11
#define             TRIS_SPI_MAS_SDO        TRISDbits.TRISD0
#define             TRIS_SPI_MAS_SSS        TRISDbits.TRISD9
#define             PPS_SPI_MAS_SDI         SDI4Rbits.SDI4R = 0b0011
#define             PPS_SPI_MAS_SDO         RPD0Rbits.RPD0R = 0b1000
#define             LATS_SPI_MAS_SSS        LATDbits.LATD9




// Reset Start Stop 
#define             PORT_SW_RESET           !(PORTAbits.RA7)
#define             PORT_SW_STOP            !(PORTAbits.RA6)
#define             PORT_SW_START           !(PORTGbits.RG0)

// Digital Out
#define             LAT_DOUT_DIS_A          LATCbits.LATC15
#define             LAT_DOUT_WR_A           LATEbits.LATE5
#define             LAT_DOUT_CS_A           LATEbits.LATE6

#define             LAT_DOUT_DIS_B          LATGbits.LATG6
#define             LAT_DOUT_WR_B           LATCbits.LATC3
#define             LAT_DOUT_CS_B           LATCbits.LATC4

#define             LAT_DIGITAL_OUT_0       LATEbits.LATE1
#define             LAT_DIGITAL_OUT_1       LATGbits.LATG14
#define             LAT_DIGITAL_OUT_2       LATGbits.LATG12
#define             LAT_DIGITAL_OUT_3       LATGbits.LATG13
#define             LAT_DIGITAL_OUT_4       LATEbits.LATE2
#define             LAT_DIGITAL_OUT_5       LATEbits.LATE3
#define             LAT_DIGITAL_OUT_6       LATEbits.LATE4
#define             LAT_DIGITAL_OUT_7       LATAbits.LATA5

#define             LAT_DIGITAL_OUT_8       LATEbits.LATE3
#define             LAT_DIGITAL_OUT_9       LATEbits.LATE4
#define             LAT_DIGITAL_OUT_10      LATAbits.LATA5
#define             LAT_DIGITAL_OUT_11      LATEbits.LATE5
#define             LAT_DIGITAL_OUT_12      LATEbits.LATE6
#define             LAT_DIGITAL_OUT_13      LATEbits.LATE7
#define             LAT_DIGITAL_OUT_14      LATCbits.LATC1
#define             LAT_DIGITAL_OUT_15      LATCbits.LATC2


// Digital In
#define             LAT_DIN_ALE_A           LATGbits.LATG1
#define             LAT_DIN_CS_A            LATBbits.LATB9
#define             LAT_DIN_WR_A            LATGbits.LATG0
#define             LAT_DIN_RD_A            LATEbits.LATE8

#define             TRIS_DIN_00             TRISDbits.TRISD15
#define             TRIS_DIN_01             TRISDbits.TRISD14
#define             TRIS_DIN_02             TRISBbits.TRISB15
#define             TRIS_DIN_03             TRISBbits.TRISB14
#define             TRIS_DIN_04             TRISBbits.TRISB13
#define             TRIS_DIN_05             TRISBbits.TRISB12
#define             TRIS_DIN_06             TRISAbits.TRISA1
#define             TRIS_DIN_07             TRISBbits.TRISB11
#define             TRIS_INTERLOCK_IN_A     TRISBbits.TRISB11

#define             LAT_DIN_00              LATDbits.LATD15
#define             LAT_DIN_01              LATDbits.LATD14
#define             LAT_DIN_02              LATBbits.LATB15
#define             LAT_DIN_03              LATBbits.LATB14
#define             LAT_DIN_04              LATBbits.LATB13
#define             LAT_DIN_05              LATBbits.LATB12
#define             LAT_DIN_06              LATAbits.LATA1
#define             LAT_DIN_07              LATBbits.LATB11
#define             LAT_INTERLOCK_IN_A      LATBbits.LATB11

#define             PORT_DIN_00              PORTDbits.RD15
#define             PORT_DIN_01              PORTDbits.RD14
#define             PORT_DIN_02              PORTBbits.RB15
#define             PORT_DIN_03              PORTBbits.RB14
#define             PORT_DIN_04              PORTBbits.RB13
#define             PORT_DIN_05              PORTBbits.RB12
#define             PORT_DIN_06              PORTAbits.RA1
#define             PORT_DIN_07              PORTBbits.RB11
#define             PORT_INTERLOCK_IN_A      PORTBbits.RB11



#define             LAT_DIN_ALE_B           LATBbits.LATB8
#define             LAT_DIN_CS_B            LATGbits.LATG12
#define             LAT_DIN_WR_B            LATBbits.LATB9
#define             LAT_DIN_RD_B            LATBbits.LATB10

#define             TRIS_DIN_08             TRISDbits.TRISD14
#define             TRIS_DIN_09             TRISBbits.TRISB15
#define             TRIS_DIN_10             TRISBbits.TRISB14
#define             TRIS_DIN_11             TRISBbits.TRISB13
#define             TRIS_DIN_12             TRISBbits.TRISB12
#define             TRIS_DIN_13             TRISAbits.TRISA1
#define             TRIS_DIN_14             TRISBbits.TRISB11
#define             TRIS_DIN_15             TRISGbits.TRISG14
#define             TRIS_INTERLOCK_IN_B     TRISGbits.TRISG14

#define             LAT_DIN_08              LATDbits.LATD14
#define             LAT_DIN_09              LATBbits.LATB15
#define             LAT_DIN_10              LATBbits.LATB14
#define             LAT_DIN_11              LATBbits.LATB13
#define             LAT_DIN_12              LATBbits.LATB12
#define             LAT_DIN_13              LATAbits.LATA1
#define             LAT_DIN_14              LATBbits.LATB11
#define             LAT_DIN_15              LATGbits.LATG14
#define             LAT_INTERLOCK_IN_B      LATGbits.LATG14

#define             PORT_DIN_08              PORTDbits.RD14
#define             PORT_DIN_09              PORTBbits.RB15
#define             PORT_DIN_10              PORTBbits.RB14
#define             PORT_DIN_11              PORTBbits.RB13
#define             PORT_DIN_12              PORTBbits.RB12
#define             PORT_DIN_13              PORTAbits.RA1
#define             PORT_DIN_14              PORTBbits.RB11
#define             PORT_DIN_15              PORTGbits.RG14
#define             PORT_INTERLOCK_IN_B      PORTGbits.RG14



#endif