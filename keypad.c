#include "GPIO.h"
#include "Button.h"
#define 	KProw   'E'
#define   KPcol   'A'

void KEYPAD_INIT(void){
	PORT_DIR(KProw,0xFF);
	PORT_DIR(KPcol,0x00);
	PIN_PUR(KPcol,4,1);
	PIN_PUR(KPcol,5,1);
	PIN_PUR(KPcol,6,1);
	PIN_PUR(KPcol,7,1);
}


unsigned char KEYPAD_READ(void){

	unsigned char arr[4][4] = {
				{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
				{'*', '0', '#', 'D'}
														};

while(1){

char row,col,x;
char returnvalue=0xFF;
	for(row=0;row<4;row++){
	WRITE_LOWERBITS(KProw,0xFF);
	PIN_WRITE(KProw,row,0);
	for(col=0;col<=3;col++){
		x = PIN_READ(KPcol, col+4);
		if(x==0){
			returnvalue=arr[row][col];
	  }
	  		return returnvalue;

    }
    if(x==0) break;
	}

}
}
