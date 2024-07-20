/*
 * button.c
 *
 * Created: 5/4/2024 7:46:17 PM
 *  Author: Sherif Abdelhay
 */ 
#include "DIO.h"

void button_init(char port, char pin){
	DIO_setpindir(port, pin, 0);
}


char button_read(char port, char pin){
	char button_state;
	button_state = DIO_read(port, pin);
	return button_state;
}



