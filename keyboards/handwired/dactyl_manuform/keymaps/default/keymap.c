#include "print.h"
#include "quantum.h"
#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_german.h"
#include "action.h"
#include "users/nebu/nebu.h"

extern keymap_config_t keymap_config;

#define BASE 0 // default layer
#define RALGR_LHOLD 1 // When pressing right ALGR, unmap left not to mask cursors
#define FX 2 // for F-keys only
#define LHASH 3
#define RHASH 4

#define ____ KC_TRNS
#define NB_D ALGR_T(KC_D)
#define NB_F RGUI_T(KC_F)
#define NB_J RGUI_T(KC_J)
#define NB_K LT(RALGR_LHOLD, KC_K)
#define NB_AE SFT_T(DE_AE)
#define NB_A TD(A_CTL) // LT(RHASH, KC_A)
#define NB_OE TD(OE_CTL) // LT(LHASH, DE_OE)

//static uint32_t last_layer_state = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( \
	LT(FX, KC_TILD),   KC_1,   KC_2,      KC_3,   KC_4, KC_5,   KC_6,                        KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   LT(FX, DE_ACUT),       KC_PAUSE, \
	       KC_PSCR,  KC_ESC,  KC_Q,      KC_W,   KC_E, KC_R,   KC_T,                         KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,         DE_PLUS, \
	       KC_UP,     KC_LSFT, NB_A, KC_S,   NB_D, NB_F,   KC_G,                             KC_H,    NB_J,   NB_K,    KC_L,   NB_OE,     NB_AE,    DE_HASH, \
	       KC_DOWN,   DE_HASH,  KC_Z,      KC_X,   KC_C, KC_V,   KC_B,                       KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSHIFT,   KC_SLCK, \
	                                      KC_LEFT,   KC_RIGHT,                                     KC_PGUP,    KC_PGDOWN,                  \
	                                            KC_SPC, KC_RCTL,                          KC_RCTL, KC_SPC,                        \
	                                                    KC_ENTER, KC_BSPC,     KC_BSPC,   KC_ENTER,                              \
	                                                    KC_TAB,  KC_LALT,      KC_LALT,  KC_TAB                               \
),
[RALGR_LHOLD] = LAYOUT( \
	RALT(KC_TILD),  RALT(KC_1),    RALT(KC_2), RALT(KC_3),   RALT(KC_4), RALT(KC_5),   RALT(KC_6),                             KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   KC_2,   KC_PAUSE, \
	RALT(KC_PSCR),  RALT(KC_ESC),  RALT(KC_Q), RALT(KC_W),   RALT(KC_E), RALT(KC_R),   RALT(KC_T),                             KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,  DE_PLUS, \
	RALT(KC_UP),    RALT(KC_LSFT), RALT(KC_A), RALT(KC_S),   RALT(KC_D), RALT(KC_F),   RALT(KC_G),                             KC_H,    NB_J,   NB_K,    KC_L,   DE_OE,     DE_AE,  DE_HASH, \
	RALT(KC_DOWN),  RALT(KC_HASH), RALT(KC_Z), RALT(KC_X),   RALT(KC_C), RALT(KC_V),   RALT(KC_B),                             KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_9,   KC_SLCK, \
	                     RALT(KC_LEFT),   RALT(KC_RIGHT),                                                                                          KC_PGUP,    KC_PGDOWN,                  \
	                             RALT(KC_SPC), KC_RCTL,                                                                     KC_RCTL, KC_SPC,                        \
	                                           KC_ENTER, KC_BSPC,                                                  KC_BSPC,   KC_ENTER,                              \
	                                           KC_TAB,  KC_LALT,                                                 KC_LALT,  KC_TAB                               \
),
[FX] = LAYOUT( \
	____,   KC_F1,   KC_F2,      KC_F3,   KC_F4, KC_F5,   KC_F6,                             KC_F7,    KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12, ____, \
	____,  ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,      ____,         ____, \
	____,     ____, ____, ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,     ____,    ____, \
	____,   ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____, ____, ____,   ____,   ____, \
	                               ____,   ____,                                                     ____,    ____,                  \
	                                     ____, ____,                          ____, ____,                        \
	                                             ____, ____,       ____,   ____,                              \
	                                             ____,  ____,      ____,  ____                               \
),
[LHASH] = LAYOUT( \
	____,   ____,   ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,   ____, ____, \
	____,  ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,      ____,         ____, \
	____,     ____, ____, ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,     ____,    ____, \
	____,   ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____, ____, ____,   ____,   ____, \
	                               ____,   ____,                                                     ____,    ____,                  \
	                                     ____, ____,                          ____, ____,                        \
	                                             ____, ____,       ____,   ____,                              \
	                                             ____,  ____,      ____,  ____                               \
),
[RHASH] = LAYOUT( \
	____,   ____,   ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,   ____, ____, \
	____,  ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,      ____,         ____, \
	____,     ____, ____, ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   KC_NO,     ____,    ____, \
	____,   ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____, ____, ____,   ____,   ____, \
	                               ____,   ____,                                                     ____,    ____,                  \
	                                     ____, ____,                          ____, ____,                        \
	                                             ____, ____,       ____,   ____,                              \
	                                             ____,  ____,      ____,  ____                               \
),
};

/*void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}*/


/*
uint32_t layer_state_set_user(uint32_t state) {
	print("layer switch\n");
	switch (biton32(state)) {
		case BASE:
			switch(biton32(last_layer_state)) {
				case RHASH:
					print("unreg hash\n");
					unregister_code(KC_RSFT);
					break;
				case LHASH:
					print("unreg hash\n");
					unregister_code(KC_RSFT);
					break;
				default: break;
			}
			last_layer_state = state;
			break;
		case RHASH:
			print("reg hash\n");
			register_code(KC_RSFT);
			last_layer_state = state;
			break;
		case LHASH:
			print("reg hash\n");
			register_code(KC_RSFT);
			last_layer_state = state;
			break;
		default: break;
	}
	return state;
}
*/
