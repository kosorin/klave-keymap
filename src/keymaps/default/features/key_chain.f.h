// Simplified version of https://github.com/andrewjrae/kyria-keymap/blob/e3ad77dc4d48b8e6a842c9136c76c1021ab5976b/README.org#userspace-leader-sequences

#pragma once

#include "action.h"


bool process_key_chain(uint16_t start_keycode, uint16_t keycode, const keyrecord_t *record);

void *key_chain_start_user(uint8_t keycode);

void key_chain_start(void);

void key_chain_stop(void);

bool is_key_chain_active(void);
