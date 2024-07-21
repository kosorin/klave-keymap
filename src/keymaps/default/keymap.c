#include QMK_KEYBOARD_H
#include "keymap.h"

#if defined(COURSE_ENABLE)
    #include "features/course.h"
#endif
#if defined(CUSTOM_UNICODE_ENABLE)
    #include "features/custom_unicode.h"
#endif
#if defined(CAPS_WORD_ENABLE)
    #include "smart_case.h"
#endif
#if defined(SECRETS_ENABLE)
    #include "secrets.h"
#endif
#if defined(COMBO_ENABLE)
    #include "combos.h"
#endif
#if defined(TAP_DANCE_ENABLE)
    #include "features/tap_dance.h"
    #include "tap_dance.h"
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
    /**/                                                                G(KC_A),    KC_PSCR,    /**/    XXXXXXX,    CK_SYST,                                                                    /**/
    /**/                            XXXXXXX,    ESC_MED,    TAB_FUN,    SPC_SYM,    KC_ENT,     /**/    KC_DEL,     BSP_NUM,    MO_NAV,     OSL_CZE,    KC_CMPS                                 /**/
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
    /**/                            _______,    _______,    _______,    _______,    _______,    /**/    _______,    _______,    _______,    _______,    _______                                 /**/
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
    /**/    XXXXXXX,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,                /**/                DM_RSTP,    KC_F17,     KC_F18,     KC_F19,     KC_F20,     XXXXXXX,        /**/
    /**/    KC_INS,     KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,                /**/                DM_REC1,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,    XXXXXXX,        /**/
    /**/    XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY2,                /**/                DM_REC2,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     XXXXXXX,        /**/
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
    /**/    XXXXXXX,    KC_SLSH,    KC_ASTR,    KC_MINS,    KC_PLUS,    XXXXXXX,                /**/                KC_PLUS,    KC_7,       KC_8,       KC_9,       KC_MINS,    KC_UNDS,        /**/
    /**/    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,                /**/                CK_DECP,    KC_4,       KC_5,       KC_6,       KC_0,       KC_ENT,         /**/
    /**/    XXXXXXX,    KC_Y,       KC_X,       XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                KC_ASTR,    KC_1,       KC_2,       KC_3,       KC_SLSH,    KC_BSLS,        /**/
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

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}


void eeconfig_init_user(void) {
}

void keyboard_pre_init_user(void) {
}

void keyboard_post_init_user(void) {
#if defined(CONSOLE_ENABLE) && !defined(NO_DEBUG)
    debug_enable = true;
#endif
}

void matrix_scan_user(void) {
}

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
    return PROCESS_NOT_HANDLED;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

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
        default:
            return 0;
    }
}
#endif

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

uint16_t COMBO_LEN = combo_events_COUNT;

const uint16_t combo_COPY[] PROGMEM = { KC_X, KC_C, COMBO_END };
const uint16_t combo_SAVE[] PROGMEM = { HRK_L3, HRK_L2, COMBO_END };
const uint16_t combo_FIND[] PROGMEM = { KC_W, KC_F, COMBO_END };
const uint16_t combo_CAPS_LOCK[] PROGMEM = { KC_P, KC_M, COMBO_END };
#if defined(CAPS_WORD_ENABLE)
const uint16_t combo_CAPS_WORD[] PROGMEM = { HRK_L1, HRK_R1, COMBO_END };
const uint16_t combo_MOCKING_CASE[] PROGMEM = { HRK_L1, HRK_R1, KC_F, KC_U, COMBO_END };
#endif

combo_t key_combos[] = {
    [C_COPY] = COMBO(combo_COPY, C(KC_C)),
    [C_SAVE] = COMBO(combo_SAVE, C(KC_S)),
    [C_FIND] = COMBO(combo_FIND, C(KC_F)),
    [C_CAPS_LOCK] = COMBO(combo_CAPS_LOCK, KC_CAPS_LOCK),
#if defined(CAPS_WORD_ENABLE)
    [C_CAPS_WORD] = COMBO_ACTION(combo_CAPS_WORD),
    [C_MOCKING_CASE] = COMBO_ACTION(combo_MOCKING_CASE),
#endif
};

#if defined(CAPS_WORD_ENABLE)
static void caps_word_toggle_combo(uint16_t combo_index) {
    switch (combo_index) {
        case C_MOCKING_CASE:
            smart_case = (smart_case_t){ .type = SC_MOCKING, .mocking = { .upper_case = false, }, };
            break;
        case C_CAPS_WORD:
        default:
            smart_case = (smart_case_t){ .type = SC_CAPS_WORD, };
            break;
    }
    caps_word_toggle();
}
#endif

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
#if defined(CAPS_WORD_ENABLE)
        case C_CAPS_WORD:
        case C_MOCKING_CASE:
            if (pressed) {
                caps_word_toggle_combo(combo_index);
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
    td_context.result = get_tap_dance_result(state, false);
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


tap_dance_action_t tap_dance_actions[] = {
#if defined(SECRETS_ENABLE)
    [TD_SECRET1] = TDA_SECRET1,
    [TD_SECRET2] = TDA_SECRET2,
    [TD_SECRET3] = TDA_SECRET3,
    [TD_SECRET4] = TDA_SECRET4,
    [TD_SECRET5] = TDA_SECRET5,
    [TD_SECRET6] = TDA_SECRET6,
    [TD_SECRET7] = TDA_SECRET7,
    [TD_SECRET8] = TDA_SECRET8,
    [TD_SECRET9] = TDA_SECRET9,
    [TD_SECRET10] = TDA_SECRET10,
    [TD_SECRET11] = TDA_SECRET11,
    [TD_SECRET12] = TDA_SECRET12,
#endif
#if defined(COURSE_ENABLE)
    [TD_SYSTEM_COURSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, finished_system_course, reset_system_course),
#endif
    [TD_DECIMAL_POINT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMMA),
};

#endif
