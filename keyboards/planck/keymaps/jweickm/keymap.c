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
#define hand_position 1 // 1: semi-wide, 2: wide
#if hand_position == 1
    #define layout 2 // 1: with OSM, 2: with OSL
#elif hand_position == 2
    #define layout 1 // 1: 1x2uC, 2: 2x2u, 3: grid
#endif

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
#if hand_position == 2 // wide

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
#elif hand_position == 1 // semi-wide (one outer row on the right)

/* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |  G-Q |  A-W |  S-F |  C-P |_Num-B| Vol+ |_Num-J|  C-L |  S-U |  A-Y |  G-; |   ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   M  |   N  |   E  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  S-Z |   X  |   C  |   D  |   V  | Vol- |   K  |   H  |   ,  |   .  |_Mo-/ |S-RALT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|!MOUSE| ESCM | LOWER| LSFT |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ | LEAD | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), LT(_MOUSE, KC_VOLU), LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), XP(DE_ue, DE_UE),  
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        LSFT_T(KC_Z), CUT_X, COPY_C, KC_D, PASTE_V, LT(_MOUSE, KC_VOLD), KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), RSFT_T(KC_RALT), 
    #if layout == 1
        LCTL_T(KC_CAPS), TG(_MOUSE), M_ESCM, LOWER, OSM(MOD_LSFT), NAVSPACE, NAVSPACE, RAISE, KC_DEL, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP), KC_LEAD
    #elif layout == 2
        LCTL_T(KC_CAPS), TG(_MOUSE), M_ESCM, OSL(_LOWER), LSFT_T(KC_BSPC), NAVSPACE, NAVSPACE, OSL(_RAISE), KC_DEL, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP), KC_LEAD
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
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   >  |   "  |   \  |   |  |   \  |   è  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ____ | ____ |     ____    |ADJUST| ____ | ____ | ____ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, X(DE_OE),
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_SZ), KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, X(DE_AE), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_DOT), S(KC_QUOT), KC_NUBS, KC_PIPE, KC_BSLS, DE_EGRAVE, 
    #if layout == 1
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, TG(_NUM)
    #endif
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
     * |!MOUSE| ____ | ____ |ADJUST| ____ |     ____    | ____ | ____ |ADJUST| ____ | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, KC_6, KC_7, KC_8, KC_9, KC_0, XP(DE_oe, DE_OE), 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, X(DE_SZ), KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, XP(DE_ae, DE_AE), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_COMM), KC_QUOT, KC_COMM, KC_DOT, KC_PIPE, DE_EAIGU, 
    #if layout == 1
        TG(_MOUSE), KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, TG(_NUM)
    #elif layout == 2
        TG(_MOUSE), KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, TG(_NUM)
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
    #endif
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
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | !NUM | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_F2,  KC_UP,  KC_ENT, KC_TRNS, KC_NLCK, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_MINS, TG(_NUM),
        KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_TAB, KC_ASTR, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_DOT,
        MO(_MOUSE), KC_F10, KC_F11, KC_ENT, KC_VOLD, KC_MUTE, KC_EQL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_COMM,
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, TG(_NUM)
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, TG(_NUM)
    #endif
    ),

/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| !LANG|A(GRV)| C(<-)| MAIL | HOME |  ->  | PGUP | COPY | PASTE| BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)|  TAB |  ESC |  ENT |VIM_GG| MPLY |  <-  |   ↓  |   ↑  |  ->  |  END | VIM_O|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |S(DEL)|DESK<-|DESK->| VIM_V| MUTE | HOME | PGDN | LSFT | RFST | C(F) | DE_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |  ESC | ____ |    _____    |  ENT | ____ | ____ | ____ | UC_SW| 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, C(KC_RGHT), LANG_SWITCH, A(KC_GRV), C(KC_LEFT), KC_MAIL, KC_HOME, KC_RIGHT, KC_PGUP, C(KC_INS), S(KC_INS), KC_BSPC, 
        CTL_TAB, KC_TAB, KC_ESC, KC_ENT, TD(TD_VIM_GG), KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, VIM_O, 
        KC_LSFT, S(KC_DEL), C(G(KC_LEFT)), C(G(KC_RGHT)), VIM_V, KC_MUTE, KC_HOME, KC_PGDN, KC_LSFT, KC_RSFT, C(KC_F), KC_DE_SWITCH, 
    #if layout == 1
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, UNICODE_ALT_SW 
    #elif layout == 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, NAVSPACE, NAVSPACE, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, UNICODE_ALT_SW 
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
    #endif
    )
#endif // hand-position
};
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
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4)),
};

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

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LOWER, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};
#endif

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
            }
        }
        SEQ_TWO_KEYS(KC_I, KC_U) {
            SEND_STRING("Yumeho");
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
            tap_code16(KC_AT);
            SEND_STRING("posteo.de");
        }
        SEQ_THREE_KEYS(KC_U, KC_N, KC_I) {
            SEND_STRING("jakob.weickmann");
            tap_code16(KC_AT);
            SEND_STRING("univie.ac.at");
        }
        SEQ_THREE_KEYS(KC_G, KC_M, KC_X) {
            SEND_STRING("j.weickmann"); 
            tap_code16(KC_AT);
            SEND_STRING("gmx.net");
        }
        SEQ_FOUR_KEYS(KC_D, KC_J, KC_J, KC_G) {
            SEND_STRING("jakob.weickmann");
            tap_code16(KC_AT);
            SEND_STRING("djjg.org");
        }
        SEQ_FOUR_KEYS(KC_A, KC_T, KC_N, KC_R) {
            tap_code16(KC_PLUS);
            SEND_STRING("4367761832729");
        }
        SEQ_FOUR_KEYS(KC_D, KC_E, KC_N, KC_R) {
            tap_code16(KC_PLUS);
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
    rgblight_set_layer_state(1, de_layout_active);
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
    //if (layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE))  {
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

