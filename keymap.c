#include QMK_KEYBOARD_H

// Set layer names for readability
#define _QWERTY 0
#define _COLEMAK_DH 1
#define _F_ROW 2
#define _FUNCTIONS 3

enum tapdances {
    TD_LAYERS
};

// Variables for keeping track of stuff (obviously)
int current_layout = _QWERTY;
bool f_row_active = false;

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi(
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_MINS, KC_EQL,  KC_BSPC, KC_GRAVE,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,        KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, TD(TD_LAYERS), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_COLEMAK_DH] = LAYOUT_65_ansi(
        KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_MINS, KC_EQL,  KC_BSPC, KC_GRAVE,
        KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,       KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS,        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,          KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,                 KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,        KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, TD(TD_LAYERS), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_F_ROW] = LAYOUT_65_ansi(
        _______,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        _______, _______, _______, _______,
        _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,
        _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,          _______, _______,
        _______,                 _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,
        _______,        _______, _______,                            _______,                   _______, _______,       _______, _______, _______, _______
    ),
    [_FUNCTIONS] = LAYOUT_65_ansi(
        _______,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,  KC_F12,  KC_BSPC, KC_GRAVE,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR,       KC_SLCK, KC_PAUS, RESET,   KC_DEL,
        _______,        RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______,       _______,          EEP_RST, KC_PGDN,
        _______,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______,       _______, _______, KC_VOLU, KC_MUTE,
        _______,        _______, _______,                            _______,                   _______, _______,       _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};

void set_persistent_default(int layer) {
    set_single_persistent_default_layer(layer);
    current_layout = layer;
}

void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
     // Get rid of the functions layer when releasing the tapdance button
     layer_off(_FUNCTIONS);

     if (state->pressed) {
         layer_on(_FUNCTIONS);
     }

     switch (state->count) {
         case 2: {
             if (f_row_active) {
                layer_off(_F_ROW);
                f_row_active = false;
             } else {
                layer_on(_F_ROW);
                f_row_active = true;
             }
             break;
         }
         case 3: {
            if (current_layout == _QWERTY) {
                set_persistent_default(_COLEMAK_DH);
            } else {
                set_persistent_default(_QWERTY);
            }
         }
     }
}

void reset_layers(qk_tap_dance_state_t *state, void *user_data) {
    layer_off(_FUNCTIONS);
}

// Tapdances
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, reset_layers)
};
