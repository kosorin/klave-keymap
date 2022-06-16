#include "layers.km.h"

#include "process_key_override.h"
#include "keycode.h"
#include "quantum_keycodes.h"


const key_override_t foo_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SPC, KC_TAB, 1 << L_BASE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &foo_key_override,
    NULL,
};
