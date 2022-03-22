/*
Copyright 2020 Thanh Nguyen <thanhnguyen12@gmail.com>>

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


//#define USE_SERIAL
#define USE_I2C
//#define EE_HANDS
#define TAPPING_TERM 130
#define PERMISSIVE_HOLD
#define SPLIT_USB_DETECT

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SPLIT
#define RGBLED_NUM 10    // Number of LEDs
//#define RGBLED_SPLIT { 5, 5 }

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define ENCODER_DIRECTION_FLIP
// #define ENCODER_RESOLUTION 2