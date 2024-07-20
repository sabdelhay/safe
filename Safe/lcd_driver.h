/*
 * lcd_driver.h
 *
 * Created: 5/27/2024 1:16:45 AM
 *  Author: Sherif Abdelhay
 */ 
#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#define CLR_Screen				0x01
#define RETURN_HOME				0x02
#define CURSOR_ON_DISPLAN_ON	0x0E
#define ENTRY_MODE				0x06

#define FOUR_BITS 0x28
#define EN 0
#define RS 1
#define RW 2
/*#define EIGHT_BITS 0x38*/

void LCD_init(void);
void enable(void);
void LCD_sendCommand(char cmd);
void LCD_sendChar(char data);
void LCD_clearScreen();
void LCD_sendString(char *ptr);
void LCD_moveCursor(char row, char col);

#endif /* LCD_DRIVER_H_ */