#include "keymap.h"

enum Layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _COLEMAK_DH_SHIFTED
};
uint8_t current_layout = _QWERTY;

// symbols: ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~ (32)
// ! " # $ % & ' ( ) * + - = @ [ \ ] ^ _ ` { | } ~ < > ? : (on symbol layer)

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
    [_COLEMAK_DH_SHIFTED] = LAYOUT(
        _______    , KC_1       , KC_2       , KC_3       , KC_4       , KC_5       ,                           KC_6       , KC_7       , KC_8       , KC_9       , KC_0       , _______ ,
        KC_TAB     , KC_Q       , KC_W       , KC_F       , KC_P       , KC_B       ,                           KC_J       , KC_L       , KC_U       , KC_Y       , KC_SCLN    , _______ ,
        _______    , LSFT(KC_A) , KC_R       , KC_S       , KC_T       , KC_G       ,                           KC_M       , KC_N       , KC_E       , KC_I       , KC_O       , _______ ,
        _______    , KC_Z       , KC_X       , KC_C       , KC_D       , KC_V       , _______    , _______    , KC_K       , KC_H       , KC_COMM    , KC_DOT     , KC_SLSH    , _______ ,
                                               KC_LALT    , KC_LCTL    , MOLSHIFT   , KC_SPC     , KC_BSPC    , MORSHIFT   , KC_RCTL    , KC_RALT
    ),
    [_LOWER] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , KC_7       , KC_8       , KC_9       , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , KC_4       , KC_5       , KC_6       , KC_0       ,                           KC_LEFT    , KC_DOWN    , KC_UP      , KC_RIGHT   , _______    , _______ ,
        _______    , _______    , KC_1       , KC_2       , KC_3       , _______    , _______    , _______    , KC_LGUI    , KC_ESC     , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , KC_DEL     , _______    , _______    , _______
    ),
    [_RAISE] = LAYOUT(
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , KC_PERC    , KC_QUOT    , KC_LBRC    , KC_RBRC    , KC_PIPE    ,                           _______    , KC_HASH    , KC_MINUS   , KC_ASTR    , KC_BSLS    , _______ ,
        _______    , KC_AT      , KC_DQUO    , KC_LPRN    , KC_RPRN    , KC_AMPR    ,                           KC_CIRC    , KC_EQUAL   , KC_EXLM    , KC_PLUS    , KC_COLN    , _______ ,
        _______    , KC_DLR     , KC_GRAVE   , KC_LCBR    , KC_RCBR    , KC_TILD    , _______    , _______    , _______    , KC_UNDS    , KC_LT      , KC_GT      , KC_QUES    , _______ ,
                                               _______    , _______    , _______    , KC_ENT     , _______    , _______    , _______    , _______
    ),
    [_ADJUST] = LAYOUT(
        TOGPERS    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        TOGGMNG    , _______    , _______    , _______    , _______    , _______    ,                           _______    , KC_VOLD    , KC_VOLU    , _______    , _______    , _______ ,
        _______    , KC_F1      , KC_F2      , KC_F3      , KC_F4      , KC_F5      ,                           KC_F6      , KC_F7      , KC_F8      , KC_F9      , KC_F10     , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
    ),
    [_GAMING] = LAYOUT(
        KC_ESC     , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        _______    , _______    , _______    , _______    , _______    , _______    ,                           _______    , _______    , _______    , _______    , _______    , _______ ,
        KC_LSFT    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______ ,
                                               _______    , _______    , _______    , _______    , _______    , _______    , _______    , _______
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    clear_weak_mods();
    
    if (record->event.pressed && (layer_state_is(_LOWER) || layer_state_is(_RAISE))) {
        hasSentLayeredKeycode = true; 
    }

    switch (keycode) {
        case KC_A ... KC_Z:
            if (shouldShiftNextKey) {
                shouldShiftNextKey = false;

                if (timer_elapsed(lsft_timer) < ONESHOT_TIMEOUT) {
                    add_weak_mods(MOD_BIT(KC_LSFT));
                }

                if (timer_elapsed(rsft_timer) < ONESHOT_TIMEOUT) {
                    add_weak_mods(MOD_BIT(KC_RSFT));
                }
            }
            break;
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
            mod_tap_layer_hold(_LOWER, record, lsft_keycode, &lsft_count, &lsft_timer);
            break;
        case MORSHIFT:
            mod_tap_layer_hold(_RAISE, record, rsft_keycode, &rsft_count, &rsft_timer);
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
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

// tap: oneshot layer the taplayer
// hold: hold the holdLayer
// double tap and hold: hold the keycode
void mod_tap_layer_hold(uint8_t tapLayer, keyrecord_t *record, uint16_t keycode, uint8_t *count, uint16_t *timer) {
    uint16_t time_elapsed = timer_elapsed(*timer);

    if (record->event.pressed) {
        hasSentLayeredKeycode = false;
        if (time_elapsed > TAPPING_TERM) {
            *count = 0;
        }

        *timer = record->event.time;
        *count += 1;
        bool isShiftHeld = false;

        if (*count == 2) {
            // double tap hold
            register_code(keycode);
            isShiftHeld = true;
        }

        if (!isShiftHeld) {
            // regular hold
            layer_on(tapLayer);
        }

    } else {
        layer_off(tapLayer);

        if (time_elapsed < TAPPING_TERM && *count == 1 && !hasSentLayeredKeycode) {
            // shift the next key
            shouldShiftNextKey = true;
        }

        if (*count == 2) {
            // cancel double tap hold
            unregister_code(keycode);
        }
    }
}
