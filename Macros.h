  /******************************************************************************
 *
 * Module:  Macros
 *
 * File Name: Macros.h
 *
 * Description: Commonly Used Macros
 *
 * Author: Hussam Eldin Wael
 *
 *******************************************************************************/


#ifndef MACROS_H_
#define MACROS_H_


/* 1- Set a bit to 1 in a register.*/
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))

/*2- Clear a bit to 0 in a register.*/
#define CLEAR_BIT(REG , BIT) (REG &=~(1<<BIT))

/*3-Toggle a bit in a register.*/
#define TOGGLE_BIT(REG , BIT) (REG ^= (1<<BIT))

/*4- Write a logic value to a bit in a register.*/
#define WRITE_BIT(REG , BIT , VAL){\
	switch(VAL) {\
	case 0 : CLEAR_BIT(REG , BIT); break; \
	case 1: SET_BIT(REG , BIT); } }

/*5- Checks if a bit is set to 1 in a register, returns 1 in that case and 0 in the other case.*/
#define BIT_IS_SET(REG ,BIT) (REG & (1<<BIT))

/*6- Checks if a bit is cleared to 0 in a register, returns 1 in that case and 0 in the other case.*/
#define BIT_IS_CLEAR(REG ,BIT) !(BIT_IS_SET(REG , BIT))


/*7- Gets the value of the bit in a register (1 or 0).*/
#define GET_BIT(REG , BIT) BIT_IS_SET(REG , BIT)?1:0

#define READ_BIT(REG,BIT) (REG &=(1<<BIT))>>BIT






#endif /* MACROS_H_ */
