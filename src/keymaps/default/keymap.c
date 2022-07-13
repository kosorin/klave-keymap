#include QMK_KEYBOARD_H
#include "layers.km.h"
#include "keycodes.km.h"
#if defined(KEY_CHAIN_ENABLE)
    #include "features/key_chain.f.h"
#endif
#if defined(USER_CONFIG_ENABLE)
    #include "user_config.km.h"
#endif

#include "quantum.h"


#if defined(USER_CONFIG_ENABLE)
user_config_t user_config;
#endif


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [L_BASE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    KC_GRV,     KC_Q,       KC_W,       KT_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KT_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_SLSH,    HRK_L4,     HRK_L3,     HRK_L2,     HRK_L1,     KC_P,       KC_MPLY,    /**/    KC_MUTE,    KC_M,       HRK_R1,     HRK_R2,     HRK_R3,     HRK_R4,     KC_SCLN,        /**/
    /**/    KC_BSLS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_QUOT,    KC_DQUO,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        TRK_L4,     TRK_L3,     TRK_L2,     TRK_L1,     /**/    TRK_R1,     TRK_R2,     TRK_R3,     TRK_R4,                                             /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(UNICODEMAP_ENABLE)
    [L_UNICODE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    _______,    _______,    _______,    ___V___,    X_Dc,       _______,                /**/                _______,    X_Nc,       ___V___,    X_Ya,       _______,    _______,        /**/
    /**/    _______,    X_Aa,       X_Rc,       X_Sc,       X_Tc,       _______,    _______,    /**/    _______,    _______,    X_Ec,       X_Ea,       X_Ia,       X_Oa,       _______,        /**/
    /**/    _______,    X_Zc,       _______,    X_Cc,       _______,    _______,                /**/                _______,    X_Ur,       X_Ua,       _______,    _______,    _______,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    KC_BSPC,    KC_DEL,     XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_SYMBOL] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    _______,    XXXXXXX,    XXXXXXX,    KC_LCBR,    KC_RCBR,    KC_CIRC,                /**/                KC_PERC,    KC_PLUS,    KC_AMPR,    KC_PIPE,    _______,    _______,        /**/
    /**/    _______,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_DLR,     _______,    /**/    _______,    KC_HASH,    KC_EQL,     KC_QUES,    KC_EXLM,    KC_COLN,    _______,        /**/
    /**/    _______,    XXXXXXX,    XXXXXXX,    KC_LABK,    KC_RABK,    KC_TILD,                /**/                KC_AT,      KC_ASTR,    _______,    _______,    _______,    _______,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    /**/    XXXXXXX,    ___T___,    ___T___,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_FUNCTION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    KC_PAUS,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,                /**/                XXXXXXX,    KC_F13,     KC_F14,     KC_F17,     KC_F16,     XXXXXXX,        /**/
    /**/    KC_INS,     KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,    _______,    /**/    _______,    XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY2,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    KC_BSPC,    KC_DEL,     XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_NAVIGATION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_SCRL,    _______,    /**/    _______,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_APP,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_NUMBER] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_MINS,    KC_PLUS,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NUM,     _______,    /**/    _______,    KC_ASTR,    KC_4,       KC_5,       KC_6,       KC_0,       KC_EQL,         /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_ENT,     KC_1,       KC_2,       KC_3,       CK_DECP,    KC_CALC,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_MEDIA] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    KC_MRWD,    KC_VOLU,    KC_MFFD,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,    _______,    /**/    _______,    XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    KC_MSTP,    KC_MUTE,    KC_MPLY,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_SYSTEM] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    UC_M_WC,    UC_M_LN,    XXXXXXX,    XXXXXXX,    KC_SYRQ,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC1,    _______,    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC2,                /**/                XXXXXXX,    CK_GON,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    ___V___,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_GAME] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    KC_ESC,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_TAB,     KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       _______,    /**/    _______,    KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_LSFT,        /**/
    /**/    KC_F1,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_DQUO,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        KC_LALT,    KC_LCTL,    KC_SPC,     XXXXXXX,    /**/    CK_GEXT,    KC_BSPC,    KC_DEL,     CK_GOFF,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_GAME_EXTENDED] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PSCR,                /**/                KC_PERC,    KC_ASTR,    KC_AT,      KC_PLUS,    KC_MINS,    KC_UNDS,        /**/
    /**/    C(KC_F7),   C(KC_F8),   C(KC_F9),   C(KC_F10),  C(KC_F11),  C(KC_F12),  _______,    /**/    _______,    KC_HASH,    KC_EQL,     KC_SCLN,    KC_COLN,    KC_DQUO,    XXXXXXX,        /**/
    /**/    C(KC_F1),   C(KC_F2),   C(KC_F3),   C(KC_F4),   C(KC_F5),   C(KC_F6),               /**/                KC_EXLM,    KC_QUES,    KC_COMM,    KC_DOT,     KC_QUOT,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                        XXXXXXX,    XXXXXXX,    S(KC_ENT),  ___V___,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
};


void eeconfig_init_user(void) {
#if defined(USER_CONFIG_ENABLE)
    user_config.raw = 0;
    user_config_reset_user();
    eeconfig_update_user(user_config.raw);
#endif
}

void keyboard_pre_init_user(void) {
#if defined(USER_CONFIG_ENABLE)
    user_config.raw = eeconfig_read_user();
#endif
}

void keyboard_post_init_user(void) {
#if defined(CONSOLE_ENABLE) && !defined(NO_DEBUG)
    debug_enable = true;
#endif
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(KEY_CHAIN_ENABLE)
    if (process_key_chain(keycode, record) == PROCESS_HANDLED) {
        return PROCESS_HANDLED;
    }
#endif
    switch (keycode) {
#if defined(KEY_CHAIN_ENABLE)
        case TRK_R4:
            if (record->tap.count) {
                if (record->event.pressed) {
                    key_chain_start();
                }
                return PROCESS_HANDLED;
            }
            break;
#endif
    }
    return PROCESS_NOT_HANDLED;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            break;
    }
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}
