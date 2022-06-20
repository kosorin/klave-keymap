#pragma once

#include "layers.km.h"
#if defined(UNICODEMAP_ENABLE)
    #include "unicode_map.km.h"
#endif
#if defined(COMBO_ENABLE)
    #include "combo.km.h"
#endif
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dance.km.h"
#endif

#include "keycode.h"
#include "quantum_keycodes.h"


enum custom_keycodes {
    CK__SAFE_RANGE = SAFE_RANGE,
#if defined(KEY_CHAIN_ENABLE)
    KEY_CHAIN,
#else
    #define KEY_CHAIN KC_NO
#endif
};


#define _TO_DO_ KC_NO
#define ___V___ KC_TRANSPARENT
#define ___T___ KC_TRANSPARENT


#if defined(UNICODEMAP_ENABLE)
    #define CK_UC MO(L_UNICODE)
    #define X_Ua XP(U_Ual, U_Uau)
    #define X_Ea XP(U_Eal, U_Eau)
    #define X_Ia XP(U_Ial, U_Iau)
    #define X_Oa XP(U_Oal, U_Oau)
    #define X_Aa XP(U_Aal, U_Aau)
    #define X_Ya XP(U_Yal, U_Yau)
    #define X_Ec XP(U_Ecl, U_Ecu)
    #define X_Rc XP(U_Rcl, U_Rcu)
    #define X_Tc XP(U_Tcl, U_Tcu)
    #define X_Zc XP(U_Zcl, U_Zcu)
    #define X_Sc XP(U_Scl, U_Scu)
    #define X_Dc XP(U_Dcl, U_Dcu)
    #define X_Cc XP(U_Ccl, U_Ccu)
    #define X_Nc XP(U_Ncl, U_Ncu)
    #define X_Ur XP(U_Url, U_Uru)
#else
    #define CK_UC KC_NO
#endif

#if defined(TAP_DANCE_ENABLE)
    #define CK_DECP TD(TD_DECIMAL_POINT)
#else
    #define CK_DECP KC_DOT
#endif

#define CK_GON TO(L_GAME)
#define CK_GOFF TG(L_GAME)
#define CK_GEXT LT(L_GAME_EXTENDED, KC_ENTER)

#define HRK_L4 GUI_T(KC_A)
#define HRK_L3 ALT_T(KC_R)
#define HRK_L2 CTL_T(KC_S)
#define HRK_L1 SFT_T(KC_T)
#define HRK_R1 SFT_T(KC_N)
#define HRK_R2 CTL_T(KC_E)
#define HRK_R3 ALT_T(KC_I)
#define HRK_R4 GUI_T(KC_O)
#define TRK_L4 LT(L_MEDIA, KC_ESCAPE)
#define TRK_L3 LT(L_FUNCTION, KC_TAB)
#define TRK_L2 LT(L_SYMBOL, KC_SPACE)
#define TRK_L1 KC_ENTER
#define TRK_R1 COMPOSE_KEY
#define TRK_R2 LT(L_NUMBER, KC_BACKSPACE)
#define TRK_R3 LT(L_NAVIGATION, KC_DELETE)
#define TRK_R4 LT(L_SYSTEM, KC_NO)
