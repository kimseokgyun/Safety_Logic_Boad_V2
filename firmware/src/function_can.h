#ifndef FUNCTION_CAN_H
#define FUNCTION_CAN_H

//#include "../sys/types.h"
#include <peripheral/peripheral.h>
#include <sys/types.h>
#include "param_define.h"
//typedef volatile uint32_t SFR_TYPE;
//
//#define _SFR_BIT_READ(reg,pos)       (  ( ( *((SFR_TYPE *)(reg)) )&(1<<(pos)) ) ? 1 : 0  )
//#define _SFR_BIT_WRITE(reg,pos,val)  (  *((SFR_TYPE *)(reg)) = ( ( *((SFR_TYPE *)(reg)) ) & ~(1<<(pos)) ) | (0x1&(val))<<(pos)  )
//#define _SFR_BIT_SET(reg,pos)        ( *((SFR_TYPE *)(reg)) |=  1<<(pos) )
//#define _SFR_BIT_CLEAR(reg,pos)      ( *((SFR_TYPE *)(reg)) &= ~(1<<(pos)) )
//#define _SFR_BIT_INVERT(reg,pos)     ( *((SFR_TYPE *)(reg)) ^=  1<<(pos) )
//
//#define _SFR_FIELD_READ(reg,mask,pos)       (  ( *((SFR_TYPE *)(reg))&(mask) ) >> (pos)  )
//#define _SFR_FIELD_WRITE(reg,mask,pos,val)  \
//    (  *((SFR_TYPE *)(reg)) = \
//        ( (*((SFR_TYPE *)(reg))) & ~(mask) ) | ( (mask)&((val)<<(pos)) )  )
//#define _SFR_FIELD_SET(reg,mask,pos,val)    (  *((SFR_TYPE *)(reg)) |=   ( (mask)&((val)<<(pos)) )  )
//#define _SFR_FIELD_CLEAR(reg,mask,pos,val)  (  *((SFR_TYPE *)(reg)) &=  ~( (mask)&((val)<<(pos)) )  )
//#define _SFR_FIELD_INVERT(reg,mask,pos,val) (  *((SFR_TYPE *)(reg)) ^=   ( (mask)&((val)<<(pos)) )  )
//
//#define _SFR_READ(reg)       ( *((SFR_TYPE *)(reg)) )
//#define _SFR_WRITE(reg,val)  ( *((SFR_TYPE *)(reg))  =  (val) )


//typedef struct{
//    /* CAN Transmit Message Standard ID. This value should be between
//    0x0 - 0x7FF */
//    unsigned sid:11;
//    unsigned :21;
//}CAN_TX_MSG_SID;


//typedef struct{
//    /* Data Length Control. Specifies the size of the data payload section of
//    the CAN packet. Valid values are 0x0 - 0x8 */
//    unsigned data_length_code:4;
//
//    /* Reserved bit. Should be always 0. */
//    unsigned reserved0:1;
//
//    /* Unimplemented bit. Should be always 0. */
//    unsigned unimplemented1:3;
//
//    /* Reserved bit. Should be always 0. */
//    unsigned reserved1:1;
//
//    /* Remote Transmit Request bit. Should be set for RTR messages, clear
//    otherwise.*/
//    unsigned remote_request:1;
//
//    /* CAN Transmit and Receive Extended ID field. Valid values are in range
//    0x0 - 0x3FFFF */
//    unsigned eid:18;
//
//    /* Identifier bit. If 0 means that message is SID. If 1 means
//    that message is EID type.*/
//    unsigned ide:1;
//
//    /* Substitute Remote request bit. This bit should always be clear for an
//    EID message. It is ignored for an SID message.*/
//    unsigned sub_remote_req:1;
//
//    /* Unimplemented bit. Should be always 0. */
//    unsigned unimplemented2:2;
//}CAN_MSG_EID;
//
//
//
//typedef union{
//    struct{
//        /* This is SID portion of the CAN Transmit message */
//        CAN_TX_MSG_SID msgSID;
//
//        /* This is EID portion of the CAN Transmit message */
//        CAN_MSG_EID msgEID;
//
//        /* This is the data portion of the CAN Transmit message */
//        unsigned char data[8];
//    };
//
//    /* This is CAN Transmit message organized as a set of 32 bit words */
//    uint32_t messageWord[4];
//}CAN_TX_MSG_BUFFER;
//
//
//typedef	struct{
//    /* SID of the Received CAN Message */
//	unsigned sid:11;
//
//    /* Filter which accepted this message */
//	unsigned filter_hit:5;
//
//    /* Time stamp of the received message. This is valid only if the
//    Timestamping is enabled */
//	unsigned msg_timestamp:16;
//}CAN_RX_MSG_SID;



//typedef union{
//	struct{
//        /* This is SID portion of the CAN Receive message */
//		CAN_RX_MSG_SID msgSID;
//
//        /* This is EID portion of the CAN Receive message */
//		CAN_MSG_EID msgEID;
//
//        /* This is the data payload section of the received message */
//		uint8_t data[8];
//	};
//
//    /* This can be used if the message buffer is to
//    be read from a Data-Only type of CAN Receive Channel */
//    uint8_t dataOnlyMsgData[8];
//
//    /* This is CAN Receive message organized as a set of 32-bit words */
//    uint32_t messageWord[4];
//}CAN_RX_MSG_BUFFER;


//extern CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer0[4*4 + 4*4 + 4*4 + 4*4];
//extern CAN_TX_MSG_BUFFER  *drv_Message0;
//extern CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer1[4*4 + 4*4 + 4*4 + 4*4];
//extern CAN_TX_MSG_BUFFER  *drv_Message1;

extern CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer0[16*4];
extern CAN_TX_MSG_BUFFER  *drv_Message0;
extern CAN_TX_MSG_BUFFER __attribute__((coherent, aligned(16))) can_message_buffer1[16*4];
extern CAN_TX_MSG_BUFFER  *drv_Message1;

inline void CAN_TX_SAFETY_ISSUE(unsigned char PMODE_type);

void CAN_PARSER_2(uint32_t id, uint8_t data[], uint8_t dlc, uint8_t chnum);
void CAN_PARSER_1(uint32_t id, uint8_t data[], uint8_t dlc, uint8_t chnum);


char CAN_WRITE_1(int address, uint8_t DLC, uint8_t *message);
char CAN_WRITE_2(int address, uint8_t DLC, uint8_t *message);

char CAN_READ_1(uint32_t *address, uint8_t *message, uint8_t *length);
char CAN_READ_2(uint32_t *address, uint8_t *message, uint8_t *length);

void CAN_RECEIVE_CHANNEL_SET_1(int channel_num, uint32_t channel_size);
void CAN_RECEIVE_CHANNEL_SET_2(int channel_num, uint32_t channel_size);

void CAN_ENABLE_FILTER_1(int filter_num);
void CAN_DISABLE_FILTER_1(int filter_num);

void CAN_ENABLE_FILTER_2(int filter_num);
void CAN_DISABLE_FILTER_2(int filter_num);

void CAN_FILTER_MASK_CONFIG_1(int mask_num, uint32_t mask_bit);
void CAN_FILTER_MASK_CONFIG_2(int mask_num, uint32_t mask_bit);

void CAN_FILTER_CONFIG_1(int filter_num, uint32_t id);
void CAN_FILTER_CONFIG_2(int filter_num, uint32_t id);

void CAN_FILTER_2_CHANNEL_LINK_1(int filter_num, int mask_num, int channel_num);
void CAN_FILTER_2_CHANNEL_LINK_2(int filter_num, int mask_num, int channel_num);

#endif

