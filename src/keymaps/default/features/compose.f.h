#pragma once

#include "action.h"


typedef struct {
    const char *lowercase;
    const char *uppercase;
} compose_data_t;


extern compose_data_t compose_map[];


bool process_compose(uint16_t keycode, const keyrecord_t *record);

void process_compose_direct(uint8_t compose_index);
