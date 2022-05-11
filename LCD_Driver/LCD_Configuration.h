#ifndef LCD_CONFIGURATION_H_INCLUDED
#define LCD_CONFIGURATION_H_INCLUDED

/* 1- Defining the data port*/
#define Data_Port 'B'

/*2- Defining the control port (Enable - Read Write - Register select)*/
#define Control_Port 'D'




/* 3- Clear display screen*/
#define Clear_Screen 0x01

/*4- Display ON, cursor OFF*/
#define Display_ON 0x0C

/*5- Defining the Entry mode */
#define Entry_mode 0x06

/*6- Defining the 8 bit mode */
#define Eight_bit_mode 0x38



/*7- Defining the control pins */
#define Enable_pin 0

#define ReadWrite_pin 1

#define RegisterSelect_pin 2

















#endif // LCD_CONFIGURATION_H_INCLUDED
