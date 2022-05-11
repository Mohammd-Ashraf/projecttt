#ifndef GPIO_H_
#define GPIO_H_

//.h file for GPIO

void Port_init(unsigned char Portname);

/*initializes the port clock and unlocks it if it's locked and enables digital
(as we're only using digital i/o in this project)*/

void PIN_DIR(unsigned char Portname , unsigned char Pinnumber,unsigned char direction);

//specifies the direction of a specific pin (whether it's i/p or o/p)

void PORT_DIR(unsigned char Portname,unsigned char direction);

//specifies the direction of a whole port(whether it's i/p or o/p)

void PIN_WRITE(unsigned char Portname,unsigned char Pinnumber,unsigned char data);

//to write on 1 specific bit only

void PORT_WRITE(unsigned char Portname,unsigned char data);

//write on the whole port(write a character for example)

unsigned char PIN_READ(unsigned char Portname,unsigned char Pinnumber);

//reads the value on 1 specific pin only

unsigned char PORT_READ(unsigned char Portname);

//reads the value written on a whole port(character for example)

void PIN_TOGGLE(unsigned char Portname,unsigned char Pinnumber);

//to toggle a specific pin

void PIN_PUR(unsigned char Portname,unsigned char Pinnumber,unsigned char activation);

//to activate or deactivate the PUR for a specific Pin

void WRITE_UPPERBITs(unsigned char Portname,unsigned char data);

//to write in the Most significant 4 bits of the data register

void WRITE_LOWERBITS(unsigned char Portname,unsigned char data);

//to write in the least significant 4 bits of the data register


