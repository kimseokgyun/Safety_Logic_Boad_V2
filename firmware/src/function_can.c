#include "system_general_configuration.h"

// ------------------------------------------------
// Safety Data Format
// ------------------------------------------------
// White Channel
// ID = 0x400 + BNO
//
// Black Channel
// ID = 0x410 + BNO
//
// Frequency
// 50 Hz
//
// DLC
// 7
//
// Data
// [0] = POS1 (LSB)
// [1] = POS1
// [2] = POS2 (LSB)
// [3] = POS2
// [4] = CUR1 (LSB)
// [5] = CUR2 (LSB)
// [6] = counter
// ------------------------------------------------
// Safety Control Format
// ------------------------------------------------
// ID = 0x04
// DLC = 2
// Data
// [0] = MODE (0 = normal / 1 = sto / 2 = ss1 / 3 = ss2)
// [1] = count (10~100)


#define NUM_OF_CAN_TX_CHANNEL       2
#define NUM_OF_CAN_RX_CHANNEL       2

unsigned int test_constant = 0;
// CAN_TX_MSG_BUFFER --> 16byte
// size : buffer number * FIFO number
// FIFO0 - Transmit - 4 Message Buffer
// FIFO1 - Transmit - 4 Message Buffer
// FIFO2 - Receive  - 4 Message Buffer
// FIFO3 - Receive  - 4 Message Buffer
// FIFO4 - FIFO31   - Not used
// 4*4 + 4*4 + 4*4 + 4*4 = 64
//CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer0[4*4 + 4*4 + 4*4 + 4*4];
//CAN_TX_MSG_BUFFER  *drv_Message0;
//
//CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer1[4*4 + 4*4 + 4*4 + 4*4];
//CAN_TX_MSG_BUFFER  *drv_Message1;

CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer0[16*4];
CAN_TX_MSG_BUFFER  *drv_Message0;

CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer1[16*4];
CAN_TX_MSG_BUFFER  *drv_Message1;

inline void CAN_TX_SAFETY_ISSUE(unsigned char PMODE_type){
    
}

/*******************************************************************************
 * User CAN TX functions
 ******************************************************************************/


/*******************************************************************************
 * User CAN RX functions
 ******************************************************************************/

#define         CAN_ID_OFFSET_WHITE         0x400
#define         CAN_ID_OFFSET_BLACK         0x410

#define         CAN_ID_OFFSET_REFERENCE     0x40

#define         WHITE_BLACK_COUNT_FAIL_BOUND_NUM      5

void CAN_PARSER_1(uint32_t id, uint8_t data[], uint8_t dlc, uint8_t chnum)
{

    unsigned char type_shadow = _mboard.type;
//    const float _dt = 0.002;
    const float _hz = 500.0;
    float PPR = _mboard.robot_info.dir * 16384.0 * _mboard.robot_info.gear_ratio / 360.0;


    if((id >= CAN_ID_OFFSET_WHITE) && (id < CAN_ID_OFFSET_WHITE+MAX_MC))
    {

        
        unsigned char bno = id - CAN_ID_OFFSET_WHITE;
        unsigned char temp_count = data[0];

        short vel1 = data[1] | (data[2] << 8);
        short vel2 = data[3] | (data[4] << 8);

        _mboard.speed_info.safety_raw[bno].raw_bytes_white[temp_count][1] = data[1];
        _mboard.speed_info.safety_raw[bno].raw_bytes_white[temp_count][2] = data[2];
        _mboard.speed_info.safety_raw[bno].raw_bytes_white[temp_count][3] = data[3];
        _mboard.speed_info.safety_raw[bno].raw_bytes_white[temp_count][4] = data[4];
        _mboard.speed_info.safety_raw[bno].cycle_time_cnt = 0;

        short delta_count = temp_count - _mboard.speed_info.safety_raw[bno].white_count_old;
        
        // Handle rollover case when counter wraps from max (255) back to 0
        if(delta_count == -(SAFETY_COUNT_NUM-1))
        {
            delta_count = 1;
        }
        
        if(_mboard.speed_info.safety_raw[bno].white_count_old >= 0 && delta_count != 1)
        {
            if(_mboard.speed_info.safety_raw[bno].count_fail_cnt_white < WHITE_BLACK_COUNT_FAIL_BOUND_NUM)
            {
                _mboard.speed_info.safety_raw[bno].count_fail_cnt_white++;
            }
        }
        else
        {
            if(_mboard.speed_info.safety_raw[bno].count_fail_cnt_white > 0)
            {
                _mboard.speed_info.safety_raw[bno].count_fail_cnt_white--;
            }
        }
        _mboard.speed_info.safety_raw[bno].white_count_old = temp_count;

                
        if(type_shadow == MCU_0)
        {
            _mboard.speed_info.safety_speed.meas_active_cnt[bno] = 0;
            _mboard.speed_info.safety_speed.meas_speed_in_pps[bno] = vel1*1000.0; //1S??? ??? ?? -- PPS
            _mboard.speed_info.safety_speed.meas_speed_in_dps_output[bno] = _mboard.speed_info.safety_speed.meas_speed_in_pps[bno]/PPR; //Pulses Per Revolution
            //in_dps_out variable is RPS
        }
        else
        {
            _mboard.speed_info.safety_speed.meas_active_cnt[bno] = 0;
            _mboard.speed_info.safety_speed.meas_speed_in_pps[bno] = vel2*1000.0;
            _mboard.speed_info.safety_speed.meas_speed_in_dps_output[bno] = _mboard.speed_info.safety_speed.meas_speed_in_pps[bno]/PPR;
        }    

    }

    else if((id >= CAN_ID_OFFSET_BLACK) && (id < CAN_ID_OFFSET_BLACK+MAX_MC))
    {
        unsigned char bno = id - CAN_ID_OFFSET_BLACK;
        unsigned char temp_count = 255 - data[0];

        _mboard.speed_info.safety_raw[bno].raw_bytes_black[temp_count][1] = data[1];
        _mboard.speed_info.safety_raw[bno].raw_bytes_black[temp_count][2] = data[1];
        _mboard.speed_info.safety_raw[bno].raw_bytes_black[temp_count][3] = data[1];
        _mboard.speed_info.safety_raw[bno].raw_bytes_black[temp_count][4] = data[1];


        short delta_count = temp_count - _mboard.speed_info.safety_raw[bno].black_count_old;

        // -255
        if(delta_count == -(SAFETY_COUNT_NUM-1))
        {        
            delta_count = 1;
        }
        if(_mboard.speed_info.safety_raw[bno].black_count_old >=0 && delta_count !=1 )
        {
            if(_mboard.speed_info.safety_raw[bno].count_fail_cnt_black < WHITE_BLACK_COUNT_FAIL_BOUND_NUM)
            {
                _mboard.speed_info.safety_raw[bno].count_fail_cnt_black++;
            }
        }
        else
        {
            if(_mboard.speed_info.safety_raw[bno].count_fail_cnt_black > 0)
            {
                _mboard.speed_info.safety_raw[bno].count_fail_cnt_black--;
            }
        }
        _mboard.speed_info.safety_raw[bno].black_count_old = temp_count;
    }    


    else if((id >= CAN_ID_OFFSET_REFERENCE) && (id < CAN_ID_OFFSET_REFERENCE+MAX_MC))
    {
        // reference 
        int bno = id - CAN_ID_OFFSET_REFERENCE;
        _mboard.speed_info.safety_speed.ref_active_cnt[bno] = 0;
        int temp_delta_enc = (int)((data[0]) | ((int)(data[1]) << 8) | ((int)(data[2]) << 16) | ((int)(data[3]) << 24));
        _mboard.speed_info.safety_speed.ref_speed_in_pps[bno] = temp_delta_enc*_hz/10.0; // 10 means amplified reference
        _mboard.speed_info.safety_speed.ref_speed_in_dps_output[bno] = _mboard.speed_info.safety_speed.ref_speed_in_pps[bno]/PPR;
    }

}


void CAN_PARSER_2(uint32_t id, uint8_t data[], uint8_t dlc, uint8_t chnum)
{
    unsigned char type_shadow = _mboard.type;
//    const float _dt = 0.002;
    const float _hz = 500.0;
    float PPR = _mboard.robot_info.dir * 16384.0 * _mboard.robot_info.gear_ratio / 360.0;
    float param_float;
    unsigned char param_u_char;
    
    
    if(type_shadow == MCU_0)
    {
        if(id == 0x222) //reset
        {
            if(data[0] == 0xAA && data[1] == 0xBB && data[2] == 0xCC && data[3] == 0xDD)
            {
                RESET();
            }
        }
        
        if(id == 0x770)
        {
            // digital out for MCU 0
            int idx = 0;
            for(idx=0; idx<8; idx++)
            {
                _mboard.io.dout[8+idx] = data[idx];
            }
        }
    }
    else
    {
        if(id == 0x223) //reset
        {
            if(data[0] == 0xAA && data[1] == 0xBB && data[2] == 0xCC && data[3] == 0xDD)
            {
                RESET();
            }
        }
        else if(id == 0x702) //MCU0 -> MCU1 IO Info
        {
            _mboard.io.sw_reset = data[0];
            _mboard.io.sw_stop =  data[1];
            _mboard.io.sw_start = data[2];
        }
        else if(id == 0x771)
        {
            // digital out for MCU 1
            int idx = 0;
            for(idx =0; idx <8; idx++)
            {
                _mboard.io.dout[0+idx] = data[idx]; 
            }
        }
        else if(id == 0x773)
        {
            // analog out(dac) for MCU 1
            int idx = 0;
//            for(idx=0; idx<4; idx++)
//            {
//                _mboard.io.dac_value[idx] = ((float)((unsigned int)(data[idx])))/10.0;
//            }
        }
        
    }
    
    if(id == 0x777)
    {
        // from Comm Board
        if(data[0] == 0x00)
        {
            // Data
            if(data[1] == 0x00)
            {
                // State
                _mboard.comm_info.sm_om_state = data[2];
                _mboard.comm_info.ri_state = data[3];
                _mboard.comm_info.charge_state = data[4];
            }
            else if(data[1] == 0x10)
            {
                // Set Robot Param
                if(data[2] == 0x00)
                {
                    // type dir gear ratio
                    _mboard.robot_info.robot_type = data[3];
                    _mboard.robot_info.dir = (int)((char)(data[4]));
                    _mboard.robot_info.gear_ratio = ((float)((short)(data[5]|(data[6]<<8)))) / 100.0;
                }
                else if(data[2] == 0x01)
                {
                    // wheel radius 
                    uint32_t raw_data = (data[3]) | (data[4] << 8) | (data[5] << 16) | (data[6] << 24);
                    memcpy(&_mboard.robot_info.wheel_radius, &raw_data, sizeof(float));
//                    _mboard.robot_info.wheel_radius = ((float)((short)(data[3]|(data[4]<<8)))) / 100.0;
//                    _mboard.robot_info.wheel_saparation = ((float)((short)(data[5]|(data[6]<<8)))) / 100.0;
                }
                else if(data[2] ==0x04)
                {
                    // wheel saparation
                    uint32_t raw_data = (data[3]) | (data[4] << 8) | (data[5] << 16) | (data[6] << 24);
                    memcpy(&_mboard.robot_info.wheel_saparation, &raw_data, sizeof(float));
                }
                else if(data[2] == 0x02)
                {
                    // max lin speed rot speed
                    //seokgyun
//                    _mboard.robot_info.max_linear_speed = ((float)((short)(data[3]|(data[4]<<8)))) ;
//                    _mboard.robot_info.max_rotation_speed = ((float)((short)(data[5]|(data[6]<<8)))) ;                  
                    _mboard.robot_info.max_linear_speed = ((float)((short)(data[3]|(data[4]<<8)))) ;// /100.0; // recive <mm/sec>  //data3 -- LSB
                    _mboard.robot_info.max_rotation_speed = ((float)((short)(data[5]|(data[6]<<8)))) / 100.0; // recive <rad/sec>
                }
                else if(data[2] == 0x03)
                {
                    // monitoring lin speed rot speed
                    //seokgyun
//                    _mboard.robot_info.monitoring_linear_speed = ((float)((short)(data[3]|(data[4]<<8)))) ;
//                    _mboard.robot_info.monitoring_rotation_speed = ((float)((short)(data[5]|(data[6]<<8))));
                    _mboard.robot_info.monitoring_linear_speed = ((float)((short)(data[3]|(data[4]<<8)))); // / 100.0;
                    _mboard.robot_info.monitoring_rotation_speed = ((float)((short)(data[5]|(data[6]<<8))));  // / 100.0;
                }
            }

            else if(data[1] == 0x11)
            {
                // Requeset Robot Param
                if(data[2] == 0x00)
                {
                    // type dir gear ratio
                }
                else if(data[2] == 0x01)
                {
                    // wheel radius saparation
                }
                else if(data[2] == 0x02)
                {
                    // max lin speed rot speed
                }
                else if(data[2] == 0x03)
                {
                    // monitoring lin speed rot speed
                }
                else if(data[2] == 0x04)
                {   
                    // for firmware parameter
                    switch(data[3])
                    {
                        case OSSD_DELAY_PARAM_SET:
                            memcpy(&param_float, &data[4], sizeof(float));
                            ParamSet_Ossd_Delay_ms(param_float);
                            break;
                            
                        case OSSD_RECOVERY_PARAM_SET:
                            memcpy(&param_float, &data[4], sizeof(float));
                            ParamSet_Ossd_Recovery_ms(param_float);
                            break;
                            
#ifdef SEM
                        case  EWELLIX_INTERLOCK_PIN_SET_1:
                            param_u_char = data[4];
                            ParamSet_EWELLIX_INTERLOCK_PIN_1(param_u_char);
                            break;
                            
                        case  EWELLIX_INTERLOCK_PIN_SET_2:
                            param_u_char = data[4];
                            ParamSet_EWELLIX_INTERLOCK_PIN_2(param_u_char);
                            break;
                            
                        case  COBOT_INTERLOCK_PIN_SET_1:
                            param_u_char = data[4];
                            ParamSetCOBOT_INTERLOCK_PIN_1(param_u_char);
                            break;
                            
                        case  COBOT_INTERLOCK_PIN_SET_2:
                            param_u_char = data[4];
                            ParamSetCOBOT_INTERLOCK_PIN_2(param_u_char);
                            break;         
#endif
                        // FOR SAFETY LOGIC PARAMETER SET
                        case USE_SAFETY_CROSS_MONITORING_SET:
                            param_u_char = data[4];
                            CAN_WRITE_2(0x496, 1, param_u_char);
                            ParamSet_USE_SAFETY_CROSS_MONITORING(param_u_char);
                            break;

                        case USE_SAFETY_SPEED_CONTROL_SET:
                            param_u_char = data[4];
                            CAN_WRITE_2(0x497, 1, param_u_char);
                            ParamSet_USE_SAFETY_SPEED_CONTROL(param_u_char);
                            break;

                        case USE_SAFETY_OBSTACLE_DETECTION_SET:
                            param_u_char = data[4];
                            CAN_WRITE_2(0x498, 1, param_u_char);
                            ParamSet_USE_SAFETY_OBSTACLE_DETECTION(param_u_char);
                            break;

                        case USE_SAFETY_BUMPER_SET:
                            param_u_char = data[4];
                            CAN_WRITE_2(0x499, 1, param_u_char);
                            ParamSet_USE_SAFETY_BUMPER(param_u_char);
                            break;

                        case USE_SAFETY_INTERLOCK_SET:  
                            param_u_char = data[4];
                            CAN_WRITE_2(0x49A, 1, param_u_char);
                            ParamSet_USE_SAFETY_INTERLOCK(param_u_char);
                            break;

                        default:
                            break;
                    }
                
                }
            }
        }
        //-------------------------------------
        else if(data[0] == 0x01)
        {
            // Command
            if(data[1] == 0x01)
            {
                // Motor Power On Off
                if(data[2] == 0x01)
                {
                    // on
                    if(data[3] == 0x00)
                    {
                        _mboard.comm_info.cmd_power_on = 1;
                    }
                    else if(data[3] == 0x01)
                    {
                        _mboard.comm_info.cmd_lift_power_on = 1;
                    }
                }
                else
                {
                    // off
                    if(data[3] == 0x00)
                    {
                        _mboard.comm_info.cmd_power_off = 1;
                    }
                    else if(data[3] == 0x01)
                    {
                        _mboard.comm_info.cmd_lift_power_off = 1;
                    }
                }
            }
            else if(data[1] == 0x02)
            {
                // Safety Result Clear
                if(data[2] == 0x00)
                {
                    // emo -> not work
                }
                else if(data[2] == 0x01)
                {
                    // ref meas mismatch
                    int bno;
                    for(bno=0; bno<MAX_MC; bno++)
                    {
                        _mboard.speed_info.safety_speed.mismatch_cnt[bno] = 0;
                    }
                    _mboard.safety_result.safety_state_ref_speed_mismatch_detected = 0;
                    
                }
                else if(data[2] == 0x02)
                {
                    // over speed
                    int bno;
                    for(bno=0; bno<MAX_MC; bno++)
                    {
                        _mboard.speed_info.safety_speed.ovrspd_cnt = 0;
                    }
                    _mboard.safety_result.safety_state_over_speed_detected = 0;
                }
                else if(data[2] == 0x03)
                {
                    // obs detected
                    _mboard.safety_result.safety_state_obstacle_detected = 0;

                    // if(USE_COBOT_SS2 == 1)
                    // {
                    //     _mboard.io.dout_for_cobot_ss2 = 0;
                    // }
                }
                else if(data[2] == 0x04)
                {
                    // spd field mismatch
                    _mboard.safety_result.safety_state_speed_field_mismatch_detected = 0;
                }
                else if(data[2] == 0x05) 
                {
                    // interlocking stop 
                    _mboard.safety_result.safety_state_interlock_stop_detected = 0;
                }
                else if(data[2] == 0x06)
                {

                    // bumper stop
                    _mboard.safety_result.safety_state_bumper_stop_detected = 0;

                    // if(USE_COBOT_SSS == 1 )
                    // {
                    //     if(_mboard.safety_result.safety_state_emo_pressed == 0)
                    //     {
                    //         _mboard.io.dout_for_cobot_sss = 0;
                    //     }
                    // }
                }
                else if (data[2] == 0x07)
                {
                    // cobot sss recovery signal
                    _mboard.safety_result.cmd_recovery_cobot_sss = 1;
                }

            }
            else if(data[1] == 0x03)
            {
                // Recover Operational Stop State
                _mboard.comm_info.cmd_recover_op_stop_state = 1;
                
            }
            else if(data[1] == 0xFF)
            {
                //seokgyun test 
                test_constant = (unsigned int)data[2];
            }
            
            else if(data[1] == 0xFE)
            {
                obstacle_detect_mode = (unsigned int)data[2];

                if(obstacle_detect_mode == 1)
                {
                    //use detect mode -- 
                    USE_SAFETY_OBSTACLE_DETECTION = 1;

                }
                else if(obstacle_detect_mode == 0) // no detect mode
                {
                    
                    //cobot parameter set
                    _mboard.io.dout_for_cobot_ss2 = 0;
                    // clear flag
                    USE_SAFETY_OBSTACLE_DETECTION = 0;
                    _mboard.safety_result.safety_state_obstacle_detected = 0;
                    _mboard.safety_result.operational_stop_state_flag = 0;
                    _mboard.comm_info.cmd_recover_op_stop_state = 0;  
                    SafetyStop(0, 0);
                }
                
            }
            
            
        }
        //-------------------------------------
        else if(data[0] == 0x02)
        {
            // Data
        }
        //-------------------------------------
        else if(data[0] == 0x03){
            // Rom
        }
    }
    
}



/*******************************************************************************
 * General CAN functions
 ******************************************************************************/

char CAN_WRITE_1(int address, uint8_t DLC, uint8_t *message){
    static unsigned int *initFIFOINT = (unsigned int*)&C1FIFOINT0;
    static unsigned int *initFIFOUA  = (unsigned int*)&C1FIFOUA0;    
    static unsigned int *initFIFOCON = (unsigned int*)&C1FIFOCON0;
    
    unsigned int *tempFIFOINT;
    unsigned int *tempFIFOUA;
    unsigned int *tempFIFOCON;
    
    int channel;
    int count = 0;
    
    for(channel=0; channel<NUM_OF_CAN_TX_CHANNEL; channel++){
        tempFIFOINT = &(initFIFOINT[16*channel]);
        
        if( ((*tempFIFOINT)>>10) & 0x00000001 == 1 ){  // if TXNFULLIF
            tempFIFOUA = &(initFIFOUA[16*channel]);
            drv_Message0 = (CAN_TX_MSG_BUFFER*)PA_TO_KVA1(*tempFIFOUA);
            drv_Message0->msgSID.sid     = address;
            drv_Message0->msgEID.eid     = 0;
            drv_Message0->msgEID.ide     = 0; 
            
            if (DLC > 8) DLC = 8;
            
            drv_Message0->msgEID.data_length_code = DLC;
            while(count < DLC){
                drv_Message0->data[count++] = *message++;
            }

            //Update CAN module and then transmit data on the bus;
            tempFIFOCON = &(initFIFOCON[16*channel]);
            *tempFIFOCON = *tempFIFOCON | (1<<13);  // set UINC
            *tempFIFOCON = *tempFIFOCON | (1<<3);   // set TXREQ
            return true;
        }
    }
    return false;
}

char CAN_WRITE_2(int address, uint8_t DLC, uint8_t *message){
    static unsigned int *initFIFOINT = (unsigned int*)&C2FIFOINT0;
    static unsigned int *initFIFOUA  = (unsigned int*)&C2FIFOUA0;    
    static unsigned int *initFIFOCON = (unsigned int*)&C2FIFOCON0;
    
    unsigned int *tempFIFOINT;
    unsigned int *tempFIFOUA;
    unsigned int *tempFIFOCON;
    
    int channel;
    int count = 0;
    
    for(channel=0; channel<NUM_OF_CAN_TX_CHANNEL; channel++){
        tempFIFOINT = &(initFIFOINT[16*channel]);
        
//        if( ((*tempFIFOINT)>>10) & 0x00000001 == 1 ){  // if TXNFULLIF
        if( (((*tempFIFOINT) >> 10) & 0x1) == 1 ){
            tempFIFOUA = &(initFIFOUA[16*channel]);
            drv_Message1 = (CAN_TX_MSG_BUFFER*)PA_TO_KVA1(*tempFIFOUA);
            drv_Message1->msgSID.sid     = address;
            drv_Message1->msgEID.eid     = 0;
            drv_Message1->msgEID.ide     = 0; 
            
            if (DLC > 8) DLC = 8;
            
            drv_Message1->msgEID.data_length_code = DLC;
            while(count < DLC){
                drv_Message1->data[count++] = *message++;
            }

            //Update CAN module and then transmit data on the bus;
            tempFIFOCON = &(initFIFOCON[16*channel]);
            *tempFIFOCON = *tempFIFOCON | (1<<13);  // set UINC
            *tempFIFOCON = *tempFIFOCON | (1<<3);   // set TXREQ
            return true;
        }
    }
    return false;
}

char CAN_READ_1(uint32_t *address, uint8_t *message, uint8_t *length){
    static unsigned int *initFIFOINT = (unsigned int*)&C1FIFOINT0;
    static unsigned int *initFIFOUA  = (unsigned int*)&C1FIFOUA0;    
    static unsigned int *initFIFOCON = (unsigned int*)&C1FIFOCON0;
    
    unsigned int *tempFIFOINT;
    unsigned int *tempFIFOUA;
    unsigned int *tempFIFOCON;
    
    int channel = -1;
    int dlc = 0;
    CAN_RX_MSG_BUFFER *RxMessage = NULL;    
            
    int ch;
    for(ch=NUM_OF_CAN_TX_CHANNEL; ch<NUM_OF_CAN_TX_CHANNEL+NUM_OF_CAN_RX_CHANNEL; ch++){
        tempFIFOINT = &(initFIFOINT[16*ch]);
//        if( (*tempFIFOINT) & 0x00000001 == 1 ){  // if RXNEMPTYIF
            if( ((*tempFIFOINT) & 0x00000001) == 1 ){  // if RXNEMPTYIF
            channel = ch;
            break;
        }
    }
    
    if(channel < 0)
        return false;
    
    tempFIFOUA = &(initFIFOUA[16*channel]);
    RxMessage = (CAN_RX_MSG_BUFFER*)PA_TO_KVA1(*tempFIFOUA);
    
    if(RxMessage != NULL){
        if(RxMessage->msgEID.ide){ //EID Address
            *address = (RxMessage->msgSID.sid << 18);
            *address |= ((0x3FFFF)&(RxMessage->msgEID.eid));
        }else{
            *address = RxMessage->msgSID.sid; 
        }

        *length = RxMessage->msgEID.data_length_code;
        if(RxMessage->msgEID.data_length_code > 0){
            while(dlc < RxMessage->msgEID.data_length_code){ 
                 *message++ = RxMessage->data[dlc++];
            }
        }
        //Process the message received

        /* Call the PLIB_CAN_ChannelUpdate function to let
        the CAN module know that the message processing
        is done. */
        tempFIFOCON = &(initFIFOCON[16*channel]);
        *tempFIFOCON = *tempFIFOCON | (1<<13);  // set UINC
        
        return true;
    }
    return false;
}

char CAN_READ_2(uint32_t *address, uint8_t *message, uint8_t *length){
    static unsigned int *initFIFOINT = (unsigned int*)&C2FIFOINT0;
    static unsigned int *initFIFOUA  = (unsigned int*)&C2FIFOUA0;    
    static unsigned int *initFIFOCON = (unsigned int*)&C2FIFOCON0;
    
    unsigned int *tempFIFOINT;
    unsigned int *tempFIFOUA;
    unsigned int *tempFIFOCON;
    
    int channel = -1;
    int dlc = 0;
    CAN_RX_MSG_BUFFER *RxMessage = NULL;    
            
    int ch;
    for(ch=NUM_OF_CAN_TX_CHANNEL; ch<NUM_OF_CAN_TX_CHANNEL+NUM_OF_CAN_RX_CHANNEL; ch++){
        tempFIFOINT = &(initFIFOINT[16*ch]);
//        if( (*tempFIFOINT) & 0x00000001 == 1 ){  // if RXNEMPTYIF
            if( ((*tempFIFOINT) & 0x00000001) == 1 ){  // if RXNEMPTYIF
            channel = ch;
            break;
        }
    }
    
    if(channel < 0)
        return false;
    
    tempFIFOUA = &(initFIFOUA[16*channel]);
    RxMessage = (CAN_RX_MSG_BUFFER*)PA_TO_KVA1(*tempFIFOUA);
    
    if(RxMessage != NULL){
        if(RxMessage->msgEID.ide){ //EID Address
            *address = (RxMessage->msgSID.sid << 18);
            *address |= ((0x3FFFF)&(RxMessage->msgEID.eid));
        }else{
            *address = RxMessage->msgSID.sid; 
        }

        *length = RxMessage->msgEID.data_length_code;
        if(RxMessage->msgEID.data_length_code > 0){
            while(dlc < RxMessage->msgEID.data_length_code){ 
                 *message++ = RxMessage->data[dlc++];
            }
        }
        //Process the message received

        /* Call the PLIB_CAN_ChannelUpdate function to let
        the CAN module know that the message processing
        is done. */
        tempFIFOCON = &(initFIFOCON[16*channel]);
        *tempFIFOCON = *tempFIFOCON | (1<<13);  // set UINC
        
        return true;
    }
    return false;
}

void CAN_RECEIVE_CHANNEL_SET_1(int channel_num, uint32_t channel_size){
    unsigned int *ChannelRcvSetControlReg = (unsigned int*)&C1FIFOCON0;
    
    // Set the channel for receive
    //#define _C1FIFOCON0_TXEN_POSITION                0x00000007
    _SFR_BIT_CLEAR(&ChannelRcvSetControlReg[16 * channel_num], _C1FIFOCON0_TXEN_POSITION);
    
    //#define _C1FIFOCON0_DONLY_LENGTH                 0x00000001
    _SFR_BIT_CLEAR(&ChannelRcvSetControlReg[16 * channel_num], _C1FIFOCON0_DONLY_LENGTH);
    
    // write the FIFO size
    //#define _C1FIFOCON0_FSIZE_POSITION               0x00000010
    //#define _C1FIFOCON0_FSIZE_MASK                   0x001F0000
    _SFR_FIELD_WRITE(&ChannelRcvSetControlReg[16 * channel_num], _C1FIFOCON0_FSIZE_MASK, _C1FIFOCON0_FSIZE_POSITION, channel_size-1);
}

void CAN_RECEIVE_CHANNEL_SET_2(int channel_num, uint32_t channel_size){
    unsigned int *ChannelRcvSetControlReg = (unsigned int*)&C2FIFOCON0;
    
    // Set the channel for receive
    //#define _C1FIFOCON0_TXEN_POSITION                0x00000007
    _SFR_BIT_CLEAR(&ChannelRcvSetControlReg[16 * channel_num], _C2FIFOCON0_TXEN_POSITION);
    
    //#define _C1FIFOCON0_DONLY_LENGTH                 0x00000001
    _SFR_BIT_CLEAR(&ChannelRcvSetControlReg[16 * channel_num], _C2FIFOCON0_DONLY_LENGTH);
    
    // write the FIFO size
    //#define _C1FIFOCON0_FSIZE_POSITION               0x00000010
    //#define _C1FIFOCON0_FSIZE_MASK                   0x001F0000
    _SFR_FIELD_WRITE(&ChannelRcvSetControlReg[16 * channel_num], _C2FIFOCON0_FSIZE_MASK, _C2FIFOCON0_FSIZE_POSITION, channel_size-1);
}


void CAN_ENABLE_FILTER_1(int filter_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C1FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_FLTEN0_POSITION               0x00000007
    _SFR_BIT_SET(&filterControlReg[4 * regIndex], (_C1FLTCON0_FLTEN0_POSITION+(regOffset*8)));
}

void CAN_DISABLE_FILTER_1(int filter_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C1FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_FLTEN0_POSITION               0x00000007
    _SFR_BIT_CLEAR(&filterControlReg[4 * regIndex], (_C1FLTCON0_FLTEN0_POSITION+(regOffset*8)));
}

void CAN_ENABLE_FILTER_2(int filter_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C2FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_FLTEN0_POSITION               0x00000007
    _SFR_BIT_SET(&filterControlReg[4 * regIndex], (_C2FLTCON0_FLTEN0_POSITION+(regOffset*8)));
}


void CAN_DISABLE_FILTER_2(int filter_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C2FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_FLTEN0_POSITION               0x00000007
    _SFR_BIT_CLEAR(&filterControlReg[4 * regIndex], (_C2FLTCON0_FLTEN0_POSITION+(regOffset*8)));
}

void CAN_FILTER_MASK_CONFIG_1(int mask_num, uint32_t mask_bit)
{
    unsigned int *maskControlReg = (unsigned int*)&C1RXM0;
    
    //#define _C1RXM0_SID_POSITION                     0x00000015
    //#define _C1RXM0_SID_MASK                         0xFFE00000
    mask_bit &= 0x7FF;  //sid
    _SFR_FIELD_WRITE(&maskControlReg[4 * mask_num], _C1RXM0_SID_MASK, _C1RXM0_SID_POSITION, mask_bit);
    
    //#define _C1RXM1_MIDE_POSITION                    0x00000013
    _SFR_BIT_SET(&maskControlReg[4 * mask_num], _C1RXM1_MIDE_POSITION);
}

void CAN_FILTER_MASK_CONFIG_2(int mask_num, uint32_t mask_bit)
{
    unsigned int *maskControlReg = (unsigned int*)&C2RXM0;
    
    //#define _C1RXM0_SID_POSITION                     0x00000015
    //#define _C1RXM0_SID_MASK                         0xFFE00000
    mask_bit &= 0x7FF;  //sid
    _SFR_FIELD_WRITE(&maskControlReg[4 * mask_num], _C2RXM0_SID_MASK, _C2RXM0_SID_POSITION, mask_bit);
    
    //#define _C1RXM1_MIDE_POSITION                    0x00000013
    _SFR_BIT_SET(&maskControlReg[4 * mask_num], _C2RXM1_MIDE_POSITION);
}

void CAN_FILTER_CONFIG_1(int filter_num, uint32_t id)
{
    unsigned int *filterControlReg = (unsigned int*)&C1RXF0;
    id &= 0x7FF;    //sid
    
    //#define _C1RXF0_SID_POSITION                     0x00000015
    //#define _C1RXF0_SID_MASK                         0xFFE00000
    _SFR_FIELD_WRITE(&filterControlReg[4 * filter_num], _C1RXF0_SID_MASK, _C1RXF0_SID_POSITION, id );
    
    //#define _C1RXF0_EXID_POSITION                    0x00000013
    _SFR_BIT_CLEAR(&filterControlReg[4 * filter_num], _C1RXF0_EXID_POSITION);
}

void CAN_FILTER_CONFIG_2(int filter_num, uint32_t id)
{
    unsigned int *filterControlReg = (unsigned int*)&C2RXF0;
    id &= 0x7FF;    //sid
    
    //#define _C1RXF0_SID_POSITION                     0x00000015
    //#define _C1RXF0_SID_MASK                         0xFFE00000
    _SFR_FIELD_WRITE(&filterControlReg[4 * filter_num], _C2RXF0_SID_MASK, _C2RXF0_SID_POSITION, id );
    
    //#define _C1RXF0_EXID_POSITION                    0x00000013
    _SFR_BIT_CLEAR(&filterControlReg[4 * filter_num], _C2RXF0_EXID_POSITION);
}

void CAN_FILTER_2_CHANNEL_LINK_1(int filter_num, int mask_num, int channel_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C1FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_MSEL0_POSITION                0x00000005
    //#define _C1FLTCON0_MSEL0_MASK                    0x00000060
    _SFR_FIELD_WRITE(&filterControlReg[regIndex*4], (_C1FLTCON0_MSEL0_MASK<<(regOffset*8)), (_C1FLTCON0_MSEL0_POSITION+(regOffset*8)), mask_num);
    
    //#define _C1FLTCON0_FSEL0_POSITION                0x00000000
    //#define _C1FLTCON0_FSEL0_MASK                    0x0000001F
    _SFR_FIELD_WRITE(&filterControlReg[regIndex*4], (_C1FLTCON0_FSEL0_MASK<<(regOffset*8)), (_C1FLTCON0_FSEL0_POSITION+(regOffset*8)), channel_num);
}

void CAN_FILTER_2_CHANNEL_LINK_2(int filter_num, int mask_num, int channel_num)
{
    unsigned int *filterControlReg = (unsigned int*)&C2FLTCON0;
    int regIndex = filter_num/4;
    int regOffset = filter_num%4;
    
    //#define _C1FLTCON0_MSEL0_POSITION                0x00000005
    //#define _C1FLTCON0_MSEL0_MASK                    0x00000060
    _SFR_FIELD_WRITE(&filterControlReg[regIndex*4], (_C2FLTCON0_MSEL0_MASK<<(regOffset*8)), (_C2FLTCON0_MSEL0_POSITION+(regOffset*8)), mask_num);
    
    //#define _C1FLTCON0_FSEL0_POSITION                0x00000000
    //#define _C1FLTCON0_FSEL0_MASK                    0x0000001F
    _SFR_FIELD_WRITE(&filterControlReg[regIndex*4], (_C2FLTCON0_FSEL0_MASK<<(regOffset*8)), (_C2FLTCON0_FSEL0_POSITION+(regOffset*8)), channel_num);
}



