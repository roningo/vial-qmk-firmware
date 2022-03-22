#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;
int current_wpm = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 270 degrees if offhand
}

void render_logo(uint8_t frame){
    oled_write_raw_P(note[frame], sizeof(note[frame]));
}

void show(void){
// Host Keyboard Layer Status
    oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case LAYOUT:
            oled_write_P(PSTR(" Main\n"), false);
            break;
        case FN1:
            oled_write_P(PSTR(" FN1\n"), false);
            break;
        case FN2:
            oled_write_P(PSTR(" FN2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_animation(uint8_t frame) {
	current_wpm = get_current_wpm();
	led_t led_state = host_keyboard_led_state();
	if(led_state.caps_lock) {
		oled_write_raw_P(bark[frame], sizeof(bark[frame]));
    } else if(isSneaking) {
        oled_write_raw_P(sneak[frame], sizeof(sneak[frame]));
    } else if(current_wpm <= 10) {
		oled_write_raw_P(sit[frame], sizeof(sit[frame]));
    } else if(current_wpm <= 50) {
		oled_write_raw_P(walk[frame], sizeof(walk[frame]));
    } else {
		oled_write_raw_P(run[frame], sizeof(run[frame]));
    }	
}

void oled_task_user(void) {
	render_logo((timer_read() / 240) % 2);
	oled_set_cursor(0,7);
    show();
	oled_set_cursor(0,13);
	render_animation((timer_read() / 120) % 2);
}