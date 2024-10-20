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
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC, 
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, 
		KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_ENT, 
        KC_LSFT, KC_LCTL, MO(FN1), KC_LGUI, KC_LALT, KC_SPC,  KC_SPC, KC_RALT, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT
    ),
	
	[FN1]=LAYOUT(
        KC_GRV, KC_1,  KC_2,  KC_3,   KC_4,   KC_5,  KC_6,  KC_7,    KC_8,   KC_9,    KC_0,    KC_DEL,
        KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6, ____,  KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____,  ____,    KC_INS, KC_HOME, KC_PGUP, ____,
        ____,   ____,  ____,  ____,   ____,   ____,  ____,  ____,    ____,   KC_END,  KC_PGDN, ____
    ),
	
	[FN2]=LAYOUT(
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____
    ),
	
	[FN3]=LAYOUT(
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____
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
