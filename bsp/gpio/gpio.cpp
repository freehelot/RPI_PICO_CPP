#include "gpio.hpp"


GpioOutputSimple::GpioOutputSimple(uint t_gpio_pin) : gpio_pin(t_gpio_pin)
{
    gpio_init(gpio_pin);
    gpio_set_dir(gpio_pin, GPIO_OUT);
    gpio_put(gpio_pin, false);
}

GpioOutputSimple::~GpioOutputSimple()
{
    gpio_deinit(GpioOutputSimple::gpio_pin);
}

void GpioOutputSimple::OutputOn()
{
    gpio_put(GpioOutputSimple::gpio_pin, true);
}
void GpioOutputSimple::OutputOff()
{
    gpio_put(GpioOutputSimple::gpio_pin, false);
}

void GpioOutputSimple::OutputToggle()
{
    gpio_put(GpioOutputSimple::gpio_pin, !(GpioOutputSimple::GetState()));
}

    // Getter functions
uint GpioOutputSimple::GetFunction()
{
    return static_cast<uint>(gpio_get_function(GpioOutputSimple::gpio_pin));
}

bool GpioOutputSimple::GetState()
{
    return static_cast<bool>(gpio_get(GpioOutputSimple::gpio_pin));
}

bool GpioOutputSimple::GetDirection()
{
    return static_cast<bool>(gpio_get_dir(GpioOutputSimple::gpio_pin));
}