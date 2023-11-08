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
     * |      |      |      |  __  |      |      |      |      |  __  |      |      |      |
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
     * |   Q  |   W  |   F  |   P  |   B  | MWHD | MWHU |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |  <-  |  ->  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |   ↓  |   ↑  |   K  |   H  |  ,<  |  .>  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL | LALT |  -_  | LOWER|  SFT |     SPC     | _UML | RAISE|  DEL | APPFN|  GUI | 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, CENT11, CENT12, J_KEY, L_KEY, U_KEY, Y_KEY, QUOT_KEY,
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, CENT21, CENT22, M_KEY, N_KEY, E_KEY,    I_KEY,   O_KEY,
        Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, CENT31, CENT32, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY,
        KC_LCTL, KC_LALT, KC_MINS, LOWER, LTHUMB, NAVSPACE, RTHUMB, RAISE, DEL_KEY, FN_KEY, GUI_KEY
        ),

    /* ----------------------------------------------------------------------------------------
     * _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   F  |   P  |   B  | MWHD | MWHU |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |  <-  |  ->  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |   ↓  |   ↑  |   K  |   H  |  ,<  |  .>  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |  -_  |LWR_DE| ____ |     ___     | ____ |RSE_DE| ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY,    _______, _______, J_KEY, L_KEY, U_KEY, Y_KEY_DE, QUOT_KEY, 
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY,    _______, _______, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, 
        Z_KEY_DE, X_KEY, C_KEY, D_KEY, V_KEY, _______, _______, K_KEY, H_KEY, _______, _______, _______, 
        _______, _______, DE_MINS, LOWER_DE, _______, _______, _______, RAISE_DE, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _GAMING
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ESC |   Q  |   W  |   E  |   R  | MWHD | MWHU |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  TAB |   A  |   S  |   D  |   F  |  <-  |  ->  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  SFT |   Z  |   X  |   C  |   V  |   ↓  |   ↑  |   K  |   H  |  ,<  |  .>  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  CTL |  ALT |   G  | RAISE|  SPC |     ___     | ____ | ____ | ____ | GAME | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_mit(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R,    _______, _______, _______, _______, _______, _______, _______, 
        KC_TAB, KC_A, KC_S, KC_D, KC_F,    _______, _______, _______, _______, _______, _______, _______, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, _______, _______, _______, _______, _______, _______, _______, 
        KC_LCTL, KC_LALT, KC_G, LT(_RAISE, KC_LCTL), KC_SPC, _______, _______, _______, _______, TG(_GAMING), _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Ä  | ____ |   ß  | ____ | ____ | ____ | ____ |  <-  |   ↓  |   ↑  |  ->  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ß  | ____ | ____ | ____ | ____ | ____ | ____ | HOME | PgDn | PgUp |  END | CTRL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_UMLAUTS] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, UE_KEY, _______, AE_KEY,
        AE_KEY, _______, SZ_KEY, _______, _______, _______, _______, KC_LEFT, KC_DOWN, RSFT_T(KC_UP), KC_RIGHT, OE_KEY,
        SZ_KEY,  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_RCTL,
        _______, _______, _______, _______, _______,     _______,       _______, _______, _______,  _______, _______ 
        ),

    /* ----------------------------------------------------------------------------------------
     * _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   e  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   +  |   4  |   5  |   6  |   *  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   %  |   =  |   1  |   2  |   3  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ |   0  |   .  |   ,  | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_mit(
        _______,   _______, _______,  _______, _______, _______, _______, KC_E, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, 
        _______, _______, _______, _______, _______, _______, KC_UNDS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, 
        _______, _______, _______,  _______, _______, _______, KC_PERC, KC_KP_EQUAL, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, 
        _______, _______, _______,  _______, _______, _______, _______,  KC_KP_0, DOT_KEY, COMM_KEY, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | ____ | ____ |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   <  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   >  |   ~  |   ,  |   .  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4),  KC_F5,  KC_F6,   _______, KC_LABK, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  _______, KC_RABK, KC_TILD, KC_COMM, KC_DOT, KC_BSLS, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | ____ | ____ |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   <  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   >  |   ~  |   ,  |   .  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4),  KC_F5,  KC_F6,   _______, DE_LABK, DE_MINS, DE_EQL, DE_LBRC, DE_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  _______, DE_RABK, DE_TILD, DE_COMM, DE_DOT, DE_BSLS, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   >  | ____ |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   "  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   >  |   `  |   ;  |   :  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   _  | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_RABK, _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, 
        LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4),  KC_F5,   KC_F6,   _______, KC_DQUO,  KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  _______, KC_RABK, KC_GRV, KC_SCLN, KC_COLN, KC_PIPE, 
        _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   >  |   §  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   "  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   >  |   `  |   ;  |   :  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   _  | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_RABK, DE_SECT, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, 
        LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4),  KC_F5,   KC_F6,   _______, DE_DQUO, DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  _______,  DE_RABK, DE_GRV, DE_SCLN, DE_COLN, DE_PIPE, 
        _______, _______, _______, _______, _______, _______, DE_UNDS, _______, _______, _______, _______
    ),

    /* ----------------------------------------------------------------------------------------
     * _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * |  ESC | BTN4 | M ↑  | BTN5 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |WHL <-| M <- | M ↓  | M -> |WHL ->| NUM  | MUTE |  F21 | RCTL | RSFT | LALT | RGUI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-|WHL ↑ |WHL ↓ |DESK->| SCRL | MMIC |  F22 |  F23 | BTN4 | BTN5 | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | BTN 3| BTN 2| BTN 1|    _____    | RSFT | RCTL | LLOCK| ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        KC_ESC, KC_BTN4, KC_MS_U, KC_BTN5, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, 
        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_NUM_LOCK, KC_MUTE, KC_F21, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, 
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_SCROLL_LOCK, KC_MMIC, KC_F22, KC_F23, KC_BTN4, KC_BTN5, KC_RSFT,
        _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_RSFT, KC_RCTL, LLOCK, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)|  INS | PSCR | C(<-)| VOL- | VOL+ | KANA | REDO | UNDO | LANG |KBLANG|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL |C-END | BRI- | BRI+ | LEFT | DOWN |  UP  | RIGHT| VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| WHLUP| WHLDN|DESK->| MUTE | MMIC | HOME | PGDN | PGUP |  END | CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH| ____ | ____ | ____ |     ____    | ____ | ____ | ____ | GAME |  AFK | 
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        ALT_TAB, C(KC_RIGHT), KC_INS,  KC_PSCR, C(KC_LEFT), KC_VOLD, KC_VOLU, A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, 
        KC_LGUI, KC_LALT,     KC_LSFT, KC_LCTL, G(A(KC_LCTL)),  KC_BRID, KC_BRIU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O,
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_MUTE, KC_MMIC, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_CAPS, 
        QK_CLEAR_EEPROM, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, TG(_GAMING), KC_AFK
        ),
};