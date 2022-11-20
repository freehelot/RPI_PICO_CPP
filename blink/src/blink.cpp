/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */



#include "blink.hpp"
#include <gpio.hpp>

using namespace std;


int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    GpioOutputSimple led(PICO_DEFAULT_LED_PIN);
    while (true) {
        led.OutputOn();
        sleep_ms(250);
        led.OutputOff();
        sleep_ms(250);
    }
#endif
}
