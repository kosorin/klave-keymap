#pragma once


enum combo_events {
    C_COPY,
    C_SAVE,
    C_FIND,
    C_CAPS_LOCK,
#if defined(CAPS_WORD_ENABLE)
    C_SMART_CASE_CAPS_WORD,
    C_SMART_CASE_MOCKING,
#endif
    combo_events_COUNT,
};
