#include "system_general_configuration.h"


inline void WAIT_10NSEC(unsigned int ncnt){
    TMR4 = 0;
    while(TMR4 <= ncnt);
}
inline unsigned int SPI_2_WRITE(unsigned int data){
 	unsigned int spi_dum2 = SPI2BUF;                 // dummy read of the SPI1BUF register to clear the SPIRBF flag
	SPI2BUF = data;                 // write the data out to the SPI peripheral
	while (!SPI2STATbits.SPIRBF);	// wait for the data to be sent out
	spi_dum2 = SPI2BUF;
	return spi_dum2;
}

/*****************************************************************************
 * Initialize MCU Port Pins
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_PinDefinition(void){
    // Init all AN pin as digital
    ANSEL_ALL = DIGITAL;
    
    // Init all pin as input
    TRIS_ALL = INPUT;
    
    // Primary OSC INPUT
    TRIS_POSC = INPUT;
    TRIS_SOSC = INPUT;
    
    // Type Control
    TRISGbits.TRISG15 = INPUT;
    
    volatile int initial_delay2 = 24000000;
    while(initial_delay2--)
        ;
    
    
    if(PORTGbits.RG15 == 1)
    {
        SF_MCU_NUM = MCU_0;
        _mboard.type = MCU_0;
    }
    else
    {
        SF_MCU_NUM = MCU_1;
        _mboard.type = MCU_1;
    }
    
//    TRIS_BOARD_TYPE
//    TRIS_BOARD_TYPE = INPUT;
    
    // LED
    TRIS_LED_1 = OUTPUT;
    TRIS_LED_2 = OUTPUT;
    
    // CAN1
    TRIS_CAN_1_TX = OUTPUT;
    TRIS_CAN_1_RX = INPUT;
    PPS_CAN_1_TX;
    PPS_CAN_1_RX;    
    
    // CAN2
    TRIS_CAN_2_TX = OUTPUT;
    TRIS_CAN_2_RX = INPUT;
    PPS_CAN_2_TX;
    PPS_CAN_2_RX;    
    
    // UART (U3)
    TRIS_UART_TX = OUTPUT;
    TRIS_UART_RX = INPUT;
    PPS_UART_TX;
    PPS_UART_RX;    
    
    // SPI for EEPROM (SPI1)
    TRIS_SPI_EEPROM_SCK = OUTPUT;
    TRIS_SPI_EEPROM_SDI = INPUT;
    TRIS_SPI_EEPROM_SDO = OUTPUT;
    TRIS_SPI_EEPROM_CS = OUTPUT;

    PPS_SPI_EEPROM_SDI;
    PPS_SPI_EEPROM_SDO;
    LATS_SPI_EEPROM_CS = HIGH;
    
    
    // ----------------------------------------------------------
    if(_mboard.type == MCU_0)
    {
        // Clock Test
        TRISAbits.TRISA9 = INPUT;
        TRISAbits.TRISA10 = INPUT;
        
        // EMO
        TRIS_EMO_1_A = INPUT;
        TRIS_EMO_2_A = INPUT;
        TRIS_EMO_3_A = INPUT;
        TRIS_EMO_4_A = INPUT;
        
        // FET (Motor)
        TRIS_MOTOR_PRE_FET_A = OUTPUT;
        TRIS_MOTOR_MAIN_FET_A = OUTPUT;
        TRIS_MOTOR_FET_FAULT_A = INPUT;
             
        // ADC
        TRISBbits.TRISB1 = INPUT;
        TRISBbits.TRISB2 = INPUT;
        ANSELBbits.ANSB1 = ANALOG;
        ANSELBbits.ANSB2 = ANALOG;

        // Lidar Field Monitoring
        TRISAbits.TRISA3 = INPUT;     // A1
        TRISAbits.TRISA2 = INPUT;     // B1     
        TRISFbits.TRISF8 = INPUT;     // C1
        TRISFbits.TRISF2 = INPUT;     // D1
        TRISCbits.TRISC15 = INPUT;    // E1        
        TRISDbits.TRISD15 = INPUT;    // F1
        
        // OSSD
        TRISCbits.TRISC14 = INPUT;    // OSSD Front A
        TRISFbits.TRISF0 = INPUT;     // OSSD Rear A
        
        // Bumper
        TRISEbits.TRISE0 = INPUT;   // Bumper 1 A
        TRISAbits.TRISA4 = INPUT;   // Bumper 2 A
        TRISAbits.TRISA0 = INPUT;   // Bumper 3 A
        TRISGbits.TRISG1 = INPUT;   // Bumper 4 A
                
        // SPI (Master)
        TRIS_SPI_MAS_SCK = OUTPUT;
        TRIS_SPI_MAS_SDI = INPUT;
        TRIS_SPI_MAS_SDO = OUTPUT;
        TRIS_SPI_MAS_SSS = OUTPUT;
        
        PPS_SPI_MAS_SDI;
        PPS_SPI_MAS_SDO;
        LATS_SPI_MAS_SSS = LOW;
                
        // Interlock
        TRISGbits.TRISG14 = INPUT;  // Interlock In 
        TRISCbits.TRISC2 = OUTPUT;  // Interlock Output
        TRISBbits.TRISB3 = INPUT;   // feedback Interlock
        
        // PLC
        GPIO_DIN_TRIS_0(INPUT);
        
        TRISEbits.TRISE3 = OUTPUT;  // Dout 08
        TRISEbits.TRISE4 = OUTPUT;  // Dout 09
        TRISAbits.TRISA5 = OUTPUT;  // Dout 10
        TRISEbits.TRISE5 = OUTPUT;  // Dout 11
        TRISEbits.TRISE6 = OUTPUT;  // Dout 12
        TRISEbits.TRISE7 = OUTPUT;  // Dout 13
        TRISCbits.TRISC1 = OUTPUT;  // Dout 14
        
        TRISGbits.TRISG7 = INPUT;   // feedback 12
        TRISGbits.TRISG8 = INPUT;   // feedback 13
        
        // Digital Out Chip Control
        TRISGbits.TRISG6 = OUTPUT;  // DO DIS B        
        TRISCbits.TRISC3 = OUTPUT;  // DO WR CH B
        TRISCbits.TRISC4 = OUTPUT;  // DO CS CH B
        
        LAT_DOUT_DIS_B = HIGH;
        LAT_DOUT_CS_B = HIGH;
        LAT_DOUT_WR_B = HIGH;
        
        // Digital Input Chip Control
        TRISBbits.TRISB8 = OUTPUT;  // DI ALE B
        TRISGbits.TRISG12 = OUTPUT; // DI CS CH B        
        TRISBbits.TRISB9 = OUTPUT;  // DI WR CH B 
        TRISBbits.TRISB10 = OUTPUT; // DI RD CH B
        
        LAT_DIN_ALE_B = LOW;        
        LAT_DIN_CS_B = HIGH;        
        LAT_DIN_WR_B = HIGH;
        LAT_DIN_RD_B = HIGH;
                
        // Start Stop Reset
        TRISGbits.TRISG0 = INPUT; // START
        TRISAbits.TRISA6 = INPUT; // STOP
        TRISAbits.TRISA7 = INPUT; // RESET
        
    }
    else
    {
        // Clock Test
        TRISAbits.TRISA9 = INPUT;
        TRISAbits.TRISA10 = INPUT;
        
        // EMO
        TRIS_EMO_1_B = INPUT;
        TRIS_EMO_2_B = INPUT;
        TRIS_EMO_3_B = INPUT;
        TRIS_EMO_4_B = INPUT;
                
        // FET (Motor - Slow On)
        TRIS_MOTOR_PRE_FET_B = OUTPUT;
        TRIS_MOTOR_MAIN_FET_B = OUTPUT;
        TRIS_MOTOR_FET_FAULT_B = INPUT;
        
        // FET (Lift)
        TRIS_LIFT_PRE_FET = OUTPUT;
        TRIS_LIFT_MAIN_FET = OUTPUT;
        TRIS_LIFT_FET_FAULT = INPUT;
        
        // ADC
        TRISBbits.TRISB0 = INPUT;
        TRISBbits.TRISB1 = INPUT;
        TRISBbits.TRISB2 = INPUT;
        ANSELBbits.ANSB0 = ANALOG;
        ANSELBbits.ANSB1 = ANALOG;
        ANSELBbits.ANSB2 = ANALOG;
                
        // Lidar Field Monitoring
        TRISFbits.TRISF8 = INPUT;     // A2
        TRISFbits.TRISF2 = INPUT;     // B2
        TRISAbits.TRISA3 = INPUT;     // C2
        TRISAbits.TRISA2 = INPUT;     // D2
        TRISCbits.TRISC14 = INPUT;    // E2
        TRISAbits.TRISA4 = INPUT;     // F2
        
        // OSSD
        TRISDbits.TRISD5 = INPUT;     // OSSD Front B
        TRISFbits.TRISF1 = INPUT;     // OSSD Rear B
        
        // Bumper
        TRISAbits.TRISA7 = INPUT;   // Bumper 1 B
        TRISCbits.TRISC2 = INPUT;   // Bumper 2 B
        TRISCbits.TRISC4 = INPUT;   // Bumper 3 B
        TRISGbits.TRISG6 = INPUT;   // Bumper 4 B
        
        // SPI (Slave)
        TRIS_SPI_MAS_SCK = OUTPUT;
        TRIS_SPI_MAS_SDI = INPUT;
        TRIS_SPI_MAS_SDO = OUTPUT;
        TRIS_SPI_MAS_SSS = INPUT;
        
        PPS_SPI_MAS_SDI;
        PPS_SPI_MAS_SDO;
//        LATS_SPI_MAS_SSS;
        
        // Interlock
        TRIS_INTERLOCK_IN_A = INPUT;  // Interlock In 
        TRISAbits.TRISA5 = OUTPUT;  // Interlock Output
        TRISBbits.TRISB4 = INPUT;   // feedback Interlock
        
        // PLC
        GPIO_DIN_TRIS_1(INPUT);
                
        TRISEbits.TRISE1 = OUTPUT;  // Dout 00
        TRISGbits.TRISG14 = OUTPUT; // Dout 01
        TRISGbits.TRISG12 = OUTPUT; // Dout 02
        TRISGbits.TRISG13 = OUTPUT; // Dout 03
        TRISEbits.TRISE2 = OUTPUT;  // Dout 04
        TRISEbits.TRISE3 = OUTPUT;  // Dout 05
        TRISEbits.TRISE4 = OUTPUT;  // Dout 06
        
        TRISEbits.TRISE7 = INPUT;   // feedback 05
        TRISCbits.TRISC1 = INPUT;   // feedback 06      
        
        // Digital Out Chip Control
        TRISCbits.TRISC15 = OUTPUT; // DO DIS A
        TRISEbits.TRISE5 = OUTPUT;  // DO WR CH A
        TRISEbits.TRISE6 = OUTPUT;  // DO CS CH A
        
        LAT_DOUT_DIS_A = HIGH;
        LAT_DOUT_CS_A = HIGH;
        LAT_DOUT_WR_A = HIGH;
        
        // Digital Input Chip Control
        TRISGbits.TRISG1 = OUTPUT;  // DI ALE A
        TRISBbits.TRISB9 = OUTPUT;  // DI CS CH A
        TRISGbits.TRISG0 = OUTPUT;  // DI WR CH A 
        TRISEbits.TRISE8 = OUTPUT;  // DI RD CH A <------------------------------------------------------------------? MCU 0
        
        LAT_DIN_ALE_A = LOW;
        LAT_DIN_CS_A = HIGH;
        LAT_DIN_WR_A = HIGH;
        LAT_DIN_RD_A = HIGH; //<------------------------------------------------------------------? MCU 0
        
    }
}

/*****************************************************************************
 * Initialize MCU Peripheral functions
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_Peripherals(void)
{
    asm volatile("di");                 // Disable all interrupt
    INTCONbits.MVEC = TRUE;             // Multi vector on
    
    Initialize_ADC();
    ADCCON3bits.GSWTRG = 1;             // adc trigger    
    
    Initialize_CAN2();
    Initialize_CAN1();            //To do -- can1 channel interrupt clear
    
    
    if(_mboard.type == MCU_0)
    {
        Initialize_Spi4Master(32, 1);
        
    }
    else
    {
        Initialize_Spi2(8, 0);
        Initialize_Spi4Slave(32, 1);
    } 
        
    Initialize_Timer2();
    Initialize_Timer4();
    Initialize_OSSD();    
    Initialize_WatchDogTimer();
    
    asm volatile("ei");                 // Enable all interrupt
    
    int i;
    for(i=0; i<10; i++)
        WAIT_10NSEC(2000000);   // 20ms
    
    // Digital In---------------------------------
    if(_mboard.type == MCU_0)
    {
//        WAIT_10NSEC(20000000);  // 200ms
        int temp_di_check_0 = GPIO_DIN_INIT_CHIP_0();
        if(temp_di_check_0 != 0){
            _mboard.io.init_din_success = false;
        }else{
            _mboard.io.init_din_success = true;
        }
        LAT_DIN_CS_B = LOW;
        WAIT_10NSEC(10);
        LAT_DIN_RD_B = LOW;
    }
    else
    {
//        WAIT_10NSEC(20000000);  // 200ms
        int temp_di_check_1 = GPIO_DIN_INIT_CHIP_1();
        if(temp_di_check_1 != 0){
            _mboard.io.init_din_success = false;
        }else{
            _mboard.io.init_din_success = true;
        }
        LAT_DIN_CS_A = LOW;
        WAIT_10NSEC(10);
        LAT_DIN_RD_A = LOW;
    }
    WAIT_10NSEC(2000000);   // 20ms
    
    // Digital Out---------------------------------
    _mboard.io.init_dout_success = true;
    if(_mboard.type == MCU_0)
    {
        // LOW
        LAT_DOUT_CS_B = LOW;
        WAIT_10NSEC(1);
        LAT_DOUT_WR_B = LOW;
        WAIT_10NSEC(1);        
    }
    else
    {
        //seokgyun temp
        LAT_DOUT_CS_A = LOW;
        WAIT_10NSEC(1);
        LAT_DOUT_WR_A = LOW;
        WAIT_10NSEC(1);
    }
    WAIT_10NSEC(2000000);   // 20ms
}
/*****************************************************************************
 * Initialize Parmeter Table
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_ParameterTable(void)
{
    // default robot value
    _mboard.robot_info.robot_type = 0;              // DD
    _mboard.robot_info.wheel_radius = 75.0;         // mm 
    _mboard.robot_info.wheel_saparation = 520.0;    // mm
    _mboard.robot_info.gear_ratio = 12.0;
    _mboard.robot_info.dir = -1.0;
    
    _mboard.robot_info.max_linear_speed = 10000.0;//1000.0;           // mm/s
    _mboard.robot_info.max_rotation_speed = 10.0;//1.04666;        // rad/s
    _mboard.robot_info.monitoring_linear_speed = 300.0;     // mm/s
    _mboard.robot_info.monitoring_rotation_speed = 0.33;    // rad/s
    
    _mboard.robot_info.lx = 300.0;  // mm
    _mboard.robot_info.ly = 300.0;  // mm
}
/*****************************************************************************
 * Initialize Internal Variabls
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_Variables(unsigned char option){
    
}

/*****************************************************************************
 * Initialize input / output port information
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_IO(void){    
    LATS_LED_1 = HIGH;
    LATS_LED_2 = HIGH;
}

/*****************************************************************************
 * Initialize Timer 2 peripheral (100 Hz)
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_Timer2(void)
{
    //Main clock is 100MHZ?
    T2CON = 0x0000;                 // clear
    T2CONbits.TCKPS = 0b110;        // prescale 64:1
    T2CONbits.TCS = 0;              // internal clock
    TMR2 = 0;
    PR2 = 15625 - 1;                // 100 Hz
    
    IPC2bits.T2IP = 5;              // priority
    IPC2bits.T2IS = 0;              // sub priority
    IFS0bits.T2IF = 0;              // clear the flag
    
    T2CONSET = 0x8000;              // on TMR 2
    IEC0bits.T2IE = 1;              // enable interrupt
}

/********************************************** *******************************
 * Initialize Watchdog (100 Hz)
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_WatchDogTimer(void)
{
    T3CON = 0x0000;                 // clear
    T3CONbits.TCKPS = 0b111;        // prescale 256:1
    T3CONbits.TCS = 0;              // internal clock
    TMR3 = 0;
    PR3 = 15625 - 1;                // 25 Hz
    
    IPC3bits.T3IP = 1;              // priority
    IPC3bits.T3IS = 0;              // sub priority
    IFS0bits.T3IF = 0;              // clear the flag
    
    T3CONSET = 0x8000;              // on TMR 3
    IEC0bits.T3IE = 1;              // enable interrupt
}

/*****************************************************************************
 * Initialize Timer 4 peripheral (100 MHz)
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_Timer4(void)
{
    T4CON = 0x0000;                 // clear
    T4CONbits.T32 = 1;
    PR4 = 0xFFFFFFFF;
    
    T4CONSET = 0x8000;              // on TMR 4
}


void Initialize_OSSD(void)
{
    if(_mboard.type == MCU_0){
        CNCONFbits.ON = 1;
        CNENFbits.CNIEF0 = 1;   // OSSD Rear A
        
        CNCONCbits.ON = 1;
        CNENCbits.CNIEC14 = 1;   // OSSD Front A
        
        PORTFbits.RF0;
        PORTCbits.RC14;
        
        IPC30bits.CNCIP = 6;
        IPC30bits.CNCIS = 1;
        IFS3bits.CNCIF = 0;
        IEC3bits.CNCIE = 1;
        
        IPC30bits.CNFIP = 6;
        IPC30bits.CNFIS = 2;
        IFS3bits.CNFIF = 0;
        IEC3bits.CNFIE = 1;
    }
    else
    {
        CNCONDbits.ON = 1;
        CNENDbits.CNIED5 = 1;   // OSSD Front B
        
        CNCONFbits.ON = 1;
        CNENFbits.CNIEF1 = 1;   // OSSD Rear B
        
        PORTDbits.RD5;
        PORTFbits.RF1;
        
        IPC30bits.CNDIP = 6;
        IPC30bits.CNDIS = 1;
        IFS3bits.CNDIF = 0;
        IEC3bits.CNDIE = 1;
        
        IPC30bits.CNFIP = 6;
        IPC30bits.CNFIS = 2;
        IFS3bits.CNFIF = 0;
        IEC3bits.CNFIE = 1;
    }
    // ============================================
}

/*****************************************************************************
 * Initialize CAN 1 peripheral
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_CAN1(void)
{
    C1CONbits.ON = 1;               // switch the CAN module on

    C1CONbits.REQOP = 0x04;         // switch the CAN module to configuration mode
    while(C1CONbits.OPMOD != 0x04); // wait until the switch is complete    
    
    // set the baud rate to 1Mbps-----
    // (Propagation Segment + Phase Segment 1) must be greater than or equal to the length of Phase Segment 2
    // Phase Segment 2 must be greater than SJW
    // F_TQ = N * F_baud, 8 <= N <= 25
    // Propagation Segment = 1 Tq
    // Phase Seg 1 = 4 Tq
    // Phase Seg 2 = 4 Tq
    // Sync Jump Width = 2 Tq
    C1CFGbits.SEG2PHTS = 1;         // Phase seg 2 is freely programmable
    C1CFGbits.PRSEG = 0;            // Propagation seg is 1 Tq
    C1CFGbits.SEG1PH = 3;           // Phase seg 1 is 4 Tq
    C1CFGbits.SEG2PH = 3;           // Phase seg 2 is 4 Tq    
    C1CFGbits.SJW = 0;              // Sync jump width is 1 Tq
    C1CFGbits.SAM = 1;              // Sample bit 3 times
#ifdef CAN_SPEED_500HZ
    C1CFGbits.BRP = 9;              // BRP = F_sys/(2*F_TQ)-1
#else
    C1CFGbits.BRP = 4;              // BRP = F_sys/(2*F_TQ)-1
#endif
    
    // assign the buffer area to the CAN module -----
    
    C1FIFOBA = KVA_TO_PA(can_message_buffer0);
    // FIFO0 - Transmit - 4 Message Buffer
    // FIFO1 - Transmit - 4 Message Buffer
    // FIFO2 - Receive  - 4 Message Buffer
    // FIFO3 - Receive  - 4 Message Buffer
    // FIFO4 - FIFO31   - Not used
    
//    C1FIFOCON0bits.FSIZE = 3;
//    C1FIFOCON0bits.TXEN = 1;        //tx    
//    C1FIFOCON1bits.FSIZE = 3;
//    C1FIFOCON1bits.TXEN = 1;        //tx        
    
//    CAN_RECEIVE_CHANNEL_SET_1(2, 4);  // CAN channel 2, size 4
//    CAN_RECEIVE_CHANNEL_SET_1(3, 4);  // CAN channel 3, size 4
    
    C1FIFOCON0bits.FSIZE = 15;
    C1FIFOCON0bits.TXEN = 1;        //tx    
    C1FIFOCON1bits.FSIZE = 15;
    C1FIFOCON1bits.TXEN = 1;        //tx
    
    CAN_RECEIVE_CHANNEL_SET_1(2, 16);  // CAN channel 2, size 4
    CAN_RECEIVE_CHANNEL_SET_1(3, 16);  // CAN channel 3, size 4
    
    
    
    
//    C1FIFOCON2bits.FSIZE = 3;
//    C1FIFOCON2bits.TXEN = 0;        //rx
//    C1FIFOCON3bits.FSIZE = 3;
//    C1FIFOCON3bits.TXEN = 0;        //rx
    
    C1FIFOINT2bits.RXNEMPTYIE = 1;
    C1FIFOINT3bits.RXNEMPTYIE = 1;
    
    
    // *** *** *** *** *** *** Filter *** *** *** *** *** *** //
    // Filter disable before the filter mask setting
    int filter_num;
    for(filter_num=0; filter_num<32; filter_num++){
        CAN_DISABLE_FILTER_1(filter_num);
    }
     
    // Filter mask setting
    CAN_FILTER_MASK_CONFIG_1(0, 0b001111111111);      // mask0 config(0x7FF)
//    CAN_FILTER_MASK_CONFIG_1(0, 0b10000010111);

    // Filter setting
    CAN_FILTER_CONFIG_1(0, 0x400);                     // filter 0
    CAN_FILTER_2_CHANNEL_LINK_1(0, 0, 2);             // filter 0, mask0, FIFO channel2
    CAN_FILTER_CONFIG_1(1, 0x401);
    CAN_FILTER_2_CHANNEL_LINK_1(1, 0, 2);             // filter 0, mask0, FIFO channel2
    CAN_FILTER_CONFIG_1(2, 0x410);
    CAN_FILTER_2_CHANNEL_LINK_1(2, 0, 2);             // filter 0, mask0, FIFO channel2    
    CAN_FILTER_CONFIG_1(3, 0x411);                     // filter 0
    CAN_FILTER_2_CHANNEL_LINK_1(3, 0, 3);             // filter 0, mask0, FIFO channel2
    
    
    // Filter enable    
    CAN_ENABLE_FILTER_1(0);
    CAN_ENABLE_FILTER_1(1);
    CAN_ENABLE_FILTER_1(2);
    CAN_ENABLE_FILTER_1(3);
    
    // *** *** *** *** *** *** Filter *** *** *** *** *** *** //
    
        
    C1CONbits.REQOP = 0b000;         // switch the CAN module to normal mode.
    while(C1CONbits.OPMOD != 0b000); // wait until the switch is complete

    // set the interrupt
    C1INTbits.RBIE = 1;             // receive interrupt
    
    IPC37bits.CAN1IP = 4;           // priority level
    IPC37bits.CAN1IS = 1;           // subpriority level
    IFS4bits.CAN1IF = 0;            // interrupt flag clear
    IEC4bits.CAN1IE = 1;            // interrupt enable
}


/*****************************************************************************
 * Initialize CAN 1 peripheral
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_CAN2(void)
{
    C2CONbits.ON = 1;

    C2CONbits.REQOP = 0x04;
    while(C2CONbits.OPMOD != 0x04);

    C2CFGbits.SEG2PHTS = 1;
    C2CFGbits.PRSEG = 0;
    C2CFGbits.SEG1PH = 3;
    C2CFGbits.SEG2PH = 3;
    C2CFGbits.SJW = 0;
    C2CFGbits.SAM = 1;
    //500kbps
    C2CFGbits.BRP = 9;


    C2FIFOBA = KVA_TO_PA(can_message_buffer1); 

    C2FIFOCON0bits.FSIZE = 15;
    C2FIFOCON0bits.TXEN = 1;
    C2FIFOCON1bits.FSIZE = 15;
    C2FIFOCON1bits.TXEN = 1;

    CAN_RECEIVE_CHANNEL_SET_2(2, 16);
    CAN_RECEIVE_CHANNEL_SET_2(3, 16);

    C2FIFOINT2bits.RXNEMPTYIE = 1;
    C2FIFOINT3bits.RXNEMPTYIE = 1;

    int filter_num;
    for(filter_num = 0; filter_num < 32; filter_num++){
        CAN_DISABLE_FILTER_2(filter_num);
    }

    CAN_FILTER_MASK_CONFIG_2(0, 0b001111111111);

    CAN_FILTER_CONFIG_2(4, 0x223);
    CAN_FILTER_2_CHANNEL_LINK_2(4, 0, 3);
    
    CAN_FILTER_CONFIG_2(5, 0x222);
    CAN_FILTER_2_CHANNEL_LINK_2(5, 0, 3);
    
    CAN_FILTER_CONFIG_2(6, CAN_ID_SF_MCU_1_CMD);
    CAN_FILTER_2_CHANNEL_LINK_2(6, 0, 2);
    CAN_FILTER_CONFIG_2(7, CAN_ID_SF_MCU_2_CMD);
    CAN_FILTER_2_CHANNEL_LINK_2(7, 0, 3);

    CAN_FILTER_CONFIG_2(8, 0x770);
    CAN_FILTER_2_CHANNEL_LINK_2(8, 0, 3);

    CAN_FILTER_CONFIG_2(9, 0x771);
    CAN_FILTER_2_CHANNEL_LINK_2(9, 0, 3);

    CAN_FILTER_CONFIG_2(10, 0x773);
    CAN_FILTER_2_CHANNEL_LINK_2(10, 0, 3);

    CAN_FILTER_CONFIG_2(11, 0x777);
    CAN_FILTER_2_CHANNEL_LINK_2(11, 0, 3);

    CAN_FILTER_CONFIG_2(12, 0x702);
    CAN_FILTER_2_CHANNEL_LINK_2(12, 0, 3);
 
    CAN_ENABLE_FILTER_2(4);
    CAN_ENABLE_FILTER_2(5);
    CAN_ENABLE_FILTER_2(6);
    CAN_ENABLE_FILTER_2(7);
    CAN_ENABLE_FILTER_2(8);
    CAN_ENABLE_FILTER_2(9);
    CAN_ENABLE_FILTER_2(10);
    CAN_ENABLE_FILTER_2(11);
    CAN_ENABLE_FILTER_2(12);

    
    C2CONbits.REQOP = 0b000;
    while(C2CONbits.OPMOD != 0b000);

    C2INTbits.RBIE = 1;
    IPC38bits.CAN2IP = 5;
    IPC38bits.CAN2IS = 1;
    IFS4bits.CAN2IF = 0;
    IEC4bits.CAN2IE = 1;
}



/*****************************************************************************
 * Initialize SPI 2
 * Input : bit_type 8/16/32
 *       : mode (0~3)
 * Return : void
 *****************************************************************************/
void Initialize_Spi2(unsigned int bit_type, unsigned int mode){
    // bit : SPI data length, 8 or 16 or 32
    char bit_mode[2];
    if(bit_type == 8){
        bit_mode[0] = 0;
        bit_mode[1] = 0;
    }else if(bit_type == 16){
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }else if(bit_type == 32){
        bit_mode[0] = 0;
        bit_mode[1] = 1;
    }else{
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }
    // mode : SPI operation mode
    // 0 = idle low & rising edge
    // 1 = idle low & falling edge
    // 2 = idle high & falling edge
    // 3 = idle high & rising edge
    char mode_selec[2];
    if(mode == 0){
        mode_selec[0] = 0;
        mode_selec[1] = 0;
    }else if(mode == 1){
        mode_selec[0] = 0;
        mode_selec[1] = 1;
    }else if(mode == 2){
        mode_selec[0] = 1;
        mode_selec[1] = 0;
    }else if(mode == 3){
        mode_selec[0] = 1;
        mode_selec[1] = 1;
    }
        
    // Register setting
    SPI2BRG = 14;                    // Fsck = Fpb/(2*(SPIxBRG+1)), Fpb = peripheral bus clock(100MHz)
    SPI2STATCLR=0x40;               // clear the Overflow
    SPI2CON = 0x0000;               // clear the register
    int dummy = SPI2BUF;            // clear the buffer by using dummy
    SPI2CONbits.MSTEN = 1;          // 1 = master mode / 0 = slave mode
    SPI2CONbits.MODE16 = bit_mode[0];
    SPI2CONbits.MODE32 = bit_mode[1];
    SPI2CONbits.SMP = 0;//1;            // 1 = input data sampled at "end" of data output time/ 0 = middle
    SPI2CONbits.CKP = mode_selec[0];
    SPI2CONbits.CKE = mode_selec[1];
    SPI2CONbits.ON = 1;             // SPI Start
}



/*****************************************************************************
 * Initialize SPI 4 for Master
 * Input : bit_type 8/16/32
 *       : mode (0~3)
 * Return : void
 *****************************************************************************/
void Initialize_Spi4Master(unsigned int bit_type, unsigned int mode){
    // bit : SPI data length, 8 or 16 or 32
    char bit_mode[2];
    if(bit_type == 8){
        bit_mode[0] = 0;
        bit_mode[1] = 0;
    }else if(bit_type == 16){
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }else if(bit_type == 32){
        bit_mode[0] = 0;
        bit_mode[1] = 1;
    }else{
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }
    // mode : SPI operation mode
    // 0 = idle low & rising edge
    // 1 = idle low & falling edge
    // 2 = idle high & falling edge
    // 3 = idle high & rising edge
    char mode_selec[2];
    if(mode == 0){
        mode_selec[0] = 0;
        mode_selec[1] = 0;
    }else if(mode == 1){
        mode_selec[0] = 0;
        mode_selec[1] = 1;
    }else if(mode == 2){
        mode_selec[0] = 1;
        mode_selec[1] = 0;
    }else if(mode == 3){
        mode_selec[0] = 1;
        mode_selec[1] = 1;
    }
        
    // Register setting
    SPI4BRG = 24;                    // Fsck = Fpb/(2*(SPIxBRG+1)), Fpb = peripheral bus clock(100MHz)
    SPI4STATCLR=0x40;               // clear the Overflow
    SPI4CON = 0x0000;               // clear the register
    int dummy = SPI4BUF;            // clear the buffer by using dummy
    SPI4CONbits.MSTEN = 1;          // 1 = master mode / 0 = slave mode
    SPI4CONbits.MODE16 = bit_mode[0];
    SPI4CONbits.MODE32 = bit_mode[1];
    SPI4CONbits.SMP = 1;            // 1 = input data sampled at "end" of data output time/ 0 = middle
    SPI4CONbits.CKP = mode_selec[0];
    SPI4CONbits.CKE = mode_selec[1];
    SPI4CONbits.ON = 1;             // SPI Start
}


/*****************************************************************************
 * Initialize SPI 4 for Slave
 * Input : bit_type 8/16/32
 *       : mode (0~3)
 * Return : void
 *****************************************************************************/
void Initialize_Spi4Slave(unsigned int bit_type, unsigned int mode){
    // bit : SPI data length, 8 or 16 or 32
    char bit_mode[2];
    if(bit_type == 8){
        bit_mode[0] = 0;
        bit_mode[1] = 0;
    }else if(bit_type == 16){
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }else if(bit_type == 32){
        bit_mode[0] = 0;
        bit_mode[1] = 1;
    }else{
        bit_mode[0] = 1;
        bit_mode[1] = 0;
    }
    // mode : SPI operation mode
    // 0 = idle low & rising edge
    // 1 = idle low & falling edge
    // 2 = idle high & falling edge
    // 3 = idle high & rising edge
    char mode_selec[2];
    if(mode == 0){
        mode_selec[0] = 0;
        mode_selec[1] = 0;
    }else if(mode == 1){
        mode_selec[0] = 0;
        mode_selec[1] = 1;
    }else if(mode == 2){
        mode_selec[0] = 1;
        mode_selec[1] = 0;
    }else if(mode == 3){
        mode_selec[0] = 1;
        mode_selec[1] = 1;
    }
        
    
    // Register setting
    SPI4BRG = 24;                    // Fsck = Fpb/(2*(SPIxBRG+1)), Fpb = peripheral bus clock(100MHz)
    SPI4STATCLR=0x40;               // clear the Overflow
    SPI4CON = 0x0000;               // clear the register
    int dummy = SPI4BUF;            // clear the buffer by using dummy
    SPI4CONbits.MSTEN = 0;          // 1 = master mode / 0 = slave mode
    SPI4CONbits.MODE16 = bit_mode[0];
    SPI4CONbits.MODE32 = bit_mode[1];
    SPI4CONbits.SMP = 1;            // 1 = input data sampled at "end" of data output time/ 0 = middle
    SPI4CONbits.CKP = mode_selec[0];
    SPI4CONbits.CKE = mode_selec[1];
    SPI4CONbits.SSEN = 1;
    SPI4CONbits.ON = 1;             // SPI Start
    
    IPC41bits.SPI4RXIP = 1;
    IPC41bits.SPI4RXIS = 0;
    IFS5bits.SPI4RXIF = 0;
    IEC5bits.SPI4RXIE = 1;
}

//
///*****************************************************************************
// * Initialize SPI 4 for Slave
// * Input : bit_type 8/16/32
// *       : mode (0~3)
// * Return : void
// *****************************************************************************/
//void Initialize_Spi4Slave(unsigned int bit_type, unsigned int mode){
//    // bit : SPI data length, 8 or 16 or 32
//    char bit_mode[2];
//    if(bit_type == 8){
//        bit_mode[0] = 0;
//        bit_mode[1] = 0;
//    }else if(bit_type == 16){
//        bit_mode[0] = 1;
//        bit_mode[1] = 0;
//    }else if(bit_type == 32){
//        bit_mode[0] = 0;
//        bit_mode[1] = 1;
//    }else{
//        bit_mode[0] = 1;
//        bit_mode[1] = 0;
//    }
//    // mode : SPI operation mode
//    // 0 = idle low & rising edge
//    // 1 = idle low & falling edge
//    // 2 = idle high & falling edge
//    // 3 = idle high & rising edge
//    char mode_selec[2];
//    if(mode == 0){
//        mode_selec[0] = 0;
//        mode_selec[1] = 0;
//    }else if(mode == 1){
//        mode_selec[0] = 0;
//        mode_selec[1] = 1;
//    }else if(mode == 2){
//        mode_selec[0] = 1;
//        mode_selec[1] = 0;
//    }else if(mode == 3){
//        mode_selec[0] = 1;
//        mode_selec[1] = 1;
//    }
//        
////    SPI4BRG = 9;                    // Fsck = Fpb/(2*(SPIxBRG+1)), Fpb = peripheral bus clock(100MHz)
//    SPI4STATCLR=0x40;               // clear the Overflow
//    SPI4CON = 0x0000;               // clear the register
//    int dummy = SPI4BUF;            // clear the buffer by using dummy
//    SPI4CONbits.MSTEN = 0;          // 1 = master mode / 0 = slave mode
//    SPI4CONbits.MODE16 = bit_mode[0];
//    SPI4CONbits.MODE32 = bit_mode[1];
//    SPI4CONbits.SMP = 1;            // 1 = input data sampled at "end" of data output time/ 0 = middle
//    SPI4CONbits.CKP = mode_selec[0];
//    SPI4CONbits.CKE = mode_selec[1];
//    SPI4CONbits.SSEN = 1;
//    SPI4CONbits.ON = 1;             // SPI Start
//    
//    IPC41bits.SPI4RXIP = 1;
//    IPC41bits.SPI4TXIS = 0;
//    IFS5bits.SPI4RXIF = 0;
//    IEC5bits.SPI4RXIE = 1;
//}

/*****************************************************************************
 * Initialize Analog to Digital (ADC) peripheral
 * Input : void
 * Return : void
 *****************************************************************************/
void Initialize_ADC(void){
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC1CFG = DEVADC2;
//    ADC7CFG = DEVADC7;
    
    // Configure ADCCON1
    ADCCON1 = 0;                    // init ADCCON1
    ADCCON1bits.SELRES = 0b11;      // ADC7 resolution is 12 bits
    ADCCON1bits.STRGSRC = 1;        // Global Software Trigger (GSWTRG) is self-cleared on the next clock cycle
    
    // Configure ADCCON2
    ADCCON2 = 0;                    // init ADCCON2
    ADCCON2bits.SAMC = 3;           // ADC7 sampling time = 5 * TAD7
    ADCCON2bits.ADCDIV = 1;         // ADC7 clock freq is half of control clock = TAD7
    
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 1;    // wake up clock = 2^5*Tad
    
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0b00;      // Tclk source
    // 00 PBCLK
    // 01 FRC
    // 10 REFCLK3
    // 11 SystemCLK
    ADCCON3bits.CONCLKDIV = 1;      // Tq = (CONCLKDIV*2)*Tclk
    ADCCON3bits.VREFSEL = 0;        // SET Vref = basic

//    ADC3TIMEbits.ADCDIV = 1;        // Tad = (ADCDIV*2)*Tq
//    ADC3TIMEbits.SAMC = 3;          // Sampling time = (SAMC+2)*Tad
//    ADC3TIMEbits.SELRES = 0b11;     // resolution 12bit
//    // 11 = 12
//    // 10 = 10
    
    ADC0TIMEbits.ADCDIV = 1;
    ADC0TIMEbits.SAMC = 5;
    ADC0TIMEbits.SELRES = 0b11;
    ADCTRGMODEbits.SH0ALT = 0;      // AN0
    ADCIMCON1bits.SIGN0 = 0;        // AN0 is using unsigned data mode
    ADCIMCON1bits.DIFF0 = 0;        // AN0 is using single ended mode

    ADC1TIMEbits.ADCDIV = 1;
    ADC1TIMEbits.SAMC = 5;
    ADC1TIMEbits.SELRES = 0b11;
    ADCTRGMODEbits.SH1ALT = 0;      // AN1
    ADCIMCON1bits.SIGN1 = 0;        // AN1 is using unsigned data mode
    ADCIMCON1bits.DIFF1 = 0;        // AN1 is using single ended mode

    ADC2TIMEbits.ADCDIV = 1;
    ADC2TIMEbits.SAMC = 5;
    ADC2TIMEbits.SELRES = 0b11;    
    ADCTRGMODEbits.SH2ALT = 0;      // AN2
    ADCIMCON1bits.SIGN2 = 0;        // AN2 is using unsigned data mode
    ADCIMCON1bits.DIFF2 = 0;        // AN2 is using single ended mode
    
//    ADCTRGMODEbits.SH3ALT = 0b01;      // AN48 !!!!!
//    ADCIMCON1bits.SIGN3 = 0;        // AN3 is using unsigned data mode
//    ADCIMCON1bits.DIFF3 = 0;        // AN3 is using single ended mode
    
//    ADCTRGMODEbits.SH4ALT = 0;      // AN4
//    ADCIMCON1bits.SIGN4 = 0;        // AN4 is using unsigned data mode
//    ADCIMCON1bits.DIFF4 = 0;        // AN4 is using single ended mode
    
//    ADCIMCON1bits.SIGN5 = 0;        // AN5 is using unsigned data mode
//    ADCIMCON1bits.DIFF5 = 0;        // AN5 is using single ended mode
//    
//    ADCIMCON1bits.SIGN6 = 0;        // AN6 is using unsigned data mode
//    ADCIMCON1bits.DIFF6 = 0;        // AN6 is using single ended mode
//    
//    ADCIMCON1bits.SIGN7 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF7 = 0;        // AN7 is using single ended mode
    
//    ADCIMCON1bits.SIGN12 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF12 = 0;        // AN7 is using single ended mode
//    
//    ADCIMCON1bits.SIGN13 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF13 = 0;        // AN7 is using single ended mode
//    
//    ADCIMCON1bits.SIGN14 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF14 = 0;        // AN7 is using single ended mode
//    
//    ADCIMCON1bits.SIGN15 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF15 = 0;        // AN7 is using single ended mode
    
//    ADCIMCON1bits.SIGN48 = 0;        // AN7 is using unsigned data mode
//    ADCIMCON1bits.DIFF48 = 0;        // AN7 is using single ended mode
    
    
    ADCGIRQEN1 = 0;                 // no interrupt
    ADCGIRQEN2 = 0;
    
    ADCCSS1 = 0;                    // no scan
    ADCCSS2 = 0;
    
    ADCCSS1bits.CSS0 = 1;           // AN0 (class 1) set for scan
    ADCCSS1bits.CSS1 = 1;           // AN1 (class 1) set for scan
    ADCCSS1bits.CSS2 = 1;           // AN2 (class 1) set for scan
//    ADCCSS1bits.CSS3 = 1;           // AN3 (class 1) set for scan
//    ADCCSS1bits.CSS4 = 1;           // AN4 (class 1) set for scan
//    ADCCSS1bits.CSS5 = 1;           // AN5 (class 1) set for scan
//    ADCCSS1bits.CSS6 = 1;           // AN6 (class 1) set for scan
//    ADCCSS1bits.CSS7 = 1;           // AN7 (class 1) set for scan
//    ADCCSS1bits.CSS12 = 1;
//    ADCCSS1bits.CSS13 = 1;
//    ADCCSS1bits.CSS14 = 1;
//    ADCCSS1bits.CSS15 = 1;
    

    ADCCMPCON1 = 0;                 // no digital comparators
    ADCCMPCON2 = 0;
    ADCCMPCON3 = 0;
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;

    ADCFLTR1 = 0;                   // no oversampling filters
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;

    ADCTRGSNSbits.LVL0 = 0;         // edge trigger
    ADCTRGSNSbits.LVL2 = 0;         // edge trigger
    ADCTRGSNSbits.LVL3 = 0;         // edge trigger
    ADCTRGSNSbits.LVL4 = 0;         // edge trigger
    ADCTRGSNSbits.LVL5 = 0;         // edge trigger
    ADCTRGSNSbits.LVL6 = 0;         // edge trigger
    
    ADCTRG1bits.TRGSRC0 = 0b11;     // AN0 set scan triger (STRIG)
    ADCTRG1bits.TRGSRC1 = 0b11;     // AN1 set scan triger (STRIG)
    ADCTRG1bits.TRGSRC2 = 0b11;     // AN2 set scan triger (STRIG)
//    ADCTRG1bits.TRGSRC3 = 0b11;     // AN3 set scan triger (STRIG)
//    ADCTRG2bits.TRGSRC4 = 0b11;     // AN4 set scan triger (STRIG)
//    ADCTRG2bits.TRGSRC5 = 0b11;     // AN5 set scan triger (STRIG)
//    ADCTRG2bits.TRGSRC6 = 0b11;     // AN6 set scan triger (STRIG)
//    ADCTRG2bits.TRGSRC7 = 0b01;     // AN7 set scan triger (STRIG)

    ADCEIEN1 = 0;                   // no early interrupt
    ADCEIEN2 = 0;
    
    ADCCON1bits.ON = 1;             // On
    
    while(!ADCCON2bits.BGVRRDY);    // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT);      // Wait if there is a fault with the reference voltage
    
    ADCANCONbits.ANEN0 = 1;         // ADC0 enable the clock to analog bias
    ADCANCONbits.ANEN1 = 1;         // ADC1 enable the clock to analog bias
    ADCANCONbits.ANEN2 = 1;         // ADC2 enable the clock to analog bias
//    ADCANCONbits.ANEN3 = 1;         // ADC3 enable the clock to analog bias
//    ADCANCONbits.ANEN4 = 1;         // ADC4 enable the clock to analog bias
//    ADCANCONbits.ANEN7 = 1;         // ADC7 enable the clock to analog bias
    
    while(!ADCANCONbits.WKRDY0);    // ADC0 wait until module is ready
    while(!ADCANCONbits.WKRDY1);    // ADC1 wait until module is ready
    while(!ADCANCONbits.WKRDY2);    // ADC2 wait until module is ready
//    while(!ADCANCONbits.WKRDY3);    // ADC3 wait until module is ready
//    while(!ADCANCONbits.WKRDY4);    // ADC4 wait until module is ready
//    while(!ADCANCONbits.WKRDY7);    // ADC7 wait until module is ready

    ADCCON3bits.DIGEN0 = 1;         // ADC0 enable
    ADCCON3bits.DIGEN1 = 1;         // ADC1 enable
    ADCCON3bits.DIGEN2 = 1;         // ADC2 enable
//    ADCCON3bits.DIGEN3 = 1;         // ADC3 enable
//    ADCCON3bits.DIGEN4 = 1;         // ADC4 enable
//    ADCCON3bits.DIGEN7 = 1;         // ADC7 enable
    
   
}

/*****************************************************************************
 * Initialize UART 1 peripheral
 * Input : baudRate (~)
 *       : stop_bit (1)
 *       : parity (0)
 * Return : void
 *****************************************************************************/
void Initialize_UART1(unsigned int baudRate, unsigned int stop_bit, unsigned int parity_mode){
    // baudRate = XX (bps)
    
    // stop_bit = 1 or 2
    
    // parity_mode 0 = none
    //             1 = odd
    //             2 = even                   
    
    // clear uart
    U1MODE = 0;
    
    // setting
    U1MODEbits.UEN = 0;             // RXTX mode
    U1STAbits.UTXISEL0=0;           // UART_INTERRUPT_ON_TX_NOT_FULL
	U1STAbits.UTXISEL1=0;           // UART_INTERRUPT_ON_TX_NOT_FULL
    U1STAbits.URXISEL = 0;          // Rx interrupt mode selection
    U1STAbits.URXISEL0 = 0;
    U1STAbits.URXISEL1 = 0;
    //U1MODEbits.RTSMD = 0;
    
    
    if(parity_mode == 0){
        // 8bit+none
        U1MODEbits.PDSEL = 0b00;
    }else if(parity_mode == 1){
        // 8bit+odd
        U1MODEbits.PDSEL = 0b10;
    }else if(parity_mode == 2){
        // 8bit+even
        U1MODEbits.PDSEL = 0b01;
    }
    U1MODEbits.STSEL = stop_bit - 1;
    U1MODEbits.BRGH = 0;            // standard mode
    
    if(baudRate > 230400){
        U1MODEbits.BRGH = 1;
        U1BRG = (unsigned int)(((double)PBCLK)/((double)baudRate)/4. - 1.);
    }else{
        U1MODEbits.BRGH = 0;
        U1BRG = (unsigned int)(((double)PBCLK)/((double)baudRate)/16. - 1.);
    }

    U1STAbits.UTXEN = 1;            // enable TX
    U1STAbits.URXEN = 1;            // enalbe RX
    U1MODEbits.ON = 1;              // enable U1  
}




void GPIO_DIN_TRIS_0(unsigned char dir){
    TRIS_DIN_08 = dir;  // Din 08
    TRIS_DIN_09 = dir;  // Din 09
    TRIS_DIN_10 = dir;  // Din 10
    TRIS_DIN_11 = dir;  // Din 11
    TRIS_DIN_12 = dir;  // Din 12
    TRIS_DIN_13 = dir;  // Din 13
    TRIS_DIN_14 = dir;  // Din 14
    TRIS_DIN_15 = dir;  // Din 15
}

void GPIO_DIN_TRIS_1(unsigned char dir){
    TRIS_DIN_00 = dir;  // Din 00
    TRIS_DIN_01 = dir;  // Din 01
    TRIS_DIN_02 = dir;  // Din 02
    TRIS_DIN_03 = dir;  // Din 03
    TRIS_DIN_04 = dir;  // Din 04
    TRIS_DIN_05 = dir;  // Din 05
    TRIS_DIN_06 = dir;  // Din 06
    TRIS_DIN_07 = dir;  // Din 07
}


int GPIO_DIN_INIT_CHIP_0(void){
    int err_global = 0;
    int err_internal = 0;
    int err_check_result = 0;
    
    int dummy_var = 0;
    
    LAT_DIN_CS_B = LOW;
    // Reset Global error ------------------------------------------------------
    
    GPIO_DIN_TRIS_0(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_B = HIGH;
    LAT_DIN_15 = 0;
    LAT_DIN_14 = 0;
    LAT_DIN_13 = 0;
    LAT_DIN_12 = 0;
    LAT_DIN_11 = 0;
    LAT_DIN_10 = 1;
    LAT_DIN_09 = 0;
    LAT_DIN_08 = 0;
    LAT_DIN_ALE_B = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_0(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_B = LOW;
    WAIT_10NSEC(10);    
    dummy_var = PORT_DIN_08;
    dummy_var = PORT_DIN_09;
    dummy_var = PORT_DIN_10;
    dummy_var = PORT_DIN_11;
    dummy_var = PORT_DIN_12;
    dummy_var = PORT_DIN_13;
    dummy_var = PORT_DIN_14;
    dummy_var = PORT_DIN_15;
    LAT_DIN_RD_B = HIGH;
    WAIT_10NSEC(10000);
    
    // Check Global error register ---------------------------------------------
    GPIO_DIN_TRIS_0(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_B = HIGH;
    LAT_DIN_15 = 0;
    LAT_DIN_14 = 0;
    LAT_DIN_13 = 0;
    LAT_DIN_12 = 0;
    LAT_DIN_11 = 0;
    LAT_DIN_10 = 1;
    LAT_DIN_09 = 0;
    LAT_DIN_08 = 0;
    LAT_DIN_ALE_B = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_0(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_B = LOW;
    WAIT_10NSEC(10);
    err_global += PORT_DIN_08;
    err_global += PORT_DIN_09;
    err_global += PORT_DIN_10;
    err_global += PORT_DIN_11;
    err_global += PORT_DIN_12;
    err_global += PORT_DIN_13;
    err_global += PORT_DIN_14;
    err_global += PORT_DIN_15;
    LAT_DIN_RD_B = HIGH;
    WAIT_10NSEC(10000);
    
    // Reset Internal error ----------------------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    LAT_DIN_ALE_B = HIGH;
    LAT_DIN_15 = 0;
    LAT_DIN_14 = 0;
    LAT_DIN_13 = 0;
    LAT_DIN_12 = 1;
    LAT_DIN_11 = 0;
    LAT_DIN_10 = 1;
    LAT_DIN_09 = 1;
    LAT_DIN_08 = 0;
    LAT_DIN_ALE_B = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_0(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_B = LOW;
    WAIT_10NSEC(10);    
    dummy_var = PORT_DIN_08;
    dummy_var = PORT_DIN_09;
    dummy_var = PORT_DIN_10;
    dummy_var = PORT_DIN_11;
    dummy_var = PORT_DIN_12;
    dummy_var = PORT_DIN_13;
    dummy_var = PORT_DIN_14;
    dummy_var = PORT_DIN_15;
    LAT_DIN_RD_B = HIGH;
    WAIT_10NSEC(10000);  

    // Clear Internal error register -------------------------------------------
    GPIO_DIN_TRIS_0(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_B = HIGH;
    LAT_DIN_15 = 0;
    LAT_DIN_14 = 0;
    LAT_DIN_13 = 0;
    LAT_DIN_12 = 1;
    LAT_DIN_11 = 0;
    LAT_DIN_10 = 1;
    LAT_DIN_09 = 1;
    LAT_DIN_08 = 0;
    LAT_DIN_ALE_B = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_0(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_B = LOW;
    WAIT_10NSEC(10);
    err_internal += PORT_DIN_08;
    err_internal += PORT_DIN_09;
    err_internal += PORT_DIN_10;
    err_internal += PORT_DIN_11;
    err_internal += PORT_DIN_12;
    err_internal += PORT_DIN_13;
    err_internal += PORT_DIN_14;
    err_internal += PORT_DIN_15;
    LAT_DIN_RD_B = HIGH;
    WAIT_10NSEC(10000);
    
    // Change target register to DATA mode -------------------------------------
    GPIO_DIN_TRIS_0(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_B = HIGH;
    LAT_DIN_15 = 0;
    LAT_DIN_14 = 0;
    LAT_DIN_13 = 0;
    LAT_DIN_12 = 0;
    LAT_DIN_11 = 0;
    LAT_DIN_10 = 0;
    LAT_DIN_09 = 1;
    LAT_DIN_08 = 0;
    LAT_DIN_ALE_B = LOW;
    WAIT_10NSEC(10000);
    GPIO_DIN_TRIS_0(INPUT);
    WAIT_10NSEC(1);
    
    // terminate ---------------------------------------------------------------
    LAT_DIN_CS_B = HIGH;
    WAIT_10NSEC(10000);
    err_check_result = err_global + err_internal;
    
    return err_check_result;
}


int GPIO_DIN_INIT_CHIP_1(void){
    int err_global = 0;
    int err_internal = 0;
    int err_check_result = 0;
    
    int dummy_var = 0;
    
    LAT_DIN_CS_A = LOW;
    // Reset Global error ------------------------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_A = HIGH;
    LAT_DIN_07 = 0;
    LAT_DIN_06 = 0;
    LAT_DIN_05 = 0;
    LAT_DIN_04 = 0;
    LAT_DIN_03 = 0;
    LAT_DIN_02 = 1;
    LAT_DIN_01 = 0;
    LAT_DIN_00 = 0;
    LAT_DIN_ALE_A = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_1(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_A = LOW;
    WAIT_10NSEC(10);
    dummy_var = PORT_DIN_02;
    dummy_var = PORT_DIN_00;
    dummy_var = PORT_DIN_03;
    dummy_var = PORT_DIN_01;
    dummy_var = PORT_DIN_04;
    dummy_var = PORT_DIN_05;
    dummy_var = PORT_DIN_06;
    dummy_var = PORT_DIN_07;
    LAT_DIN_RD_A = HIGH;
    WAIT_10NSEC(10000);
    
    // Check Global error register ---------------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_A = HIGH;
    LAT_DIN_07 = 0;
    LAT_DIN_06 = 0;
    LAT_DIN_05 = 0;
    LAT_DIN_04 = 0;
    LAT_DIN_03 = 0;
    LAT_DIN_02 = 1;
    LAT_DIN_01 = 0;
    LAT_DIN_00 = 0;
    LAT_DIN_ALE_A = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_1(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_A = LOW;
    WAIT_10NSEC(10);
    err_global += PORT_DIN_00;
    err_global += PORT_DIN_01;
    err_global += PORT_DIN_02;
    err_global += PORT_DIN_03;
    err_global += PORT_DIN_04;
    err_global += PORT_DIN_05;
    err_global += PORT_DIN_06;
    err_global += PORT_DIN_07;
    LAT_DIN_RD_A = HIGH;
    WAIT_10NSEC(10000);
    
    // Reset Internal error ----------------------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_A = HIGH;
    LAT_DIN_07 = 0;
    LAT_DIN_06 = 0;
    LAT_DIN_05 = 0;
    LAT_DIN_04 = 1;
    LAT_DIN_03 = 0;
    LAT_DIN_02 = 1;
    LAT_DIN_01 = 1;
    LAT_DIN_00 = 0;
    LAT_DIN_ALE_A = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_1(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_A = LOW;
    WAIT_10NSEC(10);
    
    dummy_var = PORT_DIN_00;
    dummy_var = PORT_DIN_01;
    dummy_var = PORT_DIN_02;
    dummy_var = PORT_DIN_03;
    dummy_var = PORT_DIN_04;
    dummy_var = PORT_DIN_05;
    dummy_var = PORT_DIN_06;
    dummy_var = PORT_DIN_07;
    LAT_DIN_RD_A = HIGH;
    WAIT_10NSEC(10000);  

    // Clear Internal error register -------------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_A = HIGH;
    LAT_DIN_07 = 0;
    LAT_DIN_06 = 0;
    LAT_DIN_05 = 0;
    LAT_DIN_04 = 1;
    LAT_DIN_03 = 0;
    LAT_DIN_02 = 1;
    LAT_DIN_01 = 1;
    LAT_DIN_00 = 0;
    LAT_DIN_ALE_A = LOW;
    WAIT_10NSEC(10000);
    
    GPIO_DIN_TRIS_1(INPUT);
    WAIT_10NSEC(1);
    LAT_DIN_RD_A = LOW;
    WAIT_10NSEC(10);
    err_internal += PORT_DIN_00;
    err_internal += PORT_DIN_01;
    err_internal += PORT_DIN_02;
    err_internal += PORT_DIN_03;
    err_internal += PORT_DIN_04;
    err_internal += PORT_DIN_05;
    err_internal += PORT_DIN_06;
    err_internal += PORT_DIN_07;
    LAT_DIN_RD_A = HIGH;
    WAIT_10NSEC(10000);
    
    // Change target register to DATA mode -------------------------------------
    GPIO_DIN_TRIS_1(OUTPUT);
    WAIT_10NSEC(1);
    LAT_DIN_ALE_A = HIGH;
    LAT_DIN_07 = 0;
    LAT_DIN_06 = 0;
    LAT_DIN_05 = 0;
    LAT_DIN_04 = 0;
    LAT_DIN_03 = 0;
    LAT_DIN_02 = 0;
    LAT_DIN_01 = 1;
    LAT_DIN_00 = 0;
    LAT_DIN_ALE_A = LOW;
    WAIT_10NSEC(10000);
    GPIO_DIN_TRIS_1(INPUT);
    WAIT_10NSEC(1);
    
    // terminate ---------------------------------------------------------------
    LAT_DIN_CS_A = HIGH;
    WAIT_10NSEC(10000);
    err_check_result = err_global + err_internal;
    
    return err_check_result;
}




