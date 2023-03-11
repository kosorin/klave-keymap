#pragma once

#if defined(CUSTOM_UNICODE_ENABLE)
    #include "uc.h"
#endif
#if defined(COMBO_ENABLE)
    #include "combos.h"
#endif
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
#endif

#include "keycode.h"
#include "quantum_keycodes.h"

#define ___V___ KC_TRANSPARENT
#define ___T___ KC_TRANSPARENT


// Layers
enum layers {
    L_BASE,
    L_SYMBOL,
    L_FUNCTION,
#if defined(SWITCHER_ENABLE)
    L_SWITCH,
#endif
    L_MEDIA,
    L_NUMBER,
    L_NUMBER_SYMBOL,
    L_NAVIGATION,
    L_SYSTEM,
#if defined(GAMING_ENABLE)
    L_GAME,
    L_GAME_EXTENDED,
#endif
    LAYER_COUNT,
};


// Custom keycodes
enum custom_keycodes {
    CK__SAFE_RANGE = QK_KB,

#if defined(CUSTOM_UNICODE_ENABLE)
    KC_UCTM_NONE,
    KC_UCTM_CZECH,
    KC_UCTM_SCRIPT,
    KC_UCTM_ZALGO,
#endif

#if defined(KEY_CHAIN_ENABLE)
    KEY_CHAIN,
#else
    #define KEY_CHAIN KC_NO
#endif

#if defined(SWITCHER_ENABLE)
    SWITCH,
#else
    #define SWITCH KC_NO
#endif
};

// Layers
#define MO_NUM MO(L_NUMBER)
#define MO_NAV MO(L_NAVIGATION)

// Zoom
#define Z_PLUS C(KC_EQUAL)
#define Z_MINUS C(KC_MINUS)
#define Z_RESET C(KC_0)

// Tap dance
#if defined(TAP_DANCE_ENABLE)
    #define CK_DECP TD(TD_DECIMAL_POINT)
#else
    #define CK_DECP KC_DOT
#endif

// Gaming
#if defined(GAMING_ENABLE)
    #define CK_GON DF(L_GAME)
    #define CK_GOFF DF(L_BASE)
    #define CK_GEXT LT(L_GAME_EXTENDED, KC_ENTER)
#else
    #define CK_GON KC_NO
#endif

// Home row keys - left
#define HRK_L4 GUI_T(KC_A)
#define HRK_L3 ALT_T(KC_R)
#define HRK_L2 CTL_T(KC_S)
#define HRK_L1 SFT_T(KC_T)

// Home row keys - right
#define HRK_R1 SFT_T(KC_N)
#define HRK_R2 CTL_T(KC_E)
#define HRK_R3 ALT_T(KC_I)
#define HRK_R4 GUI_T(KC_O)

// Thumb row keys - left
#define TRK_L4 LT(L_MEDIA, KC_ESCAPE)
#define TRK_L3 LT(L_FUNCTION, KC_TAB)
#define TRK_L2 LT(L_SYMBOL, KC_SPACE)
#define TRK_L1 KC_ENTER

// Thumb row keys - right
#if defined(KEY_CHAIN_ENABLE) && defined(TAP_DANCE_ENABLE)
    #define TRK_R1 TD(TD_SYSTEM_KEY_CHAIN)
#else
    #define TRK_R1 MO(L_SYSTEM)
#endif
#define TRK_R2 LT(L_NUMBER, KC_BACKSPACE)
#define TRK_R3 MO(L_NAVIGATION)
#if defined(CUSTOM_UNICODE_ENABLE) && defined(TAP_DANCE_ENABLE)
    #define TRK_R4 TD(TD_UNICODE_TYPING_MODE)
#else
    #define TRK_R4 COMPOSE_KEY
#endif

// Other
#define NUM_SPC LT(L_NUMBER_SYMBOL, KC_SPACE)
