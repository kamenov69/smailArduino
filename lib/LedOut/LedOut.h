#ifndef __LED_OUT__
#define __LED_OUT__
#include <Arduino.h>
#include <Ticker.h>

class LedOut{
    private:
        uint8_t _pin;
        uint32_t _clock;
        uint32_t _cloclPerioud;
        int _blinks;
        uint8_t _temp_status;
        void _timer_callback(void);

    public:
         LedOut(uint8_t pin);
         void blinks(int);
         void loop_ledOut(void);

};
#endif