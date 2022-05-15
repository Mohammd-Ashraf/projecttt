#include <stdio.h>
#include <stdlib.h>
#include "LCD_alternative.h"
#include "GPIO.h"
#include "Macros.h"
#include "tm4c123gh6pm.h"
#include "TIMER.h"

void LCD_CMD(unsigned char command){
    PIN_WRITE(control_Port,0,0);
    genericdelay(3);
    PORT_WRITE(Data_Port,command);
    genericdelay(3);



}

void LCD_INIT(){
Port_init('B');
Port_init('D');
PIN_DIR ('D',0,1); //RS  sending commands or data to LCD
PIN_DIR ('D',1,1); //RW
PIN_DIR ('D',2,1); //E
PORT_DIR('B',0xFF);
LCD_CMD(Function_8_bit);
LCD_CMD(clear_display);
LCD_CMD(cursorBlink);
LCD_CMD(Set5x7FontSize);
LCD_CMD(moveCursorRight);

}



void LCD_CHAR(unsigned char character){
        PIN_WRITE(control_Port,0,1);
        genericdelay(500);
        PORT_WRITE(Data_Port,character);
        genericdelay(500);

}

void LCD_STR(char *string){

int i;

for(i=0;string[i]!=0;i++){   //sends until the null terminator
    LCD_CHAR(string[i]);
}

}


