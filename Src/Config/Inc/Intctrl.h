/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Intctrl.h
 *       Module:  -
 *
 *  Description:  Interrupt control header file     
 *  
 *********************************************************************************************************************/
#ifndef INTCRTL_H_
#define INTCRTL_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Stdtypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Core_Periph_Base 														(0xE000E000)
#define DIS0_OFFSET																(0x00000180)
#define DIS1_OFFSET																(0x00000184)
#define DIS2_OFFSET																(0x00000188)
#define DIS3_OFFSET																(0x0000018C)
#define DIS4_OFFSET																(0x00000190)

#define Int_Clear																(0xFFFFFFFF)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define Dis_Int(Reg ,Offset)       *((uint32*)(Reg + Offset))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
enum IntCtrl_IntType{
	Sys_Tick = 1
};
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

extern void IntCtrl_init(void);
 
#endif  /* INTCRTL_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Intctrl.h
 *********************************************************************************************************************/
