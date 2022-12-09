 /* Copyright 2022 Jakob Weickmann
 * CHECKERBOARDS/QUARK
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

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum planck_layers {
    _COLEMAK = 0,
    _EN_DUALF,
    _COLEMAK_DE,
    _DE_DUALF,
    _UMLAUTS,
    _NUM,
    /* _NAV, */
    _ADJUST,
    _RAISE,
    _RAISE_DE,
    _LOWER,
    _LOWER_DE,
    _MOUSE,
};

// Define key names here 
#define Q_KEY LT(0, KC_Q)
#define W_KEY LT(0, KC_W)
#define F_KEY LT(0, KC_F)
#define P_KEY LT(0, KC_P)
#define B_KEY LT(0, KC_B)
#define J_KEY LT(0, KC_J)
#define L_KEY LT(0, KC_L)
#define U_KEY LT(0, KC_U)
#define Y_KEY LT(0, KC_Y)
#define Y_KEY_DE LT(1, DE_Y)
#define SCLN_KEY LT(0, KC_SCLN)

/* #define G_KEY LT(_ADJUST, KC_G) */
/* #define M_KEY LT(_ADJUST, KC_M) */
#define G_KEY KC_G
#define M_KEY KC_M

#define A_KEY LGUI_T(KC_A)
#define R_KEY LALT_T(KC_R)
#define S_KEY LSFT_T(KC_S)
#define T_KEY LCTL_T(KC_T)
#define N_KEY RCTL_T(KC_N)
#define E_KEY RSFT_T(KC_E)
#define I_KEY LALT_T(KC_I)
#define O_KEY RGUI_T(KC_O)

#define D_KEY LT(_NUM, KC_D)
/* #define D_KEY_DE LT(_NUM_DE, KC_D) */
#define H_KEY LT(_MOUSE, KC_H)

#define Z_KEY LT(0, KC_Z)
#define Z_KEY_DE LT(1, DE_Z)
#define X_KEY LT(0, KC_X)
#define C_KEY LT(0, KC_C)
#define V_KEY LT(0, KC_V)

#define K_KEY KC_K

//=====================================

// define the secondary function of the lower and raise keys here
#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_MINS)
#define LOWER_DE LT(_LOWER_DE, KC_BSPC)
#define RAISE_DE LT(_RAISE_DE, DE_MINS)

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY LT(_LOWER, KC_UP)

#define ESC_KEY     LALT_T(KC_ESC)

#define BSLS_KEY    LALT_T(KC_BSLS)
#define UE_KEY      LALT_T(DE_UDIA)

#define TAB_KEY     LCTL_T(KC_TAB)
#define QUOT_KEY    RCTL_T(KC_QUOT)

#define DOT_KEY     LT(0, KC_DOT)
#define COMM_KEY    LT(0, KC_COMM)
#define SLSH_KEY    LT(0, KC_SLSH)

#define NAVSPACE    LT(_ADJUST, KC_SPC)
#define ENT_KEY     RGUI_T(KC_ENT)
#define CAPS_KEY    LGUI_T(KC_CAPS)

#define BS_KEY      LT(_NUM, KC_BSPC)
#define DEL_KEY     LT(_MOUSE, KC_DEL)

#define UNDO        C(KC_Z)
#define REDO        C(KC_Y)

#define LLOCK_ADJUST LT(_ADJUST, KC_NO)
#define LLOCK_NUM LT(_NUM, KC_NO)
#define LLOCK_MOUSE LT(_MOUSE, KC_NO)

#define NUM_2 LT(0, KC_KP_2)
#define NUM_3 LT(0, KC_KP_3)

#define KB_LANG_SWITCH TG(_COLEMAK_DE)
#define LANG_SWITCH A(KC_LSFT)

enum planck_keycodes { 
    COLEMAK = SAFE_RANGE,
    VIM_O,
    ALT_TAB,
    KC_ACC_GRV,
    KC_ACC_ACUT,
    /* KB_LANG_SWITCH, */
    /* LANG_SWITCH, */
    UMLAUT_SWITCH,
    /* UMLAUT_RALT, */
    LLOCK, // layer lock key
    SZ_KEY,
    KC_DEG,
    TOGGLE_DUALF,
    AE_QUOT, 
    OE_SCLN, 
    UE_BSLS,
    AE_QUOT_CAPS, 
    OE_SCLN_CAPS, 
    UE_BSLS_CAPS,
    /* LLOCK_ADJUST, */
};

// =============== HELPER VARIABLES
// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool caps_lock_on;
bool num_lock_on;
// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched     = false; 


// ============ TAP DANCE ================
// Tap Dance declarations
#ifdef TAP_DANCE_ENABLE
enum tap_dance_codes {
    TD_LPRN,     // round brackets (parentheses)
    TD_LBRC,     // square brackets
    TD_LCBR,     // curly brackets
    TD_LABK,     // angling brackets
};
#endif

// ==== PROCESS RECORD USER
#include "g/keymap_combo.h"
#include "jweickm_process_record_user.c"

// for leader functionality
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#endif
// ===============================================
void matrix_scan_user(void) {

#ifdef LEADER_ENABLE
#include "leader_dictionary.c"
#endif

#ifdef ACHORDION
    achordion_task();
#endif
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on  = led_state.num_lock;
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ----------------------------------------------------------------------------------------
* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;: |   \| |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '" |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |  ENT | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        ESC_KEY, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, 
        TAB_KEY, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, 
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, OSM(MOD_RSFT)/*ENT_KEY*/, 
        KC_LCTL, KC_LGUI, KC_LALT, BS_KEY, LOWER,   NAVSPACE   , RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY/*FN_KEY*/
        /* LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY */
    ),

/* ----------------------------------------------------------------------------------------
* _EN_DUALF
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;: |   \| |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   '" |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |  ENT | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_EN_DUALF] = LAYOUT_planck_mit(
        KC_TRNS, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_TRNS, 
        KC_TRNS, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_TRNS, 
        KC_TRNS, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, COMM_KEY, DOT_KEY, SLSH_KEY, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS/*FN_KEY*/
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |LWR_DE|   NAVSPACE  |RSE_DE| ____ | ____ | ____ | ____ | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        KC_TRNS, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY_DE, SCLN_KEY, UE_KEY, 
        KC_TRNS, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, 
        KC_TRNS, Z_KEY_DE, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOWER_DE,   NAVSPACE   ,RAISE_DE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _DE_DUALF
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |  Ö  |    Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | RSFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |  ENT | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_DE_DUALF] = LAYOUT_planck_mit(
        KC_TRNS, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, DE_Y, DE_ODIA, UE_KEY, 
        KC_TRNS, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_TRNS, 
        KC_TRNS, Z_KEY_DE, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, COMM_KEY, DOT_KEY, SLSH_KEY, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS/*FN_KEY*/
    ),

/* ----------------------------------------------------------------------------------------
* _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_UMLAUTS] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, DE_ODIA, DE_UDIA, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_ADIA, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK|   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   0  |   :  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LGUI | LALT | LSFT | LCTL | ____ |   +  |   4  |   5  |   6  |   *  |   %  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |   °  |   €  | ____ | ____ |   -  |   1  |   2  |   3  |   /  |   _  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | BSPC |     ____    |   0  |   .  |   ,  |   =  | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_mit(
        LLOCK, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_COLN,
        KC_TRNS, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRNS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_PERC,
        KC_TRNS, KC_TRNS, KC_DEG, DE_EURO, KC_TRNS, KC_TRNS, KC_KP_MINUS, KC_KP_1, NUM_2, NUM_3, KC_KP_SLASH, KC_UNDS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL, KC_TRNS
    ),

    /* ======================== PLAN FOR SPLITTING UP _ADJUST AND _NAV LAYERS ========================== */
/* ----------------------------------------------------------------------------------------
* _NAV
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| ____ | C(->)|  MEH | HYPR | C(<-)| ____ | REDO | UNDO | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |A(TAB)| LGUI | LALT | LSFT | LCTL |CPYALL| LEFT | DOWN |  UP  | RIGHT| VIM_O| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | LOWER|     ____    | RAISE| ____ | BRI- | BRI+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    /* [_NAV] = LAYOUT_planck_mit( */
    /*     LLOCK, KC_TRNS, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), KC_TRNS, REDO, UNDO, KC_TRNS, KC_TRNS, KC_TRNS, */ 
    /*     ALT_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, COPY_ALL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_TRNS, */ 
    /*     OSM(MOD_LSFT), KC_TRNS, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS, */
    /*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOWER, KC_TRNS, RAISE, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS */
    /* ), */

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| PRINT| C(->)|  MEH | HYPR | C(<-)| KANA | REDO | UNDO | LANG |KBLANG| DUALF|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  | LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |NUMLCK|UML_SW| CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH|REBOOT| ____ | LOWER|     ____    | RAISE| ____ | BRI- | BRI+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    /* [_ADJUST] = LAYOUT_planck_mit( */
    /*     LLOCK, KC_PSCR, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, TOGGLE_DUALF, */ 
    /*     ALT_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, COPY_ALL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, */ 
    /*     OSM(MOD_LSFT), KC_NUM_LOCK, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, UMLAUT_SWITCH, KC_CAPS, */
    /*     QK_CLEAR_EEPROM, QK_BOOT, QK_REBOOT, KC_TRNS, LOWER, KC_TRNS, RAISE, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS */
    /* ), */
/* ======================== PLAN FOR SPLITTING UP _ADJUST AND _NAV LAYERS ========================== */

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| PRINT| C(->)|  MEH | HYPR | C(<-)| KANA | REDO | UNDO | LANG |KBLANG| DUALF|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |A(TAB)| LGUI | LALT | LSFT | LCTL | RALT | LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |NUMLCK|DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END |UML_SW| CAPS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH|REBOOT| ____ | LOWER|     ____    | RAISE| ____ | BRI- | BRI+ | KANA | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        LLOCK, KC_PSCR, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, TOGGLE_DUALF, 
        ALT_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        OSM(MOD_LSFT), KC_NUM_LOCK, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, UMLAUT_SWITCH, KC_CAPS,
        QK_CLEAR_EEPROM, QK_BOOT, QK_REBOOT, KC_TRNS, LOWER, KC_TRNS, RAISE, KC_TRNS, KC_BRID, KC_BRIU, A(KC_GRV)
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   [  |   ]  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   /  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |  APP | BSPC | ____ |     SPC     | ____ | MAIL | BRID | BRIU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LABK, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, QUOT_KEY, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_RABK, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACC_ACUT, 
        KC_TRNS, KC_TRNS, KC_APP, KC_BSPC, KC_TRNS, KC_SPC, KC_TRNS, KC_MAIL, KC_BRID, KC_BRIU, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   [  |   ]  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   /  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |  APP | BSPC | ____ |     SPC     | ____ | MAIL | BRID | BRIU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        DE_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, DE_LABK, DE_MINS, DE_EQL, DE_LBRC, DE_RBRC, DE_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, DE_GRV, DE_RABK, KC_TRNS, KC_TRNS, KC_TRNS, DE_ACUT, 
        KC_TRNS, KC_TRNS, KC_APP, KC_BSPC, KC_TRNS, KC_SPC, KC_TRNS, KC_MAIL, KC_BRID, KC_BRIU, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   ~  |   '  |   <  |   >  |   ?  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     |  ENT | ____ | LEFT | RIGHT| ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_mit(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_DQUO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, QUOT_KEY, KC_LABK, KC_RABK, KC_QUES, KC_ACC_GRV, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   ~  |   '  |   <  |   >  |   ?  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     SPC     |  ENT | ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_GRV, DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, DE_LPRN, DE_RPRN, DE_PIPE,
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, DE_DQUO, DE_UNDS, DE_PLUS, DE_LCBR, DE_RCBR, DE_DQUO, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, DE_TILD, DE_QUOT, DE_LABK, DE_RABK, DE_QUES, DE_GRV, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK|C-HOME| BTN4 | M ↑  | BTN5 | C-END|  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |DESK<-| M <- | M ↓  | M -> |DESK->|  F15 | RCTL | RSFT | LALT | RGUI | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LSFT |WHL <-|WHL ↑ |WHL ↓ |WHL ->|  F14 |  F13 | BTN4 | BTN5 |SCRLCK| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | BTN 3| BTN 2|    BTN 1    | LLOCK|  SPC | VOL- | VOL+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        LLOCK, C(KC_HOME), KC_BTN4, KC_MS_U, KC_BTN5, C(KC_END), KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21,
        KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_F15, KC_RCTL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), KC_TRNS, 
        KC_TRNS, KC_LSFT, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_F14, KC_F13, KC_BTN4, KC_BTN5, KC_SCROLL_LOCK, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, LLOCK, KC_SPC, KC_VOLD, KC_VOLU, KC_TRNS
    ),
};

