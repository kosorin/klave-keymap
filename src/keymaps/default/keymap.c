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

user_config_t user_config;

void eeconfig_init_user(void) {
    user_config.raw = 0;
#if defined(ENCODER_ENABLE)
    user_config.encoder_scroll_mode = false;
#endif
    eeconfig_update_user(user_config.raw);
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   /**/                KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV,         /**/
    /**/    KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_D,       KC_G,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_MINS,        /**/
    /**/    KC_LSFT,    KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       KC_MUTE,    /**/    K_ENC_SM,   KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_RSFT,        /**/
    /**/    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                   /**/                KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_QUES,    KC_RCTL,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                K_LUC,      K_LEAD,     /**/    KC_HYPR,    K_RUC,                                                                      /**/
    /**/                            KC_LGUI,    KC_LALT,    K_LWR,      KC_SPC,     KC_ENT,     /**/    KC_DEL,     KC_BSPC,    K_RSE,      KC_RALT,    KC_RGUI,                                /**/
    /*                                                                                                                                                                                            */
    _),
#if defined(UNICODEMAP_ENABLE)
    [L_UNICODE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    X(U_DEG),       /**/
    /**/    __TAB__,    _______,    _______,    _______,    K_Dc,       X(U_BTC),               /**/                _______,    K_Ur,       K_Ua,       K_Ya,       XXXXXXX,    K_N_M_DASH,     /**/
    /**/    __MOD__,    K_Aa,       K_Rc,       K_Sc,       K_Tc,       X(U_CENT),  IIIIIII,    /**/    IIIIIII,    K_Nc,       K_Ec,       K_Ea,       K_Ia,       K_Oa,       __MOD__,        /**/
    /**/    __MOD__,    K_Zc,       _______,    K_Cc,       _______,    X(U_EURO),              /**/                _______,    _______,    X(U_MIDDOT),X(U_ELLIP), XXXXXXX,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                __LYR__,    IIIIIII,    /**/    __MOD__,    __LYR__,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    IIIIIII,    X(U_NBSP),  __NPC__,    /**/    __NPC__,    __NPC__,    IIIIIII,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
#endif
    [L_LOWER] = LAYOUT(
    /**/    __ESC__,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,                /**/                XXXXXXX,    KC_7,       KC_8,       KC_9,       XXXXXXX,    XXXXXXX,        /**/
    /**/    __TAB__,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY2,                /**/                KC_ASTR,    KC_4,       KC_5,       KC_6,       KC_PLUS,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      DM_PLY1,    KC_MPLY,    /**/    IIIIIII,    KC_SLSH,    KC_1,       KC_2,       KC_3,       KC_MINS,    __MOD__,        /**/
    /**/    __MOD__,    KC_AMPR,    KC_PIPE,    KC_BSLS,    KC_SLSH,    K_WINC,                 /**/                KC_PERC,    KC_0,       KC_COMM,    KC_DOT,     KC_EQL,     __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                KC_LOCK,    K_LCK_SLP,  /**/    __MOD__,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __SPC__,    __NPC__,    /**/    __NPC__,    __NPC__,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
    [L_RAISE] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_TILD,        /**/
    /**/    __TAB__,    KC_LABK,    KC_RABK,    KC_LCBR,    KC_RCBR,    KC_CIRC,                /**/                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_DQUO,    KC_UNDS,        /**/
    /**/    __MOD__,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_AT,      IIIIIII,    /**/    IIIIIII,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_HASH,    __MOD__,        /**/
    /**/    __MOD__,    KC_AMPR,    KC_PIPE,    KC_BSLS,    KC_SLSH,    KC_DLR,                 /**/                KC_PLUS,    KC_EQL,     KC_SCLN,    KC_COLN,    KC_EXLM,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    __MOD__,    KC_APP,                                                                     /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __SPC__,    __NPC__,    /**/    __NPC__,    __NPC__,    __LYR__,    __MOD__,    __MOD__,                                /**/
    /*                                                                                                                                                                                            */
    _),
    [L_ADJUST] = LAYOUT(
    /*                                                                                                                                                                                            */
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    K_BOOT,     K_CLR,      XXXXXXX,                /**/                KC_INS,     KC_NLCK,    KC_CLCK,    KC_SLCK,    XXXXXXX,    KC_PAUS,        /**/
    /**/    __TAB__,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     DM_REC2,                /**/                XXXXXXX,    KC_MPLY,    KC_VOLU,    KC_MSTP,    XXXXXXX,    XXXXXXX,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC1,    IIIIIII,    /**/    IIIIIII,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,    __MOD__,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    KC_MRWD,    KC_MUTE,    KC_MFFD,    XXXXXXX,    __MOD__,        /**/
    /**/                                                                                        /**/                                                                                            /**/
    /**/                                                                XXXXXXX,    XXXXXXX,    /**/    __MOD__,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    IIIIIII,    IIIIIII,    /**/    IIIIIII,    IIIIIII,    __LYR__,    __MOD__,    __MOD__,                                /**/
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

#if defined(UNICODEMAP_ENABLE)

typedef struct {
    const uint8_t keycode;
    bool state;
} td_unicode_shift_t;

typedef struct {
    const uint8_t layer;
    bool state;
    td_unicode_shift_t shift;
} td_unicode_key_t;

static void td_unicode_layer_register(td_unicode_key_t *key) {
    if (!key->state) {
        key->state = true;
        layer_on(key->layer);
    }
}

static void td_unicode_layer_unregister(td_unicode_key_t *key) {
    if (key->state) {
        key->state = false;
        layer_off(key->layer);
    }
}

static void td_unicode_shift_register(td_unicode_key_t *key) {
    if (!key->shift.state) {
        key->shift.state = true;
        register_code(key->shift.keycode);
    }
}

static void td_unicode_shift_unregister(td_unicode_key_t *key) {
    if (key->shift.state) {
        key->shift.state = false;
        unregister_code(key->shift.keycode);
    }
}

#define ACTION_TAP_DANCE_UNICODE(key) { .fn = { td_unicode_on_each_tap, NULL, NULL, }, .user_data = (void *)key, }

static void td_unicode_on_each_tap(qk_tap_dance_state_t *state, void *user_data) {
    td_unicode_key_t *key = (td_unicode_key_t *)user_data;
    if (state->count >= 1) {
        td_unicode_layer_register(key);
    }
    if (state->count >= 2) {
        td_unicode_shift_register(key);
    }
}

#endif

static void td_clear_eeprom(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        eeconfig_init();
    }
}

static void td_bootloader(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        reset_keyboard();
    }
}

static void td_lock_sleep(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(RGUI(KC_L));
    }
    else if (state->count >= 3) {
        tap_code(KC_SYSTEM_SLEEP);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
#if defined(UNICODEMAP_ENABLE)
    [TD_LUC] = ACTION_TAP_DANCE_UNICODE(&((td_unicode_key_t){ .layer = L_UNICODE, .shift = { .keycode = KC_LSFT, }, })),
    [TD_RUC] = ACTION_TAP_DANCE_UNICODE(&((td_unicode_key_t){ .layer = L_UNICODE, .shift = { .keycode = KC_RSFT, }, })),
#endif
    [TD_CLR] = ACTION_TAP_DANCE_FN(td_clear_eeprom),
    [TD_BOOT] = ACTION_TAP_DANCE_FN(td_bootloader),
    [TD_LCK_SLP] = ACTION_TAP_DANCE_FN(td_lock_sleep),
};

#endif


void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void matrix_scan_user(void) {
}


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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#if defined(CUSTOM_LEADER_ENABLE)
    if (!process_leader(keycode, record)) {
        return false;
    }
#endif

    switch (keycode) {
#if defined(ENCODER_ENABLE)
        case K_ENC_SM:
            if (record->event.pressed) {
                user_config.encoder_scroll_mode ^= true;
                eeconfig_update_user(user_config.raw);
            }
            return false;
#endif
        default:
            return true;
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
            if (record->event.pressed && get_mods() == MOD_MASK_SHIFT) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
#if defined(UNICODEMAP_ENABLE) && defined(TAP_DANCE_ENABLE)
        case K_LUC:
        case K_RUC:
            if (!record->event.pressed) {
                td_unicode_key_t *td_unicode_key = (td_unicode_key_t *)(tap_dance_actions[keycode - QK_TAP_DANCE].user_data);
                td_unicode_shift_unregister(td_unicode_key);
                td_unicode_layer_unregister(td_unicode_key);
            }
            break;
#endif
        default:
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
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
        case ENCODER_INDEX_LEFT:
            tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            return false;
        case ENCODER_INDEX_RIGHT:
            tap_code(user_config.encoder_scroll_mode
                ? (clockwise ? KC_PAGE_DOWN : KC_PAGE_UP)
                : (clockwise ? KC_MS_WH_DOWN : KC_MS_WH_UP));
            return false;
        default:
            return true;
    }
}

#endif


#if defined(OLED_ENABLE)

#define SPRITE_WIDTH(width) (width * 8)
#define SPRITE_HEIGHT(height) (height)
#define SPRITE_ANIMATION_TICK(frame, fps, frame_count) \
    static uint16_t frame##_time = 0; \
    static uint8_t frame = 0; \
    static uint16_t frame##_elapsed = 0; \
    frame##_elapsed = timer_elapsed(frame##_time); \
    if (frame##_elapsed > 1000 / fps) { \
        frame##_time += frame##_elapsed; \
        frame = (frame + 1) % frame_count; \
    }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

static void render_layers(void) {
    static const uint8_t column_offset = 9;
    static const uint8_t line_offset = 0;
    static const uint8_t sprites = 5;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(3);
    static const char PROGMEM unknown_sprite[SPRITE_HEIGHT(4)][SPRITE_WIDTH(3)] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 108, 4, 0, 4, 4, 0, 4, 4, 96, 100, 196, 128, 4, 108, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 219, 128, 3, 128, 131, 3, 135, 142, 12, 140, 135, 3, 128, 219, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };
    static const char PROGMEM layer_sprites[5][SPRITE_HEIGHT(4)][SPRITE_WIDTH(3)] = {
        { // Base
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 48, 12, 3, 204, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 3, 12, 48, 192, 3, 204, 48, 192, 3, 204, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, },
        },
#if defined(UNICODEMAP_ENABLE)
        { // Unicode
            { 0, 0, 0, 0, 0, 8, 4, 8, 16, 8, 4, 8, 16, 8, 4, 8, 16, 8, 4, 8, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 112, 172, 87, 236, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 3, 12, 48, 192, 3, 206, 53, 234, 87, 236, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 64, 32, 64, 131, 64, 32, 64, 131, 64, 32, 64, 131, 64, 32, 64, 0, 0, 0, 0, },
        },
#endif
        { // Lower
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 48, 56, 60, 56, 48, 32, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 192, 240, 252, 255, 252, 48, 12, 3, 204, 48, 12, 3, 12, 48, 192, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 3, 15, 63, 255, 255, 252, 48, 192, 3, 204, 48, 192, 0, 192, 48, 12, 3, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, },
        },
        { // Raise
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 192, 48, 12, 3, 204, 48, 12, 3, 204, 240, 252, 255, 252, 240, 192, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 3, 12, 48, 192, 3, 204, 48, 192, 3, 207, 63, 255, 255, 255, 63, 15, 3, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 3, 16, 48, 112, 243, 112, 48, 16, 3, 0, 0, 0, 0, 0, 0, 0, },
        },
        { // Adjust
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 48, 56, 60, 56, 48, 32, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 192, 176, 92, 171, 220, 112, 172, 87, 236, 176, 92, 171, 92, 176, 192, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 3, 13, 58, 213, 171, 222, 53, 234, 87, 237, 58, 213, 170, 213, 58, 13, 3, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 3, 16, 48, 112, 243, 112, 48, 16, 3, 0, 0, 0, 0, 0, 0, 0, },
        },
    };

    layer_state_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(layer < sprites ? layer_sprites[layer][row] : unknown_sprite[row], sprite_width);
    }
}

static void render_caps_lock(void) {
    static const uint8_t column_offset = 18;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char PROGMEM caps_lock_sprites[2][SPRITE_HEIGHT(4)][SPRITE_WIDTH(2)] = {
        { // Off
            { 0, 0, 0, 0, 128, 192, 96, 96, 96, 96, 96, 192, 128, 0, 0, 0, },
            { 0, 0, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 0, },
            { 0, 0, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 3, 0, 0, 0, },
        },
        { // On
            { 0, 248, 252, 254, 126, 62, 158, 158, 158, 158, 158, 62, 126, 254, 252, 248, },
            { 0, 255, 255, 255, 152, 147, 147, 31, 159, 159, 147, 51, 120, 255, 255, 255, },
            { 0, 255, 255, 255, 9, 153, 153, 152, 25, 153, 153, 156, 14, 255, 255, 255, },
            { 0, 31, 63, 127, 127, 127, 127, 127, 124, 121, 121, 121, 124, 127, 63, 31, },
        },
    };

    const led_t led_state = host_keyboard_led_state();

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(caps_lock_sprites[led_state.caps_lock ? 1 : 0][row], sprite_width);
    }
}

static void render_progress_ring(void) {
    static const uint8_t column_offset = 0;
    static const uint8_t line_offset = 0;
    static const uint8_t fps = 10;
    static const uint8_t frame_count = 8;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char PROGMEM empty_sprite[SPRITE_HEIGHT(2)][SPRITE_WIDTH(2)] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };
    static const char PROGMEM ring_sprites[8][SPRITE_HEIGHT(2)][SPRITE_WIDTH(2)] = {
        {
            { 0, 0, 0, 2, 14, 31, 15, 15, 15, 31, 14, 2, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        },
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 12, 31, 62, 126, 124, 56, 32, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        },
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 240, 240, 248, 224, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, 7, 15, 3, 0, },
        },
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 24, 124, 62, 63, 31, 14, 2, 0, },
        },
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 32, 56, 124, 120, 120, 120, 124, 56, 32, 0, 0, 0, 0, },
        },
        {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 2, 14, 31, 63, 62, 124, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        },
        {
            { 224, 248, 240, 240, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 3, 15, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        },
        {
            { 32, 56, 124, 126, 62, 31, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        },
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

    SPRITE_ANIMATION_TICK(frame, fps, frame_count);

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(enabled ? ring_sprites[frame][row] : empty_sprite[row], sprite_width);
    }
}

static void render_progress_info(void) {
    static const uint8_t column_offset = 0;
    static const uint8_t line_offset = 2;
    static const uint8_t sprites = 12;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char PROGMEM empty_sprite[SPRITE_HEIGHT(2)][SPRITE_WIDTH(2)] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };
    static const char PROGMEM info_sprites[12][SPRITE_HEIGHT(2)][SPRITE_WIDTH(2)] = {
        { // 0
            { 0, 248, 252, 252, 124, 60, 60, 60, 60, 60, 60, 60, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 240, 231, 230, 228, 229, 225, 227, 231, 240, 255, 255, 127, },
        },
        { // 1
            { 0, 248, 252, 252, 60, 252, 252, 252, 252, 252, 60, 252, 252, 252, 252, 248, },
            { 0, 127, 255, 255, 240, 252, 252, 252, 252, 252, 252, 252, 253, 255, 255, 127, },
        },
        { // 2
            { 0, 248, 252, 252, 60, 60, 124, 252, 252, 252, 60, 60, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 240, 243, 254, 252, 249, 243, 243, 243, 248, 255, 255, 127, },
        },
        { // 3
            { 0, 248, 252, 252, 124, 60, 252, 252, 252, 252, 252, 60, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 248, 243, 243, 243, 248, 243, 243, 243, 248, 255, 255, 127, },
        },
        { // 4
            { 0, 248, 252, 252, 252, 252, 252, 28, 156, 60, 124, 252, 252, 252, 252, 248, },
            { 0, 127, 255, 255, 240, 249, 249, 240, 249, 249, 248, 248, 249, 255, 255, 127, },
        },
        { // 5
            { 0, 248, 252, 252, 124, 60, 252, 252, 60, 60, 60, 60, 60, 252, 252, 248, },
            { 0, 127, 255, 255, 248, 243, 243, 243, 243, 248, 255, 255, 240, 255, 255, 127, },
        },
        { // 6
            { 0, 248, 252, 252, 124, 60, 60, 60, 60, 60, 60, 124, 252, 252, 252, 248, },
            { 0, 127, 255, 255, 248, 243, 243, 243, 248, 255, 255, 254, 248, 255, 255, 127, },
        },
        { // 7
            { 0, 248, 252, 252, 124, 124, 124, 252, 252, 252, 60, 60, 60, 252, 252, 248, },
            { 0, 127, 255, 255, 254, 254, 254, 249, 243, 231, 231, 231, 224, 255, 255, 127, },
        },
        { // 8
            { 0, 248, 252, 252, 124, 60, 60, 60, 124, 60, 60, 60, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 248, 243, 243, 243, 248, 243, 243, 243, 248, 255, 255, 127, },
        },
        { // 9
            { 0, 248, 252, 252, 124, 252, 252, 252, 124, 60, 60, 60, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 252, 252, 249, 249, 240, 243, 243, 243, 248, 255, 255, 127, },
        },
        { // +
            { 0, 248, 252, 252, 252, 252, 252, 252, 60, 252, 252, 252, 252, 252, 252, 248, },
            { 0, 127, 255, 255, 255, 255, 252, 252, 240, 252, 252, 255, 255, 255, 255, 127, },
        },
        { // #
            { 0, 248, 252, 252, 124, 124, 60, 124, 124, 124, 60, 124, 124, 252, 252, 248, },
            { 0, 127, 255, 255, 242, 242, 224, 242, 242, 242, 224, 242, 242, 255, 255, 127, },
        },
    };

    int8_t info = -1;

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(info >= 0 && info < sprites ? info_sprites[info][row] : empty_sprite[row], sprite_width);
    }
}

static bool oled_task_user_master(void) {
    render_layers();
    render_caps_lock();
    render_progress_ring();
    render_progress_info();
    return false;
}

bool oled_task_user(void) {
    return is_keyboard_master()
        ? oled_task_user_master()
        : false;
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
