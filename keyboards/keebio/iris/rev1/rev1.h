#pragma once

#include "iris.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, LT4, RT4, R20, R21, R22, R23, R24, R25, \
                        LT1, LT2, LT3, RT3, RT2, RT1 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05, KC_NO }, \
        { L10, L11, L12, L13, L14, L15, KC_NO }, \
        { L20, L21, L22, L23, L24, L25, LT4 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, LT1, LT2, LT3 }, \
        { R05, R04, R03, R02, R01, R00, KC_NO }, \
        { R15, R14, R13, R12, R11, R10, KC_NO }, \
        { R25, R24, R23, R22, R21, R20, RT4 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, RT1, RT2, RT3 } \
    }
