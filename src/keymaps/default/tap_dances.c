#include "tap_dances.h"
#if defined(KEY_CHAIN_ENABLE)
    #include "features/key_chain.h"
#endif
#if defined(SECRETS_ENABLE)
    #include "secrets.h"
#endif
#if defined(CUSTOM_UNICODE_ENABLE)
    #include "uc.h"
#endif
#include "def.h"
#include "action.h"
#include "process_tap_dance.h"


static td_context_t context = {
    .state = TDS_NONE,
};


#if defined(CUSTOM_UNICODE_ENABLE)

static void finished_unicode_typing_mode(tap_dance_state_t *state, void *user_data) {
    context.state = tap_dance_state(state, false);
    switch (context.state) {
        case TDS_SINGLE_TAP:
            tap_code(COMPOSE_KEY);
            break;
        case TDS_SINGLE_HOLD:
            unicode_typing_mode = UCTM_CZECH;
            break;
        default:
            break;
    }
}

static void reset_unicode_typing_mode(tap_dance_state_t *state, void *user_data) {
    switch (context.state) {
        case TDS_SINGLE_HOLD:
            unicode_typing_mode = UCTM_NONE;
            break;
        default:
            break;
    }
    context.state = TDS_NONE;
}

#endif


#if defined(KEY_CHAIN_ENABLE)

static void finished_system_key_chain(tap_dance_state_t *state, void *user_data) {
    context.state = tap_dance_state(state, false);
    switch (context.state) {
        case TDS_SINGLE_TAP:
            key_chain_start(NULL);
            break;
#if defined(SECRETS_ENABLE)
        case TDS_DOUBLE_TAP:
            key_chain_start(secret_key_chain_start_user);
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
#if defined(KEY_CHAIN_ENABLE)
    [TD_SYSTEM_KEY_CHAIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_system_key_chain, reset_system_key_chain),
#endif
#if defined(CUSTOM_UNICODE_ENABLE)
    [TD_UNICODE_TYPING_MODE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_unicode_typing_mode, reset_unicode_typing_mode),
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
