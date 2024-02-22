/********************************************************/
 /*    DATA :12/11/2021                                  */
/*    NAME :Karim Sileem                         */
/*          RESET AND CLOCK CONTROL                     */
/*   CLOCK SOURCE             RCC  DRIVER               */
/********************************************************/

#ifndef   RCC_INTERFACE_H
#define   RCC_INTERFACE_H


#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2




/* RCC Register - CR*/




void RCC_VoidInit(void);

void RCC_VoidEnableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID);

void RCC_VoidDisableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID);


#endif
