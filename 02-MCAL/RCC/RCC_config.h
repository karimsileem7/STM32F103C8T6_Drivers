/********************************************************/
 /*    DATA :12/11/2021                                  */
/*    NAME :Karim Sileem                         */
/*          RESET AND CLOCK CONTROL                     */
/*   CLOCK SOURCE             RCC  DRIVER               */
/********************************************************/
#ifndef   RCC_CONFIG_H
#define   RCC_CONFIG_H

// System_Clock == (RCC_HSE  OR RCC_HSI OR RCC_PLL) //


#define System_Clock   RCC_HSE


//PLL_ClockSource  ==  (HSI/2 OR HSE OR HSE/2)//


#define PLL_ClockSource  HSE

//PLL Multiplication Factor (PLL_2,PLL_3,PLL_4,PLL_5,PLL_6,PLL_7,PLL_8,PLL_9,PLL_10,PLL_11,PLL_12,PLL_13,PLL_14,PLL_15,PLL_16)//

#define PLL_MultiplicationFactor  PLL_2

#endif
