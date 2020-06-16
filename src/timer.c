#include "timer.h"
#include "mcu.h"

   
void timer0_init(void){

    TCNT0 = 0x00;            //timer initial value
	TIMSK = (1<<TOIE0);      //enable overflow interrupt
	TCCR0 =  ((1<<CS02) | (1<<FOC0)) ;
}