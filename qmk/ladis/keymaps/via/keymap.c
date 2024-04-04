//#include "ladis.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
		KC_WWW_BACK, KC_UP, KC_WWW_FORWARD, \
		KC_LEFT, KC_DOWN, KC_RIGHT, \
		MO(1), KC_WWW_REFRESH, KC_F16, \
		LCTL(KC_LGUI), KC_MUTE),

[1] = LAYOUT(
		KC_F17, KC_F18, KC_F19, \
		KC_F20, KC_F21, KC_F22, \
		KC_NO, KC_F23, KC_F24, \
		KC_SYSTEM_SLEEP, KC_MUTE),

[2] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS ),

[3] = LAYOUT(
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS , KC_TRNS , \
		KC_TRNS , KC_TRNS ),

};

 #ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_BSPC, KC_DEL),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
};
#endif

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
