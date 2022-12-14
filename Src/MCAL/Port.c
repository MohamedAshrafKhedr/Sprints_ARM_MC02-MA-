/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 const Port_ConfigType Ports[NO_OF_PORTS] = {
	{PIN_MODE, PIN_LEVEL, PIN_DIR, PIN_INT_ATTACH, PIN_CURRENT},
	{Low, Low, In, Drain, 0}
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(Port_ConfigType* ConfigPtr)        
* \Description     : Initializing port configuration                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ConfigPtr   contains pin configurations                     
* \Parameters (out): None                                                      
* \Return value:   : void  			     E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	uint8 i;
	
	for(i = 0; i < NO_OF_PORTS; i++){
	
		if(('F' == PORT)&&(ConfigPtr[i].PortPinMode == 0)){
			*(((uint32*)PORTF_BASE) + GPIO_LOCK_OFFSET) =  0x4C4F434B;
			Bit_Banding(PORTF_BASE, i, GPIO_AFSEL_OFFSET) = 0;
			Bit_Banding(PORTF_BASE, i, GPIO_DEN_OFFSET) = 1;
			Bit_Banding(PORTF_BASE, i, GPIO_CR_OFFSET) = 1;
			Bit_Banding(PORTF_BASE, i, GPIO_PCTL_OFFSET) = 0x00;

		}
		
		if(ConfigPtr[i].PortPinDirection == Out){
			Bit_Banding(PORTF_BASE, i, GPIO_DIR_OFFSET) = Out;
			Bit_Banding(PORTF_BASE, i, GPIO_PDR_OFFSET) = 0;
			Bit_Banding(PORTF_BASE, i, GPIO_PUR_OFFSET) = 0;
			Bit_Banding(PORTF_BASE, i, GPIO_R8R_OFFSET) = 1;
			Bit_Banding(PORTF_BASE, i, GPIO_SLR_OFFSET) = 1;
			*(((uint32*)PORTF_BASE) + GPIO_LOCK_OFFSET) =  0x0;
		}else if(ConfigPtr[i].PortPinDirection == In){
			Bit_Banding(PORTF_BASE, i, GPIO_DIR_OFFSET) = In;
			Bit_Banding(PORTF_BASE, i, GPIO_PDR_OFFSET) = 1;
			Bit_Banding(PORTF_BASE, i, GPIO_PUR_OFFSET) = 0;
			*(((uint32*)PORTF_BASE) + GPIO_LOCK_OFFSET) =  0x0;
		}			
		
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
