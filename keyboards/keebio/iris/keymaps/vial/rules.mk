VIA_ENABLE = yes
VIAL_ENABLE = yes
LTO_ENABLE = yes
VIAL_INSECURE = yes

EXTRAFLAGS        += -flto

MOUSEKEY_ENABLE = yes

RGBLIGHT_ENABLE = yes
SRC += rgb_underglow.c

TAP_DANCE_ENABLE = yes
SRC += tap_dances.c