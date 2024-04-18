/* Copyright 2020 João Pedro Pio
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

enum layers {
  _COLEMAK_DMH,
  _SYMBOLS,
  _PROGRAMMING,
  _SYSTEM,
  _QWERTY
};

enum combos {
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LCTLALT,
    COMBO_RCTL,
    COMBO_RGUI,
    COMBO_RALT,
    COMBO_RCTLALT,
    COMBO_LACUTE,
    COMBO_LTILDE,
    COMBO_LCIRCUMFLEX,
    COMBO_RACUTE,
    COMBO_RTILDE,
    COMBO_RCIRCUMFLEX,
    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

// Layers
#define LT2_SPC LT(2,KC_SPC)
#define LT1_ENT LT(1,KC_ENT)
#define RGBLYR  MO(_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak-DHm (Layers 1 and 2 has mod taps)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓          ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃    Q    ┃    W    ┃    F    ┃    P    ┃    B    ┃          ┃    J    ┃    L    ┃    U    ┃    Y    ┃    ;    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    A    ┃    R    ┃    S    ┃    T    ┃    G    ┃          ┃    M    ┃    N    ┃    E    ┃    I    ┃    O    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    Z    ┃    X    ┃    C    ┃    D    ┃    V    ┃          ┃    K    ┃    H    ┃    ,    ┃    .    ┃    /    ┃
    ┗━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┛
                        ┃  ESC    ┃  Shift  ┃LT2/SPACE┃          ┃LT1/ENTER┃   BSCP  ┃   TAB   ┃
                        ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛          ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_COLEMAK_DMH] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,   KC_P,    KC_B,                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_R,    KC_S,   KC_T,    KC_G,                 KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,   KC_D,    KC_V,                 KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_ESC, KC_LSFT, LT2_SPC,              LT1_ENT, KC_BSPC, KC_TAB
    ),

    /* Symbols (This layer has mode taps. This draw don't show it for clarity)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓          ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃    !    ┃    @    ┃    #    ┃    $    ┃    %    ┃          ┃    ^    ┃    &    ┃    *    ┃    (    ┃    )    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    1    ┃    2    ┃    3    ┃    4    ┃    5    ┃          ┃    6    ┃    7    ┃    8    ┃    9    ┃    0    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃         ┃         ┃         ┃         ┃         ┃          ┃         ┃    ←    ┃    ↓    ┃    ↑	 ┃    →    ┃
    ┗━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┛
                        ┃         ┃         ┃  MO(3)  ┃          ┃         ┃         ┃         ┃
                        ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛          ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

    [_SYMBOLS] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, _______, _______, _______, _______,                _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                          _______, _______, MO(_SYSTEM),            _______, _______, _______
    ),

    /* Programming (This layer has mode taps. This draw don't show it for clarity)
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓          ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃    Q    ┃    W    ┃    F    ┃    P    ┃    B    ┃          ┃    "    ┃    {    ┃    }    ┃    \    ┃    |    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    A    ┃    R    ┃    S    ┃    T    ┃    G    ┃          ┃    ~    ┃    [    ┃    ]    ┃    `    ┃    '    ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃    Z    ┃    X    ┃    C    ┃    D    ┃    V    ┃          ┃         ┃    -    ┃    _    ┃    =    ┃    +    ┃
    ┗━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┛
                        ┃  ESC    ┃  Shift  ┃LT2/SPACE┃          ┃  MO(3)  ┃         ┃         ┃
                        ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛          ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */


    [_PROGRAMMING] = LAYOUT_split_3x5_3(
        LCTL(KC_Q),LCTL(KC_W),LCTL(KC_F),KC_WH_L,KC_WH_R,                 KC_DQUO, KC_LCBR, KC_RCBR, KC_BSLS, KC_PIPE,
        LCTL(KC_A),LCTL(KC_R),LCTL(KC_S),KC_WH_D,KC_WH_U,                 KC_TILD, KC_LBRC, KC_RBRC, KC_GRV,  KC_QUOT,
        LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),KC_D,LCTL(KC_V),                 _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
                               _______, _______, _______,                 MO(_SYSTEM), _______, _______
    ),

    /* System
    ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓          ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    ┃   F1    ┃   F2    ┃   F3    ┃   F4    ┃  PRTSCR ┃          ┃  RESET  ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   F5    ┃   F6    ┃   F7    ┃   F8    ┃         ┃          ┃         ┃         ┃         ┃         ┃         ┃
    ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    ┃   F9    ┃   F10   ┃   F11   ┃   F12   ┃         ┃          ┃         ┃         ┃         ┃         ┃         ┃
    ┗━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┛
                        ┃         ┃         ┃         ┃          ┃         ┃         ┃         ┃
                        ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛          ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    */

	[_SYSTEM] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,           QK_BOOT, _______, _______, _______, _______,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,           _______, _______, _______, _______, _______,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,           _______, _______, _______, _______, _______,
                          _______, _______, _______,           _______, _______, _______
    )

    // /*
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓          ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃    Q    ┃    W    ┃    E    ┃    R    ┃    T    ┃          ┃    Y    ┃    U    ┃    I    ┃    O    ┃    P    ┃  BKSP   ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃    A    ┃    S    ┃    D    ┃    F    ┃    G    ┃          ┃    H    ┃    J    ┃    K    ┃    L    ┃    ;    ┃    '    ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃    Z    ┃    X    ┃    C    ┃    V    ┃    B    ┃          ┃    N    ┃    M    ┃    ,    ┃    .    ┃    /    ┃  ENTER  ┃
    // ┗━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫          ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                     ┃  ESC    ┃  Shift  ┃LT2/SPACE┃          ┃LT1/ENTER┃   BSCP  ┃   TAB   ┃
    //                     ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛          ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    // */
    
    // [_QWERTY] = LAYOUT_split_3x5_3(
    //     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    //     KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    //                     KC_ESC, KC_LSFT, KC_SPC,              LT(_SYSTEM, KC_ENT), KC_BSPC, KC_TAB
    // )
};

// define keys that make up combos
// home row combos - left hand combos
const uint16_t PROGMEM ts_combo[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM tr_combo[] = {KC_T, KC_R, COMBO_END};
const uint16_t PROGMEM sr_combo[] = {KC_S, KC_R, COMBO_END};
const uint16_t PROGMEM tsr_combo[] = {KC_T, KC_S, KC_R, COMBO_END};

// home row combos - right-hand combos
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ni_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM nei_combo[] = {KC_N, KC_E, KC_I, COMBO_END};

// accentuation - left hand combos
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ly_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};

// accentuation - right-hand combos
const uint16_t PROGMEM pf_combo[] = {KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM pw_combo[] = {KC_P, KC_W, COMBO_END};
const uint16_t PROGMEM fw_combo[] = {KC_F, KC_W, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    // home row combos
    [COMBO_LCTL] = COMBO(ts_combo, KC_LCTL),
    [COMBO_LALT] = COMBO(tr_combo, KC_LALT),
    [COMBO_LGUI] = COMBO(sr_combo, KC_LGUI),
    [COMBO_LCTLALT] = COMBO(tsr_combo, LCTL(KC_LALT)),
    [COMBO_RCTL] = COMBO(ne_combo, KC_LCTL),
    [COMBO_RALT] = COMBO(ni_combo, KC_LALT),
    [COMBO_RGUI] = COMBO(ei_combo, KC_LGUI),
    [COMBO_RCTLALT] = COMBO(nei_combo, LCTL(KC_LALT)),

    // accentuation
    [COMBO_RACUTE] = COMBO(lu_combo, KC_QUOT),
    [COMBO_RTILDE] = COMBO(uy_combo, KC_TILD),
    [COMBO_RCIRCUMFLEX] = COMBO(ly_combo, KC_CIRC),
    [COMBO_LACUTE] = COMBO(pf_combo, KC_QUOT),
    [COMBO_LTILDE] = COMBO(fw_combo, KC_TILD),
    [COMBO_LCIRCUMFLEX] = COMBO(pw_combo, KC_CIRC)
};

#include "matrix.h"
#include OLED_FONT_H

extern matrix_row_t matrix[MATRIX_ROWS];

#define ANIM_FRAME_DURATION 100
#define IDLE_FRAMES 5
#define IDLE_TIMEOUT 750
#define SLEEP_TIMEOUT 15000

static bool OLED_redraw = true;

static const uint8_t bongofont[] PROGMEM = { \
    0xC1, 0xC1, 0xC2, 0x04, 0x08, 0x10, \
    0xC0, 0x38, 0x04, 0x03, 0x00, 0x00, \
    0xA0, 0x22, 0x24, 0x14, 0x12, 0x12, \
    0xA0, 0x21, 0x22, 0x12, 0x11, 0x11, \
    0x83, 0x7C, 0x41, 0x41, 0x40, 0x40, \
    0x82, 0x82, 0x84, 0x08, 0x10, 0x20, \
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, \
    0x80, 0x70, 0x19, 0x06, 0x00, 0x00, \
    0x80, 0x70, 0x0C, 0x03, 0x00, 0x00, \
    0x80, 0x00, 0x30, 0x30, 0x00, 0xC0, \
    0x80, 0x00, 0x30, 0x30, 0x00, 0x00, \
    0x49, 0x88, 0x08, 0x08, 0x08, 0x00, \
    0x44, 0x84, 0x04, 0x04, 0x00, 0x00, \
    0x40, 0x80, 0x00, 0x00, 0x00, 0x00, \
    0x40, 0x40, 0x20, 0x20, 0x20, 0x20, \
    0x3C, 0xC2, 0x01, 0x01, 0x02, 0x02, \
    0x35, 0x01, 0x8A, 0x7C, 0x00, 0x00, \
    0x20, 0x40, 0x80, 0x00, 0x00, 0x00, \
    0x20, 0x21, 0x22, 0x12, 0x11, 0x11, \
    0x20, 0x20, 0x10, 0x10, 0x10, 0x10, \
    0x1E, 0xE1, 0x00, 0x00, 0x01, 0x01, \
    0x1C, 0xE2, 0x01, 0x01, 0x02, 0x02, \
    0x18, 0x64, 0x82, 0x02, 0x02, 0x02, \
    0x18, 0x60, 0x80, 0x00, 0x00, 0x00, \
    0x18, 0x18, 0x1B, 0x03, 0x00, 0x40, \
    0x18, 0x06, 0x05, 0x98, 0x99, 0x84, \
    0x12, 0x0B, 0x08, 0x08, 0x08, 0x08, \
    0x11, 0x09, 0x08, 0x08, 0x08, 0x08, \
    0x10, 0x10, 0xD0, 0x11, 0x0F, 0x21, \
    0x10, 0x10, 0x10, 0x11, 0x0F, 0x01, \
    0x10, 0x08, 0x08, 0x04, 0x04, 0x04, \
    0x10, 0x08, 0x04, 0x02, 0x02, 0x04, \
    0x0C, 0x30, 0x40, 0x80, 0x00, 0x00, \
    0x0C, 0x0C, 0x0D, 0x01, 0x00, 0x40, \
    0x08, 0xE8, 0x08, 0x07, 0x10, 0x24, \
    0x08, 0x30, 0x40, 0x80, 0x00, 0x00, \
    0x08, 0x08, 0x08, 0x07, 0x00, 0x00, \
    0x08, 0x08, 0x04, 0x02, 0x02, 0x02, \
    0x08, 0x04, 0x02, 0x01, 0x01, 0x02, \
    0x05, 0x05, 0x09, 0x09, 0x10, 0x10, \
    0x04, 0x38, 0x40, 0x80, 0x00, 0x00, \
    0x04, 0x04, 0x08, 0x08, 0x10, 0x10, \
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, \
    0x04, 0x04, 0x02, 0x01, 0x00, 0x00, \
    0x02, 0x02, 0x81, 0x80, 0x80, 0x00, \
    0x02, 0x02, 0x04, 0x04, 0x08, 0x08, \
    0x02, 0x02, 0x02, 0x01, 0x01, 0x01, \
    0x02, 0x02, 0x01, 0x00, 0x00, 0x00, \
    0x01, 0xE1, 0x1A, 0x06, 0x09, 0x31, \
    0x01, 0x01, 0x02, 0x04, 0x08, 0x10, \
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, \
    0x00, 0x80, 0x80, 0x00, 0x00, 0x00, \
    0x00, 0x80, 0x40, 0x40, 0x20, 0x20, \
    0x00, 0x00, 0x80, 0x80, 0x40, 0x40, \
    0x00, 0x00, 0x60, 0x60, 0x00, 0x81, \
    0x00, 0x00, 0x01, 0x01, 0x00, 0x40, \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, \
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; 


static const uint8_t bongo_line_x[] = {51, 49, 48, 57};
static const uint8_t bongo_line_y[] = {0, 8, 16, 24};
static const uint8_t bongo_line_len[] = {5, 7, 8, 6};

const uint8_t bongo_line_data[8][26] PROGMEM = {
    { //idle1
    60, 52, 19, 30, 35, \
    22, 47, 51, 60, 9, 0, 17, \
    1, 57, 33, 3, 27, 41, 29, 50, \
    45, 36, 60, 60, 60, 60}, \
    { //idle2
    60, 52, 19, 30, 35, \
    22, 47, 51, 60, 9, 0, 17, \
    1, 57, 33, 3, 27, 41, 29, 50, \
    45, 36, 60, 60, 60, 60}, \
    { //idle3
    60, 53, 14, 31, 23, \
    15, 43, 60, 60, 54, 5, 13, \
    7, 56, 24, 2, 26, 39, 29, 50, \
    45, 36, 60, 60, 60, 60}, \
    { //idle4
    6, 52, 19, 38, 32, \
    20, 47, 51, 60, 9, 0, 17, \
    8, 57, 33, 3, 27, 41, 29, 50, \
    45, 36, 60, 60, 60, 60}, \
    { //idle5
    60, 52, 19, 37, 40, \
    21, 47, 51, 60, 9, 0, 17, \
    8, 57, 33, 3, 27, 41, 29, 50, \
    45, 36, 60, 60, 60, 60}, \
    { //prep
    6, 52, 19, 38, 32, \
    20, 44, 51, 60, 10, 48, 16, \
    8, 25, 4, 18, 27, 42, 46, 50, \
    60, 60, 60, 60, 60, 60}, \
    { //tap1
    6, 52, 19, 38, 32, \
    20, 44, 51, 60, 10, 49, 17, \
    8, 25, 4, 18, 27, 41, 28, 11, \
    60, 60, 60, 60, 58, 59}, \
    { //tap2
    6, 52, 19, 38, 32, \
    20, 47, 51, 60, 10, 48, 16, \
    8, 60, 55, 3, 27, 42, 46, 50, \
    45, 34, 12, 60, 60, 60}
};

enum anin_states { sleep, idle, prep, tap };
uint8_t anim_state = idle;
uint32_t idle_timeout_timer = 0;
uint32_t anim_timer = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 6;
uint8_t last_bongo_frame = 12;

void write_bongochar_at_pixel_xy(uint8_t x, uint8_t y, uint8_t data, bool invert) {
    uint8_t i, j, temp;
    for (i = 0; i < 6 ; i++) { // 6 = font width
        temp = pgm_read_byte(&bongofont[data * 6]+i);
        for (j = 0; j < 8; j++) {  // 8 = font height
            if (temp & 0x01) {
                oled_write_pixel(x + i, y + j, !invert);
            } else {
                oled_write_pixel(x + i, y + j, invert);
            }
            temp >>= 1;
        }
    }
}

bool is_key_down(void) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] > 0) {
            return true;
        }
    }
    return false;
}

void eval_anim_state(void) {
    bool key_down;
    key_down = is_key_down();

    switch (anim_state) {
        case sleep:
            if(key_down) { anim_state = tap; }
            break; 
        case idle:
            if(key_down) { anim_state = tap; }
            else if (timer_elapsed32(idle_timeout_timer) >= SLEEP_TIMEOUT) //prep to idle
                {
                    anim_state = sleep;
                    current_idle_frame = 0;
                }
            break;
        case prep:
            if(key_down) { anim_state = tap; }
            else if (timer_elapsed32(idle_timeout_timer) >= IDLE_TIMEOUT) //prep to idle
                {
                    anim_state = idle;
                    current_idle_frame = 0;
                }
            break;
        case tap:
            if (!key_down)
            {
                anim_state = prep;
                idle_timeout_timer = timer_read32();
            }
            break;
        default:
            break;
    }
}

void draw_bongo_table(void) {
    //draws the table edge for bongocat, this edge doesn't change during the animation
    uint8_t i;
    uint8_t y = 31;
    uint8_t j = 0;
    for (i = 17; i < 57; i++) {
        oled_write_pixel(i, y, true); //every five horizontal pixels, move up one pixel to make a diagonal line
        if (j == 4) {
            --y;
            j=0;
        } else {
            j++;
        }
    }

    y=15;
    j=0;
    for (i = 91; i < 128; i++) {

        oled_write_pixel(i, y, true); //every four horizontal pixels, move up one pixel to make a diagonal line
        if (j == 3) {
            --y;
            j=0;
        } else {
            j++;
        }
    }
}

void draw_bongocat_frame(int framenumber) {
    //only redraw if the animation frame has changed
    if (framenumber != last_bongo_frame) {
        last_bongo_frame = framenumber;
        uint8_t i, j, current_bongochar = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < bongo_line_len[i]; j++) {
                write_bongochar_at_pixel_xy(bongo_line_x[i] + j*6, bongo_line_y[i], pgm_read_byte(&bongo_line_data[framenumber][current_bongochar]), false);
                current_bongochar++;
            }
        }
    }

}

bool is_new_tap(void) {
    static matrix_row_t old_matrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    bool new_tap = false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] > old_matrix[i]) { // more 1's detected, there was a new tap
            new_tap = true;
        }
        old_matrix[i] = matrix[i];
    }
    return new_tap;
}

void draw_bongocat(void) {
    static bool already_tapped = false;
    if (is_new_tap()) {
        already_tapped = false;
    };
    eval_anim_state();
    switch (anim_state) {
        case sleep:
            draw_bongocat_frame(4);
            break;
        case idle:       
            draw_bongocat_frame(4 - current_idle_frame);
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                current_idle_frame = (current_idle_frame + 1) % 5;
                anim_timer = timer_read32();
            }
            break;
        case prep:
            draw_bongocat_frame(5);
            already_tapped = false;
            break;
        case tap:
            draw_bongocat_frame(current_tap_frame);
            if (already_tapped == false) {
                if (current_tap_frame == 6) {
                    current_tap_frame = 7;
                }
                else {
                    current_tap_frame = 6;
                }
            }
            already_tapped = true;
            break;
        default:
            draw_bongocat_frame(4);
            already_tapped = false;
            break;

    }
}

// ###########################################################################
#define SNAKE_WALK_DURATION 40
#define SNAKE_BOARD_WIDTH 10
#define SNAKE_BOARD_HEIGHT 42
#define SNAKE_PIXEL_SIZE 3
#define FATNESS 2

typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    DIRECTION_LENGTH,
    DIRECTION_NONE
} Direction;

typedef struct {
    uint8_t x;
    uint8_t y;
} Snake_coordinate;

typedef struct {
    Snake_coordinate coordinate;
    Direction direction;
    uint16_t number;
} Surrounding;

typedef struct {
    Surrounding surroundings[DIRECTION_LENGTH];
} Surroundings;

typedef enum {
    HEAD,
    TAIL
} Snake_part;

typedef struct {
    Snake_coordinate coordinate;
    Snake_part part;
} Draw_step;

bool snake_initialized = false;
bool snake_died = false;

uint16_t snake_board[SNAKE_BOARD_WIDTH][SNAKE_BOARD_HEIGHT];
const uint16_t out_of_board_number = 0;
const uint16_t inside_board_number = 1;

uint16_t current_number;
Snake_coordinate tail_coordinate;
Snake_coordinate head_coordinate;


uint8_t forward_steps = 4;
uint8_t turn_steps = 4;
uint8_t draw_steps_length = 24; //  (forward_steps + turn_steps + turn_steps) * 2
Draw_step draw_steps[24]; // draw_steps[draw_steps_length]
uint8_t draw_index;
uint8_t walk_index;
uint32_t walk_timer;

uint8_t tail_shrink_timeout = 0;


static uint8_t random_number(uint8_t end) {
    return rand() % end;
}

static uint16_t head_number(void) {
    return snake_board[head_coordinate.x][head_coordinate.y];
}

static uint16_t tail_number(void) {
    return snake_board[tail_coordinate.x][tail_coordinate.y];
}

static Direction next_direction(Direction d) {
    switch (d) {
        case UP: return RIGHT;
        case RIGHT: return DOWN;
        case DOWN: return LEFT;
        case LEFT: return UP;
        case DIRECTION_LENGTH: return DIRECTION_LENGTH;
        case DIRECTION_NONE: return DIRECTION_NONE;
    }
    return DIRECTION_NONE;
}

static Direction previous_direction(Direction d) {
    switch (d) {
        case UP: return LEFT;
        case LEFT: return DOWN;
        case DOWN: return RIGHT;
        case RIGHT: return UP;
        case DIRECTION_LENGTH: return DIRECTION_LENGTH;
        case DIRECTION_NONE: return DIRECTION_NONE;
    }
    return DIRECTION_NONE;
}

static bool is_out_of_board(uint8_t x, uint8_t y) {
    return x < 0 || x >= SNAKE_BOARD_WIDTH || y < 0 || y >= SNAKE_BOARD_HEIGHT;
}

static bool is_snake_body(uint8_t x, uint8_t y) {
    return snake_board[x][y] >= tail_number() && snake_board[x][y] <= head_number();
}

static bool can_move(Direction d, uint8_t x, uint8_t y) {
    switch (d) {
        case UP: y++; break;
        case DOWN: y--; break;
        case RIGHT: x++; break;
        case LEFT: x--; break;
        case DIRECTION_LENGTH: break;
        case DIRECTION_NONE: break;
    }
    if (is_out_of_board(x, y)) {
        return false;
    }
    if (is_snake_body(x, y)) {
        return false;
    }
    return true;
}

static uint16_t scan_surrounding_number(uint8_t x, uint8_t y) {
    if (is_out_of_board(x, y)) {
        return out_of_board_number;
    }
    return snake_board[x][y];
}

static Surrounding scan_surrounding(Direction d, uint8_t x, uint8_t y) {
    Surrounding surrounding;
    Snake_coordinate coordinate;
    switch (d) {
        case UP: y++; break;
        case DOWN: y--; break;
        case RIGHT: x++; break;
        case LEFT: x--; break;
        case DIRECTION_LENGTH: break;
        case DIRECTION_NONE: break;
    }
    surrounding.direction = d;
    surrounding.number = scan_surrounding_number(x, y);
    coordinate.x = x;
    coordinate.y = y;
    surrounding.coordinate = coordinate;
    return surrounding;
}

static Surroundings scan_surroundings(uint8_t x, uint8_t y) {
    Surroundings surroundings;

    for (uint8_t dir = 0; dir < DIRECTION_LENGTH; dir++) {
        surroundings.surroundings[dir] = scan_surrounding(dir, x, y);
    }

    return surroundings;
}

static Direction neck_direction(void) {
    Surroundings surroundings = scan_surroundings(head_coordinate.x, head_coordinate.y);
    uint16_t neck_number = head_number() - 1;
    for (uint8_t dir = 0; dir < DIRECTION_LENGTH; dir++) {
        if (surroundings.surroundings[dir].number == neck_number) {
            return surroundings.surroundings[dir].direction;
        }
    }
    return DIRECTION_NONE;
}

static Direction head_direction(void) {
    Direction d = neck_direction();
    switch (d) {
        case UP: return DOWN;
        case DOWN: return UP;
        case RIGHT: return LEFT;
        case LEFT: return RIGHT;
        case DIRECTION_LENGTH: return DIRECTION_LENGTH;
        case DIRECTION_NONE: return DIRECTION_NONE;
    }
    return DIRECTION_NONE;
}

static void set_draw_step(Snake_coordinate c, Snake_part part) {
    Draw_step draw_step;
    
    draw_step.part = part;
    draw_step.coordinate = c;

    draw_steps[draw_index] = draw_step;
    draw_index++;
}

static uint16_t next_number(void) {
    current_number += 1;
    return current_number;
}

static void move_tail(void) {
    if (tail_shrink_timeout > 0) {
        tail_shrink_timeout--;
        return;
    }

    Surroundings surroundings = scan_surroundings(tail_coordinate.x, tail_coordinate.y);
    for (int dir = 0; dir < DIRECTION_LENGTH; dir++) {
        if (surroundings.surroundings[dir].number == tail_number() + 1) {
            set_draw_step(tail_coordinate, TAIL);
            Snake_coordinate c = surroundings.surroundings[dir].coordinate;
            tail_coordinate.x = c.x;
            tail_coordinate.y = c.y;
            return;
        }
    }
}

static void move_head(Direction d) {
    uint8_t x = head_coordinate.x;
    uint8_t y = head_coordinate.y;
    if (can_move(d, x, y)) {
        switch (d) {
            case UP: y++; break;
            case DOWN: y--; break;
            case RIGHT: x++; break;
            case LEFT: x--; break;
            case DIRECTION_NONE: break;
            case DIRECTION_LENGTH: break;
        }
        head_coordinate.x = x;
        head_coordinate.y = y;
        snake_board[x][y] = next_number();
        set_draw_step(head_coordinate, HEAD);
    }
}

static void move(Direction d) {
    if (can_move(d, head_coordinate.x, head_coordinate.y)) {
        move_head(d);
        move_tail();
    }
}

static void move_steps(Direction d, uint8_t steps) {
    for (int i = 0; i < steps; i++) {
        move(d);
    }
}

static void move_forward(uint8_t steps) {
    move_steps(head_direction(), steps);
}

static void turn_left(uint8_t steps) {
    move_steps(previous_direction(head_direction()), steps);
}

static void turn_right(uint8_t steps) {
    move_steps(next_direction(head_direction()), steps);
}

static void turn_random(uint8_t steps) {
    if (random_number(2) == 0) {
        return turn_left(steps);
    }
    return turn_right(steps);
}

static bool locked(void) {
    uint8_t count_moves = 0;
    for (int dir = 0; dir < DIRECTION_LENGTH; dir++) {
        if (can_move(dir, head_coordinate.x, head_coordinate.y)) {
            count_moves++;
        }
    }
    return count_moves == 0;
}

static void snake_render_pixel(uint8_t x, uint8_t y, bool on) {
    uint8_t initial_y = y * SNAKE_PIXEL_SIZE;
    uint8_t initial_x = x * SNAKE_PIXEL_SIZE;
    for (uint8_t i = initial_y; i < initial_y + SNAKE_PIXEL_SIZE; ++i) {
        for (uint8_t j = initial_x; j < initial_x + SNAKE_PIXEL_SIZE; ++j) {
            oled_write_pixel(j, i, on);
        }
    }
}

static void draw_food(void) {
    snake_render_pixel(head_coordinate.x, head_coordinate.y, true);
}

static void make_path_to_food(void) {
    move_forward(forward_steps);
    turn_random(turn_steps);
    turn_random(turn_steps);
    tail_shrink_timeout += FATNESS;
    draw_food();
    if (locked()) {
        snake_died = true;
    }
}

static void clear_board(void) {
    for (uint8_t x = 0; x < SNAKE_BOARD_WIDTH; x++) {
        for (uint8_t y = 0; y < SNAKE_BOARD_HEIGHT; y++) {
            snake_board[x][y] = inside_board_number;
            snake_render_pixel(x, y, false);
        }
    }
}

static void initialize_snake(void) {
    clear_board();
    current_number = inside_board_number + 1;
    snake_board[4][20] = next_number();
    snake_board[4][21] = next_number();
    snake_board[4][22] = next_number();
    snake_render_pixel(4, 20, true);
    snake_render_pixel(4, 21, true);
    snake_render_pixel(4, 22, true);
    head_coordinate.x = 4;
    head_coordinate.y = 22;
    tail_coordinate.x = 4;
    tail_coordinate.y = 20;
    srand(timer_read());
    draw_index = 0;
    walk_index = 0;
    walk_timer = 0;
    tail_shrink_timeout = 0;
    snake_died = false;
    snake_initialized = true;
}

static void finalize_snake(void) {
    snake_initialized = false;
}

static void walk_render(void) {
    if (walk_index >= draw_index) {
        return;
    }
    Draw_step draw_step = draw_steps[walk_index];
    bool on = false;
    if (draw_step.part == HEAD) {
        on = true;
    }
    snake_render_pixel(draw_step.coordinate.x, draw_step.coordinate.y, on);
    walk_index++;
}

static void render_snake(void) {
    if (!snake_initialized) {
        initialize_snake();
        make_path_to_food();
    }
    if (timer_elapsed32(walk_timer) > SNAKE_WALK_DURATION) {
        walk_timer = timer_read32();
        walk_render();
        if (walk_index >= draw_index) {
            if (snake_died) {
                finalize_snake();
                return;
            }
            draw_index = 0;
            walk_index = 0;
            make_path_to_food();
        }
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180;
    }

    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    srand(timer_read32());
    if (!is_keyboard_left()) {
        if (OLED_redraw){
            oled_clear();
            last_bongo_frame = 12; //force a redraw
            draw_bongo_table();
             OLED_redraw = false;
        }
        draw_bongocat();
    } else {
        render_snake();
    }

    return false;
}