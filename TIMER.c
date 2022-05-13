void SysTick_Wait(){
		NVIC_ST_CTRL_R = 0x00;
		NVIC_ST_RELOAD_R = 0x00FFFFFF;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R = 0x05 ;
}

void wait1ms(){
		NVIC_ST_RELOAD_R = 0x3E80-1;
		NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R & 0x00010000)==0);
}

void genericdelay(unsigned long time){
	for (int i=0; i<time; i++){
		SysTick_Wait(a);
	}		
}