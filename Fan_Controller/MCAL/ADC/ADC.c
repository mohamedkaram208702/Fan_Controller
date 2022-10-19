/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	ADC.c

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Source file for the AVR ADC driver.
------------------------------------------------------------------------------------------*/
#include"ADC.h"
#include "../../Utilities/MCU_configuration.h"
#include "../../Utilities/common_macros.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX=(ADMUX&0x3F)|(ADMUX|(Config_Ptr->ref_volt << 6)); /* Determination the reference voltage of the ADC
															 according to the members in the passed structure */
	CLEAR_BIT(ADCSRA,ADIE); 			/* Disable the Module interrupt */
	SET_BIT( ADCSRA ,ADEN );  /* Enabling ADC */
	ADCSRA = (ADCSRA & 0xF8)|Config_Ptr->prescaler; /* Determination the frequency prescalar of the ADC
													according to the members in the passed structure */
}

uint16 ADC_readChannel(uint8 ch_num){
	if (ch_num > 8) return 0;  /* Return 0 if invalid ADD number is chosen */
	ADMUX|=ch_num; 	/* Setting ADC to use chosen channel */
	SET_BIT(ADCSRA,ADSC); /* ADC start conversion bit */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Waiting for ADC to finish Conversion and making the flag =1 */
	SET_BIT(ADCSRA,ADIF);   /* Clear the flag by setting ADIF */
	return ADC;
}
