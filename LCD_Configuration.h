#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_



/* 1- Defining the data port*/
#define Data_Port 'B'

/*2- Defining the control port (Enable - Read Write - Register select)*/
#define Control_Port 'E'




/* 3- Clear display screen*/
#define Clear_Screen 0x01

/*4- Display ON, cursor ON*/
#define Display_ON_Cursor_ON 0x0E


/*5- Display ON, cursor OFF*/
#define Display_ON_Cursor_OFF 0x0C

/*6- Display ON, Blinking*/
#define Display_ON_Cursor_blink 0x0F

/*7- Defining the Entry mode */
#define Entry_mode 0x06

/*8- Defining the 8 bit mode */
#define Eight_bit_mode 0x38

/*9- Return Home */
#define Return_Home 0x02


/*10- Defining the control pins */
#define Enable_pin 2

#define ReadWrite_pin 1

#define RegisterSelect_pin 0




#endif // LCD_CONFIGURATION_H_
