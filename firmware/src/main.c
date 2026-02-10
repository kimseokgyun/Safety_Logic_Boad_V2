/*******************************************************************************
  MPLAB Harmony Project Main Source File

  Company:
    Microchip Technology Inc.
  
  File Name:
    main.c

  Summary:
    This file contains the "main" function for an MPLAB Harmony project.

  Description:
    This file contains the "main" function for an MPLAB Harmony project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state 
    machines of all MPLAB Harmony modules in the system and it calls the 
    "SYS_Tasks" function from within a system-wide "super" loop to maintain 
    their correct operation. These two functions are implemented in 
    configuration-specific files (usually "system_init.c" and "system_tasks.c")
    in a configuration-specific folder under the "src/system_config" folder 
    within this project's top-level folder.  An MPLAB Harmony project may have
    more than one configuration, each contained within it's own folder under
    the "system_config" folder.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

//Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <math.h>

#include "system/common/sys_module.h"   // SYS function prototypes
#include "system_general_configuration.h"

#include "classb/classb.h"

#define APPLICATION_START_VA 0x9D000000

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

unsigned int SF_MCU_NUM = MCU_0;  // 0 or 1

FRIEND_STRUCTURE _fboard;       // friend board status
BOARD_STRUCTURE _mboard;        // my board status

// 2025-08-26
const unsigned int __attribute__((section(".crc_value"))) FLASH_CRC_REF ;


int din_chip_tiktok = 0;
int dac_chip_tiktok = 0;
int adc_chip_tiktok = 0;


void DigitalInputHandler();
void DigitalOutputHandler();

volatile struct  ClassB_Test_Flags 
{
    unsigned cpuRegister_TestResult : 1;
    unsigned programCounter_TestResult:1;
    unsigned checkerboardRam_TestResult:1;
    unsigned marchCRam_TestResult:1;
    unsigned marchCMinusRam_TestResult:1;
    unsigned marchCRamStack_TestResult:1;
    unsigned marchBRam_TestResult:1;
    unsigned flash_TestResult:1;
    unsigned clock_TestResult:1;
    unsigned clockLine_TestResult:1;
} testFlag;

void ClassBTest();


int main ( void )
{
    // apply initial delay for stable operation ---
    int initial_delay;
    for(initial_delay=0; initial_delay<100000; initial_delay++)
        ;
    for(initial_delay=0; initial_delay<100000; initial_delay++)
        ;
    volatile int initial_delay2 = 24000000;
    while(initial_delay2--)
        ;
    // --------------------------------------------
    
    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize ( NULL );


    // Class B Library
//    ClassBTest();
    
    Initialize_ParameterTable();
    Initialize_PinDefinition();
        
    Task_Control_Pre_FET_Off();
    Task_Control_Main_FET_Off();
    Task_Control_Lift_Pre_FET_Off();
    Task_Control_Lift_Main_FET_Off();
    
    Initialize_Peripherals();

    
    
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
//        SYS_Tasks ( );
        DigitalInputHandler();
        DigitalOutputHandler();
        
        
        static unsigned int ttt = 0;
        ttt++;
        
//        if(ttt%1000 == 0)
//        {
//            if(_mboard.type == MCU_0)
//            {
//                unsigned char data[8];
//                data[0] = testFlag.cpuRegister_TestResult;
//                data[1] = testFlag.programCounter_TestResult;
//                data[2] = testFlag.checkerboardRam_TestResult;
//                data[3] = testFlag.marchBRam_TestResult;
//                data[4] = testFlag.marchCRamStack_TestResult;
//                data[5] = testFlag.flash_TestResult;
//                data[6] = testFlag.clock_TestResult;
//                data[7] = testFlag.clockLine_TestResult;
//                CAN_WRITE_2(0x380, 8, data);
//            }
//            else
//            {
//                unsigned char data[8];
//                data[0] = testFlag.cpuRegister_TestResult;
//                data[1] = testFlag.programCounter_TestResult;
//                data[2] = testFlag.checkerboardRam_TestResult;
//                data[3] = testFlag.marchBRam_TestResult;
//                data[4] = testFlag.marchCRamStack_TestResult;
//                data[5] = testFlag.flash_TestResult;
//                data[6] = testFlag.clock_TestResult;
//                data[7] = testFlag.clockLine_TestResult;
//                CAN_WRITE_2(0x381, 8, data);
//            }
//        }
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}
 


void DigitalInputHandler()
{
    if(din_chip_tiktok == 1000){
        din_chip_tiktok = 0;

        // Init Din
        if(_mboard.type == MCU_0){
            LAT_DIN_ALE_B = LOW;
            LAT_DIN_CS_B = HIGH;
            LAT_DIN_RD_B = HIGH;
            WAIT_10NSEC(5000);
            int temp_di_check_0 = GPIO_DIN_INIT_CHIP_0();
            if(temp_di_check_0 != 0){
                // TURN_OFF
                _mboard.io.init_din_success = false;
            }else{
                // TURN_ON
                _mboard.io.init_din_success = true;
            }
            LAT_DIN_CS_B = LOW;
            LAT_DIN_RD_B = LOW;
        }else{
            LAT_DIN_ALE_A = LOW;
            LAT_DIN_CS_A = HIGH;
            LAT_DIN_RD_A = HIGH;
            WAIT_10NSEC(5000);
            int temp_di_check_1 = GPIO_DIN_INIT_CHIP_1();
            if(temp_di_check_1 != 0){
                // TURN_OFF
                _mboard.io.init_din_success = false;
            }else{
                // TURN_ON
                _mboard.io.init_din_success = true;
            }
            LAT_DIN_CS_A = LOW;
            LAT_DIN_RD_A = LOW;
        }        
    }else{
        din_chip_tiktok++;
//            if(gv.dinData.init_status || true)
//                GPIO_DI_TASK();
        
        if(_mboard.type == MCU_0){
            _mboard.io.din[8] = PORT_DIN_08;
            _mboard.io.din[9] = PORT_DIN_09;
            _mboard.io.din[10] = PORT_DIN_10;
            _mboard.io.din[11] = PORT_DIN_11;
            _mboard.io.din[12] = PORT_DIN_12;
            _mboard.io.din[13] = PORT_DIN_13;
            _mboard.io.din[14] = PORT_DIN_14;
            _mboard.io.din[15] = PORT_DIN_15;
        }else{
            _mboard.io.din[0] = PORT_DIN_00;
            _mboard.io.din[1] = PORT_DIN_01;
            _mboard.io.din[2] = PORT_DIN_02;
            _mboard.io.din[3] = PORT_DIN_03;
            _mboard.io.din[4] = PORT_DIN_04;
            _mboard.io.din[5] = PORT_DIN_05;
            _mboard.io.din[6] = PORT_DIN_06;
            _mboard.io.din[7] = PORT_DIN_07;
        }
    }
}

void DigitalOutputHandler()
{
    if(_mboard.type == MCU_0)
    {

        if(USE_COBOT_SSS == 1)
        {
            if(_mboard.io.dout_for_cobot_prs == 1)
            {
                SetDigitalOutput(cobot_sss_io_pin[1],1);
            }
            else
            {
                SetDigitalOutput(cobot_sss_io_pin[1],0);
            }
        }
        if(USE_COBOT_SS2 == 1)
        {
            if(_mboard.io.dout_for_cobot_ss2 == 1)
            {
                SetDigitalOutput(cobot_ss2_io_pin[1],0);
            }
            else
            {
                SetDigitalOutput(cobot_ss2_io_pin[1],1);
            }
        }

        LAT_DIGITAL_OUT_8 = _mboard.io.dout[8];
        LAT_DIGITAL_OUT_9 = _mboard.io.dout[9];
        LAT_DIGITAL_OUT_10 = _mboard.io.dout[10];
        LAT_DIGITAL_OUT_11 = _mboard.io.dout[11];
        LAT_DIGITAL_OUT_12 = _mboard.io.dout[12];
        LAT_DIGITAL_OUT_13 = _mboard.io.dout[13];
        LAT_DIGITAL_OUT_14 = _mboard.io.dout[14];
        LAT_DIGITAL_OUT_15 = _mboard.io.dout[15];
    }
    else
    {

        if(USE_COBOT_SSS == 1)
        {
            if(_mboard.io.dout_for_cobot_prs == 1)
            {
                SetDigitalOutput(cobot_sss_io_pin[0],1);
            }
            else
            {
                SetDigitalOutput(cobot_sss_io_pin[0],0);
            }
        }
        if(USE_COBOT_SS2 == 1)
        {
            if(_mboard.io.dout_for_cobot_ss2 == 1)
            {
                SetDigitalOutput(cobot_ss2_io_pin[0],0);
            }
            else
            {
                SetDigitalOutput(cobot_ss2_io_pin[0],1);
            }
        }

        LAT_DIGITAL_OUT_0 = _mboard.io.dout[0];
        LAT_DIGITAL_OUT_1 = _mboard.io.dout[1];
        LAT_DIGITAL_OUT_2 = _mboard.io.dout[2];
        LAT_DIGITAL_OUT_3 = _mboard.io.dout[3];
        LAT_DIGITAL_OUT_4 = _mboard.io.dout[4];
        LAT_DIGITAL_OUT_5 = _mboard.io.dout[5];
        LAT_DIGITAL_OUT_6 = _mboard.io.dout[6];
        LAT_DIGITAL_OUT_7 = _mboard.io.dout[7];
    }
    
}


void ClassBTest()
{
//    return;
    /**********************************************************************************/
    /*                                  CPU REGISTER TEST                             */                              
    /**********************************************************************************/
    if(CLASSB_CPURegistersTest() == 0){//CPU_REGISTER_TEST_PASS){
        // process test success
        testFlag.cpuRegister_TestResult = 1;
    }else
    {
        // process tests failure
        testFlag.cpuRegister_TestResult = 0;
    }
//    return;
    /**********************************************************************************/
    /*                                  PROGRAM COUNTER TEST                          */
    /*  This requires a special linker script (elf32pic32mx.ld) to be added           */
    /*   as part of the project. See the description in SSL_PcTest.h                  */
    /**********************************************************************************/
    if (CLASSB_CPUPCTest() == CLASSB_TEST_PASS)
    {
        // the PC register does not have stuck bits
        testFlag.programCounter_TestResult = 1;
    }
    else
    {
        testFlag.programCounter_TestResult = 0; 
    }
    
    /**********************************************************************************/
    /*                                  RAM TESTS                                     */                              
    /**********************************************************************************/
    // Variables used for RAM Tests
    extern int  _stack[];                   // the address of the stack, as placed by the linker
    extern int  _min_stack_size[];          // size of the stack, as defined in the project
    extern char _data_begin[];              // the address of the data segment, as placed by the linker

    int     *ramTestStartAddress;           // start address for the test 
    int     ramTestSize;                    // size of the tested area, bytes
    
    /*************************/
    /* Checker Board RAM test*/
    /*************************/
    // We'll test 1KB chunk at the middle of the RAM
    // Note that this test is not destructive
    // The size of the RAM area to test has to be multiple of 64.
    // It has to NOT overlap the stack space!

    int         ramTotSize;        // total RAM available, without stack
    char*       ramStartAddress;   // starting RAM address for the test
    char*       ramEndAddress;     // end address of RAM

    ramStartAddress= (char*)_data_begin;
    ramEndAddress= (char*)(_stack-(int)_min_stack_size/4);      // we leave out the stack space

    ramTotSize=ramEndAddress-ramStartAddress;

    // check if we have at least 1 KB available
    ramTestSize = (ramTotSize>0x400)?0x400:ramTotSize;
    // make sure is a multiple of 64
    ramTotSize&=0xffffffc0;

    // select 1 KB memory chunk in the middle of the RAM
    ramTestStartAddress =(int*)(ramStartAddress+(ramTotSize-ramTestSize)/2);

    // test it
    if (CLASSB_RAMCheckerBoardTest(ramTestStartAddress, ramTestSize) == CLASSB_TEST_PASS){ 
        // the test succeeded and we are confident that the RAM area can be used
        testFlag.checkerboardRam_TestResult = 1;
    }else{
        testFlag.checkerboardRam_TestResult = 0;
    }
    

    /****************************/
    /*    March B Ram Test      */
    /****************************/
    // Suppose we need to allocate and want to use a 1 KB chunk of memory
    // We'll test it using the Checker Board test before we use it
    // to make sure there is no problem with the chunk of RAM we selected.
    // Note that this test is destructive.
    // Note that the size of the RAM to test has to be multiple of 4.

    ramTestSize = 1024;
    ramTestStartAddress = (int *) malloc(ramTestSize);  // allocate RAM memory for usage

    if(ramTestStartAddress)
    { // allocation succeeded and we can perform the test
        if (CLASSB_RAMMarchBTest(ramTestStartAddress, ramTestSize ) == CLASSB_TEST_PASS){
            // the test succeeded and we can go ahead and use the allocated memory
            testFlag.marchBRam_TestResult = 1;
        }else{
            testFlag.marchBRam_TestResult = 0;
        }
        
        free(ramTestStartAddress);  // we're done with this memory block
                                    // return it to the heap
    }
    
    
    /****************************/
    /* MarchC RAM and Stack Test*/
    /****************************/
    // We allocate and want to use a 2 KB chunk of memory
    // We want to make sure that both the allocated RAM and
    // the stack space are ok.
    // We'll test it using the March C and Stack tests before we use it
    // Note that the size of the RAM to test has to be multiple of 4.
    // Also, the size of the tested RAM area has to be greater than the
    // size of the tested stack area. 
    // This test is destructive for the RAM area but preserves the Stack area.

    ramTestSize = 2048;
    ramTestStartAddress = (int *) malloc(ramTestSize);

    if(ramTestStartAddress)
    {   // allocation succeeded and we can perform the test
        // test 1024 bytes of Stack
        // we use the address of the stack, as placed by the linker

        if (CLASSB_RAMMarchCStackTest(ramTestStartAddress, ramTestSize) == CLASSB_TEST_PASS){
            // if the test succeeded we can go ahead and use the allocated memory
            // we're confident that both RAM and Stack area are ok!       
            testFlag.marchCRamStack_TestResult = 1;
        }else{
            testFlag.marchCRamStack_TestResult = 0;
        }

        free(ramTestStartAddress);  // we're done with this memory block
                                    // return it to the heap
    }

    
    /**********************************************************************************/
    /*                                  FLASH CRC TEST                                */                              
    /**********************************************************************************/
    // This function can be called at startup to generate the Reference checksum.
    // The same function can be called periodically and the generated checksum can be 
    // compared with the reference checksum.
    // If both are the same the "flash_TestResult" status bit can be set. 

    unsigned int flashCrcRef, flashCrc; // reference and current CRC values
    unsigned int crcSeed=0xffff;        // initial CRC register value
                                        // this is the recommended CRC seed
                                        // for checking properly long 0 streams.
    extern const unsigned int FLASH_CRC_REF;
    
    // calculate the CRC16 of the whole program flash (K0)      
    char* flashStartAddress = (char*)0x9d000000;       // fixed start K0 address on PIC32MX devices
    char* flashEndAddress =  flashStartAddress+0x1FFFFF-1;  // size of the flash on this device
                                                            // the BMX register stores the Flash size for this part

    // first we calculate the reference Flash CRC value
    flashCrcRef = CLASSB_CRCFlashTest( flashStartAddress, flashEndAddress, CRC_16_GEN_POLY, crcSeed);

    // at some time later we calculate again the CRC of the Flash 
    flashCrc = CLASSB_CRCFlashTest( flashStartAddress, flashEndAddress, CRC_16_GEN_POLY, crcSeed);

    // make sure that the periodic check is equal to the reference one
    if ( flashCrc == flashCrcRef){
        testFlag.flash_TestResult=1;
        // we are confident that the data programmed in Flash
        // has not been altered in any way 
    }else{ 
        testFlag.flash_TestResult=0;
    }
    
    /**********************************************************************************/
    /*        CLOCK  TEST WITH SECONDARY OSCILLATOR AS REFERENCE CLOCK                */
    /*      This test requires that a standard 32.768 KHz crystal is connected        */
    /*                      at the SOSC input.                                        */
    /**********************************************************************************/
    
    asm volatile("di");                 // Disable all interrupt
    INTCONbits.MVEC = 1;             // Multi vector on
    TRISCbits.TRISC13 = 1;
    T7CKRbits.T7CKR = 0b0111;
    
    // we'll count for 1 second
    // check the system clock to be within +/- 0.1%
    if(CLASSB_ClockTest(SYSFREQ, 32768, 100, 10) == CLASSB_TEST_PASS){
        // the CPU clock is within the required limits
        testFlag.clock_TestResult=1;
    }else{ 
        testFlag.clock_TestResult=0;
    }

}

void RESET()
{
//    return;
    //To do disenable pin
    asm volatile("di");
    
    void (*fptr)(void);
    fptr = (void (*)(void))APPLICATION_START_VA;
    fptr();
}

void SetDigitalOutput(unsigned char pin, unsigned char value) 
{
    if(pin < 16)
    {
        _mboard.io.dout[pin] = value;
    }
}
/*******************************************************************************
 End of File
*/

