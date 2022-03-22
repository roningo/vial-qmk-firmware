#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED // OU
#define MANUFACTURER    LeAK
#define PRODUCT         Yang30

/* key matrix size */
#define MATRIX_ROWS 3	
#define MATRIX_COLS 10

/* number of backlight levels */
#define BACKLIGHT_LEVELS 10

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
