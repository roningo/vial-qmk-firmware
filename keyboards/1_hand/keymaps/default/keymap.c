#include QMK_KEYBOARD_H

#define LAYOUT 0
#define FN1 1
#define FN2 2
#define FN3 3

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYOUT]=KEYMAP(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, 
		KC_LCTL, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_UP, 
		KC_SPC, KC_DOWN),

	[FN1]=KEYMAP(
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, 
		____, ____),

	[FN2]=KEYMAP(
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, 
		____, ____),

	[FN3]=KEYMAP(
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, 
		____, ____)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}