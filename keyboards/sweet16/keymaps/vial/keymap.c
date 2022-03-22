#include QMK_KEYBOARD_H

#define LAYOUT 0
#define FN1 1
#define FN2 2
#define FN3	3

#define ____ KC_TRNS

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYOUT]=LAYOUT_ortho_4x4(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,  KC_ENT,      KC_DEL, KC_HOME, KC_PGUP,  
        KC_CAPS,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,  				 
        KC_LSFT,   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_SLSH, KC_RSFT,              KC_UP, 		 
        KC_LCTL,   KC_LALT,                KC_SPC,             MO(1),           KC_RGUI,   KC_LEFT, KC_DOWN,  KC_RGHT  
    ),
	
	[FN1]=LAYOUT_ortho_4x4(
        KC_ESC, KC_1, KC_2, KC_3, KC_GRV, ____, ____, ____, ____, KC_LBRC, KC_RBRC,  ____,   KC_BSPC, ____, ____,  
        ____,  KC_4, KC_5, KC_6, ____, ____, ____, ____, ____, ____, KC_QUOT, ____,  				 
        ____,   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ____, KC_DOT, KC_BSLS,      ____,          ____, 		 
        ____,   ____,                ____,             ____,               ____,         ____, ____,  ____ 
    ),
	
	[FN2]=LAYOUT_ortho_4x4(
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  ____, ____, ____, ____,  
        ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  				 
        ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____,      ____,       ____, 		 
        ____,   ____,                ____,             ____,               ____, ____, ____,  ____ 
    ),
	
	[FN3]=LAYOUT_ortho_4x4(
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  ____, ____, ____, ____,  
        ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,  				 
        ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____,      ____,       ____, 		 
        ____,   ____,                ____,             ____,               ____, ____, ____,  ____ 
    )
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
