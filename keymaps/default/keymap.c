#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// combos
enum combo_events {
  CAPSWORD_COMBO,
  CAPSLOCK_COMBO
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM capsword_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_O, COMBO_END};

combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS)
};
#endif // COMBO_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    KC_LSFT,                      KC_ESC,   KC_SPC,             KC_BSPC,  KC_ENT,                       KC_RSFT
  ),
  
  [_LOWER] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,                      _______,  _______,            _______,  _______,                      _______
  ),
  
  [_RAISE] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,                      _______,  _______,            _______,  _______,                      _______
  ),
  
  [_ADJUST] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,
    _______,                      _______,  _______,            _______,  _______,                      _______
  ),
};
