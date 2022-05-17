#include "GPIO.h"
#include "LCD_Configuration.h"
#include "TIMER.h"



/*Function to send command*/
void LCD_Send_Command(char command){
    PIN_WRITE(Control_Port , Enable_pin , 1 );
    //GPIO_PORTE_DATA_R |= 0x08;
    genericdelay(50,0);
    PIN_WRITE( Control_Port , RegisterSelect_pin , 0); /*To know this is a command not character */
    //GPIO_PORTE_DATA_R &= ~0x01;
    genericdelay(50,0);
    PORT_WRITE( Data_Port , command); /*write the command in data port*/
    //GPIO_PORTB_DATA_R &= 00;
    //GPIO_PORTB_DATA_R |= command;

    genericdelay(50,0);

    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTE_DATA_R &= ~0x08;


}


/*Function to initialize the LCD */
void LCD_Int(void){
        PORT_DIR(Data_Port,0xFF);  /*Make all Data port as output */
    //GPIO_PORTB_DIR_R = 0xFF;


    PIN_DIR(Control_Port  , Enable_pin         ,1);    /*Make the control bits as outputs */
    PIN_DIR(Control_Port  , ReadWrite_pin      ,1);
    PIN_DIR(Control_Port  , RegisterSelect_pin ,1);
    //GPIO_PORTE_DIR_R |= 0x0E;

    PIN_WRITE(Control_Port , Enable_pin , 1 );
    //GPIO_PORTE_DATA_R |= 0x08;
    genericdelay(50,0);



    PIN_WRITE(Control_Port , ReadWrite_pin , 0 );  /*we will use the ReadWrite pin to write */
    //GPIO_PORTE_DIR_R &= ~0x04;

    LCD_Send_Command(Eight_bit_mode);  /*Send the 8-bit data directly in one stroke*/
    genericdelay(1,0);

    LCD_Send_Command(Display_ON); /* Display ON, cursor OFF*/
    genericdelay(1,0);

    LCD_Send_Command(Clear_Screen); /* Clear the display of the LCD */
    genericdelay(10,0);

    LCD_Send_Command(Entry_mode); /* Write the char and move the cursor */
    genericdelay(1,0);

    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTE_DATA_R &= ~0x08;


}




/*Function to send character */
void LCD_Send_character(char character){

    PIN_WRITE(Control_Port , Enable_pin , 1 );
    //GPIO_PORTE_DATA_R |= 0x08;
    genericdelay(50,0);

    PIN_WRITE( Control_Port , RegisterSelect_pin , 1); /*To know this is a character not command */
    //GPIO_PORTD_DATA_R |= 0x02;
    genericdelay(50,0);

    PORT_WRITE(Data_Port , character); /*write character in data port*/
    genericdelay(1,0);
    //GPIO_PORTB_DATA_R &= 00;
    //GPIO_PORTB_DATA_R |= character;

    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTE_DATA_R &= ~0x08;


}




/*Function to send string */
void LCD_Send_string(char *data){
    PIN_WRITE(Control_Port , Enable_pin , 1 );
    //GPIO_PORTE_DATA_R |= 0x08;
    genericdelay(50,0);

    while ((*data)!= '0'){
        LCD_Send_character(*data);
        data++ ;
    }
    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTE_DATA_R &= ~0x08;
}





/*Function to clear screen */
void LCD_clearScreen(void){
    PIN_WRITE(Control_Port , Enable_pin , 1 );
    //GPIO_PORTE_DATA_R |= 0x08;
    genericdelay(50,0);

    LCD_Send_Command(Clear_Screen);
    genericdelay(10,0);
      /*Delay 10 ms */
    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTE_DATA_R &= ~0x08;
}




/*Function to move the cursor */
void cursor_move(char row , char column){
    char position = 0;

PIN_WRITE(Control_Port , Enable_pin , 1 );
  //GPIO_PORTD_DATA_R |= 0x08;
    genericdelay(50,0);

    if(row == 1){
        position = (0x80) + (column-1);
    }
    else if(row == 2){
            position = (0xC0) + (column-1);
    }
    else{   /*if row is not 1 or 2 then go to the first position in the first row */
        position = 0x80;
    }

    LCD_Send_Command(position);
    genericdelay(1,0);

    PIN_WRITE(Control_Port , Enable_pin , 0);
    //GPIO_PORTD_DATA_R &= ~0x08;





/* probably we will not use it*/
/*Function to make pulse for 2 ms*/
 /*static because we will use it only in this file */

/*static void Pulse_func(void){
    PIN_WRITE(Control_Port , Enable_pin , 1 );
    genericdelay(2);
    PIN_WRITE(Control_Port , Enable_pin , 0 );

} */




}

