
/*
Copyright 2021 Matthew Dias

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODER_RESOLUTION 2

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Underglow options */
#define RGB_DI_PIN F7
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 6
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT
