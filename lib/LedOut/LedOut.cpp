#include <Arduino.h>
#include <Ticker.h>
#include "LedOut.h"

void LedOut::_timer_callback(void){
    
    if(this->_temp_status){
        if((this->_temp_status%2 == 0) &&  (this->_temp_status > 2* (this->_blinks))){
          digitalWrite(this->_pin, HIGH);
        }
        else{
           digitalWrite(this->_pin, LOW);
        }
        this->_temp_status--; 
    }
    else{
         _temp_status = 4 * (this->_blinks); 
    }
}

void LedOut::loop_ledOut(void){
   if(millis()> this->_clock){
     this->_clock = millis() + this->_cloclPerioud;
     this->_timer_callback();
   } 
}

void LedOut::blinks(int blinks){
    this->_blinks = blinks;
}

LedOut::LedOut(uint8_t pin){
   this->_pin = pin;
   this->_cloclPerioud=250;
   this->_clock = millis() + this->_cloclPerioud;
   this->_blinks = 1;
   this->_temp_status =0;

   pinMode(_pin, OUTPUT);
   digitalWrite(_pin,LOW);



}
