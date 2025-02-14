#include <Arduino.h>
#include "Ticker.h"
#include "blinker.h"


void _timer_callback();


uint8_t  _led_pin;
int _variable_blinks;

Ticker _led_ticker = Ticker(_timer_callback, 250,0, MILLIS);

void blinks(int number){
  _variable_blinks = number;
}

void _timer_callback(void){
  static int _temp_status =0;
  if(_temp_status){
      if((_temp_status%2 == 0) &&  (_temp_status > 2* (_variable_blinks+1))){
        digitalWrite(_led_pin, HIGH);
      }
      else{
        digitalWrite(_led_pin, LOW);
      }
      _temp_status--; 
  }
  else{
       _temp_status = 4 * (_variable_blinks+1); 
  }
}

void loop_blinker(){
  _led_ticker.update();
}

void setup_blinker(int pin){
    _led_pin = pin;
    pinMode(_led_pin, OUTPUT);
    digitalWrite(_led_pin, HIGH);
    _variable_blinks = 0;
    _led_ticker.start();
}

