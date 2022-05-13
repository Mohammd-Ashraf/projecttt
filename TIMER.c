#include "tm4c123gh6pm.h"


void SysTick_Wait(void){
		NVIC_ST_CTRL_R = 0x00;
		NVIC_ST_RELOAD_R = 0x00FFFFFF;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R = 0x05 ;
}

void wait1ms(void){
		NVIC_ST_RELOAD_R = 0x3E80-1;
		NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R & 0x00010000)==0);
}

void genericdelay(unsigned long time){
	int i;
	for (i=0; i<time; i++){
		wait1ms();
	}		
}
