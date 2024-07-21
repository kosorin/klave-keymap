#include "smart_case.h"
#include "action_util.h"
#include "keycode.h"
#include "quantum_keycodes.h"

static smart_case_t current_smart_case = {
    .type = SC_CAPS_WORD,
};

void set_smart_case(smart_case_type_t type) {
    switch (type) {
        case SC_CAPS_WORD:
            current_smart_case = (smart_case_t){.type = SC_CAPS_WORD, .state.caps_word = {}};
            break;
        case SC_MOCKING:
            current_smart_case = (smart_case_t){.type = SC_MOCKING, .state.mocking = {.upper = false}};
            break;
        default:
            clear_smart_case();
            break;
    }
}

void clear_smart_case(void) {
    current_smart_case = (smart_case_t){.type = SC_NONE};
}

smart_case_result_t smart_case_press(uint16_t keycode) {
    switch (current_smart_case.type) {
        case SC_CAPS_WORD:
            return smart_case_press_caps_word(keycode, &current_smart_case.state.caps_word);
        case SC_MOCKING:
            return smart_case_press_mocking(keycode, &current_smart_case.state.mocking);
        default:
            return SCR_STOP;
    }
}

__attribute__((weak)) smart_case_result_t smart_case_press_caps_word(uint16_t keycode, smart_case_state_caps_word_t* state) {
    switch (keycode) {
        case KC_A ... KC_Z:
            return SCR_UPPER;
        case KC_1 ... KC_0:
        case KC_MINUS:
        case KC_UNDERSCORE:
        case KC_BACKSPACE:
            return SCR_LOWER;
        default:
            return SCR_STOP;
    }
}

__attribute__((weak)) smart_case_result_t smart_case_press_mocking(uint16_t keycode, smart_case_state_mocking_t* state) {
    switch (keycode) {
        case KC_A ... KC_Z:
            state->upper ^= true;
            return state->upper? SCR_UPPER : SCR_LOWER;
        default:
            return SCR_LOWER;
    }
}
