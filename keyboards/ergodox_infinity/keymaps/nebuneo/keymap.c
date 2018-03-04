#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"

// define layers
#define BASE 0 // default layer
#define FKEY 1 // F1-F12 on top row
#define RALGR_LHOLD 2 // When pressing right ALGR, unmap left not to mask cursors
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TILD,        KC_1,         KC_2,   KC_3,           KC_4,         KC_5,         MO(FKEY),
        KC_TAB,         KC_Q,         KC_W,   KC_E,           KC_R,         KC_T,         KC_TAB,
        KC_ESC,         KC_A,         KC_S,   ALGR_T(KC_D),   RGUI_T(KC_F), KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,           KC_V,         KC_B,         KC_ENTER,
           KC_NO,KC_NO,KC_NO,KC_NO,KC_LGUI,
                                                        KC_DEL,KC_NO,
                                                              KC_NO,
                                               KC_SPC,KC_RCTL,KC_LALT,
        // right hand
             MO(FKEY),      KC_6,            KC_7,          KC_8,           KC_9,   KC_0,             KC_MINS,
             KC_TAB,    KC_Y,            KC_U,          KC_I,           KC_O,   KC_P,             DE_UE,
                          KC_H,            RGUI_T(KC_J),  LT(RALGR_LHOLD,KC_K),   KC_L,   DE_OE,            DE_AE,
             KC_ENTER,    KC_N,            KC_M,          KC_COMM,        KC_DOT, KC_SLSH,          KC_RSHIFT,
                                                              KC_LGUI,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,
             KC_NO,KC_DEL,
             KC_NO,
             KC_LALT,KC_RCTL,KC_BSPC
    ),
[RALGR_LHOLD] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        RALT(KC_TILD),        RALT(KC_1),         RALT(KC_2),   RALT(KC_3),           RALT(KC_4),         RALT(KC_5),         MO(FKEY),
        RALT(KC_TAB),         RALT(KC_Q),         RALT(KC_W),   RALT(KC_E),           RALT(KC_R),         RALT(KC_T),         RALT(KC_TAB),
        RALT(KC_ESC),         RALT(KC_A),         RALT(KC_S),   RALT(KC_D),           RALT(KC_F),         RALT(KC_G),
        RALT(KC_LSFT),        RALT(KC_Z),         RALT(KC_X),   RALT(KC_C),           RALT(KC_V),         RALT(KC_B),         RALT(KC_ENTER),
           KC_NO,KC_NO,KC_NO,KC_NO,KC_LGUI,
                                                        KC_DEL,KC_NO,
                                                              KC_NO,
                                               KC_SPC,KC_RCTL,KC_LALT,
        // right hand
             MO(FKEY),      KC_6,            KC_7,          KC_8,           KC_9,   KC_0,             KC_MINS,
             KC_TAB,    KC_Y,            KC_U,          KC_I,           KC_O,   KC_P,             DE_UE,
                          KC_H,            RGUI_T(KC_J),  LT(RALGR_LHOLD, KC_K),   KC_L,   DE_OE,            DE_AE,
             KC_ENTER,    KC_N,            KC_M,          KC_COMM,        KC_DOT, KC_SLSH,          KC_RSHIFT,
                                                              KC_LGUI,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,
             KC_NO,KC_DEL,
             KC_NO,
             KC_LALT,KC_RCTL,KC_BSPC
    ),
[FKEY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        _______,         KC_F1,        KC_F2,         KC_F3,   KC_F4,           KC_F5,         _______,
        _______,         _______,         _______,   _______,           _______,         _______,         _______,
        _______,         _______,         _______,   _______,   _______, _______,
        _______,        _______,         _______,   _______,           _______,         _______,         _______,
           _______,_______,_______,_______,_______,
                                                        _______,_______,
                                                              _______,
                                               _______,_______,_______,
        // right hand
             _______,      KC_F6,            KC_F7,          KC_F8,           KC_F9,   KC_F10,             KC_F11,
             _______,    _______,            _______,          _______,           _______,   _______,             KC_F12,
                          _______,            _______,  _______,   _______,   _______,            _______,
             _______,    _______,            _______,          _______,        _______, _______,          _______,
                                                              _______,_______,_______,_______,_______,
             _______,_______,
             _______,
             _______,_______,KC_BSPC
    )
};

