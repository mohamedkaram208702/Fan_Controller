/* -----------------------------------------------------------------------------------------
[Project NAME]    :	 Fan Controller system

[AUTHOR]       :	Mohamed Karam Fouad

[DATA CREATED] :	02/10/2022

[DESCRIPTION]  :	 The aim of this project is to design a temperature-controlled fan using ATmega32
					 microcontroller, in which the fan is automatically turned ON or OFF according to the
                     temperature. Use ATmega32 Microcontroller with frequency 1Mhz.
------------------------------------------------------------------------------------------*/

#include "../ECUAL/DC_Motor/DC_Motor.h"
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/LM35_Temperature_sensor/sensor.h"
#include "../MCAL/ADC/ADC.h"
#include "../Utilities/std_types.h"

int main(){
	/* Configuring ADC to use internal 2.56V reference and F_CPU/8 */
	ADC_ConfigType ADC_config = {INTERNAL2_56, Prescaler_8};
	ADC_init(&ADC_config);
	/* LCD initilization */
	LCD_init();
	/*DC motor initialization */
	DCmotor_init();
	uint8 temperature;
	LCD_displayString("Fan is ");
	LCD_moveCursor (1, 0);
	LCD_displayString("Temp = ");
	while(1){
		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 7);
		LCD_intgerToString(temperature);
		if (temperature < 30){
			DCmotor_rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 7, "OFF");
		}else if(temperature < 60){
			DCmotor_rotate(CW, 25);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}else if(temperature < 90){
			DCmotor_rotate(CW, 50);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}else if(temperature < 120){
			DCmotor_rotate(CW, 75);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}else{
			DCmotor_rotate(CW, 100);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}
	}
}



