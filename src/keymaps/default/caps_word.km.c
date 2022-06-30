#include "caps_word.km.h"
#include "keycodes.km.h"
#if defined(UNICODEMAP_ENABLE)
    #include "unicode_map.km.h"
#endif

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
        default:
            switch (keycode) {
                case KC_A ... KC_Z:
                    add_weak_mods(MOD_BIT(KC_LSFT));
                    return true;
                case KC_1 ... KC_0:
                case KC_MINUS:
                case KC_UNDERSCORE:
                case KC_BACKSPACE:
                    return true;
#if defined(UNICODEMAP_ENABLE)
                case TRK_L1:
                case TRK_R1:
                    return true;
                case QK_UNICODEMAP_PAIR ... QK_UNICODEMAP_PAIR_MAX:
                    if ((keycode & 0x7F) < U__LETTER_PAIRS_END && ((keycode >> 7) & 0x7F) < U__LETTER_PAIRS_END) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                        return true;
                    }
                    else {
                        return false;
                    }
#endif
                default:
                    return false;
            }
            break;
    }
}
