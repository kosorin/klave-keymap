#pragma once

#include "quantum.h"


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
    UCTM__COUNT,
};

extern uint8_t unicode_typing_mode;


bool process_record_unicode(uint16_t keycode, keyrecord_t *record);
