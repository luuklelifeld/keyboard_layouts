#include QMK_KEYBOARD_H

enum CustomKeycodes {
    TOGPERS = SAFE_RANGE,
    TOGGMNG,
    MOLSHIFT,
    MORSHIFT
};

uint16_t lsft_timer = 0;
uint16_t rsft_timer = 0;

void set_persistent_default(int layer);

void switch_persistent_layer(void);

void mod_tap_layer_hold(uint16_t keycode, uint8_t layer, keyrecord_t *record, uint16_t *timer) {
    if (record->event.pressed) {
        layer_on(layer);
        *timer = record->event.time;
    } else {
        layer_off(layer);
        uint16_t time_elapsed = timer_elapsed(*timer);
        if (time_elapsed < TAPPING_TERM) {
            add_oneshot_mods(MOD_BIT(keycode));
        }
    }
}