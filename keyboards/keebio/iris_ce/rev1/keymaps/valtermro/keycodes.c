enum custom_keycodes {
    A_ACCUTE = SAFE_RANGE,
    E_ACCUTE,
    I_ACCUTE,
    O_ACCUTE,
    U_ACCUTE,

    A_TILD,
    O_TILD,
    C_CEDIL,

    A_CIRC,
    E_CIRC,
    O_CIRC,

    A_GRAVE,

    SYM_CIRC,
    SYM_SQUOT,
    SYM_DQUOT,
    SYM_GRAVE,
    SYM_DGRE,
    SYM_ORDO,
    SYM_ORDA,
    SYM_TILDE,

    C_COPY,

    C_DELINE,
    C_DELEND,
    C_JOIN,
    C_MNAV,
    C_CTLK,

    M_EMAIL1,
    M_EMAIL2,
    M_EMAIL3,

    C_NOP1,
};

#define HAS_LCTL(a, b) ((a) & MOD_BIT(KC_LCTL) || (b) & MOD_BIT(KC_LCTL))
#define HAS_LSFT(a, b) ((a) & MOD_BIT(KC_LSFT) || (b) & MOD_BIT(KC_LSFT))

#define TAP_ACCENTED(tap_dead, dead_key, char_key)          \
    {                                                       \
        uint8_t current_mods = get_mods();                  \
        uint8_t current_osms = get_oneshot_mods();          \
        clear_mods();                                       \
        clear_oneshot_mods();                               \
        (tap_dead)(dead_key);                               \
        if (HAS_LSFT(current_mods, current_osms)) {         \
            register_code(KC_LSFT);                         \
            tap_code(char_key);                             \
            unregister_code(KC_LSFT);                       \
        } else {                                            \
            tap_code(char_key);                             \
        }                                                   \
        set_mods(current_mods);                             \
        set_oneshot_mods(current_osms);                     \
    }

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_ACCUTE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_A);
            }
            return false;
        }

        case E_ACCUTE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_E);
            }
            return false;
        }

        case I_ACCUTE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_I);
            }
            return false;
        }

        case O_ACCUTE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_O);
            }
            return false;
        }

        case U_ACCUTE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_U);
            }
            return false;
        }

        case A_TILD: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code16, KC_TILDE, KC_A);
            }
            return false;
        }

        case O_TILD: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code16, KC_TILDE, KC_O);
            }
            return false;
        }

        case C_CEDIL: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_QUOTE, KC_C);
            }
            return false;
        }

        case A_CIRC: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code16, KC_CIRC, KC_A);
            }
            return false;
        }

        case E_CIRC: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code16, KC_CIRC, KC_E);
            }
            return false;
        }

        case O_CIRC: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code16, KC_CIRC, KC_O);
            }
            return false;
        }

        case A_GRAVE: {
            if (record->event.pressed) {
                TAP_ACCENTED(tap_code, KC_GRAVE, KC_A);
            }
            return false;
        }

        case SYM_CIRC: {
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            return false;
        }

        case SYM_SQUOT: {
            if (record->event.pressed) {
                SEND_STRING("' ");
            }
            return false;
        }

        case SYM_DQUOT: {
            if (record->event.pressed) {
                SEND_STRING("\" ");
            }
            return false;
        }

        case SYM_GRAVE: {
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                uint8_t osms = get_oneshot_mods();

                if (HAS_LCTL(mods, osms)) {
                    SEND_STRING("`");
                } else {
                    SEND_STRING("` ");
                }
            }
            return false;
        }

        case SYM_DGRE: {
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            return false;
        }

        case SYM_ORDO: {
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_6)));
            }
            return false;
        }

        case SYM_ORDA: {
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_0)));
            }
            return false;
        }

        case SYM_TILDE: {
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                uint8_t osms = get_oneshot_mods();

                if (HAS_LCTL(mods, osms)) {
                    SEND_STRING("~");
                } else {
                    SEND_STRING("~ ");
                }
            }
            return false;
        }

        case C_JOIN: {
            if (record->event.pressed && !get_mods() && !get_oneshot_mods()) {
                SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_DOWN) SS_TAP(X_END) SS_TAP(X_HOME)) SS_TAP(X_SPACE));
            }
            return false;
        }

        case C_COPY: {
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING(SS_LCTL(SS_TAP(X_C)));
            }
            return false;
        }

        case C_DELINE: {
            if (record->event.pressed && !get_mods() && !get_oneshot_mods()) {
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_DOWN)) SS_TAP(X_DEL) SS_TAP(X_HOME));
            }
            return false;
        }

        case C_DELEND: {
            if (record->event.pressed && !get_mods() && !get_oneshot_mods()) {
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
            }
            return false;
        }

        case C_MNAV: {
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                uint8_t osms = get_oneshot_mods();

                if (HAS_LCTL(mods, osms) || HAS_LSFT(mods, osms)) {
                    clear_mods();
                    clear_oneshot_mods();
                    SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_MINUS))));
                    set_mods(mods);
                } else {
                    SEND_STRING(SS_LCTL(SS_TAP(X_MINUS)));
                }
            }
            return false;
        }

#       define CLEAR_PREFIXED_CTL_KEY()             \
            {if (global_state.prefixed_ctl_key) {   \
                unregister_code(KC_LCTL);           \
                global_state.prefixed_ctl_key = 0;  \
            }}

#       define SEND_PREFIXED_CTL_KEY(_x, _kc)                   \
            {if (!global_state.prefixed_ctl_key) {             \
                SEND_STRING(SS_LCTL(SS_TAP(_x)));              \
                global_state.prefixed_ctl_key = _kc;           \
            } else if (global_state.prefixed_ctl_key == _kc) { \
                CLEAR_PREFIXED_CTL_KEY();                      \
            }}

        case KC_A ... KC_Z: {
            if (global_state.prefixed_ctl_key) {
                if (record->event.pressed) {
                    register_code(KC_LCTL);
                } else {
                    CLEAR_PREFIXED_CTL_KEY();
                }
            }
            return true;
        }

        case C_CTLK: {
            if (record->event.pressed) {
                SEND_PREFIXED_CTL_KEY(X_K, KC_K);
            }
            return false;
        }

        case M_EMAIL1: {
            if (record->event.pressed) {
                SEND_STRING("valtermro@outlook.com");
            }
            return false;
        }

        case M_EMAIL2: {
            if (record->event.pressed) {
                SEND_STRING("valtermro@hotmail.com");
            }
            return false;
        }

        case M_EMAIL3: {
            if (record->event.pressed) {
                SEND_STRING("valter.rodrigues@softplan.com.br");
            }
            return false;
        }

        default: {
            return true;
        }
    }
}
