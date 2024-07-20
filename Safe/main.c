/*
 * main.c
 *
 * Created: 6/30/2024 2:29:39 PM
 *  Author: Sherif Abdelhay
 */ 
#include "safe.h"
#include "keypad_driver.h"
#include "lcd_driver.h"
#include "EEPROM.h"
#include "timer_driver.h"
#include "button.h"

int main(void)
{	
	keypad_init();
	LCD_init();
	button_init('B', 4);
	
	/*closeSafe();*/
	
	while(1){
		if(button_read('B',4) == 1){
			closeSafe();
			settingPassword();
			
		}else{
			settingPassword();
			checkPass();
		}
}
}// Main end
 
