#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B,                                        KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_NO,
        KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,        KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_NO,
        KC_NO, KC_Z, ALGR_T(KC_X), KC_C, KC_D, KC_V,                                KC_K, KC_H, KC_COMM, ALGR_T(KC_DOT), KC_SLSH, KC_NO,
        LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),                   LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL)
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, CW_TOGG, KC_NO,
        KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO, KC_NO,         KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
        KC_NO, KC_NO, KC_NO,                                KC_ENT, KC_BSPC, KC_DEL
    ),
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
        KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO, KC_NO,         KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
        KC_NO, KC_NO, KC_NO,                                KC_BTN2, KC_BTN1, KC_BTN3
    ),
    [_MEDIA] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_TOG, KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  KC_NO,
        KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,                                KC_MSTP, KC_MPLY, KC_MUTE
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, KC_LBRC, KC_7,  KC_8, KC_9, KC_RBRC,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,               KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,               KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_DOT, KC_0, KC_MINS,                                  KC_NO, KC_NO, KC_NO
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,          KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_LPRN, KC_RPRN, KC_UNDS,                                 KC_NO, KC_NO, KC_NO
    ),
    [_FUN] = LAYOUT_split_3x6_3(
        KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,        KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_APP, KC_SPC, KC_TAB,                             KC_NO, KC_NO, KC_NO
    )
};
// clang-format on

// lets me use regular caps when holding down SHIFT, otherwise use smart caps
// toggle
const key_override_t capsword_key_override =
    ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t *key_overrides[] = {&capsword_key_override};

// custom tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_N):
        case LSFT_T(KC_T):
            return TAPPING_TERM - 45;
        case LT(_SYM, KC_ENTER):
        case LT(_NUM, KC_BSPC):
            return TAPPING_TERM - 35;
        case LGUI_T(KC_A):
        case LGUI_T(KC_O):
        case LALT_T(KC_R):
        case LALT_T(KC_I):
            return TAPPING_TERM + 35;
        default:
            return TAPPING_TERM;
    }
}

// The LEDs are so bright on the Corne, so we set the intensity pretty low.
#define LED_INTENSITY 0x16
// Define the usual colors using the desired LED_INTENSITY defined above.
#define RGB_DARK_BLUE 0x00, 0x00, LED_INTENSITY
#define RGB_DARK_CYAN 0x00, LED_INTENSITY, LED_INTENSITY
#define RGB_DARK_GREEN 0x00, LED_INTENSITY, 0x00
#define RGB_DARK_MAGENTA LED_INTENSITY, 0x00, LED_INTENSITY
#define RGB_DARK_RED LED_INTENSITY, 0x00, 0x00
#define RGB_DARK_WHITE LED_INTENSITY, LED_INTENSITY, LED_INTENSITY
#define RGB_DARK_YELLOW LED_INTENSITY, LED_INTENSITY, 0x00

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // should be left
    if (is_keyboard_master()) {
        for (int i = 0; i < 27; i++) {
            rgb_matrix_set_color(i, RGB_DARK_CYAN);
        }
    } else {  // should be right
        for (int i = 27; i < 54; i++) {
            rgb_matrix_set_color(i, RGB_DARK_CYAN);
        }
        rgb_matrix_set_color(48, RGB_DARK_MAGENTA);
    }
    return true;
}
