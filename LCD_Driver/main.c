#include "gpio.h"
#include "LCD_Configuration.h"








/*Function to initialize the LCD */
void LCD_Int(void){

    PORT_DIR(Data_Port,0xFF);  /*Make all Data port as output */

    PIN_DIR(Data_Port  , Enable_pin ,1);    /*Make the control bits as outputs */
    PIN_DIR(Data_Port  , ReadWrite_pin ,1);
    PIN_DIR(Data_Port  , RegisterSelect_pin ,1)

    PIN_WRITE(Control_Port , ReadWrite_pin , 0 );  /*we will use the ReadWrite pin to write */

    LCD_Sending_Command(8_bit_mode);  /*Send the 8-bit data directly in one stroke*/
    Delay_LCD(1);

    LCD_Sending_Command(Display_ON); /* Display ON, cursor OFF*/
    Delay_LCD(1);

    LCD_Sending_Command(Clear_Screen); /* Clear the display of the LCD */
    Delay_LCD(10);

    LCD_Sending_Command(Entry_mode); /* Write the charcter and move the cursor */
    Delay_LCD(1);


}



































int main()
{

}
