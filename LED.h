#ifndef LED_H_
#define LED_H_

//.h file for LED

void LED_INIT (unsigned char Portname ,unsigned char Pinnumber);

void LED_ON (unsigned char Portname,unsigned char Pinnumber);

void LED_OFF (unsigned char Portname,unsigned char Pinnumber);

void LED_TOG (unsigned char Portname,unsigned char Pinnumber);

#endif
