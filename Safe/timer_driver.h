/*
 * timer.h
 *
 * Created: 5/27/2024 1:16:45 AM
 *  Author: Sherif Abdelhay
 */ 
#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

void timer_CTC_init_interrupt(void);
void timer_wave_nonPWM(void);
void timer_wave_fastPWM(void);
void timer_wave_phasecorrectPWM(void);
void timer1_wave_fastPWM(double value);

#endif /* TIMER_DRIVER_H_ */