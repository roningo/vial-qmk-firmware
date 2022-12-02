// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _LAYOUT 0
#define FN1 1
#define FN2 2
#define FN3	3

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYOUT] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_BSLS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_GRV,  ____,    KC_BSPC, KC_DEL,   KC_ENT,   KC_SPC,  KC_EQL,  KC_MINS, KC_QUOT, KC_ENT,  KC_RGUI
  ),

  [FN1] = LAYOUT(
    ____,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    ____,   ____, 	 ____,    ____,    ____,    ____,                KC_F12,  ____,    KC_UP,   ____,    ____,    ____,
    ____,   ____, 	 ____,    ____,    ____,    ____,                ____,    KC_LEFT, KC_DOWN, KC_RGHT, ____,    ____,
    ____,   ____, 	 ____,    ____,    ____,    ____,                ____,    ____,    ____,    ____,    ____,    ____,
    ____,   ____, 	 ____,    ____,    ____,    ____,  ____,  ____,  ____,    ____,    ____,    ____,    ____,    ____
  ),

  [FN2] = LAYOUT(
    ____,  ____, ____, ____, ____, ____,               ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____,               ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____,               ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____,               ____, ____, ____, ____, ____, ____,
    ____,  ____, ____, ____, ____, ____, ____,  ____,  ____, ____, ____, ____, ____, ____      
  ),

  [FN3] = LAYOUT(
    ____  ,  ____  , ____  , ____  , ____  , ____  ,                     ____  , ____  , ____  , ____  , ____  , ____   ,
    ____  ,  ____  , ____  , ____  , ____  , ____  ,                     ____  , ____  , ____  , ____  , ____  , ____   ,
    ____  ,  ____  , ____  , ____  , ____  , ____  ,                     ____  , ____  , ____  , ____  , ____  , ____   ,
    ____  ,  ____  , ____  , ____  , ____  , ____  ,                     ____  , ____  , ____  , ____  , ____  , ____   ,
    ____  ,  ____  , ____  , ____  , ____  , ____  , ____  ,  ____  ,  ____  , ____  , ____  , ____  , ____  , ____
  )
};
