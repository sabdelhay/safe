/*
 * keypad_driver.h
 *
 * Created: 6/26/2024 6:42:40 PM
 *  Author: Sherif Abdelhay
 */ 
#define KEYPAD_PORT 'C'
#define NOT_PRESSED 0xff

void keypad_init(void);
unsigned char keypad_read(void);

#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_





#endif /* KEYPAD_DRIVER_H_ */