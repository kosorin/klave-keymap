#include "promicro_led.h"
#include "wait.h"


void led_init(void) {
    gpio_set_pin_output_push_pull(B0);
    gpio_set_pin_output_push_pull(D5);

    gpio_write_pin_high(B0);
    gpio_write_pin_high(D5);
}

void led_blink(pin_t pin, uint16_t delay, uint8_t count) {
    if (count == 0) {
        return;
    }

    for (uint8_t i = (count * 2) - 1, state = 0; i > 0; i--, state ^= 1) {
        gpio_write_pin(pin, state);
        wait_ms(delay);
    }
    gpio_write_pin_high(pin);
}

void led_blink_main(uint16_t delay, uint8_t count) {
    led_blink(B0, delay, count);
}

void led_blink_both(uint16_t delay, uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        led_blink(B0, delay, 1);
        led_blink(D5, delay, 1);
    }
}

void led_blink_start(void) {
    led_blink_main(50, 2);
}

void led_blink_end(void) {
    led_blink_main(150, 2);
}

void led_blink_cancel(void) {
    led_blink_both(50, 2);
    led_blink_main(300, 1);
}

void led_blink_error(void) {
    led_blink_both(50, 2);
}
