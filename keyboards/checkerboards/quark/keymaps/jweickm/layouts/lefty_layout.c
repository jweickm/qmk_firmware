/* Copyright 2022 Jakob Weickmann
* CHECKERBOARDS QUARK
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ================================================================================================
     *  ================================================================================================
     * WIDE HAND POSITION for KAT BOW
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |  __  |      |      |  __  |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    /* ----------------------------------------------------------------------------------------
     * _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |  ;:  |  \|  |  ESC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '"  |  ENT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |  ,<  |  .>  |  /?  |  UP  |  FN  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL | LALT |  TAB | LOWER| LSFT |    RAISE    |  DEL |  GUI | LEFT | DOWN | RIGHT| 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, ESC_KEY,
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY,    I_KEY,   O_KEY, QUOT_KEY, ENT_KEY,
        Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, KC_UP, FN_KEY,
        KC_LCTL, KC_LALT, TAB_KEY, LOWER, LTHUMB, RAISE, DEL_KEY, KC_LGUI, KC_LEFT, KC_DOWN, KC_RIGHT
        ),

    /* ----------------------------------------------------------------------------------------
     * _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   Ö  |   Ü  |  ESC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   Ä  |  ENT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |  ,<  |  .>  |  /?  |  UP  |  FN  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL | LALT |  TAB | LOWER| LSFT |    RAISE    |  DEL |  GUI | LEFT | DOWN | RIGHT| 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY,    J_KEY, L_KEY, U_KEY, Y_KEY_DE, SCLN_KEY, DE_UDIA, _______,
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY,    M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, DE_ADIA, _______,
        Z_KEY_DE, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, _______, _______, _______, _______, _______, 
        _______, _______, _______, LOWER_DE, _______, RAISE_DE, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _GAMING
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ESC |   Q  |   W  |   E  |   R  | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  TAB |   A  |   S  |   D  |   F  | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  SFT |   Z  |   X  |   C  |   V  | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  CTL |  ALT |   G  | RAISE|  SPC |     SPC     | ____ | GAME | ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_mit(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R,    _______, _______, _______, _______, _______, _______, _______, 
        KC_TAB, KC_A, KC_S, KC_D, KC_F,    _______, _______, _______, _______, _______, _______, _______, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, _______, _______, _______, _______, _______, _______, _______, 
        KC_LCTL, KC_LALT, KC_G, LT(_RAISE, KC_LCTL), KC_SPC, KC_SPC, _______, TG(_GAMING), _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  |   ß  |   Ö  |   Ü  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Ä  | ____ |   ß  | ____ | ____ |  <-  |   ↓  |   ↑  |  ->  |   Ö  |   Ä  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ß  | ____ | ____ | ____ | ____ | HOME | PgDn | PgUp |  END | CTRL | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_UMLAUTS] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, UE_KEY, SZ_KEY, AE_KEY,        _______, _______, 
        AE_KEY, _______, SZ_KEY, _______, _______,   KC_LEFT, KC_DOWN, RSFT_T(KC_UP), KC_RIGHT, OE_KEY,_______, _______, 
        SZ_KEY,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LCTL,       _______, _______, 
        _______, _______, _______, _______, _______,     _______,       _______, _______, _______,  _______, _______ 
        ),

    /* ----------------------------------------------------------------------------------------
     * _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ |   e  |   7  |   8  |   9  |   0  |   \  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |   _  |   +  |   4  |   5  |   6  |   *  |   _  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |   %  |   =  |   1  |   2  |   3  |   /  |   %  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |      0      |   .  |   ,  |   =  | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, KC_E, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_BSLS, _______,
        _______, _______, _______, _______, KC_UNDS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_UNDS, _______,
        _______, _______, _______, _______, KC_PERC, KC_KP_EQUAL, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, KC_PERC, _______,
        _______, _______, _______, _______, KC_SPC, KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |   `  |   ^  |   &  |   *  |   (  |   )  |   \  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F5  |  F6  |  F7  |  F8  |   °  |   <  |   -  |   =  |   [  |   ]  |   '  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F9  |  F10 |  F11 |  F12 |   §  |   >  |   ~  |   ,  |   .  |   /  | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |  SPC |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_GRV, KC_CIRC, KC_PERC, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, _______, 
        LGUI_T(KC_F5), LALT_T(KC_F6), LSFT_T(KC_F7), LCTL_T(KC_F8), _______, KC_LABK, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_QUOT, _______, 
        KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_RABK, KC_TILD, KC_COMM, KC_DOT, KC_SLSH, _______, _______,
        _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |   `  |   ^  |   &  |   *  |   (  |   )  |   \  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F5  |  F6  |  F7  |  F8  |   °  |   <  |   -  |   =  |   [  |   ]  |   '  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F9  |  F10 |  F11 |  F12 |   §  |   >  |   ~  |   ,  |   .  |   /  | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |  SPC |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        KC_F1, KC_F2, KC_F3, KC_F4, DE_GRV, DE_CIRC, DE_PERC, DE_ASTR, DE_LPRN, DE_RPRN, DE_BSLS, _______, 
        LGUI_T(KC_F5), LALT_T(KC_F6), LSFT_T(KC_F7), LCTL_T(KC_F8), DE_DEG, DE_LABK, DE_MINS, DE_EQL, DE_LBRC, DE_RBRC, DE_QUOT, _______, 
        KC_F9, KC_F10, KC_F11, KC_F12, DE_SECT, DE_RABK, DE_TILD, DE_COMM, DE_DOT, DE_SLSH, _______, _______,
        _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______, _______
    ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   1  |   2  |   3  |   4  |   5  |   "  |   _  |   +  |   {  |   }  |   "  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   6  |   7  |   8  |   9  |   0  |   >  |   `  |   ;  |   :  |   ?  | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______, 
        LGUI_T(KC_1), LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4),  KC_5, KC_DQUO,  KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO, _______, 
        KC_6,   KC_7, KC_8,   KC_9, KC_0,  KC_RABK, KC_GRV, KC_SCLN, KC_COLN, KC_QUES, _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   1  |   2  |   3  |   4  |   5  |   "  |   _  |   +  |   {  |   }  |   "  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   6  |   7  |   8  |   9  |   0  |   >  |   `  |   ;  |   :  |   ?  | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_CIRC, DE_AMPR,  DE_ASTR, DE_LPRN, DE_RPRN, DE_PIPE, _______, 
        LGUI_T(KC_1), LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4),  KC_5, DE_DQUO,  DE_UNDS,  DE_PLUS, DE_LCBR, DE_RCBR, DE_DQUO, _______, 
        KC_6,   KC_7, KC_8,   KC_9, KC_0,  DE_RABK, DE_GRV, DE_SCLN, DE_COLN, DE_QUES, _______,  _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* ----------------------------------------------------------------------------------------
     * _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * |  ESC | BTN4 | M ↑  | BTN5 |  F13 |  F16 |  F17 |  F18 |  F19 |  F20 | MUTE | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |WHL <-| M <- | M ↓  | M -> |WHL ->|  F14 | LCTL | RSFT | LALT | RGUI |  MIC | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-|WHL ↑ |WHL ↓ |DESK->|  F15 |  F23 | BTN4 | BTN5 | RSFT | ____ | LLOCK|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | BTN 1| BTN 3|    BTN 2    | RSFT | LCTL | ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        KC_ESC, KC_BTN4, KC_MS_U, KC_BTN5, KC_F13, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_MUTE, _______,
        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_F21, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_MMIC, _______, 
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_F22, KC_F23, KC_BTN4, KC_BTN5, KC_RSFT, _______, LLOCK, 
        _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_RSFT, KC_LCTL, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)|  INS | PSCR | C(<-)| KANA | REDO | UNDO | LANG |KBLANG| MPRV | MNXT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL |C-END | LEFT | DOWN |  UP  | RIGHT| VIM_O| MUTE | MMIC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END | MPLY | VOL+ |  AFK |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH| ____ | ____ | MPLY |     ____    | ____ | GAME | BRI- | VOL- | BRI+ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        ALT_TAB, C(KC_RIGHT), KC_INS, KC_PSCR, C(KC_LEFT), A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, KC_MPRV, KC_MNXT, 
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, G(A(KC_LCTL)), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_MUTE, KC_MMIC, 
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_MPLY, KC_VOLU, KC_AFK, 
        QK_CLEAR_EEPROM, QK_BOOT, _______, _______, KC_MPLY, _______, _______, TG(_GAMING), KC_BRID, KC_VOLD, KC_BRIU
        ),
};