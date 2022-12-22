#include "key_chain.f.h"

#include "quantum.h"


static void *(*key_chain_next_func)(uint8_t) = NULL;


bool process_key_chain(uint16_t keycode, const keyrecord_t *record) {
    if (key_chain_next_func) {
        if (record->event.pressed) {
#if defined(KEY_CHAIN_CANCEL_KEY)
            if (keycode == KEY_CHAIN_CANCEL_KEY) {
                key_chain_stop();
                return PROCESS_HANDLED;
            }
#endif

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
                    else {
                        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
                        break;
                    }
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                    if (record->tap.count == 0) {
                        return PROCESS_NOT_HANDLED;
                    }
                    else {
                        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
                        break;
                    }
            }

            if (keycode > 0xFF) {
                key_chain_stop();
            }
            else {
                key_chain_next_func = key_chain_next_func((uint8_t)keycode);
            }

            return PROCESS_HANDLED;
        }
    }
    return PROCESS_NOT_HANDLED;
}

__attribute__((weak)) void *key_chain_start_user(uint8_t keycode) {
    return NULL;
}

void key_chain_start(void) {
    key_chain_next_func = key_chain_start_user;
}

void key_chain_stop(void) {
    key_chain_next_func = NULL;
}

bool is_key_chain_active(void) {
    return key_chain_next_func != NULL;
}
