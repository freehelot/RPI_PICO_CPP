#include "pico/stdlib.h"


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