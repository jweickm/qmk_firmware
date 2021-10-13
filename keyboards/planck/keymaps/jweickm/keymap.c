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
#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_german.h"


// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;
// 薙刀式

enum planck_layers {
    _HRWIDECOLEMAK,
    _HRWIDECOLEMAK_DE,
    _GAMING,
    _WIDECOLEMAK,
    // 薙刀式
    _NAGINATA, // 薙刀式入力レイヤー
    // 薙刀式
    _LOWER,
    _RAISE,
    _LOWER_DE,
    _RAISE_DE,
    _ADJUST,
    _NUM,
    _NAV,
    _MOUSE,
};

enum planck_keycodes { 
    // 薙刀式: SAFE_RANGE -> NG_SAFE_RANGE
    HRWIDECOLEMAK = NG_SAFE_RANGE,
    EISU,
    KANA2,
    // 薙刀式
    GAMING,
    WIDECOLEMAK,
    TG_COLEMAK,
    VIM_O,
    VIM_V,
    KC_SVD_BD,
    KC_SVU_BU,
    KC_TAB_MPLY,
    ALT_TAB,
    CTL_TAB,
    DE_ae,
    DE_oe,
    DE_ue,
    DE_AE,
    DE_OE,
    DE_UE,
    DE_SZ,
    DE_EGRAVE,
    DE_EAIGU,
    KC_CURRENCY,
    KC_DE_SWITCH,
    LANG_SWITCH,
    NAGINATA_SWITCH,
    DE_SLSH_QUST,
    DE_EN_QUOT,
    DE_EN_SCLN,
    DE_EN_BSLS,
    M_ESCM,
    M_RGUI_SCLN,
    DE_DOT_RAB,
    DE_COMM_LAB };

// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_PRN_DE,  // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_BRC_DE,  // square brackets
    TD_CBR,     // curly brackets
    TD_CBR_DE,  // curly brackets
    TD_VIM_GG,  // single tap to scroll down, double tap to scroll up
    TD_F4       // double tap F4 to alt-F4
};

#define LOWER OSL(_LOWER)
#define LOWER_DE OSL(_LOWER_DE)
#define RAISE OSL(_RAISE)
#define RAISE_DE OSL(_RAISE_DE)
#define ADJUST OSL(_ADJUST)

float macro_on_song[][2]        = SONG(SCROLL_LOCK_ON_SOUND);
float macro_off_song[][2]       = SONG(SCROLL_LOCK_OFF_SOUND);
float tone_caps_on[][2]         = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]        = SONG(CAPS_LOCK_OFF_SOUND);
float naginata_on_sound[][2]    = SONG(PLOVER_SOUND);
float naginata_off_sound[][2]   = SONG(PLOVER_GOODBYE_SOUND);
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _HRWIDECOLEMAK
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
    [_HRWIDECOLEMAK] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), KC_SVU_BU, LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Y), RGUI_T(KC_SCLN), DE_ue, 
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        LT(_MOUSE, KC_Z), KC_X, KC_C, KC_D, KC_V, KC_SVD_BD, KC_K, KC_H, KC_COMM, KC_DOT, LT(_MOUSE, KC_SLSH), KC_LEAD, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), LT(_RAISE, KC_ENT), RSFT_T(KC_DEL), KC_RALT, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
    ),

    /* _HRWIDECOLEMAK_DE
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
    [_HRWIDECOLEMAK_DE] = LAYOUT_planck_grid(
        LGUI_T(KC_Q), LALT_T(KC_W), LSFT_T(KC_F), LCTL_T(KC_P), LT(_NUM, KC_B), KC_SVU_BU, LT(_NUM, KC_J), RCTL_T(KC_L), RSFT_T(KC_U), LALT_T(KC_Z), M_RGUI_SCLN, DE_UDIA, 
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB, KC_M, KC_N, KC_E, KC_I, KC_O, DE_EN_QUOT, 
        LT(_MOUSE, KC_Y), KC_X, KC_C, KC_D, KC_V, KC_SVD_BD, KC_K, KC_H, DE_COMM_LAB, DE_DOT_RAB, DE_SLSH_QUST, KC_LEAD, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER_DE, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), LT(_RAISE_DE, KC_ENT), RSFT_T(KC_DEL), KC_RALT, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
    ),

    /* _GAMING
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
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_Z, KC_M, KC_SCLN, TG_COLEMAK, 
        KC_LCTL, KC_C, KC_B, KC_X, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, KC_VOLD, KC_VOLU, GAMING
    ),

    /* WIDECOLEMAK
     * no mod taps
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   W  |   F  |   P  |   B  |Vol/B+|   J  |   L  |   U  |   Y  |   /  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   R  |   S  |   T  |   G  | TAB  |   M  |   N  |   E  |   I  |   O  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   D  |   V  |Vol/B-|   K  |   H  |   ,  |   .  |   /  |!CM-EN|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS| LEAD | BSPC | LOWER| LSFT |  _Nav-SPC   | RAISE| S-DEL| RALT |_Mo ↓ |_Mo ↑ |
     * `-----------------------------------------------------------------------------------'
     */
    [_WIDECOLEMAK] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_F, KC_P, KC_B, KC_SVU_BU, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, DE_ue,
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_TAB_MPLY, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, 
        KC_Z, KC_X, KC_C, KC_D, KC_V, KC_SVD_BD, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, TG_COLEMAK, 
        LCTL_T(KC_CAPS), KC_LEAD, M_ESCM, LT(_LOWER, KC_BSPC), OSM(MOD_LSFT), LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), LT(_RAISE, KC_ENT), RSFT_T(KC_DEL), KC_RALT, LT(_MOUSE, KC_DOWN), LT(_MOUSE, KC_UP)
    ),

    /* 薙刀式
     * 
     * ,-----------------------------------------------------------------------------------.
     * |　小　|き　ぬ|て　り|し　む|　<-  | ____ |  ->  |　さ　|る　よ|す　え|へ　ゆ| EISU |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |ろ　せ|け　め|と　に|か゛ま|っ　ち| ____ |く　や|あ゛の|い　も|う　わ|ー　つ| KOTI |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ほ　|  ひ　|は　を|こ゜、|そ　み| ____ |た　お|な゜。|ん　ね|ら　ふ|  れ　| TATE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |NGSHFT|   NGSHFT    | ____ | ____ | ____ | ____ | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_grid(
        NG_Q, NG_W, NG_E, NG_R, NG_T, KC_TRNS, NG_Y, NG_U, NG_I, NG_O, NG_P, EISU,
        NG_A, NG_S, NG_D, NG_F, NG_G, KC_TRNS, NG_H, NG_J, NG_K, NG_L, NG_SCLN, NG_KOTI, 
        NG_Z, NG_X, NG_C, NG_V, NG_B, KC_TRNS, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, NG_TAYO, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NG_SHFT, NG_SHFT, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    /* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | MPLY |   /  |   \  |   |  |   \  |   è  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ____ | ____ |     ____    |  DEL | EISU |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_grid(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, DE_OE, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SZ, KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, DE_AE, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MPLY, KC_SLSH, KC_NUBS, KC_PIPE, KC_BSLS, DE_EGRAVE, 
        TG(_MOUSE), ADJUST, KC_TRNS, KC_TRNS, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_DEL, EISU, ADJUST, KC_DOWN, KC_UP
    ),
    
    /* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |   ~  |   ^  |   &  |   *  |   (  |   )  |   Ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   _  |   +  |   {  |   }  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | MPLY |   /  |   \  |   |  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| ____ | ____ | ____ |     ____    |  DEL | EISU |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER_DE] = LAYOUT_planck_grid(
        DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, RALT(KC_RBRC), DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN_DE), DE_RPRN, LSFT(DE_ODIA), 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SS, DE_UNDS, DE_PLUS, TD(TD_CBR_DE), DE_RCBR, LSFT(DE_ADIA), 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MPLY, DE_SLSH, DE_BSLS, DE_PIPE, DE_BSLS, DE_GRV, 
        TG(_MOUSE), ADJUST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, EISU, ADJUST, KC_DOWN, KC_UP
    ),

    /* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   `  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |   /  |   ,  |   .  |   \  |   é  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| KANA | BSPC | ____ |     ____    |  ENT | ____ |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, KC_6, KC_7, KC_8, KC_9, KC_0, DE_oe, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SZ, KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, DE_ae, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_COMM), KC_SLSH, KC_COMM, KC_DOT, KC_PIPE, DE_EAIGU, 
        TG(_MOUSE), ADJUST, KANA2, KC_BSPC, KC_TRNS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    ),

    /* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   °  |   6  |   7  |   8  |   9  |   0  |   ö  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   ß  |   -  |   =  |   [  |   ]  |   ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |   /  |   ,  |   .  |   \  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE|ADJUST| KANA | BSPC | ____ |     ____    |  ENT | ____ |ADJUST|   ↓  |   ↑  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_grid(
        KC_1, KC_2, KC_3, KC_4, KC_5, LSFT(KC_GRV), KC_6, KC_7, KC_8, KC_9, KC_0, DE_ODIA, 
        KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, KC_F6, DE_SS, DE_MINS, DE_EQL, TD(TD_BRC_DE), DE_RBRC, DE_ADIA, 
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DE_LABK, DE_SLSH, KC_COMM, KC_DOT, DE_BSLS, DE_ACUT, 
        TG(_MOUSE), ADJUST, KANA2, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, ADJUST, KC_DOWN, KC_UP
    ),

    /* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | A-SFT| RESET| DEBUG|RGBTOG|RGBMOD|RGBHUI|RGBHUD|RGBSAI|RGBSAD|RGBVAI|RGBVAD| !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | A-GRV|EEPRST|MU_MOD| AU_ON|AU_OFF|AGNORM|AGSWAP|!HRWCM| !WCM | A-GRV| !LANG| !GAME|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |MUV_DE|MUV_IN| MU_ON|MU_OFF| MI_ON|MI_OFF| Vol- | MPLY | Vol+ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ |EEPRST|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        LALT(KC_LSFT), RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, TG(_NUM), 
        LALT(KC_GRV), EEP_RST, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, HRWIDECOLEMAK, WIDECOLEMAK, LALT(KC_GRV), LANG_SWITCH, GAMING, 
        KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, KC_SVD_BD, KC_MPLY, KC_SVU_BU, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET
    ),

    /* _NUM
     * ,-----------------------------------------------------------------------------------.
     * |  Esc |  F2  |   ↑  |  Ent |  |<< |NUMLCK| >>|  |   7  |   8  |   9  |   -  | !NUM |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HOME |  <-  |   ↓  |  ->  | END  | TAB  |   *  |   4  |   5  |   6  |   +  |   .  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MOUSE|  F10 |  F11 |  Ent | Vol- | MUTE |   =  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    |   0  |   .  |   ,  |   =  | ____ |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
        KC_ESC, KC_F2,  KC_UP,  KC_ENT, KC_MPRV, KC_NLCK, KC_MNXT, KC_P7, KC_P8, KC_P9, KC_MINS, TG(_NUM), 
        KC_HOME, KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END, KC_TAB, KC_ASTR, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_DOT, 
        MO(_MOUSE), KC_F10, KC_F11, KC_ENT, KC_VOLD, KC_MUTE, KC_EQL, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_COMM, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_COMM, KC_EQL, KC_TRNS
    ),

    /* _NAV
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| C(->)| !LANG|A(GRV)| C(<-)| MAIL | HOME |  ->  | PGUP | COPY | PASTE|NAG-SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)|  TAB |  ESC |  ENT |VIM_GG| MPLY |  <-  |   ↓  |   ↑  |  ->  |  END | VIM_O|  
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |S(DEL)|DESK<-|DESK->| VIM_V| MUTE | HOME | PGDN | LSFT | RFST | C(F) | DE_SW|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX | XXXX | ____ |  ESC | CAPS |     ____    |  ENT | ____ | DE_SW| ____ | DE_SW|
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        ALT_TAB, LCTL(KC_RGHT), LANG_SWITCH, LALT(KC_GRV), LCTL(KC_LEFT), KC_MAIL, KC_HOME, KC_RIGHT, KC_PGUP, LCTL(KC_INS), LSFT(KC_INS), NAGINATA_SWITCH, 
        CTL_TAB, KC_TAB, KC_ESC, KC_ENT, TD(TD_VIM_GG), KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, VIM_O, 
        KC_LSFT, LSFT(KC_DEL), C(G(KC_LEFT)), C(G(KC_RGHT)), VIM_V, KC_MUTE, KC_HOME, KC_PGDN, KC_LSFT, KC_RSFT, LCTL(KC_F), KC_DE_SWITCH, 
        KANA2, EISU, KC_TRNS, KC_ESC, KC_CAPS, LT(_NAV, KC_SPC), LT(_NAV, KC_SPC), KC_ENT, KC_TRNS, KC_DE_SWITCH, KC_TRNS, KC_DE_SWITCH
    ),

    /* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | XXXX | XXXX | MBTN4| MBTN5| XXXX | Bri+ | XXXX | MWHL↑|MAUS↑ | MWHL↑| PLY2 | REC2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | XXXX | MBTN3| MBTN2| MBTN1| XXXX | MPLY | XXXX |MAUS<-|MAUS↓ |MAUS->| PLY1 | REC1 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | XXXX | XXXX | XXXX | XXXX | Bri- | XXXX | MWHL↓| XXXX | XXXX | ____ | STOP |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |!MOUSE| XXXX | XXXX | ____ | XXXX | MAUS_ACCEL2 | ____ | XXXX | XXXX |  <-  |  ->  |
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_BTN4, KC_BTN5, KC_NO, KC_BRIU, KC_NO, KC_WH_U, KC_MS_U, KC_WH_U, DM_PLY2, DM_REC2, 
        KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, KC_NO, KC_MPLY, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, DM_PLY1, DM_REC1, 
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS, DM_RSTP, 
        TG(_MOUSE), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_ACL2, KC_ACL2, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_RIGHT
    )

};

// 薙刀式
void matrix_init_user(void) {
  uint16_t ngonkeys[] = {KC_H, KC_J};
  uint16_t ngoffkeys[] = {KC_F, KC_G};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
}
// 薙刀式

// define the tap dance functions
void dance_prn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LPRN);
    } else {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code(KC_LEFT);
    }
}
void dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_LBRC);
    } else {
        tap_code(KC_LBRC);
        tap_code(KC_RBRC);
        tap_code(KC_LEFT);
    }
}
void dance_cbr(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LCBR);
    } else {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
        tap_code(KC_LEFT);
    }
}
void dance_prn_de(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_ASTR);
    } else {
        tap_code16(KC_ASTR);
        tap_code16(KC_LPRN);
        tap_code(KC_LEFT);
    }
}
void dance_brc_de(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(RALT(KC_8));
    } else {
        tap_code16(RALT(KC_8));
        tap_code16(RALT(KC_9));
        tap_code(KC_LEFT);
    }
}
void dance_cbr_de(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(RALT(KC_7));
    } else {
        tap_code16(RALT(KC_7));
        tap_code16(RALT(KC_0));
        tap_code(KC_LEFT);
    }
}
void vim_gg(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(LCTL(KC_END));
    } else {
        tap_code16(LCTL(KC_HOME));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_PRN] = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC] = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR] = ACTION_TAP_DANCE_FN(dance_cbr), 
    [TD_PRN_DE] = ACTION_TAP_DANCE_FN(dance_prn_de), 
    [TD_BRC_DE] = ACTION_TAP_DANCE_FN(dance_brc_de), 
    [TD_CBR_DE] = ACTION_TAP_DANCE_FN(dance_cbr_de), 
    [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg),
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4))
};

float thumb_factor  = 0.95;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
float td_factor     = 1.3;

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
            return TAPPING_TERM * pinky_factor;

        // tap-dance actions
        case TD(TD_PRN):
            return TAPPING_TERM * td_factor;
        case TD(TD_BRC):
            return TAPPING_TERM * td_factor;
        case TD(TD_CBR):
            return TAPPING_TERM * td_factor;
        case TD(TD_PRN_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_BRC_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_CBR_DE):
            return TAPPING_TERM * td_factor;
        case TD(TD_VIM_GG):
            return TAPPING_TERM * td_factor;
        case TD(TD_F4):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}

// alt tab function setup
bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;
bool de_layout_active  = false;
bool naginata_active   = false;
bool come_from_naginata = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t key_timer;
    switch (keycode) {
        case WIDECOLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIDECOLEMAK);
            }
            return false;
            break;
        case HRWIDECOLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_HRWIDECOLEMAK);
            }
            return false;
            break;
        case GAMING:
            if (record->event.pressed) {
                layer_invert(_GAMING);
            }
            return false;
            break;
        case TG_COLEMAK:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                layer_invert(_WIDECOLEMAK);
            }
            return false;
            break;
        case VIM_O:
            if (record->event.pressed) {
                tap_code(KC_END);
                tap_code(KC_ENT);
            }
            return false;
            break;
        case VIM_V:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                } else {
                    register_mods(MOD_LSFT);
                }
            }
            return false;
            break;
        case KC_SVU_BU:  // increase backlight when pressing shift and vol up
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(KC_BRIU);
                } else if (get_mods() & MOD_MASK_CTRL) {
                    register_code(KC_MNXT);
                } else {
                    register_code(KC_VOLU);
                }
            } else {
                unregister_code(KC_BRIU);
                unregister_code(KC_MNXT);
                unregister_code(KC_VOLU);
            }
            return false;
        case KC_SVD_BD:  // decrease backlight when pressing shift and vol up
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(KC_BRID);
                } else if (get_mods() & MOD_MASK_CTRL) {
                    register_code(KC_MPRV);
                } else {
                    register_code(KC_VOLD);
                }
            } else {
                unregister_code(KC_BRID);
                unregister_code(KC_MPRV);
                unregister_code(KC_VOLD);
            }
            return false;
        case KC_TAB_MPLY:  // press tab or play/pause when ctrl is pressed
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    register_code(KC_MPLY);
                } else {
                    register_code(KC_TAB);
                }
            } else {
                unregister_code(KC_MPLY);
                unregister_code(KC_TAB);
            }
            return false;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    add_mods(MOD_BIT(KC_LALT));
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CTL_TAB:
            if (record->event.pressed) {
                if (!is_ctl_tab_active) {
                    is_ctl_tab_active = true;
                    add_mods(MOD_BIT(KC_LCTL));
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        // the next case allows us to use alt_tab without a timer
        case LT(_NAV, KC_SPC):
            if (record->event.pressed) {
            } else {
                unregister_mods(MOD_LALT);
                unregister_mods(MOD_LCTL);
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
            }
            break;
        case DE_ae:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P9);
                    tap_code(KC_P6);  // Ä
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P8);  // ä
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_AE:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                clear_oneshot_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P9);
                tap_code(KC_P6);  // Ä
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_oe:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P1);
                    tap_code(KC_P4);  // Ö
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P4);
                    tap_code(KC_P6);  // ö
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_OE:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                clear_oneshot_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P1);
                tap_code(KC_P4);  // Ö
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_ue:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P0);  // Ü
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P5);
                    tap_code(KC_P2);  // ü
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_UE:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                clear_oneshot_mods();
                clear_mods();
                add_mods(MOD_BIT(KC_LALT));
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P0);  // Ü
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case KC_DE_SWITCH:
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    set_single_persistent_default_layer(_HRWIDECOLEMAK);
                } else {
                    if (naginata_active) {
                        naginata_off();
                    }
                    de_layout_active = true;  // activate German overlay
                    set_single_persistent_default_layer(_HRWIDECOLEMAK_DE);
                }
                return false;
            }
            break;
        case NAGINATA_SWITCH:
            if (record->event.pressed) {
                if (naginata_active) {
                    tap_code(KC_MHEN);
                    naginata_off();
                } else {
                    naginata_on();
                    tap_code(KC_HENK);
                }
            }
            return false;
        case LANG_SWITCH:
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    set_single_persistent_default_layer(_HRWIDECOLEMAK);
                } else {
                    come_from_naginata = naginata_active;
                    if (naginata_active) {
                        naginata_off();
                    } else {
                    }
                    de_layout_active = true;  // activate German overlay
                    set_single_persistent_default_layer(_HRWIDECOLEMAK_DE);
                }
            } else {
                tap_code16(LALT(KC_LSFT));
                if (come_from_naginata && !de_layout_active) {
                    naginata_on();
                }
            }
            return false;
        case DE_SZ:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P7);
                    tap_code(KC_P6);  // °
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_EGRAVE:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P0);
                    tap_code(KC_P0);  // È
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    tap_code(KC_P2);  // è
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_EAIGU:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P0);
                    tap_code(KC_P1);  // É
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    tap_code(KC_P3);  // é
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case KC_CURRENCY:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P1);
                    tap_code(KC_P5);
                    tap_code(KC_P7);  // ¥
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    tap_code(KC_P8);  // €
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_SLSH_QUST:
            if (record->event.pressed) {
                key_timer = timer_read();
                layer_on(_MOUSE);
            } else {
                if (timer_elapsed(key_timer) < (TAPPING_TERM * pinky_factor)) {
                    layer_off(_MOUSE);
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    if (temp_mods & MOD_MASK_SHIFT) {
                        tap_code(KC_MINS);  // ?
                    } else {
                        tap_code16(KC_AMPR);  // /
                    }
                } else {
                    layer_off(_MOUSE);
                }
            }
            return false;
            break;
        case DE_EN_QUOT:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    register_code(KC_2);  // \"
                } else {
                    register_code16(KC_PIPE);  // /'
                }
            } else {
                unregister_code(KC_2);
                unregister_code16(KC_PIPE);
            }
            return true;
        case DE_DOT_RAB:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    register_code16(LSFT(KC_NUBS));  // > right angle bracket 
                } else {
                    register_code(KC_DOT);  // .
                }
            } else {
                unregister_code16(LSFT(KC_NUBS));
                unregister_code(KC_DOT);
            }
            return true;
        case DE_COMM_LAB:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    clear_mods();
                    clear_oneshot_mods();
                    register_code16(KC_NUBS);  // < left angle bracket
                    set_mods(temp_mods);
                } else {
                    register_code(KC_COMM);  // ,
                }
            } else {
                unregister_code16(KC_NUBS);
                unregister_code(KC_COMM);
            }
            return true;
        case DE_EN_SCLN:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    tap_code(KC_DOT);  // ;
                } else {
                    add_mods(MOD_BIT(KC_LSFT));
                    tap_code(KC_COMM);  // :
                    del_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
            break;
        case DE_EN_BSLS:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods() | get_oneshot_mods();
                clear_mods();
                clear_oneshot_mods();
                add_mods(MOD_BIT(KC_RALT));
                if (temp_mods & MOD_MASK_SHIFT) {
                    register_code(KC_NUBS);  // | Pipe
                } else {
                    register_code(KC_MINS);  // Backslash
                }
                set_mods(temp_mods);
            } else {
                unregister_code(KC_NUBS);
                unregister_code(KC_MINS);
            }
            return true;
        // switch multiplexing for escape, short tap for escape, long press for context menu
        case M_ESCM:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) > TAPPING_TERM) {
                    tap_code(KC_APP);
                } else {
                    tap_code(KC_ESC);
                }
            }
            return false;
        case M_RGUI_SCLN:
            if (record->event.pressed) {
                key_timer = timer_read();
                add_mods(MOD_BIT(KC_RGUI));
            } else {
                del_mods(MOD_BIT(KC_RGUI));
                if (timer_elapsed(key_timer) < (TAPPING_TERM * pinky_factor)) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    if (temp_mods & MOD_MASK_SHIFT) {
                        tap_code(KC_DOT);  // ;
                    } else {
                        add_mods(MOD_BIT(KC_LSFT));
                        tap_code(KC_COMM);  // :
                        del_mods(MOD_BIT(KC_LSFT));
                    }
                } else {
                    tap_code(KC_RGUI);
                }
            }
            return false;
            break;
        // 薙刀式
        case EISU:
            if (record->event.pressed) {
                if (!de_layout_active) {
                    if (naginata_active) {
                        PLAY_SONG(naginata_off_sound);
                    }
                    naginata_off();
                }
            }
            return false;
            break;
        case KANA2:
            if (record->event.pressed) {
                if (!de_layout_active) {
                    if (!naginata_active) {
                        PLAY_SONG(naginata_on_sound);
                    }
                    naginata_on();
                }
            }
    }
    // 薙刀式
    if (!process_naginata(keycode, record))
        return false;
    // 薙刀式

    return true;
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
        SEQ_TWO_KEYS(KC_D, KC_D) {
            tap_code(KC_END);
            tap_code(KC_RIGHT);
            tap_code16(LSFT(KC_UP));
            tap_code16(LSFT(KC_DEL));
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
                tap_code16(RALT(KC_Q));
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("posteo.de");
        }
        SEQ_THREE_KEYS(KC_U, KC_N, KC_I) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(RALT(KC_Q));
            } else {
                tap_code16(KC_AT);
            }
            SEND_STRING("univie.ac.at");
        }
        SEQ_FOUR_KEYS(KC_D, KC_J, KC_J, KC_G) {
            SEND_STRING("jakob.weickmann");
            if (de_layout_active) {
                tap_code16(RALT(KC_Q));
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
                tap_code16(RALT(KC_E));
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

// Set RGB to change with layer changes
#define HSV_DARKORANGE 10, 255, 255
#define HSV_DARKPINK 150, 100, 255
#define HSV_GRASS 57, 255, 255
#define HSV_OCEAN 148, 255, 255

// Light LEDs 1 to 10 in darkorange when HRCOLEMAK is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKORANGE});
// Light LEDs 1 to 10 in green when HRWIDECOLEMAK is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_OCEAN});
// Light LEDs 1 to 10 in green when de_layout_active is true
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_GRASS});
// Light LEDs 1 to 10 in red when GAMING layer is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_RED});
// Light LEDs 1 to 10 in darkorange when WIDECOLEMAK is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKORANGE});
// Light bottom LEDs in purple when ADJUST layer is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_MAGENTA}, {7, 3, HSV_MAGENTA});
// Light bottom LEDs in darkorange when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 3, HSV_DARKORANGE}, {7, 3, HSV_DARKORANGE});
// Light LEDs 1 to 10 in white when NAVIGATION is active
const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_WHITE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_layer0_layer,   // hrcolemak
                                                                               my_layer1_layer,   // hrwidecolemak
                                                                               my_layer2_layer,   // de_layout
                                                                               my_layer3_layer,   // gaming
                                                                               my_layer4_layer,   // widecolemak
                                                                               my_layer5_layer,   // adjust
                                                                               my_nav_layer,      // nav
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
    rgblight_set_layer_state(7, led_state.caps_lock);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(4, layer_state_cmp(state, _WIDECOLEMAK));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NAGINATA));
    if (layer_state_cmp(state, _NAGINATA)) {
        naginata_active = true;
    } else {
        naginata_active = false;
    }
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
    rgblight_set_layer_state(4, layer_state_cmp(state, _WIDECOLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _HRWIDECOLEMAK));
    rgblight_set_layer_state(2, layer_state_cmp(state, _HRWIDECOLEMAK_DE));
    if (layer_state_cmp(state, _HRWIDECOLEMAK_DE)) {
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
