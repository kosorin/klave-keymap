#include "features/key_chain.f.h"
#if defined(SECRETS_ENABLE)
    #include "secrets.km.h"
#endif

#include "quantum.h"


static void send_string_random_number(uint8_t max_number_length) {
    const uint8_t max_number_length_total = 3;
    char buffer[max_number_length_total + 1];
    char *buffer_start = buffer;

    if (max_number_length < 1) {
        max_number_length = 1;
    }
    else if (max_number_length > max_number_length_total) {
        max_number_length = max_number_length_total;
    }

    uint16_t max_number = 1;
    for (uint8_t i = 0; i < max_number_length; i++) {
        max_number *= 10;
    }

    uint16_t number = rand() % max_number;

    for (uint8_t i = 0; i < max_number_length; i++) {
        uint8_t index = max_number_length_total - 1 - i;
        buffer[index] = 0x30 + (number % 10);
        number/= 10;
        if (number == 0) {
            buffer_start = buffer + index;
            break;
        }
    }
    buffer[max_number_length_total] = 0;

    send_string(buffer_start);
}

static void *key_chain_random(uint8_t keycode) {
    switch (keycode) {
        case KC_N:
            send_string_random_number(3);
            return key_chain_random;
        default:
            return NULL;
    }
}

static void *key_chain_boot(uint8_t keycode) {
    switch (keycode) {
        case KC_E:
            eeconfig_init();
            soft_reset_keyboard();
            break;
        case KC_S:
            soft_reset_keyboard();
            break;
        case KC_R:
            reset_keyboard();
            break;
        default:
            break;
    }
    return NULL;
}

static void *key_chain_lock(uint8_t keycode) {
    switch (keycode) {
        case KC_L:
            tap_code16(RGUI(KC_L));
            break;
        case KC_S:
            tap_code(KC_SYSTEM_SLEEP);
            break;
        default:
            break;
    }
    return NULL;
}

void *key_chain_start_user(uint8_t keycode) {
#if defined(SECRETS_ENABLE)
    void *secret_result = key_chain_start_secret(keycode);
    if (secret_result != NULL) {
        return secret_result;
    }
#endif
    switch (keycode) {
        case KC_R:
            // Call `srand` once for each session
            srand(timer_read());
            return key_chain_random;
        case KC_B:
            return key_chain_boot;
        case KC_L:
            return key_chain_lock;
        default:
            return NULL;
    }
}
