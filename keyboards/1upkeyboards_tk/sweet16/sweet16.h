#pragma once

#include "quantum.h"

// Any changes to the layout names and/or definitions must also be made to info.json

#define LAYOUT_ortho_4x4( \
    K00,K01, K02, K03, K04, K05, K06, K07, K08, K09, K010,   K111, K011, K012, K013,  \
    K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K110, K211,  				 \
    K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29,      K210,       K212, 		 \
    K30,   K31,                K34,             K38,         K310, K311, K312,  K313 \
) { \
    { K00, K01, K02,   K03,   K04, K05,   K06,   K07,   K08, K09,   K010, K011, K012,  K013 },  \
    { K10, K11, K12,   K13,   K14, K15,   K16,   K17,   K18, K19,   K110, K111, KC_NO, KC_NO }, \
    { K20, K21, K22,   K23,   K24, K25,   K26,   K27,   K28, K29,   K210, K211, K212,  KC_NO }, \
    { K30, K31, KC_NO, KC_NO, K34, KC_NO, KC_NO, KC_NO, K38, KC_NO, K310, K311, K312,  K313 }   \
}

#define LAYOUT_numpad_4x4( \
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

