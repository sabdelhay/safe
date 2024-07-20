/*
 * EEPROM.c
 *
 * Created: 5/27/2024 1:16:45 AM
 *  Author: Sherif Abdelhay
 */ 
#include <avr/io.h>
#include "std_macros.h"

void EEPROM_write(unsigned short address, unsigned char data){
	/* Set up the address register */
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	/* Set up the data register */
	EEDR = data;
	
	/* Write logical one to EEMWE */
	SET_BIT(EECR, EEMWE);
	/* Write logical one to EEWE */
	SET_BIT(EECR, EEWE);
	
	/* Checks the completion of the write operation */
	while(READ_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_read(const unsigned short address){
	/* Set up the address register */
	EEARL = (char)address;
	EEARH = (char)(address>>8);
	
	/* Start the EEPROM reading by setting the EERE */
	SET_BIT(EECR, EERE);
	
	/* return data from data register */
	return EEDR;
}