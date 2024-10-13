#pragma once

#include "keycodes.h"
#include "quantum_keycodes.h"

#define ___V___ KC_TRANSPARENT
#define ___T___ KC_TRANSPARENT

// ========================================================================== //
// Layers
// ========================================================================== //
enum layers {
    L_BASE,
#if defined(CUSTOM_UNICODE_ENABLE)
    L_CZECH,
#endif
    L_SYMBOL,
    L_FUNCTION,
    L_MEDIA,
    L_NUMBER,
    L_NUMBER_SYMBOL,
    L_NAVIGATION,
#if defined(MOUSEKEY_ENABLE)
    L_MOUSE,
#endif
    L_SYSTEM,
#if defined(GAMING_ENABLE)
    L_GAME,
    L_GAME_EXTENDED,
#endif
    layers_COUNT,
};

// ========================================================================== //
// Combos
// ========================================================================== //
#if defined(COMBO_ENABLE)
enum combos {
    C_COPY,
    C_SAVE,
    C_FIND,
    C_CAPS_LOCK,
#if defined(CAPS_WORD_ENABLE)
    C_SMART_CASE_CAPS_WORD,
    C_SMART_CASE_MOCKING,
#endif
    combos_COUNT,
};
#endif

// ========================================================================== //
// Tap Dance
// ========================================================================== //
#if defined(TAP_DANCE_ENABLE)
enum tap_dance {
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
#if defined(COURSE_ENABLE)
    TD_SYSTEM_COURSE,
#endif
    TD_DECIMAL_POINT,
    TD_HEX_PREFIX,
    tap_dance_COUNT,
};
#endif

// ========================================================================== //
// Custom Keycodes
// ========================================================================== //
enum custom_keycodes {
    custom_keycodes_START = QK_USER,
    KC_LNCH,
    custom_keycodes_END,
};
_Static_assert((uint16_t)custom_keycodes_END - 1 < (uint16_t)QK_USER_MAX + 1, "Too many custom keycodes!");

// Layers
#define MO_NUM MO(L_NUMBER)
#define MO_NAV MO(L_NAVIGATION)
#define ESC_MED LT(L_MEDIA, KC_ESCAPE)
#define TAB_FUN LT(L_FUNCTION, KC_TAB)
#define SPC_SYM LT(L_SYMBOL, KC_SPACE)
#define SPC_NSY LT(L_NUMBER_SYMBOL, KC_SPACE)
#define BSP_NUM LT(L_NUMBER, KC_BACKSPACE)
#if defined(MOUSEKEY_ENABLE)
    #define TT_MSE TT(L_MOUSE)
#else
    #define TT_MSE KC_NO
#endif

// Zoom
#define Z_PLUS C(KC_EQUAL)
#define Z_MINUS C(KC_MINUS)
#define Z_RESET C(KC_0)

// Czech
#if defined(CUSTOM_UNICODE_ENABLE)
    #define OSL_CZE OSL(L_CZECH)
#else
    #define OSL_CZE KC_NO
#endif

// Tap Dance
#if defined(TAP_DANCE_ENABLE)
    #define CK_DECP TD(TD_DECIMAL_POINT)
    #define CK_HEXP TD(TD_HEX_PREFIX)
#else
    #define CK_DECP KC_DOT
    #define CK_HEXP KC_HASH
#endif

#if defined(TAP_DANCE_ENABLE) && defined(SECRETS_ENABLE)
    #define TD_S1 TD(TD_SECRET1)
    #define TD_S2 TD(TD_SECRET2)
    #define TD_S3 TD(TD_SECRET3)
    #define TD_S4 TD(TD_SECRET4)
    #define TD_S5 TD(TD_SECRET5)
    #define TD_S6 TD(TD_SECRET6)
    #define TD_S7 TD(TD_SECRET7)
    #define TD_S8 TD(TD_SECRET8)
    #define TD_S9 TD(TD_SECRET9)
    #define TD_S10 TD(TD_SECRET10)
    #define TD_S11 TD(TD_SECRET11)
    #define TD_S12 TD(TD_SECRET12)
#else
    #define TD_S1 KC_NO
    #define TD_S2 KC_NO
    #define TD_S3 KC_NO
    #define TD_S4 KC_NO
    #define TD_S5 KC_NO
    #define TD_S6 KC_NO
    #define TD_S7 KC_NO
    #define TD_S8 KC_NO
    #define TD_S9 KC_NO
    #define TD_S10 KC_NO
    #define TD_S11 KC_NO
    #define TD_S12 KC_NO
#endif

// System
#if defined(COURSE_ENABLE) && defined(TAP_DANCE_ENABLE)
    #define CK_SYST TD(TD_SYSTEM_COURSE)
#else
    #define CK_SYST MO(L_SYSTEM)
#endif

// Gaming
#if defined(GAMING_ENABLE)
    #define CK_GON DF(L_GAME)
    #define CK_GOFF DF(L_BASE)
    #define CK_GEXT LT(L_GAME_EXTENDED, KC_ENTER)
#else
    #define CK_GON KC_NO
#endif

// Home Row Mod - left
#define HRK_L4 GUI_T(KC_A)
#define HRK_L3 ALT_T(KC_R)
#define HRK_L2 CTL_T(KC_S)
#define HRK_L1 SFT_T(KC_T)

// Home Row Mod - right
#define HRK_R1 SFT_T(KC_N)
#define HRK_R2 CTL_T(KC_E)
#define HRK_R3 ALT_T(KC_I)
#define HRK_R4 GUI_T(KC_O)

// Shortcuts
#define KC_CMPS COMPOSE_KEY
