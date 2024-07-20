/*
 * lcd_driver.c
 *
 * Created: 5/27/2024 1:16:45 AM
 *  Author: Sherif Abdelhay
 */ 

#include <avr/io.h>
#include "DIO.h"
#include "lcd_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_init(void){
// 	DIO_setpindir('A',0,1);
// 	DIO_setpindir('A',1,1);
// 	DIO_setpindir('A',2,1);
// 	DIO_setpindir('A',3,1);

	_delay_ms(200);
	DIO_setpindir('D',0,1);
	DIO_setpindir('D',1,1);
	DIO_setpindir('D',2,1);
	DIO_setpindir('D',3,1);
	
	DIO_setpindir('D',4,1);
	DIO_setpindir('D',5,1);
	DIO_setpindir('D',6,1);
	DIO_setpindir('D',7,1);
	
	
	DIO_setpindir('B',EN,1);
	DIO_setpindir('B',RS,1);
	DIO_setpindir('B',RW,1);
	
	DIO_write('B',RW,0);
	
	LCD_sendCommand(RETURN_HOME);
	_delay_ms(10);
	
	LCD_sendCommand(FOUR_BITS);
	_delay_ms(1);
	
	LCD_sendCommand(CURSOR_ON_DISPLAN_ON);
	_delay_ms(1);

	LCD_sendCommand(CLR_Screen);
	_delay_ms(1);

	LCD_sendCommand(ENTRY_MODE);
	_delay_ms(1);
}

void enable(void){
	DIO_write('B',EN,1);
	_delay_ms(2);
	DIO_write('B',EN,0);
	_delay_ms(2);
}

void LCD_sendCommand(char cmd){
	DIO_write_low_nibble('D', cmd >> 4);
	DIO_write('B', RS, 0);
	enable();
	DIO_write_low_nibble('D', cmd);
	DIO_write('B', RS, 0);
	enable();
	_delay_ms(1);
}

void LCD_sendChar(char data){
	DIO_write_low_nibble('D', data >> 4);
	DIO_write('B', RS, 1);
	enable();
	DIO_write_low_nibble('D', data);
	DIO_write('B', RS, 1);
	enable();
	_delay_ms(1);
}

void LCD_clearScreen(){
	LCD_sendCommand(0x01);
	_delay_ms(10);
}

void LCD_sendString(char *ptr){
	while(*ptr !='\0'){
		LCD_sendChar(*ptr);
		ptr++;
	}
}

// int i = 0;
// while(prt[i] ! = 0){
// 	LCD_sendChar(ptr[i]);
// 	i++;
// }

void LCD_moveCursor(char row, char col){
	char data;
	if(row > 4 || row < 1 || col > 20 || col < 1){
		data = 0x80;
	}
	else if(row == 1){
		data= 0x80 + col - 1;
	}
	else if (row == 2){
		data= 0xc0 + col - 1;
	}
	else if (row == 3){
		data= 0x94 + col - 1;
	}
	else if (row == 4){
		data= 0xd4 + col - 1;
	}
	LCD_sendCommand(data);
	_delay_ms(1);
}

