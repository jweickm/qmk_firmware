/* Copyright 2022 Jakob Weickmann
* PLANCK/REV6
*
This program is free software: you can redistribute it and/or modify
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

// adjust as a combo
// nav layer in middle
// but additional tab and esc and enter keys. 
// maybe another space key? or just skip it!
// additional mouse and num layer thumb keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ================================================================================================
     *  ================================================================================================
     * WIDE HAND POSITION for MT3 SUSUWATARI
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
     * |   Q  |   W  |   F  |   P  |   B  | VOL- | VOL+ |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | BRI- | BRI+ |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  | CAPS |  APP |   K  |   H  |   ,  |   .  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ESC | LALT |   BS | LOWER|  SPC |     TAB     |  SPC | RAISE|  DEL |   \| |  ENT | 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, KC_VOLD, KC_VOLU, J_KEY, L_KEY, U_KEY, Y_KEY, QUOT_KEY,
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, KC_BRID, KC_BRIU, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY,
        Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, KC_CAPS, KC_APP, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY,
        ESC_KEY, KC_LALT, BS_KEY, LOWER, NAVSPACE, TAB_KEY, NAVSPACE, RAISE, DEL_KEY, KC_BSLS, KC_ENT
        ),


    /* ----------------------------------------------------------------------------------------
     * _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   F  |   P  |   B  | ____ | ____ |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | ____ | ____ |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  | ____ | ____ |   K  |   H  |   ,  |   .  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |LWR_DE| ____ |     TAB     | ____ |RSE_DE| ____ |  \|  | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, _______, _______, J_KEY, L_KEY, U_KEY, Y_KEY_DE, QUOT_KEY, 
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, _______, _______, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, 
        Z_KEY_DE, X_KEY, C_KEY, D_KEY, V_KEY, _______, _______, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, 
        _______, _______, _______, LOWER_DE, _______, _______, _______, RAISE_DE, _______, DE_BSLS, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Ä  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ß  | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_UMLAUTS] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_UDIA, _______, DE_ADIA,
        DE_ADIA, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_ODIA,
        SZ_KEY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,       _______, _______, _______,  _______, _______ 
        ),

    /* ----------------------------------------------------------------------------------------
     * _NUM
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | LLOCK| ____ |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   .  |   ,  | LCTL | ____ | ____ |   %  |   +  |   4  |   5  |   6  |   *  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   °  |   €  | ____ | ____ | ____ |   _  |   -  |   1  |   2  |   3  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | BSPC | ____ | ____ |     ____    | ____ |   0  |   .  |   ,  |   =  | 
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_mit(
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, LLOCK, _______, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, 
        _______, DOT_KEY, COMM_KEY, KC_LCTL, _______, _______, KC_PERC, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, 
        _______, KC_DEG, DE_EURO,  _______, _______, _______, KC_UNDS, KC_KP_MINUS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, 
        _______, _______, KC_BSPC, _______, _______,  _______,  _______, KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL
        ),

    /* ----------------------------------------------------------------------------------------
     * _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)|  MEH | HYPR | C(<-)| PRNT | ____ | KANA | REDO | UNDO | LANG |KBLANG|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL | LGUI | RALT |  INS | LEFT | DOWN |  UP  | RIGHT| VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| WHLUP| WHLDN|DESK->|NUMLCK| UMLSW| HOME | PGDN | PGUP |  END | CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH| ____ | LOWER| ____ |     ____    | ____ | RAISE| ____ | BRI- | BRI+ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        ALT_TAB, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), KC_PSCR, _______, A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, 
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_LGUI, KC_RALT, KC_INS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O,
        OSM(MOD_LSFT), C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_NUM_LOCK, UMLAUT_SWITCH, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_CAPS, 
        QK_CLEAR_EEPROM, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   ~  |   \  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  <-  |   ~  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ´  |   <  |   \  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | LOWER| ____ |     SPC     | ____ | ____ | MAIL | BRID | BRIU | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   KC_TILD, KC_BSLS,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,   LARROW,     KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_ACC_ACUT, KC_LABK, KC_BSLS, _______, _______, _______, 
        _______, _______, _______, _______, _______, KC_SPC, _______, _______, KC_MAIL, KC_BRID, KC_BRIU
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   ~  |   \  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  <-  |   ~  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ´  |   <  |   \  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | LOWER| ____ |     SPC     | ____ | ____ | MAIL | BRID | BRIU | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   DE_TILD, DE_BSLS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,   LARROW_DE, DE_TILD, DE_MINS, DE_EQL,  DE_LBRC, DE_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  DE_ACUT, DE_LABK, DE_BSLS, _______, _______, _______, 
        _______, _______, _______, _______, _______, KC_SPC, _______, _______, KC_MAIL, KC_BRID, KC_BRIU
    ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   `  |   |  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |>  |   `  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ACC_`|   "  |   |  |   ;  |   :  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     |  ENT | ____ | LEFT | RIGHT| ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_GRV, KC_PIPE,    KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, 
        KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,  RPIPE,    KC_GRV,  KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12, KC_ACC_GRV, KC_DQUO, KC_PIPE, KC_SCLN, KC_COLN, KC_BSLS, 
        _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, KC_LEFT, KC_RIGHT
        ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   `  |   |  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  |>  |   `  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   `  |   "  |   |  |   ;  |   :  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     |  ENT | ____ | LEFT | RIGHT| ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_GRV, DE_PIPE, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, 
        KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,  RPIPE_DE, DE_GRV, DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12, DE_GRV,  DE_DQUO,  DE_PIPE, DE_SCLN, DE_COLN, DE_BSLS, 
        _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, KC_LEFT, KC_RIGHT
    ),

    /* ----------------------------------------------------------------------------------------
     * _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| BTN4 | M ↑  | BTN5 | C-END|C-HOME|  F21 |  F16 |  F17 |  F18 |  F19 |  F20 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |WHL <-| M <- | M ↓  | M -> |WHL ->| ____ | ____ |  F15 | RCTL | RSFT | LALT | RGUI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-|WHL ↑ |WHL ↓ |DESK->| ____ | ____ |  F14 |  F13 | BTN4 | BTN5 |SCRLCK|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | BTN 3| BTN 2| BTN 1|    _____    | RSFT | RCTL | LLOCK| VOL- | VOL+ |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        LLOCK, KC_BTN4, KC_MS_U, KC_BTN5, C(KC_END), C(KC_HOME), KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21,
        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______, _______, KC_F15, KC_RCTL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), 
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), _______, _______, KC_F14, KC_F13, KC_BTN4, KC_BTN5, KC_SCROLL_LOCK,
        _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_RSFT, KC_RCTL, LLOCK, KC_VOLD, KC_VOLU
        ),
};