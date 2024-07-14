#pragma once

#include "quantum.h"


bool process_record_switcher(uint16_t keycode, keyrecord_t *record);
bool is_switcher_active(void);
void switcher_end(void);
