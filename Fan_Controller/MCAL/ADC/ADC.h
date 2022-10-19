/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	ADC.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the AVR ADC driver.
------------------------------------------------------------------------------------------*/

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "../../Utilities/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_REF_VOLT_VALUE 2.56
#define ADC_MAXMIMU_VALUE 1023

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{			// The Reference voltage From the dataSheet
	AREF=0,				// Eternal Reference voltage from AREF pin
	AVCC=1,				// 5V ADC Reference voltage
	INTERNAL2_56=3		//  Internal 2.56V Reference voltage
}ADC_ReferenceVolatge;

typedef enum{
	Prescaler_2=1,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128
} ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	ADC_init
[DESCRIPTION]   :	initialize ADC according to Configuration in passed structure
[Args]		    :
				  in  -> ADCnumber :
								Pointer to structure containing configuration parameters
								with type defined above.

[Return]        : 16-bit integer containing the 10-bit value read from the ADC.
------------------------------------------------------------------------------------------*/
uint16 ADC_readChannel(uint8 ch_num);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	ADC_readChannel
[DESCRIPTION]   :	read data from ADC
[Args]		    :
				  in  -> ch_num :
								Number of ADC channel to read from (0 to 7).

[Return]        : 16-bit integer containing the 10-bit value read from the ADC.
------------------------------------------------------------------------------------------*/
#endif /* MCAL_ADC_ADC_H_ */
