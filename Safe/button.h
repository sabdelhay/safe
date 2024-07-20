/*
 * button.h
 *
 * Created: 5/4/2024 7:46:40 PM
 *  Author: Sherif Abdelhay
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void button_init(char port, char pin);
char button_read(char port, char pin);

#endif /* BUTTON_H_ */