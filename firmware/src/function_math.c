#include "system_general_configuration.h"

/*****************************************************************************
 * Change Power Mode
 * Input : mode number
 * Return : void
 *****************************************************************************/
inline void Change_PMode(unsigned char mode){
    CAN_TX_SAFETY_ISSUE(mode);
}

/*****************************************************************************
 * Change FET output
 * Input : mode number
 * Return : void
 *****************************************************************************/
inline void Switch_FET(unsigned char onoff){
    ;
}


inline int MCU_Self_Test(void){
    ;
}