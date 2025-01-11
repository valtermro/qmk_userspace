void rgb_init(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 25);
}

void rgb_update(uint8_t led_min, uint8_t led_max) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    bool has_caps_lock = host_keyboard_led_state().caps_lock;
#   define HAS_MOD(m) (mods & MOD_BIT(m))

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t index = g_led_config.matrix_co[row][col];

            if (index < led_min || index >= led_max) {
                continue;
            }

#           define HRM_LGUI_INDICATOR  2
#           define HRM_LALT_INDICATOR  3
#           define HRM_LSFT_INDICATOR  5
#           define HRM_LCTL_INDICATOR  6
#           define CAPS_INDICATOR      0
#           define DM_REC_INDICATOR    33

            hsv_t hsv = { .h = 0, .s = 255, .v = 125 };
#           define HUE_INDICATOR  128 // Blue
#           define HUE_ACTIVE_1   43  // Yellow
#           define HUE_ACTIVE_2   85  // Green

            if ((index == HRM_LALT_INDICATOR && HAS_MOD(KC_LALT)) ||
                (index == HRM_LGUI_INDICATOR && HAS_MOD(KC_LGUI)) ||
                (index == HRM_LSFT_INDICATOR && HAS_MOD(KC_LSFT)))
            {
                hsv.h = HUE_INDICATOR;
            }
            else if (index == HRM_LCTL_INDICATOR) {
                switch (global_state.prefixed_ctl_key) {
                    case KC_K:
                        hsv.h = HUE_ACTIVE_2;
                        break;
                    case KC_M:
                        hsv.h = HUE_ACTIVE_1;
                        break;
                    default:
                        if (HAS_MOD(KC_LCTL))
                            hsv.h = HUE_INDICATOR;
                        break;
                }
            }
            else if (index == CAPS_INDICATOR) {
                if (global_state.has_caps_word)
                    hsv.h = HUE_INDICATOR;
                else if (has_caps_lock)
                    hsv.h = HUE_ACTIVE_1;
            }
            else if (index == DM_REC_INDICATOR) {
                if (global_state.is_recording_macro_2)
                    hsv.h = HUE_ACTIVE_1;
                else if (global_state.is_recording_macro_1)
                    hsv.h = HUE_INDICATOR;
            }

            if (hsv.h != 0) {
                rgb_t rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }
}
