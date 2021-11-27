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

// Left-hand home row mods - Base Layer
#define GUI_A   LGUI_T(KC_A)
#define ALT_R   LALT_T(KC_R)
#define CTRL_S  LCTL_T(KC_S)
#define SHIFT_T LSFT_T(KC_T)

// Right-hand home row mods  - Base Layer
#define SHIFT_N RSFT_T(KC_N)
#define CTRL_E  RCTL_T(KC_E)
#define ALT_I   LALT_T(KC_I)
#define GUI_O   RGUI_T(KC_O)

// Left-hand home row mods - Layer 1
#define GU_EXLM LGUI_T(KC_EXLM)
#define AL_AT   LALT_T(KC_AT)
#define CT_HASH LCTL_T(KC_HASH)
#define SH_DLR  LSFT_T(KC_DLR)

// Right-hand home row mods - Layer 1
#define SH_AMPR RSFT_T(KC_AMPR)
#define CT_ASTR RCTL_T(KC_ASTR)
#define AL_LPRN LALT_T(KC_LPRN)
#define GU_RPRN RGUI_T(KC_RPRN)

// Left-hand home row mods - Layer 2
#define GUI_F5   LGUI_T(KC_F5)
#define ALT_F6   LALT_T(KC_F6)
#define CTRL_F7  LCTL_T(KC_F7)
#define SHIFT_F8 LSFT_T(KC_F8)

// Right-hand home row mods - Layer 2
#define S_LBRC RSFT_T(KC_LBRC)
#define C_RBRC RCTL_T(KC_RBRC)
#define A_LCBR LALT_T(KC_LCBR)
#define G_RCBR RGUI_T(KC_RCBR)

// Layers
#define LT2_SPC LT(2,KC_SPC)
#define LT1_ENT LT(1,KC_ENT)

enum layers {
  _COLEMAK_DMH,
  _SYMBOLS,
  _PROGRAMMING,
  _SYSTEM,
  _GAMER,
  _GAMER_NUMBERS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak-DHm
     * ,-----------------------------------------------------------------------------------.
     * |  Q   |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  |   ;  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | GUI/A| ALT/R| CTL/S| SFT/T|   G  |      |      |   M  | SFT/N| CTL/E| ALT/I| GUI/O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      | Tab  | Esc  |L2/Spc|             |L1/ENT| BSCP | DEL  |      |      |
     * `-----------------------------------------------------------------------------------'
     */

	[_COLEMAK_DMH] = LAYOUT_planck_mit(
        KC_Q,    KC_W,    KC_F,   KC_P,    KC_B,    XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        GUI_A,   ALT_R,   CTRL_S, SHIFT_T, KC_G,    XXXXXXX, XXXXXXX, KC_M,    SHIFT_N, CTRL_E,  ALT_I,   GUI_O,
        KC_Z,    KC_X,    KC_C,   KC_D,    KC_V,    XXXXXXX, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
        XXXXXXX, XXXXXXX, KC_TAB, KC_ESC,  LT2_SPC,      XXXXXXX,     LT1_ENT, KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
    ),


    /* Symbols
     * ,-----------------------------------------------------------------------------------.
     * |  1   |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  !   |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      | MO(3)|             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_SYMBOLS] = LAYOUT_planck_mit(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        GU_EXLM, AL_AT,   CT_HASH, SH_DLR,  KC_PERC, _______, _______, KC_CIRC, SH_AMPR, CT_ASTR, AL_LPRN, GU_RPRN,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        _______, _______, _______, _______, MO(3),        _______,     _______, _______, _______, _______, _______
    ),

    /* Programming
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |PRT/SC|      |      |   `  |   '  |   "  |   \  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F5  |  F6  |  F7  |  F8  |      |      |      |   ~  |   [  |   ]  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F9  |  F10 |  F11 |  F12 |      |      |      |      |   -  |   _  |   =  |   +  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             | MO(3)|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_PROGRAMMING] = LAYOUT_planck_mit(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_PSCR, _______, _______, KC_GRV,  KC_QUOT, KC_DQUO, KC_BSLS, KC_PIPE,
        GUI_F5,  ALT_F6,  CTRL_F7, SHIFT_F8, _______, _______, _______, KC_TILD, S_LBRC,  C_RBRC,  A_LCBR,  G_RCBR,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______, _______, _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS,
        _______, _______, _______, _______,  _______,      _______,     MO(3),   _______, _______, _______, _______
    ),

    /* System
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      | RESET|      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      | TO(4)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

	[_SYSTEM] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(4),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    /* Gamer
     * ,-----------------------------------------------------------------------------------.
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | SHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | CTRL |      |      | ALT  | MO(5)|    Space    |  GUI |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

	[_GAMER] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,  KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,  KC_H, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,  KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT, MO(5),    KC_SPC,   KC_LGUI, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Gamer Numbers
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

	[_GAMER_NUMBERS] = LAYOUT_planck_mit(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,       _______,    _______, _______, _______, _______, _______
    )
};
