#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    SCR_STOP,
    SCR_LOWER,
    SCR_UPPER,
} smart_case_result_t;

typedef enum {
    SC_NONE,
    SC_CAPS_WORD,
    SC_MOCKING,
    smart_case_type_COUNT,
} smart_case_type_t;

typedef struct {
} smart_case_state_caps_word_t;

typedef struct {
    bool upper;
} smart_case_state_mocking_t;

typedef struct {
    smart_case_type_t type;
    union {
        smart_case_state_caps_word_t caps_word;
        smart_case_state_mocking_t mocking;
    } state;
} smart_case_t;

void set_smart_case(smart_case_type_t type);
void clear_smart_case(void);

smart_case_result_t smart_case_press(uint16_t keycode);
smart_case_result_t smart_case_press_caps_word(uint16_t keycode, smart_case_state_caps_word_t* state);
smart_case_result_t smart_case_press_mocking(uint16_t keycode, smart_case_state_mocking_t* state);
