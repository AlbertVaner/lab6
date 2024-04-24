/*
 * UART_CONFI.h
 *
 * Created: 23/04/2024 12:01:55 p. m.
 *  Author: Albert V H
 */ 


#ifndef UART_CONFI_H_
#define UART_CONFI_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdarg.h>

#define _fast 1

#define  _On 1
#define  _Off 0

#define  _b_5 0
#define  _b_6 1
#define  _b_7 2
#define  _b_8 3
#define  _b_9 4

void UART_confi( uint8_t modo,	uint8_t interup_R, uint8_t interup_W, uint8_t sincrono, uint8_t largo_bit, uint16_t valor_baurate);


#endif /* UART_CONFI_H_ */