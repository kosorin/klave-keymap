#include "tap_dance.h"

bool is_tap_dance_hold(tap_dance_state_t *state) {
    return state->pressed && !state->interrupted;
}

tap_dance_result_t get_tap_dance_result(tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            return is_tap_dance_hold(state) ? TDS_SINGLE_HOLD : TDS_SINGLE_TAP;
        case 2:
            return is_tap_dance_hold(state) ? TDS_DOUBLE_HOLD : TDS_DOUBLE_TAP;
        case 3:
            return is_tap_dance_hold(state) ? TDS_TRIPLE_HOLD : TDS_TRIPLE_TAP;
        default:
            return TDS_UNKNOWN;
    }
}
