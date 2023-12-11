#include QMK_KEYBOARD_H
#include <stdio.h>

#define _HALMAK 0
#define _QWERTY 1

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
    [_HALMAK] = LAYOUT_split_3x5_3(
        KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,                              KC_COLN,      KC_Q,    KC_U,    KC_D,    KC_J,
        KC_S,    KC_H,    KC_N,    KC_T,    KC_COMMA,                          KC_DOT,       KC_A,    KC_E,    KC_O,    KC_I,
        KC_F,    KC_M,    KC_V,    KC_C,    KC_SLASH,                          KC_G,         KC_P,    KC_X,    KC_K,    KC_Y,
                                   KC_ESC,  KC_LEFT_SHIFT, KC_ENT, KC_LEFT_GUI,  KC_SPC,  KC_BSPC
    ),
    /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤BSP│
      *           └───┤SHT├───┐   ┌───┤SPC├───┘
      *               └───┤ENT│   │ OS├───┘
      *                   └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_BSPC, KC_LEFT_SHIFT, KC_DELETE,          KC_LEFT_GUI,  KC_SPC,  KC_ENT
    )
};

const key_override_t colon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COLN, KC_SCLN, ~0);
const key_override_t comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_LPRN, ~0);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_RPRN, ~0);
const key_override_t slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH, ~0);
const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE, ~0);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&colon_key_override,
	&comma_key_override,
	&dot_key_override,
	&slash_key_override,
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

