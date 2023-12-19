#include "features/key_chain.h"
#if defined(CUSTOM_UNICODE_ENABLE)
    #include "uc.h"
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
        tap_code((KC_1 - 1) + digit);
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
        case KC_BACKSPACE:
        case KC_DELETE:
        case KC_TAB:
        case KC_ENTER:
        case KC_DOT:
        case KC_COMMA:
            tap_code(keycode);
            return key_chain_random_number;
        default:
            return key_chain_bad_key;
    }
}

static void *key_chain_random(uint8_t keycode) {
    switch (keycode) {
        case KC_N:
            return key_chain_random_number;
        default:
            return key_chain_bad_key;
    }
}

#if defined(CUSTOM_UNICODE_ENABLE)

static void *key_chain_unicode_mode(uint8_t keycode) {
    switch (keycode) {
        case KC_W:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            return NULL;
        case KC_C:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            return NULL;
        case KC_L:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            return NULL;
        default:
            return key_chain_bad_key;
    }
}

static void *key_chain_unicode_typing_mode(uint8_t keycode) {
    switch (keycode) {
        case KC_S:
            unicode_typing_mode = UCTM_SCRIPT;
            return NULL;
        case KC_Z:
            unicode_typing_mode = UCTM_ZALGO;
            return NULL;
        case KC_F:
            unicode_typing_mode = UCTM_NONE;
            return NULL;
        default:
            return key_chain_bad_key;
    }
}

void *key_chain_unicode(uint8_t keycode) {
    switch (keycode) {
        case KC_M:
            return key_chain_unicode_mode;
        case KC_F:
            return key_chain_unicode_typing_mode;
        default:
            return key_chain_bad_key;
    }
}

#endif

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
    return key_chain_bad_key;
}

void *key_chain_user(uint8_t keycode) {
    switch (keycode) {
        case KC_R:
            srand(timer_read());
            return key_chain_random;
#if defined(CUSTOM_UNICODE_ENABLE)
        case KC_U:
            return key_chain_unicode;
#endif
        case KC_DELETE:
            return key_chain_system;
        default:
            return key_chain_bad_key;
    }
}
