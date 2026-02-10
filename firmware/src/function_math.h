#ifndef FUNCTION_MATH_H
#define FUNCTION_MATH_H

inline void             Change_PMode(unsigned char mode);

inline void             Switch_FET(unsigned char onoff);

inline void             Do_Reset(unsigned char opt);

inline int              MCU_Self_Test(void);

float                   Calculate_Digit2Temperature(int digit);

#endif