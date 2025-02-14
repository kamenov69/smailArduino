#ifndef __BLINKER_H__
#define __BLINKER_H__
#include <Arduino.h>
#include "Ticker.h"

/*
Flashing a LED. Flashes a LED by flashing as much 
as the value of the connected variable followed by 
a pause. The process repeats again.
*/


void setup_blinker(int);  // pin number, address of a variable  
void blinks(int);         // set blinking number 
void loop_blinker();     // should be in the main loop

#endif
