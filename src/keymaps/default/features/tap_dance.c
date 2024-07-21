#include "tap_dance.h"

tap_dance_result_t get_tap_dance_result(tap_dance_state_t *state, bool interrupt_tap) {
    switch (state->count) {
        case 1:
            return state->pressed && (!interrupt_tap || !state->interrupted) ? TDS_SINGLE_HOLD : TDS_SINGLE_TAP;
        case 2:
            return state->pressed && (!interrupt_tap || !state->interrupted) ? TDS_DOUBLE_HOLD : TDS_DOUBLE_TAP;
        case 3:
            return state->pressed && (!interrupt_tap || !state->interrupted) ? TDS_TRIPLE_HOLD : TDS_TRIPLE_TAP;
        default:
            return TDS_UNKNOWN;
    }
}
