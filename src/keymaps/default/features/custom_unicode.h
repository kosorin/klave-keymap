// Modified version of https://github.com/qmk/qmk_firmware/blob/breakpoint_2023_05_28/users/drashna/keyrecords/unicode.md

#pragma once

#include "action.h"

enum unicode_typing_modes {
    UCTM_NONE,
    UCTM_CZECH,
    UCTM_MATH_SCRIPT,
    UCTM_MATH_FRAKTUR,
    UCTM_CIRCLE,
    UCTM_SQUARE,
    UCTM_SQUARE_OUTLINE,
    UCTM_REGIONAL,
    UCTM_ZALGO,
    unicode_typing_modes_COUNT,
};

bool process_record_custom_unicode(uint16_t keycode, keyrecord_t *record);

void set_unicode_typing_mode(uint8_t typing_mode);
void clear_unicode_typing_mode(void);
