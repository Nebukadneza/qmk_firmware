#include "print.h"
#include "quantum.h"
#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_german.h"
#include "action.h"
#include "timer.h"
#include "process_keycode/process_tap_dance.h"

extern keymap_config_t keymap_config;

#define BASE 0 // default layer
#define RALGR_LHOLD 1 // When pressing right ALGR, unmap left not to mask cursors
#define FX 2 // for F-keys only
#define LHASH 3
#define RHASH 4

#define ____ KC_TRNS
#define NB_D ALGR_T(KC_D)
#define NB_F LGUI_T(KC_F)
#define NB_J LGUI_T(KC_J)
#define NB_K LT(RALGR_LHOLD, KC_K)
#define NB_AE SFT_T(DE_AE)
//#define NB_A LT(RHASH, KC_A)
//#define NB_OE LT(LHASH, DE_OE)
#define NB_A MT(MOD_RGUI, KC_A)
#define NB_OE MT(MOD_RGUI, DE_OE)
#define NB_S SFT_T(KC_S)
#define NB_L SFT_T(KC_L)

enum {
  TD_Z = 0,
  TD_SLSH,
  TD_O,
  TD_W
};
bool shiftheld=false;
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_Z);
	} else {
		if(!shiftheld) {
			register_code(KC_RSHIFT);
			register_code(KC_LSHIFT);
			unregister_code(KC_RSHIFT);
			unregister_code(KC_LSHIFT);
			shiftheld=true;
		} else {
			register_code(KC_RSHIFT);
			register_code(KC_LSHIFT);
			unregister_code(KC_RSHIFT);
			unregister_code(KC_LSHIFT);
			shiftheld=false;

		}
	}
}
void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_Z);
	}
}
void dance_slsh_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_SLSH);
	} else {
		if(!shiftheld) {
			register_code(KC_RSHIFT);
			register_code(KC_LSHIFT);
			unregister_code(KC_RSHIFT);
			unregister_code(KC_LSHIFT);
			shiftheld=true;
		} else {
			register_code(KC_RSHIFT);
			register_code(KC_LSHIFT);
			unregister_code(KC_RSHIFT);
			unregister_code(KC_LSHIFT);
			shiftheld=false;

		}
	}
}
void dance_slsh_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_SLSH);
	}
}

void dance_o_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_O);
	} else {
		register_code(KC_ESC);
		unregister_code(KC_ESC);
	}
}
void dance_o_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_O);
	}
}
void dance_w_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_W);
	} else {
		register_code(KC_ESC);
		unregister_code(KC_ESC);
	}
}
void dance_w_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_W);
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_Z] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_z_finished, dance_z_reset, 100),
	[TD_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_slsh_finished, dance_slsh_reset, 100),
	[TD_O] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_o_finished, dance_o_reset, 100),
	[TD_W] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_w_finished, dance_w_reset, 100)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT( \
	LT(FX, KC_TILD),  KC_1,    KC_2,     KC_3,     KC_4, KC_5,   KC_6,                        KC_7,    KC_8,   KC_9,    KC_0,     KC_MINS,     DE_ACUT,       LT(FX, KC_PAUSE), \
	       KC_PSCR,   KC_ESC,  KC_Q,     TD(TD_W), KC_E, KC_R,   KC_T,                        KC_Y,    KC_U,   KC_I,    TD(TD_O), KC_P,        DE_UE,                DE_PLUS, \
	       KC_UP,     KC_LSFT, NB_A,     NB_S,     NB_D, NB_F,   KC_G,                        KC_H,    NB_J,   NB_K,    NB_L,     NB_OE,       NB_AE,                DE_HASH, \
	       KC_DOWN,   DE_HASH, TD(TD_Z), KC_X,     KC_C, KC_V,   KC_B,                        KC_N,    KC_M,   KC_COMM, KC_DOT,   TD(TD_SLSH), KC_RSHIFT,            KC_SLCK, \
	                                     KC_LEFT,  KC_RIGHT,                                                   KC_PGUP, KC_PGDOWN,                  \
	                                               KC_SPC, KC_RCTL,                           KC_RCTL, KC_SPC,                        \
	                                                       KC_ENTER, KC_BSPC,      KC_BSPC,   KC_ENTER,                              \
	                                                       KC_TAB,  KC_LALT,        KC_LALT,  KC_TAB                               \
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


