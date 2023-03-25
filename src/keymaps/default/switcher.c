#include "switcher.h"
#include "def.h"


bool is_switching = false;


bool process_record_switcher(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SWITCH:
            if (record->event.pressed) {
                is_switching = true;
                register_mods(MOD_BIT(SWITCH_MOD_KEY));
                register_code(KC_TAB);
                layer_on(L_SWITCH);
            }
            else {
                unregister_code(KC_TAB);
            }
            return PROCESS_HANDLED;
    }
    return PROCESS_NOT_HANDLED;
}
