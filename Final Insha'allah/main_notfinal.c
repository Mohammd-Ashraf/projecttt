//some defines for the LCD
#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80
#include "TM4C123.h"    // Device header
#include "tm4c123gh6pm.h"
#include <ctype.h>
#define LCD GPIOB    		//LCD port with Tiva C
#define RS 0x01				 	//RS -> PB0 (0x01)
#define RW 0x02         //RW -> PB1 (0x02)
#define EN 0x04  		 	 	//EN -> PB2 (0x04)


//Functions Declaration
void delayUs(int);   														   //Delay in Micro Seconds
void delayMs(int);   														   //Delay in Milli Seconds
void LCD4bits_Init(void);													 //Initialization of LCD Dispaly
void LCD_Write4bits(unsigned char, unsigned char); //Write data as (4 bits) on LCD
void LCD_WriteString(char*);											 //Write a string on LCD
void LCD4bits_Cmd(unsigned char);									 //Write command
void LCD4bits_Data(unsigned char);								 //Write a character



void LCD4bits_Init(void)
{
	SYSCTL->RCGCGPIO |= 0x02;    //enable clock for PORTB
	delayMs(10);                 //delay 10 ms for enable the clock of PORTB
  LCD->DIR = 0xFF;             //let PORTB as output pins
	LCD->DEN = 0xFF;             //enable PORTB digital IO pins
	LCD4bits_Cmd(0x28);          //2 lines and 5x7 character (4-bit data, D4 to D7)
	LCD4bits_Cmd(0x06);          //Automatic Increment cursor (shift cursor to right)
	LCD4bits_Cmd(0x01);					 //Clear display screen
	LCD4bits_Cmd(0x0C);          //Display on, cursor blinking
}


void LCD_Write4bits(unsigned char data, unsigned char control)
{
	data &= 0xF0;                       //clear lower nibble for control
	control &= 0x0F;                    //clear upper nibble for data
	LCD->DATA = data | control;         //Include RS value (command or data ) with data
	LCD->DATA = data | control | EN;    //pulse EN
	delayUs(0);													//delay for pulsing EN
	LCD->DATA = data | control;					//Turn off the pulse EN
	LCD->DATA = 0;                      //Clear the Data
}

void LCD_WriteString(char * str)
{
	volatile int i = 0;          //volatile is important

	while(*(str+i) != '\0')       //until the end of the string
	{
		LCD4bits_Data(*(str+i));    //Write each character of string
		i++;                        //increment for next character
	}
}

void LCD4bits_Cmd(unsigned char command)
{
	LCD_Write4bits(command & 0xF0 , 0);    //upper nibble first
	LCD_Write4bits(command << 4 , 0);			 //then lower nibble

	if(command < 4)
		delayMs(2);       //commands 1 and 2 need up to 1.64ms
	else
		delayUs(40);      //all others 40 us
}

void LCD4bits_Data(unsigned char data)
{
	LCD_Write4bits(data & 0xF0 , RS);   //upper nibble first
	LCD_Write4bits(data << 4 , RS);     //then lower nibble
	delayUs(40);												//delay for LCD (MCU is faster than LCD)
}

void delayMs(int n)
{
	volatile int i,j;             //volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)         //delay for 1 msec
		{}
}

void delayUs(int n)
{
	volatile int i,j;							//volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)            //delay for 1 micro second
		{}
}






void PortF_init(void){                             //LED & buttons

	SYSCTL_RCGCGPIO_R |= 0x20;
            while((SYSCTL_PRGPIO_R &=0x20)==0);
			GPIO_PORTF_LOCK_R = 0x4C4F434B ;
			GPIO_PORTF_CR_R |= 0xFF;
			GPIO_PORTF_DEN_R |= 0xFF;
			GPIO_PORTF_AFSEL_R = 0x00;
			GPIO_PORTF_AMSEL_R = 0x00;
			GPIO_PORTF_PCTL_R = 0;
			GPIO_PORTF_DIR_R |= 0x0E;
			GPIO_PORTF_PUR_R |= 0x11;
}






void PortA_init(void){                                // A 4 5 6 7 >>> cols out

	SYSCTL_RCGCGPIO_R |= 0x01;
            while((SYSCTL_PRGPIO_R &=0x01)==0);
			GPIO_PORTA_LOCK_R = 0x4C4F434B ;
			GPIO_PORTA_CR_R |= 0xFF;
			GPIO_PORTA_DEN_R |= 0xFF;
			GPIO_PORTA_AFSEL_R = 0x00;
			GPIO_PORTA_PCTL_R = 0;
			GPIO_PORTA_DIR_R |= 0xF0;
}


void PortD_init(void){                                // D 0 1 2 3 >>> rows input
	SYSCTL_RCGCGPIO_R |= 0x08;
            while((SYSCTL_PRGPIO_R &=0x08)==0);
			GPIO_PORTD_LOCK_R = 0x4C4F434B ;
			GPIO_PORTD_CR_R |= 0xFF;
			GPIO_PORTD_DEN_R |= 0xFF;
			GPIO_PORTD_AFSEL_R = 0x00;
			GPIO_PORTD_AMSEL_R = 0x00;
			GPIO_PORTD_PCTL_R = 0;
			GPIO_PORTD_DIR_R |= 0x00;
}


void PortE_init(void){
	SYSCTL_RCGCGPIO_R |= 0x10;
            while((SYSCTL_PRGPIO_R &=0x10)==0);
			GPIO_PORTE_LOCK_R = 0x4C4F434B ;
			GPIO_PORTE_CR_R |= 0xFF;
			GPIO_PORTE_DEN_R |= 0xFF;
			GPIO_PORTE_AFSEL_R = 0x00;
			GPIO_PORTE_AMSEL_R = 0x00;
			GPIO_PORTE_PCTL_R = 0;
			GPIO_PORTE_DIR_R |= 0x08;        //button E0,Buzzer E1
			GPIO_PORTE_PUR_R |= 0x01;
}

void SysTick_Wait(void){
		NVIC_ST_CTRL_R = 0x00;
		NVIC_ST_RELOAD_R = 0x00FFFFFF;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R = 0x05 ;
}

void wait1ms(void){
		NVIC_ST_RELOAD_R = 0x3E80-1;
		NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R & 0x00010000)==0);
}


void wait1us(void){

        NVIC_ST_RELOAD_R = 0x10-1;
		NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R & 0x00010000)==0);



}

void genericdelay(unsigned long time,unsigned char unit){
	int i;
	if (unit == 0){
	for (i=0; i<time; i++){
		wait1ms();
	}
	}
	else {for (i=0; i<time; i++){
		wait1us();
	}	}
}



unsigned char arr[4][4] = {                 //arr for keypad
				{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
				{'*', '0', '#', 'D'}
														};


 void KEYPAD_INIT(void){
	PortA_init();                             // init Port A for col
  PortD_init();                             // init Port D for rows
	 GPIO_PORTD_PDR_R |= 0x0F;									// Pull Down (rows)
	 GPIO_PORTD_DATA_R &= 0x0F;
}



unsigned char KEYPAD_READ(void){


	int i,j;
  while(1)
  {
    for(i = 0; i < 4; i++)   								 // Scan columns
    {
      GPIO_PORTA_DATA_R = (1U << (i+4));         // passing 1 through colums
			genericdelay(2,1);       							 // delay 2us

       for( j = 0; j < 4; j++)  						 // Scan rows
      {
        if((GPIO_PORTD_DATA_R  & 0x0F) & (1U << (j))){         // check if any key is pressed
          GPIO_PORTD_DATA_R &= (~0X0F);										 // clear Port D (lowerbits)
          GPIO_PORTA_DATA_R &= (~0XF0);										 // clear Port A (upperbits)
					return arr[j][i];}
      }
    }
  }
	return 0xFF;
}
void counter(float time,unsigned char identifier){
	int Minutes=0,Seconds1=0,Seconds2=0;
	float Seconds;
	Minutes =(int) time;
	Seconds = time - Minutes;
	if(identifier == 'A'){
Seconds1 = (int)(Seconds*10);
Seconds2 =(int) (Seconds*100 -Seconds1 *10);
	}
	else if(identifier == 'B' ){
		Seconds = Seconds * 0.6;
	Seconds1 = (int)(Seconds*10) ;
Seconds2 =(int) (Seconds*100 -Seconds1 *10);

	}else if(identifier == 'C'){
				Seconds = Seconds * 0.6;
	Seconds1 = (int)(Seconds*10) ;
Seconds2 =(int) (Seconds*100 -Seconds1 *10);
	}


while(1){


		         if (!(GPIO_PORTF_DATA_R & 0x10)|| !(GPIO_PORTE_DATA_R & 0x01)) {
						   genericdelay(1000,0);
							 while(((GPIO_PORTF_DATA_R & 0x10))  &&((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01)));
							 if(!(GPIO_PORTF_DATA_R & 0x10)){
							 goto stop;

							 }
							 else if((!(GPIO_PORTF_DATA_R & 0x01) )){
							 //|| !(GPIO_PORTE_DATA_R & 0x01))){
							 continue;
							 }
						 }
						LCD4bits_Cmd(0x01);


            LCD4bits_Data((Minutes+48));

            LCD4bits_Data(':');

            LCD4bits_Data(Seconds1+48);
						LCD4bits_Data(Seconds2+48);


            genericdelay(1000,0);
            if(Seconds2 !=00){
                Seconds2--;
            }
						if(Seconds2 ==00 && Seconds1!=0){
						LCD4bits_Cmd(0x01);
						LCD4bits_Data((Minutes+48));
						LCD4bits_Data(':');

						LCD4bits_Data(Seconds1+48);
						LCD4bits_Data(Seconds2+48);
						genericdelay(1000,0);
						Seconds2 =9;
						Seconds1--;

						}
            if(Seconds1==0 && Seconds2 ==0 &&Minutes !=0 ){
                Seconds1 =5;
								Seconds2 =9;
                Minutes--;
            }
            if(Seconds1 ==0 && Seconds2 ==0 && Minutes ==0){
							stop:
                    break;}
}
}


void Dcounter(int num1,int num2,int num3,int num4){


          while(1){
						   if (!(GPIO_PORTF_DATA_R & 0x10)|| !(GPIO_PORTE_DATA_R & 0x01)) {
						   genericdelay(1000,0);
							 while(((GPIO_PORTF_DATA_R & 0x10))  &&((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01)));
							 if(!(GPIO_PORTF_DATA_R & 0x10)){
							 goto end;

							 }
							 else if((!(GPIO_PORTF_DATA_R & 0x01) )){
							 //|| !(GPIO_PORTE_DATA_R & 0x01))){
							 continue;
							 }
						 }



						LCD4bits_Cmd(0x01);
						LCD4bits_Data((num1+48));
						LCD4bits_Data((num2+48));
            LCD4bits_Data(':');
            LCD4bits_Data(num3+48);
						LCD4bits_Data(num4+48);
            genericdelay(1000,0);

						if(num4 !=0){
                num4--;
            }
						if(num4 == 0 && num3 != 0){
						LCD4bits_Cmd(0x01);
						LCD4bits_Data((num1+48));
						LCD4bits_Data((num2+48));
						LCD4bits_Data(':');
						LCD4bits_Data(num3+48);
						LCD4bits_Data(num4+48);
						genericdelay(1000,0);
						num4 =9;
						num3--;

						}
            if(num4==0 && num3 ==0 && num2 !=0 ){
                LCD4bits_Cmd(0x01);
								LCD4bits_Data((num1+48));
								LCD4bits_Data((num2+48));
								LCD4bits_Data(':');
								LCD4bits_Data(num3+48);
								LCD4bits_Data(num4+48);
								genericdelay(1000,0);
								num3 =5;
								num4 =9;
                num2--;
            }
						if(num4==0 && num3 ==0 && num2 ==0 && num1 !=0){
								LCD4bits_Cmd(0x01);
								LCD4bits_Data((num1+48));
								LCD4bits_Data((num2+48));
								LCD4bits_Data(':');
								LCD4bits_Data(num3+48);
								LCD4bits_Data(num4+48);
								genericdelay(1000,0);
								num2=9;
								num3=5;
								num4=9;
								num1--;

						}
            if(num3 ==0 && num4 ==0 && num2 ==0 && num1 ==0){

							end:	break;}





}
}




unsigned char keypadinput;
//int Minutes,Seconds1,Seconds2;
unsigned char Kilos;

char caseA[] ="    PoP-Corn   ";
char caseB[] ="  Beef weight?";
char caseC[] ="Chicken weight?";
char error[] = "     Error  ";
char* str2 = " Press any key ";
int i;

int num1 =0 , num2 =0 ;
int num3 =0 , num4 =0 ;

int main(void){


	char* str = "** Microwave ** ";    //Write any string you want to display on LCD
	LCD4bits_Init();									//Initialization of LCD
	LCD4bits_Cmd(0x01);								//Clear the display
	LCD4bits_Cmd(0x80);               //Force the cursor to beginning of 1st line
	delayMs(500);											//delay 500 ms for LCD (MCU is faster than LCD)
	LCD_WriteString(str);							//Write the string on LCD
	delayMs(1000);											//Delay 500 ms to let the LCD diplays the data
	LCD4bits_Cmd(0x01);								//Clear the display

	PortF_init();
	PortE_init();
	KEYPAD_INIT();
	SysTick_Wait();

	while(1){


			LCD4bits_Cmd(0x80);
			delayMs(500);
			LCD_WriteString(str2);
			keypadinput=KEYPAD_READ();
																									//GPIO_PORTE_DATA_R |= 0x02;

		switch(keypadinput){

			case 'A':

				LCD4bits_Cmd(0x01);
				LCD_WriteString(caseA);
				delayMs(500);


				while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));

				GPIO_PORTF_DATA_R |= 0x0E;

				counter(1,'A');

				for(i=0;i<=3;i++){
				GPIO_PORTF_DATA_R ^= (0x0E);
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
						for(i=0;i<=3;i++){
								GPIO_PORTF_DATA_R ^= (0x0E);
								genericdelay(500,0);
						}
					//	GPIO_PORTE_DATA_R |= 0x02;
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
							for(i=0;i<=3;i++){
								GPIO_PORTF_DATA_R ^= (0x0E);
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
				genericdelay(500, 0);
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
				genericdelay(500, 0);
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
				genericdelay(500, 0);
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
				genericdelay(500, 0);
				LCD4bits_Data(num1);
				LCD4bits_Data(num2);
				LCD4bits_Data(':');
				LCD4bits_Data(num3);
				LCD4bits_Data(num4);
				genericdelay(1000, 0);




				while((GPIO_PORTF_DATA_R & 0x01) || !(GPIO_PORTE_DATA_R & 0x01));
				GPIO_PORTF_DATA_R |= 0x0E;
				Dcounter(num1-48,num2-48,num3-48,num4-48);
				for(i=0;i<=3;i++){
						GPIO_PORTF_DATA_R ^= (0x0E);
						genericdelay(500,0);
						}
				GPIO_PORTF_DATA_R &= ~(0x0E);
				LCD4bits_Cmd(0x01);
			 break;


}
}
}
