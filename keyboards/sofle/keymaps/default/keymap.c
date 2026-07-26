/* Copyright 2022 Khoa Truong <foureight84@gmail.com>
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
#include <string.h>
#include <math.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_MOUSE,
    KC_UNDSC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [_QWERTY] = LAYOUT(/* QWERTY
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | Bspc |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        | Tab  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   |  \   |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        | Esc  |  A   |  S   |  D   |  F   |  G   |-------.    ,-------|  H   |  J   |  K   |  L   |  ;   |  '   |
        |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        |LSFT  |  Z   |  X   |  C   |  V   |  B   |-------|    |-------|  N   |  M   |  ,   |  .   |  /   |RSFT |
        `-----------------------------------------/       /     \      \-----------------------------------------'
                   |LGUI |LALT |LCTL |LOWER | ENT          \ SPC  |RAISE|RCTL |RALT |RGUI
        */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                   KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_ENT,        KC_SPC,  KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI
    ),
    // clang-format on

    // clang-format off
    [_COLEMAK] = LAYOUT(/* COLEMAK
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  `   |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        | Esc  |  Q   |  W   |  F   |  P   |  G   |                    |  J   |  L   |  U   |  Y   |  ;   | Bspc |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        | Tab  |  A   |  R   |  S   |  T   |  D   |-------.    ,-------|  H   |  N   |  E   |  I   |  O   |  '   |
        |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        |LSFT  |  Z   |  X   |  C   |  V   |  B   |-------|    |-------|  K   |  M   |  ,   |  .   |  /   |RSFT |
        `-----------------------------------------/       /     \      \-----------------------------------------'
                   |LGUI |LALT |LCTL |LOWER | ENT          \ SPC  |RAISE|RCTL |RALT |RGUI
        */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_ENT,        KC_SPC,  KC_RAISE, KC_RALT, KC_RALT, KC_RCTL

    ),
    // clang-format on

    // clang-format off

    [_LOWER] = LAYOUT(/* LOWER
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        | F1   | F2   | F3   | F4   | F5   | F6   |                    | F7   | F8   | F9   | F10  | F11  | F12  |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   |  `   |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |MOUSE |  !   |  @   |  #   |  $   |  %   |-------.    ,-------|  ^   |  &   |  *   |  (   |  )   |  |   |
        |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        |LSFT  |  =   |  -   |  +   |  {   |  }   |-------|    |-------|  [   |  ]   |  ;   |  :   |  \   |LSFT |
        `-----------------------------------------/       /     \      \-----------------------------------------'
                   |     |     |     |LOWER | ENT          \ SPC  |RAISE|     |     |
        */
        KC_F12,   KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,
        KC_GRV,   _______, KC_PPLS,  KC_EQL,  _______, KC_LCBR,                     KC_RCBR, KC_P7,  KC_P8,  KC_P9,  KC_PAST, KC_BSPC,
        KC_MOUSE, _______, KC_MINS,  _______, _______, KC_LBRC,                     KC_RBRC, KC_P4,  KC_P5,  KC_P6,  KC_PSLS, KC_PENT,
        KC_LSFT,  _______, KC_UNDSC, KC_COLN, _______, KC_LPRN, KC_MUTE,   XXXXXXX, KC_RPRN, KC_P1,  KC_P2,  KC_P3,  KC_CAPS, KC_NUM,

                    _______,_______,_______,_______,_______,                       _______,_______,KC_PEQL, KC_P0, KC_PDOT
    ),
    // clang-format on

    // clang-format off
    [_RAISE] = LAYOUT(

        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                          KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, _______, _______, KC_UP,   _______,  _______,                        _______,  KC_PRVWD, KC_UP,   KC_NXTWD, KC_PGUP, KC_BSPC,
        KC_LALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                        _______,  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGDN, KC_BSPC,
        _______, _______, _______, _______, _______, _______, KC_MUTE,      _______,  KC_DEL,   KC_HOME,  _______, KC_END,   _______, _______,

                   _______,_______,_______,_______,_______,                           _______,_______,_______,_______,_______
    ),
    // clang-format on

    // clang-format off
    [_ADJUST] = LAYOUT(/* ADJUST
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |RST   |      |      |      |      |      |                    |      |      |      |      |      |      |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |      |      |MACWIN|      |      |      |-------.    ,-------|      |VOLD |MUTE |VOLU |      |      |
        |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------|
        |      |      |      |      |      |      |-------|    |-------|      |PREV |PLAY |NEXT |      |      |
        `-----------------------------------------/       /     \      \-----------------------------------------'
                          |     |     |     |     | ENT          \ SPC  |     |     |     |
        */
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, DM_RSTP, CG_TOGG, XXXXXXX, DM_PLY1,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,     XXXXXXX,XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______
    ),

    // clang-format on

    // clang-format off
    [_MOUSE] = LAYOUT(/* MOUSE
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        |      |      |      |      |      |      |-------.    ,-------| BTN1 | BTN2 |      |      |      |      |
        |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
        |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
        `-----------------------------------------/       /     \      \-----------------------------------------'
                   |     |     |     |     | ENT          \ SPC  |     |     |     |
        */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, MS_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN1, MS_BTN3,                      XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_MUTE,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

                   _______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______
    )
    // clang-format on

};

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

/* Animation bit by j-inc https://github.com/qmk/qmk_firmware/tree/master/keyboards/kyria/keymaps/j-inc */
// WPM-responsive animation stuff here
#    define IDLE_FRAMES 5
#    define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#    define TAP_FRAMES 2
#    define TAP_SPEED 60 // above this wpm value typing animation to triggere

#    define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#    define ANIM_SIZE 320 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Implementation credit j-inc(/James Incandenza), pixelbenny, and obosob.
// Bongo cat images changed and adapted for sofle keyboard oled size.
// Original gif can be found here: https://www.pixilart.com/art/bongo-cat-bd2a8e9323aa705
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {{
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f, 0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80, 0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05, 0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19, 0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80, 0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
    }};
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE]   = {
        {
            0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40, 0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19, 0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80, 0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f, 0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80, 0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05, 0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80, 0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01},
    };

    // assumes 1 frame prep stage
    void animation_phase(void) {
        if (get_current_wpm() <= IDLE_SPEED) {
            oled_write_raw_P(idle[0], ANIM_SIZE);
        }
        if (get_current_wpm() >= TAP_SPEED) {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
        }
    }
    if (get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_anim();
        oled_set_cursor(1, 12);
        oled_write_P(PSTR("WPM"), false);
        oled_set_cursor(1, 13);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
            }
            return false;
        case KC_UNDSC:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LSFT));
                register_code(KC_MINS);
            } else {
                unregister_mods(mod_config(MOD_LSFT));
                unregister_code(KC_MINS);
            }
            break;
    }
    return true;
}

#define SCROLL_MULTIPLIER 2

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (!layer_state_is(_MOUSE)) {
        mouse_report.h = SCROLL_MULTIPLIER * mouse_report.x;
        mouse_report.v = SCROLL_MULTIPLIER * mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][NUM_DIRECTIONS] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, [_LOWER] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)}, [_RAISE] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)}, [_ADJUST] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)}, [_MOUSE] = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
};
#endif
