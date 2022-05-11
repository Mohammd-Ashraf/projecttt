#include "gpio.h"


void LED_INIT (unsigned char Portname ,unsigned char Pinnumber){
	
	PIN_DIR(Portname,Pinnumber,1);
}

void LED_ON (unsigned char Portname,unsigned char Pinnumber){
	
	PIN_WRITE(Portname,Pinnumber,1);

}

void LED_OFF (unsigned char Portname,unsigned char Pinnumber){
	
	PIN_WRITE(Portname,Pinnumber,0);

}

void LED_TOG (unsigned char Portname,unsigned char Pinnumber){
	
	PIN_TOGGLE(Portname,Pinnumber,0);
	
}