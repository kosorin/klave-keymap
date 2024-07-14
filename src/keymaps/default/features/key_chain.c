#include "features/key_chain.h"
#include "promicro_led.h"

#include "quantum.h"


static void *(*next_func)(uint8_t) = NULL;


bool process_key_chain(uint16_t keycode, const keyrecord_t *record) {
    if (next_func) {
        if (record->event.pressed) {
            switch (keycode) {
                case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                case QK_TO ... QK_TO_MAX:
                case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
                case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
                    return PROCESS_NOT_HANDLED;
                case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                    if (record->tap.count == 0) {
                        return PROCESS_NOT_HANDLED;
                    }
                    keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
                    break;
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                    if (record->tap.count == 0) {
                        return PROCESS_NOT_HANDLED;
                    }
                    keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
                    break;
            }

#if defined(KEY_CHAIN_CANCEL_KEY)
            if (keycode == KEY_CHAIN_CANCEL_KEY) {
                key_chain_stop();
                return PROCESS_HANDLED;
            }
#endif

            if (keycode <= 0xFF) {
                next_func = next_func((uint8_t)keycode);
                return PROCESS_HANDLED;
            }
            else {
                return PROCESS_NOT_HANDLED;
            }
        }
    }
    return PROCESS_NOT_HANDLED;
}

bool is_key_chain_active(void) {
    return next_func != NULL;
}

void key_chain_start(void *(*func)(uint8_t)) {
    next_func = func != NULL ? func : key_chain_user;
}

void key_chain_stop(void) {
    next_func = NULL;
}

void *key_chain_bad_key(uint8_t keycode) {
    led_blink_main(100, 2);

#if defined(KEY_CHAIN_CANCEL_KEY)
    return key_chain_bad_key;
#else
    return NULL;
#endif
}

__attribute__((weak)) void *key_chain_user(uint8_t keycode) {
    return key_chain_bad_key;
}
