/*
                A program to control a 7-segment display using Timer0.
  Requirements:
• the 7-segment display is connected to PORTC.
• Configure the timer clock to F_CPU/256.
• Timer0 in Normal Mode.
• Every 1 second the 7-segment increments by one.
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "mcu.h"

uint8_t tick = 0;

ISR(TIMER0_OVF_vect)
{
	tick++;
	if(tick == OVERFLOW_COUNT){

		tick = 0;

		if(PORTC == 9)	
			PORTC = 0;
		else
	 		PORTC++;
	}	
}

int main(void)
{	
	sei();              // enable global interrupt mask bit
	DDRC  = 0xFF;       // PORTC pins as output pins.
	PORTC = 0x00;       // 7-segment display zero initially

	timer_init();       
    for(;;);
}
