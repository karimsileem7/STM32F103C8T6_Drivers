/********************************************************/
 /*    DATA :12/11/2021                                  */
/*    NAME :Karim Sileem                         */
/*          RESET AND CLOCK CONTROL                     */
/*   CLOCK SOURCE             RCC  DRIVER               */
/********************************************************/

#ifndef   RCC_PRIVATE_H
#define   RCC_PRIVATE_H





#define RCC_CR          *((volatile u32 *)0x40021000)
#define RCC_CFGR        *((volatile u32 *)0x40021004)
#define RCC_CIR         *((volatile u32 *)0x40021008)
#define RCC_APB2RSTR    *((volatile u32 *)0x4002100C)
#define RCC_APB1RSTR    *((volatile u32 *)0x40021010)
#define RCC_AHBENR      *((volatile u32 *)0x40021014)
#define RCC_APB2ENR     *((volatile u32 *)0x40021018)
#define RCC_APB1ENR     *((volatile u32 *)0x4002101C)
#define RCC_BDCR        *((volatile u32 *)0x40021020)
#define RCC_CSR         *((volatile u32 *)0x40021024)


#define RCC_HSI			1

#define RCC_HSE			2


#define RCC_HSE_Electric 0
#define RCC_HSE_CERAMIC  1
#define RCC_HSE_Crystal  2



#endif
