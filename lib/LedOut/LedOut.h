#ifndef __LED_OUT__
#define __LED_OUT__
#include <Arduino.h>
//#include <Ticker.h>

class LedOut{
    private:
        uint8_t _pin;
        uint32_t _clock;
        uint32_t _cloclPerioud;
        int _blinks;
        uint8_t _temp_status;
        
        //Ticker ticker = Ticker(NULL, 250);

    public:
         LedOut(uint8_t pin);
         void blinks(int);
         void loop_ledOut(void);
         void _timer_callback(void);
         //void const *method_pointer;
};
#endif