#include QMK_KEYBOARD_H

#define LAYOUT 0
#define FN1 1
#define FN2 2

static uint16_t oled_timer = 0;

bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYOUT]=LAYOUT_ortho_4x4(
        KC_ESC,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,  KC_I,    KC_O,    KC_P,      KC_LBRC,  KC_BSPC,
        KC_TAB,  KC_A,    KC_S,   KC_D,    KC_F,    KC_G,    KC_H,     KC_J,  KC_K,    KC_L,    KC_SCLN,   KC_ENT,
        KC_LCTL, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,     KC_M,  KC_COMM, KC_SLSH, KC_RSFT,            KC_UP,
        KC_LALT, MO(FN1), KC_SPC, MO(FN2),                                                                 KC_LEFT, KC_DOWN, KC_RIGHT  
    ),
	
	[FN1]=LAYOUT_ortho_4x4(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_PSCR,
        KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS, 
        KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT,  KC_TRNS, KC_RSFT,          KC_VOLU,
        KC_LALT, KC_TRNS, KC_SPC,  KC_MUTE,                                                                KC_MPRV, KC_VOLD, KC_MNXT 
    ),
	
	[FN2]=LAYOUT_ortho_4x4(
        KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,  KC_INS,  KC_HOME, KC_PGUP, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,          RGB_SAI, 
        KC_LALT, KC_CAPS, KC_MPLY, KC_TRNS,                                                                RGB_TOG, RGB_HUI, RGB_MOD
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


