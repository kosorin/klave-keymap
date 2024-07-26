#include "course.h"
#if defined(KEYBOARD_klave_rev1)
    #include "promicro_led.h"
#endif
#include "quantum.h"


static course_handler_t next_handler = NULL;


bool process_course(uint16_t keycode, const keyrecord_t *record) {
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

#if defined(COURSE_CANCEL_KEY)
            if (keycode == COURSE_CANCEL_KEY) {
                course_stop();
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

bool is_course_active(void) {
    return next_handler != NULL;
}

void course_start(course_handler_t handler) {
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_start();
#endif

    next_handler = handler != NULL ? handler : COURSE_HANDLER(main);
}

void course_stop(void) {
    if (is_course_active()) {
#if defined(KEYBOARD_klave_rev1)
        pmled_blink_cancel();
#endif
    }

    next_handler = NULL;
}

course_handler_t course_done(void) {
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_end();
#endif
    return NULL;
}

course_handler_t course_cancel(void) {
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_cancel();
#endif
    return NULL;
}

#if defined(COURSE_CANCEL_KEY)
static DEFINE_COURSE_HANDLER(bad_key) {
    return course_bad_key();
}
#endif

course_handler_t course_bad_key(void) {
#if defined(COURSE_CANCEL_KEY)
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_error();
#endif
    return COURSE_HANDLER(bad_key);
#else
    return course_cancel();
#endif
}

course_handler_t course_again(void) {
    return next_handler;
}

__attribute__((weak)) DEFINE_COURSE_HANDLER(main) {
    return course_bad_key();
}
