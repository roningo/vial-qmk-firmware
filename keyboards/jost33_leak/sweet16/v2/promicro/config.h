#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x0010
#define DEVICE_VER      0x0001

#define RX_PIN F5
#define RY_PIN F4
#define LX_PIN F7
#define LY_PIN F6

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, B6, B2, B3, B1 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Joystick */
#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXES_COUNT 4

/* Encoder pins */
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B4 }
#define ENCODER_RESOLUTION 4
#define VIAL_ENCODER_DEFAULT { KC_VOLU, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#define VIAL_ENCODER_KEYCODE_DELAY 10

/* Underglow options */
#define RGB_DI_PIN F4
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 1
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
