#ifndef FUNCTION_TASK_H
#define FUNCTION_TASK_H

#include "system_general_configuration.h"

//SafetyStopInfoMessage
typedef enum{
    AMR_STO_MESSAGE_NUM =1,
    AMR_SS1_MEESAGE_NUM,
    AMR_SS2_MESSAGE_NUM,
    COBOT_SS2_MESSAGE_NUM,
    EWELLIX_STO_MESSAGE_NUM
}EN_SAFETY_INFO_MEESAGE;


// Operation Mode 
typedef enum{
    SM_OM_POWER_OFF = 0,
    SM_OM_MAIN_POWER_UP, //1
    SM_OM_PC_POWER_UP, //2
    SM_OM_ROBOT_POWER_OFF, //3
    SM_OM_ROBOT_INITIALIZE, //4
    SM_OM_NORMAL_OP, //5
    SM_OM_NORMAL_OP_AUTO, //6
    SM_OM_NORMAL_OP_MANUAL, //7
    SM_OM_NORMAL_LOW_BAT, //8
    SM_OM_OPERATIONAL_STOP, //9
    SM_OM_CHARGING, //10
    SM_OM_CONFIGURATION //11
}EN_STATE_MACHINE_OM_MODE;

// Robot Initializing Process
typedef enum{
    RI_IDLE = 0,
    RI_SAFETY_CHECK,
    RI_POWER_ON,
    RI_POWER_CHECK,
    RI_MOTOR_INIT,
    RI_MOTOR_CHECK,
    RI_DONE,
    RI_FAIL
}EN_ROBOT_INIT_STATE;

// Charging Process
typedef enum{
    CHARGE_IDLE = 0,
    CHARGE_BATTERY_ON,
    CHARGE_CHARGING,
    CHARGE_TRIG_TO_STOP_CHARGE,
    CHARGE_FAIL
}EN_CHARGE_STATE;


void    Task_ADC_Measure(void);
void    Task_Lidar_Handler(void);
void    Task_Power_Handler(void);

void    Task_Control_FET_On(void);
void    Task_Control_FET_Off(void);
void    Task_Control_Lift_FET_On(void);
void    Task_Control_Lift_FET_Off(void);

// SF RESET IO DETECTION FUNCTION
void Task_SF_RESET_IO_Detection(void);

// SF DETECTION FUNCTION
void Task_SF_EMO_Detection(void);
void Task_SF_SpeedControl_Detection(void);
void Task_SF_Obstacle_Detection(void);
void Task_SF_Cross_Monitoring_Detection(void);
void Task_SF_BUMPER_Detection(void);

// SF STOP SIGNAL GENERATION FUNCTION
void Stop_Signal_Generation(void);

// SF STOP FUNCTION
void Task_SF_STO(void);
void Task_SF_SS1(void);
void Task_SF_SS2(void);

void Task_SF_ChannelCheck(void);

void Task_SF_COBOT_PRS(void);
void Task_SF_COBOT_SS2(void);
void Task_SF_COBOT_SS2_RECOVERY(void);
void Task_SF_COBOT_SSS_RECOVERY(void);
#ifdef SEM
void Task_SF_EWELLIX_STO(void);
#endif

void SolenoidControl(int target, int mode);
void SafetyStop(int mode, int time_10ms);
unsigned char getBumperSwitch(void);
#endif
