/*
 * safe.h
 *
 * Created: 6/30/2024 2:29:39 PM
 *  Author: Sherif Abdelhay
 */ 

#define EEPROM_STATUS_LOCATION 0x30
#define EEPROM_PASSWORD_LOCATION1 0x31
#define EEPROM_PASSWORD_LOCATION2 0x32
#define EEPROM_PASSWORD_LOCATION3 0x33
#define EEPROM_PASSWORD_LOCATION4 0x34
#define MAX_TRIES 3
#define DEFAULT 0xff


void checkPass(void);
void settingPassword(void);
void closeSafe();

#ifndef MAIN_H_
#define MAIN_H_





#endif /* MAIN_H_ */