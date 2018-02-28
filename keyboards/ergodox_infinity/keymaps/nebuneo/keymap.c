#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"

// define layers
#define BASE 0 // default layer

// define custom macros
#define L_KC_CAPS F(M_KC_CAPS_L)

// timers for tap/hold
static uint16_t m_kc_caps_l_timer;

enum functions {
	M_KC_CAPS_L
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TILD,        KC_1,         KC_2,   KC_3,   KC_4,       KC_5,   KC_TAB,
        KC_NO,        KC_Q,         KC_W,   KC_E,   KC_R,         KC_T,   KC_ENTER,
        KC_ESC,        KC_A,         KC_S,   KC_D,   L_KC_CAPS,   KC_G,
        KC_LSFT,      KC_Z,         KC_X,   KC_C,   KC_V,   KC_B, KC_CAPS,
           KC_NO,KC_NO,KC_NO,KC_NO,KC_LGUI,
                                                        KC_NO, KC_NO,
                                                               KC_NO,
                                               KC_SPC,KC_CAPS,KC_RALT,
        // right hand
             KC_TAB,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_ENTER,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             DE_UE,
                          KC_H,   KC_J,  KC_K,   KC_L,   DE_OE,            DE_AE,
             KC_CAPS,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,   KC_RSHIFT,
                                             KC_RGUI,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,
             KC_NO,KC_NO,
             KC_NO,
             KC_RALT,KC_RCTL, KC_BSPC
    )
};

const uint16_t PROGMEM fn_actions[] = {
	[M_KC_CAPS_L] = ACTION_MACRO_TAP(M_KC_CAPS_L),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	bool tap_not_interrupted = record->tap.count > 0 && !record->tap.interrupted;

	switch(id) {
		case M_KC_CAPS_L:
			if (record->event.pressed) {
				m_kc_caps_l_timer = timer_read();

				if (!tap_not_interrupted) { //set mod
					return MACRO(D(CAPS), END);
				}
			} else {
				if (tap_not_interrupted && timer_elapsed(m_kc_caps_l_timer) < TAPPING_TERM) { // send tap-character
					record->tap.count = 0;
					return MACRO(T(F), END);
				} else { // release mod
					return MACRO(U(CAPS), END);
				}
			}
		break;
	}
return MACRO_NONE;
};

