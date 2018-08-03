#include "print.h"
#include "quantum.h"
#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_german.h"
#include "action.h"
#include "users/nebu/nebu.h"
#include "timer.h"

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
//#define NB_A LT(RHASH, KC_A)
//#define NB_OE LT(LHASH, DE_OE)
#define NB_A MT(MOD_LGUI, KC_A)
#define NB_OE MT(MOD_LGUI, DE_OE)
#define NB_S SFT_T(KC_S)
#define NB_L SFT_T(KC_L)

//static uint32_t last_layer_state = 0;

enum my_keycodes {
	CS_A = SAFE_RANGE,
	CS_OE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( \
	LT(FX, KC_TILD),   KC_1,   KC_2,      KC_3,   KC_4, KC_5,   KC_6,                        KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   DE_ACUT,       LT(FX, KC_PAUSE), \
	       KC_PSCR,   KC_ESC,  KC_Q,      KC_W,   KC_E, KC_R,   KC_T,                         KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,         DE_PLUS, \
	       KC_UP,     KC_LSFT, CS_A,     NB_S,   NB_D, NB_F,   KC_G,                             KC_H,    NB_J,   NB_K,    NB_L,   NB_OE,     NB_AE,    DE_HASH, \
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
	                             KC_SPC, KC_RCTL,                                                                     KC_RCTL, KC_SPC,                        \
	                                           KC_ENTER, KC_BSPC,                                                  KC_BSPC,   KC_ENTER,                              \
	                                           KC_TAB,  KC_LALT,                                                 KC_LALT,  KC_TAB                                 \
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
	____,     ____, ____, ____,   ____, ____,   ____,                             ____,    ____,   ____,    ____,   ____,     ____,    ____, \
	____,   ____,  ____,      ____,   ____, ____,   ____,                             ____,    ____,   ____, ____, ____,   ____,   ____, \
	                               ____,   ____,                                                     ____,    ____,                  \
	                                     ____, ____,                          ____, ____,                        \
	                                             ____, ____,       ____,   ____,                              \
	                                             ____,  ____,      ____,  ____                               \
),
};


static uint16_t a_timer;
bool a_pressed = false;
bool a_registered = false;
bool masked = false;
uint16_t masked_keycode = 0;
#define STOP false
#define CONT true
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case CS_A:
			if(record->event.pressed) {
				print("pressed CS_A\n");
				a_pressed = true;
				a_timer = timer_read();
				return STOP;
			} else { // released
				print("released CS_A ");
				a_pressed = false;
				if(timer_elapsed(a_timer) <= TAPPING_TERM) { // regular tap, no hold
					print("below TAPPING_TERM ");
					register_code(KC_A);
					unregister_code(KC_A);
				}
				print("unregistering DE_HASH\n");
				unregister_code(DE_HASH); // unregisters too often, probably doesn’t matter?
				a_registered = false;
				return STOP;
			}
			break;
		default:
			if(record->event.pressed) {
				xprintf("pressed %d ", keycode);
				if(masked) {
					if(a_pressed) {
						register_code(DE_HASH);
						a_registered = true;
						register_code(masked_keycode);
						masked = false;
						masked_keycode = 0;
					} else {
						register_code(masked_keycode);
						masked = false;
						masked_keycode = 0;
					}
				}
				if(a_pressed && timer_elapsed(a_timer) <= TAPPING_TERM) {
					print(" masking\n");
					masked = true;
					masked_keycode = keycode;
					return STOP;
				} else if(a_pressed && timer_elapsed(a_timer) > TAPPING_TERM) {
					if(masked) {
						register_code(masked_keycode);
						masked = false;
						masked_keycode = 0;
					}
					print(" with DE_HASH\n");
					register_code(DE_HASH);
					a_registered = true;
					return CONT;
				} else { // regular press
					print(" regular\n");
					return CONT;
				}
			} else { // release
				xprintf("released %d ", keycode);
				if(a_pressed && timer_elapsed(a_timer) > TAPPING_TERM) {
					print(" and registering DE_HASH ");
					register_code(DE_HASH);
					a_registered = true;
				}

				if(masked) {
					xprintf(" and had masked %d ", keycode);
					register_code(masked_keycode);
					masked = false;
					masked_keycode = 0;
				}
				print("\n");
				return CONT;
			}
			break;
	}
	return true;
}

void matrix_scan_user(void) {
	if(a_pressed && !a_registered && timer_elapsed(a_timer) > TAPPING_TERM) {
		print("matrixscan, registering DE_HASH\n");
		a_registered = true;
		register_code(DE_HASH);
	}
}

/*void persistent_default_layer_set(uint16_t default_layer) {
  ueconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}*/


/*uint32_t layer_state_set_user(uint32_t state) {
	switch(biton32(state)) {
		case BASE:
			layerkc1 = KC_NO;
			hasregistered = false;
			break;
		case RHASH:
		case LHASH:
			layerkc1 = DE_HASH;
			hasregistered = false;
			break;
	}
	return state;
}

void matrix_scan_user(void) {
	if(!hasregistered) {
		register_code(layerkc1);
		hasregistered=true;
	}
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
