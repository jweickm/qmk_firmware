const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ================================================================================================
*  ================================================================================================
* WIDE HAND POSITION (2)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |  __  |      |      |      |      |  __  |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      | 
     * `-----------------------------------------------------------------------------------'
     */

/* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |   ü  |_Num-J|  C-L |  S-U |  A-Y |  G-; |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   '  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |_Mo-Z |   X  |   C  |   D  |   V  | Vol- | LEAD |   K  |   H  |   ,  |   .  |_Mo-/ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | ESCM | LOWER| LSFT |   NAV-SPC   | NSPC | RAISE|  ENT | RALT | LEAD | 1x2uC 
     * |                                                                                   |
     * |C-CAPS| LEAD | ESCM | LOWER|     LSFT    |    SPACE    | RAISE|  ENT | RALT | LEAD | 2x2u
     * |                                                                                   |
     * |C-CAPS| LEAD | ESCM | LOWER| LSFT |  ESC |  ENT | NSPC | RAISE|  ENT | RALT | LEAD | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), XP(DE_ue, DE_UE), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN),  
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_QUOT, KC_M, KC_N, KC_E, KC_I, KC_O, 
        LT(_MOUSE, KC_Z), CUT_X, COPY_C, KC_D, PASTE_V, LT(_MOUSE, KC_VOLD), KC_LEAD, KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), 
    #if layout == 1
        LCTL_T(KC_CAPS), KC_LSFT, M_ESCM, LOWER, OSM(MOD_LSFT), NAVSPACE, NAVSPACE, NAVSPACE, RAISE, KC_ENT, KC_RALT, KC_LEAD
    #elif layout == 2
        LCTL_T(KC_CAPS), KC_LSFT, M_ESCM, LOWER, OSM(MOD_LSFT), NAVSPACE, KC_RALT, NAVSPACE, RAISE, KC_ENT, KC_RALT, KC_LEAD
    #elif layout == 3
        LCTL_T(KC_CAPS), KC_LSFT, M_ESCM, LOWER, OSM(MOD_LSFT), KC_ESC, KC_ENT, NAVSPACE, RAISE, KC_ENT, KC_RALT, KC_LEAD
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
     * |                                                                                   |
     * | LCTL |   C  |   B  |   X  |     LALT    |    SPACE    | ENT  | Vol- | Vol+ | !GAME| 2x2u
     * |                                                                                   |
     * | LCTL |   C  |   B  |   X  | LALT |  SPC |  SPC | ENT  | RALT | Vol- | Vol+ | !GAME| grid
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
    #elif layout == 3
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
    #endif
    ),

// ----------------------------------------------------------------------------------------
#ifdef NAGINATA_ENABLE
/* 薙刀式
     * ,-----------------------------------------------------------------------------------.
     * |　小　|き　ぬ|て　り|し　む|　<-  | ____ | EISU |  ->  |　さ　|る　よ|す　え|へ　ゆ|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |ろ　せ|け　め|と　に|か゛ま|っ　ち| ____ | KOTI |く　や|あ゛の|い　も|う　わ|ー　つ|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ほ　|  ひ　|は　を|こ゜、|そ　み| ____ | TATE |た　お|な゜。|ん　ね|ら　ふ|  れ　|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |ENSHFT|   NGSHFT    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ |    ENSHFT   |   NGSHFT    | ____ | ____ | ____ | ____ | 2x2u
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ |ENSHFT| ____ | ____ |NGSHFT| ____ | ____ | ____ | ____ | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
        NG_Q, NG_W, NG_E, NG_R, KC_LEFT, KC_TRNS, EISU, KC_RGHT, NG_U, NG_I, NG_O, NG_P,
        NG_A, NG_S, NG_D, NG_F, NG_G, KC_TRNS, NG_KOTI, NG_H, NG_J, NG_K, NG_L, NG_SCLN, 
        NG_Z, NG_X, NG_C, NG_V, NG_B, KC_TRNS, NG_TAYO, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, 
    #if layout == 1
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #elif layout == 2
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #elif layout == 3
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    #endif
    ),
// 薙刀式
#endif

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   Ö  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   Ä  |   ß  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   è  |   >  |   "  |   \  |   |  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ESC  | ____ |     ____    | ____ |ADJUST| ____ |ADJUST|   ↓  | 1x2uC
     * |                                                                                   |
     * |!MOUSE|ADJUST| ____ | ESC  |     ____    |     ____    |ADJUST| ____ |ADJUST|   ↓  | 2x2u
     * |                                                                                   |
     * |!MOUSE|ADJUST| ____ | ESC  | ____ | ____ |   ↑  | ____ |ADJUST| ____ |ADJUST|   ↓  | grid
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, X(DE_OE), KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_AE), X(DE_SZ), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_EGRAVE, S(KC_DOT), S(KC_QUOT), KC_NUBS, KC_PIPE, KC_BSLS, 
    #if layout == 1
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, OSL(_ADJUST), KC_DOWN
    #elif layout == 2
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, OSL(_ADJUST), KC_DOWN
    #elif layout == 3
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, OSL(_ADJUST), KC_DOWN
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   `  |   ö  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ä  |   ß  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   é  |   <  |   '  |   ,  |   .  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ |ADJUST| ____ |     ____    | ____ |  ENT | ____ |ADJUST|   ↓  | 1x2uC
     * |                                                                                   |
     * |!MOUSE|ADJUST| ____ |ADJUST|     ____    |     ____    |  ENT | ____ |ADJUST|   ↓  | 2x2u
     * |                                                                                   |
     * |!MOUSE|ADJUST| ____ |ADJUST| ____ | ____ |   ↑  | ____ |  ENT | ____ |ADJUST|   ↓  | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, XP(DE_oe, DE_OE), KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, XP(DE_ae, DE_AE), X(DE_SZ), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_EAIGU,  S(KC_COMM), KC_QUOT, KC_COMM, KC_DOT, KC_PIPE,
    #if layout == 1
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_DOWN
    #elif layout == 2
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_DOWN
    #elif layout == 3
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_DOWN
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | A-SFT| RESET| XXXX |RGBTOG| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | A-GRV| XXXX | XXXX | AU_ON|AU_OFF| XXXX | XXXX | XXXX | XXXX | A-GRV| !LANG| !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | DE_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST| 1x2uC
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ |     ____    |     ____    | ____ | ____ | ____ |EEPRST| 2x2u
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST| grid
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        A(KC_LSFT), RESET, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_NUM), 
        A(KC_GRV), KC_NO, KC_NO, AU_ON, AU_OFF, KC_NO, KC_NO, KC_NO, KC_NO, A(KC_GRV), LANG_SWITCH, GAMING, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DE_SWITCH,
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    #elif layout == 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * |  Esc |  F2  |   ↑  |  Ent | ____ |NUMLCK| !NUM | ____ |   7  |   8  |   9  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HOME |  <-  |   ↓  |  ->  | END  | TAB  |   .  |   *  |   4  |   5  |   6  |   +  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MOUSE|  F10 |  F11 |  Ent | Vol- | MUTE |   ,  |   =  |   1  |   2  |   3  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ |   0  |   .  |   ,  |   =  | 1x2uC
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ |     ____    |     ____    |   0  |   .  |   ,  |   =  | 2x2u
     * |                                                                                   |
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ |   0  |   .  |   ,  |   =  | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_F2,  KC_UP,  KC_ENT, KC_TRNS, KC_NLCK, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_MINS, TG(_NUM),
        KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_TAB, KC_ASTR, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_DOT,
        MO(_MOUSE), KC_F10, KC_F11, KC_ENT, KC_VOLD, KC_MUTE, KC_EQL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_COMM,
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    #elif layout == 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| !LANG|A(GRV)| C(<-)| MAIL | BSPC | HOME |  ->  | PGUP | COPY | PASTE|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)|  TAB |  ESC |  ENT |VIM_GG| MPLY | VIM_O|  <-  |   ↓  |   ↑  |  ->  |  END |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |S(DEL)|DESK<-|DESK->| VIM_V| MUTE | DE_SW| HOME | PGDN | LSFT | RFST | C(F) |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |  ESC | CAPS |    UC_SW    | ____ |  ENT | ____ | DE_SW| ____ | 1x2uC
     * |                                                                                   |
     * | ____ | ____ | ____ |  ESC |     CAPS    |     UC_SW   | ____ |  ENT | ____ | DE_SW| 2x2u
     * |                                                                                   |
     * | ____ | ____ | ____ |  ESC | CAPS | ____ | UC_SW| ____ |  ENT | ____ | DE_SW| ____ | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, KC_BSPC, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), 
        CTL_TAB, KC_TAB, KC_ESC, KC_ENT, TD(TD_VIM_GG), KC_MPLY, VIM_O, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END,
        KC_LSFT, S(KC_DEL), C(G(KC_LEFT)), C(G(KC_RGHT)), VIM_V, KC_MUTE, KC_DE_SWITCH, KC_HOME, KC_PGDN, KC_LSFT, KC_RSFT, C(KC_F),
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_CAPS, NAVSPACE, UNICODE_ALT_SW, NAVSPACE, KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_CAPS, NAVSPACE, UNICODE_ALT_SW, NAVSPACE, KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS
    #elif layout == 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_CAPS, NAVSPACE, UNICODE_ALT_SW, NAVSPACE, KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | XXXX | XXXX | MBTN4| MBTN5| XXXX | Bri+ | XXXX | MWHL↑|MAUS↑ | MWHL↑| PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX | MBTN3| MBTN2| MBTN1| XXXX | MPLY | XXXX |MAUS<-|MAUS↓ |MAUS->| PLY1 | REC1 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX | XXXX | BSPC | XXXX | Bri- | XXXX | MWHL↓| XXXX | XXXX | ____ | STOP |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| XXXX | XXXX | ____ | XXXX | MAUS_ACCEL2 | ____ | XXXX | XXXX |  <-  |  ->  | 1x2uC
     * |                                                                                   |
     * |!MOUSE| XXXX | XXXX | ____ | MAUS_ACCEL2 | MAUS_ACCEL2 | XXXX | XXXX |  <-  |  ->  | 2x2uC
     * |                                                                                   |
     * |!MOUSE| XXXX | XXXX | ____ | XXXX |ACCEL2|ACCEL2| ____ | XXXX | XXXX |  <-  |  ->  | grid
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_BTN4, KC_BTN5, KC_NO, KC_BRIU, KC_NO, KC_WH_U, KC_MS_U, KC_WH_U, DM_PLY2, DM_REC2,
        KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MPLY, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, DM_PLY1, DM_REC1,
        KC_TRNS, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_BRID, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS, DM_RSTP,
    #if layout == 1
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    #elif layout == 2
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    #elif layout == 3
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    #endif
    )

};
