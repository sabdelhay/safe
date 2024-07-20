/*
 * DiO.c
 *
 * Created: 4/29/2024 7:53:08 PM
 *  Author: Sherif Abdelhay
 */ 
#include <avr/io.h>
#include "std_macros.h"

void DIO_setpindir(char port, char pin, char dir){
	switch(port){
	case 'A':
	case 'a':
	
	if(dir == 1){
		SET_BIT(DDRA, pin);
	}else{
		CLR_BIT(DDRA, pin);
	}
	break;
	
	case 'B':
	case 'b':
	if(dir == 1){
		SET_BIT(DDRB, pin);
	}else{
		CLR_BIT(DDRB, pin);
	}
	break;
	
	case 'C':
	case 'c':
	if(dir == 1){
		SET_BIT(DDRC, pin);
	}
	else{
		CLR_BIT(DDRC, pin);
	}
	break;
	
	case 'D':
	case 'd':
	if(dir == 1){
		SET_BIT(DDRD, pin);
	}else{
		CLR_BIT(DDRD, pin);
	}
	break;
	default: break;
	}
}

void DIO_write(char port, char pin, char val){
	switch(port){
		case 'A':
		case 'a':
		
		if(val == 1){
			SET_BIT(PORTA, pin);
		}else{
			CLR_BIT(PORTA, pin);
		}
		break;
		
		case 'B':
		case 'b':
		if(val == 1){
			SET_BIT(PORTB, pin);
		}else{
			CLR_BIT(PORTB, pin);
		}
		break;
		
		case 'C':
		case 'c':
		if(val == 1){
			SET_BIT(PORTC, pin);
		}else{
			CLR_BIT(PORTC, pin);
		}
		break;
		
		case 'D':
		case 'd':
		if(val == 1){
			SET_BIT(PORTD, pin);
		}else{
			CLR_BIT(PORTD, pin);
		}
		break;
		default: break;
	}
}

void DOI_toggle(char port,char pin){
	switch(port){
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin);
		break;
		
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin);
		break;
		
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);
		break;
		default: break;
	}
}

char DIO_read(char port, char pin){
	char returned_val =0;
	
	switch(port){
		case 'A':
		case 'a':
		 returned_val = READ_BIT(PINA, pin);
		break;
		
		case 'B':
		case 'b':
		returned_val = READ_BIT(PINB, pin);
		break;
		
		case 'C':
		case 'c':
		returned_val = READ_BIT(PINC, pin);
		break;
		
		case 'D':
		case 'd':
		returned_val = READ_BIT(PIND, pin);
		break;
		default: break;
	}
	return returned_val;
}
void DIO_connectPullUp(char port, char pin, char connect){
	{
		switch(port){
			case 'A':
			case 'a':
			
			if(connect == 1){
				SET_BIT(PORTA, pin);
			}else{
				CLR_BIT(PORTA, pin);
			}
			break;
			
			case 'B':
			case 'b':
			if(connect == 1){
				SET_BIT(PORTB, pin);
			}else{
				CLR_BIT(PORTB, pin);
			}
			break;
			
			case 'C':
			case 'c':
			if(connect == 1){
				SET_BIT(PORTC, pin);
			}else{
				CLR_BIT(PORTC, pin);
			}
			break;
			
			case 'D':
			case 'd':
			if(connect == 1){
				SET_BIT(PORTD, pin);
			}else{
				CLR_BIT(PORTD, pin);
			}
			break;
			default: break;
		}
	}
}
void DIO_setportdir(char port, char dir){
	switch(port)
	{
		case 'A':
		case 'a':
		DDRA=dir; 
		break ;
		
		case 'B':
		case 'b':
		DDRB=dir; 
		
		break ;
		case 'C':
		case 'c':
		DDRC=dir; 
		break ;
		
		case 'D':
		case 'd':
		DDRD=dir; 
		break ;
		
		default:
		break ;
	}
}
void DIO_writeport(char port, char val){
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=val; 
		break ;
		case 'B':
		case 'b':
		PORTB=val; 
		break ;
		case 'C':
		case 'c':
		PORTC=val; 
		break ;
		case 'D':
		case 'd':
		PORTD=val; 
		break ;
		default:
		break ;
	}
}

void DIO_write_low_nibble(char port,char val){
	 val&=0x0f;
	 switch(port)
	 {
		 case 'A':
		 PORTA&=0xf0;
		 PORTA|=val;
		 break;
		 case 'B':
		 PORTB&=0xf0;
		 PORTB|=val;
		 break;
		 case 'C':
		 PORTC&=0xf0;
		 PORTC|=val;
		 break;
		 case 'D':
		 PORTD&=0xf0;
		 PORTD|=val;
		 break;
	 }
}
void DIO_write_high_nibble(char port,char val)
	{
		val<<=4;
		switch(port)
		{
			case 'A':
			PORTA&=0x0f;
			PORTA|=val;
			break;
			case 'B':
			PORTB&=0x0f;
			PORTB|=val;
			break;
			case 'C':
			PORTC&=0x0f;
			PORTC|=val;
			break;
			case 'D':
			PORTD&=0x0f;
			PORTD|=val;
			break;
		}
	}