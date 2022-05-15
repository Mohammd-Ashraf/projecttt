#include "GPIO.h"

void BUTTON_INIT (unsigned char Portname , unsigned char Pinnumber){
	PIN_DIR(Portname , Pinnumber , 0);
}


unsigned char BUTTON_READ (unsigned char Portname , unsigned char Pinnumber){
	return PIN_READ(Portname , Pinnumber);
}

void BUTTON_INIT_PULLUP (unsigned char Portname , unsigned char Pinnumber){
	PIN_DIR(Portname , Pinnumber , 0);
	PIN_PUR(Portname,Pinnumber,1);
}
