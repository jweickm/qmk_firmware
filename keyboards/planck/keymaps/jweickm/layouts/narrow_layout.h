const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ================================================================================================
*  ================================================================================================
* NARROW HAND POSITION (3) for MT3 SUSUWATARI
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |  __  |      |      |      |  __  |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      | 
     * `-----------------------------------------------------------------------------------'
     */

/* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  | ;: Ö | \| Ü |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | '" Ä |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT| BSPC |LOWER |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ |A_RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
        ESC_KEY, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, // LT(0, DE_UDIA), 
//        ESC_KEY, LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), KC_B, KC_J, RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), BSLS_KEY, // LT(0, DE_UDIA), 
        KC_TAB, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, // KC_QUOT, 
//#if homerow_mods == 1
//        KC_TAB, LT(0, KC_A), KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, LT(0, KC_O), QUOT_KEY, // KC_QUOT, 
//#elif homerow_mods == 2
//        KC_TAB, LT(0, KC_A), KC_R, LSFT_T(KC_S), KC_T, KC_G, KC_M, KC_N, RSFT_T(KC_E), KC_I, LT(0, KC_O), QUOT_KEY, // KC_QUOT, 
//#endif
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, ENT_KEY, 
    #if layout == 1
        #if thumb == 1
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
        #elif thumb == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
        #endif
    #elif layout == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, RSFT_T(KC_RALT)
    #endif
    ),

/* _QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |  G-Q |  A-W |  S-F |  C-P |   B  |   J  |  C-L |  S-U |  A-Y | G-; Ö| \| Ü |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | '" Ä |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  ESC |LOWER |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ |A_RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(
        ESC_KEY, LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_E), LCTL_T(KC_R), KC_T, KC_Y, RCTL_T(KC_U), RSFT_T(KC_I), LALT_T(KC_O), RGUI_T(KC_P), BSLS_KEY, // LT(0, DE_UDIA), 
#if homerow_mods == 1
        KC_TAB, LT(0, KC_A), KC_S, D_KEY, KC_F, KC_G, H_KEY, KC_J, KC_K, KC_L, LT(0, KC_SCLN), QUOT_KEY, // KC_QUOT, 
#elif homerow_mods == 2
        KC_TAB, LT(0, KC_A), KC_S, LSFT_T(KC_D), KC_F, KC_G, H_KEY, KC_J, RSFT_T(KC_K), KC_L, LT(0, KC_SCLN), QUOT_KEY, // KC_QUOT, 
#endif
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, V_KEY, KC_B, KC_N, KC_M, COMM_KEY, DOT_KEY, SLSH_KEY, ENT_KEY, 
    #if layout == 1
        #if thumb == 1
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
        #elif thumb == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
        #endif
    #elif layout == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, RSFT_T(KC_RALT)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _GAMING
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  F5  |  F8  |  F9  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |   M  |   N  |   J  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   A  |   S  |   D  |   F  |   G  |   K  |   H  |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL |   C  | LALT |   B  |   P  |    SPACE    | ____ | RALT | DOWN |  UP  |ADJUST| 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_F5, KC_F8, KC_F9, KC_BSPC, 
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_M, KC_N, KC_J, KC_I, KC_O, KC_QUOT, 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, 
    #if layout == 1
        KC_LCTL, KC_C, KC_LALT, KC_B, KC_P, KC_SPC, KC_SPC, KC_TRNS, KC_RALT, DOWN_KEY, UP_KEY, MO(_ADJUST)
    #elif layout == 2
        KC_LCTL, KC_C, KC_LALT, KC_B, KC_P, KC_SPC, KC_SPC, KC_TRNS, KC_RALT, DOWN_KEY, UP_KEY, MO(_ADJUST)
    #endif
    ),

// ----------------------------------------------------------------------------------------
#ifdef NAGINATA_ENABLE
/* 薙刀式
     * ,----------------------------------------------------------------------------------.
     * | ____ |  小  |き  ぬ|て  り|し  む|  <-  |  ->  |さ  え|う　わ|す  ゆ|へ  ：| TATE |
     * +------|------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |あ  せ|け  め|と  に|か゛ま|っ  ち|く  や|の゛ー|る　も|い　よ|お  つ| KOTI |
     * +------|------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |  ほ  |  ひ  |は  を|こ゜、|そ  み|た  ろ|な゜。|ん  ね|ら  ふ|れ　ふ| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | EISU | ____ | ____ | ____ | ____ |   NGSHFT    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
       KC_TRNS, NG_Q, NG_W, NG_E, NG_R, NG_T, NG_Y, NG_U, NG_I, NG_O, NG_P, NG_TAYO,
       KC_TRNS, NG_A, NG_S, NG_D, NG_F, NG_G, NG_H, NG_J, NG_K, NG_L, NG_SCLN, NG_KOTI,
       KC_TRNS, NG_Z, NG_X, NG_C, NG_V, NG_B, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, KC_TRNS,
    #if layout == 1
        EISU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #elif layout == 2
        EISU, KC_TRNS, KC_TRNS, KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #endif
    ),
// 薙刀式
#endif

/* ----------------------------------------------------------------------------------------
* _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  | ____ |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Ä  | ____ |  SFT | ____ | ____ | ____ | ____ |  SFT | ____ |   Ö  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_UMLAUTS] = LAYOUT_planck_grid(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_UE, KC_TRNS, DE_OE, DE_UE,
        KC_TRNS, DE_AE, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, DE_OE, DE_AE, 
        KC_TRNS, DE_SZ, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |A-GRV | LGUI | LALT | LSFT | LCTL | PAUSE|   "  |   _  |   +  |   [  |   ]  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|CTLTAB| MIC  | MPLY | MUTE |A-CAPS|   ~  |   '  |   <  |   >  |   -  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| ____ |ADJUST| ____ | ____ |     ____    |ADJUST| ____ | Bri- | Bri+ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, KC_PIPE,
        A(KC_GRV), KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_PAUSE, S(KC_QUOT), KC_UNDS, KC_PLUS, TD(TD_BRC), KC_RBRC, S(KC_QUOT), 
        C(KC_CAPS), CTL_TAB, KC_MAIL, KC_MPLY, KC_MUTE, A(KC_CAPS), KC_TILD, KC_QUOT, TD(TD_LARROW), TD(TD_RARROW), KC_MINS, DE_ACC_GRV, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_BRID, KC_BRIU, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_BRID, KC_BRIU, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   {  |   }  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   _  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| ____ |ADJUST| ____ |ADJUST|     ____    | ____ | MAIL | <<|  |  |>> | MUTE | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, S(KC_COMM), KC_MINS, KC_EQL, TD(TD_CBR), KC_RCBR, KC_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, S(KC_DOT), COMM_KEY, DOT_KEY, KC_UNDS, DE_ACC_ACUT, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ |   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   ;  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   *  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   1  |   2  |   3  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | !NUM | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_grid(
        KC_TRNS, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_MINS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS,
    #if layout == 1
        TG(_NUM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, DOT_KEY, COMM_KEY, KC_EQL, TG(_NUM)
    #elif layout == 2
        TG(_NUM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, DOT_KEY, COMM_KEY, KC_EQL, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| XXXX | C(->)|  TAB | HYPER| C(<-)|  CUT | REDO | UNDO | COPY | PASTE| BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)| LGUI | LALT | LSFT | LCTL |VIM_GG|  <-  |   ↓  |   ↑  |  ->  | VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |NAVSFT|!LANG |DESK<-|WHL ↑ | WHL↓ |DESK->| HOME | PGDN | PGUP |  END | C(F) | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |C-BSPC| BSPC |    _____    | ____ | C-DEL|  <-  |  ->  | END  | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, KC_NO, C(KC_RGHT), KC_TAB, KC_HYPR, C(KC_LEFT), C(KC_X), REDO, UNDO, C(KC_INS), S(KC_INS), KC_BSPC, 
        C(KC_TAB), KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, TD(TD_VIM_GG), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        NAVSFT, LANG_SWITCH, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, C(KC_F), KC_TRNS, 
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, LEFT_KEY, RIGHT_KEY, KC_END 
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, LEFT_KEY, RIGHT_KEY, KC_END 
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | ____ | !MSE |WHL <-| M ↑  |WHL ->| XXXX | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | BTN 4| M <- | M ↓  | M -> |BTN 5 | XXXX | RCTL | RSFT | LALT | RGUI | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ACCEL| XXXX |WHL ↑ |WHL ↓ | XXXX | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|!MOUSE| XXXX |BTN 2 |BTN 3 |    BTN 1    | ____ | ____ | Bri- | Bri+ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_TRNS, TG(_MOUSE), KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
        KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_NO, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_TRNS, 
        KC_TRNS, KC_ACL0, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
    #if layout == 1
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS
    #elif layout == 2
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |SHTDWN| RESET| XXXX |RGBTOG| AU_ON|AU_OFF| XXXX | KANA | !LANG| DE_SW|JP<>DE| SLEEP|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | RCTL | RSFT | LALT | RGUI | !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | 薙刀 | EISU |QWERTY| CD_SW| UC_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| ____ | ____ | ____ | ____ |     ____    | MUTE | MPLY | VOLD | VOLU | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_SYSTEM_POWER, RESET, KC_NO, RGB_TOG, AU_ON, AU_OFF, KC_NO, A(KC_GRV), LANG_SWITCH, KC_DE_SWITCH, A(KC_LSFT), KC_SLEP, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, GAMING, 
    #ifdef NAGINATA_ENABLE
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, NAGINATA_SWITCH, EISU, QWERTY, CODING_SW, KC_TRNS,
    #else
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, QWERTY, CODING_SW, KC_TRNS,
    #endif
    #if layout == 1
        EEPROM_RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS
    #elif layout == 2
        EEPROM_RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS
    #endif
    ),
};
