#if defined(KEY_CHAIN_ENABLE)
    #include "features/key_chain.f.h"
#endif

#include "quantum.h"


#if defined(DYNAMIC_MACRO_ENABLE)
extern bool dynamic_macro_recording;
#endif

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
    static const uint8_t column_offset = 9;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char layer_sprites[SPRITE_HEIGHT(2) * SPRITE_WIDTH(2) * 12] PROGMEM = {
        0,248,252,252,124, 60, 60, 60, 60, 60, 60, 60,124,252,252,248,  0,127,255,255,240,231,230,228,229,225,227,231,240,255,255,127,  0,248,252,252, 60,252,252,252,252,252, 60,252,252,252,252,248,  0,127,255,255,240,252,252,252,252,252,252,252,253,255,255,127,  0,248,252,252, 60, 60,124,252,252,252, 60, 60,124,252,252,248,  0,127,255,255,240,243,254,252,249,243,243,243,248,255,255,127,  0,248,252,252,124, 60,252,252,252,252,252, 60,124,252,252,248,  0,127,255,255,248,243,243,243,248,243,243,243,248,255,255,127,
        0,248,252,252,252,252,252, 28,156, 60,124,252,252,252,252,248,  0,127,255,255,240,249,249,240,249,249,248,248,249,255,255,127,  0,248,252,252,124, 60,252,252, 60, 60, 60, 60, 60,252,252,248,  0,127,255,255,248,243,243,243,243,248,255,255,240,255,255,127,  0,248,252,252,124, 60, 60, 60, 60, 60, 60,124,252,252,252,248,  0,127,255,255,248,243,243,243,248,255,255,254,248,255,255,127,  0,248,252,252,124,124,124,252,252,252, 60, 60, 60,252,252,248,  0,127,255,255,254,254,254,249,243,231,231,231,224,255,255,127, 
        0,248,252,252,124, 60, 60, 60,124, 60, 60, 60,124,252,252,248,  0,127,255,255,248,243,243,243,248,243,243,243,248,255,255,127,  0,248,252,252,124,252,252,252,124, 60, 60, 60,124,252,252,248,  0,127,255,255,252,252,249,249,240,243,243,243,248,255,255,127,  0,248,252,252,252,252,252,252, 60,252,252,252,252,252,252,248,  0,127,255,255,255,255,252,252,240,252,252,255,255,255,255,127,  0,248,252,252,124,124, 60,124,124,124, 60,124,124,252,252,248,  0,127,255,255,242,242,224,242,242,242,224,242,242,255,255,127,
    };

    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P(layer_sprites + ((sprite_width * row) + (layer * sprite_width * sprite_height)), sprite_width);
    }
}

static void render_caps_lock(void) {
    static const uint8_t column_offset = 18;
    static const uint8_t line_offset = 0;
    static const uint8_t sprite_height = SPRITE_HEIGHT(4);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char caps_lock_sprites[][SPRITE_HEIGHT(4) * SPRITE_WIDTH(2)] PROGMEM = {
        { /* Off */ 0, 0, 0, 0, 128, 192, 96, 96, 96, 96, 96, 192, 128, 0, 0, 0, 0, 0, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 0, 0, 0, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 6, 3, 0, 0, 0, },
        { /* On */ 0, 248, 252, 254, 126, 62, 158, 158, 158, 158, 158, 62, 126, 254, 252, 248, 0, 255, 255, 255, 152, 147, 147, 31, 159, 159, 147, 51, 120, 255, 255, 255, 0, 255, 255, 255, 9, 153, 153, 152, 25, 153, 153, 156, 14, 255, 255, 255, 0, 31, 63, 127, 127, 127, 127, 127, 124, 121, 121, 121, 124, 127, 63, 31, },
#if defined(CAPS_WORD_ENABLE)
        { /* Word */ 0, 248, 12, 6, 130, 194, 98, 98, 98, 98, 98, 194, 130, 6, 12, 248, 0, 255, 0, 0, 103, 108, 108, 224, 96, 96, 108, 204, 135, 0, 0, 255, 0, 255, 0, 0, 246, 102, 102, 103, 230, 102, 102, 99, 241, 0, 0, 255, 0, 31, 48, 96, 64, 64, 64, 64, 67, 70, 70, 70, 67, 96, 48, 31, },
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
        oled_write_raw_P(caps_lock_sprites[sprite_index] + (sprite_width * row), sprite_width);
    }
}

static void render_progress_ring(void) {
    static const uint8_t column_offset = 0;
    static const uint8_t line_offset = 0;
    static const uint8_t fps = 10;
    static const uint8_t frame_count = 8;
    static const uint8_t sprite_height = SPRITE_HEIGHT(2);
    static const uint8_t sprite_width = SPRITE_WIDTH(2);
    static const char empty_sprite[SPRITE_HEIGHT(2) * SPRITE_WIDTH(2)] PROGMEM = 
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
    static const char ring_sprites[][SPRITE_HEIGHT(2) * SPRITE_WIDTH(2)] PROGMEM = {
        { 0, 0, 0, 2, 14, 31, 15, 15, 15, 31, 14, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 12, 31, 62, 126, 124, 56, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 240, 240, 248, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 7, 7, 15, 3, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 124, 62, 63, 31, 14, 2, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 56, 124, 120, 120, 120, 124, 56, 32, 0, 0, 0, 0, },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 14, 31, 63, 62, 124, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 224, 248, 240, 240, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 15, 7, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
        { 32, 56, 124, 126, 62, 31, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    };

    bool enabled = false;
    if (false) { }
#if defined(KEY_LOCK_ENABLE)
    else if (watching) {
        enabled = true;
    }
#endif
#if defined(KEY_CHAIN_ENABLE)
    else if (is_key_chain_active()) {
        enabled = true;
    }
#endif
#if defined(DYNAMIC_MACRO_ENABLE)
    else if (dynamic_macro_recording) {
        enabled = true;
    }
#endif

    SPRITE_ANIMATION_TICK(frame, fps, frame_count, enabled);

    for (uint8_t row = 0; row < sprite_height; row++) {
        oled_set_cursor(column_offset, line_offset + row);
        oled_write_raw_P((enabled ? ring_sprites[frame] : empty_sprite) + (sprite_width * row), sprite_width);
    }
}

static bool oled_task_user_master(void) {
    render_layers();
    render_caps_lock();
    render_progress_ring();
    return PROCESS_HANDLED;
}

bool oled_task_user(void) {
    return is_keyboard_master()
        ? oled_task_user_master()
        : PROCESS_HANDLED;
}
