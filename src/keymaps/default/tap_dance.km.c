#include "tap_dance.km.h"
#include "keycodes.km.h"

#include "action.h"
#include "process_tap_dance.h"


#if TAP_DANCE_ADVANCED

static td_tap_t tap_dance;

td_state_t tap_dance_state(tap_dance_state_t *state) {
    if (state->count == 1) {
        return state->interrupted || !state->pressed
            ? TD_SINGLE_TAP
            : TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
        return state->interrupted || !state->pressed
            ? TD_DOUBLE_TAP
            : TD_DOUBLE_HOLD;
    }
    else if (state->count == 3) {
        return state->interrupted || !state->pressed
            ? TD_TRIPLE_TAP
            : TD_TRIPLE_HOLD;
    }
    return TD_UNKNOWN;
}

#endif

tap_dance_action_t tap_dance_actions[] = {
    [TD_DECIMAL_POINT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
};
