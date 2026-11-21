// Ported from the ZMK cantanker keymap (~/Documents/cantanker/cantanker-shield/boards/shields/cantanker/cantanker.keymap)
#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _UPPER,
  _LOWER,
  _ADJUST,
  _GAMING,
  _GAME_LOWER,
};

enum custom_keycodes {
  PAREN = SAFE_RANGE, // ()<-
  BRKT,               // []<-
  BRACE,              // {}<-
  ANGLE,              // <><-
};

enum tap_dances {
  TD_SS, // Tap/Hold = Shift | Double-Tap/Hold = Super
};

// Home row mods
#define HM_A    LCTL_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LSFT_T(KC_D)
#define HM_F    LGUI_T(KC_F)
#define HM_J    RGUI_T(KC_J)
#define HM_K    RSFT_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Play |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Sft/Gu|Ctl/A |Alt/S |Sft/D |Gui/F |   G  |-------.    ,-------|   H  |Gui/J |Sft/K |Alt/L |Ctl/; |  '   |
 * |------+------+------+------+------+------| MCLK  |    | MCLK  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |UPPER | /Space  /       \Bkspc \  |Enter |LOWER | Del  |
 *                   `----------------------------'           '------''--------------------'
 * Ctrl+Esc = `   Shift+Esc = ~
 */
 [_BASE] = LAYOUT(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MPLY,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  TD(TD_SS), HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                       KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MS_BTN3,  MS_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                             KC_LALT, KC_LGUI, MO(_UPPER), KC_SPC,  KC_BSPC, KC_ENT,  MO(_LOWER), KC_DEL
),

/* UPPER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    | Del  |   /  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PgUp |  Up  | PgDn | Home |      |                    |      |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down |Right |Gui/End| Bksp|-------.    ,-------|      |   4  |   5  |   6  |   ;  |  '   |
 * |------+------+------+------+------+------| BOOT  |    |       |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |-------|    |-------|      |   1  |   2  |   3  |   \  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |  0   |
 *                   `----------------------------'           '------''--------------------'
 */
[_UPPER] = LAYOUT(
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,         KC_5,                       KC_DEL,  KC_SLSH, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME,      XXXXXXX,                    XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, LGUI_T(KC_END), KC_BSPC,                  XXXXXXX, KC_4,    KC_5,    KC_6,    KC_SCLN, KC_QUOT,
  _______, KC_6,    KC_7,    KC_8,    KC_9,         KC_0,    QK_BOOT,  _______, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_EQL,
                             _______, _______,      _______, _______,  _______, _______, _______, KC_0
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   _  |   -  |   =  |   +  |-------.    ,-------|   {  |   }  |   [  |   ]  |   |  |      |
 * |------+------+------+------+------+------| MCLK  |    |       |------+------+------+------+------+------|
 * |      |   `  |   \  |   ;  |   :  |   ?  |-------|    |-------|   <  |   >  |   "  |   '  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |PrtSc |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  QK_BOOT,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
  _______, KC_TILD, KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS,                    KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE, _______,
  _______, KC_GRV,  KC_BSLS, KC_SCLN, KC_COLN, KC_QUES, MS_BTN3,  _______, KC_LT,   KC_GT,   KC_DQUO, KC_QUOT, KC_SLSH, _______,
                             _______, _______, _______, _______,  _______, _______, _______, KC_PSCR
),

/* ADJUST (UPPER + LOWER)
 * Top-left toggles GAMING, BOOT on both ends of the Tab row. (Bluetooth keys from ZMK have no QMK equivalent.)
 */
[_ADJUST] = LAYOUT(
  TG(_GAMING), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* GAMING: plain QWERTY, no home row mods / tap dance / Esc morphs */
[_GAMING] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MPLY,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MS_BTN3,  MS_BTN3, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                    KC_LALT, KC_LGUI, MO(_GAME_LOWER), KC_SPC,    KC_BSPC, KC_ENT,  MO(_UPPER), KC_DEL
),

/* GAME_LOWER: mirrored right-hand letters on the left, top-left exits GAMING */
[_GAME_LOWER] = LAYOUT(
  TG(_GAMING), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     _______, _______, _______, _______, _______, _______,
  _______,     KC_P,    _______, KC_I,    KC_U,    KC_Y,                      _______, _______, _______, _______, _______, _______,
  _______,     _______, _______, _______, KC_J,    KC_H,                      _______, _______, _______, _______, _______, _______,
  _______,     KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______
),
};

/* Combos (resolved from _BASE by position, see COMBO_ONLY_FROM_LAYER)
 * top row pair = open, bottom row pair = close, home row pair = both + cursor between
 */
const uint16_t PROGMEM yu_combo[]    = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM nm_combo[]    = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM hj_combo[]    = {KC_H, HM_J, COMBO_END};
const uint16_t PROGMEM ui_combo[]    = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM jk_combo[]    = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM io_combo[]    = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM kl_combo[]    = {HM_K, HM_L, COMBO_END};
const uint16_t PROGMEM op_combo[]    = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {HM_L, HM_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(yu_combo, KC_LT),
    COMBO(nm_combo, KC_GT),
    COMBO(hj_combo, ANGLE),
    COMBO(ui_combo, KC_LCBR),
    COMBO(mcomm_combo, KC_RCBR),
    COMBO(jk_combo, BRACE),
    COMBO(io_combo, KC_LBRC),
    COMBO(commdot_combo, KC_RBRC),
    COMBO(kl_combo, BRKT),
    COMBO(op_combo, KC_LPRN),
    COMBO(dotslsh_combo, KC_RPRN),
    COMBO(lscln_combo, PAREN),
};

/* Esc morphs (base layer only, like ZMK where GAMING uses plain Esc) */
const key_override_t esc_ctrl_override  = ko_make_with_layers(MOD_MASK_CTRL, KC_ESC, KC_GRV, 1 << _BASE);
const key_override_t esc_shift_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_ESC, KC_TILD, 1 << _BASE);

const key_override_t *key_overrides[] = {
    &esc_shift_override,
    &esc_ctrl_override,
};

/* Tap dance: Tap/Hold = Shift | Double-Tap/Hold = Super */
static uint16_t td_ss_mod;

static void td_ss_finished(tap_dance_state_t *state, void *user_data) {
  td_ss_mod = state->count >= 2 ? KC_LGUI : KC_LSFT;
  register_code(td_ss_mod);
}

static void td_ss_reset(tap_dance_state_t *state, void *user_data) {
  unregister_code(td_ss_mod);
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_SS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ss_finished, td_ss_reset),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_SS):
      return 200;
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _UPPER, _LOWER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }
  switch (keycode) {
    case PAREN:
      SEND_STRING("()" SS_TAP(X_LEFT));
      return false;
    case BRKT:
      SEND_STRING("[]" SS_TAP(X_LEFT));
      return false;
    case BRACE:
      SEND_STRING("{}" SS_TAP(X_LEFT));
      return false;
    case ANGLE:
      SEND_STRING("<>" SS_TAP(X_LEFT));
      return false;
  }
  return true;
}
