#include "GPIO.h"
#include "TIMER.h"
#include "tm4c123gh6pm.h"


unsigned char arr[4][4] = {                 //better outside the function
				{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
				{'*', '0', '#', 'D'}
														};

														
 void KEYPAD_INIT(void){
	Port_init('A');                           // init Port A for col
  Port_init('D');                           // init Port D for rows
  PORT_DIR('D',0x00);                       // rows >>>> input
  PORT_DIR('A',0xF0);       								// col  >>>> output
	GPIO_PORTD_PDR_R |= 0x0F;									// Pull Down (rows)
	 GPIO_PORTD_DATA_R &= 0x0F;               // ??
	 GPIO_PORTA_DATA_R &= 0XF0;               // ??
}


														
unsigned char KEYPAD_READ(void){
	
	
	int i,j;
  while(1)
  {
    for(i = 0; i < 4; i++)   								 // Scan columns
    {
      PORT_WRITE('A',(1U << (i+4)));         // passing 1 through colums 
			genericdelay(2,1);       							 // delay 2us
			
       for( j = 0; j < 4; j++)  						 // Scan rows
      {
        if((PORT_READ('D') & 0x0F) & (1U << (j))){         // check if any key is pressed
          GPIO_PORTD_DATA_R &= (~0X0F);										 // clear Port D (lowerbits)
          GPIO_PORTA_DATA_R &= (~0XF0);										 // clear Port A (upperbits)
					return arr[j][i];}
      }
    }
  }
	return 0xFF;
}
