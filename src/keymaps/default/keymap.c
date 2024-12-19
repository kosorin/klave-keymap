#include "keymap.h"
#include QMK_KEYBOARD_H
#if defined(KEYBOARD_klave_rev1)
    #include "promicro_led.h"
#endif
#if defined(COURSE_ENABLE)
    #include "features/course.h"
#endif
#if defined(CUSTOM_UNICODE_ENABLE)
    #include "features/custom_unicode.h"
#endif
#if defined(CAPS_WORD_ENABLE)
    #include "features/smart_case.h"
#endif
#if defined(TAP_DANCE_ENABLE)
    #include "features/tap_dance.h"
#endif
#if defined(SECRETS_ENABLE)
    #include "keymap_secrets.h"
#endif
#include "quantum.h"


// ========================================================================== //
// Keymap
// ========================================================================== //

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [L_BASE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    TD_S1,      TD_S2,      TD_S3,      TD_S4,      TD_S5,      TD_S6,                  /**/                TD_S7,      TD_S8,      TD_S9,      TD_S10,     TD_S11,     TD_S12,         /**/
    /**/    KC_DQUO,    KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_QUOT,    HRK_L4,     HRK_L3,     HRK_L2,     HRK_L1,     KC_P,                   /**/                KC_M,       HRK_R1,     HRK_R2,     HRK_R3,     HRK_R4,     KC_SCLN,        /**/
    /**/    KC_GRV,     KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                KC_LNCH,    KC_PSCR,    /**/    KC_INS,     CK_SYST,                                                                    /**/
    /**/                            KC_ALTB,    ESC_MED,    TAB_FUN,    SPC_SYM,    KC_ENT,     /**/    KC_DEL,     BSP_NUM,    MO_NAV,     OSL_CZE,    KC_CMPS                                 /**/
    /*                                                                                                                                                                                            */
    ),
#if defined(CUSTOM_UNICODE_ENABLE)
    [L_CZECH] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    _______,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/    _______,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/    _______,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/    _______,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                _______,    _______,    /**/    _______,    _______,                                                                    /**/
    /**/                            _______,    _______,    _______,    _______,    _______,    /**/    _______,    _______,    _______,    ___V___,    _______                                 /**/
    /*                                                                                                                                                                                            */
    ),
#endif
    [L_SYMBOL] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_DQUO,    KC_CIRC,    KC_DLR,     KC_LCBR,    KC_RCBR,    XXXXXXX,                /**/                KC_PLUS,    KC_PIPE,    KC_PERC,    KC_AT,      KC_MINS,    KC_UNDS,        /**/
    /**/    KC_QUOT,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    XXXXXXX,                /**/                KC_HASH,    KC_EQL,     KC_QUES,    KC_EXLM,    KC_COLN,    KC_SCLN,        /**/
    /**/    KC_GRV,     KC_TILD,    XXXXXXX,    KC_LABK,    KC_RABK,    XXXXXXX,                /**/                KC_ASTR,    KC_AMPR,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    /**/    KC_DEL,     ___T___,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_FUNCTION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,                /**/                DM_RSTP,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,                /**/                DM_REC1,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY2,                /**/                DM_REC2,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    /**/    KC_DEL,     KC_BSPC,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_MEDIA] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_PLUS,     G(KC_MRWD), KC_MRWD,    KC_VOLU,    KC_MFFD,    G(KC_MFFD),             /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_MINUS,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    Z_RESET,    G(KC_MSTP), KC_MSTP,    KC_MUTE,    KC_MPLY,    G(KC_MPLY),             /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_NUMBER] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    KC_D,       KC_E,       KC_F,       XXXXXXX,                /**/                KC_PLUS,    KC_7,       KC_8,       KC_9,       KC_MINS,    KC_UNDS,        /**/
    /**/    XXXXXXX,    KC_LGUI,    ALT_T(KC_A),CTL_T(KC_B),SFT_T(KC_C),CK_HEXP,                /**/                CK_DECP,    KC_4,       KC_5,       KC_6,       KC_0,       KC_ENT,         /**/
    /**/    XXXXXXX,    XXXXXXX,    KC_X,       KC_Y,       KC_Z,       XXXXXXX,                /**/                KC_ASTR,    KC_1,       KC_2,       KC_3,       KC_SLSH,    KC_PERC,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    KC_CALC,                                                                    /**/
    /**/                            XXXXXXX,    KC_ESC,     KC_TAB,     SPC_NSY,    KC_ENT,     /**/    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_NUMBER_SYMBOL] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_DQUO,    KC_CIRC,    KC_DLR,     KC_LCBR,    KC_RCBR,    XXXXXXX,                /**/                KC_PLUS,    KC_PIPE,    KC_PERC,    KC_AT,      KC_MINS,    KC_UNDS,        /**/
    /**/    KC_QUOT,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    XXXXXXX,                /**/                KC_HASH,    KC_EQL,     KC_QUES,    KC_EXLM,    KC_COLN,    KC_SCLN,        /**/
    /**/    KC_GRV,     KC_TILD,    XXXXXXX,    KC_LABK,    KC_RABK,    XXXXXXX,                /**/                KC_ASTR,    KC_AMPR,    KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    /**/    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_NAVIGATION] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,                /**/                XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,    KC_ENT,         /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_PGDN,    KC_PGUP,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    XXXXXXX,    ___V___,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
#if defined(MOUSEKEY_ENABLE)
    [L_MOUSE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_ACL1,    KC_BTN4,    KC_WH_U,    KC_BTN5,    XXXXXXX,                /**/                XXXXXXX,    KC_BTN4,    KC_MS_U,    KC_BTN5,    KC_ACL1,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_ACL0,    KC_WH_L,    KC_WH_D,    KC_WH_R,    XXXXXXX,                /**/                XXXXXXX,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_ACL0,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_ACL2,    KC_BTN2,    KC_BTN3,    KC_BTN1,    XXXXXXX,                /**/                KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    KC_ACL2,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            ___V___,    KC_ESC,     KC_TAB,     KC_SPC,     KC_ENT,     /**/    XXXXXXX,    KC_BTN1,    KC_BTN3,    KC_BTN2,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
#endif
    [L_SYSTEM] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_NUM,     KC_SCRL,    KC_PAUS,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    ___V___,                                                                    /**/
    /**/                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_MAKE,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
#if defined(GAMING_ENABLE)
    [L_GAME] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    KC_ESC,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_TAB,     KC_A,       KC_R,       KC_S,       KC_T,       KC_P,                   /**/                KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_LSFT,        /**/
    /**/    KC_F1,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_DQUO,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    KC_LALT,    KC_LCTL,    KC_SPC,     XXXXXXX,    /**/    CK_GEXT,    KC_BSPC,    KC_DEL,     CK_GOFF,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
    [L_GAME_EXTENDED] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PSCR,                /**/                KC_PERC,    KC_ASTR,    KC_AT,      KC_PLUS,    KC_MINS,    KC_UNDS,        /**/
    /**/    C(KC_F7),   C(KC_F8),   C(KC_F9),   C(KC_F10),  C(KC_F11),  C(KC_F12),              /**/                KC_HASH,    KC_EQL,     KC_SCLN,    KC_COLN,    KC_DQUO,    XXXXXXX,        /**/
    /**/    C(KC_F1),   C(KC_F2),   C(KC_F3),   C(KC_F4),   C(KC_F5),   C(KC_F6),               /**/                KC_EXLM,    KC_QUES,    KC_COMM,    KC_DOT,     KC_QUOT,    XXXXXXX,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            XXXXXXX,    XXXXXXX,    XXXXXXX,    S(KC_ENT),  ___V___,    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX                                 /**/
    /*                                                                                                                                                                                            */
    ),
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(COURSE_ENABLE)
    if (process_course(keycode, record) == PROCESS_HANDLED) {
        return PROCESS_HANDLED;
    }
#endif
#if defined(CUSTOM_UNICODE_ENABLE)
    if (process_record_custom_unicode(keycode, record) == PROCESS_HANDLED) {
        return PROCESS_HANDLED;
    }
#endif
    switch (keycode) {
        case KC_LNCH:
            if (record->event.pressed) {
#if defined(OS_DETECTION_ENABLE)
                switch (detected_host_os()) {
                    case OS_LINUX:
                        tap_code16(QK_LGUI | KC_A);
                        break;
                    default:
                        tap_code(KC_LEFT_GUI);
                        break;
                }
#else
                tap_code(KC_LEFT_GUI);
#endif
            }
            return PROCESS_HANDLED;
        case KC_ALTB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(50);
                tap_code_delay(KC_TAB, 50);
            }
            else {
                wait_ms(50);
                unregister_code(KC_LALT);
            }
            return PROCESS_HANDLED;
    }
    return PROCESS_NOT_HANDLED;
}


// ========================================================================== //
// Layers
// ========================================================================== //

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}


// ========================================================================== //
// Tapping
// ========================================================================== //

#if defined(TAPPING_TERM_PER_KEY)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if defined(COURSE_ENABLE) && defined(TAP_DANCE_ENABLE)
        case TD(TD_SYSTEM_COURSE):
            return COURSE_TAPPING_TERM;
#endif
        default:
            return TAPPING_TERM;
    }
}
#endif

#if defined(QUICK_TAP_TERM_PER_KEY)
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if defined(MOUSEKEY_ENABLE)
        case TT_MSE:
            return QUICK_TAP_TERM;
#endif
        default:
            return 0;
    }
}
#endif


// ========================================================================== //
// One Shot
// ========================================================================== //

void oneshot_layer_changed_user(uint8_t layer) {
#if defined(CUSTOM_UNICODE_ENABLE)
    if (layer == L_CZECH) {
        set_unicode_typing_mode(UCTM_CZECH);
    }
    else {
        clear_unicode_typing_mode();
    }
#endif
}


// ========================================================================== //
// Combos
// ========================================================================== //
#if defined(COMBO_ENABLE)

const uint16_t combo_COPY[] PROGMEM = { KC_X, KC_C, COMBO_END };
const uint16_t combo_SAVE[] PROGMEM = { HRK_L3, HRK_L2, COMBO_END };
const uint16_t combo_FIND[] PROGMEM = { KC_W, KC_F, COMBO_END };
const uint16_t combo_CAPS_LOCK[] PROGMEM = { KC_P, KC_M, COMBO_END };
#if defined(CAPS_WORD_ENABLE)
const uint16_t combo_SMART_CASE_CAPS_WORD[] PROGMEM = { HRK_L1, HRK_R1, COMBO_END };
const uint16_t combo_SMART_CASE_MOCKING[] PROGMEM = { HRK_L1, HRK_R1, KC_F, KC_U, COMBO_END };
#endif

combo_t key_combos[] = {
    [C_COPY] = COMBO(combo_COPY, C(KC_C)),
    [C_SAVE] = COMBO(combo_SAVE, C(KC_S)),
    [C_FIND] = COMBO(combo_FIND, C(KC_F)),
    [C_CAPS_LOCK] = COMBO(combo_CAPS_LOCK, KC_CAPS_LOCK),
#if defined(CAPS_WORD_ENABLE)
    [C_SMART_CASE_CAPS_WORD] = COMBO_ACTION(combo_SMART_CASE_CAPS_WORD),
    [C_SMART_CASE_MOCKING] = COMBO_ACTION(combo_SMART_CASE_MOCKING),
#endif
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
#if defined(CAPS_WORD_ENABLE)
        case C_SMART_CASE_CAPS_WORD:
            if (pressed) {
                caps_word_toggle();
                set_smart_case(SC_CAPS_WORD);
            }
            break;
        case C_SMART_CASE_MOCKING:
            if (pressed) {
                caps_word_toggle();
                set_smart_case(SC_MOCKING);
            }
            break;
#endif
        default:
            break;
    }
}

#ifdef COMBO_PROCESS_KEY_RELEASE
bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    return false;
}
#endif

#ifdef COMBO_SHOULD_TRIGGER
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return true;
}
#endif

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    return COMBO_TERM;
}
#endif

#ifdef COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    return false;
}
#endif

#ifdef COMBO_MUST_HOLD_PER_COMBO
bool get_combo_must_hold(uint16_t combo_index, combo_t *combo) {
    return false;
}
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_CAPS_LOCK:
            return false;
        default:
            return true;
    }
}
#endif

#endif


// ========================================================================== //
// Tap Dance
// ========================================================================== //
#if defined(TAP_DANCE_ENABLE)

static tap_dance_context_t td_context = {
    .result = TDS_NONE,
};


#if defined(COURSE_ENABLE)

static void finished_system_course(tap_dance_state_t *state, void *user_data) {
    td_context.result = get_tap_dance_result(state);
    switch (td_context.result) {
        case TDS_SINGLE_TAP:
            course_start(COURSE_HANDLER(main));
            break;
#if defined(SECRETS_ENABLE)
        case TDS_DOUBLE_TAP:
            course_start(COURSE_HANDLER(secret));
            break;
#endif
        case TDS_SINGLE_HOLD:
            layer_on(L_SYSTEM);
            break;
        default:
            break;
    }
}

static void reset_system_course(tap_dance_state_t *state, void *user_data) {
    switch (td_context.result) {
        case TDS_SINGLE_HOLD:
            layer_off(L_SYSTEM);
            break;
        default:
            break;
    }
    td_context.result = TDS_NONE;
}

#endif

static void finished_hex_prefix(tap_dance_state_t *state, void *user_data) {
    td_context.result = get_tap_dance_result(state);
    switch (td_context.result) {
        case TDS_SINGLE_TAP:
            tap_code16(KC_HASH);
            break;
        case TDS_SINGLE_HOLD:
            register_code16(KC_HASH);
            break;
        case TDS_DOUBLE_TAP:
            SEND_STRING("0x");
            break;
        default:
            break;
    }
}

static void reset_hex_prefix(tap_dance_state_t *state, void *user_data) {
    switch (td_context.result) {
        case TDS_SINGLE_HOLD:
            unregister_code16(KC_HASH);
            break;
        default:
            break;
    }
    td_context.result = TDS_NONE;
}


tap_dance_action_t tap_dance_actions[] = {
#if defined(SECRETS_ENABLE)
    [TD_SECRET1] = ACTION_TAP_DANCE_FN(tap_dance_secret1),
    [TD_SECRET2] = ACTION_TAP_DANCE_FN(tap_dance_secret2),
    [TD_SECRET3] = ACTION_TAP_DANCE_FN(tap_dance_secret3),
    [TD_SECRET4] = ACTION_TAP_DANCE_FN(tap_dance_secret4),
    [TD_SECRET5] = ACTION_TAP_DANCE_FN(tap_dance_secret5),
    [TD_SECRET6] = ACTION_TAP_DANCE_FN(tap_dance_secret6),
    [TD_SECRET7] = ACTION_TAP_DANCE_FN(tap_dance_secret7),
    [TD_SECRET8] = ACTION_TAP_DANCE_FN(tap_dance_secret8),
    [TD_SECRET9] = ACTION_TAP_DANCE_FN(tap_dance_secret9),
    [TD_SECRET10] = ACTION_TAP_DANCE_FN(tap_dance_secret10),
    [TD_SECRET11] = ACTION_TAP_DANCE_FN(tap_dance_secret11),
    [TD_SECRET12] = ACTION_TAP_DANCE_FN(tap_dance_secret12),
#endif
#if defined(COURSE_ENABLE)
    [TD_SYSTEM_COURSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_system_course, reset_system_course),
#endif
    [TD_DECIMAL_POINT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
    [TD_HEX_PREFIX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_hex_prefix, reset_hex_prefix),
};

#endif


// ========================================================================== //
// Caps Word & Smart Case
// ========================================================================== //
#if defined(CAPS_WORD_ENABLE)

void caps_word_set_user(bool active) {
    clear_smart_case();
}

bool caps_word_press_user(uint16_t keycode) {
    switch (smart_case_press(keycode)) {
        case SCR_LOWER:
            return true;
        case SCR_UPPER:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        default:
            return false;
    }
}

#endif


// ========================================================================== //
// Course
// ========================================================================== //
#if defined(COURSE_ENABLE)

static void send_random_number(uint8_t digit_count) {
    bool any = false;
    for (uint8_t i = 0; i < digit_count; i++) {
        uint8_t digit = rand() % 10;
        if (digit == 0) {
            if (any) {
                digit += 10;
            }
            else {
                continue;
            }
        }
        any = true;
        tap_code((KC_1 - 1) + digit);
    }
    if (!any) {
        tap_code(KC_0);
    }
}

static DEFINE_COURSE_HANDLER(random_number) {
    static uint8_t digit_count = 3;
    switch (keycode) {
        case KC_1 ... KC_9:
            digit_count = keycode - KC_1 + 1;
        case KC_N:
            send_random_number(digit_count);
            return course_again();
        case KC_SPACE:
        case KC_BACKSPACE:
        case KC_DELETE:
        case KC_TAB:
        case KC_ENTER:
        case KC_DOT:
        case KC_COMMA:
            tap_code(keycode);
            return course_again();
        default:
            return course_bad_key();
    }
}

static DEFINE_COURSE_HANDLER(random) {
    switch (keycode) {
        case KC_N:
            return COURSE_HANDLER(random_number);
        default:
            return course_bad_key();
    }
}

#if defined(CUSTOM_UNICODE_ENABLE)

static DEFINE_COURSE_HANDLER(unicode_mode) {
    switch (keycode) {
        case KC_W:
            set_unicode_input_mode(UNICODE_MODE_WINDOWS);
            return course_done();
        case KC_C:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            return course_done();
        case KC_L:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            return course_done();
        default:
            return course_bad_key();
    }
}

static DEFINE_COURSE_HANDLER(unicode_typing_mode) {
    switch (keycode) {
        case KC_M:
            set_unicode_typing_mode(UCTM_MATH_SCRIPT);
            return course_done();
        case KC_N:
            set_unicode_typing_mode(UCTM_MATH_FRAKTUR);
            return course_done();
        case KC_C:
            set_unicode_typing_mode(UCTM_CIRCLE);
            return course_done();
        case KC_S:
            set_unicode_typing_mode(UCTM_SQUARE);
            return course_done();
        case KC_T:
            set_unicode_typing_mode(UCTM_SQUARE_OUTLINE);
            return course_done();
        case KC_R:
            set_unicode_typing_mode(UCTM_REGIONAL);
            return course_done();
        case KC_Z:
            set_unicode_typing_mode(UCTM_ZALGO);
            return course_done();
        case KC_F:
            clear_unicode_typing_mode();
            return course_done();
        default:
            return course_bad_key();
    }
}

static DEFINE_COURSE_HANDLER(unicode) {
    switch (keycode) {
        case KC_M:
            return COURSE_HANDLER(unicode_mode);
        case KC_F:
            return COURSE_HANDLER(unicode_typing_mode);
        default:
            return course_bad_key();
    }
}

#endif

static DEFINE_COURSE_HANDLER(system) {
    switch (keycode) {
        case KC_E:
            eeconfig_init();
            soft_reset_keyboard();
            return course_done();
        case KC_R:
            soft_reset_keyboard();
            return course_done();
        case KC_B:
            reset_keyboard();
            return course_done();
        default:
            return course_bad_key();
    }
}

DEFINE_COURSE_HANDLER(main) {
    switch (keycode) {
        case KC_R:
            srand(timer_read());
            return COURSE_HANDLER(random);
#if defined(CUSTOM_UNICODE_ENABLE)
        case KC_U:
            return COURSE_HANDLER(unicode);
#endif
        case KC_DELETE:
            return COURSE_HANDLER(system);
        default:
            return course_bad_key();
    }
}

#endif


// ========================================================================== //
// Dynamic Macro
// ========================================================================== //
#if defined(DYNAMIC_MACRO_ENABLE)

bool dynamic_macro_record_start_user(int8_t direction) {
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_start();
#endif
    return true;
}

bool dynamic_macro_record_end_user(int8_t direction) {
#if defined(KEYBOARD_klave_rev1)
    pmled_blink_end();
#endif
    return true;
}

#endif


// ========================================================================== //
// OS Detection
// ========================================================================== //
#if defined(OS_DETECTION_ENABLE)

bool process_detected_host_os_user(os_variant_t detected_os) {
#if defined(CUSTOM_UNICODE_ENABLE)
    switch (detected_os) {
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        default:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;
    }
#endif
    return true;
}

#endif
