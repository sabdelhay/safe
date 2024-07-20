/*
 * keypad_driver.c
 *
 * Created: 6/26/2024 6:42:40 PM
 *  Author: Sherif Abdelhay
 */ 
#include "keypad_driver.h"
#include "DIO.h"

void keypad_init(){
	DIO_setpindir('A',0,1);
	DIO_setpindir('A',1,1);
	DIO_setpindir('A',2,1);
	DIO_setpindir('A',3,1);

	DIO_setpindir('A',4,0);
	DIO_setpindir('A',5,0);
	DIO_setpindir('A',6,0);
	DIO_setpindir('A',7,0);

	DIO_connectPullUp('A',4,1);
	DIO_connectPullUp('A',5,1);
	DIO_connectPullUp('A',6,1);
	DIO_connectPullUp('A',7,1);
}

unsigned char keypad_read(){
	char ascii_char[4][4]={{'1','2','3','+'}, {'4','5','6','-'}, {'7','8','9','*'}, {'c','0','=','/'}};
	char row, col, button_status; 
	char return_val = NOT_PRESSED;
	
	for(row =0;row<4;row++){
		DIO_write('A',0,1);
		DIO_write('A',1,1);
		DIO_write('A',2,1);
		DIO_write('A',3,1);
		
		DIO_write('A',row,0);
		
		for(col = 0; col<4;col++){
			button_status = DIO_read('A', (col+4));
			if(button_status == 0){
				return_val = ascii_char[row][col];
				break;
			}
		}
		if(button_status == 0){
			break;
		}
	}
	return return_val;
} 