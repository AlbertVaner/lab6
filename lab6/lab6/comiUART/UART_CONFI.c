/*
 * UART_CONFI.c
 *
 * Created: 23/04/2024 12:07:27 p. m.
 *  Author: Albert V H
 */ 
#include "UART_CONFI.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void UART_confi( uint8_t modo,	uint8_t interup_R, uint8_t interup_W, uint8_t sincrono, uint8_t largo_bit, uint16_t valor_baurate){
	// Activar el pin 0 como entrada y el 1 como salida
	DDRD &= ~(1<<DDD0);
	DDRD |= (1<<DDD1);
	UCSR0A= 0;
	// Configurar el modo que se desea
	if(modo==1){
		UCSR0A |=(1<<U2X0); // MODO FAST
	}
	// AQUI SE HABILITA LAS INTERRUPCIONES DE RECIBIR Y LEER
	UCSR0B =0;
	if(interup_R==1){
		UCSR0B |=(1<<RXCIE0);
	}
	if(interup_W==1){
		UCSR0B |=(1<<TXCIE0);
	}
	// AQUÍ SE ACTIVA FORMATO USART
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
	// ACTIVAR EL FRAME 
	if (sincrono==1){
		UCSR0C |=(1<<UMSEL00);
	}
	switch(largo_bit){
			case 0:
				UCSR0C &=~(1<<UCSZ00);
				UCSR0C &=~(1<<UCSZ01);
				UCSR0B &=~(1<<UCSZ02);
				break;
			case 1:
				UCSR0C |=(1<<UCSZ00);
				UCSR0C &=~(1<<UCSZ01);
				UCSR0B &=~(1<<UCSZ02);
				break;
			case 2:
				UCSR0C &=~(1<<UCSZ00);
				UCSR0C |=(1<<UCSZ01);
				UCSR0B &=~(1<<UCSZ02);
				break;
			case 3:
				UCSR0C |=(1<<UCSZ00);
				UCSR0C |=(1<<UCSZ01);
				UCSR0B &=~(1<<UCSZ02);
				break;
			case 4:
				UCSR0C |=(1<<UCSZ00);
				UCSR0C |=(1<<UCSZ01);
				UCSR0B |=(1<<UCSZ02);
				break;
			default:
				UCSR0C &=~(1<<UCSZ00);
				UCSR0C &=~(1<<UCSZ01);
				UCSR0B &=~(1<<UCSZ02);
				break;
	}
	//velocidad (baurate)
			UBRR0 =valor_baurate;
	}
