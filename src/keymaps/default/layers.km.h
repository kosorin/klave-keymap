#pragma once


enum layers {
    L_BASE,
#if defined(UNICODEMAP_ENABLE)
    L_UNICODE,
#endif
    L_SYMBOL,
    L_NUMBER,
    L_NAVIGATION,
    L_FUNCTION,
    L_MEDIA,
    L_SYSTEM,
    L_GAME,
    L_GAME_EXTENDED,
    LAYER_COUNT,
};
