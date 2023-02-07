#include QMK_KEYBOARD_H
#include "layers.km.h"
#include "keycodes.km.h"
#if defined(KEY_CHAIN_ENABLE)
    #include "key_chain.f.h"
#endif
#if defined(COMPOSE_ENABLE)
    #include "compose.f.h"
    #include "compose.km.h"
#endif
#if defined(USER_CONFIG_ENABLE)
    #include "user_config.km.h"
#endif

#include "quantum.h"


#if defined(USER_CONFIG_ENABLE)
user_config_t user_config;
#endif

bool is_switching = false;


#define __L1_SYMBOL_________________________    KC_GRV,     XXXXXXX,    XXXXXXX,    KC_LCBR,    KC_RCBR,    KC_CIRC
#define __L2_SYMBOL_________________________    KC_MINS,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_DLR
#define __L3_SYMBOL_________________________    KC_UNDS,    XXXXXXX,    XXXXXXX,    KC_LABK,    KC_RABK,    KC_TILD

#define __R1_SYMBOL_________________________    KC_ASTR,    KC_AMPR,    KC_PERC,    KC_AT,      KC_QUOT,    KC_DQUO
#define __R2_SYMBOL_________________________    KC_HASH,    KC_EQL,     KC_QUES,    KC_EXLM,    KC_COLN,    KC_SCLN
#define __R3_SYMBOL_________________________    KC_PLUS,    KC_PIPE,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [L_BASE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_GRV,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_DQUO,        /**/
    /**/    KC_MINS,    HRK_L4,     HRK_L3,     HRK_L2,     HRK_L1,     KC_P,       KC_MPLY,    /**/    KC_MUTE,    KC_M,       HRK_R1,     HRK_R2,     HRK_R3,     HRK_R4,     KC_SCLN,        /**/
    /**/    KC_UNDS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                G(KC_A),    SH_TG,      /**/    SH_TG,      KC_DEL,                                                                     /**/
    /**/                                        TRK_L4,     TRK_L3,     TRK_L2,     TRK_L1,     /**/    TRK_R1,     TRK_R2,     TRK_R3,     TRK_R4,                                             /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(COMPOSE_ENABLE)
    [L_DIACRITIC] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    _______,    _______,                                                                /**/                                                                _______,    _______,        /**/
    /**/    _______,    _______,    _______,    _______,    CK_Dc,      _______,                /**/                _______,    CK_Ua,      CK_Ur,      CK_Ya,      _______,    _______,        /**/
    /**/    _______,    CK_Aa,      CK_Rc,      CK_Sc,      ___T___,    _______,    _______,    /**/    _______,    _______,    ___T___,    CK_Ec,      CK_Ia,      CK_Oa,      _______,        /**/
    /**/    _______,    CK_Zc,      _______,    CK_Cc,      _______,    _______,                /**/                _______,    _______,    CK_Ea,      _______,    _______,    _______,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    KC_DEL,                                                                     /**/
    /**/                                        KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    KC_BSPC,    XXXXXXX,    ___V___,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_SYMBOL] = LAYOUT_wrapper(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    __L1_SYMBOL_________________________,                                               /**/                __R1_SYMBOL_________________________,                                       /**/
    /**/    __L2_SYMBOL_________________________,                                   _______,    /**/    _______,    __R2_SYMBOL_________________________,                                       /**/
    /**/    __L3_SYMBOL_________________________,                                               /**/                __R3_SYMBOL_________________________,                                       /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    ___T___,                                                                    /**/
    /**/                                        XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    /**/    XXXXXXX,    ___T___,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_FUNCTION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    SWITCH,     KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,                /**/                DM_RSTP,    KC_F17,     KC_F18,     KC_F19,     KC_F20,     XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,    _______,    /**/    _______,    DM_REC1,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY2,                /**/                DM_REC2,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    KC_DEL,                                                                     /**/
    /**/                                        XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    KC_BSPC,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(SWITCHER_ENABLE)
    [L_SWITCH] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_TAB,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    _______,    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    XXXXXXX,                                                                    /**/
    /**/                                        XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    MO_NUM,     MO_NAV,     XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_MEDIA] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_PLUS,     G(KC_MRWD), KC_MRWD,    KC_VOLU,    KC_MFFD,    G(KC_MFFD),             /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_MINUS,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,    _______,    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_RESET,    G(KC_MSTP), KC_MSTP,    KC_MUTE,    KC_MPLY,    G(KC_MPLY),             /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    XXXXXXX,                                                                    /**/
    /**/                                        ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_NUMBER] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                KC_NUM,     XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_SLSH,    KC_ASTR,    KC_MINS,    KC_PLUS,    XXXXXXX,                /**/                KC_ASTR,    KC_7,       KC_8,       KC_9,       KC_SLSH,    KC_PERC,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    _______,    /**/    _______,    CK_DECP,    KC_4,       KC_5,       KC_6,       KC_0,       KC_ENT,         /**/
    /**/    XXXXXXX,    KC_Y,       KC_X,       XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_PLUS,    KC_1,       KC_2,       KC_3,       KC_MINS,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    KC_CALC,                                                                    /**/
    /**/                                        KC_ESC,     KC_TAB,     NUM_SPC,    KC_ENT,     /**/    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_NUMBER_SYMBOL] = LAYOUT_wrapper(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    __L1_SYMBOL_________________________,                                               /**/                __R1_SYMBOL_________________________,                                       /**/
    /**/    __L2_SYMBOL_________________________,                                   _______,    /**/    _______,    __R2_SYMBOL_________________________,                                       /**/
    /**/    __L3_SYMBOL_________________________,                                               /**/                __R3_SYMBOL_________________________,                                       /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    XXXXXXX,                                                                    /**/
    /**/                                        XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    /**/    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_NAVIGATION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                KC_SCRL,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    _______,    /**/    _______,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    KC_ENT,         /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_INS,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    XXXXXXX,                                                                    /**/
    /**/                                        KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_SYSTEM] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                KC_PAUS,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    QK_RBT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    /**/    _______,    QK_MAKE,    XXXXXXX,    EE_CLR,     XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_BOOT,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    _______,    /**/    _______,    XXXXXXX,                                                                    /**/
    /**/                                        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /**/    ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(GAMING_ENABLE)
    [L_GAME] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_ESC,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_TAB,     KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       KC_MPLY,    /**/    KC_MUTE,    KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_LSFT,        /**/
    /**/    KC_F1,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_DQUO,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                                        KC_LALT,    KC_LCTL,    KC_SPC,     XXXXXXX,    /**/    CK_GEXT,    KC_BSPC,    KC_DEL,     CK_GOFF,                                            /**/
    /*                                                                                                                                                                                            */
    _),
    [L_GAME_EXTENDED] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,                                                                /**/                                                                XXXXXXX,    XXXXXXX,        /**/
    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PSCR,                /**/                KC_PERC,    KC_ASTR,    KC_AT,      KC_PLUS,    KC_MINS,    KC_UNDS,        /**/
    /**/    C(KC_F7),   C(KC_F8),   C(KC_F9),   C(KC_F10),  C(KC_F11),  C(KC_F12),  _______,    /**/    _______,    KC_HASH,    KC_EQL,     KC_SCLN,    KC_COLN,    KC_DQUO,    XXXXXXX,        /**/
    /**/    C(KC_F1),   C(KC_F2),   C(KC_F3),   C(KC_F4),   C(KC_F5),   C(KC_F6),               /**/                KC_EXLM,    KC_QUES,    KC_COMM,    KC_DOT,     KC_QUOT,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                                        XXXXXXX,    XXXXXXX,    S(KC_ENT),  ___V___,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                            /**/
    /*                                                                                                                                                                                            */
    _),
#endif
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
#if defined(COMPOSE_ENABLE)
    if (process_compose(keycode, record) == PROCESS_HANDLED) {
        return PROCESS_HANDLED;
    }
#endif
#if defined(KEY_CHAIN_ENABLE)
    if (process_key_chain(keycode, record) == PROCESS_HANDLED) {
        return PROCESS_HANDLED;
    }
#endif
    switch (keycode) {
#if defined(SWITCHER_ENABLE)
        case SWITCH:
            if (record->event.pressed) {
                is_switching = true;
                register_mods(MOD_BIT(SWITCH_MOD_KEY));
                register_code(KC_TAB);
                layer_on(L_SWITCH);
            }
            else {
                unregister_code(KC_TAB);
            }
            return PROCESS_HANDLED;
#endif
#if defined(COMPOSE_ENABLE)
        case HRK_L1:
        case HRK_R1:
            if (layer_state_is(L_DIACRITIC)) {
                if (record->tap.count) {
                    if (record->event.pressed) {
                        uint8_t compose_index;
                        switch (QK_MOD_TAP_GET_TAP_KEYCODE(keycode)) {
                            case KC_T: compose_index = XC_Tc; break;
                            case KC_N: compose_index = XC_Nc; break;
                            default: return PROCESS_HANDLED;
                        }
                        process_compose_direct(compose_index);
                    }
                    return PROCESS_HANDLED;
                }
            }
            break;
#endif
#if defined(KEY_CHAIN_ENABLE)
        case TRK_R1:
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
#if defined(SWITCHER_ENABLE)
    if (is_switching && !layer_state_cmp(state, L_FUNCTION)) {
        is_switching = false;
        state &= ~(1 << L_SWITCH);
        unregister_mods(MOD_BIT(SWITCH_MOD_KEY));
    }
#endif
    return state;
}

#if defined(TAPPING_FORCE_HOLD_PER_KEY)
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true;
    }
}
#endif
