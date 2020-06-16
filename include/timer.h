#ifndef _TIMER_H
#define _TIMER_H

/* with clock = 1Mhz and prescaler value of F_CPU/256 
 * every count will take 32 us
 * initial timer counts from 0 --> 255 (255 * 32us = 8.16 ms per overflow)
 * so we need timer to overflow 123 times to get a 1 second 
 */

#define OVERFLOW_COUNT     123   

void timer0_init(void);

#endif