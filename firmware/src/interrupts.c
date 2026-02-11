#include "system_general_configuration.h"

typedef enum
{
    STATE_IDLE = 0,
    STATE_5V_ON,
    STATE_CHARGER_ON,
    STATE_CHARGING,
    STATE_CHARGER_OFF,
    STATE_FAIL,
    STATE_EMO
}STATE_ENUM;

int STATE = STATE_IDLE;

/* ===== [TEST CODE START] EMO→FET 1회 실행 테스트 ===== */
static unsigned char test_emo_prev  = 0;
static unsigned char test_fet_run   = 0;  // 0=대기, 1=실행중, 2=완료
static unsigned char test_fet_state = 0;  // 0=PRE_ON, 1=MAIN_ON, 2=PRE_OFF, 3=DONE
static unsigned int  test_fet_cnt   = 0;
/* ===== [TEST CODE END] ===== */

/*******************************************************************************
 * Timer 2 Interrupt
 ******************************************************************************/
/* MISRA C-2012 Rule 2.1 deviation: This function is an interrupt service routine and is called by hardware. */
void __ISR(_TIMER_2_VECTOR, ipl5AUTO) Handler_TMR_2(void)
{ //100HZ
    static unsigned int tmr2_cnt = 0;
    tmr2_cnt++;
    

    // if(tmr2_cnt%10 == 0)
    // {
    //     // LATS_LED_1 ^= 1;
    //     LATS_LED_2 ^= 1;
    // }
    // if(_mboard.safety_result.safety_state_emo_pressed == 1)
    // {
    //     LATS_LED_1 = 0;
    // }
    // else
    // {
    //     LATS_LED_1 = 1;
    // }
    

    if(_mboard.safety_result.safety_state_emo_pressed == 1)
    {
        /* ===== [TEST CODE START] EMO rising edge → FET 1회 트리거 ===== */
        if(test_emo_prev == 0)
        {
            test_fet_run   = 1;
            test_fet_state = 0;
            test_fet_cnt   = 0;
        }
        /* ===== [TEST CODE END] ===== */
    }
    else
    {
        /* ===== [TEST CODE START] EMO falling edge → FET OFF ===== */
        if(test_emo_prev == 1)
        {
            Task_Control_Pre_FET_Off();
            Task_Control_Main_FET_Off();
            test_fet_run   = 0;
            test_fet_state = 0;
            test_fet_cnt   = 0;
        }
        /* ===== [TEST CODE END] ===== */
    }
    
    /* ===== [TEST CODE START] prev 갱신 ===== */
    test_emo_prev = _mboard.safety_result.safety_state_emo_pressed;
    /* ===== [TEST CODE END] ===== */

    /* ===== [TEST CODE START] FET 시퀀스 1회 실행 ===== */
    if(test_fet_run == 1)
    {
        /* FAULT 감지 시 즉시 FET OFF + LED 둘 다 OFF */
        /* MCU_0: FAULT_A, MCU_1: FAULT_B */
        if((_mboard.type == MCU_0 && PORT_MOTOR_FET_FAULT_A == 0) ||
           (_mboard.type == MCU_1 && PORT_MOTOR_FET_FAULT_B == 0))
        {
            LATS_LED_1 = 1; LATS_LED_2 = 1;
        }
        else
        {
            switch(test_fet_state)
            {
                case 0: // PRE_ON — LED: 둘 다 OFF (0번)
                    LATS_LED_1 = 1; LATS_LED_2 = 1;
                    Task_Control_Pre_FET_On();
                    test_fet_cnt++;
                    if(test_fet_cnt >= 50) { test_fet_cnt = 0; test_fet_state = 1; }  // 500ms (TMR=300ms 대기)
                    break;
                case 1: // MAIN_ON — LED: LED1만 ON (1번)
                    LATS_LED_1 = 0; LATS_LED_2 = 1;
                    Task_Control_Main_FET_On();
                    test_fet_cnt++;
                    if(test_fet_cnt >= 10) { test_fet_cnt = 0; test_fet_state = 2; }  // 100ms
                    break;
                case 2: // PRE_OFF — LED: LED2만 ON (2번)
                    LATS_LED_1 = 1; LATS_LED_2 = 0;
                    Task_Control_Pre_FET_Off();
                    test_fet_cnt++;
                    if(test_fet_cnt >= 10) { test_fet_cnt = 0; test_fet_state = 3; }  // 100ms
                    break;
                case 3: // DONE — LED: 둘 다 ON (3번)
                    LATS_LED_1 = 0; LATS_LED_2 = 0;
                    Task_Control_Main_FET_On();
                    Task_Control_Pre_FET_Off();
                    test_fet_run = 2;
                    break;
            }
        }
    }
    /* ===== [TEST CODE END] ===== */

    Task_ADC_Measure();
    Task_Lidar_Handler();

    Task_SF_Total();

    Task_Power_Handler();
    Task_IO_Handler();
    
    CommDataHandler();
    DebugDataHandler();
    
    // Clear the timer2 interrupt flag -----------------------------------------
    IFS0bits.T2IF=0;
}

/*******************************************************************************
 * CAN RX Interrupt
 ******************************************************************************/
void __ISR(_CAN1_VECTOR, ipl4AUTO) Handler_CAN_1(void)
{
    static uint8_t      data[8];
    static uint32_t     id;
    static uint8_t      dlc;
        
    while(CAN_READ_1(&id, data, &dlc))
    {
        CAN_PARSER_1(id, data, dlc, 1);        
    }
    
    // Clear the CAN 1 interrupt flag
    IFS4bits.CAN1IF = 0;
}

void __ISR(_CAN2_VECTOR, ipl5AUTO) Handler_CAN_2(void){
    static uint8_t      data[8];
    static uint32_t     id;
    static uint8_t      dlc;
    
    while(CAN_READ_2(&id, data, &dlc))
    {
        CAN_PARSER_2(id, data, dlc, 2);
    }
    
    // Clear the CAN 2 interrupt flag
    IFS4bits.CAN2IF = 0;
}

/*******************************************************************************
 * Spi 4 Slave RX Interrupt
 ******************************************************************************/
void __ISR(_SPI4_RX_VECTOR, ipl1AUTO) Handler_SPI_4_RX(void)
{
    // Receive friend status data and reply my status data
    static unsigned int a = 0;
    
    unsigned int send_status = _mboard.status_now.raw;
    
    unsigned int rcv_status = SPI4BUF;
//    SPI4BUF = 0xABCDABCD;
    SPI4BUF = send_status;

    
    _fboard.status_old.raw = _fboard.status_now.raw;
    _fboard.status_now.raw = rcv_status;


    if(_mboard.status_now.raw == _fboard.status_now.raw)
    {
        ;
    }
    else if(_mboard.status_now.raw == _fboard.status_old.raw)
    {
        ;
    }
    else if(_mboard.status_old.raw == _fboard.status_now.raw)
    {
        ;
    }
    else
    {
        a++;
    }
    _mboard.status_old.raw = _mboard.status_now.raw;
    
    unsigned char temp2[4];
    temp2[0]= rcv_status & 0xFF;
    temp2[1] = (rcv_status >>8 ) & 0xFF;
    temp2[2] = (rcv_status >>16 ) & 0xFF;
    temp2[3] = (rcv_status >>24 ) & 0xFF;
    
//    if(_mboard.type == MCU_0)
//    {
//        CAN_WRITE_2(0x203, 4, temp2);
//    }
//    else
//    {
//        CAN_WRITE_2(0x202, 4, temp2);
//    }
    
    // Clear the SPI 4 interrupt flag
    IFS5bits.SPI4RXIF = 0;
}


/*******************************************************************************
 * Watchdog
 ******************************************************************************/
void __ISR(_TIMER_3_VECTOR, ipl1AUTO) Handler_WatchDog(void){
    
    // interrupt flag -----------------------------------------
    IFS0bits.T3IF=0;
}



/*******************************************************************************
 * OSSD
 ******************************************************************************/
void __ISR(_CHANGE_NOTICE_C_VECTOR, IPL6AUTO) CNC_Handler(void)
{
    if(_mboard.type == MCU_0)
    {
        if(PORTCbits.RC14 == 0)
        {
            // OSSD Front A
            _mboard.sensor.ossd_front_triggered = 1;
            _mboard.sensor.ossd_front_counter = 0;
        }
    }
    
    IFS3bits.CNCIF = 0;
}


void __ISR(_CHANGE_NOTICE_D_VECTOR, IPL6AUTO) CND_Handler(void)
{
    if(_mboard.type == MCU_1)
    {
        if(PORTDbits.RD5 == 0)
        {
            // OSSD Front B
            _mboard.sensor.ossd_front_triggered = 1;
            _mboard.sensor.ossd_front_counter = 0;
        }
    }
    
    IFS3bits.CNDIF = 0;
}

void __ISR(_CHANGE_NOTICE_F_VECTOR, IPL6AUTO) CNF_Handler(void)
{
    if(_mboard.type == MCU_0)
    {
        if(PORTFbits.RF0 == 0)
        {
            // OSSD Rear A
            _mboard.sensor.ossd_rear_triggered = 1;
            _mboard.sensor.ossd_rear_counter = 0;
        }
    }
    else
    {
        if(PORTFbits.RF1 == 0)
        {
            // OSSD Rear B
            _mboard.sensor.ossd_rear_triggered = 1;
            _mboard.sensor.ossd_rear_counter = 0;
        }
    }
    IFS3bits.CNFIF = 0;
}
