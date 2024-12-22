const uint16_t PROGMEM combo_r1[] = {KC_6,     KC_J,     COMBO_END};
const uint16_t PROGMEM combo_r2[] = {KC_7,     KC_L,     COMBO_END};
const uint16_t PROGMEM combo_r3[] = {KC_8,     KC_U,     COMBO_END};
const uint16_t PROGMEM combo_r4[] = {KC_9,     KC_Y,     COMBO_END};
//const uint16_t PROGMEM combo_r5[] = {KC_J,     KC_M,     COMBO_END};
//const uint16_t PROGMEM combo_r6[] = {KC_L,     KC_N,     COMBO_END};
//const uint16_t PROGMEM combo_r7[] = {KC_Y,     KC_I,     COMBO_END};

const uint16_t PROGMEM combo_l2[] = {KC_2,     KC_W,     COMBO_END};
const uint16_t PROGMEM combo_l3[] = {KC_3,     KC_F,     COMBO_END};
const uint16_t PROGMEM combo_l4[] = {KC_4,     KC_P,     COMBO_END};
const uint16_t PROGMEM combo_l6[] = {KC_Q,     KC_A,     COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_r1, KC_UNDS),
    COMBO(combo_r2, KC_ENTER),
    COMBO(combo_r4, KC_BSPC),
    COMBO(combo_r3, KC_TAB),

    COMBO(combo_l2, LCTL(KC_X)),
    COMBO(combo_l3, LCTL(KC_C)),
    COMBO(combo_l4, LCTL(KC_V)),
    COMBO(combo_l6, KC_ESC),
};
