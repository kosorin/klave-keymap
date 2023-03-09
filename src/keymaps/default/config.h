#pragma once

#define ENABLE_COMPILE_KEYCODE

// [custom] Switcher
#define SWITCH_MOD_KEY KC_LALT

// [custom] Compose
#define COMPOSE_KEY KC_APP

// [custom] Key chain
#define KEY_CHAIN_CANCEL_KEY KC_ESC

// Console (debugging)
#if defined(CONSOLE_ENABLE)
    // #define NO_DEBUG
    // #define USER_PRINT
    #if !defined(NO_DEBUG)
        // #define DEBUG_ACTION
    #endif
#endif

// Layers
#undef NO_ACTION_LAYER
#define LAYER_STATE_16BIT
// #define STRICT_LAYER_RELEASE

// Tapping
#undef NO_ACTION_TAPPING
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define QUICK_TAP_TERM TAPPING_TERM
#define QUICK_TAP_TERM_PER_KEY

// One shot
#undef NO_ACTION_ONESHOT
#define ONESHOT_TAP_TOGGLE TAPPING_TOGGLE
#define ONESHOT_TIMEOUT 0

// Leader key
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

// Dynamic macros
#define DYNAMIC_MACRO_NO_NESTING
#define DYNAMIC_MACRO_DELAY 33

// Unicode
#define UNICODE_CYCLE_PERSIST false
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_KEY_WINC COMPOSE_KEY

// Caps word
#define CAPS_WORD_IDLE_TIMEOUT 0

// Combos
#define COMBO_TERM 50
// #define COMBO_TERM_PER_COMBO
// #define COMBO_HOLD_TERM COMBO_TERM
#define COMBO_STRICT_TIMER
// #define COMBO_NO_TIMER
// #define COMBO_ONLY_FROM_LAYER 0
// #define COMBO_PROCESS_KEY_RELEASE
// #define COMBO_SHOULD_TRIGGER
// #define COMBO_MUST_PRESS_IN_ORDER
// #define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
// #define COMBO_MUST_HOLD_MODS
// #define COMBO_MUST_HOLD_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
