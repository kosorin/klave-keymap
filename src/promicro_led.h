#pragma once

#include "gpio.h"
#include <stdbool.h>
#include <stdint.h>

void led_init(void);

void led_blink(uint8_t pin, uint16_t delay, uint8_t count);
void led_blink_single(uint16_t delay, uint8_t count);
void led_blink_alternate(uint16_t delay, uint8_t count);

void led_blink_start(void);
void led_blink_end(void);
void led_blink_cancel(void);
void led_blink_error(void);
