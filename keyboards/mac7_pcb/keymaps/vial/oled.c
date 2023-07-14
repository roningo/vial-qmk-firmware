#pragma once

#include "progmem.h"
#include "animation.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 270 degrees if offhand
}

void render_logo(uint8_t frame){
	if (frame >= 10) {
		frame = 10;
		}
    oled_write_raw_P(kuco[frame], sizeof(kuco[frame]));
}

void show(void){
// Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Main"), false);
            break;
        case 1:
            oled_write_P(PSTR(" -1-"), false);
            break;
        case 2:
            oled_write_P(PSTR(" -2-"), false);
            break;
		case 3:
            oled_write_P(PSTR(" -3-"), false);
            break;
        default:
            break;
    }
}

void oled_task_user(void) {
	
	oled_set_cursor(3,0);
	show();

	oled_set_cursor(12,0);
	render_logo((timer_read() / 120) % 20);
	
	

	
}