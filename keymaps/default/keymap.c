#include QMK_KEYBOARD_H
#include <stdio.h>

#define _HALMAK 0
#define _QWERTY 1
#define _NAV 2
#define _NUM 3
#define _ANKI 4

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
        KC_S,    KC_H,    KC_N,    KC_T,         MT(MO(_NAV), KC_COMMA),                            KC_DOT,  KC_A,    KC_E,    KC_O,    KC_I,
        KC_F,    KC_M,    KC_V,    KC_C,         MT(MO(_NUM), KC_SLASH),                            KC_G,    KC_P,    KC_X,    KC_K,    KC_Y,
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
      * │   │   │   │   │   │       │+ =│ 4 │ 5 │ 6 │/ *│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │ - │ 1 │ 2 │ 3 │ . │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      */
    [_NUM] = LAYOUT_split_3x5_3(
        KC_1,      KC_2,       KC_3,         KC_4,     KC_5,                                  KC_6,    KC_7,    KC_8, KC_9, KC_0,
        KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,                               KC_PPLS, KC_4,    KC_5, KC_6, KC_PSLS,
        KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_TRNS,                               KC_MINS, KC_1,    KC_2, KC_3, KC_DOT,
                                             KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ A │ E │ B │ D │   │       │   │ D │ B │ E │ A │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ 4 │ 3 │ 2 │ 1 │ Y │       │ Y │ 1 │ 2 │ 3 │ 4 │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │ / │       │ / │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │   ├───┐           ┌───┤   │
      *           └───┤SPC├───┐   ┌───┤SPC├───┘
      *               └───┤UNDO   │UNDO───┘
      *                   └───┘   └───┘
      */
    [_ANKI] = LAYOUT_split_3x5_3(
        KC_A,   KC_E,    KC_B,      KC_D,  KC_TRNS,                                            KC_TRNS, KC_D, KC_B,      KC_E,    KC_A,
        KC_4,   KC_3,    KC_2,      KC_1,  KC_Y,                                               KC_Y, KC_1, KC_2,      KC_3,    KC_4,
        KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,  KC_SLASH,                               KC_SLASH, KC_TRNS, KC_TRNS,      KC_TRNS,    KC_TRNS,
                                             KC_TRNS,  KC_SPC, LCTL(KC_Z),             LCTL(KC_Z), KC_SPC, KC_TRNS
    )
};

const key_override_t colon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COLN, KC_SCLN, ~_HALMAK);
const key_override_t comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_LPRN, ~_HALMAK);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_RPRN, ~_HALMAK);
const key_override_t slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_BACKSLASH, ~_HALMAK);
const key_override_t numbers_slash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PSLS, KC_KP_ASTERISK, ~_NUM);
const key_override_t numbers_plus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PPLS, KC_EQUAL, ~_NUM);
const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE, ~_HALMAK | ~_NAV | ~_QWERTY | ~_NUM);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&colon_key_override,
	&comma_key_override,
	&dot_key_override,
	&slash_key_override,
	&numbers_slash_key_override,
	&numbers_plus_key_override,
	&delete_key_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM nav_layer_combo[] = {KC_COLN, KC_S, COMBO_END};
const uint16_t PROGMEM numbers_layer_combo[] = {KC_COLN, KC_W, COMBO_END};

const uint16_t PROGMEM halmak_layer_combo[] = {KC_DOT, KC_S, COMBO_END};
const uint16_t PROGMEM qwerty_layer_combo[] = {KC_DOT, KC_W, COMBO_END};
const uint16_t PROGMEM anki_layer_combo[] = {KC_DOT, KC_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(nav_layer_combo, TO(_NAV)),
    COMBO(numbers_layer_combo, TO(_NUM)),
    COMBO(halmak_layer_combo, TO(_HALMAK)),
    COMBO(qwerty_layer_combo, TO(_QWERTY)),
    COMBO(anki_layer_combo, TO(_ANKI)),
};
