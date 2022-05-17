#include "tm4c123gh6pm.h"
#include "LED.h"
#include "Macros.h"
#include "GPIO.h"
#include "LCD.h"
#include "keypad.h"
#include "timer.h"
#include "Button.h"
#include "LCD_Configuration.h"

unsigned char keypadinput;

unsigned int Minutes,Seconds;
float time;
unsigned char x;

char caseA[] ="PopCorn";
char caseB[] ="Beef weight?";
char caseC[] ="Chicken weight?";
char error[] = "Err";



int main() {

Port_init('A');
Port_init('E');
Port_init('D');
Port_init('F');
Port_init('B');

BUTTON_INIT_PULLUP('F',0);
BUTTON_INIT_PULLUP('F',4);
BUTTON_INIT_PULLUP('E',5);

LCD_Int();

KEYPAD_INIT();

SysTick_Wait();

LED_INIT('F',1);
LED_INIT('F',2);
LED_INIT('F',3);

while(1){
keypadinput = KEYPAD_READ();

LCD_clearScreen();

switch(keypadinput){
	case 'A': LCD_Send_string(caseA);
	genericdelay(2000,0);
	Minutes =01;Seconds = 00;

	while((GPIO_PORTF_DATA_R &0x01 == 1)||(GPIO_PORTE_DATA_R &0x20 == 0));

	while(1){

            LED_ON('F',1);
            LED_ON('F',2);
            LED_ON('F',3);

            if((GPIO_PORTF_DATA_R &0x10 == 0) ||(GPIO_PORTE_DATA_R &0x20 == 1 )){


            }

            LCD_clearScreen();
            cursor_move(1,1);
            LCD_Send_character(Minutes);
            cursor_move(1,3);
            LCD_Send_character(':');
            cursor_move(1,4);
            LCD_Send_character(Seconds);

            genericdelay(1000,0);
            if(Seconds !=00){
                Seconds--;
            }
            if(Seconds==0 && Minutes !=0){
                Seconds =59;
                Minutes--;
            }
            if(Seconds ==0 && Minutes ==0){
                    for(int i=0;i<3;i++)
                    {
                        GPIO_PORTF_DATA_R ^= 0x0E;
                    }
                        GPIO_PORTF_DATA_R &= ~(0x0E);

                    break;}

	}break;

	case 'B': LCD_Send_string(caseB);
              genericdelay(2000,0);
               x =KEYPAD_READ();

              while(1){
                if (isdigit(x)&& x!=0){
                    break;
                }
                else LCD_Send_string(error);
                     genericdelay(2000,0);
              }

               time = x * 0.5;
              Minutes = (int) time;
              Seconds = (time - Minutes)*60;
              LCD_clearScreen();
              cursor_move(1,1);
              LCD_Send_character(Minutes);
              cursor_move(1,3);
              LCD_Send_character(':');
              cursor_move(1,4);
              LCD_Send_character(Seconds);
              genericdelay(2000,0);

    while(1){

            LED_ON('F',1);
            LED_ON('F',2);
            LED_ON('F',3);

            LCD_clearScreen();
            cursor_move(1,1);
            LCD_Send_character(Minutes);
            cursor_move(1,3);
            LCD_Send_character(':');
            cursor_move(1,4);
            LCD_Send_character(Seconds);
            genericdelay(1000,0);

            if(Seconds !=00){
                Seconds--;
            }
            if(Seconds==0 && Minutes !=0){
                Seconds =59;
                Minutes--;
            }
            if(Seconds ==0 && Minutes ==0){
                    for(int i=0;i<3;i++)
                    {
                        GPIO_PORTF_DATA_R ^= 0x0E;
                    }
                        GPIO_PORTF_DATA_R &= ~(0x0E);

                    break;}

	}break;

	case 'C': LCD_Send_string(caseC);
              genericdelay(2000,0);
               x =KEYPAD_READ();

              while(1){
                if (isdigit(x)&& x!=0){
                    break;
                }
                else LCD_Send_string(error);
                     genericdelay(2000,0);
              }

               time = x * 0.5;
              Minutes = (int) time;
              Seconds = (time - Minutes)*60;
              LCD_clearScreen();
              cursor_move(1,1);
              LCD_Send_character(Minutes);
              cursor_move(1,3);
              LCD_Send_character(':');
              cursor_move(1,4);
              LCD_Send_character(Seconds);
              genericdelay(2000,0);

    while(1){

            LED_ON('F',1);
            LED_ON('F',2);
            LED_ON('F',3);

            LCD_clearScreen();
            cursor_move(1,1);
            LCD_Send_character(Minutes);
            cursor_move(1,3);
            LCD_Send_character(':');
            cursor_move(1,4);
            LCD_Send_character(Seconds);
            genericdelay(1000,0);

            if(Seconds !=00){
                Seconds--;
            }
            if(Seconds==0 && Minutes !=0){
                Seconds =59;
                Minutes--;
            }
            if(Seconds ==0 && Minutes ==0){

                    for(int i=0;i<3;i++)
                    {
                        GPIO_PORTF_DATA_R ^= 0x0E;
                    }
                        GPIO_PORTF_DATA_R &= ~(0x0E);

                    break;}

	}break;








}

}
}
