// inspiration from
// - https://github.com/OneDeadKey/arsenik
// - https://github.com/manna-harbour/miryoku


/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layers {
    _BASE,// Base alpha (colemak-dh)
    _NAV, // Navigation
    _NUM, // Numberpad
    _SYM, // Symbols
    _FUN, // Functions
};

#define L_BASE   DF(_BASE)
#define L_NAV   MO(_NAV)
#define L_SYM   MO(_SYM)
#define L_NUM   MO(_NUM)
#define L_FUN   MO(_FUN)

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
    RST_ESC,
    BACKSPACE,
    DELETE,
    NEI_ENTER,
  };

  const uint16_t PROGMEM caps_word_combo[] = {KC_G, KC_M, COMBO_END};
  const uint16_t PROGMEM semicolon_combo[] = {KC_COMM, KC_DOT, COMBO_END};
  const uint16_t PROGMEM colon_combo[] = {KC_H, KC_COMM, COMBO_END};
  const uint16_t PROGMEM dv_paste[] = {KC_D, KC_V, COMBO_END};
  const uint16_t PROGMEM cd_copy[] = {KC_C, KC_D, COMBO_END};
  const uint16_t PROGMEM xc_cut[] = {KC_X, KC_C, COMBO_END};
  const uint16_t PROGMEM rst_esc[] = {KC_U, KC_Y, COMBO_END};
  const uint16_t PROGMEM backspace_combo[] = {MT(MOD_LGUI,KC_R), MT(MOD_LCTL,KC_S), COMBO_END};
  const uint16_t PROGMEM delete_combo[] = {KC_W, KC_F, COMBO_END};
  const uint16_t PROGMEM nei_enter[] = {MT(MOD_RCTL,KC_E), MT(MOD_RGUI,KC_I), COMBO_END};

  combo_t key_combos[] = {
     [CAPS_WORD] = COMBO(caps_word_combo, QK_CAPS_WORD_TOGGLE),
     [SEMICOLON] = COMBO(semicolon_combo, KC_SCLN),
     [COLON] = COMBO(colon_combo, KC_COLON),
     [DV_PASTE] = COMBO(dv_paste, C(KC_V)), // ctrl-v; paste
     [CD_COPY] = COMBO(cd_copy, C(KC_C)), // ctrl-c; copy
     [XC_CUT] = COMBO(xc_cut, C(KC_X)), // ctrl-x; cut
     [RST_ESC] = COMBO(rst_esc, KC_ESC),
     [BACKSPACE] = COMBO(backspace_combo, KC_BSPC),
     [DELETE] = COMBO(delete_combo, KC_DEL),
     [NEI_ENTER] = COMBO(nei_enter, KC_ENT),
  };


  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      if (!process_smtd(keycode, record)) {
          return false;
      }
      // your code here

     return true;
  }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Colemak DH - Koy
     *
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │Lay│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │     │ Q │ W │ F │ P │ B │   │ J │ L │ U │ Y │ ; │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │ A │ R │ S │ T │ G │   │ M │ N │ E │ I │ O │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │      Z │ X │ C │ D │ V │   │   │ K │ H │ , │ . │ /    │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │ Esc│ Ent│         Space          │Bspc│ Tab│ │   │   │   │
     * └────┴────┴────┴────────────────────────┴────┴────┴─┴───┴───┴───┘
     */
     [_BASE] = LAYOUT_65_ansi_blocker_split_bs(
        XXXXXXX,     XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,     KC_Q,           KC_W,    KC_F,    KC_P,    KC_B,               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,              XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX,     LT(_NUM,KC_A),  MT(MOD_LGUI,KC_R),   MT(MOD_LCTL,KC_S),   MT(MOD_LALT,KC_T),   KC_G,               KC_M,    MT(MOD_RALT,KC_N),   MT(MOD_RCTL,KC_E),   MT(MOD_RGUI,KC_I),   LT(_FUN,KC_O),                 XXXXXXX,                   XXXXXXX, XXXXXXX,
                     LT(_SYM,KC_Z),  KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,              XXXXXXX,                   XXXXXXX, XXXXXXX,
        XXXXXXX,     XXXXXXX, OSM(MOD_LSFT),              LT(_NAV,KC_SPC),                    OSL(_SYM),  XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // [X] = LAYOUT_65_ansi_blocker_split_bs(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______,
    //     _______, _______, _______,                            _______,                   _______, _______,                    _______, _______, _______
    // ),

    // Nav
    [_NAV] = LAYOUT_65_ansi_blocker_split_bs(
        _______,     _______, _______,   _______,  _______, _______,                 _______, _______, _______, _______,  _______,              _______, _______, _______, _______, _______,
        _______,     _______, C(KC_W), S(C(KC_TAB)), C(KC_TAB), _______,             KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,              _______, _______,          _______, _______,
        _______,     KC_WBAK, KC_WFWD, S(KC_TAB),  KC_TAB,  _______,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,              _______,                   _______, _______,
                     _______, _______, _______,  _______, _______,    _______,     _______, _______, _______, _______,  _______,              _______,                   _______, _______,
        _______,     _______, KC_DEL,                             _______,                   KC_ESC, _______,                                                    _______, _______, _______
    ),

    // Numbers
    [_NUM] = LAYOUT_65_ansi_blocker_split_bs(
        _______,     _______, _______, _______, _______,  _______,                  _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______,
        _______,     _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP,                  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_EQL,                _______, _______,          _______, _______,
        _______,     _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                  KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,                  _______,                   _______, _______,
                     _______, _______, _______, _______,  _______,     _______,     KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,                _______,                   _______, _______,
        _______,     _______, _______,                                 _______,                   _______,   _______,                                            _______, _______, _______
    ),

    // Symbols
    [_SYM] = LAYOUT_65_ansi_blocker_split_bs(
        _______,     _______, _______, _______, _______, _______,                   _______,  _______, _______, _______, _______,            _______, _______, _______, _______, _______,
        _______,     KC_CIRC, KC_LT,   KC_GT,   KC_DLR,  KC_PERC ,                  KC_AT,    KC_AMPR, KC_ASTR, KC_QUOT, KC_GRV,         _______, _______,          _______, _______,
        _______,     KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,                    KC_BSLS,  KC_PLUS, KC_MINS, KC_SLSH, KC_DQUO,          _______,                   _______, _______,
                     KC_TILD, KC_LBRC, KC_RBRC, KC_UNDS, KC_HASH,      _______,     KC_PIPE,  KC_EXLM, KC_SCLN, KC_COLN, KC_QUES,         _______,                   _______, _______,
        _______,     _______, KC_BSPC,                                 KC_SPC,                   XXXXXXX, _______,                                            _______, _______, _______
    ),

    // Functions
    [_FUN] = LAYOUT_65_ansi_blocker_split_bs(
        _______,     _______, _______, _______, _______, _______,                  _______,  _______,  _______,  _______, _______,            _______, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______,                  KC_F10,   KC_F7,    KC_F8,    KC_F9,   _______,          _______, _______,            _______, _______,
        _______,     _______, _______, _______, _______, _______,                  KC_F11,   KC_F4,    KC_F5,    KC_F6,   _______,            _______,                   _______, _______,
                     _______, _______, _______, _______, _______,     _______,     KC_F12,   KC_F1,    KC_F2,    KC_F3,   _______,            _______,                   _______, _______,
        _______,     _______, _______,                                KC_SPC,                   _______, _______,                                              _______, _______, _______
    ),

};

