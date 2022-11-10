#pragma once

#include "layers.km.h"
#if defined(COMPOSE_ENABLE)
    #include "compose.km.h"
#endif
#if defined(COMBO_ENABLE)
    #include "combo.km.h"
#endif
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dance.km.h"
#endif

#include "keycode.h"
#include "quantum_keycodes.h"


#define ___V___ KC_TRANSPARENT
#define ___T___ KC_TRANSPARENT
#define _XXXXX_ KC_TRANSPARENT


// Custom keycodes
enum custom_keycodes {
    CK__SAFE_RANGE = SAFE_RANGE, // ~0x5D00

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

    CK__SAFE_RANGE_MAX,

    CK_COMPOSE     = 0x5E00,
    CK_COMPOSE_MAX = 0x5EFF,

    // Maximum possible custom keycode is 0x5FFF
};
_Static_assert(CK__SAFE_RANGE_MAX <= 0x5E00, "too many custom keycodes");

#define COMPOSE(index) (CK_COMPOSE | ((index) & 0xFF))

// Diacritic
#if defined(COMPOSE_ENABLE)
    #define OSL_DIA OSL(L_DIACRITIC)
    #define CK_Ua COMPOSE(XC_Ua)
    #define CK_Ea COMPOSE(XC_Ea)
    #define CK_Ia COMPOSE(XC_Ia)
    #define CK_Oa COMPOSE(XC_Oa)
    #define CK_Aa COMPOSE(XC_Aa)
    #define CK_Ya COMPOSE(XC_Ya)
    #define CK_Ec COMPOSE(XC_Ec)
    #define CK_Rc COMPOSE(XC_Rc)
    #define CK_Tc COMPOSE(XC_Tc)
    #define CK_Zc COMPOSE(XC_Zc)
    #define CK_Sc COMPOSE(XC_Sc)
    #define CK_Dc COMPOSE(XC_Dc)
    #define CK_Cc COMPOSE(XC_Cc)
    #define CK_Nc COMPOSE(XC_Nc)
    #define CK_Ur COMPOSE(XC_Ur)
#else
    #define OSL_DIA KC_NO
#endif

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
#if defined(KEY_CHAIN_ENABLE)
    // In process_record() : KC_NO => key_chain_start()
    #define TRK_R1 LT(L_SYSTEM, KC_NO)
#else
    #define TRK_R1 MO(L_SYSTEM)
#endif
#define TRK_R2 LT(L_NUMBER, KC_BACKSPACE)
#define TRK_R3 MO(L_NAVIGATION)
#define TRK_R4 LT(L_VI, COMPOSE_KEY)

// Other
#define NUM_SPC LT(L_NUMBER_SYMBOL, KC_SPACE)
