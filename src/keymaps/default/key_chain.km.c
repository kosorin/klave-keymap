#include "features/key_chain.f.h"
#if defined(SECRETS_ENABLE)
    #include "secrets.km.h"
#endif

#include "quantum.h"


static void send_random_number(uint8_t digit_count) {
    bool any = false;
    for (uint8_t i = 0; i < digit_count; i++) {
        uint8_t digit = rand() % 10;
        if (digit == 0) {
            if (any) {
                digit += 10;
            }
            else {
                continue;
            }
        }
        any = true;
        tap_code(KC_1 + digit - 1);
    }
    if (!any) {
        tap_code(KC_0);
    }
}

static void *key_chain_random_number(uint8_t keycode) {
    static uint8_t digit_count = 3;
    switch (keycode) {
        case KC_1 ... KC_9:
            digit_count = keycode - KC_1 + 1;
        case KC_N:
            send_random_number(digit_count);
            return key_chain_random_number;
        case KC_SPACE:
        case KC_TAB:
        case KC_ENTER:
        case KC_DOT:
        case KC_COMMA:
            tap_code(keycode);
            return key_chain_random_number;
        default:
            return NULL;
    }
}

static void *key_chain_random(uint8_t keycode) {
    switch (keycode) {
        case KC_N:
            return key_chain_random_number;
        default:
            return NULL;
    }
}

static void *key_chain_system(uint8_t keycode) {
    switch (keycode) {
        case KC_E:
            eeconfig_init();
            soft_reset_keyboard();
            break;
        case KC_R:
            soft_reset_keyboard();
            break;
        case KC_B:
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
        case KC_ESC:
            return key_chain_system;
        case KC_L:
            return key_chain_lock;
        default:
            return NULL;
    }
}
