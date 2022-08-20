#pragma once


enum combo_events {
    C_COPY,
    C_SAVE,
    C_FIND,
    C_CAPS_LOCK,
#if defined(CAPS_WORD_ENABLE)
    C_CAPS_WORD,
    C_SPONGEBOB_CASE,
    C_CAMEL_CASE,
    C_PASCAL_CASE,
    C_SNAKE_CASE,
    C_KEBAB_CASE,
#endif
    COMBO_COUNT,
};
