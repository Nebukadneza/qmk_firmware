#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_german.h"

extern keymap_config_t keymap_config;

#define BASE 0 // default layer
#define RALGR_LHOLD 1 // When pressing right ALGR, unmap left not to mask cursors

#define NB_D ALGR_T(KC_D)
#define NB_F RGUI_T(KC_F)
#define NB_J RGUI_T(KC_J)
#define NB_K LT(RALGR_LHOLD, KC_K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( \
	KC_TILD, KC_1, KC_2, KC_3,   KC_4, KC_5,   KC_6,                             KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   KC_NO,      KC_PAUSE, \
	DEBUG,  KC_ESC, KC_Q, KC_W,   KC_E, KC_R,   KC_T,                             KC_Z,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,     DE_PLUS, \
	KC_UP,  KC_LSFT, KC_A, KC_S,   NB_D, NB_F,   KC_G,                             KC_H,    NB_J,   NB_K,    KC_L,   DE_OE,     DE_AE,    DE_HASH, \
	KC_DOWN, KC_NO, KC_Y, KC_X,   KC_C, KC_V,   KC_B,                             KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSHIFT,   KC_NO, \
	                     KC_LEFT,   KC_RIGHT,                                                            KC_PGUP,    KC_PGDOWN,                  \
	                                   KC_SPC, KC_RCTL,                          KC_RCTL, KC_SPC,                        \
	                                           KC_ENTER, KC_BSPC,       KC_BSPC,   KC_ENTER,                              \
	                                           KC_TAB,  KC_LALT,      KC_LALT,  KC_TAB                               \
),
[RALGR_LHOLD] = LAYOUT( \
	RALT(KC_TILD), RALT(KC_1), RALT(KC_2), RALT(KC_3),   RALT(KC_4), RALT(KC_5),   RALT(KC_6),                             KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   KC_2,   KC_PAUSE, \
	RALT(KC_TAB),  RALT(KC_5), RALT(KC_Q), RALT(KC_W),   RALT(KC_E), RALT(KC_R),   RALT(KC_T),                             KC_Z,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,  KC_6, \
	RALT(KC_ESC),  RALT(KC_6), RALT(KC_A), RALT(KC_S),   RALT(KC_D), RALT(KC_F),   RALT(KC_G),                             KC_H,    NB_J,   NB_K,    KC_L,   DE_OE,     DE_AE,  KC_7, \
	RALT(KC_LSFT), RALT(KC_7), RALT(KC_Y), RALT(KC_X),   RALT(KC_C), RALT(KC_V),   RALT(KC_B),                             KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_9,   KC_RSHIFT, \
	                     RALT(KC_5),   RALT(KC_4),                                                                                          KC_2,    KC_5,                  \
	                             RALT(KC_SPC), KC_RCTL,                                                                     KC_RCTL, KC_SPC,                        \
	                                           KC_ENTER, KC_BSPC,                                                  KC_BSPC,   KC_ENTER,                              \
	                                           KC_TAB,  KC_LALT,                                                 KC_LALT,  KC_TAB                               \
)
};

/*void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}*/

