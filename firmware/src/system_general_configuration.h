#ifndef SYSTEM_GENERAL_CONFIGURATION_H
#define SYSTEM_GENERAL_CONFIGURATION_H

//#define  CAN_SPEED_500HZ
/*******************************************************************************
 * Common System Headers
 ******************************************************************************/
#include "system_pin_map.h"
#include "param_define.h"
#include <xc.h>
#include <sys/kmem.h>
#include <sys/attribs.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

#include <string.h>
#include <math.h>

//#define DEFAULT

extern unsigned int SF_MCU_NUM;  // 0 or 1
extern unsigned int test_constant;
extern unsigned int obstacle_detect_mode; 

//volatile struct  ClassB_Test_Flags {
//    unsigned cpuRegister_TestResult : 1;
//    unsigned programCounter_TestResult:1;
//    unsigned checkerboardRam_TestResult:1;
//    unsigned marchCRam_TestResult:1;
//    unsigned marchCMinusRam_TestResult:1;
//    unsigned marchCRamStack_TestResult:1;
//    unsigned marchBRam_TestResult:1;
//    unsigned flash_TestResult:1;
//    unsigned clock_TestResult:1;
//    unsigned clockLine_TestResult:1;
//} testFlag;

/*******************************************************************************
 * Common Constants
 ******************************************************************************/
#define             FIRMWARE_NUMBER         15
// SF-3-FIRMWARE_NUMBER
// 10 : 2020.12.04
// 11 : 2021.01.28
// 12 : 2021.03.31
// 13 : 2021.04.06 because of STS board current R value 3mohm - >5
// 14 : 2022.06.14 add CAN Baud Rate Code
// 15 : 2022.10.05 ..modi221005 slow on ....STO check -> STO or FET out
//    :            .. when turn on slow-on .... add time condition 10 count (about 100 msec)
#define             MAX_MC                  4

#define             JOINT_NUMBER            6
#define             SAFETY_COUNT_NUM        256
#define             SAFETY_DATA_DLC         7
#define             MCU_0                   0
#define             MCU_1                   1

#define             SYSFREQ                 200000000
#define             PBCLK                   100000000

#define             FALSE                   0
#define             TRUE                    1
#define             OUTPUT                  0
#define             INPUT                   1
#define             LOW                     0
#define             HIGH                    1
#define             DIGITAL                 0
#define             ANALOG                  1
#define             TURN_OFF                0
#define             TURN_ON                 1

#define             TYPE_INT                0
#define             TYPE_FLOAT              1

#define             STU_CHECK_CNT           100//1
#define             MEM_CHECK_CNT           100//2
#define             FRM_CHECK_CNT           100//5

#define             DATA_WRITE              0
#define             DATA_READ               1
#define             DATA_READ_ID            2
#define             DATA_STUCK              44

#define             FORCE_RESET             3
#define             FORCE_PMODE             4
#define             FORCE_SWITCH            5
#define             FORCE_STATUS            6
#define             FORCE_COUNT             7
#define             FORCE_SLEEP             8
#define             FORCE_FLAG              9
#define             FORCE_STUCK             44
#define             FORCE_MEM               55
#define             FORCE_CAN               66

#define             CAN_ID_SF_MCU_1_CMD     0x407
#define             CAN_ID_SF_MCU_2_CMD     0x417
#define             CAN_ID_SF_MCU_1_RET     0x3F7
#define             CAN_ID_SF_MCU_2_RET     0x3FB

static float        PI      = 3.141592653589793;
static float        D2R     = 0.017453292519943;
static float        R2D     = 57.295779513082323;




/*******************************************************************************
 * ENUM Variable
 ******************************************************************************/

typedef enum{
    SAFETY_MODE_NORMAL = 0,
    SAFETY_MODE_STO, //1
    SAFETY_MODE_SS1, //2
    SAFETY_MODE_SS2, //3
}EN_SAFETY_MODE;


typedef enum{
    REMOTE_FLAG_OFF_STATE = 0,
    REMOTE_FLAG_ON_STATE,
    REMOTE_FLAG_ON_ACTION,
    REMOTE_FLAG_OFF_ACTION
}EN_REMOTE_FLAG;

typedef enum{
    POWER_STATE_OFF = 0,
    POWER_STATE_PRE_WAIT,
    POWER_STATE_PRE_ON,
    POWER_STATE_MAIN_ON,
    POWER_STATE_PRE_OFF,
    POWER_STATE_ON
}EN_POWER_STATE;





enum POWER_MODE_NUMBER{
    PMODE_NON = 0,
    PMODE_STO,
    PMODE_SS1,
    PMODE_SS2,
    PMODE_SOS,
};

enum SW_SELECTION_NUMBER{
    SW_MODE_DUMMY = 0,
    SW_MODE_STO,
    SW_MODE_SS1,
    SW_MODE_SS2,
};

enum SF_SETTING_LIST{
    SFSET_NONE = 0,
    SFSET_BOUND_SLP_UP_J0,
    SFSET_BOUND_SLP_UP_J1,
    SFSET_SW_ROLE,
    SFSET_NUMBER
};


extern int                 SF_Settings[SFSET_NUMBER];
extern int                 SF_Settings_Background[SFSET_NUMBER];

/*******************************************************************************
 * Speed Data Structure
 ******************************************************************************/
typedef struct{
    unsigned short  raw_bytes_white[SAFETY_COUNT_NUM][SAFETY_DATA_DLC];
    unsigned short  raw_bytes_black[SAFETY_COUNT_NUM][SAFETY_DATA_DLC];
    
    short           white_count_old;
    short           black_count_old;
    
    unsigned int    cycle_time_cnt;
    unsigned int    count_fail_cnt_white; //data loss check
    unsigned int    count_fail_cnt_black; //data loss check
    
    unsigned int    white_black_mimatch_cnt; // inverting data check
    
}SPEED_SAFETY_RAW_STRUCT;

typedef struct{
    float           ref_speed_in_pps[MAX_MC];
    float           ref_speed_in_dps_output[MAX_MC];
    float           meas_speed_in_pps[MAX_MC];
    float           meas_speed_in_dps_output[MAX_MC];
    
    int             mismatch_cnt[MAX_MC];
    unsigned int    meas_active_cnt[MAX_MC];
    unsigned int    ref_active_cnt[MAX_MC];
    
    int             ovrspd_cnt;
}SPEED_SAFETY_SPEED_STRUCT;

typedef struct{
    SPEED_SAFETY_SPEED_STRUCT   safety_speed;
    SPEED_SAFETY_RAW_STRUCT     safety_raw[MAX_MC];
}SPEED_STRUCTURE;

/*******************************************************************************
 * Safety MCU Data Structure
 ******************************************************************************/
typedef union{
    unsigned char           raw;
    struct{
        unsigned char       line_A_val : 6;
        unsigned char       in_V_stat : 1;
        unsigned char       out_V_stat : 1;
    };
}UART_TX_STRUCTURE;

typedef union{
    unsigned char           raw;
    struct{
        unsigned char       dummy : 2;
        unsigned char       is_PC_sf_on : 1;
        unsigned char       is_PC_ref_onf : 1;
        unsigned char       is_PC_teaching : 1;
        unsigned char       is_PC_coll_detect : 1;
        unsigned char       is_PC_prog_run : 1;
        unsigned char       is_PC_find_home : 1;
    };
}UART_RX_STRUCTURE;

typedef union{
    unsigned int            raw;
    struct{
        unsigned char       on_dummy1 : 3;
        unsigned char       on_SLP : 1;
        unsigned char       on_SLS : 1;
        unsigned char       on_SLA : 1;
        unsigned char       on_SLI : 1;
        unsigned char       on_SLT : 1;
        
        unsigned char       on_TPL : 1;
        unsigned char       on_TSL : 1;
        unsigned char       on_CBP : 1;
        unsigned char       on_EM1 : 1;
        unsigned char       on_EM2 : 1;
        unsigned char       on_PRS : 1;
        unsigned char       on_HSS : 1;
        unsigned char       on_SSS : 1;
        
        unsigned char       on_ECI : 1;
        unsigned char       on_ECC : 1;
        unsigned char       on_ECT : 1;
        unsigned char       on_SWE : 1;
        unsigned char       on_TMP : 1;
        unsigned char       on_MEM : 1;
        unsigned char       on_FRM : 1;
        
        unsigned short      on_dummy2 : 9;
    };
}SAFETY_ONOFF_STRUCTURE;

typedef union{
    unsigned int            raw;
    struct{
        unsigned char       is_emo_press_detected : 1;
        unsigned char       is_ref_spd_mismatch_detected : 1;
        unsigned char       is_ovr_spd_detected : 1;
        unsigned char       is_obs_detected : 1;
        unsigned char       is_spd_field_mismatch_detected : 1;
        unsigned char       is_in_op_stop_state : 1;
        unsigned char       is_bumper_press_detected :1;
        unsigned char       is_interlock_detected :1;
//        unsigned char       dummy : 2;
        
        unsigned char       DUMMY1 : 8;
        unsigned char       DUMMY2 : 8;
        unsigned char       DUMMY3 : 8;
    };
}STATUS_STRUCTURE;


typedef struct{
    unsigned char           btn_reset;
    
    float                   adc_inlet_voltage;  // V
    float                   adc_outlet_voltage; // V
    float                   adc_current_line;   // A
    
    float                   adc_inlet_voltage_lift;  // V
    float                   adc_outlet_voltage_lift; // V
    float                   adc_current_line_lift;   // A
    
    unsigned char           emo_pressed;
    
    unsigned char           field_selection[6];
    unsigned char           ossd_detected[2];
    unsigned int            field_num;
    
    // ---------------------------------------------------    
    
    unsigned int        field_fail_cnt[6];
    unsigned char       field_valid[6];
    
    unsigned char           ossd_front_triggered;
    unsigned char           ossd_rear_triggered;    
    unsigned int            ossd_front_counter;
    unsigned int            ossd_rear_counter;
}SENSOR_STRUCTURE;




typedef struct{
    bool                    stuck_flag;
    bool                    xfrm_flag;
    unsigned char           xcan_flag;
}SYS_STRUCTURE;

typedef struct{
    unsigned char   robot_type;         // 0:DD, 1:QD(Mecanum)
    float           wheel_radius;       // mm
    float           wheel_saparation;   // mm
    float           gear_ratio; 
    float           dir;
    
    // speed limit
    float           max_linear_speed;
    float           max_rotation_speed;
    float           monitoring_linear_speed;
    float           monitoring_rotation_speed;
    
    // for mecanum
    float           lx;
    float           ly;
}ROBOT_STRUCTURE;

typedef struct{
    unsigned char   pc_connected;   // 1: communication with pc program
    unsigned char   btn_brake_release;
    unsigned char   btn_mode;
    
    // state
    unsigned char   sm_om_state;
    unsigned char   ri_state;
    unsigned char   charge_state;
    
    
    // command
    unsigned char   cmd_power_on;
    unsigned char   cmd_power_off;
    unsigned char   cmd_lift_power_on;
    unsigned char   cmd_lift_power_off;
    unsigned char   cmd_recover_op_stop_state;
}COMM_BOARD_STRUCTURE;


typedef struct{
    // command
    unsigned char   cmd_power_off;
    
    unsigned char   cmd_sto;
    unsigned char   cmd_ss1;
    unsigned char   cmd_ss2;
    
    unsigned char   cmd_ewellix_sto;
    unsigned char   cmd_cobot_ss2;
    unsigned char   cmd_cobot_sss;
    unsigned char   cmd_recovery_cobot_sss;
    unsigned char   prs_state;
    
    unsigned char   operational_stop_state_flag;
    
    unsigned int    stop_count_ss1;
    unsigned int    stop_count_ss2;
    
    
    unsigned char   safety_state_emo_pressed;                   // CAT 0 (STO)
    unsigned char   safety_state_ref_speed_mismatch_detected;   // CAT 2 (SS2)
    unsigned char   safety_state_over_speed_detected;           // CAT 1 (SS1)
    unsigned char   safety_state_obstacle_detected;             // CAT 2 (SS2)
    unsigned char   safety_state_speed_field_mismatch_detected; // CAT 2 (SS2)
    unsigned char   safety_state_interlock_stop_detected;
    unsigned char   safety_state_bumper_stop_detected;
    //    unsigned char   safety_state_over_speed_at_muting_detected; // CAT 1 (SS1)  -- Forced Muting & Manual Mode

    unsigned char   prev_safety_state_emo_pressed;                   // CAT 0 (STO)
    unsigned char   prev_safety_state_ref_speed_mismatch_detected;   // CAT 2 (SS2)
    unsigned char   prev_safety_state_over_speed_detected;           // CAT 1 (SS1)
    unsigned char   prev_safety_state_obstacle_detected;             // CAT 2 (SS2)
    unsigned char   prev_safety_state_speed_field_mismatch_detected; // CAT 2 (SS2)
    unsigned char   prev_safety_state_interlock_stop_detected;
    unsigned char   prev_safety_state_bumper_stop_detected;
}SAFETY_RESULT_STRUCTURE;


typedef struct{
    unsigned char init_din_success;
    unsigned char init_dout_success;
    
    unsigned char dout[16];
    unsigned char din[16];
    
    unsigned char sw_reset;
    unsigned char sw_stop;
    unsigned char sw_start;
    
    
    unsigned char is_there_err_occur[4];
    
    
    unsigned char dout_for_cobot_ss2;
    unsigned char dout_for_cobot_prs;
    unsigned char dout_for_torso_sto;
}IO_STRUCTURE;

typedef struct{
    unsigned char           type;
    ROBOT_STRUCTURE         robot_info;
    COMM_BOARD_STRUCTURE    comm_info;
    
    SPEED_STRUCTURE         speed_info;
    
    SAFETY_RESULT_STRUCTURE safety_result;
    
    STATUS_STRUCTURE        status_now;
    STATUS_STRUCTURE        status_old;
    
    SENSOR_STRUCTURE        sensor;
    
//    UART_TX_STRUCTURE       uart;
//    UART_RX_STRUCTURE       pcstate;
    SAFETY_ONOFF_STRUCTURE  sfonoff;
    SYS_STRUCTURE           sys;
    
    IO_STRUCTURE            io;
}BOARD_STRUCTURE;

typedef struct{
    STATUS_STRUCTURE        status_now;
    STATUS_STRUCTURE        status_old;
}FRIEND_STRUCTURE;

extern FRIEND_STRUCTURE _fboard;       // friend board status
extern BOARD_STRUCTURE _mboard;        // my board status

/*******************************************************************************
 * Global variables
 ******************************************************************************/

/*******************************************************************************
 * Common Function Headers
 ******************************************************************************/
#include "function_initialization.h"
#include "function_task.h"
#include "function_can.h"
#include "function_spi.h"
#include "function_math.h"



#endif