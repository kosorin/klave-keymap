#include "compose.f.h"
#include "compose.km.h"
#include "keycodes.km.h"

#include "quantum.h"


bool process_compose(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed && keycode >= CK_COMPOSE && keycode <= CK_COMPOSE_MAX) {
        process_compose_direct(keycode - CK_COMPOSE);
        return PROCESS_HANDLED;
    }
    return PROCESS_NOT_HANDLED;
}

static uint8_t get_and_clear_all_mods(uint8_t compose_index) {
    uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    clear_mods();
    clear_oneshot_mods();
    clear_weak_mods();

#if defined(CAPS_WORD_ENABLE)
    // This is not so nice workaround.
    // We must handle CapsWord here because `process_record_user()` is called before `process_caps_word()`.
    if (is_caps_word_on()) {
        if (caps_word_press_user(COMPOSE(compose_index))) {
            mods |= get_weak_mods();
            clear_weak_mods();
        }
        else {
            caps_word_off();
        }
    }
#endif

    return mods;
}

void process_compose_direct(uint8_t compose_index) {
    if (compose_index >= XC__COUNT) {
        return;
    }

    compose_data_t *compose_data = &compose_map[compose_index];
    if (compose_data == NULL || compose_data->lowercase == NULL) {
        return;
    }

    const uint8_t saved_mods = get_mods();
    const bool saved_caps_lock = host_keyboard_led_state().caps_lock;

    if (saved_caps_lock) {
        tap_code(KC_CAPS_LOCK);
    }

    const uint8_t mods = get_and_clear_all_mods(compose_index);
    const bool shifted = (mods & MOD_MASK_SHIFT) ? 1 : 0;
    const bool uppercase = compose_data->uppercase != NULL && (shifted ^ saved_caps_lock);
    const char *compose_string = uppercase ? compose_data->uppercase : compose_data->lowercase;

    tap_code(COMPOSE_KEY);
    send_string(compose_string);

    set_mods(saved_mods);
    if (saved_caps_lock) {
        tap_code(KC_CAPS_LOCK);
    }

    return;
}
