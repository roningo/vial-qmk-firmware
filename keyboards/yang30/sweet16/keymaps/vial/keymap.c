#include QMK_KEYBOARD_H

#define LAYOUT 0
#define FN1 1
#define FN2 2
#define FN3	3

#define ____ KC_TRNS

static uint16_t oled_timer = 0;

bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYOUT]=LAYOUT_ortho(
        KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,  KC_I,    KC_O,    KC_P,   
        KC_A,    KC_S,   KC_D,    KC_F,    KC_G,    KC_H,     KC_J,  KC_K,    KC_L,    KC_ENT,
        KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,     KC_M,  MO(1),   KC_LSFT, KC_SPC
    ),
	
	[FN1]=LAYOUT_ortho(
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____ 
    ),
	
	[FN2]=LAYOUT_ortho(
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____
    ),
	
	[FN3]=LAYOUT_ortho(
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____,
        ____,    ____,    ____,   ____,     ____,    ____,    ____,    ____,    ____,    ____
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer = timer_read();
    }
	switch(keycode){
		case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
	}
    return true;
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif


