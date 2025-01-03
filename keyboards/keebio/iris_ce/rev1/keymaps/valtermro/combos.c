//const uint16_t PROGMEM combo_r1[] = {KC_6,     KC_J,     COMBO_END};
//const uint16_t PROGMEM combo_r2[] = {KC_7,     KC_L,     COMBO_END};
//const uint16_t PROGMEM combo_r3[] = {KC_8,     KC_U,     COMBO_END};
//const uint16_t PROGMEM combo_r4[] = {KC_9,     KC_Y,     COMBO_END};
const uint16_t PROGMEM combo_unds[]  = {KC_J,     KC_M,     COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_L,     KC_N,     COMBO_END};
const uint16_t PROGMEM combo_tab[]   = {KC_U,     KC_E,     COMBO_END};
const uint16_t PROGMEM combo_bspc[]  = {KC_Y,     KC_I,     COMBO_END};
const uint16_t PROGMEM combo_esc[]   = {KC_Q,     KC_A,     COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_bspc,  KC_BSPC),
    COMBO(combo_tab,   KC_TAB),
    COMBO(combo_unds,  KC_UNDS),
    COMBO(combo_esc,   KC_ESC),
};
