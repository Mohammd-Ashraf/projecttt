#include "GPIO.h"
#include "Button.h"

void KEYPAD_INIT(unsigned char Portname){
	Port_init(Portname);
	PORT_DIR(Portname,0x0F);
	PIN_PUR(Portname,4,1);
	PIN_PUR(Portname,5,1);
	PIN_PUR(Portname,6,1);
	PIN_PUR(Portname,7,1);
}


unsigned char KEYPAD_READ(unsigned char Portname){
	
	unsigned char arr[4][4] = {
				{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
				{'*', '0', '#', 'D'}
														};
char row,col,x;
char returnvalue=0xFF;
	for(row=0;row<4;row++){
	WRITE_LOWERBITS(Portname,0xFF);
	PIN_WRITE(Portname,row,0);
	for(col=0;col<=3;col++){
		x = PIN_READ(Portname, col+4);
		if(x==0){
			returnvalue=arr[row][col];
		break;
	  }
		if(x==0) break;
		return returnvalue;			
    }
	}
}
