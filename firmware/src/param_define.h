#ifndef PARAM_DEFINE_H
#define PARAM_DEFINE_H

//#define SEM

#define TIME_CONSTANT_10MS 10 // 10ms

#define OSSD_DELAY_PARAM_SET 0x01
#define OSSD_RECOVERY_PARAM_SET 0x02
#define EWELLIX_INTERLOCK_PIN_SET_1 0x03
#define EWELLIX_INTERLOCK_PIN_SET_2 0x04
#define COBOT_INTERLOCK_PIN_SET_1 0x05
#define COBOT_INTERLOCK_PIN_SET_2 0x06

#define USE_SAFETY_CROSS_MONITORING_SET 0x07
#define USE_SAFETY_SPEED_CONTROL_SET 0x08
#define USE_SAFETY_OBSTACLE_DETECTION_SET 0x09
#define USE_SAFETY_BUMPER_SET 0x0A
#define USE_SAFETY_INTERLOCK_SET 0x0B

// for safety parameter
extern unsigned int SS1_STOP_TIME;
extern unsigned int SS2_STOP_TIME;

// for safety use parameter
extern unsigned char USE_SAFETY_CROSS_MONITORING;
extern unsigned char USE_SAFETY_SPEED_CONTROL;
extern unsigned char USE_SAFETY_OBSTACLE_DETECTION;
extern unsigned char USE_SAFETY_BUMPER;
extern unsigned char USE_SAFETY_INTERLOCK;


// obstacle_detection parameter
extern void ParamSet_Ossd_Delay_ms(float);
extern float ossd_delay_ms;

extern void ParamSet_Ossd_Recovery_ms(float);
extern float ossd_recovery_ms;

// for safety logic
extern void ParamSet_USE_SAFETY_CROSS_MONITORING(unsigned char param);
extern void ParamSet_USE_SAFETY_SPEED_CONTROL(unsigned char param);
extern void ParamSet_USE_SAFETY_OBSTACLE_DETECTION(unsigned char param);
extern void ParamSet_USE_SAFETY_BUMPER(unsigned char param);
extern void ParamSet_USE_SAFETY_INTERLOCK(unsigned char param);


// for safety io 
extern unsigned char USE_COBOT_SSS;
extern unsigned char USE_COBOT_SS2;
extern unsigned char cobot_sss_io_pin[2];
extern unsigned char cobot_ss2_io_pin[2];
extern unsigned char cobot_interlock_io_pin[2];
extern unsigned char cobot_ss2_field_num[2];

#ifdef SEM
extern void ParamSet_EWELLIX_INTERLOCK_PIN_1(unsigned char param);
unsigned char EWELLIX_INTERLOCK_IN_1 = 0;

extern void ParamSet_EWELLIX_INTERLOCK_PIN_2(unsigned char param);
unsigned char EWELLIX_INTERLOCK_IN_2 = 1;

extern void ParamSetCOBOT_INTERLOCK_PIN_1(unsigned char param);
unsigned char COBOT_INTERLOCK_IN_1 = 2;

extern void ParamSetCOBOT_INTERLOCK_PIN_2(unsigned char param);
unsigned char COBOT_INTERLOCK_IN_2 = 4;

float INTERLOCK_MOTOR_DPS_LIMIT = 1;
#endif


#endif
