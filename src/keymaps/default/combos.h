#pragma once


enum combo_events {
    C_COPY,
    C_SAVE,
    C_FIND,
    C_CAPS_LOCK,
#if defined(CAPS_WORD_ENABLE)
    C_CAPS_WORD,
    C_MOCKING_CASE,
#endif
    combo_events_COUNT,
};
