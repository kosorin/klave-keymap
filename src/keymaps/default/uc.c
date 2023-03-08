#include "uc.h"
#include "kc.h"

#include "quantum.h"
#include "process_unicode_common.h"
#include "unicode.h"
#include "progmem.h"


uint8_t unicode_typing_mode = UCTM_NONE;


typedef uint32_t (*translator_function_t)(uint32_t keycode, bool is_shifted);

#define DEFINE_UNICODE_RANGE_TRANSLATOR(translator_name, alpha_lower, alpha_upper, number_zero, number_one, space)  \
    static inline uint32_t translator_name(uint32_t keycode, bool is_shifted) {                                     \
        switch (keycode) {                                                                                          \
            case KC_A ... KC_Z:                                                                                     \
                return (is_shifted ? alpha_upper : alpha_lower) + (keycode - KC_A);                                 \
            case KC_0:                                                                                              \
                return number_zero;                                                                                 \
            case KC_1 ... KC_9:                                                                                     \
                return number_one + (keycode - KC_1);                                                               \
            case KC_SPACE:                                                                                          \
                return space;                                                                                       \
        }                                                                                                           \
        return keycode;                                                                                             \
    }

#define DEFINE_UNICODE_ALPHABET_TRANSLATOR(translator_name, ...)                    \
    static inline uint32_t translator_name(uint32_t keycode, bool is_shifted) {     \
        static const uint32_t map[] = {__VA_ARGS__};                                \
        _Static_assert(ARRAY_SIZE(map) == ((KC_Z - KC_A) + 1) * 2, "");             \
        switch (keycode) {                                                          \
            case KC_A ... KC_Z:                                                     \
                return map[keycode - KC_A + (is_shifted ? (KC_Z - KC_A) + 1 : 0)];  \
        }                                                                           \
        return keycode;                                                             \
    }


DEFINE_UNICODE_ALPHABET_TRANSLATOR(unicode_translator_czech,
    // Lower
    0x00e1, // a á
    0, // b
    0x010d, // c č
    0x010f, // d ď
    0x011b, // e ě
    0, // f
    0, // g
    0x00e9, // h é
    0x00ed, // i í
    0, // j
    0, // k
    0x00fa, // l ú
    0, // m
    0x0148, // n ň
    0x00f3, // o ó
    0, // p
    0, // q
    0x0159, // r ř
    0x0161, // s š
    0x0165, // t ť
    0x016f, // u ů
    0, // v
    0, // w
    0, // x
    0x00fd, // y ý
    0x017e, // z ž

    0x00c1, // A Á
    0, // B
    0x010c, // C Č
    0x010e, // D Ď
    0x011a, // E Ě
    0, // F
    0, // G
    0x00c9, // H É
    0x00cd, // I Í
    0, // J
    0, // K
    0x016e, // L Ů
    0, // M
    0x0147, // N Ň
    0x00d3, // O Ó
    0, // P
    0, // Q
    0x0158, // R Ř
    0x0160, // S Š
    0x0164, // T Ť
    0x00da, // U Ú
    0, // V
    0, // W
    0, // X
    0x00dd, // Y Ý
    0x017d, // Z Ž
);

DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_translator_script, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7CF, 0x2002);

static bool process_record_zalgo(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        tap_code16(keycode);

        int number = (rand() % (8 + 1 - 2)) + 2;
        for (int index = 0; index < number; index++) {
            uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
            register_unicode(hex);
        }

        return PROCESS_HANDLED;
    }
    return PROCESS_NOT_HANDLED;
}


static uint8_t check_shift(uint16_t keycode) {
    uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

#if defined(CAPS_WORD_ENABLE)
    // This is not so nice workaround.
    // We must handle CapsWord here because `process_record_user()` is called before `process_caps_word()`.
    if (is_caps_word_on()) {
        if (caps_word_press_user(keycode)) {
            mods |= get_weak_mods();
            clear_weak_mods();
        }
        else {
            caps_word_off();
        }
    }
#endif

    return mods & MOD_MASK_SHIFT;
}

static bool process_record_unicode_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator) {
    if (record->event.pressed) {
        bool is_shifted = check_shift(keycode);
        uint32_t cp = translator(keycode, is_shifted);
        if (!cp) {
            return PROCESS_NOT_HANDLED;
        }
        register_unicode(cp);
    }
    return PROCESS_HANDLED;
}

bool process_record_unicode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_UCTM_NONE ... KC_UCTM_NONE + (UCTM__COUNT - 1):
            if (record->event.pressed) {
                if (unicode_typing_mode != keycode - KC_UCTM_NONE) {
                    unicode_typing_mode = keycode - KC_UCTM_NONE;
                }
                else {
                    unicode_typing_mode = UCTM_NONE;
                }
            }
            return PROCESS_HANDLED;
    }

    if (unicode_typing_mode == UCTM_NONE) {
        return PROCESS_NOT_HANDLED;
    }

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0) {
                return PROCESS_NOT_HANDLED;
            }
            keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            break;
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return PROCESS_NOT_HANDLED;
            }
            keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
            break;
    }

    if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
        return PROCESS_NOT_HANDLED;
    }

    if (unicode_typing_mode == UCTM_CZECH) {
        if ((KC_A <= keycode) && (keycode <= KC_Z)) {
            return process_record_unicode_replacement(keycode, record, unicode_translator_czech);
        }
    }
    else if (unicode_typing_mode == UCTM_SCRIPT) {
        if (((KC_A <= keycode) && (keycode <= KC_0)) || keycode == KC_SPACE) {
            return process_record_unicode_replacement(keycode, record, unicode_translator_script);
        }
    }
    else if (unicode_typing_mode == UCTM_ZALGO) {
        if ((KC_A <= keycode) && (keycode <= KC_0)) {
            return process_record_zalgo(keycode, record);
        }
    }
    return PROCESS_NOT_HANDLED;
}