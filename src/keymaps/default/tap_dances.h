#pragma once

#include "action.h"
#include "process_tap_dance.h"


enum tap_dances {
#if defined(SECRETS_ENABLE)
    TD_SECRET1,
    TD_SECRET2,
    TD_SECRET3,
    TD_SECRET4,
    TD_SECRET5,
    TD_SECRET6,
    TD_SECRET7,
    TD_SECRET8,
    TD_SECRET9,
    TD_SECRET10,
    TD_SECRET11,
    TD_SECRET12,
#endif
#if defined(KEY_CHAIN_ENABLE)
    TD_SYSTEM_KEY_CHAIN,
#endif
    TD_DECIMAL_POINT,
};


typedef enum {
    TDS_NONE,
    TDS_SINGLE_TAP,
    TDS_SINGLE_HOLD,
    TDS_DOUBLE_TAP,
    TDS_DOUBLE_HOLD,
    TDS_TRIPLE_TAP,
    TDS_TRIPLE_HOLD,
    TDS_UNKNOWN,
} td_state_t;

typedef struct {
    td_state_t state;
} td_context_t;

td_state_t tap_dance_state(tap_dance_state_t *state, bool interrupt_tap);
