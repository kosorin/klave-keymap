#pragma once

#include "quantum.h"


extern bool is_switching;


bool process_record_switcher(uint16_t keycode, keyrecord_t *record);
