#include <Arduino.h>
#include "main.h"
#include "blinker.h"
#include "Cmd.h"
#include "globals.h"

global_t globals[] = {
    {(char*)"mode",     3, 0, 4, true},
    {(char*)"tst_glob", 2, 0, 1,true},
    {(char*)"tst2",     1, -127,127, true},
    {(char*)"tst3",     4,  127,127, true}
};
int MAX_GLOBALS = sizeof(globals)/sizeof(global_t);


void setup(){
    Serial.begin(9600);
    cmdInit(&Serial);
    cmdAdd("hello", [](int argn, char** args){cmdGetStream()->print("Smail!!!");});
    setup_globals();
    setup_blinker(BLINK_LED);
    blinks(0);

}

void loop(){
    cmdPoll();
    loop_blinker();
    blinks(globals[index("mode")].value);
   
        
}
  

