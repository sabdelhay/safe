/*
 * std_macros.h
 *
 * Created: 4/26/2024 12:13:41 PM
 *  Author:Sherif Abdelhay
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(reg_name,bit)		reg_name |=(1<<bit)
#define CLR_BIT(reg_name,bit)		reg_name &=(~(1<<bit))
#define TOG_BIT(reg_name,bit)		reg_name ^=(1<<bit)
#define READ_BIT(reg_name,bit)		((reg_name&(1<<bit))>>bit)

#endif /* STD_MACROS_H_ */