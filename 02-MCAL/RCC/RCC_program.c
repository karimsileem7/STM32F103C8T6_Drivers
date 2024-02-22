/********************************************************/
 /*    DATA :12/11/2021                                  */
/*    NAME :Karim Sileem                         */
/*          RESET AND CLOCK CONTROL                     */
/*   CLOCK SOURCE             RCC  DRIVER               */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.H"

#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"


void RCC_VoidInit(void)
{     //selected system clock source//

	//clock source type  (HSI..HSE..PLL)//
	//*****************************************HSI****************************//
#if System_Clock==RCC_HSI
	//HSI Choice//
	CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);

	//HSI ON//
	SET_BIT(RCC_CR,0); 

	//HSI READY//
	while(GET_BIT(RCC_CR,1)==0)
	{

	}


	//*****************************************HSE****************************//
#elif System_Clock==RCC_HSE
	//HSE Choice//

	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);

	//HSE TYPES (electric or cyramic or crystal)//

#if RCC_HSE_Type==RCC_HSE_Electric
	SET_BIT(RCC_CR,18);

#elif RCC_HSE_Type==RCC_HSE_Crystal
	CLR_BIT(RCC_CR,18);
#elif RCC_HSE_Type==RCC_HSE_CERAMIC
	CLR_BIT(RCC_CR,18);
#endif
	//HSE ON//
	SET_BIT(RCC_CR,16);

	//HSI READY//
	while(GET_BIT(RCC_CR,17)==0)
	{

	}


	//*****************************************PLL****************************//
#elif System_Clock==RCC_PLL
	//PLL Choice//
	CLR_BIT(RCC_CFGR,0);
	SET_BIT(RCC_CFGR,1);

	//PLL Clock Source   (HSI/2 OR HSE OR HSE/2)//

	//PLL CLOCK SOURCE HSI Divided by 2//
#if PLL_ClockSource==HSI/2
	CLR_BIT(RCC_CFGR,16);   

	//PLL CLOCK SOURCE HSE//
#elif PLL_ClockSource==HSE
	SET_BIT(RCC_CFGR,16); 

	//PLL CLOCK SOURCE HSE/2//
#elif PLL_ClockSource==HSE/2
	SET_BIT(RCC_CFGR,17); 
#endif

	//PLL Multiplication Factor (PLL_2,PLL_3,PLL_4,PLL_5,PLL_6,PLL_7,PLL_8,PLL_9,PLL_10,PLL_11,PLL_12,PLL_13,PLL_14,PLL_15,PLL_16)//
#if PLL_MultiplicationFactor==PLL_2
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0000<<18);
#elif PLL_MultiplicationFactor==PLL_3
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0001<<18);
#elif PLL_MultiplicationFactor==PLL_4
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0010<<18);
#elif PLL_MultiplicationFactor==PLL_5
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0011<<18);
#elif PLL_MultiplicationFactor==PLL_6
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0100<<18);
#elif PLL_MultiplicationFactor==PLL_7
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0101<<18);
#elif PLL_MultiplicationFactor==PLL_8
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0110<<18);
#elif PLL_MultiplicationFactor==PLL_9
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b0111<<18);
#elif PLL_MultiplicationFactor==PLL_10
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1000<<18);
#elif PLL_MultiplicationFactor==PLL_11
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1001<<18);
#elif PLL_MultiplicationFactor==PLL_12
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1010<<18);
#elif PLL_MultiplicationFactor==PLL_13
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1011<<18);
#elif PLL_MultiplicationFactor==PLL_14
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1100<<18);
#elif PLL_MultiplicationFactor==PLL_15
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1101<<18);
#elif PLL_MultiplicationFactor==PLL_16
	RCC_CFGR &=~(0b1111)<<18 ;
	RCC_CFGR |=(0b1110<<18);


#endif
	//PLL ENABLE//
	SET_BIT(RCC_CR,24);

	//PLL READY FLAG//
	while(GET_BIT(RCC_CR,25)==0)
	{

	}
#else
#error("Wrong choise clock source !")
#endif


}

void RCC_VoidEnableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID)
{
	if(copy_u8PeripheralID <32)
	{
		switch(copy_u8BusID)
		{
		case RCC_AHB  : SET_BIT(RCC_AHBENR,copy_u8PeripheralID);break;
		case RCC_APB1 : SET_BIT(RCC_APB1ENR,copy_u8PeripheralID);break;
		case RCC_APB2 : SET_BIT(RCC_APB2ENR,copy_u8PeripheralID);break;
		}

	}
}

void RCC_VoidDisableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID)
{
	if(copy_u8PeripheralID <32)
	{
		switch(copy_u8BusID)
		{
		case RCC_AHB  : CLR_BIT(RCC_AHBENR,copy_u8PeripheralID);break;
		case RCC_APB1 : CLR_BIT(RCC_APB1ENR,copy_u8PeripheralID);break;
		case RCC_APB2 : CLR_BIT(RCC_APB2ENR,copy_u8PeripheralID);break;
		}

	}
}

