/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

class led
{
    public:
        explicit led(const uint t_gpio);
        ~led();
        void toggle();
        void on();
        void off();
        bool get_state();
    private:
    volatile bool state;
    const uint gpio;
};

led::led(uint t_gpio): gpio(t_gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(led::gpio, false);
    led::state = false;
}

led::~led()
{
    gpio_deinit(led::gpio);
}

void led::on()
{
    gpio_put(led::gpio, true);
    led::state = true;
}

void led::off()
{
    gpio_put(led::gpio, false);
    led::state = false;
}

void led::toggle()
{
    if(led::state)
    {
        led::off();
    }
    else
    {
        led::on();
    }
}

bool led::get_state()
{
    return led::state;
}

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    led ledica(PICO_DEFAULT_LED_PIN);
    while (true) {
        ledica.off();
        sleep_ms(250);
        ledica.on();
        sleep_ms(250);
    }
#endif
}
