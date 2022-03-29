const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ================================================================================================
*  ================================================================================================
* SEMI-WIDE HAND POSITION (1)
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
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |_Num-J|  C-L |  S-U |  A-Y |  G-; |   ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   M  |   N  |   E  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  | Vol- |   K  |   H  |   ,  |   .  |   /  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  ESC | LOWER| LSFT |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ |S-RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
#if homerow_mods == 1
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), KC_B, LT(_MOUSE, KC_VOLU), KC_J, RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), LT(0, DE_UDIA), //XP(DE_ue, DE_UE),  
        KC_A, KC_R, LSFT_T(KC_S), KC_T, KC_G, KC_TAB, KC_M, KC_N, RSFT_T(KC_E), KC_I, KC_O, LT(0, KC_QUOT), //KC_QUOT, 
#elif homerow_mods == 2
        KC_Q, KC_W, KC_F, KC_P, KC_B, LT(_MOUSE, KC_VOLU), KC_J, KC_L, KC_U, KC_Y, LT(0, KC_SCLN), LT(0, DE_UDIA), //XP(DE_ue, DE_UE),  
        LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_TAB, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), LT(0, KC_QUOT), //KC_QUOT,
#endif
        LT(0, KC_Z), CUT_X, COPY_C, KC_D, PASTE_V, LT(_MOUSE, KC_VOLD), KC_K, KC_H, LT(0, KC_COMM), LT(0, KC_DOT), LT(0, KC_SLSH), LT(0, KC_MINS), 
    #if layout == 1
        LCTL_T(KC_CAPS), KC_LGUI, LT(_NUM, KC_ESC), LOWER, OSM(MOD_LSFT), NAVSPACE, NAVSPACE, RAISE, LT(_MOUSE, KC_DEL), LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP), RSFT_T(KC_RALT)
    #elif layout == 2
        LCTL_T(KC_CAPS), KC_LGUI, LT(_NUM, KC_ESC), LOWER, LSFT_T(KC_BSPC), NAVSPACE, NAVSPACE, RAISE, LT(_MOUSE, KC_DEL), LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP), RSFT_T(KC_RALT)
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
     * ,-----------------------------------------------------------------------------------.
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
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL | XXXX | XXXX |   "  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CTLTAB| XXXX | XXXX | XXXX | XXXX | XXXX |   ~  |   `  |   \  |   |  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ____ | ____ |     ____    |  DEL | ____ | ____ | ____ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, DE_OE,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NO, KC_NO, S(KC_QUOT), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, DE_AE, 
        CTL_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TILD, KC_GRV, KC_NUBS, KC_PIPE, KC_BSLS, DE_ACC_GRV, 
    #if layout == 1
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   `  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   <  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ~  |   >  |   ,  |   .  |   |  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| ____ | ____ | BSPC | ____ |     ____    | ____ | ____ |ADJUST| ____ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, KC_6, KC_7, KC_8, KC_9, KC_0, DE_oe, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, S(KC_COMM), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, DE_ae, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TILD, S(KC_DOT), LT(0, KC_COMM), LT(0, KC_DOT), KC_PIPE, DE_ACC_ACUT, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |SHTDWN| RESET| XXXX |RGBTOG| AU_ON|AU_OFF| XXXX | KANA | !LANG| DE_SW|JP<>DE| SLEEP|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | XXXX | RCTL | RSFT | LALT | RGUI | !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | XXXX | XXXX | XXXX | XXXX | XXXX | UC_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | RESET| ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST| 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_SYSTEM_POWER, RESET, KC_NO, RGB_TOG, AU_ON, AU_OFF, KC_NO, A(KC_GRV), LANG_SWITCH, KC_DE_SWITCH, A(KC_LSFT), KC_SLEP, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, KC_NO, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, GAMING, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UNICODE_ALT_SW,
    #if layout == 1
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    #elif layout == 2
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * |  Esc |  TAB | LSFT |  Ent | ____ | XXXX |  ENT |   7  |   8  |   9  |   -  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL | END  | TAB  |   *  |   4  |   5  |   6  |   +  |   .  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX | XXXX | XXXX |  Ent | XXXX | MUTE |   =  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_TAB, KC_LSFT, KC_ENT, KC_TRNS, KC_NO, KC_ENT, LT(0, KC_7), LT(0, KC_8), LT(0, KC_9), KC_MINS, KC_BSPC,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_END, KC_TAB, KC_ASTR, LT(0, KC_4), LT(0, KC_5), LT(0, KC_6), KC_PLUS, LT(0, KC_DOT),
        KC_NO, KC_NO, KC_NO, KC_ENT, KC_NO, KC_MUTE, KC_EQL, LT(0, KC_1), LT(0, KC_2), LT(0, KC_3), KC_SLSH, LT(0, KC_COMM),
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(0, KC_0), LT(0, KC_DOT), KC_COMM, KC_EQL, TG(_NUM)
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(0, KC_0), LT(0, KC_DOT), KC_COMM, KC_EQL, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| XXXX | PASTE| C(<-)| MAIL |  CUT | REDO | UNDO | COPY | PASTE| BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL |VIM_GG| MPLY |  <-  |   ↓  |   ↑  |  ->  | VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| PGUP | PGDN |DESK->| MUTE | HOME | PGDN | PGUP |  END | C(F) | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | BSPC | ____ |    _____    |  ENT | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, C(KC_RGHT), KC_NO, S(KC_INS), C(KC_LEFT), KC_MAIL, C(KC_X), REDO, UNDO, C(KC_INS), S(KC_INS), KC_BSPC, 
        CTL_TAB, KC_LALT, KC_LSFT, KC_LCTL, TD(TD_VIM_GG), KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        KC_LSFT, C(G(KC_LEFT)), KC_PGUP, KC_PGDN, C(G(KC_RGHT)), KC_MUTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END, C(KC_F), KC_TRNS, 
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | XXXX |WHL <-| M ↑  |WHL ->| XXXX | Bri+ | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | BTN 4| M <- | M ↓  | M -> |BTN 5 | MPLY | XXXX | XXXX | RCTL | RSFT | LALT | RGUI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX |WHL ↑ |WHL ↓ | XXXX | Bri- | XXXX | STOP | PLY1 | REC1 | PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|!MOUSE| XXXX |BTN 2 |BTN 3 |    BTN 1    | ____ | ____ |  <-  |  ->  | XXXX | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_BRIU, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
        KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_MPLY, KC_NO, KC_NO, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI,
        KC_TRNS, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_BRID, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
    #if layout == 1
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_NO, KC_LEFT, KC_RIGHT, KC_NO
    #elif layout == 2
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_TRNS, KC_NO, KC_LEFT, KC_RIGHT, KC_NO
    #endif
    )
};
