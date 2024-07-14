// Modified version of https://github.com/andrewjrae/kyria-keymap/blob/e3ad77dc4d48b8e6a842c9136c76c1021ab5976b/README.org#userspace-leader-sequences

#pragma once

#include "action.h"


#define KEY_CHAIN_HANDLER(name) _key_chain_handle_##name
#define DEFINE_KEY_CHAIN_HANDLER(name) void *KEY_CHAIN_HANDLER(name)(uint8_t keycode)

typedef void *(*key_chain_handler_t)(uint8_t keycode);


bool process_key_chain(uint16_t keycode, const keyrecord_t *record);
bool is_key_chain_active(void);
void key_chain_start(key_chain_handler_t handler);
void key_chain_stop(void);

key_chain_handler_t key_chain_done(void);
key_chain_handler_t key_chain_cancel(void);
key_chain_handler_t key_chain_bad_key(void);
key_chain_handler_t key_chain_again(void);

DEFINE_KEY_CHAIN_HANDLER(main);
