#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K000, K001, K002, K003, K004,                                     \
	K100, K101, K102, K103, K104,                                     \
	K200, K201, K202, K203, K204,                                     \
	                  K303, K304, K305, K306, K307,                   \
	                                    K406, K407, K408, K409, K410, \
	                                    K506, K507, K508, K509, K510, \
	                                    K606, K607, K608, K609, K610  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K100,  K101,  K102,  K103,  K104,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ K200,  K201,  K202,  K203,  K204,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ KC_NO, KC_NO, KC_NO, K303,  K304,  K305,  K306,  K307,  KC_NO, KC_NO, KC_NO }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K406,  K407,  K408,  K409,  K410 }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K506,  K507,  K508,  K509,  K510 }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K606,  K607,  K608,  K609,  K610 }  \
}

#endif