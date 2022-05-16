#include "GPIO.h"
#include "TIMER.h"
#include "tm4c123gh6pm.h"


unsigned char arr[4][4] = {
				{'1', '2', '3', 'A'},
				{'4', '5', '6', 'B'},
				{'7', '8', '9', 'C'},
				{'*', '0', '#', 'D'}
														};

														
 void KEYPAD_INIT(void){
	Port_init('A');
  Port_init('D');
  PORT_DIR('D',0x00);
  PORT_DIR('A',0xF0);
	GPIO_PORTD_PDR_R |= 0x0F;
	 GPIO_PORTD_DATA_R &= 0x0F;
	 GPIO_PORTA_DATA_R &=0XF0;
}


														
unsigned char KEYPAD_READ(void){
	
	
	int i,j;
  while(1)
  {
    for(i = 0; i < 4; i++)    //Scan columns loop
    {
      PORT_WRITE('A',(1U << (i+4)));
			genericdelay(2,1);
       for( j = 0; j < 4; j++)  //Scan rows
      {
        if((PORT_READ('D') & 0x0F) & (1U << (j))){
          GPIO_PORTD_DATA_R &= (~0X0F);
          GPIO_PORTA_DATA_R &= (~0XF0);
					return arr[j][i];}
      }
    }
  }
	return 0xFF;
}
