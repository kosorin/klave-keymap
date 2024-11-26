#pragma once

#include "process_tap_dance.h"

typedef enum {
    TDS_NONE,
    TDS_SINGLE_TAP,
    TDS_SINGLE_HOLD,
    TDS_DOUBLE_TAP,
    TDS_DOUBLE_HOLD,
    TDS_TRIPLE_TAP,
    TDS_TRIPLE_HOLD,
    TDS_UNKNOWN,
} tap_dance_result_t;

typedef struct {
    tap_dance_result_t result;
} tap_dance_context_t;

bool is_tap_dance_hold(tap_dance_state_t *state);

tap_dance_result_t get_tap_dance_result(tap_dance_state_t *state);
