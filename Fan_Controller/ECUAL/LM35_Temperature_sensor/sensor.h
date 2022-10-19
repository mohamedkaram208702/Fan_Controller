/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	sensor.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the sensor driver.
------------------------------------------------------------------------------------------*/
#include "../../Utilities/std_types.h"

#ifndef ECUAL_LM35_TEMPERATURE_SENSOR_SENSOR_H_
#define ECUAL_LM35_TEMPERATURE_SENSOR_SENSOR_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 LM35_getTemperature(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	LM35_getTemperature
[DESCRIPTION]   :	Function responsible for calculate the temperature from the ADC digital value.

[Return]        : temperature from the ADC digital value.
------------------------------------------------------------------------------------------*/
#endif /* ECUAL_LM35_TEMPERATURE_SENSOR_SENSOR_H_ */
