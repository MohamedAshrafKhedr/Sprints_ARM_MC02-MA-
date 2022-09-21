/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  GPIO_DIO
 *
 *  Description:  <DIO Deriver>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"../Common/Stdtypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define Dio_PortType 																			uint32

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 																						Dio_ChannelType;	

enum Dio_LevelType{
	Low ,
	Hi
};

typedef uint8 																						Dio_PortLevelType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
enum Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, enum Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId); 

void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);

enum Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId); 
 
#endif  /* DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
