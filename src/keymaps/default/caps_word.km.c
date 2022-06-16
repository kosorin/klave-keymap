#include "keycodes.km.h"
#if defined(UNICODEMAP_ENABLE)
    #include "unicode_map.km.h"
#endif

#include "action_util.h"
#include "keycode.h"
#include "quantum_keycodes.h"


bool caps_word_press_user(uint16_t keycode) {
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
        case CK_UC:
            return true;
        case QK_UNICODEMAP_PAIR ... QK_UNICODEMAP_PAIR_MAX:
            if ((((keycode - QK_UNICODEMAP_PAIR) & 0x7F)) < U__LETTER_PAIRS_END) {
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
}
