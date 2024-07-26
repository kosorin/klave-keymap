#pragma once

#include "gpio.h"
#include <stdbool.h>
#include <stdint.h>

void pmled_init(void);

void pmled_blink(uint8_t pin, uint16_t delay, uint8_t count);
void pmled_blink_single(uint16_t delay, uint8_t count);
void pmled_blink_alternate(uint16_t delay, uint8_t count);

void pmled_blink_start(void);
void pmled_blink_end(void);
void pmled_blink_cancel(void);
void pmled_blink_error(void);
