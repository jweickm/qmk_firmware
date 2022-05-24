LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_J) {
        SEND_STRING("Jakob");
    }
    SEQ_ONE_KEY(KC_E) {
        SEND_STRING("E");
        SEND_SPECIAL('-');
        SEND_STRING("Mail");
    }
    /* SEQ_ONE_KEY(KC_A) { */
    /*     if (de_layout_active) { */
    /*         tap_code(DE_ADIA); */
    /*     } else { */
    /*         SEND_UMLAUT('a'); */
    /*     } */
    /* } */
    /* SEQ_TWO_KEYS(KC_A, KC_A) { */
    /*     if (de_layout_active) { */
    /*         tap_code16(S(DE_ADIA)); */
    /*     } else { */
    /*         SEND_UMLAUT('A'); */
    /*     } */
    /* } */
    /* SEQ_ONE_KEY(KC_U) { */
    /*     if (de_layout_active) { */
    /*         tap_code(DE_UDIA); */
    /*     } else { */
    /*         SEND_UMLAUT('u'); */
    /*     } */
    /* } */
    /* SEQ_TWO_KEYS(KC_U, KC_U) { */
    /*     if (de_layout_active) { */
    /*         tap_code16(S(DE_UDIA)); */
    /*     } else { */
    /*         SEND_UMLAUT('U'); */
    /*     } */
    /* } */
    /* SEQ_ONE_KEY(KC_O) { */
    /*     if (de_layout_active) { */
    /*         tap_code(DE_ODIA); */
    /*     } else { */
    /*         SEND_UMLAUT('o'); */
    /*     } */
    /* } */
    /* SEQ_TWO_KEYS(KC_O, KC_O) { */
    /*     if (de_layout_active) { */
    /*         tap_code16(S(DE_ODIA)); */
    /*     } else { */
    /*         SEND_UMLAUT('O'); */
    /*     } */
    /* } */
    /* SEQ_ONE_KEY(KC_Z) { */
    /*     if (de_layout_active) { */
    /*         tap_code16(DE_SS); */
    /*     } else { */
    /*         SEND_UMLAUT('s'); */
    /*         /1* add_mods(MOD_BIT(KC_LALT)); *1/ */
    /*         /1* tap_code(KC_P0); *1/ */
    /*         /1* tap_code(KC_P2); *1/ */
    /*         /1* tap_code(KC_P2); *1/ */
    /*         /1* tap_code(KC_P3);  // ß *1/ */
    /*         /1* unregister_mods(MOD_LALT); *1/ */
    /*     } */
    /* } */
    /* SEQ_ONE_KEY(KC_S) { */
    /*     if (de_layout_active) { */
    /*         tap_code16(DE_SS); */
    /*     } else { */
    /*         SEND_UMLAUT('s'); */
    /*         /1* add_mods(MOD_BIT(KC_LALT)); *1/ */
    /*         /1* tap_code(KC_P0); *1/ */
    /*         /1* tap_code(KC_P2); *1/ */
    /*         /1* tap_code(KC_P2); *1/ */
    /*         /1* tap_code(KC_P3);  // ß *1/ */
    /*         /1* unregister_mods(MOD_LALT); *1/ */
    /*     } */
    /* } */
    SEQ_ONE_KEY(KC_W) {
        SEND_STRING("Weickmann");
    }
    SEQ_ONE_KEY(KC_P) {
        tap_code16(KC_PERC);
        if (de_layout_active) {
            tap_code16(DE_RABK);
        } else {
            tap_code16(S(KC_DOT));
        }
        tap_code16(KC_PERC);
    }
    SEQ_TWO_KEYS(KC_M, KC_E) {
        SEND_STRING("Jakob Weickmann");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
        SEND_STRING("Alser Stra");
        SEND_UMLAUT('s');
        SEND_STRING("e 53");
        SEND_SPECIAL('/');
        SEND_STRING("2");
        SEND_SPECIAL('/');
        SEND_STRING("12, 1080 Wien");
    }
    SEQ_TWO_KEYS(KC_L, KC_G) {
        SEND_STRING("Liebe ");
        if (de_layout_active) {
            SEND_STRING("Gr[-e");
        } else {
            SEND_STRING("Gr");
            SEND_UMLAUT('u');
            /* add_mods(MOD_BIT(KC_LALT)); */
            /* tap_code(KC_P0); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P5); */
            /* tap_code(KC_P2);  // ü */
            /* unregister_mods(MOD_LALT); */
            
            SEND_UMLAUT('s');
            /* add_mods(MOD_BIT(KC_LALT)); */
            /* tap_code(KC_P0); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P3);  // ß */
            /* unregister_mods(MOD_LALT); */
            SEND_STRING("e");
        }
    }
    SEQ_TWO_KEYS(KC_G, KC_A) {
        SEND_STRING("git add .");
        tap_code(KC_ENT);
    }
    SEQ_TWO_KEYS(KC_G, KC_C) {
        SEND_STRING("git commit ");
        if (!de_layout_active) {
            SEND_STRING("-m \"\"");
        } else  {
            SEND_STRING("/m @@");
        }
        tap_code(KC_LEFT);
    }
    SEQ_TWO_KEYS(KC_G, KC_P) {
        SEND_STRING("git push");
        tap_code(KC_ENT);
    }
    SEQ_TWO_KEYS(KC_G, KC_U) {
        SEND_STRING("git pull upstream master");
        tap_code(KC_ENT);
    }
    SEQ_TWO_KEYS(KC_F, KC_T) {
        tap_code16(C(KC_L));
        tap_code(KC_HOME);
        SEND_STRING("12ft.io");
        SEND_SPECIAL('/');
        tap_code(KC_ENT);
    }
    /* SEQ_TWO_KEYS(KC_G, KC_B) { */
    /*     SEND_STRING("git checkout jweickm"); */
    /*     if (de_layout_active) { */
    /*         SEND_STRING("?"); */
    /*     } else { */
    /*         SEND_STRING("_"); */
    /*     } */
    /* } */
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
    /* SEQ_TWO_KEYS(KC_I, KC_U) { */
    /*     if (de_layout_active) { */
    /*         SEND_STRING("Z"); */
    /*     } else { */
    /*         SEND_STRING("Y"); */
    /*     } */
    /*     SEND_STRING("umeho"); */
    /* } */
    /* SEQ_TWO_KEYS(KC_D, KC_D) { */
    /*     tap_code(KC_END); */
    /*     tap_code(KC_RIGHT); */
    /*     tap_code16(S(KC_UP)); */
    /*     tap_code16(S(KC_DEL)); */
    /* } */
    SEQ_TWO_KEYS(KC_H, KC_G) {
        if (de_layout_active) {
            SEND_STRING("Mit herylichen Gr[-en");
        } else {
            SEND_STRING("Mit herzlichen Gr");
            SEND_UMLAUT('u');
            /* add_mods(MOD_BIT(KC_LALT)); */
            /* tap_code(KC_P0); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P5); */
            /* tap_code(KC_P2);  // ü */
            /* unregister_mods(MOD_LALT); */
            
            SEND_UMLAUT('s');
            /* add_mods(MOD_BIT(KC_LALT)); */
            /* tap_code(KC_P0); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P2); */
            /* tap_code(KC_P3);  // ß */
            /* unregister_mods(MOD_LALT); */
            SEND_STRING("en");
        }
    }
    SEQ_TWO_KEYS(KC_V, KC_D) {
        SEND_STRING("haben Sie vielen Dank f");
        SEND_UMLAUT('u');
        SEND_STRING("r Ihre Nachricht.");
    }
    SEQ_TWO_KEYS(KC_F, KC_G) {
        SEND_STRING("Mit freundlichen Gr");
        SEND_UMLAUT('u');
        SEND_UMLAUT('s');
        SEND_STRING("en");
    }
    SEQ_THREE_KEYS(KC_A, KC_D, KC_R) {
        SEND_STRING("Alser Stra");
        SEND_UMLAUT('s');
        SEND_STRING("e 53");
        SEND_SPECIAL('/');
        SEND_STRING("2");
        SEND_SPECIAL('/');
        SEND_STRING("12, 1080 Wien");
    }
    SEQ_THREE_KEYS(KC_U, KC_N, KC_I) {
        SEND_STRING("jakob.weickmann");
        SEND_SPECIAL('@');
        SEND_STRING("univie.ac.at");
    }
    SEQ_THREE_KEYS(KC_G, KC_M, KC_X) {
        SEND_STRING("j.weickmann"); 
        SEND_SPECIAL('@');
        SEND_STRING("gmx.net");
    }
    SEQ_THREE_KEYS(KC_G, KC_A, KC_C) {
        SEND_STRING("git add .");
        tap_code(KC_ENT);
        SEND_STRING("git commit ");
        if (!de_layout_active) {
            SEND_STRING("-m \"\"");
        } else  {
            SEND_STRING("/m @@");
        }
        tap_code(KC_LEFT);
    }
    SEQ_FOUR_KEYS(KC_V, KC_I, KC_S, KC_A) {
        SEND_STRING("4570382900105176");
    }
    SEQ_FOUR_KEYS(KC_P, KC_O, KC_S, KC_T) {
        SEND_STRING("jakob.weickmann");
        SEND_SPECIAL('@');
        SEND_STRING("posteo.de");
    }
    SEQ_FOUR_KEYS(KC_D, KC_J, KC_J, KC_G) {
        SEND_STRING("jakob.weickmann");
        SEND_SPECIAL('@');
        SEND_STRING("djjg.org");
    }
    SEQ_FOUR_KEYS(KC_A, KC_T, KC_N, KC_R) {
        SEND_SPECIAL('+');
        SEND_STRING("4367761832729");
    }
    SEQ_FOUR_KEYS(KC_D, KC_E, KC_N, KC_R) {
        SEND_SPECIAL('+');
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
            SEND_UMLAUT('e'); // €
        }
    }
    SEQ_TWO_KEYS(KC_E, KC_N) {
        SEND_UMLAUT('y'); // ¥
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
