#ifndef Button_H_
#define Button_H_

//.h file for Button

void BUTTON_INIT (unsigned char Portname , unsigned char Pinnumber);

unsigned char BUTTON_READ (unsigned char Portname , unsigned char Pinnumber);

void BUTTON_INIT_PULLUP (unsigned char Portname , unsigned char Pinnumber);

#endif
