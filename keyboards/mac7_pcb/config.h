#pragma once

#include "config_common.h"
#define VIAL_KEYBOARD_UID {0x43, 0xB7, 0xDE, 0x1F, 0x8B, 0x94, 0xF0, 0xE7}

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414B
#define PRODUCT_ID      0x0014
#define DEVICE_VER      0x0001
#define PRODUCT         Mac7 //Edited by wplnguyen & schmintendo

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { D7 }
#define MATRIX_COL_PINS { E6, B4, B5, B1, B3, B2, B6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Underglow options */
#define RGB_DI_PIN F7
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 6
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

