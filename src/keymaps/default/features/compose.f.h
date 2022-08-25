#pragma once

#include "action.h"


extern const char *compose_map[][2];


bool process_compose(uint16_t keycode, const keyrecord_t *record);

void process_compose_direct(uint8_t compose_index);
