#pragma once

#include "quantum.h"

// Any changes to the layout names and/or definitions must also be made to info.json

#define LAYOUT_ortho_4x4( \
	K52, K00, K01, K02, K03, K04, K05, K30, K31, K32, K33,     \
		 K10, K11, K12, K13, K14, K15, K40, K41, K42, K43,     \
		 K20, K21, K22, K23, K24, K25, K50, K51,               \
	K35, K53, K34, K44, K54, K55,                          K45 \
) { \
    { K00,  K01,   	K02,  	K03, 	K04, 	K05 }, \
    { K10,  K11,   	K12,  	K13, 	K14, 	K15 }, \
    { K20,  K21,   	K22,   	K23, 	K24, 	K25 }, \
	{ K30,  K31,   	K32,   	K33, 	K34, 	K35 }, \
    { K40, 	K41, 	K42, 	K43, 	K44, 	K45 }, \
	{ K50, 	K51,	K52, 	K53, 	K54, 	K55 }  \
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
