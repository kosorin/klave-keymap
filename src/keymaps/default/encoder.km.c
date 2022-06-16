#include "action.h"


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            return PROCESS_HANDLED;
        default:
            return PROCESS_NOT_HANDLED;
    }
}
