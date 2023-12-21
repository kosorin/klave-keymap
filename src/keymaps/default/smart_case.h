#pragma once

#include <stdbool.h>


typedef enum {
    SC_CAPS_WORD,
    SC_MOCKING,
} smart_case_type_t;

typedef struct {
    smart_case_type_t type;
    union {
        struct {
            bool upper_case;
        } mocking;
    };
} smart_case_t;

extern smart_case_t smart_case;
