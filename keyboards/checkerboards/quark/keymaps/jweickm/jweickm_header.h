#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum planck_layers {
    _COLEMAK = 0,
    _UMLAUTS,
    _LOWER,
    _RAISE,
    _NUM,
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

#define G_KEY LT(_NUM, KC_G)
/* #define M_KEY LT(0, KC_M) */
#define M_KEY LT(_RAISE, KC_M)

#define A_KEY LGUI_T(KC_A)
#define R_KEY LALT_T(KC_R)
#define S_KEY LSFT_T(KC_S)
#define T_KEY LCTL_T(KC_T)
#define N_KEY RCTL_T(KC_N)
#define E_KEY LSFT_T(KC_E)
#define I_KEY LALT_T(KC_I)
#define O_KEY LGUI_T(KC_O)

/* #define D_KEY LT(_NUM, KC_D) */
/* #define H_KEY LT(_MOUSE, KC_H) */
#define D_KEY LT(_ADJUST, KC_D)
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

#define DOWN_KEY LT(_MOUSE, KC_DOWN)
#define UP_KEY LT(_MOUSE, KC_UP)
#define LEFT_KEY KC_LEFT
#define RIGHT_KEY KC_RIGHT

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
#define DEL_KEY     LT(_MOUSE, KC_DEL)

enum planck_keycodes { 
    COLEMAK = SAFE_RANGE,
    VIM_O,
    VIM_V,
    ALT_TAB,
    CTL_TAB,
    /* REDO, */ 
    /* UNDO, */ 
    DE_ACC_GRV,
    DE_ACC_ACUT,
    KC_DE_SWITCH,
    LANG_SWITCH,
    CODING_SW,
    DE_UE,  // Ü
    DE_OE,  // Ö
    DE_AE,  // Ä
    DE_SZ,   // ß
    NAVSFT,
    UMLAUT_RALT 
};

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

// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool is_alt_tab_active  = false;
bool is_ctl_tab_active  = false;

// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched     = false; 
bool caps_lock_on       = false;
