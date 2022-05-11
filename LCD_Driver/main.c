#include "gpio.h"
#include "LCD_Configuration.h"








/*Function to initialize the LCD */
void LCD_Int(void){

    PORT_DIR(Data_Port,0xFF);  /*Make all Data port as output */

    PIN_DIR(Data_Port  , Enable_pin         ,1);    /*Make the control bits as outputs */
    PIN_DIR(Data_Port  , ReadWrite_pin      ,1);
    PIN_DIR(Data_Port  , RegisterSelect_pin ,1);

    PIN_WRITE(Control_Port , ReadWrite_pin , 0 );  /*we will use the ReadWrite pin to write */

    LCD_Send_Command(Eight_bit_mode);  /*Send the 8-bit data directly in one stroke*/
    Delay_LCD(1);

    LCD_Send_Command(Display_ON); /* Display ON, cursor OFF*/
    Delay_LCD(1);

    LCD_Send_Command(Clear_Screen); /* Clear the display of the LCD */
    Delay_LCD(10);

    LCD_Send_Command(Entry_mode); /* Write the char and move the cursor */
    Delay_LCD(1);


}




/*Function to make pulse for 2 ms*/
static void Pulse_func(void){         /*static because we will use it only in this file */

    PIN_WRITE(Control_Port , Enable_pin , 1 );
    Delay_LCD(2);
    PIN_WRITE(Control_Port , Enable_pin , 0 );

}


/*Function to send command*/
void LCD_Send_Command(char command){

    PORT_WRITE( Data_Port , command); /*write the command in data port*/

    PIN_WRITE( Control_Port , RegisterSelect_pin , 0); /*To know this is a command not character */

    Pulse_func();
    Delay_LCD(1);


}



/*Function to send character */
void LCD_Send_character(char character){

    PORT_WRITE( Data_Port , character); /*write character in data port*/

    PIN_WRITE( Control_Port , RegisterSelect_pin , 1); /*To know this is a character not command */

    Pulse_func();
    Delay_LCD(1);


}
























int main()
{

}
