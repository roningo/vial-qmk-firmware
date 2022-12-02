#include QMK_KEYBOARD_H

#define DEFAULT 0
#define FN1 1
#define FN2 2
#define FN3	3

#define ____ KC_TRNS

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT]=LAYOUT(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R,   KC_T,        KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_BSPC,
        KC_TAB,  KC_A, KC_S, KC_D, KC_F,   KC_G,        KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V,   KC_B,        KC_B, KC_N, KC_M, KC_COMM, KC_SLSH, KC_UP,   KC_ENT,
        KC_LCTL, KC_A, KC_A, KC_A, KC_LALT,      KC_SPC,      KC_A, KC_A, KC_A,    KC_LEFT, KC_DOWN, KC_RIGHT
    ),
	
	[FN1]=LAYOUT(
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, KC_LBRC, KC_DEL,
        KC_CAPS, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, KC_DOT, ____, ____, ____,
        ____, ____, ____, ____, ____,       ____,          ____, ____, ____, ____, ____, ____
    ),
	
	[FN2]=LAYOUT(
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____,       ____,          ____, ____, ____, ____, ____, ____
    ),
	
	[FN3]=LAYOUT(
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, 		 ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____,       ____,          ____, ____, ____, ____, ____, ____
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UP_URL:
            if (record->event.pressed) {
                SEND_STRING("http://1upkeyboards.com");
            }
            return false;
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
