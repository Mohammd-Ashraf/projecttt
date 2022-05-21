#include <stdio.h>
#include <stdlib.h>

int main()
{

Case('D');        /*If D is pushed on the keypad, the words “Cooking Time?” should appear on the LCD.*/

int num1 =0 , num2 =0 ;
int num3 =0 , num4 =0 ;


cursor_move(1 ,1);
LCD_Send_string('Cooking Time?');
genericdelay(2000, 0);
LCD_clearScreen();

num1= KEYPAD_READ();   /*After that the user can enter a value between 1 and 30 to indicate the cooking time required in minutes and seconds.*/
cursor_move(1 ,1);
LCD_Send_string('00:0');
cursor_move(1 ,5);
LCD_Send_character(num1);


num2= KEYPAD_READ();
cursor_move(1 ,1);
LCD_Send_string('00:');
cursor_move(1 ,4);
LCD_Send_character(num1);
cursor_move(1 ,5);
LCD_Send_character(num2);


num3= KEYPAD_READ();
cursor_move(1 ,1);
LCD_Send_character('0');
cursor_move(1 ,2);
LCD_Send_character(num1);
cursor_move(1 ,3);
LCD_Send_character(':');
cursor_move(1 ,3);
LCD_Send_character(num2);
cursor_move(1 ,4);
LCD_Send_character(num3);



num4= KEYPAD_READ();
cursor_move(1 ,1);
LCD_Send_character(num1);
cursor_move(1 ,2);
LCD_Send_character(num2);
cursor_move(1 ,3);
LCD_Send_character(':');
cursor_move(1 ,4);
LCD_Send_character(num3);
cursor_move(1 ,5);
LCD_Send_character(num4);





}
