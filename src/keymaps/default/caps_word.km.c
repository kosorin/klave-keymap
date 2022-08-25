#include "caps_word.km.h"
#include "keycodes.km.h"

#include "action_util.h"
#include "keycode.h"
#include "quantum_keycodes.h"


smart_case_t smart_case = { .type = SC_CAPS_WORD, };

bool caps_word_press_user(uint16_t keycode) {
    switch (smart_case.type) {
        case SC_SPONGEBOB:
            switch (keycode) {
                case KC_A ... KC_Z:
                    if (smart_case.spongebob.upper_case) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                    }
                    smart_case.spongebob.upper_case ^= true;
                    return true;
                default:
                    return true;
            }
            break;
        case SC_CAMEL:
        case SC_PASCAL:
        case SC_SNAKE:
        case SC_KEBAB:
            // TODO
            return false;
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
#if defined(COMPOSE_ENABLE)
                case COMPOSE(XC__LETTER) ... COMPOSE(XC__LETTER_MAX):
                    add_weak_mods(MOD_BIT(KC_LSFT));
                    return true;
#endif
                default:
                    return false;
            }
            break;
        default:
            return false;
    }
}
