#include "combo.km.h"
#include "keycodes.km.h"

#include "process_combo.h"
#include "action.h"
#include "progmem.h"


uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t combo_UNDO[] PROGMEM = { KC_Z, HRK_L2, COMBO_END };
const uint16_t combo_REDO[] PROGMEM = { KC_Z, HRK_L2, HRK_L1, COMBO_END };
const uint16_t combo_COPY[] PROGMEM = { KC_X, KC_C, COMBO_END };
const uint16_t combo_PASTE[] PROGMEM = { KC_C, KC_V, COMBO_END };
const uint16_t combo_SAVE[] PROGMEM = { HRK_L3, HRK_L2, COMBO_END };
const uint16_t combo_FIND[] PROGMEM = { KC_W, KC_F, COMBO_END };
const uint16_t combo_CAPS_LOCK[] PROGMEM = { KC_P, KC_M, COMBO_END };
#if defined(CAPS_WORD_ENABLE)
const uint16_t combo_CAPS_WORD[] PROGMEM = { HRK_L1, HRK_R1, COMBO_END };
#endif

combo_t key_combos[] = {
    [C_UNDO] = COMBO(combo_UNDO, C(KC_Z)),
    [C_REDO] = COMBO(combo_REDO, C(KC_Y)),
    [C_COPY] = COMBO(combo_COPY, C(KC_C)),
    [C_PASTE] = COMBO(combo_PASTE, C(KC_V)),
    [C_SAVE] = COMBO(combo_SAVE, C(KC_S)),
    [C_FIND] = COMBO(combo_FIND, C(KC_F)),
    [C_CAPS_LOCK] = COMBO(combo_CAPS_LOCK, KC_CAPS_LOCK),
#if defined(CAPS_WORD_ENABLE)
    [C_CAPS_WORD] = COMBO_ACTION(combo_CAPS_WORD),
#endif
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case C_CAPS_WORD:
            if (pressed) {
                caps_word_toggle();
            }
            break;
        default:
            break;
    }
}

#ifdef COMBO_PROCESS_KEY_RELEASE
bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    return false;
}
#endif

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return true;
}
#endif

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    return COMBO_TERM;
}
#endif

#ifdef COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    return false;
}
#endif

#ifdef COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t combo_index, combo_t *combo) {
    return false;
}
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_CAPS_LOCK:
            return false;
        default:
            return true;
    }
}
#endif
