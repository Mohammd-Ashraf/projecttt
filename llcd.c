#include <stdio.h>
#include <stdlib.h>
0
#include "lcd.h"

void LCD_INIT(void)
{
    Port_init('B');
    Port_init('E');
    PORT_DIR('B', 0xFF);
    PIN_DIR('E', 3, 1);  //E
    PIN_DIR('E', 1,1 );  //Rs
    PIN_DIR('E', 2,1 ); //Rw
    PIN_WRITE('E', 2, 0);
    lcd_command(0x38);
    genericdelay(1);
    /* Entry Mode Set  */
    lcd_command(0x06);
    genericdelay(1);

    /* Display ON OFF Control */
    lcd_command(0x0F);
    genericdelay(1);

    /* Clear Display */
    lcd_command(0x01);
    genericdelay(2);

    /* Return Home  */
    lcd_command(0x02);
    genericdelay(2);
}

void lcd_command(unsigned char cmd)
{
    PIN_WRITE('B', cmd);
    PIN_WRITE('E', 0x08);
    // GPIO_PORTB_DATA_R=cmd;
    // GPIO_PORTE_DATA_R=0X04; // pin(B0-B7)
    genericdelay(1);
    PIN_WRITE('E', 0x00);
    // GPIO_PORTE_DATA_R=0; //Rs---->portE0,RW--->graound or portE1, E---->portE2
    genericdelay(50);

    return;
}
void send_char(unsigned char data) //-----> recive only one char
{
    PIN_WRITE(DATA_PORT, data);
    // GPIO_PORTB_DATA_R=data;
    PIN_WRITE(CTRL_PORT, 0x05);
    // GPIO_PORTE_DATA_R=0X05;
    genericdelay(1);
    PIN_WRITE(CTRL_PORT, 0x01);
    // GPIO_PORTE_DATA_R=0X01;
    genericdelay(50);

    return;
}
void send_String(unsigned char *data)
{
    while ((*data) != '0')
    {
        send_Char(*data);
        data++;
    }
}
void LCD_Move_Cursor(unsigned char row, unsigned char col)
{
    unsigned char position = 0;

    if (row == 1)
    {
        position = (FirstRow) + col - 1;
    }
    else if (row == 2)
    {
        position = (SecondRow) + col - 1;
    }
    else
    {
        position = FirstRow;
    }
    lcd_command(position);
    genericdelay(1);
}
void LCD_COUNT_DOWN(unsigned char timer)
{
    unsigned char i;
    for (i = timer - 1; i >= 0; i--)
    {
        send_char(i);
        genericdelay(1);
        lcd_command(clear_display);
    }
}

void LCD_HOLD(unsigned char hold, unsigned char time)
{
    send_char(hold);
    genericdelay(time);
}
