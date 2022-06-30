#pragma once

#include <stdbool.h>


typedef enum {
    SC_CAPS_WORD,
    SC_SPONGEBOB,
    SC_CAMEL,
    SC_PASCAL,
    SC_SNAKE,
    SC_KEBAB,
} smart_case_type_t;

typedef struct {
    smart_case_type_t type;
    union {
        struct {
            bool upper_case;
        } spongebob;
    };
} smart_case_t;

extern smart_case_t smart_case;
