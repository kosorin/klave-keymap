#include "combos.h"
#include "def.h"
#if defined(CAPS_WORD_ENABLE)
    #include "smart_case.h"
#endif

#include "process_combo.h"
#include "action.h"
#include "progmem.h"


uint16_t COMBO_LEN = combo_events_COUNT;

const uint16_t combo_COPY[] PROGMEM = { KC_X, KC_C, COMBO_END };
const uint16_t combo_SAVE[] PROGMEM = { HRK_L3, HRK_L2, COMBO_END };
const uint16_t combo_FIND[] PROGMEM = { KC_W, KC_F, COMBO_END };
const uint16_t combo_CAPS_LOCK[] PROGMEM = { KC_P, KC_M, COMBO_END };
#if defined(CAPS_WORD_ENABLE)
const uint16_t combo_CAPS_WORD[] PROGMEM = { HRK_L1, HRK_R1, COMBO_END };
const uint16_t combo_MOCKING_CASE[] PROGMEM = { HRK_L1, HRK_R1, KC_F, KC_U, COMBO_END };
#endif

combo_t key_combos[] = {
    [C_COPY] = COMBO(combo_COPY, C(KC_C)),
    [C_SAVE] = COMBO(combo_SAVE, C(KC_S)),
    [C_FIND] = COMBO(combo_FIND, C(KC_F)),
    [C_CAPS_LOCK] = COMBO(combo_CAPS_LOCK, KC_CAPS_LOCK),
#if defined(CAPS_WORD_ENABLE)
    [C_CAPS_WORD] = COMBO_ACTION(combo_CAPS_WORD),
    [C_MOCKING_CASE] = COMBO_ACTION(combo_MOCKING_CASE),
#endif
};

#if defined(CAPS_WORD_ENABLE)
static void caps_word_toggle_combo(uint16_t combo_index) {
    switch(combo_index) {
        case C_MOCKING_CASE:
            smart_case = (smart_case_t){ .type = SC_MOCKING, .mocking = { .upper_case = false, }, };
            break;
        case C_CAPS_WORD:
        default:
            smart_case = (smart_case_t){ .type = SC_CAPS_WORD, };
            break;
    }
    caps_word_toggle();
}
#endif

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
#if defined(CAPS_WORD_ENABLE)
        case C_CAPS_WORD:
        case C_MOCKING_CASE:
            if (pressed) {
                caps_word_toggle_combo(combo_index);
            }
            break;
#endif
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
