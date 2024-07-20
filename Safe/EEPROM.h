/*
 * EEPROM.h
 *
 * Created: 5/27/2024 1:17:16 AM
 *  Author: Sherif Abdelhay
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned short address, unsigned char data);
unsigned char EEPROM_read(const unsigned short address);


#endif /* EEPROM_H_ */