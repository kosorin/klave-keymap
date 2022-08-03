#include "layers.km.h"
#if defined(DYNAMIC_MACRO_ENABLE)
    #include "dynamic_macro.km.h"
#endif
#if defined(KEY_CHAIN_ENABLE)
    #include "features/key_chain.f.h"
#endif

#include "quantum.h"


#if defined(KEY_LOCK_ENABLE)
extern bool watching;
#endif


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}


#define SPRITE_WIDTH(width) (width * 8)
#define SPRITE_HEIGHT(height) (height)
#define SPRITE_ANIMATION_TICK(frame, fps, frame_count, enabled) \
    static int8_t frame = -1; \
    static uint16_t frame##_elapsed = 0; \
    static uint16_t frame##_time = 0; \
    if (enabled) { \
        frame##_elapsed = timer_elapsed(frame##_time); \
        if (frame##_elapsed > 1000 / (fps)) { \
            frame##_time += frame##_elapsed; \
            frame = (frame + 1) % (frame_count); \
        } \
    } \
    else { \
        frame = -1; \
        frame##_elapsed = 0; \
        frame##_time = 0; \
    };

static void render_layers(void) {
    static const uint8_t column_offset = 8;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(4);
    static const char layer_sprites[] PROGMEM = { // ^(\s+)( \d+,){32} => $0\n$1
        // L_BASE
        0, 0, 60, 4, 4, 4, 0, 0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 60, 0, 0,
        0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0,
        0, 0, 243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 243, 0, 0,
        0, 0, 60, 32, 32, 32, 0, 0, 32, 32, 32, 32, 0, 0, 32, 32, 32, 32, 0, 0, 32, 32, 32, 32, 0, 0, 32, 32, 32, 60, 0, 0,
#if defined(UNICODEMAP_ENABLE)
        // L_UNICODE
        192, 192, 48, 48, 12, 12, 12, 12, 12, 12, 60, 60, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 240, 240,
        255, 255, 0, 0, 192, 192, 192, 192, 192, 192, 12, 12, 207, 207, 207, 207, 207, 207, 15, 15, 15, 15, 207, 207, 15, 15, 15, 15, 15, 15, 3, 3,
        255, 255, 0, 0, 204, 204, 204, 204, 207, 207, 204, 204, 255, 255, 12, 12, 207, 207, 204, 204, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0,
        255, 255, 192, 192, 204, 204, 204, 204, 207, 207, 192, 192, 207, 207, 195, 195, 207, 207, 204, 204, 192, 192, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0,
#endif
        // L_SYMBOL
        0, 0, 0, 0, 192, 192, 240, 240, 240, 240, 240, 240, 0, 0, 192, 192, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 192, 192, 0, 0, 0, 0,
        0, 0, 15, 15, 255, 255, 255, 255, 3, 3, 51, 51, 0, 0, 255, 255, 255, 255, 3, 3, 51, 51, 3, 3, 255, 255, 255, 255, 15, 15, 0, 0,
        0, 0, 207, 207, 63, 63, 255, 255, 252, 252, 252, 252, 252, 252, 255, 255, 63, 63, 0, 0, 252, 252, 252, 252, 255, 255, 63, 63, 207, 207, 0, 0,
        0, 0, 0, 0, 3, 3, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 3, 12, 12, 12, 12, 12, 12, 12, 12, 3, 3, 0, 0, 0, 0,
        // L_FUNCTION
        0, 0, 60, 60, 255, 255, 243, 243, 243, 243, 243, 243, 243, 243, 195, 195, 243, 243, 195, 195, 255, 255, 60, 60, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 255, 255, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 0, 0, 252, 252, 252, 252, 252, 252, 255, 255, 0, 0, 15, 15, 15, 15, 252, 252,
        0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 195, 195, 60, 60, 60, 60, 60, 60, 195, 195, 255, 255, 255, 255, 0, 0, 60, 60, 60, 60, 15, 15,
        0, 0, 15, 15, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 0, 0, 63, 63, 63, 63, 63, 63, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0,
        // L_NAVIGATION
        0, 0, 0, 0, 192, 192, 48, 48, 192, 192, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 48, 48, 48, 48, 240, 240, 192, 192, 0, 0, 0, 0,
        0, 0, 255, 255, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 192, 192, 195, 195, 207, 207, 63, 63, 252, 252, 195, 195, 255, 255, 0, 0,
        0, 0, 255, 255, 0, 0, 255, 255, 15, 15, 255, 255, 252, 252, 240, 240, 207, 207, 12, 12, 207, 207, 240, 240, 252, 252, 3, 3, 255, 255, 0, 0,
        0, 0, 3, 3, 12, 12, 51, 51, 15, 15, 60, 60, 51, 51, 51, 51, 51, 51, 63, 63, 60, 60, 60, 60, 60, 60, 12, 12, 3, 3, 0, 0,
        // L_NUMBER
        0, 0, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 0, 0, 0, 0, 0, 0, 204, 204, 51, 51, 51, 51, 51, 51, 51, 51, 204, 204,
        243, 243, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 51, 51, 204, 204, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255,
        15, 15, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 192, 192, 0, 0, 0, 0, 3, 3, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 12, 12, 48, 48, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 63, 63,
        // L_MEDIA
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 240, 252, 252, 240, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 240, 240, 252, 252, 240, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 51, 51, 15, 15, 3, 3, 0, 0,
        0, 0, 0, 0, 195, 195, 3, 3, 3, 3, 3, 3, 3, 3, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 15, 15, 63, 63, 63, 63, 48, 48, 48, 48, 48, 48, 63, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        // L_SYSTEM
        240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 0, 0, 255, 255, 255, 255, 255, 255, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240,
        192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 207, 207, 207, 207, 207, 207, 0, 0, 252, 252, 252, 252, 252, 252, 192, 192, 192, 192, 192, 192,
        3, 3, 3, 3, 3, 3, 243, 243, 243, 243, 243, 243, 3, 3, 3, 3, 3, 3, 0, 0, 63, 63, 63, 63, 63, 63, 3, 3, 3, 3, 3, 3,
        15, 15, 15, 15, 0, 0, 255, 255, 255, 255, 255, 255, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
#if defined(GAMING_ENABLE)
        // L_GAME
        0, 0, 0, 0, 240, 240, 12, 12, 243, 243, 252, 252, 255, 255, 63, 63, 15, 15, 63, 63, 255, 255, 252, 252, 240, 240, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 15, 15, 48, 48, 207, 207, 63, 63, 255, 255, 255, 255, 60, 60, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 240, 240, 12, 12, 243, 243, 252, 252, 255, 255, 63, 63, 252, 252, 63, 63, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 15, 15, 48, 48, 207, 207, 63, 63, 255, 255, 243, 243, 255, 255, 243, 243, 255, 255, 63, 63, 15, 15, 0, 0, 0, 0, 0, 0,
        // L_GAME_EXTENDED
        0, 0, 0, 0, 240, 240, 12, 12, 243, 243, 252, 252, 255, 255, 63, 63, 15, 15, 63, 63, 255, 255, 252, 252, 240, 240, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 15, 15, 48, 48, 207, 207, 63, 63, 255, 255, 255, 255, 60, 60, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 240, 240, 12, 12, 243, 243, 252, 252, 255, 255, 63, 63, 252, 252, 63, 63, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 15, 15, 48, 48, 207, 207, 63, 63, 255, 255, 243, 243, 255, 255, 243, 243, 255, 255, 63, 63, 15, 15, 0, 0, 0, 0, 0, 0,
#endif
    };

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(layer_sprites + (layer * sprite_width * sprite_height) + (sprite_width * row), sprite_width);
    }
}

static void render_caps_lock(void) {
    static const uint8_t column_offset = 18;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char caps_lock_sprites[] PROGMEM = {
        // Off
        0, 0, 0, 0, 128, 192, 96, 96, 96, 96, 96, 192, 128, 0, 0, 0, 0, 0, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 0,
        0, 0, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 3, 0, 0, 0,
        // On
        0, 248, 252, 254, 126, 62, 158, 158, 158, 158, 158, 62, 126, 254, 252, 248, 0, 255, 255, 255, 152, 147, 147, 31, 159, 159, 147, 51, 120, 255, 255, 255,
        0, 255, 255, 255, 9, 153, 153, 152, 25, 153, 153, 156, 14, 255, 255, 255, 0, 31, 63, 127, 127, 127, 127, 127, 124, 121, 121, 121, 124, 127, 63, 31,
#if defined(CAPS_WORD_ENABLE)
        // Word
        0, 248, 12, 6, 130, 194, 98, 98, 98, 98, 98, 194, 130, 6, 12, 248, 0, 255, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 255,
        0, 255, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 255, 0, 31, 48, 96, 64, 64, 64, 64, 67, 70, 70, 70, 67, 96, 48, 31,
#endif
    };

    const led_t led_state = host_keyboard_led_state();

    uint8_t sprite_index = led_state.caps_lock ? 1 : 0;

#if defined(CAPS_WORD_ENABLE)
    SPRITE_ANIMATION_TICK(caps_word_frame, 4, 2, is_caps_word_on());
    if (caps_word_frame == 0) {
        sprite_index = 2;
    }
#endif

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(caps_lock_sprites + (sprite_index * sprite_width * sprite_height) + (sprite_width * row), sprite_width);
    }
}

static void render_progress(void) {
    static const uint8_t column_offset = 0;
    static const uint8_t line_offset = 0;
    static const uint8_t ring_fps = 10;
    static const uint8_t ring_frame_count = 8;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char empty_sprite[] PROGMEM = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    static const char ring_sprites[] PROGMEM = {
        0, 0, 0, 2, 14, 31, 15, 15, 15, 31, 14, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 12, 31, 62, 126, 124, 56, 32, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 240, 240, 248, 224, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, 7, 15, 3, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 24, 124, 62, 63, 31, 14, 2, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 32, 56, 124, 120, 120, 120, 124, 56, 32, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 14, 31, 63, 62, 124, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        224, 248, 240, 240, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 15, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        32, 56, 124, 126, 62, 31, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    const char *info_sprite = empty_sprite;
    bool enabled = false;
    if (false) { }
#if defined(KEY_LOCK_ENABLE)
    else if (watching) {
        static const char key_lock_sprite[] PROGMEM = {
            0, 0, 0, 42, 62, 28, 28, 254, 254, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 60, 126, 102, 102, 102, 103, 103, 102, 102, 102, 126, 60, 0, 0,
        };
        info_sprite = key_lock_sprite;
        enabled = true;
    }
#endif
#if defined(KEY_CHAIN_ENABLE)
    else if (is_key_chain_active()) {
        static const char key_chain_sprite[] PROGMEM = {
            56, 184, 216, 240, 224, 224, 224, 224, 224, 224, 240, 216, 184, 56, 56, 56,
            28, 29, 29, 14, 6, 8, 12, 12, 0, 6, 14, 29, 29, 28, 28, 28,
        };
        info_sprite = key_chain_sprite;
        enabled = true;
    }
#endif
#if defined(DYNAMIC_MACRO_ENABLE)
    else if (is_dynamic_macro_recording()) {
        static const char dynamic_macro_sprite[] PROGMEM = {
            251, 250, 11, 251, 11, 251, 11, 251, 7, 255, 255, 7, 199, 199, 199, 199,
            223, 95, 208, 223, 208, 223, 208, 223, 224, 255, 255, 224, 239, 235, 235, 239,
        };
        info_sprite = dynamic_macro_sprite;
        enabled = true;
    }
#endif

    SPRITE_ANIMATION_TICK(ring_frame, ring_fps, ring_frame_count, enabled);

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P((enabled ? ring_sprites + (ring_frame * sprite_width * sprite_height) : empty_sprite) + (sprite_width * row), sprite_width);
    }

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + sprite_height + row);
        oled_write_raw_P(info_sprite + (sprite_width * row), sprite_width);
    }
}

static bool oled_task_user_master(void) {
    render_layers();
    render_caps_lock();
    render_progress();
    return PROCESS_HANDLED;
}

bool oled_task_user(void) {
    return is_keyboard_master()
        ? oled_task_user_master()
        : PROCESS_HANDLED;
}
