#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _NUMBER,
    _NAV,
    _SYMBOL,
    _FUNCTION
};

// LEFT HAND HOME ROW MODS
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_D MT(MOD_LGUI, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)
#define RALT_G MT(MOD_RALT, KC_G)

// RIGHT HAND HOME ROW MODS
#define RALT_H MT(MOD_RALT, KC_H)
#define SFT_J MT(MOD_RSFT, KC_J)
#define GUI_K MT(MOD_RGUI, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define CTL_SEMI MT(MOD_RCTL, KC_SCLN)

// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUMBER, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_BSPC LT(_SYMBOL, KC_BSPC)
#define FUN_ENT LT(_FUNCTION, KC_ENT)

// combos
enum combo_events {
  CAPSWORD_COMBO,
  CAPSLOCK_COMBO,
  QUOT_COMBO
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM capsword_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT)
};
#endif // COMBO_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    CTL_A,    ALT_S,    GUI_D,    SFT_F,    RALT_G,             RALT_H,   SFT_J,    GUI_K,    KC_L,     CTL_SEMI,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    KC_LSFT,                      NUM_ESC,  NAV_SPC,            SYM_BSPC, FUN_ENT,                      KC_RSFT
  ),
  
  [_NUMBER] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_PLUS,  KC_7,  KC_8,  KC_9,  XXXXXXX,
    KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,            KC_MINS,  KC_4,  KC_5,  KC_6,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_1,  KC_2,  KC_3,  XXXXXXX,
    XXXXXXX,                      XXXXXXX,  XXXXXXX,            KC_E,     KC_0,                XXXXXXX
  ),
  
  [_NAV] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TAB,             KC_INS,  KC_HOME,  XXXXXXX, KC_PGUP,  XXXXXXX,
    KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_CAPS,            KC_DEL,  KC_END,   KC_UP,   KC_PGDN,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_LEFT, KC_DOWN, KC_RGHT,  XXXXXXX,
    XXXXXXX,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                    XXXXXXX
  ),
  
  [_SYMBOL] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                      XXXXXXX
  ),
  
  [_FUNCTION] = LAYOUT(
    QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F7,  KC_F8,  KC_F9,  KC_F12,
    KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,            XXXXXXX,  KC_F4,  KC_F5,  KC_F6,  KC_F11,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F10,
    XXXXXXX,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                XXXXXXX
  ),
};
