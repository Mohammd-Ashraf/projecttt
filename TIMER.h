#ifndef TIMER_H_
#define TIMER_H_

void SysTick_Wait(void);
void wait1ms(void);
void wait1us(void);
void genericdelay(unsigned long time,unsigned char unit);
#endif
