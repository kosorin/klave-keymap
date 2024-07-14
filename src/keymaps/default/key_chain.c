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

static DEFINE_KEY_CHAIN_HANDLER(random_number) {
    static uint8_t digit_count = 3;
    switch (keycode) {
        case KC_1 ... KC_9:
            digit_count = keycode - KC_1 + 1;
        case KC_N:
            send_random_number(digit_count);
            return key_chain_again();
        case KC_SPACE:
        case KC_BACKSPACE:
        case KC_DELETE:
        case KC_TAB:
        case KC_ENTER:
        case KC_DOT:
        case KC_COMMA:
            tap_code(keycode);
            return key_chain_again();
        default:
            return key_chain_bad_key();
    }
}

static DEFINE_KEY_CHAIN_HANDLER(random) {
    switch (keycode) {
        case KC_N:
            return KEY_CHAIN_HANDLER(random_number);
        default:
            return key_chain_bad_key();
    }
}

#if defined(CUSTOM_UNICODE_ENABLE)

static DEFINE_KEY_CHAIN_HANDLER(unicode_mode) {
    switch (keycode) {
        case KC_W:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            return key_chain_done();
        case KC_C:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            return key_chain_done();
        case KC_L:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            return key_chain_done();
        default:
            return key_chain_bad_key();
    }
}

static DEFINE_KEY_CHAIN_HANDLER(unicode_typing_mode) {
    switch (keycode) {
        case KC_M:
            unicode_typing_mode = UCTM_MATH_SCRIPT;
            return key_chain_done();
        case KC_N:
            unicode_typing_mode = UCTM_MATH_FRAKTUR;
            return key_chain_done();
        case KC_C:
            unicode_typing_mode = UCTM_CIRCLE;
            return key_chain_done();
        case KC_S:
            unicode_typing_mode = UCTM_SQUARE;
            return key_chain_done();
        case KC_T:
            unicode_typing_mode = UCTM_SQUARE_OUTLINE;
            return key_chain_done();
        case KC_R:
            unicode_typing_mode = UCTM_REGIONAL;
            return key_chain_done();
        case KC_Z:
            unicode_typing_mode = UCTM_ZALGO;
            return key_chain_done();
        case KC_F:
            unicode_typing_mode = UCTM_NONE;
            return key_chain_done();
        default:
            return key_chain_bad_key();
    }
}

static DEFINE_KEY_CHAIN_HANDLER(unicode) {
    switch (keycode) {
        case KC_M:
            return KEY_CHAIN_HANDLER(unicode_mode);
        case KC_F:
            return KEY_CHAIN_HANDLER(unicode_typing_mode);
        default:
            return key_chain_bad_key();
    }
}

#endif

static DEFINE_KEY_CHAIN_HANDLER(system) {
    switch (keycode) {
        case KC_E:
            eeconfig_init();
            soft_reset_keyboard();
            return key_chain_done();
        case KC_R:
            soft_reset_keyboard();
            return key_chain_done();
        case KC_B:
            reset_keyboard();
            return key_chain_done();
        default:
            return key_chain_bad_key();
    }
}

DEFINE_KEY_CHAIN_HANDLER(main) {
    switch (keycode) {
        case KC_R:
            srand(timer_read());
            return KEY_CHAIN_HANDLER(random);
#if defined(CUSTOM_UNICODE_ENABLE)
        case KC_U:
            return KEY_CHAIN_HANDLER(unicode);
#endif
        case KC_DELETE:
            return KEY_CHAIN_HANDLER(system);
        default:
            return key_chain_bad_key();
    }
}
