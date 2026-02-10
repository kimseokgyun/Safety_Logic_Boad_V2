#include "system_general_configuration.h"
#include <string.h>
#include "param_define.h"

#define EMO_ENSURE_CNT          2
#define BUMPER_ENSURE_CNT       2
#define INTERLOCK_ENSURE_CNT    5

static unsigned char GetState_EMO();

static float dt_ = 0.01;
unsigned int mcu0_ossd_sig_front, mcu0_ossd_sig_rear;
unsigned int mcu1_ossd_sig_front, mcu1_ossd_sig_rear;

unsigned int POWER_STATE = POWER_STATE_OFF;
unsigned int LIFT_POWER_STATE = POWER_STATE_OFF;

unsigned int op_stop_trig_delay = 0;
unsigned int obstacle_detect_mode = 1;
unsigned char BUMPER_TRIGGER =0;

unsigned int obs_detect_delay_time = 150; //ms

void Task_ADC_Measure(void)
{
    if(_mboard.type == MCU_0)
    {
        
//        while (ADCDSTAT1bits.ARDY0 == 0);
//        while (ADCDSTAT1bits.ARDY1 == 0);
//        while (ADCDSTAT1bits.ARDY2 == 0);
    
        unsigned int adc0 = ADCDATA0;
        unsigned int adc1 = ADCDATA1;
        unsigned int adc2 = ADCDATA2;

        // i = x(digit)*3.3(v)/4096(digit)/20(gain)/0.003(ohm) = 0.0134 * x
        // i = x(digit)*3.3(v)/4096(digit)/20(gain)/0.0025(ohm) = 0.01611 * x
        float current_amr = adc0 * 0.0134; // (A unit)

        // v = x(digit)*3.3(v)/4096(digit)*49.7k(ohm)/2.7k(ohm) = 0.0148 * x
        float voltage_in = adc1 * 0.0148; // (V unit)
        float voltage_out = adc2 * 0.0148;
        
        _mboard.sensor.adc_inlet_voltage = voltage_in;
        _mboard.sensor.adc_outlet_voltage = voltage_out;
        _mboard.sensor.adc_current_line = current_amr;
        
        ADCCON3bits.GSWTRG = 1;             // adc trigger
    }
    else
    {
        unsigned int adc0 = ADCDATA0;
        unsigned int adc1 = ADCDATA1;
        unsigned int adc2 = ADCDATA2;

        // i = x(digit)*3.3(v)/4096(digit)/20(gain)/0.003(ohm) = 0.0134 * x
        // i = x(digit)*3.3(v)/4096(digit)/20(gain)/0.0025(ohm) = 0.01611 * x
        float current_amr = adc0 * 0.0134; // (A unit)

        // v = x(digit)*3.3(v)/4096(digit)*49.7k(ohm)/2.7k(ohm) = 0.0148 * x
        float voltage_in = adc1 * 0.0148; // (V unit)
        float voltage_out = adc2 * 0.0148;
        
        _mboard.sensor.adc_inlet_voltage_lift = voltage_in;
        _mboard.sensor.adc_outlet_voltage_lift = voltage_out;
        _mboard.sensor.adc_current_line_lift = current_amr;
        
        ADCCON3bits.GSWTRG = 1;             // adc trigger
    }
}

void Task_Lidar_Handler(void)
{
    uint8_t data[1] = {0,};
    
    if(_mboard.type == MCU_0)
    {
        _mboard.sensor.field_selection[0] = PORTAbits.RA3;
        _mboard.sensor.field_selection[1] = PORTAbits.RA2;
        _mboard.sensor.field_selection[2] = PORTFbits.RF8;
        _mboard.sensor.field_selection[3] = PORTFbits.RF2;
        _mboard.sensor.field_selection[4] = PORTCbits.RC15;
        _mboard.sensor.field_selection[5] = PORTDbits.RD15;
       
        unsigned int field_bits = 0;
        
        field_bits = _mboard.sensor.field_selection[0] & 0x01 |
                    (_mboard.sensor.field_selection[1] & 0x01)<<1 |
                    (_mboard.sensor.field_selection[2] & 0x01)<<2 |
                    (_mboard.sensor.field_selection[3] & 0x01)<<3 |
                    (_mboard.sensor.field_selection[4] & 0x01)<<4 |
                    (_mboard.sensor.field_selection[5] & 0x01)<<5;
        
        _mboard.sensor.field_num = field_bits;
        
        data[0] = (unsigned char)_mboard.sensor.field_num;
        
        CAN_WRITE_2(0x321, 1, data);
    }

    else
    {
        _mboard.sensor.field_selection[0] = !(PORTFbits.RF8);
        _mboard.sensor.field_selection[1] = !(PORTFbits.RF2);
        _mboard.sensor.field_selection[2] = !(PORTAbits.RA3);
        _mboard.sensor.field_selection[3] = !(PORTAbits.RA2);
        _mboard.sensor.field_selection[4] = !(PORTCbits.RC14);
        _mboard.sensor.field_selection[5] = !(PORTAbits.RA4);
        
        unsigned int field_bits = 0;
        
        field_bits = _mboard.sensor.field_selection[0] & 0x01 |
                    (_mboard.sensor.field_selection[1] & 0x01)<<1 |
                    (_mboard.sensor.field_selection[2] & 0x01)<<2 |
                    (_mboard.sensor.field_selection[3] & 0x01)<<3 |
                    (_mboard.sensor.field_selection[4] & 0x01)<<4 |
                    (_mboard.sensor.field_selection[5] & 0x01)<<5;
        
        _mboard.sensor.field_num = field_bits;
        
        data[0] = (unsigned char)_mboard.sensor.field_num;
        
        CAN_WRITE_2(0x320, 1, data);
    }
}

// 100Hz handler
void Task_Power_Handler(void)
{
    static unsigned int power_motor_cnt = 0;
    static unsigned int power_lift_cnt = 0;
    unsigned int try_power_on = 0;
    unsigned int try_power_off = 0;
    unsigned int try_lift_power_on = 0;
    unsigned int try_lift_power_off = 0;
    
    // check power on off command
    if(_mboard.comm_info.cmd_power_on == 1)
    {
        _mboard.comm_info.cmd_power_on = 0;     // make one shot working
        try_power_on = 1;
    }

    if(_mboard.comm_info.cmd_power_off == 1)
    {
        _mboard.comm_info.cmd_power_off = 0;    // make one shot working
        try_power_off = 1;
    }
    
    // check lift power on off command
    if(_mboard.comm_info.cmd_lift_power_on == 1)
    {
        _mboard.comm_info.cmd_lift_power_on = 0;     // make one shot working
        
        try_lift_power_on = 1;
    }
    
    if(_mboard.comm_info.cmd_lift_power_off == 1)
    {
        _mboard.comm_info.cmd_lift_power_off = 0;    // make one shot working
        
        try_lift_power_off = 1;
    }

    
    if(_mboard.safety_result.cmd_power_off == 1)
    {
        _mboard.safety_result.cmd_power_off = 0;
        
        try_power_off = 1;
        #ifdef SEM
//        try_lift_power_off = 1;
        #endif
    }
    
    // check SF state    
    if(_mboard.sensor.emo_pressed == 1)
    {
        try_power_on = 0;
        if(_mboard.sensor.adc_outlet_voltage > 40.0)
        {
            try_power_off = 1;
        }
    }
    
    // do power action
    if(try_power_on !=0U)
    {
        POWER_STATE = POWER_STATE_ON;
    }
    if(try_power_off !=0U)
    {
        POWER_STATE = POWER_STATE_OFF;
    }
    
    
    // MOTOR FET CONTROL 
    switch(POWER_STATE)
    {
        case POWER_STATE_OFF:
            Task_Control_Pre_FET_Off();
            Task_Control_Main_FET_Off();
            power_motor_cnt = 0;
            break;
            
        case POWER_STATE_PRE_WAIT:
            if(_mboard.type == MCU_0)
            {
                // bypass
                power_motor_cnt = 0;
                POWER_STATE = POWER_STATE_PRE_ON;
            }
            else
            {
                // wait until MCU 0 turn on the FET first (30cnt = 300ms)
                power_motor_cnt++;
                if(power_motor_cnt >= 30)
                {
                    power_motor_cnt = 0;
                    POWER_STATE = POWER_STATE_PRE_ON;
                }
            }
            break;
            
        case POWER_STATE_PRE_ON:
            Task_Control_Pre_FET_On();
            power_motor_cnt++;
            if(_mboard.type == MCU_0)
            {
                if(power_motor_cnt >= 2)
                {
                    power_motor_cnt = 0;
                    POWER_STATE = POWER_STATE_MAIN_ON;
                }                
            }
            else
            {
                if(power_motor_cnt >= 6)  // 6cnt = 60ms
                {
                    power_motor_cnt = 0;
                    POWER_STATE = POWER_STATE_MAIN_ON;
                }                
            }
            break;
            
        case POWER_STATE_MAIN_ON:
            Task_Control_Main_FET_On();
            power_motor_cnt++;
            if(power_motor_cnt >= 5)  // 5cnt = 50ms
            {
                power_motor_cnt = 0;
                POWER_STATE = POWER_STATE_PRE_OFF;
            }
            break;
            
        case POWER_STATE_PRE_OFF:
            Task_Control_Pre_FET_Off();
            power_motor_cnt++;
            if(power_motor_cnt >= 5)  // 5cnt = 50ms
            {
                power_motor_cnt = 0;
                POWER_STATE = POWER_STATE_ON;
            }
            break;
            
        case POWER_STATE_ON:
            Task_Control_Main_FET_On();
            Task_Control_Pre_FET_Off();
            break;
            
        default:
            break;
    }
    
    
    // do lift power action
    if(try_lift_power_on)
    {
        LIFT_POWER_STATE = POWER_STATE_ON;
    }
    if(try_lift_power_off)
    {
        LIFT_POWER_STATE = POWER_STATE_OFF;
    }
    
    
    // LIFT POWWER CONTORL
    if(_mboard.type == MCU_1)
    {
        switch(LIFT_POWER_STATE)
        {
            case POWER_STATE_OFF:
                Task_Control_Lift_Pre_FET_Off();
                Task_Control_Lift_Main_FET_Off();
                power_lift_cnt = 0;
                break;

            case POWER_STATE_PRE_WAIT:
                // bypass
                power_lift_cnt = 0;
                LIFT_POWER_STATE = POWER_STATE_PRE_ON;
                break;

            case POWER_STATE_PRE_ON:
                Task_Control_Lift_Pre_FET_On();
                power_lift_cnt++;
                if(power_lift_cnt >= 6)  // 6cnt = 60ms
                {
                    power_lift_cnt = 0;
                    LIFT_POWER_STATE = POWER_STATE_MAIN_ON;
                }
                break;

            case POWER_STATE_MAIN_ON:
                Task_Control_Lift_Main_FET_On();
                power_lift_cnt++;
                if(power_lift_cnt >= 5)  // 5cnt = 50ms
                {
                    power_lift_cnt = 0;
                    LIFT_POWER_STATE = POWER_STATE_PRE_OFF;
                }
                break;

            case POWER_STATE_PRE_OFF:
                Task_Control_Lift_Pre_FET_Off();
                power_lift_cnt++;
                if(power_lift_cnt >= 5)  // 5cnt = 50ms
                {
                    power_lift_cnt = 0;
                    LIFT_POWER_STATE = POWER_STATE_ON;
                }
                break;

            case POWER_STATE_ON:
                Task_Control_Lift_Main_FET_On();
                Task_Control_Lift_Pre_FET_Off();
                break;

            default:
                break;
        }
    }
}


void Task_IO_Handler()
{
    // reset stop start
    if(_mboard.type == MCU_0)
    {
        _mboard.io.sw_reset = PORT_SW_RESET;
        _mboard.io.sw_stop = PORT_SW_STOP;
        _mboard.io.sw_start = PORT_SW_START;
    }
}

void Task_SF_INTERLOCK_Detection()
{
    static unsigned char prev_interlock = 0;
    static unsigned int interlock_cnt = 0;


    if(USE_SAFETY_INTERLOCK == 0)
    {
        return;
    }

    unsigned char interlock = 0;
    // get interlock state
    if(_mboard.type == MCU_0)
    {
        if(_mboard.io.din[cobot_interlock_io_pin[1]] == 1 )
        {
            if(_mboard.speed_info.safety_speed.meas_speed_in_dps_output[0] >= 100  ||
                    _mboard.speed_info.safety_speed.meas_speed_in_dps_output[1] >= 100 )
            {
                interlock = 1;
            }
            else
            {
                interlock = 0;
            }
        }
    }
    else 
    {
        if(_mboard.io.din[cobot_interlock_io_pin[0]] == 1 )
        {
            if(_mboard.speed_info.safety_speed.meas_speed_in_dps_output[0] >= 100 ||
                    _mboard.speed_info.safety_speed.meas_speed_in_dps_output[1] >= 100)
            {
                interlock = 1;
            }
        }

        else
        {
            interlock = 0;
        }

    } 
    
    
    // check interlock state with jitter 
    if(interlock == 1)
    {
        if(prev_interlock == 1)
        {
            interlock_cnt++;
            if(interlock_cnt > INTERLOCK_ENSURE_CNT)
            {
                _mboard.safety_result.safety_state_interlock_stop_detected = 1;
            }
        }
        else
        {
            interlock_cnt = 0;
        }
    }

    prev_interlock = interlock;
}

void Task_SF_Total()
{
    
    if(USE_COBOT_SSS == 1)
    {
        Task_SF_RESET_IO_Detection();
    }

    // safety detection
    Task_SF_EMO_Detection();
    Task_SF_Cross_Monitoring_Detection();
    Task_SF_Obstacle_Detection();
    Task_SF_SpeedControl_Detection();
    Task_SF_BUMPER_Detection();
    Task_SF_INTERLOCK_Detection();
    

    // stop category
    Stop_Signal_Generation();
    

    // safety stop -- one shot trigger
    Task_SF_STO();
    Task_SF_SS1();
    Task_SF_SS2();


    if(USE_COBOT_SSS == 1)
    {
        Task_SF_COBOT_PRS();
    }
    if(USE_COBOT_SS2 == 1)
    {
        Task_SF_COBOT_SS2();

        // to do change reset logic
        // Task_SF_COBOT_SS2_RECOVERY();
    }


#ifdef SEM
    Task_SF_COBOT_SS2();
    Task_SF_EWELLIX_STO();
#endif
    

    // only sem emo user info logic
    if((_mboard.safety_result.safety_state_emo_pressed) && !(_mboard.safety_result.prev_safety_state_emo_pressed))
    {
        SafetyStopInfoMessage(AMR_STO_MESSAGE_NUM);
    }
    
    // recover from ss2 state (operational stop state)
    if(_mboard.comm_info.cmd_recover_op_stop_state == 1)
    {
        _mboard.comm_info.cmd_recover_op_stop_state = 0;        
        _mboard.safety_result.operational_stop_state_flag = 0;
        SafetyStop(SAFETY_MODE_NORMAL, 0);
    }
    
    // status_now variable update 
    _mboard.status_now.is_emo_press_detected = _mboard.safety_result.safety_state_emo_pressed;
    _mboard.status_now.is_ref_spd_mismatch_detected = _mboard.safety_result.safety_state_ref_speed_mismatch_detected;
    _mboard.status_now.is_ovr_spd_detected = _mboard.safety_result.safety_state_over_speed_detected;
    _mboard.status_now.is_obs_detected = _mboard.safety_result.safety_state_obstacle_detected;
    _mboard.status_now.is_spd_field_mismatch_detected = _mboard.safety_result.safety_state_speed_field_mismatch_detected;
    _mboard.status_now.is_in_op_stop_state = _mboard.safety_result.operational_stop_state_flag;
    _mboard.status_now.is_bumper_press_detected = _mboard.safety_result.safety_state_bumper_stop_detected;
    
    // safety_result prev variable update
    _mboard.safety_result.prev_safety_state_emo_pressed = _mboard.safety_result.safety_state_emo_pressed;
    _mboard.safety_result.prev_safety_state_ref_speed_mismatch_detected = _mboard.safety_result.safety_state_ref_speed_mismatch_detected;
    _mboard.safety_result.prev_safety_state_over_speed_detected = _mboard.safety_result.safety_state_over_speed_detected;
    _mboard.safety_result.prev_safety_state_obstacle_detected = _mboard.safety_result.safety_state_obstacle_detected;
    _mboard.safety_result.prev_safety_state_speed_field_mismatch_detected = _mboard.safety_result.safety_state_speed_field_mismatch_detected;
    _mboard.safety_result.prev_safety_state_interlock_stop_detected = _mboard.safety_result.safety_state_interlock_stop_detected;
    _mboard.safety_result.prev_safety_state_bumper_stop_detected = _mboard.safety_result.safety_state_bumper_stop_detected;
}

void Task_SF_Cross_Monitoring_Detection()
{
    static unsigned int a = 0;


    if(USE_SAFETY_CROSS_MONITORING == 0)
    {
        return;
    }

    if(_mboard.type == MCU_0)
    {
        unsigned int send_status = _mboard.status_now.raw;
        unsigned int rcv_status = Write_SpiMaster(send_status);
        
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
    }
}

void Stop_Signal_Generation(void)
{
    // stop signal generation

    // interlock stop signal generation
    if(_mboard.safety_result.safety_state_interlock_stop_detected == 1 )
    {
        if(_mboard.safety_result.prev_safety_state_interlock_stop_detected == 0)
        {
            _mboard.safety_result.cmd_ss1 =1;
        }
    }
    
    // bumper stop signal generation
    if(_mboard.safety_result.safety_state_bumper_stop_detected == 1)
    {
        if(_mboard.safety_result.prev_safety_state_bumper_stop_detected == 0)
        {
            _mboard.safety_result.cmd_ss1 = 1;

            //cobot signal
            if(USE_COBOT_SSS == 1)
            {
                _mboard.safety_result.prs_state = 0;
            }
        }
    }

    // emo stop signal generation
    if(_mboard.safety_result.safety_state_emo_pressed == 1)
    {
        _mboard.safety_result.cmd_sto = 1;

        //cobot signal
        if(USE_COBOT_SSS == 1)
        {
            _mboard.safety_result.prs_state = 0;
        }
    }
    
    // speed mismatch stop signal generation
    if(_mboard.safety_result.safety_state_ref_speed_mismatch_detected == 1)
    {
        if(_mboard.safety_result.prev_safety_state_ref_speed_mismatch_detected == 0)
        {
            _mboard.safety_result.cmd_ss2 = 1;
        }

    }
    
    // over speed stop signal generation
    if(_mboard.safety_result.safety_state_over_speed_detected == 1)
    {
        if(_mboard.safety_result.prev_safety_state_over_speed_detected == 0)
        {
            _mboard.safety_result.cmd_ss1 = 1;
        }
    }
    
    // obstacle stop signal generation
    if(_mboard.safety_result.safety_state_obstacle_detected == 1)
    {
        if(_mboard.safety_result.prev_safety_state_obstacle_detected == 0)
        {
            _mboard.safety_result.cmd_ss2 = 1;
            
            if(USE_COBOT_SS2 == 1 && 
                _mboard.sensor.field_num >= cobot_ss2_field_num[0] && 
                _mboard.sensor.field_num <= cobot_ss2_field_num[1])
            {
                _mboard.safety_result.cmd_cobot_ss2 = 1;
            }
        }
    }
    
    // speed field mismatch stop signal generation
    if(_mboard.safety_result.safety_state_speed_field_mismatch_detected == 1)
    {
        if(_mboard.safety_result.prev_safety_state_speed_field_mismatch_detected == 0)
        {
            _mboard.safety_result.cmd_ss2 = 1;
        }
    }



}

void Task_SF_STO(void)
{
    if(_mboard.safety_result.cmd_sto == 1)
    {   
        _mboard.safety_result.cmd_sto = 0;
        _mboard.safety_result.cmd_power_off = 1;
        
        //add -08-22
        //reason: SEM know recovery signal -- but to be checked 
        // _mboard.safety_result.operational_stop_state_flag = 1;
    
    }
}

void Task_SF_SS1(void)
{
    if(_mboard.safety_result.cmd_ss1 == 1)
    {
        _mboard.safety_result.cmd_ss1 = 0; 
        _mboard.safety_result.stop_count_ss1 = (unsigned int)(SS1_STOP_TIME / TIME_CONSTANT_10MS ); // 10ms
        SafetyStop(SAFETY_MODE_SS1, 10); // 10ms
        SafetyStopInfoMessage(SAFETY_MODE_SS1);
    }
        
    if(_mboard.safety_result.stop_count_ss1 != 0)
    {
        _mboard.safety_result.stop_count_ss1--;
        
        if(_mboard.safety_result.stop_count_ss1 == 0)
        {
            _mboard.safety_result.cmd_power_off = 1;
        }
    }
}

void Task_SF_SS2(void)
{
    if(_mboard.safety_result.cmd_ss2 == 1)
    {
        _mboard.safety_result.cmd_ss2 = 0;
        
        _mboard.safety_result.stop_count_ss2 = (unsigned int)(SS2_STOP_TIME / TIME_CONSTANT_10MS );
        SafetyStop(SAFETY_MODE_SS2, 10);  //10ms
        SafetyStopInfoMessage(SAFETY_MODE_SS2);
        
    }
    
    if(_mboard.safety_result.stop_count_ss2 != 0)
    {
        _mboard.safety_result.stop_count_ss2--;            
        
        if(_mboard.safety_result.stop_count_ss2 == 0)
        {
            // check safety
            _mboard.safety_result.operational_stop_state_flag = 1;
        }
    }
}

void Task_SF_BUMPER_Detection(void)
{
    static unsigned char prev_bumper = 0;
    static unsigned int bumper_cnt = 0;


    if(USE_SAFETY_BUMPER == 0)
    {
        return;
    }

    BUMPER_TRIGGER = getBumperSwitch();

    if(BUMPER_TRIGGER == 1)
    {
        if(prev_bumper == 1)
        {
            bumper_cnt++;
            if(bumper_cnt > BUMPER_ENSURE_CNT)
            {
                _mboard.safety_result.safety_state_bumper_stop_detected = 1;
            }
        }
        else
        {
            bumper_cnt = 0;
        }
    }
    // else
    // {
    //     bumper_cnt = 0;
    // }
    else
    {
        if(prev_bumper == 0)
        {
            bumper_cnt++;
            if(bumper_cnt > BUMPER_ENSURE_CNT)
            {
                _mboard.safety_result.safety_state_bumper_stop_detected = 0; 
            }
        }
        else
        {
            bumper_cnt = 0;
        }
    }



    prev_bumper = BUMPER_TRIGGER;
}

void Task_SF_RESET_IO_Detection(void)
{
    static unsigned char now_reset = 0;
    static unsigned char prev_reset = 0;

    now_reset = _mboard.io.sw_reset;

    // reset signal detected
    if(now_reset == 1)
    {
        if(prev_reset == 0)
        {
            _mboard.safety_result.prs_state = 1; // reset button pressed
        }
    }

    prev_reset = now_reset;
}

void Task_SF_EMO_Detection(void)
{
    static unsigned char prev_EMO = 0;
    static unsigned int emo_cnt = 0;
    unsigned char EMO = GetState_EMO();
    
    if(EMO == 1)
    {
        if(prev_EMO == 1)
        {
            emo_cnt++;
            if(emo_cnt > EMO_ENSURE_CNT)
            {
                _mboard.sensor.emo_pressed = 1;
                _mboard.safety_result.safety_state_emo_pressed = 1;
            }
        }
        else
        {
            emo_cnt = 0;
        }
    }

    else
    {
        if(prev_EMO == 0)
        {
            emo_cnt++;
            if(emo_cnt > EMO_ENSURE_CNT)
            {
                _mboard.sensor.emo_pressed = 0;
                _mboard.safety_result.safety_state_emo_pressed = 0;
            }
        }
        else
        {
            emo_cnt = 0;
        }
    }
    prev_EMO = EMO;
}

//    unsigned char   safety_state_speed_field_mismatch_detected; // CAT 2 (SS2)
#define REF_MEAS_SPEED_MISMATCH_THRESHOLD   50.0  //20.0
#define SF_SPD_MISMATCH_CHECK_NUM           500 //50
#define SF_OVR_SPD_CHECK_NUM                50
#define WHITE_BLACK_MISMATCH_CHECK_MS       100 //100ms == 0.1s

void Task_SF_SpeedControl_Detection(void)
{
    if(USE_SAFETY_SPEED_CONTROL == 0)
    {
        return;
    }

    int bno = 0;
    
    // reference & measured speed mismatch check
    for(bno=0; bno<MAX_MC; bno++)
    {
        if(++_mboard.speed_info.safety_speed.meas_active_cnt[bno] > 5)
        {
            continue;
        }
        if(++_mboard.speed_info.safety_speed.ref_active_cnt[bno] > 5)
        {
            continue;
        }
        
        
        if(fabs(_mboard.speed_info.safety_speed.ref_speed_in_dps_output[bno]-_mboard.speed_info.safety_speed.meas_speed_in_dps_output[bno]) > REF_MEAS_SPEED_MISMATCH_THRESHOLD)
        {
            _mboard.speed_info.safety_speed.mismatch_cnt[bno]++;            
        }
        else
        {
            if(_mboard.speed_info.safety_speed.mismatch_cnt[bno] > 0)
            {
                _mboard.speed_info.safety_speed.mismatch_cnt[bno]--;
            }
        }
        
        if((_mboard.safety_result.safety_state_ref_speed_mismatch_detected == 0) &&
                (_mboard.speed_info.safety_speed.mismatch_cnt[bno] > SF_SPD_MISMATCH_CHECK_NUM))
        {
            _mboard.safety_result.safety_state_ref_speed_mismatch_detected = 1;        
        }
        
        if (    (_mboard.safety_result.safety_state_ref_speed_mismatch_detected == 1) &&
                (_mboard.speed_info.safety_speed.mismatch_cnt[0] < 3) &&
                (_mboard.speed_info.safety_speed.mismatch_cnt[1] < 3) &&
                (_mboard.speed_info.safety_speed.mismatch_cnt[2] < 3) &&
                (_mboard.speed_info.safety_speed.mismatch_cnt[3] < 3)
            )
        {
            //recovery behavior
            _mboard.safety_result.safety_state_ref_speed_mismatch_detected = 0;
            _mboard.comm_info.cmd_recover_op_stop_state = 0;        
            _mboard.safety_result.operational_stop_state_flag = 0;
            SafetyStop(SAFETY_MODE_NORMAL, 0);
        }
    }

    // check measured speed not over the target speed (maximum speed & low speed at manual mode)
    float vr = _mboard.speed_info.safety_speed.meas_speed_in_dps_output[0] * D2R;//*2.0 *PI; //* D2R; //???  dps ??? rps???? 
    float vl = _mboard.speed_info.safety_speed.meas_speed_in_dps_output[1] * D2R;//*2.0 *PI; //* D2R;
    
    float sr = (float)(vr*_mboard.robot_info.wheel_radius);
    float sl = (float)(vl*_mboard.robot_info.wheel_radius);
    float dtheta = (float)((sr-sl)/_mboard.robot_info.wheel_saparation);

    float cur_lin_speed = (sr+sl)*0.5;          // mm/s -- because dt = 0.01 
    float cur_rot_speed = (dtheta);            // rad/s
    
    float target_linear_speed = _mboard.robot_info.max_linear_speed + 10.0;     // 10 means esp <mm/s>
    float target_rotation_speed = _mboard.robot_info.max_rotation_speed + 0.02; // 0.02 means esp <rad/s>
    
    if(_mboard.comm_info.sm_om_state == SM_OM_NORMAL_OP_MANUAL)
    {
        target_linear_speed = _mboard.robot_info.monitoring_linear_speed + 10.0;
        target_rotation_speed = _mboard.robot_info.monitoring_rotation_speed + 0.02;
    }
    
    if((fabs(cur_lin_speed) > target_linear_speed) || (fabs(cur_rot_speed) > target_rotation_speed))
    {
        _mboard.speed_info.safety_speed.ovrspd_cnt++;
    }
    
    else
    {
        if(_mboard.speed_info.safety_speed.ovrspd_cnt > 0)
        {
            _mboard.speed_info.safety_speed.ovrspd_cnt--; 
        }
    }
    
    if((_mboard.safety_result.safety_state_over_speed_detected == 0) &&
            (_mboard.speed_info.safety_speed.ovrspd_cnt > SF_OVR_SPD_CHECK_NUM))
    { 
        _mboard.safety_result.safety_state_over_speed_detected = 1;
    }
        
    unsigned char temp22[8];
    temp22[0] = (int)(fabs(cur_lin_speed)/10.0);
    temp22[1] = (int)(target_linear_speed/10.0);
    temp22[2] = (int)(fabs(cur_rot_speed)*10.0);
    temp22[3] = (int)(target_rotation_speed*10.0);
    temp22[4] = _mboard.speed_info.safety_speed.ovrspd_cnt; // ????? ???
    CAN_WRITE_2(0x350+SF_MCU_NUM, 5, temp22);
}



void Task_SF_Obstacle_Detection(void)
{
    //100hz -- 0.01s = 10ms
    static const int SF_TIME_CONSTANT = 10; 

    int ossd_sig_front;
    int ossd_sig_rear;

    //static -- Data Section storage
    static unsigned int ossd_front_delay_cnt = 0;
    static unsigned int ossd_rear_delay_cnt = 0;
    static unsigned int ossd_front_recovery_cnt = 0;
    static unsigned int ossd_rear_recovery_cnt= 0;
    static unsigned int ossd_front_detected_local = 0;
    static unsigned int ossd_rear_detected_local = 0;
    


    if(USE_SAFETY_OBSTACLE_DETECTION == 0)
    {
        ossd_front_delay_cnt = 0;
        ossd_rear_delay_cnt = 0;
        ossd_front_recovery_cnt = 0;
        ossd_rear_recovery_cnt = 0;
        ossd_front_detected_local = 0;
        ossd_rear_detected_local = 0;
        return;
    }

    if((_mboard.comm_info.sm_om_state >= SM_OM_NORMAL_OP) && (_mboard.comm_info.sm_om_state <= SM_OM_NORMAL_OP_MANUAL))
    {

        //avalibale obstacle detection
        if(_mboard.type == MCU_0)
        {
            ossd_sig_front = PORTCbits.RC14;
            ossd_sig_rear = PORTFbits.RF0;
            mcu0_ossd_sig_front = ossd_sig_front;
            mcu0_ossd_sig_rear = ossd_sig_rear;
        }
        else
        {
            ossd_sig_front = PORTDbits.RD5;
            ossd_sig_rear = PORTFbits.RF1;
            mcu1_ossd_sig_front = ossd_sig_front;
            mcu1_ossd_sig_rear = ossd_sig_rear;
        }
        
        // time propagate
        ossd_front_delay_cnt++;
        ossd_rear_delay_cnt++;
        _mboard.sensor.ossd_front_counter++;
        _mboard.sensor.ossd_rear_counter++;

        // front lidar check
        if(_mboard.sensor.ossd_front_triggered == 1)
        {
            _mboard.sensor.ossd_front_triggered = 0;        
            ossd_front_delay_cnt = 0;
        }

        if(ossd_front_delay_cnt > (unsigned int)(ossd_delay_ms / SF_TIME_CONSTANT) ) //0.15s
        {
            if(ossd_sig_front == LOW)
            {
                // OBS DETECTED !!
                ossd_front_detected_local = 1;
                _mboard.safety_result.safety_state_obstacle_detected = 1;
            }
            else
            {
                // Alive
            }
        }

        // rear lidar check
        if(_mboard.sensor.ossd_rear_triggered == 1)
        {
            _mboard.sensor.ossd_rear_triggered = 0;        
            ossd_rear_delay_cnt = 0;
        }

        // check return -- if not obstacle detected
        if(ossd_rear_delay_cnt > (unsigned int)(ossd_delay_ms / SF_TIME_CONSTANT))
        {
            if(ossd_sig_rear == LOW)
            {
                // OBS DETECTED !!
                ossd_rear_detected_local = 1;
                _mboard.safety_result.safety_state_obstacle_detected = 1;
            }
            else
            {
                // Alive
            }
        }
            
        
    }

    //for automatic recovery 
    else if(_mboard.comm_info.sm_om_state == SM_OM_OPERATIONAL_STOP && _mboard.safety_result.safety_state_obstacle_detected == 1)
    {
        
        if(_mboard.type == MCU_0)
        {
            ossd_sig_front = PORTCbits.RC14;
            ossd_sig_rear = PORTFbits.RF0;
            mcu0_ossd_sig_front = ossd_sig_front;
            mcu0_ossd_sig_rear = ossd_sig_rear;
        }
        else
        {
            ossd_sig_front = PORTDbits.RD5;
            ossd_sig_rear = PORTFbits.RF1;
            mcu1_ossd_sig_front = ossd_sig_front;
            mcu1_ossd_sig_rear = ossd_sig_rear;
        }

        // front lidar ossd signal check
        if(_mboard.sensor.ossd_front_triggered == 1)
        {
            _mboard.sensor.ossd_front_triggered = 0;        
            ossd_front_recovery_cnt ++;
        }

        if((ossd_front_recovery_cnt > (unsigned int)(ossd_recovery_ms / SF_TIME_CONSTANT) ) && (_mboard.sensor.ossd_detected[0] == 1))
        {
            if(ossd_sig_front == HIGH)
            { 
                ossd_front_detected_local = 0;
            }
            else 
            {
                if(ossd_front_recovery_cnt > 0)
                {
                    ossd_front_recovery_cnt--;
                }
            }
        }
        
        // rear lidar check
        if(_mboard.sensor.ossd_rear_triggered == 1)
        {
            _mboard.sensor.ossd_rear_triggered = 0;        
            ossd_rear_recovery_cnt++;
        }

        if((ossd_rear_recovery_cnt > (unsigned int)(ossd_recovery_ms / SF_TIME_CONSTANT) ) && (_mboard.sensor.ossd_detected[1] == 1))
        {
            if(ossd_sig_rear == HIGH)
            {
                ossd_rear_detected_local = 0;
            }
            else
            {
                if(ossd_rear_recovery_cnt >0)
                {
                    ossd_rear_recovery_cnt--;
                }
            }
        }
        
        //for recovery
        if((ossd_front_detected_local == 0) && (ossd_rear_detected_local == 0))
        {
            ossd_front_recovery_cnt = 0;
            ossd_rear_recovery_cnt = 0;
            ossd_front_delay_cnt = 0;
            ossd_rear_delay_cnt = 0;
            _mboard.safety_result.safety_state_obstacle_detected = 0;
            _mboard.comm_info.cmd_recover_op_stop_state = 0;        
            _mboard.safety_result.operational_stop_state_flag = 0;
            SafetyStop(0, 0);
            
            _mboard.io.dout_for_cobot_ss2 = 0;
        }

    }
    
    _mboard.sensor.ossd_detected[0] = ossd_front_detected_local;
    _mboard.sensor.ossd_detected[1] = ossd_rear_detected_local;
}


unsigned char GetState_EMO()
{
//    return ((!PORT_EMO_A) & (!PORT_EMO_B));
    if(_mboard.type == MCU_0)
    {
        return (!PORT_EMO_1_A) | (!PORT_EMO_2_A) | (!PORT_EMO_3_A) | (!PORT_EMO_4_A);
    }
    else
    {
        return (!PORT_EMO_1_B) | (!PORT_EMO_2_B) | (!PORT_EMO_3_B) | (!PORT_EMO_4_B);
    }
}

void Task_Control_Pre_FET_On()
{
    if(_mboard.type == MCU_0)
    {
        LAT_MOTOR_PRE_FET_A = HIGH;
    }
    else
    {
        LAT_MOTOR_PRE_FET_B = HIGH;
    }
}

void Task_Control_Pre_FET_Off()
{
    if(_mboard.type == MCU_0)
    {
        LAT_MOTOR_PRE_FET_A = LOW;
    }
    else
    {
        LAT_MOTOR_PRE_FET_B = LOW;
    }
}

void Task_Control_Main_FET_On()
{
    if(_mboard.type == MCU_0)
    {
        LAT_MOTOR_MAIN_FET_A = HIGH;
    }
    else
    {
        LAT_MOTOR_MAIN_FET_B = HIGH;
    }
}

void Task_Control_Main_FET_Off()
{
    if(_mboard.type == MCU_0)
    {
        LAT_MOTOR_MAIN_FET_A = LOW;
    }
    else
    {
        LAT_MOTOR_MAIN_FET_B = LOW;
    }
}



void Task_Control_Lift_Pre_FET_On()
{
    if(_mboard.type == MCU_1)
    {
        LAT_LIFT_PRE_FET = HIGH;
    }
}

void Task_Control_Lift_Pre_FET_Off()
{
    if(_mboard.type == MCU_1)
    {
        LAT_LIFT_PRE_FET = LOW;
    }
}

void Task_Control_Lift_Main_FET_On()
{
    if(_mboard.type == MCU_1)
    {
        LAT_LIFT_MAIN_FET = HIGH;
    }
}

void Task_Control_Lift_Main_FET_Off()
{
    if(_mboard.type == MCU_1)
    {
        LAT_LIFT_MAIN_FET = LOW;
    }
}




void MotorController_FET_OnOff(int onoff)
{
    int id = 0x10;
    unsigned char data[8];
    data[0] = 0x0B;
    data[1] = 0x00;
    data[2] = onoff;

    CAN_WRITE_1(id, 3, data);
    CAN_WRITE_1(id+1, 3, data);
    CAN_WRITE_1(id+2, 3, data);
    CAN_WRITE_1(id+3, 3, data);
}

void SolenoidControl(int target, int mode)
{
    int id;
    unsigned char data[8];
    
    if(target == 0x00)
    {
        id = 0x10;
    }
    else if(target == 0x01)
    {
        id = 0x11;
    }
    data[0] = 0xC0;
    
    if(mode == 0)
    {
        // Off
        data[1] = 0;
    }
    else if(mode == 1)
    {
        // Hard Push
        data[1] = 1;
    }
    
    CAN_WRITE_1(id, 2, data);
}

void SafetyStopInfoMessage(int mode)
{
    uint8_t data[1];
    
    // mode 1 :sto || mode 2 : ss1 || mode 3 : ss2 || mode 4 : cobot ss2 ||| mode 5 : ewellix sto
    data[0] = mode;
   
    CAN_WRITE_2( 0x125, 1, data);
}

void SafetyStop(int mode, int time_10ms)
{
    int id = 0x04;
    unsigned char data[8];
    
    if(mode == SAFETY_MODE_NORMAL)
    {
        // Go back to Normal
        data[0] = 0;
    }
    else if(mode == SAFETY_MODE_STO)
    {
        // STO
        data[0] = 1;
    }
    else if(mode == SAFETY_MODE_SS1)
    {
        // SS1
        data[0] = 2;
        data[1] = time_10ms;
    }
    else if(mode == SAFETY_MODE_SS2)
    {
        // SS2
        data[0] = 3;
        data[1] = time_10ms;
    }

    CAN_WRITE_1(id, 2, data);
    CAN_WRITE_1(id+1, 2, data);
}


void CommDataHandler()
{
    static unsigned char cnt = 0;
    unsigned char temp[8];
    int idx = 0;
    
    cnt++;
    
    if(_mboard.type == MCU_0)
    {
        if(cnt%5 == 0)
        {
            // Power Info
            unsigned short v_i = (unsigned short)(_mboard.sensor.adc_inlet_voltage*10.0);
            unsigned short v_o = (unsigned short)(_mboard.sensor.adc_outlet_voltage*10.0);
            unsigned short c_l = (unsigned short)(_mboard.sensor.adc_current_line*10.0);
            temp[0] = 0x01;     // power info
            temp[1] = v_i&0xFF;
            temp[2] = (v_i>>8)&0xFF;
            temp[3] = v_o&0xFF;
            temp[4] = (v_o>>8)&0xFF;
            temp[5] = c_l&0xFF;
            temp[6] = (c_l>>8)&0xFF;
            CAN_WRITE_2(0x700, 7, temp);
        }
        else if(cnt%5 == 1)
        {
            unsigned char in = 0;
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_emo_pressed & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_ref_speed_mismatch_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_over_speed_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_obstacle_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_speed_field_mismatch_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.operational_stop_state_flag & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_interlock_stop_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_bumper_stop_detected & 0x01);

            // Safety Function Info
            temp[0] = 0x00;         // SF info
            temp[1] = in;

            CAN_WRITE_2(0x701, 2, temp);
        }
        else if(cnt%5 == 2)
        {
            // Reset Stop Start
            temp[0] = _mboard.io.sw_reset;
            temp[1] = _mboard.io.sw_stop;
            temp[2] = _mboard.io.sw_start;
            CAN_WRITE_2(0x702, 3, temp);
        }
        else if(cnt%5 == 3)
        {
            // Digital Input & Output
            unsigned char in = 0;
            unsigned char out = 0;
            for(idx=7; idx>=0; idx--)
            {
                in <<= 1;
                in |= (_mboard.io.din[8+idx]&0x01);
                out <<= 1;
                out |= (_mboard.io.dout[8+idx]&0x01);
            }
            temp[0] = in;
            temp[1] = out;
            CAN_WRITE_2(0x703, 2, temp);
        }
        else if(cnt%5 == 4)
        {
            
        }
    }
    else
    {
        if(cnt%5 == 0)
        {
            // Power Info
            unsigned short v_i = (unsigned short)(_mboard.sensor.adc_inlet_voltage_lift*10.0);
            unsigned short v_o = (unsigned short)(_mboard.sensor.adc_outlet_voltage_lift*10.0);
            unsigned short c_l = (unsigned short)(_mboard.sensor.adc_current_line_lift*10.0);
            temp[0] = 0x01;     // power info
            temp[1] = v_i&0xFF;
            temp[2] = (v_i>>8)&0xFF;
            temp[3] = v_o&0xFF;
            temp[4] = (v_o>>8)&0xFF;
            temp[5] = c_l&0xFF;
            temp[6] = (c_l>>8)&0xFF;
            CAN_WRITE_2(0x710, 7, temp);
        }
        else if(cnt%5 == 1)
        {
            // Safety Function Info
            unsigned char in = 0;
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_emo_pressed & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_ref_speed_mismatch_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_over_speed_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_obstacle_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_speed_field_mismatch_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.operational_stop_state_flag & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_interlock_stop_detected & 0x01);
            in <<= 1;
            in |= (_mboard.safety_result.safety_state_bumper_stop_detected & 0x01);

            temp[0] = 0x00;         // SF info
            temp[1] = in;

            CAN_WRITE_2(0x711, 2, temp);
        }
        else if(cnt%5 == 2)
        {
            // Analog Input & Output
            temp[0] = 0;//(unsigned char)((int)(_mboard.io.adc_value[0]*10.0));
            temp[1] = 0;//(unsigned char)((int)(_mboard.io.adc_value[1]*10.0));
            temp[2] = 0;//(unsigned char)((int)(_mboard.io.adc_value[2]*10.0));
            temp[3] = 0;//(unsigned char)((int)(_mboard.io.adc_value[3]*10.0));
            temp[4] = 0;//(unsigned char)((int)(_mboard.io.dac_value[0]*10.0));
            temp[5] = 0;//(unsigned char)((int)(_mboard.io.dac_value[1]*10.0));
            temp[6] = 0;//(unsigned char)((int)(_mboard.io.dac_value[2]*10.0));
            temp[7] = 0;//(unsigned char)((int)(_mboard.io.dac_value[3]*10.0));
//            CAN_WRITE_2(0x712, 8, temp);
        }
        else if(cnt%5 == 3)
        {
            // Digital Input & Output
            unsigned char in = 0;
            unsigned char out = 0;
            for(idx=7; idx>=0; idx--)
            {
                in <<= 1;
                in |= (_mboard.io.din[0+idx]&0x01);
                out <<= 1;
                out |= (_mboard.io.dout[0+idx]&0x01);
            }
            temp[0] = in;
            temp[1] = out;
            CAN_WRITE_2(0x713, 2, temp);
        }
        else if(cnt%5 == 4)
        {
            
        }
    }
}

void DebugDataHandler()
{
    unsigned char temp[8];
    int idx = 0;
    
}

unsigned char getBumperSwitch(void)
{
    //if bumpper switch is pressed, it will retrun high       
    if(_mboard.type == MCU_0)
    {
        return (!PORT_BUMP_1_A) | (!PORT_BUMP_1_C) | (!PORT_BUMP_1_E) | (!PORT_BUMP_1_G);
    }
    else
    {   
        return (!PORT_BUMP_2_B) | (!PORT_BUMP_2_D) | (!PORT_BUMP_2_F) | (!PORT_BUMP_2_H);
    }

}   

void Task_SF_ChannelCheck(void)
{
    // data hz : 50hz
    // check white and black raw data match
    
    // TODO : Check Timing issue 
    unsigned char board_num;
    int i=0;
    
    for(board_num =0; board_num < 4; board_num++)
    {
        unsigned char WHITE_SEQ = _mboard.speed_info.safety_raw[board_num].white_count_old;
        unsigned char BLACK_SEQ = _mboard.speed_info.safety_raw[board_num].black_count_old;
        
        if(WHITE_SEQ == BLACK_SEQ)
        {
            unsigned char TIMING_SEQ = WHITE_SEQ;
            
            unsigned short white_raw = _mboard.speed_info.safety_raw[board_num].raw_bytes_white[TIMING_SEQ];
            unsigned short black_raw = _mboard.speed_info.safety_raw[board_num].raw_bytes_black[TIMING_SEQ]; 
            
            if(white_raw != black_raw)
            {
              _mboard.speed_info.safety_raw[board_num].white_black_mimatch_cnt++;
            }
        }
    }
    for(board_num =0; board_num <4; board_num++)
    {
        //MS 
        if(_mboard.speed_info.safety_raw[board_num].white_black_mimatch_cnt > 0.05 * WHITE_BLACK_MISMATCH_CHECK_MS)
       {
            _mboard.safety_result.safety_state_speed_field_mismatch_detected = 1;
        }

         //if you want to recover from speed field mismatch state, you can use the below code
        // else
        // {
        //     _mboard.safety_result.safety_state_speed_field_mismatch_detected = 0;
        
    }
}



void Task_SF_COBOT_SS2(void)
{
    //one shot trigger
    if(_mboard.safety_result.cmd_cobot_ss2 == 1)
    {
        _mboard.safety_result.cmd_cobot_ss2 = 0;
        _mboard.safety_result.operational_stop_state_flag = 1;
        
        //do something
        _mboard.io.dout_for_cobot_ss2 = 1;
        SafetyStopInfoMessage(COBOT_SS2_MESSAGE_NUM);
    }
}

void Task_SF_COBOT_PRS(void)
{
    if(_mboard.safety_result.prs_state == 1)
    {
        _mboard.io.dout_for_cobot_prs = 1;
    }
    else    
    {
        _mboard.io.dout_for_cobot_prs = 0;
    }

    // send reset state to comm board
    if(_mboard.type == MCU_0)
    {
        CAN_WRITE_2(0x704, 1, &_mboard.safety_result.prs_state);
    }
    else
    {
        CAN_WRITE_2(0x714, 1, &_mboard.safety_result.prs_state);
    }

}

void Task_SF_COBOT_SS2_RECOVERY(void)
{


}

void Task_SF_COBOT_SSS_RECOVERY(void)
{
    static unsigned int sss_recovery_cnt = 0;

    if(_mboard.safety_result.cmd_recovery_cobot_sss == 1)
    {
        if(_mboard.safety_result.safety_state_emo_pressed == 0 && _mboard.safety_result.safety_state_bumper_stop_detected == 0)
        {
            _mboard.io.dout_for_cobot_prs = 0;
        }
        
        _mboard.safety_result.cmd_recovery_cobot_sss = 0;
    }
}

#ifdef SEM
void Task_SF_EWELLIX_STO(void)
{
    if(_mboard.safety_result.cmd_ewellix_sto == 1)
    {
        _mboard.safety_result.cmd_ewellix_sto = 0;
        _mboard.safety_result.operational_stop_state_flag = 1;
        
        //do something
        _mboard.io.dout_for_torso_sto = 1;
        
        SafetyStopInfoMessage(EWELLIX_STO_MESSAGE_NUM);
    }
    
}
#endif
