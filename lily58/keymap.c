#include QMK_KEYBOARD_H

// Layer names
#define _QWERTY 0
#define _COLEMAK_DH 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

// Aliases
#define LT_LOW LT(_LOWER, KC_SPC)
#define LT_HI LT(_RAISE, KC_ENT)

int current_layout = _QWERTY;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                     KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_MINS,
        KC_ESC  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,                     KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , _______ , _______ , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                                      KC_LGUI , KC_LALT , KC_LCTL , LT_LOW  , LT_HI   , KC_BSPC , KC_RALT , _______
    ),
	[_COLEMAK_DH] = LAYOUT(
        KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
        KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    ,                     KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_MINS,
        KC_ESC  , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,                     KC_M    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT,
        KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , _______ , _______ , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                                      KC_LGUI , KC_LALT , KC_LCTL , LT_LOW  , LT_HI   , KC_BSPC , KC_RALT , _______
    ),
	[_LOWER] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ , _______ , _______ , KC_DEL  , _______ , _______
    ),
    [_RAISE] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
    [_ADJUST] = LAYOUT(
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SPL:
//             if (record->event.pressed) {
//                 switch_persistent_layer();
//             } else {
//                 // when keycode QMKBEST is released
//             }
//         break;
//     }
//     return true;
// }

// void switch_persistent_layer() {
//     if (current_layout == _QWERTY) {
//         set_persistent_default(_COLEMAK_DH);
//     } else {
//         set_persistent_default(_QWERTY);
//     }
// }