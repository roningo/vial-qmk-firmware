#include "rev1.h"

#ifdef SSD1306OLED
void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    led_set_user(usb_led);
}
#endif

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4}},
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}, {6,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}, {6,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}, {6,7}},
    /* Right hand, matrix positions */
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}},
    {{0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2}},
    {{0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}, {6,3}},
};
#endif
