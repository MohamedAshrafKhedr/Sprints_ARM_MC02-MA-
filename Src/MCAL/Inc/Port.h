/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  GPIO_Port
 *
 *  Description:  <Ports Deriver>     
 *  
 *********************************************************************************************************************/
#ifndef Port_H_
#define Port_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Port_PinType 																						uint8
#define Port_PinOutputCurrentType 																			uint8
#define PORTF_BASE 																							(0x400253F0UL)
#define GPIO_DATA_OFFSET																					(0x000UL)
#define GPIO_DIR_OFFSET																						(0x400UL)
#define GPIO_AFSEL_OFFSET																					(0x420UL)
#define GPIO_DEN_OFFSET																						(0x51CUL)
#define GPIO_PDR_OFFSET																						(0x514UL)
#define GPIO_PUR_OFFSET																						(0x510UL)
#define GPIO_PCTL_OFFSET																					(0x52CUL)
#define GPIO_CR_OFFSET																						(0x524UL)
#define GPIO_R8R_OFFSET																						(0x508UL)
#define GPIO_SLR_OFFSET																						(0x518UL)
#define NO_OF_PORTS																							(1UL)
#define PIN_MODE																							 0
#define PIN_LEVEL																							 Low
#define PIN_DIR																								 Out
#define PIN_INT_ATTACH																						 0
#define PIN_CURRENT 																						 8
#define PORT 																								 'F'	
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define Bit_Banding(reg, pin, offset)																		 *((volatile uint32*)(0x42000000 + (((reg + offset) - 0x40000000)*32)) + (pin * 4))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 enum Port_PinModeType {
	Low = 0, 
	Hi = 1
	};
 enum Port_PinDirectionType {
	In = 0,
	Out = 1 
	};
 enum Port_PinInternalAttachType {
	 Down ,
	 Up ,
	 Drain 
	 };
typedef struct{
	
	Port_PinType 							PortPinMode;
	enum Port_PinModeType 					PortPinLevelValue;
	enum Port_PinDirectionType 				PortPinDirection;
	enum Port_PinInternalAttachType 		PortPinInternalAttach;
	Port_PinOutputCurrentType 				PortPinOutputCurrentMode;
	
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);
 
#endif  /* DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
