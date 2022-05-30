/* Copyright 2020 Nathan Spears
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
    _UMLAUTS,
    _LOWER,
    _LOWER_DE,
    _RAISE,
    _RAISE_DE,
    _NUM,
    _NUM_DE,
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
#define SCLN_KEY LT(0, KC_SCLN)

#define G_KEY KC_G
/* #define G_KEY_DE LT(_LOWER_DE, KC_G) */
/* #define M_KEY LT(0, KC_M) */
#define M_KEY KC_M

#define A_KEY LGUI_T(KC_A)
#define R_KEY LALT_T(KC_R)
#define S_KEY LSFT_T(KC_S)
#define T_KEY LCTL_T(KC_T)
#define N_KEY RCTL_T(KC_N)
#define E_KEY LSFT_T(KC_E)
#define I_KEY LALT_T(KC_I)
#define O_KEY LGUI_T(KC_O)

#define D_KEY LT(_NUM, KC_D)
#define H_KEY LT(_MOUSE, KC_H)

#define Z_KEY LT(0, KC_Z)
#define X_KEY LT(0, KC_X)
#define C_KEY LT(0, KC_C)
#define V_KEY LT(0, KC_V)

#define K_KEY KC_K

//=====================================

// define the secondary function of the lower and raise keys here
#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define LOWER_DE LT(_LOWER_DE, KC_SPC)
#define RAISE_DE LT(_RAISE_DE, KC_SPC)

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY LT(_LOWER, KC_UP)

#define ESC_KEY     LT(0, KC_ESC)
#define BSLS_KEY    LT(0, KC_BSLS)
#define DOT_KEY     LT(0, KC_DOT)
#define COMM_KEY    LT(0, KC_COMM)
#define QUOT_KEY    LT(0, KC_QUOT)
#define SLSH_KEY    LT(0, KC_SLSH)
#define NAVSPACE    LT(_ADJUST, KC_SPC)
#define FN_KEY      LT(_ADJUST, KC_RALT)
#define ENT_KEY     RSFT_T(KC_ENT)

#define BS_KEY      LT(_NUM, KC_BSPC)
#define BS_KEY_DE      LT(_NUM_DE, KC_BSPC)
#define DEL_KEY     LT(_MOUSE, KC_DEL)

enum planck_keycodes { 
    COLEMAK = SAFE_RANGE,
    VIM_O,
    ALT_TAB,
    CTL_TAB,
    /* REDO, */ 
    /* UNDO, */ 
    DE_ACC_GRV,
    DE_ACC_ACUT,
    KC_DE_SWITCH,
    LANG_SWITCH,
    DE_UE,  // Ü
    DE_OE,  // Ö
    DE_AE,  // Ä
    DE_SZ,   // ß
    NAVSFT,
    UMLAUT_RALT,
    LLOCK // layer lock key
};

// =============== HELPER VARIABLES
// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool is_alt_tab_active  = false;
bool is_ctl_tab_active  = false;

bool caps_lock_on       = false;

// ============ TAP DANCE ================
// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_CBR,     // curly brackets
    TD_VIM_GG,  // single tap to scroll down, double tap to scroll up
    TD_F4,      // double tap F4 to alt-F4
    TD_LARROW,  // double tap left-angling bracket to get left arrow 
    TD_RARROW,  // double tap right-angling bracket to get right arrow
};

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

void dance_labrk(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LABK);
    } else {
        tap_code16(S(KC_COMM));
    }
    if (state->count == 1) {
    } else {
        if (de_layout_active) {
            tap_code(DE_MINS);
        } else {
            tap_code16(KC_MINS);
        }
    }
}
void dance_rabrk(qk_tap_dance_state_t *state, void *user_data) {
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
    [TD_PRN] = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC] = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR] = ACTION_TAP_DANCE_FN(dance_cbr), 
    [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg),
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4)),
    [TD_LARROW] = ACTION_TAP_DANCE_FN(dance_labrk),
    [TD_RARROW] = ACTION_TAP_DANCE_FN(dance_rabrk),
};

// =============================================================

// define custom function for tapping umlaut keys
void SEND_UMLAUT(char umlaut) {
    clear_mods();
    clear_oneshot_mods();
    add_mods(MOD_BIT(KC_LALT));
    switch (umlaut) {
        case 'a':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P2);
            tap_code(KC_P8);  // ä
            break;
        case 'A':
            tap_code(KC_P0);
            tap_code(KC_P1);
            tap_code(KC_P9);
            tap_code(KC_P6);  // Ä
            break;
        case 'u':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P5);
            tap_code(KC_P2);  // ü
            break;
        case 'U':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P2);
            tap_code(KC_P0);  // Ü
            break;
        case 'o':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P4);
            tap_code(KC_P6);  // ö
            break;
        case 'O':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P1);
            tap_code(KC_P4);  // Ö
            break;
        case 's':
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P2);
            tap_code(KC_P3);  // ß
            break;
        case 'e':
            tap_code(KC_P0);
            tap_code(KC_P1);
            tap_code(KC_P2);
            tap_code(KC_P8);  // €
            break;
        case 'y':
            tap_code(KC_P1);
            tap_code(KC_P5);
            tap_code(KC_P7);  // ¥
            break;
        default:
            break; 
    }
    unregister_mods(MOD_LALT);
}

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

// might be able to move this into the function that calls the custom umlauts so it's less invasive
void led_set_user(uint8_t usb_led) {
    // keep numlock turned on, i.e. turn it off everytime it is turned on
    if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
        tap_code(KC_NUMLOCK);
    }
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        caps_lock_on = true;
    } else {
        caps_lock_on = false;
    }
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
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT| BSPC |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |A_RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        ESC_KEY, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, 
        KC_TAB, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, 
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, ENT_KEY, 
        LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, FN_KEY
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Y  |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |   G  | ____ | ____ | ____ | ____ | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  | ____ | ____ | ____ | ____ | ____ | ____ |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ |  BS  |LWR_DE|     ____    |RSE_DE| ____ | ____ | ____ | ____ | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, BS_KEY_DE, LOWER_DE,     KC_TRNS,     RAISE_DE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ü  | ____ |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Ä  | ____ |  SFT | ____ | ____ | ____ | ____ |  SFT | ____ |   Ö  |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_UMLAUTS] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_UE, KC_TRNS, DE_OE, DE_UE,
        KC_TRNS, DE_AE, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSM(MOD_LSFT), KC_TRNS, DE_OE, DE_AE, 
        KC_TRNS, DE_SZ, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)| VIM_O| LEFT |  UP  | DOWN | RIGHT|   `  |   _  |   +  |   [  |   ]  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |NAVSFT| XXXX | HOME | PGUP | PGDN |  END |   ~  |   '  |   <  |   >  |   -  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |ADJUST| ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_mit(
        ALT_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, KC_PIPE,
        CTL_TAB, VIM_O, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_GRV, KC_UNDS, KC_PLUS, TD(TD_BRC), KC_RBRC, S(KC_QUOT), 
        NAVSFT, KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_TILD, KC_QUOT, TD(TD_LARROW), TD(TD_RARROW), KC_MINS, DE_ACC_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)| VIM_O| LEFT |  UP  | DOWN | RIGHT|   `  |   _  |   +  |   [  |   ]  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |NAVSFT| XXXX | HOME | PGUP | PGDN |  END |   ~  |   '  |   <  |   >  |   -  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |ADJUST| ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER_DE] = LAYOUT_planck_mit(
        ALT_TAB, DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN), DE_RPRN, DE_PIPE,
        CTL_TAB, VIM_O, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, DE_GRV, DE_UNDS, DE_PLUS, TD(TD_BRC), DE_RBRC, DE_DQUO, 
        NAVSFT, KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, DE_TILD, DE_QUOT, TD(TD_LARROW), TD(TD_RARROW), DE_MINS, DE_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   {  |   }  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   _  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ |ADJUST|     ____    | ____ | MAIL | <<|  |  |>> | MUTE | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, TD(TD_LARROW), KC_MINS, KC_EQL, TD(TD_CBR), KC_RCBR, KC_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, TD(TD_RARROW), COMM_KEY, DOT_KEY, KC_UNDS, DE_ACC_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   {  |   }  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   _  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ |ADJUST|     ____    | ____ | MAIL | <<|  |  |>> | MUTE | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        DE_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, TD(TD_F4), KC_F5, TD(TD_LARROW), DE_MINS, DE_EQL, TD(TD_CBR), DE_RCBR, DE_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, DE_GRV, TD(TD_RARROW), COMM_KEY, DOT_KEY, DE_UNDS, DE_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_MUTE
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | ____ |   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   0  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   *  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | LLOCK|     ____    |   0  |   .  |   ,  |   =  | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_mit(
        KC_TRNS, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_MINS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_1, KC_2, KC_3, SLSH_KEY, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LLOCK, KC_TRNS, KC_0, DOT_KEY, COMM_KEY, KC_EQL, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _NUM_DE
     * ,-----------------------------------------------------------------------------------.
     * | ____ |   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   0  | BSPC |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   *  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ |   _  |   1  |   2  |   3  |   /  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | LLOCK|     ____    |   0  |   .  |   ,  |   =  | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM_DE] = LAYOUT_planck_mit(
        KC_TRNS, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_ASTR, KC_4, KC_5, KC_6, DE_PLUS, DE_MINS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_UNDS, KC_1, KC_2, KC_3, SLSH_KEY, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LLOCK, KC_TRNS, KC_0, DOT_KEY, COMM_KEY, DE_EQL, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | ____ | !MSE |WHL <-| M ↑  |WHL ->| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | BTN 4| M <- | M ↓  | M -> |BTN 5 | XXXX | RCTL | RSFT | LALT | RGUI | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ACCEL| XXXX |WHL ↑ |WHL ↓ | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | XXXX | BTN 3| BTN 2|    BTN 1    | LLOCK| ____ | Bri- | Bri+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        KC_TRNS, TG(_MOUSE), KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_NO, KC_LCTL, KC_RSFT, KC_LALT, KC_RGUI, KC_TRNS, 
        KC_TRNS, KC_ACL0, KC_NO, KC_WH_U, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_BTN3, KC_BTN2, KC_BTN1, LLOCK, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |A(TAB)| XXXX | C(->)|  TAB | ____ | C(<-)| XXXX | KANA | !LANG| DE_SW|JP<>DE| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C(TAB)| LGUI | LALT | LSFT | LCTL |VIM_GG| LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |NAVSFT| XXXX |DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END | XXXX | MPLY |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH|REBOOT| ____ | LLOCK|     ____    | LLOCK| MUTE | VOLD | VOLU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        ALT_TAB, KC_NO, C(KC_RIGHT), KC_TAB, LLOCK, C(KC_LEFT), KC_NO, A(KC_GRV), LANG_SWITCH, KC_DE_SWITCH, A(KC_LSFT), KC_TRNS, 
        CTL_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, TD(TD_VIM_GG), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        NAVSFT, KC_NO, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_MPLY,
        QK_CLEAR_EEPROM, QK_BOOT, QK_REBOOT, KC_TRNS, LLOCK, KC_TRNS, LLOCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS
    ),
};

