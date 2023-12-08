#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ W │ L │ R │ B │ Z │       │: ;│ Q │ U │ D │ J │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ S │ H │ N │ T │, (│       │. )│ A │ E │ O │ I │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ F │ M │ V │ C │/ \│       │ G │ P │ X │ K │ Y │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │BSP├───┐           ┌───┤ENT│
      *           └───┤SHT├───┐   ┌───┤SPC├───┘
      *               └───┤DEL│   │ OS├───┘
      *                   └───┘   └───┘
      */
    [0] = LAYOUT_split_3x5_3(
        KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,                              KC_COLN,    KC_Q,    KC_U,    KC_D,    KC_J,
        KC_S,    KC_H,    KC_N,    KC_T,    KC_COMMA,                          KC_DOT,     KC_A,    KC_E,    KC_O,    KC_I,
        KC_F,    KC_M,    KC_V,    KC_C,    KC_SLASH,                          KC_G,       KC_P,    KC_X,    KC_K,    KC_Y,
                                   KC_BSPC, KC_LEFT_SHIFT, KC_DELETE,          KC_LEFT_GUI,  KC_SPC,  KC_ENT
    )
};

const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_LPRN);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_RPRN);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&colon_key_override,
	&comma_key_override,
	&dot_key_override,
	&slash_key_override,
	NULL // Null terminate the array of overrides!
};
