void rgb_init(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 0);
}

void rgb_update(uint8_t led_min, uint8_t led_max) {
#if true
    uint8_t mods = get_mods() | get_oneshot_mods();
#   define HAS_MOD(m) (mods & MOD_BIT(m))

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t index = g_led_config.matrix_co[row][col];

            if (index < led_min || index >= led_max) {
                continue;
            }

#           define HRM_LGUI_INDICATOR  0 // 2
#           define HRM_LALT_INDICATOR  0 // 3
#           define HRM_RALT_INDICATOR  0 // 3
#           define HRM_LSFT_INDICATOR  0 // 5
#           define HRM_LCTL_INDICATOR  0 // 6
#           define CAPS_INDICATOR      0
#           define DM_REC_INDICATOR    0 // 33

            hsv_t hsv = { .h = 0, .s = 255, .v = 75 };
#           define HUE_0 128 // Blue
#           define HUE_1 85  // Green
#           define HUE_2 43  // Yellow
#           define HUE_3 1   // Red
#           define HUE_4 191 // Purple

            if (index == DM_REC_INDICATOR) 
            {
                if (global_state.is_recording_macro_1 || global_state.is_recording_macro_2)
                    hsv.h = HUE_3;
            }

            if (index == HRM_RALT_INDICATOR && HAS_MOD(KC_RALT))
            {
                hsv.h = HUE_4;
            }

            if ((index == HRM_LALT_INDICATOR && HAS_MOD(KC_LALT)) ||
                (index == HRM_LGUI_INDICATOR && HAS_MOD(KC_LGUI)) ||
                (index == HRM_LSFT_INDICATOR && HAS_MOD(KC_LSFT)))
            {
                hsv.h = HUE_0;
            }

            if (index == HRM_LCTL_INDICATOR) 
            {
                if (global_state.prefixed_ctl_key)
                    hsv.h = HUE_1;
                else if (HAS_MOD(KC_LCTL))
                    hsv.h = HUE_0;
            }

            // if (index == CAPS_INDICATOR && host_keyboard_led_state().caps_lock)
            // {
            //     hsv.h = HUE_;
            // }

            if (hsv.h != 0) 
            {
                rgb_t rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }

#endif
}
