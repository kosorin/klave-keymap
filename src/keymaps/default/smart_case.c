#include "smart_case.h"
#include "keymap.h"

#include "action_util.h"
#include "keycode.h"
#include "quantum_keycodes.h"


smart_case_t smart_case = {
    .type = SC_CAPS_WORD,
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
#if defined(CUSTOM_UNICODE_ENABLE)
        case OSL_CZE:
            return true;
#endif
    }

    switch (smart_case.type) {
        case SC_CAPS_WORD:
            switch (keycode) {
                case KC_A ... KC_Z:
                    add_weak_mods(MOD_BIT(KC_LSFT));
                    return true;
                case KC_1 ... KC_0:
                case KC_MINUS:
                case KC_UNDERSCORE:
                case KC_BACKSPACE:
                    return true;
            }
            return false;
        case SC_MOCKING:
            switch (keycode) {
                case KC_A ... KC_Z:
                    if (smart_case.mocking.upper_case) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                    }
                    smart_case.mocking.upper_case ^= true;
                    return true;
            }
            return true;
        default:
            return false;
    }
}
