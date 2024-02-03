#include QMK_KEYBOARD_H
#include "keymap.h"

// Layer names
#define _QWERTY 0
#define _COLEMAK_DH 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

// Aliases
#define LS MOD_LSFT
#define RS MOD_RSFT

enum CustomKeycodes {
    TOGPERS = SAFE_RANGE,
    MOLSHIFT,
    MORSHIFT
};

int current_layout = _QWERTY;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC     , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , KC_EQL  ,
        KC_TAB     , KC_Q       , KC_W       , KC_E       , KC_R       , KC_T       ,                           KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       , KC_MINS ,
        KC_ESC     , KC_A       , KC_S       , KC_D       , MT(LS,KC_F), KC_G       ,                           KC_H       , MT(RS,KC_J), KC_K       , KC_L       , KC_SCLN    , KC_QUOT ,
        _______    , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B       , _______    , _______    , KC_N       , KC_M       , KC_COMM    , KC_DOT     , KC_SLSH    , _______ ,
                                               KC_LALT    , KC_LCTL    , MOLSHIFT   , KC_SPC     , KC_ENT     , MO(3)      , KC_RALT    , _______
    ),
	[_COLEMAK_DH] = LAYOUT(
        KC_ESC     , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , KC_BSPC ,
        KC_TAB     , KC_Q       , KC_W       , KC_F       , KC_P       , KC_B       ,                           KC_J       , KC_L       , KC_U       , KC_Y       , KC_SCLN    , KC_MINS ,
        KC_ESC     , KC_A       , KC_R       , KC_S       , MT(LS,KC_T), KC_G       ,                           KC_M       , MT(RS,KC_N), KC_E       , KC_I       , KC_O       , KC_QUOT ,
        _______    , KC_Z       , KC_X       , KC_C       , KC_D       , KC_V       , _______    , _______    , KC_K       , KC_H       , KC_COMM    , KC_DOT     , KC_SLSH    , _______ ,
                                               KC_LALT    , KC_LCTL    , MO(2)      , KC_SPC     , KC_ENT     , MO(3)      , KC_RALT    , _______
    ),
    [_LOWER] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , KC_LGUI    , _______    ,                           KC_LEFT    , KC_DOWN    , KC_UP      , KC_RIGHT   , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , KC_DEL     , _______    , _______    , _______
    ),
	[_RAISE] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , KC_1       , KC_2       , KC_3       , MT(LS,KC_4), KC_5       ,                           KC_6       , MT(RS,KC_7), KC_8       , KC_9       , KC_0       , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , KC_BSPC    , _______    , _______    , _______    , _______
    ),
    [_ADJUST] = LAYOUT(
        TOGPERS    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGPERS:
            if (record->event.pressed) {
                switch_persistent_layer();
            }
            break;
        case MOLSHIFT:
            uint16_t press_time = record->event.time;
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
                uint16_t time_elapsed = timer_elapsed(press_time); // todo global var I think
                if (time_elapsed < TAPPING_TERM) {
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                }
            }
            break;
        case MORSHIFT:
            break;
    }
    return true;
}

void set_persistent_default(int layer) {
    set_single_persistent_default_layer(layer);
    current_layout = layer;
}

void switch_persistent_layer(void) {
    if (current_layout == _QWERTY) {
        set_persistent_default(_COLEMAK_DH);
    } else {
        set_persistent_default(_QWERTY);
    }
}