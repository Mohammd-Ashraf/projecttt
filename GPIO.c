#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "macros.h"



void Port_init(unsigned char Portname){  //initialize the port
	switch(toupper(Portname)){
		case 'A':
			SYSCTL_RCGCGPIO_R |= 0x01;
            while((SYSCTL_PRGPIO_R &=0x01)==0);
			GPIO_PORTA_LOCK_R = 0x4C4F434B ;
			GPIO_PORTA_CR_R |= 0xFF;
			GPIO_PORTA_DEN_R |= 0xFF;
			GPIO_PORTA_AFSEL_R = 0x00;
			GPIO_PORTA_PCTL_R = 0;

	break;

		case 'B':
			SYSCTL_RCGCGPIO_R |= 0x02;
            while((SYSCTL_PRGPIO_R &=0x02)==0);
			GPIO_PORTB_LOCK_R = 0x4C4F434B ;
			GPIO_PORTB_CR_R |= 0xFF;
			GPIO_PORTB_DEN_R |= 0xFF;
			GPIO_PORTB_AFSEL_R = 0x00;
			GPIO_PORTB_PCTL_R = 0;
	break;

		case 'C':
			SYSCTL_RCGCGPIO_R |= 0x04;
            while((SYSCTL_PRGPIO_R &=0x04)==0);
			GPIO_PORTC_LOCK_R = 0x4C4F434B ;
			GPIO_PORTC_CR_R |= 0xFF;
			GPIO_PORTC_DEN_R |= 0xFF;
			GPIO_PORTC_AFSEL_R = 0x00;
			GPIO_PORTC_PCTL_R = 0;
	break;

		case 'D':
			SYSCTL_RCGCGPIO_R |= 0x08;
            while((SYSCTL_PRGPIO_R &=0x08)==0);
			GPIO_PORTD_LOCK_R = 0x4C4F434B ;
			GPIO_PORTD_CR_R |= 0xFF;
			GPIO_PORTD_DEN_R |= 0xFF;
			GPIO_PORTD_AFSEL_R = 0x00;
			GPIO_PORTD_PCTL_R = 0;
	break;

		case 'E':
			SYSCTL_RCGCGPIO_R |= 0x10;
            while((SYSCTL_PRGPIO_R &=0x10)==0);
			GPIO_PORTE_LOCK_R = 0x4C4F434B ;
			GPIO_PORTE_CR_R |= 0xFF;
			GPIO_PORTE_AFSEL_R = 0x00;
			GPIO_PORTE_PCTL_R = 0;
	break;

		case 'F':
			SYSCTL_RCGCGPIO_R |= 0x20;
            while((SYSCTL_PRGPIO_R &=0x20)==0);
			GPIO_PORTF_LOCK_R = 0x4C4F434B ;
			GPIO_PORTF_CR_R |= 0xFF;
			GPIO_PORTF_DEN_R |= 0xFF;
			GPIO_PORTF_AFSEL_R = 0x00;
			GPIO_PORTF_PCTL_R = 0;
	break;
}
}


void PIN_DIR(unsigned char Portname , unsigned char Pinnumber,unsigned char direction){  //specify the dir of a pin

switch(toupper(Portname)){
    case 'A': if(direction==1){
       SET_BIT(GPIO_PORTA_DIR_R,Pinnumber);
       //GPIO_PORTA_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTA_DIR_R,Pinnumber);
        //GPIO_PORTA_DIR_R &= ~(1<<Pinnumber);
        break;

      case 'B': if(direction==1){
       SET_BIT(GPIO_PORTB_DIR_R,Pinnumber);
       //GPIO_PORTB_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTB_DIR_R,Pinnumber);
        //GPIO_PORTB_DIR_R &= ~(1<<Pinnumber);
            break;

          case 'C': if(direction==1){
       SET_BIT(GPIO_PORTC_DIR_R,Pinnumber);
       //GPIO_PORTC_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTC_DIR_R,Pinnumber);
        //GPIO_PORTC_DIR_R &= ~(1<<Pinnumber);
            break;

       case 'D': if(direction==1){
       SET_BIT(GPIO_PORTD_DIR_R,Pinnumber);
       //GPIO_PORTD_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTD_DIR_R,Pinnumber);
        //GPIO_PORTD_DIR_R &= ~(1<<Pinnumber)
            break;

        case 'E': if(direction==1){
       SET_BIT(GPIO_PORTE_DIR_R,Pinnumber);
       //GPIO_PORTE_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTE_DIR_R,Pinnumber);
        //GPIO_PORTE_DIR_R &= ~(1<<Pinnumber)
            break;

        case 'F': if(direction==1){
       SET_BIT(GPIO_PORTF_DIR_R,Pinnumber);
       //GPIO_PORTF_DIR_R |= (direction<<Pinnumber);
       }
        else CLEAR_BIT(GPIO_PORTF_DIR_R,Pinnumber);
        //GPIO_PORTF_DIR_R &= ~(1<<Pinnumber)
            break;

}

}

void PORT_DIR(unsigned char Portname,unsigned char direction){  //specify the DIR of aport
    switch(toupper(Portname)){
        case 'A': GPIO_PORTA_DIR_R = direction;
                break;
        case 'B': GPIO_PORTB_DIR_R = direction;
                break;
        case 'C': GPIO_PORTC_DIR_R = direction;
                break;
        case 'D': GPIO_PORTD_DIR_R = direction;
                break;
        case 'E': GPIO_PORTE_DIR_R = direction;
                break;
        case 'F': GPIO_PORTF_DIR_R = direction;
                break;


    }
}


void PIN_WRITE(unsigned char Portname,unsigned char Pinnumber,unsigned char data){  //write on a specific Pin
switch(toupper(Portname)){
       case 'A':if(data ==1){
       SET_BIT(GPIO_PORTA_DATA_R,Pinnumber);
       //GPIO_PORTA_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTA_DATA_R,Pinnumber);
       //GPIO_PORTA_DATA_R &= ~(1<<Pinnumber);
        break;

       case 'B':if(data ==1){
       SET_BIT(GPIO_PORTB_DATA_R,Pinnumber);
       //GPIO_PORTB_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTB_DATA_R,Pinnumber);
       //GPIO_PORTB_DATA_R &= ~(1<<Pinnumber);
        break;

        case 'C':if(data ==1){
       SET_BIT(GPIO_PORTC_DATA_R,Pinnumber);
       //GPIO_PORTC_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTC_DATA_R,Pinnumber);
       //GPIO_PORTC_DATA_R &= ~(1<<Pinnumber);
        break;

        case 'D':if(data ==1){
       SET_BIT(GPIO_PORTD_DATA_R,Pinnumber);
       //GPIO_PORTD_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTD_DATA_R,Pinnumber);
       //GPIO_PORTD_DATA_R &= ~(1<<Pinnumber);
        break;

       case 'E':if(data ==1){
       SET_BIT(GPIO_PORTE_DATA_R,Pinnumber);
       //GPIO_PORTE_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTE_DATA_R,Pinnumber);
       //GPIO_PORTE_DATA_R &= ~(1<<Pinnumber);
        break;

        case 'F':if(data ==1){
       SET_BIT(GPIO_PORTF_DATA_R,Pinnumber);
       //GPIO_PORTF_DATA_R |= (data<<Pinnumber);
       }
       else CLEAR_BIT(GPIO_PORTF_DATA_R,Pinnumber);
       //GPIO_PORTF_DATA_R &= ~(1<<Pinnumber);
        break;
       }
       }



void PORT_WRITE(unsigned char Portname,unsigned char data){   //write on the whole port
    switch(toupper(Portname)){
        case 'A': GPIO_PORTA_DATA_R = data;
                break;
        case 'B': GPIO_PORTB_DATA_R = data;
                break;
        case 'C': GPIO_PORTC_DATA_R = data;
                break;
        case 'D': GPIO_PORTD_DATA_R = data;
                break;
        case 'E': GPIO_PORTE_DATA_R = data;
                break;
        case 'F': GPIO_PORTF_DATA_R = data;
                break;

    }
}

unsigned char PIN_READ(unsigned char Portname,unsigned char Pinnumber){ //read from one pin only
    switch(toupper(Portname)){
    case 'A': return READ_BIT(GPIO_PORTA_DATA_R,Pinnumber);
    case 'B': return READ_BIT(GPIO_PORTB_DATA_R,Pinnumber);
    case 'C': return READ_BIT(GPIO_PORTC_DATA_R,Pinnumber);
    case 'D': return READ_BIT(GPIO_PORTD_DATA_R,Pinnumber);
    case 'E': return READ_BIT(GPIO_PORTE_DATA_R,Pinnumber);
    case 'F': return READ_BIT(GPIO_PORTF_DATA_R,Pinnumber);

			default: return READ_BIT(GPIO_PORTF_DATA_R,Pinnumber);
    }
}

unsigned char PORT_READ(unsigned char Portname){  //read from the whole port(read character)
    switch(toupper(Portname)){
    case 'A': return GPIO_PORTA_DATA_R;
    case 'B': return GPIO_PORTB_DATA_R;
    case 'C': return GPIO_PORTC_DATA_R;
    case 'D': return GPIO_PORTD_DATA_R;
    case 'E': return GPIO_PORTE_DATA_R;
    case 'F': return GPIO_PORTF_DATA_R;

			default: return GPIO_PORTF_DATA_R;

    }

}

void PIN_TOGGLE(unsigned char Portname,unsigned char Pinnumber){  //toggle a specific pin
    switch(toupper(Portname)){
        case 'A': TOGGLE_BIT(GPIO_PORTA_DATA_R,Pinnumber);
                //GPIO_PORTA_DATA_R ^= (1<<Pinnumber);
                  break;
        case 'B': TOGGLE_BIT(GPIO_PORTB_DATA_R,Pinnumber);
                //GPIO_PORTB_DATA_R ^= (1<<Pinnumber);
                  break;
        case 'C': TOGGLE_BIT(GPIO_PORTC_DATA_R,Pinnumber);
                //GPIO_PORTC_DATA_R ^= (1<<Pinnumber);
                  break;
        case 'D': TOGGLE_BIT(GPIO_PORTD_DATA_R,Pinnumber);
                //GPIO_PORTD_DATA_R ^= (1<<Pinnumber);
                  break;
        case 'E': TOGGLE_BIT(GPIO_PORTE_DATA_R,Pinnumber);
                //GPIO_PORTE_DATA_R ^= (1<<Pinnumber);
                  break;
        case 'F': TOGGLE_BIT(GPIO_PORTF_DATA_R,Pinnumber);
                  //GPIO_PORTF_DATA_R ^= (1<<Pinnumber);
                  break;
    }



}

void PIN_PUR(unsigned char Portname,unsigned char Pinnumber,unsigned char activation){
    switch(toupper(Portname)){
    case 'A': if(activation == 1){
        SET_BIT(GPIO_PORTA_PUR_R,Pinnumber);
         //GPIO_PORTA_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTA_PUR_R,Pinnumber);
         //GPIO_PORTA_PUR_R &= ~(1<<Pinnumber);
        break;

    case 'B': if(activation == 1){
        SET_BIT(GPIO_PORTB_PUR_R,Pinnumber);
        //GPIO_PORTB_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTB_PUR_R,Pinnumber);
        //GPIO_PORTB_PUR_R &= ~(1<<Pinnumber);
        break;

    case 'C': if(activation == 1){
        SET_BIT(GPIO_PORTC_PUR_R,Pinnumber);
        //GPIO_PORTC_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTC_PUR_R,Pinnumber);
       //GPIO_PORTC_PUR_R &= ~(1<<Pinnumber);
        break;

        case 'D': if(activation == 1){
        SET_BIT(GPIO_PORTD_PUR_R,Pinnumber);
        //GPIO_PORTD_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTD_PUR_R,Pinnumber);
        //GPIO_PORTD_PUR_R &= ~(1<<Pinnumber);
        break;

        case 'E': if(activation == 1){
        SET_BIT(GPIO_PORTE_PUR_R,Pinnumber);
        //GPIO_PORTE_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTE_PUR_R,Pinnumber);
        //GPIO_PORTE_PUR_R &= ~(1<<Pinnumber);
        break;

        case 'F': if(activation == 1){
        SET_BIT(GPIO_PORTF_PUR_R,Pinnumber);
        //GPIO_PORTF_PUR_R |= (1<<Pinnumber);
    }else CLEAR_BIT(GPIO_PORTF_PUR_R,Pinnumber);
        //GPIO_PORTF_PUR_R &= ~(1<<Pinnumber);
        break;
    }

}

void PIN_PDN(unsigned char Portname,unsigned char Pinnumber){
    switch(toupper(Portname)){
         case 'A': SET_BIT(GPIO_PORTA_PDR_R,Pinnumber);
                //GPIO_PORTA_PDR_R |=(1<<Pinnumber);
                  break;
        case 'B': SET_BIT(GPIO_PORTB_PDR_R,Pinnumber);
                //GPIO_PORTB_PDR_R |=(1<<Pinnumber);
                  break;
        case 'C': SET_BIT(GPIO_PORTC_PDR_R,Pinnumber);
                //GPIO_PORTC_PDR_R |=(1<<Pinnumber);
                  break;
        case 'D': SET_BIT(GPIO_PORTD_PDR_R,Pinnumber);
                //GPIO_PORTD_PDR_R |=(1<<Pinnumber);
                  break;
        case 'E': SET_BIT(GPIO_PORTE_PDR_R,Pinnumber);
                //GPIO_PORTE_PDR_R |=(1<<Pinnumber);
                  break;
        case 'F': SET_BIT(GPIO_PORTF_PDR_R,Pinnumber);
                //GPIO_PORTF_PDR_R |=(1<<Pinnumber);
                  break;

    }



}

void WRITE_UPPERBITs(unsigned char Portname,unsigned char data){ //write in the 4 upperbits only of the data register
    data <<= 4;
    switch(toupper(Portname)){
        case 'A': GPIO_PORTA_DATA_R &= 0x0F;
                  GPIO_PORTA_DATA_R |= data;
                  break;

        case 'B': GPIO_PORTB_DATA_R &= 0x0F;
                  GPIO_PORTB_DATA_R |= data;
                  break;

        case 'C': GPIO_PORTC_DATA_R &= 0x0F;
                  GPIO_PORTC_DATA_R |= data;
                  break;

        case 'D': GPIO_PORTD_DATA_R &= 0x0F;
                  GPIO_PORTD_DATA_R |= data;
                  break;

        case 'E': GPIO_PORTE_DATA_R &= 0x0F;
                  GPIO_PORTE_DATA_R |= data;
                  break;

        case 'F': GPIO_PORTF_DATA_R &= 0x0F;
                  GPIO_PORTF_DATA_R |= data;
                  break;

    }

}

void WRITE_LOWERBITS(unsigned char Portname,unsigned char data){   //write in the 4 lowerbits only of the data register
    switch(toupper(Portname)){
        case 'A': GPIO_PORTA_DATA_R &= 0xF0;
                  GPIO_PORTA_DATA_R |= data;
                  break;
        case 'B': GPIO_PORTB_DATA_R &= 0xF0;
                  GPIO_PORTB_DATA_R |= data;
                  break;
        case 'C': GPIO_PORTC_DATA_R &= 0xF0;
                  GPIO_PORTC_DATA_R |= data;
                  break;
        case 'D': GPIO_PORTD_DATA_R &= 0xF0;
                  GPIO_PORTD_DATA_R |= data;
                  break;
        case 'E': GPIO_PORTE_DATA_R &= 0xF0;
                  GPIO_PORTE_DATA_R |= data;
                  break;
        case 'F': GPIO_PORTF_DATA_R &= 0xF0;
                  GPIO_PORTF_DATA_R |= data;
                  break;

    }

}

