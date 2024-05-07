#include QMK_KEYBOARD_H

enum CustomKeycodes {
    TOGPERS = SAFE_RANGE,
    TOGGMNG,
    MOLSHIFT,
    MORSHIFT
};

uint16_t lsft_keycode = KC_LSFT;
uint16_t lsft_timer = 0;
uint8_t lsft_count = 1;

uint16_t rsft_keycode = KC_RSFT;
uint16_t rsft_timer = 0;
uint8_t rsft_count = 1;

void set_persistent_default(int layer);

void switch_persistent_layer(void);

void mod_tap_layer_hold(uint8_t layer, keyrecord_t *record, uint16_t keycode, uint16_t *timer, uint8_t *count) {
    uint16_t time_elapsed = timer_elapsed(*timer);

    if (record->event.pressed) {
        bool isShiftHeld = false;

        if (time_elapsed > TAPPING_TERM) {
            *count = 1;
        } else if (*count >= 2) {
            register_code(keycode);
            isShiftHeld = true;
        }

        if (!isShiftHeld) {
            layer_on(layer);
        }

        *count += 1;
        *timer = record->event.time;
    } else {
        layer_off(layer);
        if (time_elapsed < TAPPING_TERM) {
            add_oneshot_mods(MOD_BIT(keycode));
        }

        if (*count >= 2) {
            unregister_code(keycode);
        }
    }
}