/*
 * safe.c
 *
 * Created: 6/30/2024 2:29:39 PM
 *  Author: Sherif Abdelhay
 */ 
#include "safe.h"
#define F_CPU 1000000U
#include <util/delay.h>
#include "keypad_driver.h"
#include "lcd_driver.h"
#include "EEPROM.h"
#include "timer_driver.h"
#include "button.h"

char arr[4];
volatile char safeStatus=0;
volatile char value = DEFAULT;
volatile char flag=0, i;
volatile char tries = MAX_TRIES;

void checkPass(void){
	while(flag==0 && safeStatus == 0)
	{
		timer1_wave_fastPWM(1.0);
		arr[0]=arr[1]=arr[2]=arr[3]=DEFAULT;
		LCD_clearScreen();
		LCD_sendString("check pass:");
		// For loop start
		for (i=0;i<=3;i++){
			do
			{
				arr[i]=keypad_read();
				_delay_ms(200);
			}while (arr[i]==DEFAULT);
			LCD_sendChar(arr[i]);
			_delay_ms(500);
			LCD_moveCursor(1,12+i);
			LCD_sendChar('*');
			_delay_ms(500);
		}// For loop end
		// Outer if start
		if(EEPROM_read(EEPROM_PASSWORD_LOCATION1)==arr[0] &&  \
		EEPROM_read(EEPROM_PASSWORD_LOCATION2)==arr[1] && \
		EEPROM_read(EEPROM_PASSWORD_LOCATION3)==arr[2] && \
		 EEPROM_read(EEPROM_PASSWORD_LOCATION4)==arr[3])
		{
			
			timer1_wave_fastPWM(2.0);
			LCD_clearScreen();
			LCD_sendString("right password");
			LCD_moveCursor(2,1);
			LCD_sendString("safe opened");
			flag=1;
			safeStatus = 1;
		}// Outer if end
		// Start the outer else
		else
		{
			tries=tries-1;
			if (tries>0)
			{
				LCD_clearScreen();
				LCD_sendString("wrong password");
				_delay_ms(1000);
				LCD_clearScreen();
				LCD_sendString("tries left:");
				LCD_sendChar(tries+48);
				_delay_ms(1000);
			}
			else
			{
				LCD_clearScreen();
				timer1_wave_fastPWM(1.0);
				LCD_sendString("wrong password");
				LCD_moveCursor(2,1);
				LCD_sendString("safe closed");
				flag=1;
				safeStatus = 1;
			}
		}// End the outer else
	} // End while
}

void settingPassword(void){
	
	if(EEPROM_read(EEPROM_STATUS_LOCATION)==DEFAULT){
		LCD_sendString("SET PASS:");
		for(i=0;i<=3;i++){
			do{
				value = keypad_read();
				//_delay_ms(250);
			}while(value==DEFAULT);
			LCD_sendChar(value);
			_delay_ms(500);
			LCD_moveCursor(1,10+i);
			LCD_sendChar('*');
			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i, value);
			//_delay_ms(250);
		}
		EEPROM_write(EEPROM_STATUS_LOCATION, 0x00);
	}// End If
}

void closeSafe(){
	if(button_read('B', 4) == 1){
		timer1_wave_fastPWM(1.0);
		LCD_clearScreen();
		flag=0;
		safeStatus = 0;
		
		checkPass();
	}
}
