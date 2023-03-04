#pragma once

#include "action.h"
#include "process_tap_dance.h"


#define TAP_DANCE_ADVANCED false
#if TAP_DANCE_ADVANCED

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

td_state_t tap_dance_state(tap_dance_state_t *state);

#endif

enum tap_dances {
    TD_DECIMAL_POINT,
};
