/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include QMK_KEYBOARD_H

 enum layers{
     _BASE, // colemak 33 keys
     _NAV,
     ALT_BASE,
     _NUM,
     _SYM,
     _FUN,
     ALT_FUN,
 };

 #define KC_TASK LGUI(KC_TAB)
 #define KC_FLXP LGUI(KC_E)

 #define L_BAS   DF(_BASE)
 #define L_NAV   MO(_NAV)
#define L_NUM   MO(_NUM)
 #define L_SYM   MO(_SYM)
 #define L_FUN   MO(_FUN)
 #define L_BA2   DF(_ALT_BASE)
 #define L_FN2   MO(_ALT_FUN)

 enum custom_keycodes {
     SMTD_KEYCODES_BEGIN = SAFE_RANGE,
     SMTD_KEYCODES_END,
 };
 #include "sm_td.h"

 void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
     switch (keycode) {
     }
 }

 enum combos {
    CAPS_WORD,
    SEMICOLON,
    COLON,
    DV_PASTE,
    CD_COPY,
    XC_CUT,
    ZX_UNDO,
    NEI_ENTER,
    RST_ESC,
  };

  const uint16_t PROGMEM caps_word_combo[] = {KC_G, KC_M, COMBO_END};
  const uint16_t PROGMEM semicolon_combo[] = {KC_COMM, KC_DOT, COMBO_END};
  const uint16_t PROGMEM colon_combo[] = {KC_H, KC_COMM, COMBO_END};
  const uint16_t PROGMEM dv_paste[] = {KC_D, KC_V, COMBO_END};
  const uint16_t PROGMEM cd_copy[] = {KC_C, KC_D, COMBO_END};
  const uint16_t PROGMEM xc_cut[] = {KC_X, KC_C, COMBO_END};
  const uint16_t PROGMEM zx_undo[] = {KC_Z, KC_X, COMBO_END};
  const uint16_t PROGMEM nei_enter[] = {MT(MOD_RALT,KC_N), MT(MOD_RCTL,KC_E), COMBO_END};
  const uint16_t PROGMEM rst_esc[] = {MT(MOD_LCTL,KC_S), MT(MOD_LALT,KC_T), COMBO_END};

  combo_t key_combos[] = {
     [CAPS_WORD] = COMBO(caps_word_combo, QK_CAPS_WORD_TOGGLE),
     [SEMICOLON] = COMBO(semicolon_combo, KC_SCLN),
     [COLON] = COMBO(colon_combo, KC_COLON),
     [DV_PASTE] = COMBO(dv_paste, C(KC_V)), // ctrl-v; paste
     [CD_COPY] = COMBO(cd_copy, C(KC_C)), // ctrl-c; copy
     [XC_CUT] = COMBO(xc_cut, C(KC_X)), // ctrl-x; cut
     [ZX_UNDO] = COMBO(zx_undo, C(KC_Z)), // ctrl-z; undo - not working for some reason
     [NEI_ENTER] = COMBO(nei_enter, KC_ENT),
     [RST_ESC] = COMBO(rst_esc, KC_ESC),
  };


 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     if (!process_smtd(keycode, record)) {
         return false;
     }
     // your code here

    return true;
 }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [MAC_BASE] = LAYOUT_ansi_82(
    //     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,      KC_Q,     KC_W,     KC_F,     KC_P,    KC_B,  XXXXXXX,     KC_J,     KC_L,     KC_U,     KC_Y,  KC_SCLN,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,     CKC_A,    CKC_R,    CKC_S,    CKC_T,    KC_G,  XXXXXXX,     KC_M,    CKC_N,    CKC_E,    CKC_I,    CKC_O,    XXXXXXX,  XXXXXXX,
    //     LT(_SYM,KC_Z),          KC_X,     KC_C,     KC_D,    KC_V,  XXXXXXX,  XXXXXXX,     KC_K,     KC_H,  KC_COMM,   KC_DOT,              KC_SLSH,  XXXXXXX,
    //     XXXXXXX,  KC_ESC,  LT(_NUM,KC_ENT),                             LT(_NAV,KC_SPC),                KC_BSPC, LT(_FUN,KC_TAB), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_BASE] = LAYOUT_ansi_82(
        XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,      KC_Q,     KC_W,     KC_F,     KC_P,    KC_B,  KC_J,     KC_L,     KC_U,     KC_Y,  KC_QUOT,    XXXXXXX,     XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,     LT(_NUM,KC_A),  MT(MOD_LGUI,KC_R),   MT(MOD_LCTL,KC_S),   MT(MOD_LALT,KC_T),   KC_G,               KC_M,    MT(MOD_RALT,KC_N),   MT(MOD_RCTL,KC_E),   MT(MOD_RGUI,KC_I),   LT(_FUN,KC_O),    XXXXXXX, XXXXXXX,  XXXXXXX,
                  LT(_SYM,KC_Z),    KC_X,     KC_C,     KC_D,    KC_V,  XXXXXXX,  KC_K,     KC_H,  KC_COMM,   KC_DOT,   KC_SLSH,  XXXXXXX,     XXXXXXX,
        XXXXXXX,   XXXXXXX,      LSFT_T(KC_BSPC),                             LT(_NAV,KC_SPC),                LT(_SYM,KC_ENT),   XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [_NAV] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______, C(KC_W),   KC_WBAK,  KC_WFWD, _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,  _______,  _______,    _______,  _______,            _______,
        _______,  C(KC_A), S(KC_TAB), C(KC_S),  KC_TAB,  _______,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT, _______,   _______,              _______,            _______,
        C(KC_Z), C(KC_X),   C(KC_C),  XXXXXXX, C(KC_V),  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  KC_DEL,                                _______,                                KC_ESC,   _______,     _______,  _______,  _______,  _______),

    [_NUM] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_SLSH, KC_7, KC_8,KC_9,KC_EQL,    _______,  _______,      _______,        _______,
        _______,  _______,  KC_LEFT,  KC_UP,  KC_RIGHT, KC_PGDN,  KC_MINS, KC_4, KC_5,KC_6, KC_0,              _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,KC_COMM,  KC_1,  KC_2,  KC_3, KC_DOT, _______,             _______,
        _______,  _______,  _______,                                _______,                              _______, _______,    _______,  _______,  _______,  _______),

    [_SYM] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC ,                  KC_AT,    KC_AMPR, KC_ASTR, KC_QUOT, KC_GRV,         _______, _______,  _______,            _______,
        _______,  KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,                    KC_BSLS,  KC_PLUS, KC_MINS, KC_SLSH, KC_DQUO,          _______,                   _______, _______,
                    KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH,      _______,     KC_PIPE,  KC_EXLM, KC_SCLN, KC_COLN, KC_QUES,         _______,                   _______,
        _______, _______,  KC_BSPC,                                _______,                                   KC_ESC,  _______,    _______,  _______,  _______,  _______),

    [_FUN] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  KC_F7,  KC_F8,  KC_F9,  KC_F12,  KC_F12,    _______,  _______,    _______,  _______,    _______,  _______, _______,             _______,
        _______,  _______,  KC_F4,  KC_F5,  KC_F6,  KC_F11,  KC_F11,    _______,    KC_RALT,    KC_RCTL,  KC_RGUI,              _______,  _______,            _______,
        _______,  KC_F1,            KC_F2,  KC_F3,  KC_F10,  _______,   _______,    _______,    _______,    _______,              _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [ALT_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(ALT_FUN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [ALT_FUN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [ALT_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [ALT_FUN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE
