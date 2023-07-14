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
        KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C, 
        KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C, 
		KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C, 
        KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C,  KC_A, KC_B, KC_C
    ),
	
	[FN1]=LAYOUT(
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____,
        ____, ____, ____,____, ____, ____,____, ____, ____,____, ____, ____
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
