#pragma once

#include "quantum.h"


enum unicode_typing_modes {
    UCTM_NONE,
    UCTM_CZECH,
    UCTM_SCRIPT,
    UCTM_ZALGO,
    UCTM__COUNT,
};

extern uint8_t unicode_typing_mode;


bool process_record_unicode(uint16_t keycode, keyrecord_t *record);
