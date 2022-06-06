#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSPC,
   KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                     KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
   KC_ESC,  KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_BSPC,  LOWER,  RAISE,   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT
),

[_LOWER] = LAYOUT_ortho_4x12(
   KC_EXLM, KC_AT,   KC_HASH, KC_LPRN, KC_RPRN, KC_BSLS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DEL,
   KC_DLR,  KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
   KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR,                      KC_TRNS,  KC_TRNS,  KC_BRID,  KC_BRIU,  KC_SLEP,  KC_TRNS,
   KC_ESC,  KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,  KC_TRNS
),

[_RAISE] = LAYOUT_ortho_4x12(
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK,                      KC_0,    KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PLUS, KC_4,    KC_5,    KC_6,    KC_SLSH, KC_DOT,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_MINS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_EQL,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_ENT
),
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
