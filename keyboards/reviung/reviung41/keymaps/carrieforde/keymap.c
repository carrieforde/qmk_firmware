/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Aliases for readability
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define OPT_BSPC MT(MOD_LALT, KC_BSPC)
#define LCK_SCN  LGUI(LCTL(KC_Q))
#define SCSHT    LGUI(LSFT(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY
     *
     * ,---------------------------------------------------------------------------------------------------------------.
     * |    Tab    |  Q  |  W  |  E  |    R   |    T    |         |    Y    |      U     |  I  |  O  |  P  |     -     |
     * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----------|
     * | Ctrl/Esc  |  A  |  S  |  D  |    F   |    G    |         |    H    |      J     |  K  |  L  |  ;  |     '     |
     * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----------|
     * |  (LShift  |  Z  |  X  |  C  |    V   |    B    |         |    N    |      M     |  ,  |  .  |  /  |  Rshift)  |
     * |-----------------------------+--------+---------|---------|---------+------------+-----------------------------|
     *                               |  LGUI  |  LOWER  |  Space  |  RAISE  |  Opt/BSPC  |
     *                               `---------------------------------------------------'
     */
  [_BASE] = LAYOUT(
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS,
    CTRL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    SC_LSPO,   KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_RSPC,
                                             KC_LGUI,   LOWER,    KC_SPC,   RAISE,    OPT_BSPC
  ),

   /*
    * Lower Layer: symbols & navigation
    *
    * ,---------------------------------------------------------------------------------------------------------------.
    * |           |  !  |  @  |  #  |    $   |    %    |         |    ^    |      &     |  *  |  (  |  )  |    DEL    |
    * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----------|
    * |           |  _  |  +  |  {  |    }   |    |    |         |    ←    |      ↓     |  ↑  |  →  |  `  |     ~     |
    * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----------|
    * |           | ESC | LS  | SS  |  CAPS  |    "    |         |    N    |      M     |  ,  |  .  |  /  |           |
    * |-----------------------------+--------+---------|---------|---------+------------+-----------------------------|
    *                               |  LGUI  |  LOWER  |  Space  |  RAISE  |  Opt/BSPC  |
    *                               `---------------------------------------------------'
    */
  [_LOWER] = LAYOUT(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_ESC,   LCK_SCN,    SCSHT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  _______,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

   /*
    * Raise Layer: numbers & symbols
    *
    * ,---------------------------------------------------------------------------------------------------------.
    * |           |  1  |  2  |  3  |    4   |    5    |         |    6    |      7     |  8  |  9  |  0  |  =  |
    * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----|
    * |           |  -  |  =  |  [  |    ]   |    \    |         |    .    |      4     |  5  |  6  |  -  |  /  |
    * |-----------+-----+-----+-----+--------+---------|---------|---------+------------+-----+-----+-----+-----|
    * |           |     |     |     |  CAPS  |    '    |         |    0    |      1     |  2  |  3  |  +  |  *  |
    * |-----------------------------+--------+---------|---------|---------+------------+-----------------------|
    *                               |  LGUI  |  LOWER  |  Space  |  RAISE  |  Opt/BSPC  |
    *                               `---------------------------------------------------'
    */
  [_RAISE] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_PDOT,  KC_4,     KC_5,     KC_6,     KC_PMNS,  KC_PSLS,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_0,     KC_1,     KC_2,     KC_3,     KC_PPLS,  KC_PAST,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT(
    _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, KC_VOLU, KC_MNXT, _______, _______, _______,
    _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_MUTE, KC_MPLY, _______, _______, _______,
    _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,                                     _______, KC_VOLD, KC_MPRV, _______, _______, _______,
                                                 _______, _______, XXXXXXX, _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

