#pragma once
/******************************************************************************/
/* File   : CfgEcuabCanIf.hpp                                                 */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Types_EcuabCanIf.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CANIF_CFG_NUM_CANRXPDUIDS                                              1
#define CANIF_TOTAL_CTRLS                                                      1
#define USER                                                                   1

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef uint8* Type_CtrlIdTable_Ptr;
typedef uint8* Type_TxPduIdTable_Ptr;
typedef uint8  CanIf_RxCbk_Prototype;
typedef uint8  Type_CtrlCanCtrlRef;

typedef struct{
   uint32 RxPduCanId;
   uint32 RxPduTargetId_t;
   uint8  IndexForUL_u8;
}CanIf_Cfg_RxPduType_tst;

typedef struct{
   uint32 TxPduId;
   uint32 TxPduCanId;
   uint32 TxPduCanIdType;
   uint32 TxPduTargetPduId;
   uint8  TxPduTxUserUL;
}CanIf_Cfg_TxPduConfig_tst;

typedef struct{
   void (*User_ControllerBusOff)(
         VAR(uint8,                            AUTOMATIC) ControllerId
   );
   void (*User_ControllerModeIndication)(
         VAR(uint8,                            AUTOMATIC) ControllerId
      ,  VAR(Type_EcuabCanIf_eModesController, AUTOMATIC) ControllerMode
   );
}CanIf_CallbackFuncType;

typedef struct{
   Type_CtrlCanCtrlRef CtrlCanCtrlRef;
}CanIf_Cfg_CtrlConfig_tst;

typedef struct{
   Type_CtrlIdTable_Ptr       CtrlIdTable_Ptr;
   CanIf_Cfg_CtrlConfig_tst*  CanIf_CtrlConfigPtr;
   uint8                      NumCanCtrl_u8;
   Type_TxPduIdTable_Ptr      TxPduIdTable_Ptr;
   CanIf_Cfg_TxPduConfig_tst* CanIf_TxPduConfigPtr;
   CanIf_Cfg_RxPduType_tst*   RxPduConfig_pcst;
   uint8*                     RxPduIdTable_Ptr;
   uint8                      NumOfTxPdus;
   uint8                      NumCanRxPduId_t;
   uint8                      NumCddRxPdus_t;
}Type_CfgEcuabCanIf_st;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern CONST(Type_CfgEcuabCanIf_st, ECUABIFCAN_CONFIG_DATA) CfgEcuabCanIf_st;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
