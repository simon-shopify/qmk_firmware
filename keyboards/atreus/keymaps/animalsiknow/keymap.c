#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap
// matrix below. Layer names don't all need to be of the same length, obviously,
// and you can also skip them entirely and just use numbers.
#define QWERTY 0
#define RAISE 1
#define LOWER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = KEYMAP(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   ,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_RALT, KC_LCTL, KC_SPC,  MO(RAISE), MO(LOWER), KC_QUOT, KC_ENT),
/*
 *   !      @      {     }    "        ||       _     7     8     9    *
 *   #      $      (     )    '        ||       -     4     5     6    +
 *   %      ^      [     ]    ~        ||       &     1     2     3    \
 *   |      `    super shift bksp ctrl || alt space raise lower   0    =
 */
[RAISE] = KEYMAP(
  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, S(KC_QUOT),                S(KC_MINS), KC_7,   KC_8,   KC_9, KC_ASTR ,
  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_QUOT,                   KC_MINS, KC_4,      KC_5,   KC_6, KC_PLUS ,
  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                   KC_AMPR, KC_1,      KC_2,   KC_3, KC_BSLS ,
  KC_PIPE, KC_GRV,  KC_LGUI, KC_LSFT, KC_BSPC, KC_RALT, KC_LCTL, KC_SPC,  MO(RAISE), MO(LOWER), KC_0, KC_EQL),
/*
 *              up           ”         ||     pgup   F7    F8    F9     F10
 *        left down  right   “         ||     pgdn   F4    F5    F6     F11
 *                                     ||     play   F1    F2    F3     F12
 * volup voldn super shift bksp  ctrl  || alt space raise lower scroll reset
 */
[LOWER] = KEYMAP(
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_PGUP, KC_F7,     KC_F8,     KC_F9, KC_F10,
  KC_NO,   KC_NO,   UC(L'“'), UC(L'”'), KC_NO,                     KC_PGDN, KC_F4,     KC_F5,     KC_F6, KC_F11,
  KC_NO,   KC_NO,   KC_NO,    KC_NO,    RESET,                     KC_MPLY, KC_F1,     KC_F2,     KC_F3, KC_F12,
  KC_VOLD, KC_VOLU, KC_LGUI,  KC_LSFT,  KC_BSPC, KC_RALT, KC_LCTL, KC_SPC,  MO(RAISE), MO(LOWER), KC_NO, RESET)
};

const uint16_t PROGMEM fn_actions[] = {};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
}
