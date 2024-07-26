#include "promicro_led.h"
#include "wait.h"

void pmled_init(void) {
    gpio_set_pin_output_push_pull(B0);
    gpio_set_pin_output_push_pull(D5);

    gpio_write_pin_high(B0);
    gpio_write_pin_high(D5);
}

void pmled_blink(pin_t pin, uint16_t delay, uint8_t count) {
    if (count == 0) {
        return;
    }

    for (uint8_t i = (count * 2) - 1, state = 0; i > 0; i--, state ^= 1) {
        gpio_write_pin(pin, state);
        wait_ms(delay);
    }
    gpio_write_pin_high(pin);
}

void pmled_blink_single(uint16_t delay, uint8_t count) {
    pmled_blink(B0, delay, count);
}

void pmled_blink_alternate(uint16_t delay, uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        pmled_blink(B0, delay, 1);
        pmled_blink(D5, delay, 1);
    }
}

void pmled_blink_start(void) {
    pmled_blink_single(50, 2);
}

void pmled_blink_end(void) {
    pmled_blink_single(150, 2);
}

void pmled_blink_cancel(void) {
    pmled_blink_alternate(50, 2);
    pmled_blink_single(300, 1);
}

void pmled_blink_error(void) {
    pmled_blink_alternate(50, 2);
}
