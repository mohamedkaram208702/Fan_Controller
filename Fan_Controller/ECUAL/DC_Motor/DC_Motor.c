/* -----------------------------------------------------------------------------------------
[FILE NAME]    :	DC_Motor.c

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	Header file for the DC_Motor driver.
------------------------------------------------------------------------------------------*/
#include"DC_Motor.h"
#include "../../MCAL/PWM/PWM.h"
#include "../../MCAL/GPIO/GPIO.h"
/* Function to initialize DCmotor */
void DCmotor_init(void){
	/* Set motor pins to output pins */
	GPIO_setupPinDirection(DCmotor_Port, DCmotor_PinA, PIN_OUTPUT);
	GPIO_setupPinDirection(DCmotor_Port, DCmotor_PinB, PIN_OUTPUT);
	/* Stop motor initially */
	GPIO_writePin(DCmotor_Port, DCmotor_PinA, 0);
	GPIO_writePin(DCmotor_Port, DCmotor_PinB, 0);
}

void DCmotor_rotate(DCmotor_state state, uint8 speed){
	switch(state) {
		case STOP:
			GPIO_writePin(DCmotor_Port, DCmotor_PinA, 0);
			GPIO_writePin(DCmotor_Port, DCmotor_PinB, 0);
			break;
		case CW:
			GPIO_writePin(DCmotor_Port, DCmotor_PinA, 1);
			GPIO_writePin(DCmotor_Port, DCmotor_PinB, 0);
			break;
		case ACW:
			GPIO_writePin(DCmotor_Port, DCmotor_PinA, 0);
			GPIO_writePin(DCmotor_Port, DCmotor_PinB, 1);
		}
		/* Set Timer0 to produce desired PWM */
		PWM_Timer0_Start(speed);
}
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
