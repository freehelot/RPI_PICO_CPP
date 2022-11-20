#include "pico/stdlib.h"


/*
2 types of GPIO possible:
- Input
- Output

These 2 types can then have different functions/properties,
but some functions/properties are similar.

*/

class GpioOutputSimple
{
    private:
    uint gpio_pin;

    public:
    explicit GpioOutputSimple(uint t_gpio_pin);
    ~GpioOutputSimple();
    void OutputOn();
    void OutputOff();
    void OutputToggle();

    // Getter functions
    uint GetFunction();
    bool GetState();
    bool GetDirection();

};