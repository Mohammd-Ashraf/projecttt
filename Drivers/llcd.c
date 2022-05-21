#include <stdio.h>
#include <stdlib.h>
#include "gpio.h"
#include "lcd.h"
#include "TIMER.h"
#include "tm4c123gh6pm.h"



void lcd_command(unsigned char cmd)
{
    PORT_WRITE('B', cmd);
    PORT_WRITE('E', 0x04);
    // GPIO_PORTB_DATA_R=cmd;
    // GPIO_PORTE_DATA_R=0X04; // pin(B0-B7)
    genericdelay(1,0);
    PORT_WRITE('E', 0x00);
    // GPIO_PORTE_DATA_R=0; //Rs---->portE0,RW--->graound or portE1, E---->portE2
    genericdelay(50,0);

    return;
}
	
	
void LCD_INIT(void)
{
	
		genericdelay(500,0);
	
    GPIO_Init(1);
    GPIO_Init(2);
    //PORT_DIR('B', 0xFF);
	  GPIO_PORTB_DIR_R = 0xFF;
//  	PIN_DIR('E', 3, 1);  //E
//    PIN_DIR('E', 1,1 );  //Rs
//    PIN_DIR('E', 2,1 ); //Rw
		 GPIO_PORTE_DIR_R |= 0x07;
	
    //PIN_WRITE('E', 2, 0);
	  //GPIO_PORTE_DATA_R &= ~(0x0);
    lcd_command(0x38);
    genericdelay(1,0);
    /* Entry Mode Set  */
    lcd_command(0x06);
    genericdelay(1,0);

    /* Display ON OFF Control */
    lcd_command(0x0F);
    genericdelay(1,0);

    /* Clear Display */
    lcd_command(0x01);
    genericdelay(2,0);

    /* Return Home  */
    lcd_command(0x02);
    genericdelay(2,0);
}



void send_char(unsigned char data) //-----> recive only one char
{
    //PORT_WRITE('B', data);
     GPIO_PORTB_DATA_R=data;
    //PORT_WRITE('E', 0x09);
     GPIO_PORTE_DATA_R |= 0X05;
    genericdelay(50,0);
    //PORT_WRITE('E', 0x01);
     GPIO_PORTE_DATA_R = 0X01;
    genericdelay(50,0);

    return;
}
void send_String(unsigned char *data)
{
    while ( *data )
    {
        send_char(*data);
        data++;
    }
}
void LCD_Move_Cursor(unsigned char row, unsigned char col)
{
    unsigned char position = 0;

    if (row == 1)
    {
        position = (0x80) + col - 1;
    }
    else if (row == 2)
    {
        position = (0xC0) + col - 1;
    }
    else
    {
        position = 0x80;
    }
    lcd_command(position);
    genericdelay(1,0);
}
void LCD_COUNT_DOWN(unsigned char timer)
{
    unsigned char i;
    for (i = timer - 1; i >= 0; i--)
    {
        send_char(i);
        genericdelay(1,0);
        lcd_command(0x01);
    }
}

void LCD_HOLD(unsigned char hold, unsigned char time)
{
    send_char(hold);
    genericdelay(time,0);
}
