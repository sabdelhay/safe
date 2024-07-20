/*
 * DIO.h
 *
 * Created: 4/29/2024 7:56:40 PM
 *  Author: Sherif Abdelhay
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_setpindir(char port, char pin, char dir);
void DIO_write(char port, char pin, char val);
void DOI_toggle(char prot,char pin);
char DIO_read(char port, char pin);
void DOI_toggle(char prot,char pin);
void DIO_connectPullUp(char port, char pin, char connect);
void DIO_setportdir(char port, char dir);
void DIO_writeport(char port, char val);
void DIO_write_low_nibble(unsigned char port, unsigned val);
void DIO_write_high_nibble(unsigned char port, unsigned val);

/*
char DIO_readport(char port);
void DIO_toggleport(char port);
*/

#endif /* DIO_H_ */