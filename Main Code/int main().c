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



LCD_Int();

KEYPAD_INIT();

SysTick_Wait();



while(1){
keypadinput = KEYPAD_READ();

LCD_clearScreen();

switch(keypadinput){

			case 'A':

				LCD4bits_Cmd(0x01);
				LCD_WriteString(caseA);
				delayMs(500);


				while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));

				GPIO_PORTF_DATA_R |= 0x0E;

				counter(1,'A');

				for(i=0;i<=4;i++){
				GPIO_PORTF_DATA_R ^= (0x0E);
				GPIO_PORTE_DATA_R ^= 0x02;
				genericdelay(500,0);
				}

				GPIO_PORTE_DATA_R |= 0x02;
				GPIO_PORTF_DATA_R &= ~(0x0E);
				LCD4bits_Cmd(0x01);

			break;

			case 'B':

				CaseBStart:
				LCD4bits_Cmd(0x01);
				LCD_WriteString(caseB);
        genericdelay(1000,0);
        Kilos =KEYPAD_READ();


        while(1){

					if (isdigit(Kilos)&& Kilos!='0'){
						LCD4bits_Cmd(0x01);
						LCD4bits_Data(Kilos);
						LCD_WriteString(" Kg");
						genericdelay(2000,0);
						while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));
						GPIO_PORTF_DATA_R |= 0x0E;
						counter((Kilos-48)*0.5,'B');
						for(i=0;i<=4;i++){
								GPIO_PORTF_DATA_R ^= (0x0E);
								GPIO_PORTE_DATA_R ^= 0x02;
								genericdelay(500,0);
						}
						GPIO_PORTE_DATA_R |= 0x02;
						GPIO_PORTF_DATA_R &= ~(0x0E);
            break;
                }
            else LCD4bits_Cmd(0x01);
								LCD_WriteString(error);
                genericdelay(1500,0);
								LCD4bits_Cmd(0x01);
								goto CaseBStart;
              }
			 break;


				case 'C':

					CaseCStart:
					LCD4bits_Cmd(0x01);
					LCD_WriteString(caseC);
          genericdelay(1000,0);
          Kilos =KEYPAD_READ();


          while(1){

             if (isdigit(Kilos)&& Kilos!='0'){
						  LCD4bits_Cmd(0x01);
							LCD4bits_Data(Kilos);
							LCD_WriteString(" Kg");
							genericdelay(2000,0);
							while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));
							GPIO_PORTF_DATA_R |= 0x0E;
							counter((Kilos-48)*0.2,'C');
							for(i=0;i<=4;i++){
								GPIO_PORTF_DATA_R ^= (0x0E);
								GPIO_PORTE_DATA_R ^= 0x02;
								genericdelay(500,0);
								}
							GPIO_PORTE_DATA_R |= 0x02;
							GPIO_PORTF_DATA_R &= ~(0x0E);
             break;
              }
              else LCD4bits_Cmd(0x01);
									LCD_WriteString(error);
                  genericdelay(1500,0);
									LCD4bits_Cmd(0x01);
									goto CaseCStart;
              }
					 LCD4bits_Cmd(0x01);
					 break;



			case  'D':      /*If D is pushed on the keypad, the words “Cooking Time?” should appear on the LCD.*/

			  cookingtime:
				LCD4bits_Cmd(0x01);
				LCD_WriteString(" Cooking Time?");
				genericdelay(1000, 0);

				num1= KEYPAD_READ();                                //After that the user can enter a value between 1 and 30
				if (num1 >= '3' || num1<'0') {
				LCD4bits_Cmd(0x01);
				LCD_WriteString("   Not valid");
				genericdelay(1000, 0);
				goto cookingtime;
				}
				LCD4bits_Cmd(clear_display);												//to indicate the cooking time required in minutes and seconds.*/
				genericdelay(200, 0);
				LCD_WriteString("--:-");
				LCD4bits_Data(num1);

				num2= KEYPAD_READ();
				if (!(isdigit(num2)) ) {
				LCD4bits_Cmd(0x01);
				LCD_WriteString("   Not valid");
				genericdelay(1000, 0);
				goto cookingtime;
				}
				LCD4bits_Cmd(clear_display);
				genericdelay(200, 0);
				LCD_WriteString("--:");
				LCD4bits_Data(num1);
				LCD4bits_Data(num2);


				num3= KEYPAD_READ();
				if (!(isdigit(num3)) || num3 > '5' ) {
				LCD4bits_Cmd(0x01);
				LCD_WriteString("   Not valid");
				genericdelay(1000, 0);
				goto cookingtime;
				}
				LCD4bits_Cmd(clear_display);
				genericdelay(200, 0);
				LCD4bits_Data('-');
				LCD4bits_Data(num1);
				LCD4bits_Data(':');
				LCD4bits_Data(num2);
				LCD4bits_Data(num3);



				num4= KEYPAD_READ();
				if (!(isdigit(num4))) {
				LCD4bits_Cmd(0x01);
				LCD_WriteString("   Not valid");
				genericdelay(1000, 0);
				goto cookingtime;
				}
				LCD4bits_Cmd(clear_display);
				genericdelay(200, 0);
				LCD4bits_Data(num1);
				LCD4bits_Data(num2);
				LCD4bits_Data(':');
				LCD4bits_Data(num3);
				LCD4bits_Data(num4);
				genericdelay(1000, 0);




				while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));
				GPIO_PORTF_DATA_R |= 0x0E;
				Dcounter(num1-48,num2-48,num3-48,num4-48);
				for(i=0;i<=4;i++){
						GPIO_PORTF_DATA_R ^= (0x0E);
  					GPIO_PORTE_DATA_R ^= 0x02;
						genericdelay(500,0);
						}
				GPIO_PORTF_DATA_R &= ~(0x0E);
				GPIO_PORTE_DATA_R |= 0x02;

				LCD4bits_Cmd(0x01);
			 break;


}
}
}

}


