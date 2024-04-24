/*
 * lab6.c
 *
 * Created: 23/04/2024 11:58:54 a. m.
 * Author : Albert V H
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdarg.h>
#include "comiUART/UART_CONFI.h"


void mensaje();
void escribri_terminal(char caracter);
void setup(void);
void prender_leds(void);
volatile CaracterRx;


int main(void)
{
	setup();
	UART_confi(_fast,_On,_Off,_Off,_b_8,207);
	sei();
	mensaje();
	
    /* Replace with your application code */
    while (1) 
    {
    }
	
}


ISR(USART_RX_vect){
	CaracterRx= UDR0;
	while(!((UCSR0A &(1<<UDRE0))));
	 UDR0= CaracterRx;
	mensaje();
	prender_leds();
}
void escribri_terminal(char caracter){
	while(!((UCSR0A &(1<<UDRE0))));
	UDR0= caracter;
}
void mensaje(){
	escribri_terminal('\n');
	escribri_terminal('I');
	escribri_terminal('N');
	escribri_terminal('G');
	escribri_terminal('R');
	escribri_terminal('E');
	escribri_terminal('S');
	escribri_terminal('E');
	escribri_terminal(' ');
	escribri_terminal('U');
	escribri_terminal('N');
	escribri_terminal(' ');
	escribri_terminal('C');
	escribri_terminal('A');
	escribri_terminal('R');
	escribri_terminal('A');
	escribri_terminal('C');
	escribri_terminal('T');
	escribri_terminal('E');
	escribri_terminal('R');
	escribri_terminal('\n');
	escribri_terminal(10);
	escribri_terminal(13);
}
void setup(void){
	DDRB =0xFF;
	PORTB= 0;
	DDRC =0x03;
	PORTC= 0xF0;
}
void prender_leds(void){
	PORTB=CaracterRx;
	PORTC=((CaracterRx>>6)&0b11)|(0xF0);
}
