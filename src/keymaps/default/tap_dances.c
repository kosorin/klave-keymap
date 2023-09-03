#include "tap_dances.h"
#include <stddef.h>
#if defined(KEY_CHAIN_ENABLE)
    #include "features/key_chain.h"
#endif
#if defined(SECRETS_ENABLE)
    #include "secrets.h"
#endif
#include "def.h"
#include "action.h"
#include "process_tap_dance.h"
#include "action_layer.h"


static td_context_t context = {
    .state = TDS_NONE,
};


#if defined(KEY_CHAIN_ENABLE)

static void finished_system_key_chain(tap_dance_state_t *state, void *user_data) {
    context.state = tap_dance_state(state, false);
    switch (context.state) {
        case TDS_SINGLE_TAP:
            key_chain_start(NULL);
            break;
#if defined(SECRETS_ENABLE)
        case TDS_DOUBLE_TAP:
            key_chain_start(secret_key_chain_start);
            break;
#endif
        case TDS_SINGLE_HOLD:
            layer_on(L_SYSTEM);
            break;
        default:
            break;
    }
}

static void reset_system_key_chain(tap_dance_state_t *state, void *user_data) {
    switch (context.state) {
        case TDS_SINGLE_HOLD:
            layer_off(L_SYSTEM);
            break;
        default:
            break;
    }
    context.state = TDS_NONE;
}

#endif


tap_dance_action_t tap_dance_actions[] = {
#if defined(SECRETS_ENABLE)
    [TD_SECRET1] = TD_SECRET1_ACTION,
    [TD_SECRET2] = TD_SECRET2_ACTION,
    [TD_SECRET3] = TD_SECRET3_ACTION,
    [TD_SECRET4] = TD_SECRET4_ACTION,
    [TD_SECRET5] = TD_SECRET5_ACTION,
    [TD_SECRET6] = TD_SECRET6_ACTION,
    [TD_SECRET7] = TD_SECRET7_ACTION,
    [TD_SECRET8] = TD_SECRET8_ACTION,
    [TD_SECRET9] = TD_SECRET9_ACTION,
    [TD_SECRET10] = TD_SECRET10_ACTION,
    [TD_SECRET11] = TD_SECRET11_ACTION,
    [TD_SECRET12] = TD_SECRET12_ACTION,
#endif
#if defined(KEY_CHAIN_ENABLE)
    [TD_SYSTEM_KEY_CHAIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_system_key_chain, reset_system_key_chain),
#endif
    [TD_DECIMAL_POINT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
};


td_state_t tap_dance_state(tap_dance_state_t *state, bool interrupt_tap) {
    if (state->count == 1) {
        return state->pressed && (!interrupt_tap || !state->interrupted)
            ? TDS_SINGLE_HOLD
            : TDS_SINGLE_TAP;
    }
    else if (state->count == 2) {
        return state->pressed && (!interrupt_tap || !state->interrupted)
            ? TDS_DOUBLE_HOLD
            : TDS_DOUBLE_TAP;
    }
    else if (state->count == 3) {
        return state->pressed && (!interrupt_tap || !state->interrupted)
            ? TDS_TRIPLE_HOLD
            : TDS_TRIPLE_TAP;
    }
    return TDS_UNKNOWN;
}
