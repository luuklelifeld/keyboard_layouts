
#include "keymap.h"

// Layer names
#define _QWERTY 0
#define _COLEMAK_DH 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _GAMING 5

uint8_t current_layout = _QWERTY;

// symbols: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ (32)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        _______    , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , _______ ,
        KC_TAB     , KC_Q       , KC_W       , KC_E       , KC_R       , KC_T       ,                           KC_Y       , KC_U       , KC_I       , KC_O       , KC_P       , _______ ,
        _______    , KC_A       , KC_S       , KC_D       , KC_F       , KC_G       ,                           KC_H       , KC_J       , KC_K       , KC_L       , KC_SCLN    , _______ ,
        _______    , KC_Z       , KC_X       , KC_C       , KC_V       , KC_B       , _______    , _______    , KC_N       , KC_M       , KC_COMM    , KC_DOT     , KC_SLSH    , _______ ,
                                               KC_LALT    , KC_LCTL    , MOLSHIFT   , KC_SPC     , KC_BSPC    , MORSHIFT   , KC_RCTL    , KC_RALT
    ),
	[_COLEMAK_DH] = LAYOUT(
        _______    , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , _______ ,
        KC_TAB     , KC_Q       , KC_W       , KC_F       , KC_P       , KC_B       ,                           KC_J       , KC_L       , KC_U       , KC_Y       , KC_SCLN    , _______ ,
        _______    , KC_A       , KC_R       , KC_S       , KC_T       , KC_G       ,                           KC_M       , KC_N       , KC_E       , KC_I       , KC_O       , _______ ,
        _______    , KC_Z       , KC_X       , KC_C       , KC_D       , KC_V       , _______    , _______    , KC_K       , KC_H       , KC_COMM    , KC_DOT     , KC_SLSH    , _______ ,
                                               KC_LALT    , KC_LCTL    , MOLSHIFT   , KC_SPC     , KC_BSPC    , MORSHIFT   , KC_RCTL    , KC_RALT
    ),
    [_LOWER] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , KC_HASH    , KC_LBRC    , KC_RBRC    , _______    ,                           _______    , KC_UNDS    , KC_MINUS   , KC_PLUS    , KC_ASTR    , _______ ,
        _______    , KC_EXLM    , KC_AT      , KC_LPRN    , KC_RPRN    , KC_EQUAL   ,                           KC_LEFT    , KC_DOWN    , KC_UP      , KC_RIGHT   , KC_COLN    , _______ ,
        _______    , _______    , KC_TILD    , KC_LCBR    , KC_RCBR    , KC_BSLS    , _______    , _______    , _______    , KC_ESC     , KC_GT      , KC_LT      , KC_QUES    , _______ ,
                                               _______    , _______    , _______    , _______    , KC_DEL     , _______    , _______    , _______
    ),
	[_RAISE] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , KC_CIRC    , KC_PERC    , KC_DLR     , _______    ,                           _______    , KC_AMPR    , KC_PIPE    , _______    , _______    , _______ ,
        _______    , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , _______ ,
        _______    , _______    , KC_GRAVE   , KC_DQUO    , KC_QUOT    , _______    , _______    , _______    , _______    , KC_LGUI    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , KC_ENT     , _______    , _______    , _______    , _______
    ),
    [_ADJUST] = LAYOUT(
        TOGPERS    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        TOGGMNG    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
    ),
    [_GAMING] = LAYOUT(
        KC_ESC     , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        KC_LSFT    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
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
        case TOGGMNG:
            if (record->event.pressed) {
                layer_invert(_GAMING);
            }
            break;
        case MOLSHIFT:
            mod_tap_layer_hold(KC_LSFT, _LOWER, record, &lsft_timer);
            break;
        case MORSHIFT:
            mod_tap_layer_hold(KC_RSFT, _RAISE, record, &rsft_timer);
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case MOLSHIFT:
        case MORSHIFT:
            return true;

        default:
            return false; 
    }
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