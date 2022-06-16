#pragma once


#define _X_ KC_NO // Not a key
#define _U_ KC_NO // Unused

#define LAYOUT( \
        L10,L11,L12,L13,L14,L15,            R15,R14,R13,R12,R11,R10, \
        L20,L21,L22,L23,L24,L25,L50,    R50,R25,R24,R23,R22,R21,R20, \
        L30,L31,L32,L33,L34,L35,            R35,R34,R33,R32,R31,R30, \
                    L42,L43,L54,L55,    R55,R54,R43,R42,             \
        _) \
    { \
        { _U_,_U_,_U_,_U_,_U_,_U_ }, \
        { L10,L11,L12,L13,L14,L15 }, \
        { L20,L21,L22,L23,L24,L25 }, \
        { L30,L31,L32,L33,L34,L35 }, \
        { _X_,_U_,L42,L43,_U_,_U_ }, \
        { L50,_X_,_X_,_X_,L54,L55 }, \
    \
        { _U_,_U_,_U_,_U_,_U_,_U_ }, \
        { R10,R11,R12,R13,R14,R15 }, \
        { R20,R21,R22,R23,R24,R25 }, \
        { R30,R31,R32,R33,R34,R35 }, \
        { _X_,_U_,R42,R43,_U_,_U_ }, \
        { R50,_X_,_X_,_X_,R54,R55 }, \
    }
