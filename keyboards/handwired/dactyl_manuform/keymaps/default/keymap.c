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
	       KC_UP,     KC_LSFT, CS_A,     NB_S,   NB_D, NB_F,   KC_G,                             KC_H,    NB_J,   NB_K,    NB_L,   CS_OE,     NB_AE,    DE_HASH, \
	       KC_DOWN,   DE_HASH,  KC_Z,      KC_X,   KC_C, KC_V,   KC_B,                       KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSHIFT,   KC_SLCK, \
	                                      KC_LEFT,   KC_RIGHT,                                     KC_PGUP,    KC_PGDOWN,                  \
	                                            KC_SPC, KC_RCTL,                          KC_RCTL, KC_SPC,                        \
	                                                    KC_ENTER, KC_BSPC,     KC_BSPC,   KC_ENTER,                              \
	                                                    KC_TAB,  KC_LALT,      KC_LALT,  KC_TAB                               \
),
[RALGR_LHOLD] = LAYOUT( \
	RALT(KC_TILD),  RALT(KC_1),    RALT(KC_2), RALT(KC_3),   RALT(KC_4), RALT(KC_5),   RALT(KC_6),                             KC_7,    KC_8,   KC_9,    KC_0,   KC_MINS,   KC_2,   KC_PAUSE, \
	RALT(KC_PSCR),  RALT(KC_ESC),  RALT(KC_Q), RALT(KC_W),   RALT(KC_E), RALT(KC_R),   RALT(KC_T),                             KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,      DE_UE,  DE_PLUS, \
	RALT(KC_UP),    RALT(KC_LSFT), RALT(KC_A), RALT(KC_S),   RALT(KC_D), RALT(KC_F),   RALT(KC_G),                             KC_H,    NB_J,   NB_K,    KC_L,   CS_OE,     DE_AE,  DE_HASH, \
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




bool oe_hash = false;
bool oe_pressed = false;
uint16_t oe_masking_code = 0;
uint16_t oe_timer = 0;

bool a_hash = false;
bool a_pressed = false;
uint16_t a_masking_code = 0;
uint16_t a_timer = 0;

#define STOP false
#define CONT true

bool process_a(uint16_t keycode, keyrecord_t *record) {
	uint16_t elapsed = timer_elapsed(a_timer);
	if(keycode == CS_A) {
		if(record->event.pressed) {
			xprintf("pressed CS_A, a_hash: %d, a_pressed: %d, a_masking_code: %d\n\t", a_hash, a_pressed, a_masking_code);
			if(oe_pressed) { // be a normal key in case oe is mod
				print(" / but oe is hash already, registering KC_A => STOP\n");
				register_code(KC_A);
				return STOP;
			}
			// no other mod-hold yet
			print(" / and saved timer => STOP\n");
			a_timer = timer_read();
			a_pressed = true;
			return STOP;
		} else { // released
			xprintf("release CS_A, a_hash: %d, a_pressed: %d, a_masking_code: %d\n\t", a_hash, a_pressed, a_masking_code);
			if(oe_hash) {
				print(" / but oe is hash, release normally => STOP\n");
				unregister_code(KC_A);
				return STOP;
			}
			if(a_hash) {
				print(" / and unregister DE_HASH");
				unregister_code(DE_HASH);
				a_hash = false;
			}
			if(elapsed < TAPPING_TERM) {
				print(" / and tap KC_A");
				register_code(KC_A);
				unregister_code(KC_A);
			}
			print(" / and unpress => STOP\n");
			a_pressed = false;
			return STOP;
		}
	} else {
		if(record->event.pressed) {
			xprintf("pressed %d, a_hash: %d, a_pressed: %d, a_masking_code: %d\n\t", keycode, a_hash, a_pressed, a_masking_code);
			if(a_pressed && !a_masking_code && elapsed >= TAPPING_TERM) {
				print(" / and registering DE_HASH => CONT\n");
				a_hash = true;
				register_code(DE_HASH);
				return CONT;
			} else if(a_pressed && a_masking_code == 0) {
				print(" / and masking key => STOP\n");
				a_masking_code = keycode;
				return STOP;
			} else if(a_pressed && a_masking_code != keycode) {
				print(" / and 2nd tap after mask, registering DE_HASH and masked => CONT\n");
				register_code(DE_HASH);
				a_hash = true;
				register_code(a_masking_code);
				a_masking_code = 0;
			} else {
				print(" / is regular press\n");
				return CONT;
			}
		} else { // released
			xprintf("released %d, a_hash: %d, a_pressed: %d, a_masking_code: %d\n\t", keycode, a_hash, a_pressed, a_masking_code);
			if(a_pressed && a_masking_code == 0 && elapsed >= TAPPING_TERM) {
				print(" / had hold while tapping ... confused => CONT\n");
				register_code(DE_HASH);
				a_hash = true;
				return CONT;
			} else if(a_pressed && a_masking_code == keycode) {
				print(" / released masked key, pressing DE_HASH and key => CONT\n");
				register_code(DE_HASH);
				a_hash = true;
				register_code(keycode);
				a_masking_code = 0;
				return CONT;
			} else if(!a_pressed && a_masking_code != 0) {
				print(" / unmasking and => CONT\n");
				register_code(keycode);
				return CONT;
			} else {
				print(" / regular release => CONT\n");
				return CONT;
			}
		}
	}
	return CONT;
}

void scan_a(void) {
	if(!a_hash && a_pressed && timer_elapsed(a_timer) >= TAPPING_TERM) {
		xprintf("scan found a has hold time, registering DE_HASH, a_hash: %d, a_pressed: %d, a_masking_code: %d\n", a_hash, a_pressed, a_masking_code);
		register_code(DE_HASH);
		a_hash = true;
	}
}

bool process_oe(uint16_t keycode, keyrecord_t *record) {
	uint16_t elapsed = timer_elapsed(oe_timer);
	if(keycode == CS_OE) {
		if(record->event.pressed) {
			xprintf("pressed CS_OE, oe_hash: %d, oe_pressed: %d, oe_masking_code: %d\n\t", oe_hash, oe_pressed, oe_masking_code);
			if(a_hash) { // be a normal key in case a is mod
				print(" / but a is hash already, registering DE_OE => STOP\n");
				register_code(DE_OE);
				return STOP;
			}
			// no other mod-hold yet
			print(" / and saved timer => STOP\n");
			oe_timer = timer_read();
			oe_pressed = true;
			return STOP;
		} else { // released
			xprintf("release CS_OE, oe_hash: %d, oe_pressed: %d, oe_masking_code: %d\n\t", oe_hash, oe_pressed, oe_masking_code);
			if(a_hash) { // be a normal key in case a is mod
				print(" / but a is hash, unregistering DE_OE => STOP\n");
				unregister_code(DE_OE);
				return STOP;
			}
			if(oe_hash) {
				print(" / and unregister DE_HASH");
				unregister_code(DE_HASH);
				oe_hash = false;
			}
			if(elapsed < TAPPING_TERM) {
				print(" / and tap DE_OE");
				register_code(DE_OE);
				unregister_code(DE_OE);
			}
			print(" / and unpress => STOP\n");
			oe_pressed = false;
			return STOP;
		}
	} else {
		if(record->event.pressed) {
			xprintf("pressed %d, oe_hash: %d, oe_pressed: %d, oe_masking_code: %d\n\t", keycode, oe_hash, oe_pressed, oe_masking_code);
			if(oe_pressed && !oe_masking_code && elapsed >= TAPPING_TERM) {
				print(" / and registering DE_HASH => CONT\n");
				oe_hash = true;
				register_code(DE_HASH);
				return CONT;
			} else if(oe_pressed && oe_masking_code == 0) {
				print(" / and masking key => STOP\n");
				oe_masking_code = keycode;
				return STOP;
			} else if(oe_pressed && oe_masking_code != keycode) {
				print(" / and 2nd tap after mask, registering DE_HASH and masked => CONT\n");
				register_code(DE_HASH);
				oe_hash = true;
				register_code(oe_masking_code);
				oe_masking_code = 0;
			} else {
				print(" / is regular press\n");
				return CONT;
			}
		} else { // released
			xprintf("released %d, oe_hash: %d, oe_pressed: %d, oe_masking_code: %d\n\t", keycode, oe_hash, oe_pressed, oe_masking_code);
			if(oe_pressed && oe_masking_code == 0 && elapsed >= TAPPING_TERM) {
				print(" / had hold while tapping ... confused => CONT\n");
				register_code(DE_HASH);
				oe_hash = true;
				return CONT;
			} else if(oe_pressed && oe_masking_code == keycode) {
				print(" / released masked key, pressing DE_HASH and key => CONT\n");
				register_code(DE_HASH);
				oe_hash = true;
				register_code(keycode);
				oe_masking_code = 0;
				return CONT;
			} else if(!oe_pressed && oe_masking_code != 0) {
				print(" / unmasking and => CONT\n");
				register_code(keycode);
				return CONT;
			} else {
				print(" / regular release => CONT\n");
				return CONT;
			}
		}
	}
	return CONT;
}

void scan_oe(void) {
	if(!oe_hash && oe_pressed && timer_elapsed(oe_timer) >= TAPPING_TERM) {
		xprintf("scan found a has hold time, registering DE_HASH, oe_hash: %d, oe_pressed: %d, oe_masking_code: %d\n", oe_hash, oe_pressed, oe_masking_code);
		register_code(DE_HASH);
		oe_hash = true;
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if(process_a(keycode, record) == CONT) {
		return process_oe(keycode, record);
	} else {
		return STOP;
	}
}

void matrix_scan_user(void) {
	scan_a();
	scan_oe();
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
