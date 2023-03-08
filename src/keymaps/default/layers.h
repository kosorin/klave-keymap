#pragma once


enum layers {
    L_BASE,
    L_SYMBOL,
    L_FUNCTION,
#if defined(SWITCHER_ENABLE)
    L_SWITCH,
#endif
    L_MEDIA,
    L_NUMBER,
    L_NUMBER_SYMBOL,
    L_NAVIGATION,
    L_SYSTEM,
#if defined(GAMING_ENABLE)
    L_GAME,
    L_GAME_EXTENDED,
#endif
    LAYER_COUNT,
};
