#pragma once


enum combo_events {
    C_UNDO,
    C_REDO,
    C_COPY,
    C_PASTE,
    C_SAVE,
    C_FIND,
    C_CAPS_LOCK,
#if defined(CAPS_WORD_ENABLE)
    C_CAPS_WORD,
#endif
    COMBO_COUNT,
};
