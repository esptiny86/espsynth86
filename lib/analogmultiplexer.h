#ifndef ANALOGMULTIPLEXER_H
#define ANALOGMULTIPLEXER_H

#include "Arduino.h"

class AnalogMultiplexerPin
{
private:
    uint8_t _pin;
    int _prevValue[8];
    uint8_t s1;
    uint8_t s2;
    uint8_t s3;
    uint8_t z;

public:

    void setup(const uint8_t _s1, const uint8_t _s2, const uint8_t _s3, const uint8_t _z)
    {
        s1 = _s1;
        s2 = _s2;
        s3 = _s3;
        z =  _z; //analog pin connected to multiplexer

        pinMode(s1, OUTPUT);
        pinMode(s2, OUTPUT);
        pinMode(s3, OUTPUT);
        pinMode(z, INPUT);

        //set initial value
        _prevValue[0] = 0;
        _prevValue[1] = 0;
        _prevValue[2] = 0;
        _prevValue[3] = 0;
        _prevValue[4] = 0;
        _prevValue[5] = 0;
        _prevValue[6] = 0;
        _prevValue[7] = 0;

    }

    void setInitialValue(uint8_t _pin_index)
    {
        _prevValue[_pin_index] = readChannel(_pin_index);
    }

    int readChannel (const uint8_t _pin_index)
    {
        // set switch to output (not sure why, but must be set everytime..)
//        pinMode(s1, OUTPUT);
//        pinMode(s2, OUTPUT);
//        pinMode(s3, OUTPUT);

        // set multiplexer, select channel
        digitalWrite(s1, (_pin_index & 0x01));
        digitalWrite(s2, ((_pin_index>>1) & 0x01));
        digitalWrite(s3, ((_pin_index>>2) & 0x01));

        // read value
        return analogRead(z);

    }

    // noise 0..255; in practice 0..4
    int read(const uint8_t _pin_index, const uint8_t noise = 0)
    {
        int value = readChannel(_pin_index);
        if (noise == 0 || ((value - _prevValue[_pin_index]) & 0x7FFF) > noise)
        {
            _prevValue[_pin_index] = value;
        }
        return _prevValue[_pin_index];

    }

    // alpha 0..31;
    // int readSmoothed(const uint8_t _pin_index, uint8_t alpha = 0);

    // int readPrevious(const uint8_t _pin_index);



};

#endif // ANALOGMULTIPLEXER_H
