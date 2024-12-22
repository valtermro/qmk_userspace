enum custom_keycodes {
    A_ACCUTE = QK_KB_0, // For regular QMK this should be SAFE_RANGE,
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

    ACC_TILD,

    SYM_UNDS,
    SYM_SQUOT,
    SYM_DQUOT,
    SYM_DGRE,
    SYM_ORDO,
    SYM_ORDA,

    X_XDEL,
};

#define SEND_ACCENTED(lower, upper)        \
    {if (get_mods() == MOD_BIT(KC_LSFT)) { \
        unregister_code(KC_LSFT);          \
        SEND_STRING(upper);                \
        register_code(KC_LSFT);            \
    } else {                               \
        SEND_STRING(lower);                \
    }}

#define SEND_SHIFTED(regular, shifted)     \
    {if (get_mods() == MOD_BIT(KC_LSFT)) { \
        unregister_code(KC_LSFT);          \
        SEND_STRING(shifted);              \
        register_code(KC_LSFT);            \
    } else {                               \
        SEND_STRING(regular);              \
    }}

#define SEND_ALT_SEQUENCE(sequence)        \
   SEND_STRING(SS_LALT(sequence));

bool has_dm_rec1 = false;

bool handle_keycode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_ACCUTE: {
            if (record->event.pressed) {
                SEND_ACCENTED("'a", "'A");
            }
            return false;
        }

        case E_ACCUTE: {
            if (record->event.pressed) {
                SEND_ACCENTED("'e", "'E");
            }
            return false;
        }

        case I_ACCUTE: {
            if (record->event.pressed) {
                SEND_ACCENTED("'i", "'I");
            }
            return false;
        }

        case O_ACCUTE: {
            if (record->event.pressed) {
                SEND_ACCENTED("'o", "'O");
            }
            return false;
        }

        case U_ACCUTE: {
            if (record->event.pressed) {
                SEND_ACCENTED("'u", "'U");
            }
            return false;
        }

        case A_TILD: {
            if (record->event.pressed) {
                SEND_ACCENTED("~a", "~A");
            }
            return false;
        }

        case O_TILD: {
            if (record->event.pressed) {
                SEND_ACCENTED("~o", "~O");
            }
            return false;
        }

        case C_CEDIL: {
            if (record->event.pressed) {
                SEND_ACCENTED("'c", "'C");
            }
            return false;
        }

        case A_CIRC: {
            if (record->event.pressed) {
                SEND_ACCENTED("^a", "^A");
            }
            return false;
        }

        case E_CIRC: {
            if (record->event.pressed) {
                SEND_ACCENTED("^e", "^E");
            }
            return false;
        }

        case O_CIRC: {
            if (record->event.pressed) {
                SEND_ACCENTED("^o", "^O");
            }
            return false;
        }

        case A_GRAVE: {
            if (record->event.pressed) {
                SEND_ACCENTED("`a", "`A");
            }
            return false;
        }

        case ACC_TILD: {
            if (record->event.pressed) {
                SEND_SHIFTED("~", "`");
            }
            return false;
        }

        case SYM_UNDS: {
            if (record->event.pressed) {
                SEND_SHIFTED("_", "-");
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

        case SYM_DGRE: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6) SS_UP(X_LALT));
            }
            return false;
        }

        case SYM_ORDO: {
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_6) SS_UP(X_LALT));
            }
            return false;
        }

        case SYM_ORDA: {
            if (record->event.pressed) {
            }
            return false;
        }

        case X_XDEL: {
            if (record->event.pressed) {
                if (get_mods() == MOD_BIT(KC_LCTL)) {
                    unregister_code(KC_LCTL);
                    SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LSFT) SS_TAP(X_DEL));
                    register_code(KC_LCTL);
                } else {
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL));
                }
            }
            return false;
        }

        default: {
            return true;
        }
    }
}
