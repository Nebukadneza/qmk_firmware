/*
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"
#include "keymap_german.h"
#include "nebu.h"

int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static xtap oetap_state = {
  .is_press_action = true,
  .state = 0
};
static xtap atap_state = {
  .is_press_action = true,
  .state = 0
};

void oe_finished (qk_tap_dance_state_t *state, void *user_data) {
  oetap_state.state = cur_dance(state);
  switch (oetap_state.state) {
    case SINGLE_TAP: register_code(DE_OE); break;
    case SINGLE_HOLD: register_code(DE_HASH); break;
  }
}

void oe_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (oetap_state.state) {
    case SINGLE_TAP: unregister_code(DE_OE); break;
    case SINGLE_HOLD: unregister_code(DE_HASH); break;
  }
  oetap_state.state = 0;
}

void a_finished (qk_tap_dance_state_t *state, void *user_data) {
  atap_state.state = cur_dance(state);
  switch (atap_state.state) {
    case SINGLE_TAP: register_code(DE_A); break;
    case SINGLE_HOLD: register_code(DE_HASH); break;
  }
}

void a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (atap_state.state) {
    case SINGLE_TAP: unregister_code(DE_A); break;
    case SINGLE_HOLD: unregister_code(DE_HASH); break;
  }
  atap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [OE_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, oe_finished, oe_reset, 78),
  [A_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, a_finished, a_reset, 78)
};
*/
