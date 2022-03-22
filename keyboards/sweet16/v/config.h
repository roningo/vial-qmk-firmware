#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x0012
#define DEVICE_VER      0x0001

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, D6, D7, B4 }
#define MATRIX_COL_PINS { F7, F6, F5, F4, F1, F0, E6, B0, B7, D0, D1, D2, D3, D5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Encoder pins */
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4

/* Underglow options */
#define RGB_DI_PIN F4
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 1
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
