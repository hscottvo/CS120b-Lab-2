/*	Author: svo021
 *  Partner(s) Name: Scott Vo
 *	Lab Section:021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure 8 pins of A into inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure 8 pins of B into outputs, initialize to 0s
    /* Insert your solution below */
	unsigned char tmpB = 0x00;
	unsigned char tmpA0 = 0x00;	
	unsigned char tmpA1 = 0x00;

    while (1) {
	// read input
	tmpA0 = PINA & 0x01;
	tmpA1 = (PINA >> 1) & 0x01;
	// computation: if PA0 == 1 -> set PB1PB0 = 01, else = 10
	if (tmpA0 == 0x01 && tmpA1 == 0x00) {
		tmpB = (tmpB & 0xFE) | 0x01;
	}
	else {
		tmpB = (tmpB & 0xFE) | 0x00;
	}
	PORTB = tmpB;
    }
    return 0;
}
