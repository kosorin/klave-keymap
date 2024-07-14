#include "features/key_chain.h"
#include "promicro_led.h"

#include "quantum.h"


static key_chain_handler_t next_handler = NULL;


bool process_key_chain(uint16_t keycode, const keyrecord_t *record) {
    if (next_handler) {
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

            if (keycode <= QK_BASIC_MAX) {
                next_handler = next_handler((uint8_t)keycode);
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
    return next_handler != NULL;
}

void key_chain_start(key_chain_handler_t handler) {
    led_blink_start();

    next_handler = handler != NULL ? handler : KEY_CHAIN_HANDLER(main);
}

void key_chain_stop(void) {
    if (is_key_chain_active()) {
        led_blink_cancel();
    }

    next_handler = NULL;
}

key_chain_handler_t key_chain_done(void) {
    led_blink_end();
    return NULL;
}

key_chain_handler_t key_chain_cancel(void) {
    led_blink_cancel();
    return NULL;
}

#if defined(KEY_CHAIN_CANCEL_KEY)
static DEFINE_KEY_CHAIN_HANDLER(bad_key) {
    return key_chain_bad_key();
}
#endif

key_chain_handler_t key_chain_bad_key(void) {
#if defined(KEY_CHAIN_CANCEL_KEY)
    led_blink_error();
    return KEY_CHAIN_HANDLER(bad_key);
#else
    return key_chain_cancel();
#endif
}

key_chain_handler_t key_chain_again(void) {
    return next_handler;
}

__attribute__((weak)) DEFINE_KEY_CHAIN_HANDLER(main) {
    return key_chain_bad_key();
}
