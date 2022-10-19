/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	PWM.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the AVR PWM driver.
------------------------------------------------------------------------------------------*/


#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_
#include "../../Utilities/std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 set_duty_cycle);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	PWM_Timer0_Start
[DESCRIPTION]   :	➢ The function responsible for trigger the Timer0 with the PWM Mode.
					➢ Setup the PWM mode with Non-Inverting.
					➢ Setup the prescaler with F_CPU/8.
					➢ Setup the compare value based on the required input duty cycle
					➢ Setup the direction for OC0 as output pin through the GPIO driver.
					➢ The generated PWM signal frequency will be 500Hz to control the DC
					Motor speed.

[Args]		    :
				  in  -> duty_cycle :
							The required duty cycle percentage of the generated
							PWM signal. Its value should be from 0 → 100

------------------------------------------------------------------------------------------*/

#endif /* MCAL_PWM_PWM_H_ */
