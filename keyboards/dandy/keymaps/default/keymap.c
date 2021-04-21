/*
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

// Layer shorthand
enum layer {
    _BASE,
    _SYS,
    _LWR,
    _RSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬────────┐
     * |   ~    │  1  │  2  │  3  │  4  │  5  │  -  │  +  │  6  │  7  │  8  │  9  │  0  │  BKSP  │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |   ESC  │  Q  │  W  │  E  │  R  │  T  │  [  │  ]  │  Y  │  U  │  I  │  O  │  P  │   |    │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |   TAB  │  A  │  S  │  D  │  F  │  G  │ HME │ END │  H  │  J  │  K  │  L  │  :  │   "    │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |  SHFT  │  Z  │  X  │  C  │  V  │  B  │ PUP │ PDN │  N  │  M  │  <  │  >  │  ?  │  SHFT  │
     * ├────────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┴─────┼─────┼─────┼─────┼─────┼────────┤
     * |  CTRL  │ LR0 │ WIN │ ALT │ LR1 │   SPACE   │   ENTER   │ LR2 │  ←  │  ↓  │  ↑  │   →    │
     * └────────┴─────┴─────┴─────┴─────┴───────────┴───────────┴─────┴─────┴─────┴─────┴────────┘
     */

    [_BASE] = LAYOUT_ortho_2x2u(
        KC_GRAVE, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,   KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_ESC,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC,  KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_END,   KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP, KC_PGDN,  KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,  MO(_RSE), KC_LGUI, KC_LALT, MO(_LWR),         KC_SPC,  KC_ENTER,          KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL
    ),

    /*
     * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬────────┐
     * |        │     │     │     │     │     │     │     │     │ NUM │  /  │  *  │  -  │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │  7  │  8  │  9  │  +  │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │  4  │  5  │  6  │  +  │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │  1  │  2  │  3  │ ENT │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┴─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │           │           │  0  │  00 │  .  │ ENT │        │
     * └────────┴─────┴─────┴─────┴─────┴───────────┴───────────┴─────┴─────┴─────┴─────┴────────┘
     */

    [_LWR] = LAYOUT_ortho_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
        _______, _______, _______, _______, _______,          _______, _______,          KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______
    ),

    /*
     * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬────────┐
     * |        │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │     │     │     │     │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │     │     │     │     │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │     │     │     │     │     │     │     │     │        │
     * ├────────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┴─────┼─────┼─────┼─────┼─────┼────────┤
     * |        │     │     │     │     │           │           │     │     │     │     │        │
     * └────────┴─────┴─────┴─────┴─────┴───────────┴───────────┴─────┴─────┴─────┴─────┴────────┘
     */

    [_RSE] = LAYOUT_ortho_2x2u(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______
    )

};
