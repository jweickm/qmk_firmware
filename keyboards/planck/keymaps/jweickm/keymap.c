/* Copyright 2015-2017 Jack Humbert
 * Copyright 2021 Jakob Weickmann
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
#include "jweickm_header.h"
#include "jweickm_process_record_user.h"
#define layout 1 // 1: 1x2uC, 2: 2x2u, 3: grid

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* =========================================================================================
*                        ██ ██   ██ ██████  ██    ██  ██████ 
*                       ███  ██ ██       ██ ██    ██ ██      
*                        ██   ███    █████  ██    ██ ██      
*                        ██  ██ ██  ██      ██    ██ ██      
*                        ██ ██   ██ ███████  ██████   ██████ 
* ==========================================================================================
*/
#if layout == 1

/*_COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |_Num-J|  C-L |  S-U |  A-Y |  G-/ |   ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   M  |   N  |   E  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |_Mo-Z |   X  |   C  |   D  |   V  | Vol- |   K  |   H  |   ,  |   .  |_Mo-/ | LEAD |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | BSPC | LOWER| LSFT |  _Nav-SPC   | RAISE| S-DEL| RALT |_Mo ↓ |_Mo ↑ |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), XP(DE_ue, DE_UE), 
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        LT(_MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, LT(_MOUSE, KC_VOLD), KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), KC_LEAD, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), LT(_RAISE, KC_ENT), RSFT_T(KC_DEL), KC_RALT, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
* same as above, when the PC is set to German layout
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B|Vol/B+|_Num-J|  C-L |  S-U |  A-Y |  G-/ |   ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   M  |   N  |   E  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |_Mo-Z |   X  |   C  |   D  |   V  |Vol/B-|   K  |   H  |   ,  |   .  |_Mo-/ | LEAD |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | ESCM | LOWER| LSFT |  _Nav-SPC   | RAISE| S-DEL| RALT |_Mo ↓ |_Mo ↑ |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), XP(DE_ue, DE_UE),
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        LT(_MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, LT(_MOUSE, KC_VOLD), KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), KC_LEAD, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER_DE, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), LT(_RAISE_DE, KC_ENT), RSFT_T(KC_DEL), KC_RALT, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
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
     * | LCTL |   C  |   B  |   X  | LALT |    SPACE    | ENT  | RALT | Vol- | Vol+ | !GAME|
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_F5, KC_F8, KC_F9, KC_BSPC, 
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, C(G(KC_LEFT)), C(G(KC_RGHT)), 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_Z, KC_M, KC_SCLN, KC_TRNS, 
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
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
     * | ____ | ____ | ____ | ____ |ENSHFT|   NGSHFT    | ____ | ____ | ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
        NG_Q, NG_W, NG_E, NG_R, KC_LEFT, KC_TRNS, KC_RGHT, NG_U, NG_I, NG_O, NG_P, EISU,
        NG_A, NG_S, NG_D, NG_F, NG_G, KC_TRNS, NG_H, NG_J, NG_K, NG_L, NG_SCLN, NG_KOTI, 
        NG_Z, NG_X, NG_C, NG_V, NG_B, KC_TRNS, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, NG_TAYO, 
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    #endif
// 薙刀式

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   >  |   "  |   \  |   |  |   \  |   è  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ESC  | ____ |     ____    |  DEL | EISU |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, X(DE_OE), 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_SZ), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, X(DE_AE), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_DOT), S(KC_QUOT), KC_NUBS, KC_PIPE, KC_BSLS, DE_EGRAVE, 
    #ifdef NAGINATA_ENABLE
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_DEL, EISU, ADJUST, KC_DOWN, KC_UP
    #else
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_DEL, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   >  |   "  |   \  |   |  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ESC  | ____ |     ____    |  DEL | ____ |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_grid(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_TILD, DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN), DE_RPRN, S(DE_ODIA), 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SS, DE_UNDS, DE_PLUS, TD(TD_CBR), DE_RCBR, S(DE_ADIA), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_RABK, DE_DQUO, DE_BSLS, DE_PIPE, DE_BSLS, DE_GRV, 
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   `  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |   '  |   ,  |   .  |   |  |   é  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| KANA | BSPC | ____ |     ____    |  ENT | ____ |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, KC_6, KC_7, KC_8, KC_9, KC_0, XP(DE_oe, DE_OE), 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_SZ), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, XP(DE_ae, DE_AE), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_COMM), KC_QUOT, KC_COMM, KC_DOT, KC_PIPE, DE_EAIGU, 
    #ifdef NAGINATA_ENABLE
        TG(_MOUSE), ADJUST, KANA2, KC_BSPC, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    #else
        TG(_MOUSE), ADJUST, KC_TRNS, KC_BSPC, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   °  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |   '  |   ,  |   .  |   |  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | BSPC | ____ |     ____    |  ENT | ____ |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, S(KC_GRV), KC_6, KC_7, KC_8, KC_9, KC_0, DE_ODIA, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SS, DE_MINS, DE_EQL, TD(TD_BRC), DE_RBRC, DE_ADIA, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_LABK, DE_QUOT, KC_COMM, KC_DOT, DE_PIPE, DE_ACUT, 
        TG(_MOUSE), ADJUST, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | A-SFT| RESET| XXXX |RGBTOG| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | A-GRV| XXXX | XXXX | AU_ON|AU_OFF| XXXX | XXXX | XXXX | XXXX | A-GRV| !LANG| !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        A(KC_LSFT), RESET, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_NUM), 
        A(KC_GRV), KC_NO, KC_NO, AU_ON, AU_OFF, KC_NO, KC_NO, KC_NO, KC_NO, A(KC_GRV), LANG_SWITCH, GAMING, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * |  Esc |  F2  |   ↑  |  Ent | ____ |NUMLCK| ____ |   7  |   8  |   9  |   -  | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HOME |  <-  |   ↓  |  ->  | END  | TAB  |   *  |   4  |   5  |   6  |   +  |   .  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MOUSE|  F10 |  F11 |  Ent | Vol- | MUTE |   =  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_F2,  KC_UP,  KC_ENT, KC_TRNS, KC_NLCK, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_MINS, TG(_NUM),
        KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_TAB, KC_ASTR, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_DOT,
        MO(_MOUSE), KC_F10, KC_F11, KC_ENT, KC_VOLD, KC_MUTE, KC_EQL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_COMM,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| !LANG|A(GRV)| C(<-)| MAIL | HOME |  ->  | PGUP | COPY | PASTE|NAG-SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)|  TAB |  ESC |  ENT |VIM_GG| MPLY |  <-  |   ↓  |   ↑  |  ->  |  END | VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |S(DEL)|DESK<-|DESK->| VIM_V| MUTE | HOME | PGDN | LSFT | RFST | C(F) | DE_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |  ESC | CAPS |     ____    |  ENT | ____ | DE_SW| ____ | UC_SW|
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
    #ifdef NAGINATA_ENABLE
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), NAGINATA_SWITCH,
    #else
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), KC_BSPC,
    #endif
        CTL_TAB, KC_TAB, KC_ESC, KC_ENT, TD(TD_VIM_GG), KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, VIM_O,
        KC_LSFT, S(KC_DEL), C(G(KC_LEFT)), C(G(KC_RGHT)), VIM_V, KC_MUTE, KC_HOME, KC_PGDN, KC_LSFT, KC_RSFT, C(KC_F), KC_DE_SWITCH,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_CAPS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS, UNICODE_ALT_SW
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
     * |!MOUSE| XXXX | XXXX | ____ | XXXX | MAUS_ACCEL2 | ____ | XXXX | XXXX |  <-  |  ->  |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_BTN4, KC_BTN5, KC_NO, KC_BRIU, KC_NO, KC_WH_U, KC_MS_U, KC_WH_U, DM_PLY2, DM_REC2,
        KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MPLY, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, DM_PLY1, DM_REC1,
        KC_TRNS, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_BRID, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS, DM_RSTP,
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    )

/* =========================================================================================
*    ██████  ██████  ██ ██████      ██       █████  ██    ██  ██████  ██    ██ ████████ 
*   ██       ██   ██ ██ ██   ██     ██      ██   ██  ██  ██  ██    ██ ██    ██    ██    
*   ██   ███ ██████  ██ ██   ██     ██      ███████   ████   ██    ██ ██    ██    ██    
*   ██    ██ ██   ██ ██ ██   ██     ██      ██   ██    ██    ██    ██ ██    ██    ██    
*    ██████  ██   ██ ██ ██████      ███████ ██   ██    ██     ██████   ██████     ██    
*  =========================================================================================
*/
#elif layout == 3
/*
 * _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |   ü  |_Num-J|  C-L |  S-U |  A-Y |  G-/ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   '  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |_Mo-Z |   X  |   C  |   D  |   V  | Vol- | LEAD |   K  |   H  |   ,  |   .  |_Mo-/ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | BSPC | LOWER| LSFT | NSPC | RALT | NSPC | RAISE| S-DEL|_Mo ↓ |_Mo ↑ |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), XP(DE_ue, DE_UE), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN),  
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_QUOT, KC_M, KC_N, KC_E, KC_I, KC_O, 
        LT(_MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, LT(_MOUSE, KC_VOLD), KC_LEAD, KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), KC_RALT, LT(_NAV, KC_SPC), LT(_RAISE, KC_ENT), RSFT_T(KC_DEL), LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |   ü  |_Num-J|  C-L |  S-U |  A-Y |  G-/ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   '  |   M  |   N  |   E  |   I  |   O  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |_Mo-Z |   X  |   C  |   D  |   V  | Vol- | LEAD |   K  |   H  |   ,  |   .  |_Mo-/ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | BSPC | LOWER| LSFT | NSPC | RALT | NSPC | RAISE| S-DEL|_Mo ↓ |_Mo ↑ |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), M_RGUI_SCLN, DE_UDIA, 
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        LT(_MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, LT(_MOUSE, KC_VOLD), KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), KC_LEAD, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER_DE, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), KC_RALT, LT(_NAV, KC_SPC), LT(_RAISE_DE, KC_ENT), RSFT_T(KC_DEL), LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
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
     * | LCTL |   C  |   B  |   X  | LALT |    SPACE    | ENT  | RALT | Vol- | Vol+ | !GAME|
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_F5, KC_F8, KC_F9, KC_BSPC, 
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, C(G(KC_LEFT)), C(G(KC_RGHT)), 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_Z, KC_M, KC_SCLN, KC_TRNS, 
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
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
     * | ____ | ____ | ____ | ____ |ENSHFT|   NGSHFT    | ____ | ____ | ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
        NG_Q, NG_W, NG_E, NG_R, KC_LEFT, KC_TRNS, EISU, KC_RGHT, NG_U, NG_I, NG_O, NG_P,
        NG_A, NG_S, NG_D, NG_F, NG_G, KC_TRNS, NG_KOTI, NG_H, NG_J, NG_K, NG_L, NG_SCLN, 
        NG_Z, NG_X, NG_C, NG_V, NG_B, KC_TRNS, NG_TAYO, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, 
        KC_TRNS, KC_LGUI, LALT_T(KC_ESC), KC_TRNS, NG_SHFT2, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
     * |!MOUSE|ADJUST| ____ | ESC  | ____ | ____ |   ↑  | ____ |  DEL | EISU |ADJUST|   ↓  |
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, X(DE_OE), KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_AE), X(DE_SZ), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_EGRAVE, S(KC_DOT), S(KC_QUOT), KC_NUBS, KC_PIPE, KC_BSLS, 
    #ifdef NAGINATA_ENABLE
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, LT(_NAV, KC_SPC), KC_UP, LT(_NAV, KC_SPC), KC_DEL, EISU, ADJUST, KC_DOWN
    #else
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, LT(_NAV, KC_SPC), KC_UP, LT(_NAV, KC_SPC), KC_DEL, KC_TRNS, ADJUST, KC_DOWN
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   Ö  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   Ä  |   ß  |   _  |   +  |   {  |   }  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   `  |   >  |   "  |   \  |   |  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ESC  | ____ | ____ |   ↑  | ____ |  DEL | EISU |ADJUST|   ↓  |
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER_DE] = LAYOUT_planck_grid(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_TILD, S(DE_ODIA), DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN), DE_RPRN,
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, S(DE_ADIA), DE_SS, DE_UNDS, DE_PLUS, TD(TD_CBR), DE_RCBR,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_GRV, DE_RABK, DE_DQUO, DE_BSLS, DE_PIPE, DE_BSLS,
        TG(_MOUSE), ADJUST, KC_TRNS, KC_ESC, KC_TRNS, LT(_NAV, KC_SPC), KC_UP, LT(_NAV, KC_SPC), KC_DEL, KC_TRNS, ADJUST, KC_DOWN
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
     * |!MOUSE|ADJUST| KANA | BSPC | ____ | ____ |   ↑  | ____ |  ENT | ____ |ADJUST|   ↓  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, XP(DE_oe, DE_OE), KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, XP(DE_ae, DE_AE), X(DE_SZ), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_EAIGU,  S(KC_COMM), KC_QUOT, KC_COMM, KC_DOT, KC_PIPE,
    #ifdef NAGINATA_ENABLE
        TG(_MOUSE), ADJUST, KANA2, KC_BSPC, KC_TRNS, LT(_NAV, KC_SPC), KC_UP, LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, ADJUST, KC_DOWN
    #else
        TG(_MOUSE), ADJUST, KC_TRNS, KC_BSPC, KC_TRNS, LT(_NAV, KC_SPC), KC_UP, LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, ADJUST, KC_DOWN
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   °  |   ö  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ä  |   ß  |   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   é  |   <  |   '  |   ,  |   .  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| KANA | BSPC | ____ | ____ |   ↑  | ____ |  ENT | ____ |ADJUST|   ↓  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, S(KC_GRV), DE_ODIA, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_ADIA, DE_SS, DE_MINS, DE_EQL, TD(TD_BRC), DE_RBRC,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_ACUT, DE_LABK, DE_QUOT, KC_COMM, KC_DOT, DE_PIPE,
        TG(_MOUSE), ADJUST, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_ENT, KC_TRNS, ADJUST, KC_DOWN
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | A-SFT| RESET| XXXX |RGBTOG| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | A-GRV| XXXX | XXXX | AU_ON|AU_OFF| XXXX | XXXX | XXXX | XXXX | A-GRV| !LANG| !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        A(KC_LSFT), RESET, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(_NUM), 
        A(KC_GRV), KC_NO, KC_NO, AU_ON, AU_OFF, KC_NO, KC_NO, KC_NO, KC_NO, A(KC_GRV), LANG_SWITCH, GAMING, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * |  Esc |  F2  |   ↑  |  Ent | ____ |NUMLCK| ____ |   7  |   8  |   9  |   -  | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HOME |  <-  |   ↓  |  ->  | END  | TAB  |   *  |   4  |   5  |   6  |   +  |   .  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MOUSE|  F10 |  F11 |  Ent | Vol- | MUTE |   =  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_F2,  KC_UP,  KC_ENT, KC_TRNS, KC_NLCK, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_MINS, TG(_NUM),
        KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_TAB, KC_ASTR, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_DOT,
        MO(_MOUSE), KC_F10, KC_F11, KC_ENT, KC_VOLD, KC_MUTE, KC_EQL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_COMM,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| !LANG|A(GRV)| C(<-)| MAIL |NAG-SW| HOME |  ->  | PGUP | COPY | PASTE|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)|  TAB |  ESC |  ENT |VIM_GG| MPLY | VIM_O|  <-  |   ↓  |   ↑  |  ->  |  END |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |S(DEL)|DESK<-|DESK->| VIM_V| MUTE | DE_SW| HOME | PGDN | LSFT | RFST | C(F) |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |  ESC | CAPS | ____ | UC_SW| ____ |  ENT | ____ | DE_SW| ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
    #ifdef NAGINATA_ENABLE
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, NAGINATA_SWITCH, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), 
    #else
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, KC_BSPC, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), 
    #endif
        CTL_TAB, KC_TAB, KC_ESC, KC_ENT, TD(TD_VIM_GG), KC_MPLY, VIM_O, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END,
        KC_LSFT, S(KC_DEL), C(G(KC_LEFT)), C(G(KC_RGHT)), VIM_V, KC_MUTE, KC_DE_SWITCH, KC_HOME, KC_PGDN, KC_LSFT, KC_RSFT, C(KC_F),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_CAPS, LT(_NAV, KC_SPC), UNICODE_ALT_SW, LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS
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
     * |!MOUSE| XXXX | XXXX | ____ | XXXX | MAUS_ACCEL2 | ____ | XXXX | XXXX |  <-  |  ->  |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_BTN4, KC_BTN5, KC_NO, KC_BRIU, KC_NO, KC_WH_U, KC_MS_U, KC_WH_U, DM_PLY2, DM_REC2,
        KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MPLY, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, DM_PLY1, DM_REC1,
        KC_TRNS, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_BRID, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS, DM_RSTP,
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    )
#endif
};

// =========================================================================================
// =========================================================================================

#ifdef NAGINATA_ENABLE
// 薙刀式
void matrix_init_user(void) {
  uint16_t ngonkeys[]  = {NG_DUMMY, NG_DUMMY};
  uint16_t ngoffkeys[] = {NG_DUMMY, NG_DUMMY};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
// set_naginata(_NAGINATA);
}
// 薙刀式
#endif

// define the tap dance functions
void dance_prn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
            tap_code16(DE_LPRN);
        } else {
            tap_code16(KC_LPRN);
        }
    } else {
        if (de_layout_active) {
            tap_code16(DE_LPRN);
            tap_code16(DE_RPRN);
            tap_code(KC_LEFT);
        } else {
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_LEFT);
        }
    }
}
void dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
            tap_code16(DE_LBRC);
        } else {
            tap_code(KC_LBRC);
        }
    } else {
        if (de_layout_active) {
            tap_code16(DE_LBRC);
            tap_code16(DE_RBRC);
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            tap_code(KC_LEFT);
        }
    }
}
void dance_cbr(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
            tap_code16(DE_LCBR);
        } else {
            tap_code16(KC_LCBR);
        }
    } else {
        if (de_layout_active) {
            tap_code16(DE_LCBR);
            tap_code16(DE_RCBR);
            tap_code(KC_LEFT);
        } else {
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            tap_code(KC_LEFT);
        }
    }
}
void vim_gg(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(C(KC_END));
    } else {
        tap_code16(C(KC_HOME));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_PRN] = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC] = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR] = ACTION_TAP_DANCE_FN(dance_cbr), 
    [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg),
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4))
};

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case RSFT_T(KC_DEL):
            return TAPPING_TERM * thumb_factor;
        case RCTL_T(KC_TAB):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_LEFT):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_RIGHT):
            return TAPPING_TERM * thumb_factor;
        case LT(_LOWER, KC_BSPC):
            return TAPPING_TERM * thumb_factor;
        case LT(_LOWER_DE, KC_BSPC):
            return TAPPING_TERM * thumb_factor;
        case LT(_RAISE, KC_ENT):
            return TAPPING_TERM * thumb_factor;
        case LT(_RAISE_DE, KC_ENT):
            return TAPPING_TERM * thumb_factor;
        case LT(_NAV, KC_SPC):
            return TAPPING_TERM * 1.1;
        case LALT_T(KC_ESC):
            return TAPPING_TERM * thumb_factor;

        // index finger keys
        case LCTL_T(KC_P):
            return TAPPING_TERM * index_factor;
        case RCTL_T(KC_L):
            return TAPPING_TERM * (index_factor + 0.1);
        case LT(_NUM, KC_B):
            return TAPPING_TERM * (index_factor + 0.1);
        case LT(_NUM, KC_J):
            return TAPPING_TERM * index_factor;
        case LT(_MOUSE, KC_VOLU):
            return TAPPING_TERM * td_factor;
        case LT(_MOUSE, KC_VOLD):
            return TAPPING_TERM * td_factor;

        // middle finger keys
        case LSFT_T(KC_F):
            return TAPPING_TERM * middle_factor;
        case RSFT_T(KC_U):
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case LALT_T(KC_W):
            return TAPPING_TERM * ring_factor;
        case LALT_T(KC_Y):
            return TAPPING_TERM * ring_factor;
        case LGUI_T(KC_TAB):
            return TAPPING_TERM * ring_factor;

        // pinky keys
        case LGUI_T(KC_Q):
            return TAPPING_TERM * pinky_factor;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM * pinky_factor;
        case RGUI_T(KC_LBRC):
            return TAPPING_TERM * pinky_factor;
        case LT(_MOUSE, KC_Z):
            return TAPPING_TERM * pinky_factor;
        case LT(_MOUSE, KC_SLSH):
            return TAPPING_TERM * pinky_factor;
        case LCTL_T(KC_CAPS):
            return TAPPING_TERM; // prefer this one to be shorter

        // tap-dance actions
        case TD(TD_PRN):
            return TAPPING_TERM * td_factor;
        case TD(TD_BRC):
            return TAPPING_TERM * td_factor;
        case TD(TD_CBR):
            return TAPPING_TERM * td_factor;
        case TD(TD_VIM_GG):
            return TAPPING_TERM * td_factor;
        case TD(TD_F4):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_S):
            return true;
        case RSFT_T(KC_E):
            return true;
        case LSFT_T(KC_D):
            return true;
        case RSFT_T(KC_K):
            return true;
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(KC_U):
            return true;
        case LT(_RAISE, KC_ENT):
            return true;
        case LT(_RAISE_DE, KC_ENT):
            return true;
        case LT(_LOWER, KC_BSPC):
            return true;
        case LT(_LOWER_DE, KC_BSPC):
            return true;
        default:
            return false;
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case BJ_NUM:
            if (pressed) {
                layer_invert(_NUM);
            }
            break;
    }
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_J) {
            SEND_STRING("Jakob");
        }
        SEQ_ONE_KEY(KC_W) {
            SEND_STRING("Weickmann");
        }
        SEQ_TWO_KEYS(KC_M, KC_E) {
            SEND_STRING("Jakob Weickmann");
        }
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
            } else {
                SEND_STRING("Yumeho");
            }
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            tap_code(KC_END);
            tap_code(KC_RIGHT);
            tap_code16(S(KC_UP));
            tap_code16(S(KC_DEL));
        }
        SEQ_TWO_KEYS(KC_H, KC_G) {
            if (de_layout_active) {
                SEND_STRING("Mit herylichen Gr[-en");
            } else {
                SEND_STRING("Mit herzlichen Gr");
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                unregister_mods(MOD_LALT);
                
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
                SEND_STRING("en");
            }
        }
        SEQ_TWO_KEYS(KC_V, KC_D) {
            SEND_STRING("haben Sie vielen Dank f"SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2))"r Ihre Nachricht.");
        }
        SEQ_TWO_KEYS(KC_F, KC_G) {
            if (de_layout_active) {
                SEND_STRING("Mit freundlichen Gr[-en");
            } else {
                SEND_STRING("Mit freundlichen Gr");
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                unregister_mods(MOD_BIT(KC_LALT));
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                unregister_mods(MOD_LALT);
                SEND_STRING("en");
            }
        }
        SEQ_FOUR_KEYS(KC_V, KC_I, KC_S, KC_A) {
            SEND_STRING("4570382900105176");
        }
        SEQ_FOUR_KEYS(KC_P, KC_O, KC_S, KC_T) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("posteo.de");
        }
        SEQ_THREE_KEYS(KC_U, KC_N, KC_I) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("univie.ac.at");
        }
        SEQ_FOUR_KEYS(KC_D, KC_J, KC_J, KC_G) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(DE_AT);
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("djjg.org");
        }
        SEQ_FOUR_KEYS(KC_A, KC_T, KC_N, KC_R) {
            if (de_layout_active) {
                tap_code16(KC_RBRC);
            } else {
                tap_code16(KC_PLUS);
            }
            SEND_STRING("4367761832729");
        }
        SEQ_FOUR_KEYS(KC_D, KC_E, KC_N, KC_R) {
            if (de_layout_active) {
                tap_code16(KC_RBRC);
            } else {
                tap_code16(KC_PLUS);
            }
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
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P8);  // €
                unregister_mods(MOD_BIT(KC_LALT));
            }
        }
        SEQ_THREE_KEYS(KC_Y, KC_E, KC_N) {
            add_mods(MOD_BIT(KC_LALT));
            tap_code(KC_P1);
            tap_code(KC_P5);
            tap_code(KC_P7);  // ¥
            unregister_mods(MOD_BIT(KC_LALT));
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

#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

// Set RGB to change with layer changes
#define HSV_DARKORANGE 10, 255, 255
#define HSV_DARKPINK 150, 100, 255
#define HSV_GRASS 57, 255, 255
#define HSV_OCEAN 148, 255, 255

// Light LEDs 1 to 10 in green when COLEMAK is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_OCEAN});
// Light LEDs 1 to 10 in green when de_layout_active is true
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_GRASS});
// Light LEDs 1 to 10 in red when GAMING layer is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_RED});
// Light LEDs 1 to 10 in darkorange when NAGINATA is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKORANGE});
// Light bottom LEDs in purple when ADJUST layer is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_MAGENTA}, {7, 3, HSV_MAGENTA});
// Light LEDs 1 to 10 in white when ... is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_WHITE});
// Light bottom LEDs in darkorange when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_DARKORANGE}, {7, 3, HSV_DARKORANGE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_layer0_layer,   // hrwidecolemak
                                                                               my_layer1_layer,   // de_layout
                                                                               my_layer2_layer,   // gaming
                                                                               my_layer3_layer,   // naginata
                                                                               my_layer4_layer,   // adjust
                                                                               my_layer5_layer,   // ...
                                                                               my_capslock_layer  // capslock
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

#ifdef AUDIO_ENABLE
    void led_set_user(uint8_t usb_led) {
        static uint8_t old_usb_led = 0;

        if (!is_playing_notes()) {
            if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK))) { 
                    // If CAPS LK LED is turning on...
                    PLAY_SONG(tone_caps_on);
            } else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK))) {
                    // If CAPS LK LED is turning off...
                    PLAY_SONG(tone_caps_off);
            }
        }
        old_usb_led = usb_led;
    }
#endif

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(6, led_state.caps_lock);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
#ifdef NAGINATA_ENABLE
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAGINATA));
    if (layer_state_cmp(state, _NAGINATA)) {
        naginata_active = true;
    } else {
        naginata_active = false;
    }
#endif
    //if ((layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE)) || (layer_state_cmp(state, _LOWER_DE) && layer_state_cmp(state, _RAISE_DE))) {
    //    return state | (1UL << _ADJUST);
    //} else {
    //    return state & ~(1UL << _ADJUST);
    //}
    // state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    //rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK_DE));
    if (layer_state_cmp(state, _COLEMAK_DE)) {
        de_layout_active = true;
    } else {
        de_layout_active = false;
    }
    return state;
}

#ifdef DYNAMIC_MACRO_ENABLE
    #ifdef AUDIO_ENABLE
        void dynamic_macro_record_start_user(void) {
            PLAY_SONG(macro_on_song);
        }
        void dynamic_macro_record_end_user(int8_t direction) {
            PLAY_SONG(macro_off_song);
        }
    #endif
#endif
