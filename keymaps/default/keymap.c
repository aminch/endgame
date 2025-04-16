#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "quantum/rgblight/rgblight.h"

enum layer_names {
    _QWERTY,
    _NUMBER,    
    _NAV,
    _SYMBOL,
    _FUNCTION
};

enum custom_keycodes {
  L_CTRL = SAFE_RANGE
};

// LEFT HAND HOME ROW MODS
#define LCTL_A MT(MOD_LCTL, KC_A)
#define LGUI_S MT(MOD_LGUI, KC_S)
#define LALT_D MT(MOD_LALT, KC_D)
#define LSFT_F MT(MOD_LSFT, KC_F)
#define RALT_G MT(MOD_RALT, KC_G)

// RIGHT HAND HOME ROW MODS
#define LALT_H MT(MOD_LALT, KC_H)
#define RSFT_J MT(MOD_RSFT, KC_J)
#define RALT_K MT(MOD_RALT, KC_K)
#define RGUI_L MT(MOD_RGUI, KC_L)
#define RCTL_SEMI MT(MOD_RCTL, KC_SCLN)

// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUMBER, KC_ESC)
#define M_NUM_ESC LT(_NUMBER_MAC, KC_ESC)
#define NAV_LSPC LT(_NAV, KC_SPC)
#define SYM_RSPC LT(_SYMBOL, KC_SPC)
#define FUN_ENT LT(_FUNCTION, KC_ENT)

// combos
enum combo_events {
  CAPSWORD_COMBO,
  CAPSLOCK_COMBO,
  QUOT_COMBO,
  BOOT_COMBO
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM capsword_combo[] = {LSFT_F, RSFT_J, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM boot_combo[] = {KC_F1, KC_F10, COMBO_END};

combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT),
    [BOOT_COMBO] = COMBO(boot_combo, QK_BOOT)
};
#endif // COMBO_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    LCTL_A,   LGUI_S,   LALT_D,   LSFT_F,   RALT_G,             LALT_H,   RSFT_J,   RALT_K,   RGUI_L,   RCTL_SEMI,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    L_CTRL,                       NUM_ESC,  NAV_LSPC,           SYM_RSPC, FUN_ENT,                      KC_BSPC
  ),
  
  [_NUMBER] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_PPLS,  KC_7,  KC_8,  KC_9,  KC_PSLS,
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_RALT,            KC_PMNS,  KC_4,  KC_5,  KC_6,  KC_PAST,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_1,  KC_2,  KC_3,  KC_PDOT,
    KC_LSFT,                      XXXXXXX,  XXXXXXX,            KC_E,     KC_0,                KC_BSPC
  ),

  [_NAV] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_TAB,             KC_INS,   KC_HOME,  XXXXXXX, KC_PGUP,  XXXXXXX,
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_RALT,            KC_DEL,   KC_END,   KC_UP,   KC_PGDN,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CAPS,            XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RGHT,  XXXXXXX,
    L_CTRL,                       XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                     KC_BSPC
  ),
  
  [_SYMBOL] = LAYOUT(
    KC_GRV,  KC_TILD,  KC_PIPE,  XXXXXXX,  KC_LBRC,             KC_RBRC,  KC_AMPR,  KC_ASTR,  KC_QUOT,  KC_DQT,
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LPRN,            KC_RPRN,  KC_DLR,   KC_PERC,  KC_CIRC,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LABK,            KC_RABK,  KC_EXLM,  KC_AT,    KC_HASH,  KC_UNDS,
    KC_LSFT,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                      KC_BSPC
  ),
  
  [_FUNCTION] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F7,  KC_F8,  KC_F9,  KC_F12,
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_RALT,            XXXXXXX,  KC_F4,  KC_F5,  KC_F6,  KC_F11,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_F1,  KC_F2,  KC_F3,  KC_F10,
    L_CTRL,                       XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,                KC_BSPC
  ),
};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 
        'L',           'L', 'L',     'R', 'R',           'R'
    );
#endif  // CHORDAL_HOLD

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case L_CTRL:
            // Handle lower left key differently when MacOS is detected
            if (record->event.pressed) {
              if (keymap_config.swap_lalt_lgui) {
                  register_mods(MOD_LGUI);
              } else {
                  register_mods(MOD_LCTL);
              }
            } else {
              if (keymap_config.swap_lalt_lgui) {
                  unregister_mods(MOD_LGUI);
              } else {
                  unregister_mods(MOD_LCTL);
              }
            }
            break;
    }
    return true;
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
      return false;
  }

  switch (detected_os) {
      case OS_MACOS:
          // When MacOS is detected, flip GUI and ALT
          keymap_config.swap_lalt_lgui = true;
          keymap_config.swap_ralt_rgui = true;
          break; 
      case OS_UNSURE:
      case OS_LINUX:
      case OS_WINDOWS:
      case OS_IOS:
          break;
  }
  
  return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  switch (combo_index) {
      case BOOT_COMBO:
          if (!layer_state_is(_FUNCTION)) {
              return false;
          }
  }

  return true;
}

void keyboard_post_init_user(void) {
  //rgblight_setrgb_range(25, 0, 0, 0, 1);  // Red
  //rgblight_setrgb_range(0, 25, 0, 0, 1);  // Green
  //rgblight_setrgb_range(0, 0, 25, 0, 1);  // Blue
  //rgblight_setrgb_range(0, 25, 25, 0, 1);  // Cyan
  rgblight_setrgb_range(25, 0, 50, 0, 1);  // Purple
  //rgblight_setrgb_range(25, 25, 0, 0, 1);  // Yellow
  //rgblight_setrgb_range(25, 25, 25, 0, 1);  // White
}
