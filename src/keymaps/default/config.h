#pragma once

// [custom] Compose
#define COMPOSE_KEY KC_F19

// [custom] Key chain
// #define KEY_CHAIN_CANCEL_KEY KC_ESC

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
// #define TAP_CODE_DELAY 100
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
// #define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
// #define RETRO_TAPPING

// One shot
#undef NO_ACTION_ONESHOT
#define ONESHOT_TAP_TOGGLE TAPPING_TOGGLE
#define ONESHOT_TIMEOUT 0

// Leader key
#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
// #define LEADER_KEY_STRICT_KEY_PROCESSING

// Dynamic macros
#define DYNAMIC_MACRO_NO_NESTING

// Unicode
#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX
#define UNICODE_KEY_WINC COMPOSE_KEY
#define UNICODE_CYCLE_PERSIST false

// Key overrides
// #define KEY_OVERRIDE_REPEAT_DELAY 500

// Caps word
#define CAPS_WORD_IDLE_TIMEOUT 0
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Mouse keys
// #define MK_KINETIC_SPEED

// Combos
#define COMBO_TERM (TAPPING_TERM / 4)
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
