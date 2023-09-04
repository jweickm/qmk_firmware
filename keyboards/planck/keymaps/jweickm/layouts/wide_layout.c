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
     * |   Q  |   W  |   F  |   P  |   B  |  \|  |  ESC |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |  TAB |  ENT |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |  <-  |  ->  |   K  |   H  |  ,<  |  .>  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCTL |  ALT |  BS  |OSMSFT| LOWER|     GUI     | RAISE|NAVSPC|  DEL | APPFN|  GUI | 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, KC_BSLS, KC_ESC, J_KEY, L_KEY, U_KEY, Y_KEY, QUOT_KEY,
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, KC_TAB,  KC_ENT, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY,
        Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, KC_LEFT, KC_RIGHT, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY,
        KC_LCTL, KC_LALT, BS_KEY, OSM(MOD_LSFT), LOWER, NAVGUI, RAISE, NAVSPACE, DEL_KEY, FN_KEY, KC_LGUI
        ),

    /* ----------------------------------------------------------------------------------------
     * _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   F  |   P  |   B  |  \|  |  ESC |   J  |   L  |   U  |   Y  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  |  TAB |  ENT |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |  <-  |  ->  |   K  |   H  |  ,<  |  .>  |  /?  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |LWR_DE|     ___     |RSE_DE| ____ | ____ | ____ |  ENT |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, DE_LBRC, DE_RBRC, J_KEY, L_KEY, U_KEY, Y_KEY_DE, QUOT_KEY, 
        A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, DE_BSLS, DE_MINS, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, 
        Z_KEY_DE, X_KEY, C_KEY, D_KEY, V_KEY, _______, _______, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, 
        _______, _______, _______, LOWER_DE, _______, _______, _______, RAISE_DE, _______, _______, _______
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
        _______, _______, _______, _______, _______, _______, _______, _______, _______, UE_KEY, _______, AE_KEY,
        AE_KEY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OE_KEY,
        SZ_KEY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,       _______, _______, _______,  _______, _______ 
        ),

    /* ----------------------------------------------------------------------------------------
     * _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   e  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   +  |   4  |   5  |   6  |   *  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   %  |   -  |   1  |   2  |   3  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |  SPC |   0  |   .  |   ,  |   =  | 
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_mit(
        S(KC_Q),   S(KC_W), S(KC_F),  S(KC_P), S(KC_B), _______, _______, KC_E, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, 
        S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G), _______, KC_UNDS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, 
        S(KC_Z), S(KC_X), S(KC_C),  S(KC_D), S(KC_V), _______, KC_PERC, KC_KP_MINUS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_SLASH, 
        _______, _______, _______,  _______, _______, _______, KC_SPC,  KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | ____ | ____ |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   <  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   \  |   ~  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,   _______, KC_LABK, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  _______, KC_BSLS, KC_TILD, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  | ____ | ____ |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   <  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   \  |   ~  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ___     | ____ | ____ | ____ | ____ | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    
        KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,   _______, DE_LABK, DE_MINS, DE_EQL,  DE_LBRC, DE_RBRC, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  _______, DE_BSLS, DE_TILD, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   {  |   }  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   "  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   |  |   `  |   ;  |   :  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     | ____ | ____ | ____ | ____ |   >  | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, 
        KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,   _______, KC_DQUO,  KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  _______, KC_PIPE, KC_GRV, KC_SCLN, KC_COLN, KC_BSLS, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RABK
        ),

    /* ----------------------------------------------------------------------------------------
     * _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   {  |   }  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | ____ |   "  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | ____ |   |  |   `  |   ;  |   :  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     | ____ | ____ | ____ | ____ |   >  | 
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_LCBR, DE_RCBR, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, 
        KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,   _______, DE_DQUO, DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, 
        KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  _______,  DE_PIPE,  DE_GRV, DE_SCLN, DE_COLN, DE_BSLS, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_RABK
    ),

    /* ----------------------------------------------------------------------------------------
     * _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * |  ESC | BTN4 | M ↑  | BTN5 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |WHL <-| M <- | M ↓  | M -> |WHL ->| NUM  | MUTE |  F21 | RCTL | RSFT | LALT | RGUI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-|WHL ↑ |WHL ↓ |DESK->| SCRL | RALT |  F22 |  F23 | BTN4 | BTN5 | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | BTN 3| BTN 2| BTN 1|    _____    | RSFT | RCTL | LLOCK| ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        KC_ESC, KC_BTN4, KC_MS_U, KC_BTN5, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, 
        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_NUM_LOCK, KC_MUTE, KC_F21, KC_RCTL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), 
        KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_SCROLL_LOCK, KC_RALT, KC_F22, KC_F23, KC_BTN4, KC_BTN5, KC_RSFT,
        _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_RSFT, KC_RCTL, LLOCK, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)|  INS | PSCR | C(<-)| VOL- | VOL+ | KANA | REDO | UNDO | LANG |KBLANG|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL |C-END | BRI- | BRI+ | LEFT | DOWN |  UP  | RIGHT| VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| WHLUP| WHLDN|DESK->|  ↓   |  ↑   | HOME | PGDN | PGUP |  END | CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH| ____ | ____ | ____ |     ____    | ____ | ____ | ____ |  AFK | ____ | 
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_mit(
        ALT_TAB, C(KC_RIGHT), KC_INS, KC_PSCR, C(KC_LEFT), KC_VOLD, KC_VOLU, A(KC_GRV), REDO, UNDO, _______, _______, 
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, C(KC_END), KC_BRID, KC_BRIU, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O,
        OSM(MOD_LSFT), C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_DOWN, KC_UP, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_CAPS, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* ----------------------------------------------------------------------------------------
     * _FN
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)|  INS | PSCR | C(<-)| VOL- | VOL+ | KANA | REDO | UNDO | LANG |KBLANG|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LGUI | LALT | LSFT | LCTL |C-END | BRI- | BRI+ | LEFT | DOWN |  UP  | RIGHT| VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |DESK<-| WHLUP| WHLDN|DESK->|  ↓   |  ↑   | HOME | PGDN | PGUP |  END | CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH| ____ | ____ | ____ |     LANG    | ____ | ____ | ____ | ____ |  AFK | 
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_planck_mit(
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MMIC, _______, KC_VOLD, KC_VOLU, _______, _______, _______, LANG_SWITCH, KB_LANG_SWITCH, 
        _______, KC_BRID, KC_BRIU, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        QK_CLEAR_EEPROM, QK_BOOT, _______, _______, _______, LANG_SWITCH, _______, _______, _______, _______, KC_AFK
        ),
};