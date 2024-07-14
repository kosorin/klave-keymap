#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "gpio.h"


void led_init(void);

void led_blink(uint8_t pin, uint16_t delay, uint8_t count);
void led_blink_main(uint16_t delay, uint8_t count);
void led_blink_both(uint16_t delay, uint8_t count);
