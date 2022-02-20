#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  LDESK,
  RDESK
};

#define KC_RQL LT(MO(_LOWER), KC_SPC)
#define EISU KC_F13
#define KANA KC_F14

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | Eisu |                    | Kana |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Shift|||||||| Ctrl |      |   N  |   M  |   ,  |   .  |   /  |   \  |
   * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
   * | Esc  |  GUI |  ALt |  Adj |||||||| Lower|      |Delete|||||||| Bksp |      |Raise=|||||||| GUI  | ALt  | LDESK| RDESK|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    EISU,                           KANA,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_RSFT,       KC_RCTRL,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_ESC, KC_LGUI, KC_LALT, ADJUST,            LOWER,   KC_SPC , KC_DEL,        KC_BSPC,KC_ENT , RAISE,            KC_RGUI, KC_RALT, LDESK,   RDESK
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |      |      |  GUI |      | Eisu |                    | Kana | Left | Down |  Up  | Right|   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      | Shift|||||||| Ctrl |      | Home |PageDn|PageUp|  End |   /  | Shift|
   * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
   * | Esc  |      |      |  Adj |||||||| Lower|      |Delete|||||||| Bksp |      | Raise||||||||      |      |      |      |
   * ,--------------------------------------------------------------------- -------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TAB , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
    KC_LCTL, _______, _______, _______, KC_LGUI, _______, EISU,                           KANA,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, KC_QUOT,
    KC_LSFT, _______, _______, _______, _______, _______,           KC_RSFT,       KC_RCTRL,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_SLSH, KC_RSFT,
    KC_ESC , _______, _______, ADJUST,           LOWER,   KC_SPC,  KC_DEL,        KC_BSPC,KC_ENT,  RAISE,            _______, _______, _______, _______
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * | Tab  |      |      |      |      |      |   (  |                    |   )  |   /  |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * | Ctrl |      |      |      |  GUI |      | Eisu |                    | Kana |   *  |   4  |   5  |   6  |   +  |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |      | Shift|||||||| Ctrl |      | Bksp |   1  |   2  |   3  | Enter|      |
  * |-------------+------+------+------+------| Space|------+------+------| Enter|------+------+------+------+-------------|
  * | Esc  |      |      |  Adj |||||||| Lower|      |Delete|||||||| Bksp |      | Raise||||||||   0  |   .  |      |      |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_TAB , _______, _______, _______, _______, _______, KC_LPRN,                        KC_RPRN, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
    KC_LCTL, _______, _______, _______, KC_LGUI, _______, EISU,                           KANA,    KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    KC_LSFT, _______, _______, _______, _______, _______,         KC_RSFT,        KC_RCTRL,        KC_BSPC, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
    KC_ESC,  _______, _______, ADJUST,           LOWER,   KC_SPC, KC_DEL,         KC_BSPC,KC_ENT , RAISE,            KC_0,    KC_DOT,  _______, _______
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |      |      |      |      |      |      |                    |      |      |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |      |  ALt |  GUI |      |      |                    |      |      |  F4  |  F5  |  F6  |  F11 |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |      ||||||||      |      |      |  F1  |  F2  |  F3  |      |      |
   * |-------------+------+------+------+------|      |------+------+------|      |------+------+------+------+-------------|
   * | Esc  |      |      |  Adj |||||||| Lower|      |      ||||||||      |      | Raise||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______, _______, _______, KC_LALT, KC_LGUI , BL_DEC ,_______,                      _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    _______, _______, _______, _______, _______, _______,        _______,       _______,         _______, KC_F1,   KC_F2,   KC_F3,   _______, _______,
    _______, _______, _______, ADJUST,           LOWER,  _______,_______,       _______,_______, RAISE,            _______, _______, _______, _______
  )
};

static bool raise_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LDESK:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        unregister_code(KC_LEFT);
      }

      return false;
      break;
    case RDESK:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        register_code(KC_RGHT);
      } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        unregister_code(KC_RGHT);
      }

      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed) {
          register_code(KC_EQL);
          unregister_code(KC_EQL);
        }
        raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        raise_pressed = false;
      }
      break;
  }
  return true;
}
