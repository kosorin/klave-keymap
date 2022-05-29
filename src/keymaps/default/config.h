#pragma once

// Console (debugging)
#if defined(CONSOLE_ENABLE)
    #define NO_DEBUG
#endif

// Layers
#undef NO_ACTION_LAYER
#define LAYER_STATE_8BIT

// Tapping
#undef NO_ACTION_TAPPING
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define PERMISSIVE_HOLD

// Custom leader key
#define LEADER_CANCEL_KEY KC_ESC

// One shot
#define NO_ACTION_ONESHOT
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 0

// Dynamic macros
#define DYNAMIC_MACRO_NO_NESTING

// Unicode
#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_F19

// Key override
#define KEY_OVERRIDE_REPEAT_DELAY 500

// Caps word
#define CAPS_WORD_IDLE_TIMEOUT 0
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#undef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
