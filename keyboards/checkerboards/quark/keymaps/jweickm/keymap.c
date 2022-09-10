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
    _COLEMAK_DE,
#ifdef QWERTY_LAYER
    _QWERTY,
#endif
    _UMLAUTS,
#ifdef GAMING_LAYER
    _GAMING,
#endif
    _LOWER,
    _LOWER_DE,
    _RAISE,
    _RAISE_DE,
    _NUM,
    /* _NUM_DE, */
    _MOUSE,
    _ADJUST,
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
#define RAISE LT(_RAISE, KC_SPC)
#define LOWER_DE LT(_LOWER_DE, KC_BSPC)
#define RAISE_DE LT(_RAISE_DE, KC_SPC)

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY LT(_LOWER, KC_UP)

#define ESC_KEY     LT(0, KC_ESC)

#define BSLS_KEY    LT(0, KC_BSLS)

/* #define TAB_KEY     LCAG_T(KC_TAB) */
#define TAB_KEY     KC_TAB
#define QUOT_KEY    LT(0, KC_QUOT)

#define DOT_KEY     LT(0, KC_DOT)
#define COMM_KEY    LT(0, KC_COMM)
#define SLSH_KEY    LT(0, KC_SLSH)

#define NAVSPACE    LT(_ADJUST, KC_SPC)
/* #define FN_KEY      LT(_ADJUST, KC_RALT) */
/* #define FN_KEY      LT(_ADJUST, KC_ENT) */
/* #define ENT_KEY     RSFT_T(KC_ENT) */
#define ENT_KEY     LT(_ADJUST, KC_ENT)

#define BS_KEY      LT(_NUM, KC_BSPC)
/* #define BS_KEY_DE   LT(_NUM_DE, KC_BSPC) */
#define DEL_KEY     LT(_MOUSE, KC_DEL)

#define UNDO        C(KC_Z)
#define REDO        C(KC_Y)

#define COPY_ALL    C(KC_INS)

#define LLOCK_ADJUST LT(_ADJUST, KC_NO)

#define NUM_2 LT(0, KC_KP_2)
#define NUM_3 LT(0, KC_KP_3)

#define KB_LANG_SWITCH TG(_COLEMAK_DE)
#define LANG_SWITCH A(KC_LSFT)

enum planck_keycodes { 
    COLEMAK = SAFE_RANGE,
#ifdef GAMING_LAYER
    GAMING,
#endif
    VIM_O,
    ALT_TAB,
    DE_ACC_GRV,
    DE_ACC_ACUT,
    /* KB_LANG_SWITCH, */
    /* LANG_SWITCH, */
    UMLAUT_SWITCH,
    UMLAUT_RALT,
    LLOCK, // layer lock key
    SZ_KEY,
    KC_DEG,
    /* KC_HEMINGWAY, */
    /* LLOCK_ADJUST, */
};

// =============== HELPER VARIABLES
// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool is_alt_tab_active  = false;

bool caps_lock_on;
bool num_lock_on;
// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched     = false; 


// ============ TAP DANCE ================
// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_CBR,     // curly brackets
    /* TD_VIM_GG,  // single tap to scroll down, double tap to scroll up */
    /* TD_F4,      // double tap F4 to alt-F4 */
    /* TD_LARROW,  // double tap left-angling bracket to get left arrow */ 
    TD_RARROW,  // double tap right-angling bracket to get right arrow
    TD_ABK,     // angle brackets
};

// define the tap dance functions
void dance_prn(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LPRN);
    } else {
        tap_code16(KC_LPRN);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RPRN);
        } else {
            tap_code16(KC_RPRN);
        }
        tap_code(KC_LEFT);
    }
}
void dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LBRC);
    } else {
        tap_code(KC_LBRC);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RBRC);
        } else {
            tap_code(KC_RBRC);
        }
        tap_code(KC_LEFT);
    }
}
void dance_cbr(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LCBR);
    } else {
        tap_code16(KC_LCBR);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RCBR);
        } else {
            tap_code16(KC_RCBR);
        }
        tap_code(KC_LEFT);
    }
}
/* void vim_gg(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         tap_code16(C(KC_END)); */
/*     } else { */
/*         tap_code16(C(KC_HOME)); */
/*     } */
/* } */

void dance_abk(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LABK);
    } else {
        tap_code16(KC_LABK);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RABK);
        } else {
            tap_code16(KC_RABK);
        }
        tap_code(KC_LEFT);
    }
}

/* void dance_larrow(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (de_layout_active) { */
/*         tap_code16(DE_LABK); */
/*     } else { */
/*         tap_code16(S(KC_COMM)); */
/*     } */
/*     if (state->count == 1) { */
/*     } else { */
/*         if (de_layout_active) { */
/*             tap_code(DE_MINS); */
/*         } else { */
/*             tap_code16(KC_MINS); */
/*         } */
/*     } */
/* } */
void dance_rarrow(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code(DE_MINS);
        } else {
            tap_code16(KC_MINS);
        }
    } 
    if (de_layout_active) {
        tap_code16(DE_RABK);
    } else {
        tap_code16(S(KC_DOT));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_PRN]    = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC]    = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR]    = ACTION_TAP_DANCE_FN(dance_cbr), 
    /* [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg), */
    /* [TD_F4]     = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4)), */
    /* [TD_LARROW] = ACTION_TAP_DANCE_FN(dance_larrow), */
    [TD_RARROW] = ACTION_TAP_DANCE_FN(dance_rarrow),
    [TD_ABK]    = ACTION_TAP_DANCE_FN(dance_abk),
};

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
        LCTL_T(KC_CAPS), OSM(MOD_LGUI), OSM(MOD_LALT), BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY/*FN_KEY*/
        /* LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY */
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Y  |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  | ____ | ____ | ____ | ____ | ____ | ____ |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |LWR_DE|     ____    |RSE_DE| ____ | ____ | ____ | ____ | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, Y_KEY_DE, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, Z_KEY_DE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOWER_DE,     KC_TRNS,     RAISE_DE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

#ifdef QWERTY_LAYER
/* _QWERTY without homerow mods so that it can be used with AHK-Naginata 薙刀式
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [] |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '" |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |  ENT | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_BRC), 
        KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS/*FN_KEY*/
    ),
#endif 

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

/* ----------------------------------------------------------------------------------------*/
/* * _GAMING*/
/*      * ,-----------------------------------------------------------------------------------.*/
/*      * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |  F5  |  F8  |  F9  | BSPC |*/
/*      * |------+------+------+------+------+------+------+------+------+------+------+------|*/
/*      * | TAB  |   Q  |   W  |   E  |   R  |   G  |   M  |   N  |   T  |   I  |   O  |   '  |*/
/*      * |------+------+------+------+------+------+------+------+------+------+------+------|*/
/*      * | LSFT |   A  |   S  |   D  |   F  |   V  |   K  |   H  |   ,  |   .  |   /  | RSFT |*/
/*      * |------+------+------+------+------+------+------+------+------+------+------+------|*/
/*      * | LCTL |   Z  | LALT |   B  |   P  |    SPACE    |  ENT | RALT | DOWN |  UP  |ADJUST| 1x2uC*/
/*      * `-----------------------------------------------------------------------------------'*/
/*      */
#ifdef GAMING_LAYER
    [_GAMING] = LAYOUT_planck_mit(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_F5, KC_F8, KC_F9, KC_BSPC, 
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_G, KC_M, KC_N, KC_T, KC_I, KC_O, KC_QUOT, 
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
        KC_LCTL, KC_Z, KC_LALT, KC_B, KC_P, KC_SPC, KC_ENT, KC_RALT, DOWN_KEY, UP_KEY, MO(_ADJUST)
    ),
#endif

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   (  |   )  |   [  |   ]  |C-HOME|   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   %  |   ^  |   {  |   }  | C-END|   ~  |   '  |   <  |   >  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |  ENT | ____ | LEFT | RIGHT| ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_mit(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, KC_PIPE,
        KC_TRNS, TD(TD_PRN), KC_RPRN, TD(TD_BRC), KC_RBRC, C(KC_HOME), KC_DQUO, KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, KC_DQUO, 
        KC_TRNS, KC_PERC, KC_CIRC, TD(TD_CBR), KC_RCBR, C(KC_END), KC_TILD, QUOT_KEY, TD(TD_ABK), KC_RABK, KC_BSLS, DE_ACC_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   (  |   )  |   [  |   ]  |C-HOME|   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   %  |   ^  |   {  |   }  | C-END|   ~  |   '  |   <  |   >  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |  ENT | ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_GRV, DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN), DE_RPRN, DE_PIPE,
        KC_TRNS, TD(TD_PRN), DE_RPRN, TD(TD_BRC), DE_RBRC, C(KC_HOME), DE_DQUO, DE_UNDS, DE_PLUS, TD(TD_CBR), DE_RCBR, DE_DQUO, 
        KC_TRNS, DE_PERC, DE_CIRC, TD(TD_CBR), DE_RCBR, C(KC_END), DE_TILD, DE_QUOT, TD(TD_ABK), DE_RABK, DE_BSLS, DE_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
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
     * | ____ | ____ |ADJUST| ____ | BSPC |     ____    | ____ | MAIL | <<|  |  |>> | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4/*TD(TD_F4)*/, KC_F5, KC_LABK, KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, QUOT_KEY, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, TD(TD_RARROW), KC_TRNS, KC_TRNS, KC_TRNS, DE_ACC_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_TRNS
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
     * | ____ | ____ |ADJUST| ____ | BSPC |     ____    | ____ | MAIL | <<|  |  |>> | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        DE_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4/*TD(TD_F4)*/, KC_F5, DE_LABK, DE_MINS, DE_EQL, TD(TD_BRC), DE_RBRC, DE_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, DE_GRV, TD(TD_RARROW), KC_TRNS, KC_TRNS, KC_TRNS, DE_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK|   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   0  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LGUI | LALT | LSFT | LCTL | ____ |   +  |   4  |   5  |   6  |   *  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |   °  |   €  | ____ | ____ |   -  |   1  |   2  |   3  |   /  |   _  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | BSPC |     ____    |   0  |   .  |   ,  |   =  | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_mit(
        LLOCK, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_EQUAL,
        KC_TRNS, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRNS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_COMM,
        KC_TRNS, KC_TRNS, KC_DEG, DE_EURO, KC_TRNS, KC_TRNS, KC_KP_MINUS, KC_KP_1, NUM_2, NUM_3, KC_KP_SLASH, KC_UNDS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL, KC_TRNS
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
     * | ____ | ____ | ____ | BTN 3| BTN 2|    BTN 1    | LLOCK|  SPC | Bri- | Bri+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        LLOCK, C(KC_HOME), KC_BTN4, KC_MS_U, KC_BTN5, C(KC_END), KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21,
        KC_TRNS, C(G(KC_LEFT)), KC_MS_L, KC_MS_D, KC_MS_R, C(G(KC_RIGHT)), KC_F15, KC_RCTL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), KC_TRNS, 
        KC_TRNS, KC_LSFT, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_F14, KC_F13, KC_BTN4, KC_BTN5, KC_SCROLL_LOCK, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, LLOCK, KC_SPC, KC_BRID, KC_BRIU, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| PRINT| C(->)|  MEH | HYPR | C(<-)| KANA | REDO | UNDO | LANG |KBLANG|G(SPC)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |A(TAB)| LGUI | LALT | LSFT | LCTL |CPYALL| LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |NUMLCK|DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END |UML_SW| MUTE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH|REBOOT| ____ | ____ |     ____    | ____ | ____ | VOLD | VOLU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        LLOCK, KC_PSCR, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, G(KC_SPC), 
        ALT_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, COPY_ALL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        OSM(MOD_LSFT), KC_NUM_LOCK, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, UMLAUT_SWITCH, KC_MUTE,
        QK_CLEAR_EEPROM, QK_BOOT, QK_REBOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS
    ),
};

