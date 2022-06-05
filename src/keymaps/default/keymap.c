#include "keymap.h"
#if defined(SECRETS_ENABLE)
    #include "secrets.h"
#endif


#if defined(CUSTOM_LEADER_ENABLE)
typedef void *(*leader_func_t)(uint8_t);
static bool leading = false;
static leader_func_t leader_func = NULL;
#endif

#if defined(DYNAMIC_MACRO_ENABLE)
static bool dynamic_macro_recording = false;
#endif

#if defined(KEY_LOCK_ENABLE)
extern bool watching;
#endif

bool one_handed_adjust = false;

// user_config_t user_config;

// void eeconfig_init_user(void) {
//     user_config.raw = 0;
//     user_config.foo_bar = false;
//     eeconfig_update_user(user_config.raw);
// }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    #define IIIIIII XXXXXXX // Do NOT change!
    #define __LYR__ _______
    #define __MOD__ _______
    #define __SPC__ _______
    #define __NPC__ _______
    #define __ESC__ _______
    #define __TAB__ _______
    #if defined(UNICODEMAP_ENABLE)
        #define K_UC OSL(L_UNICODE)
    #else
        #define K_UC KC_NO
    #endif
    #define K_LWR TT(L_LOWER)
    #define K_RSE TT(L_RAISE)
    [L_BASE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    KC_ESC,     KC_7,       KC_5,       KC_3,       KC_1,       KC_9,                   /**/                KC_8,       KC_0,       KC_2,       KC_4,       KC_6,       KC_GRV,         /**/
    /**/    KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_MINS,    KC_UNDS,        /**/
    /**/    KC_LSFT,    KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       KC_MPLY,    /**/    KC_MUTE,    KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_RSFT,        /**/
    /**/    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_QUOT,    KC_RCTL,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                K_UC,       KC_HYPR,    /**/    K_LEAD,     K_UC,                                                                       /**/
    /**/                            KC_LGUI,    KC_LALT,    K_LWR,      KC_SPC,     KC_ENT,     /**/    KC_DEL,     KC_BSPC,    K_RSE,      KC_RALT,    KC_RGUI,                                /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(UNICODEMAP_ENABLE)
    [L_UNICODE] = LAYOUT(
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
    #define X_NBSP XP(U_NBSP, U_OBOX)
    #define X_PRIME XP(U_SPRIME, U_DPRIME)
    #define X_DASH XP(U_NDASH, U_MDASH)
    #define X_B_QUO XP(U_BDQUO, U_BSQUO)
    #define X_L_QUO XP(U_LDQUO, U_LSQUO)
    #define X_R_QUO XP(U_RDQUO, U_RSQUO)
    #define X_LA_QUO XP(U_LAQUO, U_LSAQUO)
    #define X_RA_QUO XP(U_RAQUO, U_RSAQUO)
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    X_LA_QUO,   X_RA_QUO,   X_B_QUO,    X_L_QUO,    X_R_QUO,                /**/                X(U_PERM),  X(U_DEG),   X_PRIME,    XXXXXXX,    XXXXXXX,    X(U_CENT),      /**/
    /**/    __TAB__,    _______,    _______,    _______,    X_Dc,       _______,                /**/                X(U_SEC),   X_Ur,       X_Ua,       X_Ya,       X_DASH,     X(U_EURO),      /**/
    /**/    __MOD__,    X_Aa,       X_Rc,       X_Sc,       X_Tc,       _______,    IIIIIII,    /**/    IIIIIII,    X_Nc,       X_Ec,       X_Ea,       X_Ia,       X_Oa,       __MOD__,        /**/
    /**/    __MOD__,    X_Zc,       X(U_CROSS), X_Cc,       X(U_CHECK), X(U_BTC),               /**/                X(U_IBANG), X(U_INF),   X(U_MIDDOT),X(U_ELLIP), XXXXXXX,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                __LYR__,    __MOD__,    /**/    IIIIIII,    __LYR__,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    IIIIIII,    X_NBSP,     X(U_PAR),   /**/    __NPC__,    __NPC__,    IIIIIII,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_LOWER] = LAYOUT(
    #define K_COMP COMPOSE_KEY
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,                /**/                KC_PERC,    KC_7,       KC_8,       KC_9,       KC_EQL,     XXXXXXX,        /**/
    /**/    __TAB__,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY2,                /**/                KC_SLSH,    KC_4,       KC_5,       KC_6,       KC_MINS,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY1,    IIIIIII,    /**/    IIIIIII,    KC_ASTR,    KC_1,       KC_2,       KC_3,       KC_PLUS,    __MOD__,        /**/
    /**/    __MOD__,    K_OH_ADJ,   XXXXXXX,    XXXXXXX,    XXXXXXX,    K_COMP,                 /**/                KC_CIRC,    KC_0,       KC_COMM,    KC_DOT,     KC_ENT,     __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    __MOD__,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __SPC__,    __NPC__,    /**/    __NPC__,    __NPC__,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
    [L_RAISE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    XXXXXXX,    KC_CIRC,    KC_AMPR,    KC_PIPE,    KC_PERC,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    __TAB__,    KC_LABK,    KC_RABK,    KC_LCBR,    KC_RCBR,    KC_AT,                  /**/                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_MINS,    KC_DLR,         /**/
    /**/    __MOD__,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_HASH,    IIIIIII,    /**/    IIIIIII,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_EQL,     __MOD__,        /**/
    /**/    __MOD__,    KC_PLUS,    KC_ASTR,    KC_TILD,    KC_SLSH,    KC_BSLS,                /**/                KC_EXLM,    KC_QUES,    KC_SCLN,    KC_COLN,    KC_DQUO,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    __MOD__,    /**/    XXXXXXX,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __SPC__,    __NPC__,    /**/    __NPC__,    __NPC__,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
    [L_ADJUST] = LAYOUT(
#if defined(MOUSEKEY_ENABLE)
    #define K_MS TG(L_MOUSE)
#else
    #define K_MS KC_NO
#endif
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     XXXXXXX,                /**/                XXXXXXX,    KC_NLCK,    KC_CLCK,    KC_SLCK,    XXXXXXX,    KC_PAUS,        /**/
    /**/    __TAB__,    XXXXXXX,    KC_MSTP,    KC_VOLU,    KC_MPLY,    DM_REC2,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_INS,         /**/
    /**/    __MOD__,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    DM_REC1,    IIIIIII,    /**/    IIIIIII,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    __MOD__,        /**/
    /**/    __MOD__,    XXXXXXX,    KC_MRWD,    KC_MUTE,    KC_MFFD,    KC_LOCK,                /**/                KC_APP,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    __MOD__,    /**/    XXXXXXX,    K_MS,                                                                       /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    IIIIIII,    IIIIIII,    /**/    IIIIIII,    IIIIIII,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(MOUSEKEY_ENABLE)
    [L_MOUSE] = LAYOUT(
    #define K_MS_EXT MO(L_MOUSE_EXT)
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_F7,      KC_F11,                 /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    __TAB__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_F5,      C(KC_W),                /**/                KC_PGUP,    KC_HOME,    KC_MS_U,    KC_END,     XXXXXXX,    XXXXXXX,        /**/
    /**/    __MOD__,    XXXXXXX,    KC_ACL0,    KC_ACL1,    KC_ACL2,    C(KC_T),    _______,    /**/    _______,    KC_PGDN,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,    __MOD__,        /**/
    /**/    __MOD__,    C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    C(KC_N),                /**/                XXXXXXX,    KC_BTN4,    KC_BTN5,    XXXXXXX,    KC_BTN3,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    __MOD__,    /**/    XXXXXXX,    K_MS,                                                                       /**/
    /**/                            __MOD__,    __MOD__,    K_MS_EXT,   KC_BTN1,    __NPC__,    /**/    __NPC__,    KC_BTN1,    K_MS_EXT,   __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
    [L_MOUSE_EXT] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/    __TAB__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    KC_WH_U,    _______,    _______,    _______,        /**/
    /**/    __MOD__,    _______,    _______,    _______,    _______,    _______,    _______,    /**/    _______,    _______,    KC_WH_L,    KC_WH_D,    KC_WH_R,    _______,    __MOD__,        /**/
    /**/    __MOD__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                _______,    __MOD__,    /**/    _______,    __LYR__,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    _______,    __NPC__,    /**/    __NPC__,    _______,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_GAME] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    KC_PSCR,        /**/
    /**/    __TAB__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    _______,        /**/
    /**/    __MOD__,    _______,    _______,    _______,    _______,    _______,    _______,    /**/    _______,    _______,    _______,    _______,    _______,    _______,    __MOD__,        /**/
    /**/    KC_F11,     _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    TG(L_GAME),     /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                KC_F1,      KC_F2,      /**/    KC_F6,      KC_F7,                                                                      /**/
    /**/                            KC_F3,      KC_LALT,    KC_LCTL,    __SPC__,    __NPC__,    /**/    __NPC__,    __NPC__,    KC_F8,      KC_F9,      KC_F10,                                 /**/
    /*                                                                                                                                                                                            */
    _),
};


#if defined(UNICODEMAP_ENABLE)

const uint32_t PROGMEM unicode_map[] = {
    [U_Ual   ] = 0x00fa, // ú
    [U_Eal   ] = 0x00e9, // é
    [U_Ial   ] = 0x00ed, // í
    [U_Oal   ] = 0x00f3, // ó
    [U_Aal   ] = 0x00e1, // á
    [U_Yal   ] = 0x00fd, // ý
    [U_Ecl   ] = 0x011b, // ě
    [U_Rcl   ] = 0x0159, // ř
    [U_Tcl   ] = 0x0165, // ť
    [U_Zcl   ] = 0x017e, // ž
    [U_Scl   ] = 0x0161, // š
    [U_Dcl   ] = 0x010f, // ď
    [U_Ccl   ] = 0x010d, // č
    [U_Ncl   ] = 0x0148, // ň
    [U_Url   ] = 0x016f, // ů
    [U_Uau   ] = 0x00da, // Ú
    [U_Eau   ] = 0x00c9, // É
    [U_Iau   ] = 0x00cd, // Í
    [U_Oau   ] = 0x00d3, // Ó
    [U_Aau   ] = 0x00c1, // Á
    [U_Yau   ] = 0x00dd, // Ý
    [U_Ecu   ] = 0x011a, // Ě
    [U_Rcu   ] = 0x0158, // Ř
    [U_Tcu   ] = 0x0164, // Ť
    [U_Zcu   ] = 0x017d, // Ž
    [U_Scu   ] = 0x0160, // Š
    [U_Dcu   ] = 0x010e, // Ď
    [U_Ccu   ] = 0x010c, // Č
    [U_Ncu   ] = 0x0147, // Ň
    [U_Uru   ] = 0x016e, // Ů
    [U__LETTER_PAIRS_END] = 0x2327, // ⌧
    [U_DEG   ] = 0x00b0, // ° Znak stupně
    [U_ACUTE ] = 0x00b4, // ´ Čárka
    [U_CARON ] = 0x02c7, // ˇ Háček
    [U_BDQUO ] = 0x201e, // „ Počáteční uvozovka dvojitá
    [U_LDQUO ] = 0x201c, // “ Koncová uvozovka dvojitá / Anglická počáteční uvozovka dvojitá
    [U_BSQUO ] = 0x201a, // ‚ Počáteční uvozovka jednoduchá
    [U_LSQUO ] = 0x2018, // ‘ Koncová uvozovka jednoduchá / Anglická počáteční uvozovka jednoduchá
    [U_RAQUO ] = 0x00bb, // » Dvojité lomené uvozovky vpravo
    [U_LAQUO ] = 0x00ab, // « Dvojité lomené uvozovky vlevo
    [U_RSAQUO] = 0x203a, // › Jednoduché lomené uvozovky vpravo
    [U_LSAQUO] = 0x2039, // ‹ Jednoduché lomené uvozovky vlevo
    [U_RDQUO ] = 0x201d, // ” Anglická koncová uvozovka dvojitá
    [U_RSQUO ] = 0x2019, // ’ Anglická koncová uvozovka jednoduchá
    [U_NDASH ] = 0x2013, // – En pomlčka
    [U_MDASH ] = 0x2014, // — Em pomlčka
    [U_NBSP  ] = 0x00a0, //   Nepřerušující mezera
    [U_ELLIP ] = 0x2026, // … Výpustka
    [U_MIDDOT] = 0x00b7, // · Middle dot
    [U_EURO  ] = 0x20ac, // € Euro
    [U_CENT  ] = 0x00a2, // ¢ Cent
    [U_POUND ] = 0x00a3, // £ Pound
    [U_CURR  ] = 0x00a4, // ¤ Currency
    [U_YEN   ] = 0x00a5, // ¥ Yen
    [U_WON   ] = 0x20a9, // ₩ Won
    [U_RUPEE ] = 0x20b9, // ₹ Rupee
    [U_BTC   ] = 0x20bf, // ₿ Bitcoin
	[U_SEC   ] = 0x00a7, // §
	[U_PAR   ] = 0x00b6, // ¶
	[U_CHECK ] = 0x2713, // ✓
	[U_CROSS ] = 0x2717, // ✗
	[U_INF   ] = 0x221e, // ∞
	[U_PERM  ] = 0x2030, // ‰
	[U_IBANG ] = 0x203d, // ‽
	[U_OBOX  ] = 0x2423, // ␣
	[U_SQRT  ] = 0x221a, // √
	[U_SPRIME] = 0x2032, // ′
	[U_DPRIME] = 0x2033, // ″
};

#endif


#if defined(KEY_OVERRIDE_ENABLE)

const key_override_t foo_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SPC, KC_TAB, 1 << L_BASE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &foo_key_override,
    NULL,
};

#endif


#if defined(TAP_DANCE_ENABLE)

qk_tap_dance_action_t tap_dance_actions[] = {
};

#endif


#if defined(CUSTOM_LEADER_ENABLE)

static void send_string_random_number(uint8_t max_number_length) {
    const uint8_t max_number_length_total = 3;
    char buffer[max_number_length_total + 1];
    char *buffer_start = buffer;

    if (max_number_length < 1) {
        max_number_length = 1;
    }
    else if (max_number_length > max_number_length_total) {
        max_number_length = max_number_length_total;
    }

    uint16_t max_number = 1;
    for (uint8_t i = 0; i < max_number_length; i++) {
        max_number *= 10;
    }

    uint16_t number = rand() % max_number;

    for (uint8_t i = 0; i < max_number_length; i++) {
        uint8_t index = max_number_length_total - 1 - i;
        buffer[index] = 0x30 + (number % 10);
        number/= 10;
        if (number == 0) {
            buffer_start = buffer + index;
            break;
        }
    }
    buffer[max_number_length_total] = 0;

    send_string(buffer_start);
}

static void *leader_func_random(uint8_t keycode) {
    switch (keycode) {
        case KC_N:
            send_string_random_number(3);
            return leader_func_random;
        default:
            return NULL;
    }
}

static void *leader_func_boot(uint8_t keycode) {
    switch (keycode) {
        case KC_E:
            eeconfig_init();
            soft_reset_keyboard();
            break;
        case KC_S:
            soft_reset_keyboard();
            break;
        case KC_R:
            reset_keyboard();
            break;
        default:
            break;
    }
    return NULL;
}

static void *leader_func_lock(uint8_t keycode) {
    switch (keycode) {
        case KC_L:
            tap_code16(RGUI(KC_L));
            break;
        case KC_S:
            tap_code(KC_SYSTEM_SLEEP);
            break;
        default:
            break;
    }
    return NULL;
}

static void *leader_func_start(uint8_t keycode) {
#if defined(SECRETS_ENABLE)
    void *secret_result = secret_leader_func_start(keycode);
    if (secret_result != NULL) {
        return secret_result;
    }
#endif
    switch (keycode) {
        case KC_R:
            // Call `srand` once for each session
            srand(timer_read());
            return leader_func_random;
        case KC_B:
            return leader_func_boot;
        case KC_L:
            return leader_func_lock;
        case KC_RCTL:
            layer_move(L_GAME);
            return NULL;
        default:
            return NULL;
    }
}

static void leader_start(void) {
    leading = true;
    leader_func = leader_func_start;
}

static void leader_stop(void) {
    leading = false;
    leader_func = NULL;
}

static bool process_leader(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        if (leading) {
            if (keycode == LEADER_CANCEL_KEY) {
                leader_stop();
                return false;
            }

            if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
                keycode = keycode & 0xFF;
            }

            if (keycode > 0xFF) {
                return true;
            }

            leader_func = leader_func((uint8_t)keycode);

            if (leader_func == NULL) {
                leader_stop();
            }

            return false;
        }
        else {
            if (keycode == K_LEAD) {
                leader_start();
            }
        }
    }
    return true;
}

#endif


#if defined(DYNAMIC_MACRO_ENABLE)

void dynamic_macro_record_start_user(void) {
    dynamic_macro_recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro_recording = false;
}

#endif


#if defined(CAPS_WORD_ENABLE)

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_MINUS:
        case KC_UNDERSCORE:
        case KC_BACKSPACE:
            return true;

#if defined(UNICODEMAP_ENABLE)
        case K_UC:
            return true;
        case QK_UNICODEMAP_PAIR ... QK_UNICODEMAP_PAIR_MAX:
            if ((((keycode - QK_UNICODEMAP_PAIR) & 0x7F)) < U__LETTER_PAIRS_END) {
                add_weak_mods(MOD_BIT(KC_LSFT));
                return true;
            }
            else {
                return false;
            }
#endif

        default:
            return false;
    }
}

#endif


void keyboard_post_init_user(void) {
    // user_config.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#if defined(CUSTOM_LEADER_ENABLE)
    if (!process_leader(keycode, record)) {
        return false;
    }
#endif

    switch (keycode) {
        case TT(L_LOWER):
            return !record->event.pressed || !layer_state_is(L_LOWER);
        case TT(L_RAISE):
            return !record->event.pressed || !layer_state_is(L_RAISE);
        case K_OH_ADJ:
            if (record->event.pressed) {
                layer_on(L_RAISE);
                one_handed_adjust = true; 
            }
            return false;
        default:
            return true;
    }

}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (one_handed_adjust) {
        if (!layer_state_cmp(state, L_LOWER)) {
            state = state & ~((layer_state_t)1 << L_RAISE);
            one_handed_adjust = false; 
        }
        else {
            state |= (layer_state_t)1 << L_RAISE;
        }
    }

    state = update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);

#if !defined(OLED_ENABLE)
    static layer_state_t last_state = 0;
    if (layer_state_cmp(state, L_LOWER) != layer_state_cmp(last_state, L_LOWER)) {
        if (layer_state_cmp(state, L_LOWER)) {
            writePinLow(B0);
        } else {
            writePinHigh(B0);
        }
    }
    if (layer_state_cmp(state, L_RAISE) != layer_state_cmp(last_state, L_RAISE)) {
        if (layer_state_cmp(state, L_RAISE)) {
            writePinLow(D5);
        } else {
            writePinHigh(D5);
        }
    }
    last_state = state;
#endif

    return state;
}


#if defined(ENCODER_ENABLE)

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            return false;
        default:
            return true;
    }
}

#endif


#if defined(OLED_ENABLE)

#define SPRITE_WIDTH(width) (width * 8)
#define SPRITE_HEIGHT(height) (height)
#define SPRITE_ANIMATION_TICK(frame, fps, frame_count, enabled) \
    static int8_t frame = -1; \
    static uint16_t frame##_elapsed = 0; \
    static uint16_t frame##_time = 0; \
    if (enabled) { \
        frame##_elapsed = timer_elapsed(frame##_time); \
        if (frame##_elapsed > 1000 / fps) { \
            frame##_time += frame##_elapsed; \
            frame = (frame + 1) % frame_count; \
        } \
    } else { \
        frame = -1; \
        frame##_elapsed = 0; \
        frame##_time = 0; \
    };

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

static void render_layers(void) {
    static const uint8_t column_offset = 9;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(3);
    static const char PROGMEM layer_sprites[][SPRITE_HEIGHT(4) * SPRITE_WIDTH(3)] = {
        [L_BASE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 48, 12, 3, 204, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0, 0, 0, 0, 0, 3, 12, 48, 192, 3, 204, 48, 192, 3, 204, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, },
#if defined(UNICODEMAP_ENABLE)
        [L_UNICODE] = { 0, 0, 0, 0, 0, 8, 4, 8, 16, 8, 4, 8, 16, 8, 4, 8, 16, 8, 4, 8, 0, 0, 0, 0,0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 112, 172, 87, 236, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0,0, 0, 0, 0, 3, 12, 48, 192, 3, 206, 53, 234, 87, 236, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0,0, 0, 0, 0, 0, 64, 32, 64, 131, 64, 32, 64, 131, 64, 32, 64, 131, 64, 32, 64, 0, 0, 0, 0, },
#endif
        [L_LOWER] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 48, 56, 60, 56, 48, 32, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 192, 240, 252, 255, 252, 48, 12, 3, 204, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0,0, 0, 0, 0, 3, 15, 63, 255, 255, 252, 48, 192, 3, 204, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, },
        [L_RAISE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 48, 12, 3, 204, 240, 252, 255, 252, 240, 192, 0, 0, 0, 0,0, 0, 0, 0, 3, 12, 48, 192, 3, 204, 48, 192, 3, 207, 63, 255, 255, 255, 63, 15, 3, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 3, 16, 48, 112, 243, 112, 48, 16, 3, 0, 0, 0, 0, 0, 0, 0, },
        [L_ADJUST] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 48, 56, 60, 56, 48, 32, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 192, 176, 92, 171, 220, 112, 172, 87, 236, 176, 92, 171, 92, 176, 192, 0, 0, 0, 0,0, 0, 0, 0, 3, 13, 58, 213, 171, 222, 53, 234, 87, 237, 58, 213, 170, 213, 58, 13, 3, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 3, 16, 48, 112, 243, 112, 48, 16, 3, 0, 0, 0, 0, 0, 0, 0, },
#if defined(MOUSEKEY_ENABLE)
        [L_MOUSE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 32, 16, 136, 132, 132, 130, 17, 25, 150, 144, 144, 144, 144, 144, 96, 0, 0, 0, 0, 0, 0, 0, 0, 27, 20, 16, 42, 42, 74, 74, 64, 64, 84, 52, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        [L_MOUSE_EXT] = { 0, 0, 0, 0, 32, 32, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 32, 32, 0, 0, 0, 0, 0, 0, 0, 0, 224, 32, 16, 136, 132, 132, 130, 17, 25, 150, 144, 144, 144, 144, 144, 96, 0, 0, 0, 0, 0, 0, 0, 0, 27, 20, 16, 42, 42, 74, 74, 64, 64, 84, 52, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 0, 0, 0, 0, },
#endif
        [L_GAME] = { 0, 0, 0, 128, 64, 32, 16, 16, 16, 16, 16, 144, 144, 32, 32, 32, 64, 128, 0, 0, 0, 0, 0, 0,0, 0, 0, 7, 8, 8, 16, 224, 0, 198, 6, 31, 31, 6, 6, 0, 0, 3, 252, 0, 128, 128, 0, 0,0, 0, 0, 192, 32, 32, 16, 15, 0, 198, 192, 48, 48, 192, 192, 0, 0, 128, 127, 1, 0, 0, 1, 0,0, 0, 0, 3, 4, 8, 16, 16, 16, 16, 16, 19, 19, 8, 8, 8, 4, 3, 0, 0, 0, 0, 0, 0, },
        [LAYER_COUNT] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 4, 0, 4, 4, 0, 4, 4, 96, 100, 196, 128, 4, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 219, 128, 3, 128, 131, 3, 135, 142, 12, 140, 135, 3, 128, 219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };

    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P((layer < LAYER_COUNT ? layer_sprites[layer] : layer_sprites[LAYER_COUNT]) + (sprite_width * row), sprite_width);
    }
}

static void render_caps_lock(void) {
    static const uint8_t column_offset = 18;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char PROGMEM caps_lock_sprites[][SPRITE_HEIGHT(4) * SPRITE_WIDTH(2)] = {
        { /* Off */ 0, 0, 0, 0, 128, 192, 96, 96, 96, 96, 96, 192, 128, 0, 0, 0, 0, 0, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 0, 0, 0, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 3, 0, 0, 0, },
        { /* On */ 0, 248, 252, 254, 126, 62, 158, 158, 158, 158, 158, 62, 126, 254, 252, 248, 0, 255, 255, 255, 152, 147, 147, 31, 159, 159, 147, 51, 120, 255, 255, 255, 0, 255, 255, 255, 9, 153, 153, 152, 25, 153, 153, 156, 14, 255, 255, 255, 0, 31, 63, 127, 127, 127, 127, 127, 124, 121, 121, 121, 124, 127, 63, 31, },
#if defined(CAPS_WORD_ENABLE)
        { /* Word */ 0, 248, 12, 6, 130, 194, 98, 98, 98, 98, 98, 194, 130, 6, 12, 248, 0, 255, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 255, 0, 255, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 255, 0, 31, 48, 96, 64, 64, 64, 64, 67, 70, 70, 70, 67, 96, 48, 31, },
#endif
    };

    const led_t led_state = host_keyboard_led_state();

    uint8_t sprite_index = led_state.caps_lock ? 1 : 0;

#if defined(CAPS_WORD_ENABLE)
    SPRITE_ANIMATION_TICK(caps_word_frame, 4, 2, is_caps_word_on());
    if (caps_word_frame == 0) {
        sprite_index = 2;
    }
#endif

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(caps_lock_sprites[sprite_index] + (sprite_width * row), sprite_width);
    }
}

static void render_progress_ring(void) {
    static const uint8_t column_offset = 0;
    static const uint8_t line_offset = 0;
    static const uint8_t fps = 10;
    static const uint8_t frame_count = 8;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char PROGMEM empty_sprite[SPRITE_HEIGHT(2) * SPRITE_WIDTH(2)] = 
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
    static const char PROGMEM ring_sprites[][SPRITE_HEIGHT(2) * SPRITE_WIDTH(2)] = {
        { 0, 0, 0, 2, 14, 31, 15, 15, 15, 31, 14, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 12, 31, 62, 126, 124, 56, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 240, 240, 248, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, 7, 15, 3, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 124, 62, 63, 31, 14, 2, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 56, 124, 120, 120, 120, 124, 56, 32, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 14, 31, 63, 62, 124, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 224, 248, 240, 240, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 15, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 32, 56, 124, 126, 62, 31, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };

    bool enabled = false;
    if (false) { }
#if defined(KEY_LOCK_ENABLE)
    else if (watching) {
        enabled = true;
    }
#endif
#if defined(CUSTOM_LEADER_ENABLE)
    else if (leading) {
        enabled = true;
    }
#endif
#if defined(DYNAMIC_MACRO_ENABLE)
    else if (dynamic_macro_recording) {
        enabled = true;
    }
#endif

    SPRITE_ANIMATION_TICK(frame, fps, frame_count, enabled);

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P((enabled ? ring_sprites[frame] : empty_sprite) + (sprite_width * row), sprite_width);
    }
}

static bool oled_task_user_master(void) {
    render_layers();
    render_caps_lock();
    render_progress_ring();
    return false;
}

bool oled_task_user(void) {
    return is_keyboard_master()
        ? oled_task_user_master()
        : false;
}

#endif
