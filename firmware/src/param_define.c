#include "param_define.h"


// for safety parameter
unsigned int SS1_STOP_TIME = 10; // 10ms
unsigned int SS2_STOP_TIME = 100; // 100ms

// for use safety parameter 
unsigned char USE_SAFETY_CROSS_MONITORING = 0;
unsigned char USE_SAFETY_SPEED_CONTROL = 0;
unsigned char USE_SAFETY_OBSTACLE_DETECTION = 0;
unsigned char USE_SAFETY_BUMPER = 1;
unsigned char USE_SAFETY_INTERLOCK = 0;

// for safety io 0~7 mcu1 , 8~15 mcu0
unsigned char USE_COBOT_SSS = 1;
unsigned char USE_COBOT_SS2 = 1;
unsigned char cobot_sss_io_pin[2] = {0, 8};
unsigned char cobot_ss2_io_pin[2] = {6, 14};
unsigned char cobot_interlock_io_pin[2] = {7, 15};
unsigned char cobot_ss2_field_num[2] = {0, 63}; // 0~63

// obstacle_detection parameter
float ossd_delay_ms = 150.0; // 0.15s
float ossd_recovery_ms = 250.0; // 0.25s





// for use safety logic parameter set function
void ParamSet_USE_SAFETY_CROSS_MONITORING(unsigned char param)
{
    USE_SAFETY_CROSS_MONITORING = param;
}

void ParamSet_USE_SAFETY_SPEED_CONTROL(unsigned char param)
{
    USE_SAFETY_SPEED_CONTROL = param;
}

void ParamSet_USE_SAFETY_OBSTACLE_DETECTION(unsigned char param)
{
    unsigned char data[1];
    data[0] = 0xEE;
     CAN_WRITE_2(0x202, 4, data);
    USE_SAFETY_OBSTACLE_DETECTION = param;
}

void ParamSet_USE_SAFETY_BUMPER(unsigned char param)
{
    USE_SAFETY_BUMPER = param;
}

void ParamSet_USE_SAFETY_INTERLOCK(unsigned char param)
{
    USE_SAFETY_INTERLOCK = param;
}

// ossd parameter set functon
void ParamSet_Ossd_Delay_ms(float param)
{
    ossd_delay_ms = param;
}

void ParamSet_Ossd_Recovery_ms(float param)
{
    ossd_recovery_ms = param;
}

#ifdef SEM
void ParamSet_EWELLIX_INTERLOCK_PIN_1(unsigned char param)
{
    EWELLIX_INTERLOCK_IN_1 = param;
}

void ParamSet_EWELLIX_INTERLOCK_PIN_2(unsigned char param)
{
    EWELLIX_INTERLOCK_IN_2 = param;
}

void ParamSetCOBOT_INTERLOCK_PIN_1(unsigned char param)
{
    COBOT_INTERLOCK_IN_1 = param;
}

void ParamSetCOBOT_INTERLOCK_PIN_2(unsigned char param)
{
    COBOT_INTERLOCK_IN_1 = param;
}
#endif