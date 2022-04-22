#pragma once

#include QMK_KEYBOARD_H


typedef union {
    uint32_t raw;
    struct {
#if defined(ENCODER_ENABLE)
        bool encoder_scroll_mode : 1;
#endif
    };
} user_config_t;


#if defined(UNICODEMAP_ENABLE)
enum unicode_names {
    U_Ual,
    U_Eal,
    U_Ial,
    U_Oal,
    U_Aal,
    U_Yal,
    U_Ecl,
    U_Rcl,
    U_Tcl,
    U_Zcl,
    U_Scl,
    U_Dcl,
    U_Ccl,
    U_Ncl,
    U_Url,
    U_Uau,
    U_Eau,
    U_Iau,
    U_Oau,
    U_Aau,
    U_Yau,
    U_Ecu,
    U_Rcu,
    U_Tcu,
    U_Zcu,
    U_Scu,
    U_Dcu,
    U_Ccu,
    U_Ncu,
    U_Uru,
    U_DEG,
    U_ACUTE,
    U_CARON,
    U_BDQUO,
    U_LDQUO,
    U_BSQUO,
    U_LSQUO,
    U_RAQUO,
    U_LAQUO,
    U_RSAQUO,
    U_LSAQUO,
    U_RDQUO,
    U_RSQUO,
    U_NDASH,
    U_MDASH,
    U_NBSP,
    U_ELLIP,
    U_MIDDOT,
    U_EURO,
    U_CENT,
    U_POUND,
    U_CURR,
    U_YEN,
    U_WON,
    U_RUPEE,
    U_BTC,
};
#endif

#if defined(TAP_DANCE_ENABLE)
enum tap_dances {
#if defined(UNICODEMAP_ENABLE)
    TD_LUC,
    TD_RUC,
#endif
    TD_CLR,
    TD_BOOT,
    TD_LCK_SLP,
};
#endif

enum layers {
    L_BASE,
#if defined(UNICODEMAP_ENABLE)
    L_UNICODE,
#endif
    L_LOWER,
    L_RAISE,
    L_ADJUST,
};

enum custom_keycodes {
    K_SAFE_RANGE = SAFE_RANGE,
#if defined(CUSTOM_LEADER_ENABLE)
    K_LEAD,
#endif
#if defined(ENCODER_ENABLE)
    K_ENC_SM,
#endif
};


enum keycode_aliases {
    IIIIIII = XXXXXXX,
    __LYR__ = _______,
    __MOD__ = _______,
    __SPC__ = _______,
    __NPC__ = _______,
    __ESC__ = _______,
    __TAB__ = _______,

    K_LWR = TT(L_LOWER),
    K_RSE = TT(L_RAISE),

#if defined(TAP_DANCE_ENABLE)
    K_CLR = TD(TD_CLR),
    K_BOOT = TD(TD_BOOT),
    K_LCK_SLP = TD(TD_LCK_SLP),
#else
    K_CLR = EE_CLR,
    K_BOOT = QK_BOOT,
    K_LCK_SLP = RGUI(KC_L),
#endif

#if defined(UNICODEMAP_ENABLE) && defined(TAP_DANCE_ENABLE)
    K_LUC = TD(TD_LUC),
    K_RUC = TD(TD_RUC),
#elif defined(UNICODEMAP_ENABLE)
    K_LUC = MO(L_UNICODE),
    K_RUC = MO(L_UNICODE),
#else
    K_LUC = KC_NO,
    K_RUC = KC_NO,
#endif

#if defined(UNICODEMAP_ENABLE)
    K_Ua = XP(U_Ual, U_Uau),
    K_Ea = XP(U_Eal, U_Eau),
    K_Ia = XP(U_Ial, U_Iau),
    K_Oa = XP(U_Oal, U_Oau),
    K_Aa = XP(U_Aal, U_Aau),
    K_Ya = XP(U_Yal, U_Yau),
    K_Ec = XP(U_Ecl, U_Ecu),
    K_Rc = XP(U_Rcl, U_Rcu),
    K_Tc = XP(U_Tcl, U_Tcu),
    K_Zc = XP(U_Zcl, U_Zcu),
    K_Sc = XP(U_Scl, U_Scu),
    K_Dc = XP(U_Dcl, U_Dcu),
    K_Cc = XP(U_Ccl, U_Ccu),
    K_Nc = XP(U_Ncl, U_Ncu),
    K_Ur = XP(U_Url, U_Uru),
    K_N_M_DASH = XP(U_NDASH, U_MDASH),
#endif

#if !defined(CUSTOM_LEADER_ENABLE)
    K_LEAD = KC_NO,
#endif

#if !defined(ENCODER_ENABLE)
    K_ENC_SM = KC_NO,
#endif

    K_WINC = UNICODE_KEY_WINC,
};
