#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_



/* 1- Defining the data port*/
#define Data_Port 'B'

/*2- Defining the control port (Enable - Read Write - Register select)*/
#define Control_Port 'E'




/* 3- Clear display screen*/
#define Clear_Screen 0x01

/*4- Display ON, cursor ON*/
#define Display_Cursor_ON 0x0E


/*5- Display ON, cursor OFF*/
#define Display_Cursor_OFF 0x0C


/*6- Defining the Entry mode */
#define Entry_mode 0x06

/*7- Defining the 8 bit mode */
#define Eight_bit_mode 0x38





/*8- Defining the control pins */
#define Enable_pin 3

#define ReadWrite_pin 2

#define RegisterSelect_pin 1




#endif // LCD_CONFIGURATION_H_
