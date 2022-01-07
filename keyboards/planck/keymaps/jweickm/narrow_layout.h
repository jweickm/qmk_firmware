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
     * | ESC  |  G-Q |  A-W |  S-F |  C-P |_Num-B|_Num-J|  C-L |  S-U |  A-Y |  G-; |Ü (\|)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '" |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  ESC |LOWER |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ |A_RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
#if homerow_mods == 1
        KC_ESC, LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), KC_B, KC_J, RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), LT(0, KC_BSLS), // LT(0, DE_UDIA), 
        KC_TAB, LT(0, KC_A), KC_R, LSFT_T(KC_S), KC_T, KC_G, KC_M, KC_N, RSFT_T(KC_E), KC_I, LT(0, KC_O), LT(0, KC_QUOT), // KC_QUOT, 
#elif homerow_mods == 2
        KC_Q, KC_W, KC_F, KC_P, KC_B, LT(_MOUSE, KC_VOLU), KC_J, KC_L, KC_U, KC_Y, LT(0, KC_SCLN), LT(0, DE_UDIA), //XP(DE_ue, DE_UE),  
        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_TAB, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), LT(0, KC_QUOT), //KC_QUOT,
#endif
        OSM(MOD_LSFT), LT(0, KC_Z), CUT_X, COPY_C, KC_D, PASTE_V, KC_K, KC_H, LT(0, KC_COMM), LT(0, KC_DOT), LT(0, KC_SLSH), RSFT_T(KC_ENT), 
    #if layout == 1
        #if thumb == 1
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, LT(_MOUSE, KC_DEL), LT(_NAV, KC_DOWN), LT(_NAV, KC_UP), LT(_ADJUST, KC_RALT)
        #elif thumb == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_BSPC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, LT(_MOUSE, KC_DEL), LT(_NAV, KC_DOWN), LT(_NAV, KC_UP), LT(_ADJUST, KC_RALT)
        #endif
    #elif layout == 2
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, RAISE, LT(_MOUSE, KC_DEL), LT(_NAV, KC_DOWN), LT(_NAV, KC_UP), RSFT_T(KC_RALT)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _GAMING
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  F5  |  F8  |  F9  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |DESK<-|DESK->|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   Z  |   M  |   ;  |_CM-EN|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL |   C  |   B  |   X  | LALT |    SPACE    | ENT  | RALT | Vol- | Vol+ | !GAME| 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_F5, KC_F8, KC_F9, KC_BSPC, 
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, C(G(KC_LEFT)), C(G(KC_RGHT)), 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_Z, KC_M, KC_SCLN, KC_TRNS, 
    #if layout == 1
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
    #elif layout == 2
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
    #endif
    ),

// ----------------------------------------------------------------------------------------
#ifdef NAGINATA_ENABLE
/* 薙刀式
     * ,----------------------------------------------------------------------------------.
     * |　小　|き　ぬ|て　り|し　む|　<-  | ____ |  ->  |　さ　|る　よ|す　え|へ　ゆ| EISU |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |ろ　せ|け　め|と　に|か゛ま|っ　ち| ____ |く　や|あ゛の|い　も|う　わ|ー　つ| KOTI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ほ　|  ひ　|は　を|こ゜、|そ　み| ____ |た　お|な゜。|ん　ね|ら　ふ|  れ　| TATE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |ENSHFT|   NGSHFT    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
        NG_Q, NG_W, NG_E, NG_R, KC_LEFT, KC_TRNS, KC_RGHT, NG_U, NG_I, NG_O, NG_P, EISU,
        NG_A, NG_S, NG_D, NG_F, NG_G, KC_TRNS, NG_H, NG_J, NG_K, NG_L, NG_SCLN, NG_KOTI,
        NG_Z, NG_X, NG_C, NG_V, NG_B, KC_TRNS, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, NG_TAYO,
    #if layout == 1
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #elif layout == 2
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #endif
    ),
// 薙刀式
#endif

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LGUI | LALT | LSFT | LCTL | XXXX |   "  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |CTLTAB| MIC  | MPLY | MUTE | XXXX |   `  |   '  |   \  |   |  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| ____ |ADJUST| ____ | ____ |     ____    |  ENT | ____ | Bri- | Bri+ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, DE_OE,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO, S(KC_QUOT), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, DE_AE, 
        KC_TRNS, CTL_TAB, KC_MAIL, KC_MPLY, KC_MUTE, KC_NO, KC_GRV, KC_QUOT, KC_NUBS, KC_PIPE, KC_BSLS, DE_ACC_GRV, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_BRID, KC_BRIU, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_BRID, KC_BRIU, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   ~  |   >  |   ,  |   .  |   |  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| ____ | ____ | ____ | BSPC |     ____    | ____ | MAIL | <<|  |  |>> | MUTE | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_oe, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, S(KC_COMM), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, DE_ae, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, S(KC_DOT), LT(0, KC_COMM), LT(0, KC_DOT), KC_PIPE, DE_ACC_ACUT, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, KC_TRNS, C(KC_BSPC), KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |SHTDWN| RESET| XXXX |RGBTOG| AU_ON|AU_OFF| XXXX | KANA | !LANG| DE_SW|JP<>DE| SLEEP|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | RCTL | RSFT | LALT | RGUI | !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | XXXX | XXXX | XXXX | XXXX | UC_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| ____ | ____ | ____ | ____ |     ____    | ____ | MPLY | VOLD | VOLU | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_SYSTEM_POWER, RESET, KC_NO, RGB_TOG, AU_ON, AU_OFF, KC_NO, A(KC_GRV), LANG_SWITCH, KC_DE_SWITCH, A(KC_LSFT), KC_SLEP, 
        KC_NO, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, GAMING, 
        KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, UNICODE_ALT_SW,
    #if layout == 1
        EEPROM_RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS
    #elif layout == 2
        EEPROM_RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ |  Esc |  TAB | LSFT |  Ent | ____ |  ENT |   7  |   8  |   9  |   -  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  | LGUI | LALT | LSFT | LCTL | END  |   *  |   4  |   5  |   6  |   +  |   .  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MUTE | XXXX | XXXX | XXXX |  Ent | XXXX |   =  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_TRNS, KC_ESC, KC_TAB, KC_LSFT, KC_ENT, KC_TRNS, KC_ENT, LT(0, KC_7), LT(0, KC_8), LT(0, KC_9), KC_MINS, KC_BSPC,
        KC_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_END, KC_ASTR, LT(0, KC_4), LT(0, KC_5), LT(0, KC_6), KC_PLUS, LT(0, KC_DOT),
        KC_MUTE, KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_EQL, LT(0, KC_1), LT(0, KC_2), LT(0, KC_3), KC_SLSH, LT(0, KC_COMM),
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(0, KC_0), LT(0, KC_DOT), KC_COMM, KC_EQL, TG(_NUM)
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(0, KC_0), LT(0, KC_DOT), KC_COMM, KC_EQL, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| XXXX | C(->)| XXXX | PASTE| C(<-)|  CUT | REDO | UNDO | COPY | PASTE| BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)| LGUI | LALT | LSFT | LCTL |VIM_GG|  <-  |   ↓  |   ↑  |  ->  | VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX |DESK<-| PGUP | PGDN |DESK->| HOME | PGDN | PGUP |  END | C(F) | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |C-BSPC| BSPC |    _____    |  ENT | HOME |  <-  |  ->  | END  | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, KC_NO, C(KC_RGHT), KC_NO, S(KC_INS), C(KC_LEFT), C(KC_X), REDO, UNDO, C(KC_INS), S(KC_INS), KC_BSPC, 
        CTL_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, TD(TD_VIM_GG), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        KC_TRNS, KC_NO, C(G(KC_LEFT)), KC_PGUP, KC_PGDN, C(G(KC_RGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, C(KC_F), KC_TRNS, 
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, C(KC_BSPC), KC_BSPC, NAVSPACE, NAVSPACE, C(KC_DEL), KC_HOME, KC_LEFT, KC_RIGHT, KC_END 
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, NAVSPACE, NAVSPACE, KC_ENT, KC_HOME, KC_LEFT, KC_RIGHT, KC_END 
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | Bri+ | XXXX |WHL <-| M ↑  |WHL ->| XXXX | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MPLY | BTN 4| M <- | M ↓  | M -> |BTN 5 | XXXX | XXXX | RCTL | RSFT | LALT | RGUI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Bri- | ____ | XXXX |WHL ↑ |WHL ↓ | XXXX | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|!MOUSE| XXXX |BTN 2 |BTN 3 |    BTN 1    | ____ | ____ | Bri- | Bri+ | XXXX | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_BRIU, KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
        KC_MPLY, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_NO, KC_NO, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI,
        KC_BRID, KC_TRNS, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
    #if layout == 1
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_NO
    #elif layout == 2
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_NO
    #endif
    )
};
