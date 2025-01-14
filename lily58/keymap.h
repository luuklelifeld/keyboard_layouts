#include QMK_KEYBOARD_H

enum CustomKeycodes {
    TOGPERS = SAFE_RANGE,
    MOLSHIFT,
    MORSHIFT
};

uint16_t lsft_keycode = KC_LSFT;
uint16_t lsft_timer = 0;
uint8_t lsft_count = 0;

uint16_t rsft_keycode = KC_RSFT;
uint16_t rsft_timer = 0;
uint8_t rsft_count = 0;

bool shouldShiftNextKey = false;
bool hasSentLayeredKeycode = false;

void set_persistent_default(int layer);

void switch_persistent_layer(void);

void mod_tap_layer_hold(
    uint8_t tapLayer, 
    keyrecord_t *record, 
    uint16_t keycode, 
    uint8_t *count, 
    uint16_t *timer
);
