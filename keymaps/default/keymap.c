#include QMK_KEYBOARD_H
#include <stdio.h>

#define _HALMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUMBERS 3

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
      *           │OS ├───┐           ┌───┤ESC│
      *           └───┤SHT├───┐   ┌───┤SPC├───┘
      *               └───┤ENT│   │BSP├───┘
      *                   └───┘   └───┘
      */
    [_HALMAK] = LAYOUT_split_3x5_3(
        KC_W,    KC_L,    KC_R,    KC_B,         KC_Z,                                KC_COLN, KC_Q,    KC_U,    KC_D,    KC_J,
        KC_S,    KC_H,    KC_N,    KC_T,         KC_COMMA,                            KC_DOT,  KC_A,    KC_E,    KC_O,    KC_I,
        KC_F,    KC_M,    KC_V,    KC_C,         KC_SLASH,                            KC_G,    KC_P,    KC_X,    KC_K,    KC_Y,
                                   KC_LEFT_GUI,  KC_LEFT_SHIFT, MT(MOD_LCTL, KC_ENT),          KC_BSPC, KC_SPC,  MT(MOD_LALT, KC_ESC)
    ),
    /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │HME│PGU│PGD│END│   │       │   │HME│PGD│PGU│END│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ⬅ │⬆  │ ⬇ │ ➡ │   │       │   │ ⬅ │ ⬇ │ ⬆ │ ➡ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_NAV] = LAYOUT_split_3x5_3(
        KC_HOME,   KC_PAGE_UP, KC_PAGE_DOWN, KC_END,   KC_TRNS,                               KC_TRNS, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,
        KC_LEFT,   KC_UP,      KC_DOWN,      KC_RIGHT, KC_TRNS,                               KC_TRNS, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT,
        KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS,
                                             KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │ + │ 4 │ 5 │ 6 │/ *│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │ - │ 1 │ 2 │ 3 │ . │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_NUMBERS] = LAYOUT_split_3x5_3(
        KC_HOME,   KC_PAGE_UP, KC_PAGE_DOWN, KC_END,   KC_TRNS,                               KC_TRNS, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,
        KC_LEFT,   KC_UP,      KC_DOWN,      KC_RIGHT, KC_TRNS,                               KC_TRNS, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT,
        KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS,
                                             KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS
    )
};

const key_override_t colon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COLN, KC_SCLN, ~_HALMAK);
const key_override_t comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_LPRN, ~_HALMAK);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_RPRN, ~_HALMAK);
const key_override_t slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH, ~_HALMAK);
const key_override_t numbers_slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_KP_ASTERISK, ~_NUMBERS);
const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE, ~_HALMAK | ~_NAV | ~_QWERTY | ~_NUMBERS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&colon_key_override,
	&comma_key_override,
	&dot_key_override,
	&slash_key_override,
	&numbers_slash_key_override,
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM halmak_layer_combo[] = {KC_T, KC_A, COMBO_END};
const uint16_t PROGMEM nav_layer_combo[] = {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM numbers_layer_combo[] = {KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM qwerty_layer_combo[] = {KC_T, KC_Q, COMBO_END};

const uint16_t PROGMEM osl_nav_layer_combo[] = {KC_T, KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM osl_numbers_layer_combo[] = {KC_T, KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM osl_qwerty_layer_combo[] = {KC_T, KC_N, KC_Q, COMBO_END};

combo_t key_combos[] = {
    COMBO(halmak_layer_combo, TO(_HALMAK)),
    COMBO(nav_layer_combo, TO(_NAV)),
    COMBO(numbers_layer_combo, TO(_NUMBERS)),
    COMBO(qwerty_layer_combo, TO(_QWERTY)),
    COMBO(osl_nav_layer_combo, OSL(_NAV)),
    COMBO(osl_numbers_layer_combo, OSL(_NUMBERS)),
    COMBO(osl_qwerty_layer_combo, OSL(_QWERTY)),
};

