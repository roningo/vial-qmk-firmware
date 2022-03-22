#pragma once

#include "quantum.h"

// Any changes to the layout names and/or definitions must also be made to info.json

#define LAYOUT_ortho( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, 	\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, 	\
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29	\
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29 } \
}

/* #define LAYOUT_numpad_4x4( \
    K00, K01, K02, K03, \
    K10, K11, K12,      \
    K20, K21, K22, K23, \
       K31,   K32      \
) { \
    { K00,   K01,   K02,   K03 }, \
    { K10,   K11,   K12,   KC_NO }, \
    { K20,   K21,   K22,   K23 }, \
    { KC_NO, K31,   K32,   KC_NO }  \
}
 */
