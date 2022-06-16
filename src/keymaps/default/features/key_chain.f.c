#include "key_chain.f.h"

#include "quantum.h"


static void *(*key_chain_next_func)(uint8_t) = NULL;


bool process_key_chain(uint16_t start_keycode, uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        if (key_chain_next_func) {

#if defined(KEY_CHAIN_CANCEL_KEY)
            if (keycode == KEY_CHAIN_CANCEL_KEY) {
                key_chain_stop();
                return PROCESS_HANDLED;
            }
#endif

            if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
                keycode &= 0xFF;
            }

            if (keycode > 0xFF) {
                return PROCESS_NOT_HANDLED;
            }

            key_chain_next_func = key_chain_next_func((uint8_t)keycode);

            return PROCESS_HANDLED;
        }
        else if (keycode == start_keycode) {
            key_chain_start();
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
