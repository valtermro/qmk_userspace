#if defined(COMBO_ENABLE)

const uint16_t PROGMEM combo_g1[] = {KC_1, KC_Q,     COMBO_END};
const uint16_t PROGMEM combo_g2[] = {KC_2, KC_W,     COMBO_END};
const uint16_t PROGMEM combo_g3[] = {KC_3, KC_F,     COMBO_END};
const uint16_t PROGMEM combo_g4[] = {KC_4, KC_P,     COMBO_END};
const uint16_t PROGMEM combo_g5[] = {KC_5, KC_B,     COMBO_END};

const uint16_t PROGMEM combo_c1[] = {KC_6, KC_J,     COMBO_END};
const uint16_t PROGMEM combo_c2[] = {KC_7, KC_L,     COMBO_END};
const uint16_t PROGMEM combo_c3[] = {KC_8, KC_U,     COMBO_END};
const uint16_t PROGMEM combo_c4[] = {KC_9, KC_Y,     COMBO_END};
const uint16_t PROGMEM combo_c5[] = {KC_0, KC_GRAVE, COMBO_END};

const uint16_t PROGMEM combo_macro_layer[] = {KC_ENTER, KC_ESC, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_g1, LGUI(KC_1)),
    COMBO(combo_g2, LGUI(KC_2)),
    COMBO(combo_g3, LGUI(KC_3)),
    COMBO(combo_g4, LGUI(KC_4)),
    COMBO(combo_g5, LGUI(KC_5)),

    COMBO(combo_c1, LCTL(KC_1)),
    COMBO(combo_c2, LCTL(KC_2)),
    COMBO(combo_c3, LCTL(KC_3)),
    COMBO(combo_c4, LCTL(KC_4)),
    COMBO(combo_c5, LCTL(KC_5)),

    COMBO(combo_macro_layer, MO(_MACRO)),
};

#endif
