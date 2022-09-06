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
     * |      |      |      |      |             |             |      |      |      |      | 
     * `-----------------------------------------------------------------------------------'
     */

/* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  | ;: Ö | \| Ü |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | '" Ä |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |  ENT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  ENT | LOWER BSPC  | RAISE SPACE |  DEL | Mo ↓ | Mo ↑ |A_RALT| 2x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_2x2u(
        ESC_KEY, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, // LT(0, DE_UDIA), 
        KC_TAB, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, // KC_QUOT, 
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, RSFT_T(KC_ENT), 
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER,  RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
), 

/* ----------------------------------------------------------------------------------------
* _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  | ____ |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Ä  | ____ |  SFT | ____ | ____ | ____ | ____ |  SFT | ____ |   Ö  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |     ____    |     ____    | ____ | ____ | ____ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_UMLAUTS] = LAYOUT_planck_2x2u(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_UE, KC_TRNS, DE_OE, DE_UE,
        KC_TRNS, DE_AE, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, DE_OE, DE_AE, 
        KC_TRNS, DE_SZ, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | VIM_O| LEFT |  UP  | DOWN | RIGHT|   `  |   _  |   +  |   [  |   ]  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |CTLTAB| HOME | PGUP | PGDN |  END |   ~  |   '  |   <  |   >  |   -  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ |     ____    |    ADJUST   | ____ | Bri- | Bri+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_2x2u(
        ALT_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, KC_PIPE,
        CTL_TAB, VIM_O, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_GRV, KC_UNDS, KC_PLUS, TD(TD_BRC), KC_RBRC, S(KC_QUOT), 
        NAVSFT, CTL_TAB, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_TILD, KC_QUOT, TD(TD_LARROW), TD(TD_RARROW), KC_MINS, DE_ACC_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS
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
     * | ____ | ____ |ADJUST| ____ |    ADJUST   |     ____    | MAIL | <<|  |  |>> | MUTE | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_2x2u(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, S(KC_COMM), KC_MINS, KC_EQL, TD(TD_CBR), KC_RCBR, KC_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, S(KC_DOT), COMM_KEY, DOT_KEY, KC_UNDS, DE_ACC_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ |   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   ;  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   *  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | !NUM | ____ | ____ | ____ |     ____    |      0      |   .  |   ,  |   =  | !NUM | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_2x2u(
        KC_TRNS, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_MINS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS,
        TG(_NUM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, DOT_KEY, COMM_KEY, KC_EQL, TG(_NUM)
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
     * |!MOUSE|!MOUSE| XXXX |BTN 2 |    BTN 1    |    BTN 3    | ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_2x2u(
        KC_TRNS, TG(_MOUSE), KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
        KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_NO, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_TRNS, 
        KC_TRNS, KC_ACL0, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, DM_RSTP, DM_PLY1, DM_REC1, DM_PLY2, DM_REC2,
        TG(_MOUSE), TG(_MOUSE), KC_NO, KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | ____ | XXXX | C(->)|  TAB | XXXX | C(<-)| XXXX | KANA | !LANG| DE_SW|JP<>DE| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LGUI | LALT | LSFT | LCTL |VIM_GG| LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX |DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END | CD_SW| MUTE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| RESET| ____ | ____ |     ____    |     ____    | MPLY | VOLD | VOLU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_2x2u(
        KC_TRNS, KC_NO, C(KC_RIGHT), KC_TAB, KC_NO, C(KC_LEFT), KC_NO, A(KC_GRV), LANG_SWITCH, KC_DE_SWITCH, A(KC_LSFT), KC_TRNS, 
        KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, TD(TD_VIM_GG), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        KC_TRNS, KC_NO, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, CODING_SW, KC_MUTE,
        EEPROM_RESET, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS
    ),
};
