/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	DC_Motor.h

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the DC_Motor driver.
------------------------------------------------------------------------------------------*/

#ifndef ECUAL_DC_MOTOR_DC_MOTOR_H_
#define ECUAL_DC_MOTOR_DC_MOTOR_H_

#include "../../Utilities/std_types.h"

#define DCmotor_Port PORTB_ID
#define DCmotor_PinA PIN0_ID
#define DCmotor_PinB PIN1_ID

typedef enum{
	CW, /* Clockwise */
	ACW, /* Anti-clockwise */
	STOP
}DCmotor_state;

/* Function to initialize DCmotor */
void DCmotor_init(void);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	DCmotor_rotate
[DESCRIPTION]   :	 The Function responsible for setup the direction for the two
					 motor pins through the GPIO driver.

					 The Function responsible for setup the direction for the two
					 motor pins through the GPIO driver.
------------------------------------------------------------------------------------------*/

void DCmotor_rotate(DCmotor_state state, uint8 speed);
/* -----------------------------------------------------------------------------------------
[Function NAME] :	DCmotor_rotate
[DESCRIPTION]   :	The function responsible for rotate the DC Motor CW/ or A-CW or
					stop the motor based on the state input state value.

					Send the required duty cycle to the PWM driver based on the
					required speed value.

[Args]		    :
				  in  -> state :
							direction of motor rotation (Clockwise, Anti-clockwise, Stop).
				  in  -> speed:
							 decimal value for the required motor speed, it should be from
							 0 → 100. For example, if the input is 50, The motor should rotate with
                             50% of its maximum speed.
------------------------------------------------------------------------------------------*/

#endif /* ECUAL_DC_MOTOR_DC_MOTOR_H_ */
