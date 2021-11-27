LEADER_EXTERNS();

void matrix_scan_user(void) {

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_J) {
            SEND_STRING("Jakob");
        }
        SEQ_ONE_KEY(KC_W) {
            SEND_STRING("Weickmann");
        }
        SEQ_ONE_KEY(KC_S) {
            if (de_layout_active) {
                tap_code16(DE_SS);
            } else {
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
            }
        }
        SEQ_TWO_KEYS(KC_M, KC_E) {
            SEND_STRING("Jakob Weickmann");
        }
        SEQ_TWO_KEYS(KC_G, KC_R) {
            if (de_layout_active) {
                SEND_STRING("Gr[-e");
            } else {
                SEND_STRING("Gr");
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                unregister_mods(MOD_LALT);
                
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
                SEND_STRING("e");
            }
        }
        SEQ_TWO_KEYS(KC_V, KC_A) {
            if (!de_layout_active) {
                SEND_STRING("vaikuman/yakobu"SS_TAP(X_F7));
            }
        }
        SEQ_TWO_KEYS(KC_Y, KC_A) {
            if (!de_layout_active) {
                SEND_STRING("yakobu"SS_TAP(X_F7));
            }
        }
        SEQ_TWO_KEYS(KC_Y, KC_U) {
            if (!de_layout_active) {
                SEND_STRING("yumeho");
            }
        }
        SEQ_TWO_KEYS(KC_I, KC_U) {
            SEND_STRING("Yumeho");
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            tap_code(KC_END);
            tap_code(KC_RIGHT);
            tap_code16(S(KC_UP));
            tap_code16(S(KC_DEL));
        }
        SEQ_TWO_KEYS(KC_H, KC_G) {
            if (de_layout_active) {
                SEND_STRING("Mit herylichen Gr[-en");
            } else {
                SEND_STRING("Mit herzlichen Gr");
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                unregister_mods(MOD_LALT);
                
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
                SEND_STRING("en");
            }
        }
        SEQ_TWO_KEYS(KC_V, KC_D) {
            SEND_STRING("haben Sie vielen Dank f"SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2))"r Ihre Nachricht.");
        }
        SEQ_TWO_KEYS(KC_F, KC_G) {
            if (de_layout_active) {
                SEND_STRING("Mit freundlichen Gr[-en");
            } else {
                SEND_STRING("Mit freundlichen Gr");
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                unregister_mods(MOD_BIT(KC_LALT));
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
                SEND_STRING("en");
            }
        }
        SEQ_FOUR_KEYS(KC_V, KC_I, KC_S, KC_A) {
            SEND_STRING("4570382900105176");
        }
        SEQ_FOUR_KEYS(KC_P, KC_O, KC_S, KC_T) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);    
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("posteo.de");
        }
        SEQ_THREE_KEYS(KC_U, KC_N, KC_I) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);    
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("univie.ac.at");
        }
        SEQ_THREE_KEYS(KC_G, KC_M, KC_X) {
            SEND_STRING("j.weickmann"); 
            if (de_layout_active) {
                tap_code16(DE_AT);    
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("gmx.net");
        }
        SEQ_FOUR_KEYS(KC_D, KC_J, KC_J, KC_G) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);    
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("djjg.org");
        }
        SEQ_FOUR_KEYS(KC_A, KC_T, KC_N, KC_R) {
            if (de_layout_active) {
                tap_code16(DE_PLUS);
            } else {
                tap_code16(KC_PLUS);
            }
            SEND_STRING("4367761832729");
        }
        SEQ_FOUR_KEYS(KC_D, KC_E, KC_N, KC_R) {
            if (de_layout_active) {
                tap_code16(DE_PLUS);
            } else {
                tap_code16(KC_PLUS);
            }
            SEND_STRING("491743625328");
        }
        SEQ_FOUR_KEYS(KC_I, KC_B, KC_A, KC_N) {
            SEND_STRING("DE58100900001279503003");
        }
        SEQ_THREE_KEYS(KC_B, KC_I, KC_C) {
            SEND_STRING("BEVODEBB");
        }
        SEQ_THREE_KEYS(KC_E, KC_U, KC_R) {
            if (de_layout_active) {
                tap_code16(DE_EURO);
            } else {
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P8);  // €
                unregister_mods(MOD_BIT(KC_LALT));
            }
        }
        SEQ_TWO_KEYS(KC_E, KC_N) {
            add_mods(MOD_BIT(KC_LALT));
            tap_code(KC_P1);
            tap_code(KC_P5);
            tap_code(KC_P7);  // ¥
            unregister_mods(MOD_BIT(KC_LALT));
        }
        SEQ_ONE_KEY(KC_Q) {
            add_mods(MOD_BIT(KC_LALT));
            tap_code(KC_P9);
            tap_code(KC_P6); // `
            unregister_mods(MOD_BIT(KC_LALT));
        }
        SEQ_TWO_KEYS(KC_Q, KC_Q) {
            for (int i=0; i<3; i++) {
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P9);
                tap_code(KC_P6); // `
                unregister_mods(MOD_BIT(KC_LALT));
            }
        }
    }
