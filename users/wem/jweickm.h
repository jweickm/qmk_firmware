#pragma once
#include QMK_KEYBOARD_H

#include "keymap_german.h"

#include "g/keymap_combo.h"

#include "features/getreuer/achordion.h"
#include "features/getreuer/layer_lock.h"

enum planck_layers {
    _COLEMAK=0,
    _EN_DUALF,
    _COLEMAK_DE,
    _DE_DUALF,
    _UMLAUTS,
    _NUM,
    _ADJUST,
    _RAISE,
    _RAISE_DE,
    _LOWER,
    _LOWER_DE,
    _MOUSE,
};

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
#define M_KEY LT(_MOUSE, KC_M)

#define A_KEY LGUI_T(KC_A)
#define R_KEY LALT_T(KC_R)
#define S_KEY LSFT_T(KC_S)
#define T_KEY LCTL_T(KC_T)
#define N_KEY RCTL_T(KC_N)
#define E_KEY RSFT_T(KC_E)
#define I_KEY LALT_T(KC_I)
#define O_KEY RGUI_T(KC_O)

#define D_KEY LT(_UMLAUTS, KC_D)
#define H_KEY LT(_UMLAUTS, KC_H)

#define Z_KEY LT(0, KC_Z)
#define X_KEY LT(0, KC_X)
#define C_KEY LT(0, KC_C)
#define V_KEY LT(0, KC_V)

#define K_KEY KC_K

// define the secondary function of the lower and raise keys here
#define LOWER       LT(_LOWER, KC_BSPC)
#define RAISE       LT(_RAISE, KC_SPC)
// GERMAN VERSIONS OF THE KEYS
#define LOWER_DE    LT(_LOWER_DE, KC_BSPC)
#define RAISE_DE    LT(_RAISE_DE, KC_SPC)

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY   LT(_LOWER, KC_UP)
#define LEFT_KEY KC_LEFT
#define RIGHT_KEY KC_RIGHT

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

// ======================================================
// GERMAN VERSIONS OF THE KEYS
#define Z_KEY_DE    LT(1, DE_Z)
#define Y_KEY_DE    LT(1, DE_Y)

// OS keys
#define REDO C(KC_Y)
#define UNDO C(KC_Z)

#define LLOCK_ADJUST LT(_ADJUST, KC_NO)
#define LLOCK_NUM LT(_NUM, KC_NO)
#define LLOCK_MOUSE LT(_MOUSE, KC_NO)

#define NUM_2 LT(0, KC_KP_2)
#define NUM_3 LT(0, KC_KP_3)

#define KB_LANG_SWITCH TG(_COLEMAK_DE)
#define LANG_SWITCH S(KC_LALT)

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
    /* DUALF_ON, */
    /* DUALF_OFF, */
    /* LLOCK_ADJUST, */
    AE_QUOT,
    OE_SCLN,
    UE_BSLS,
    AE_QUOT_CAPS,
    OE_SCLN_CAPS,
    UE_BSLS_CAPS,
};

// Tap Dance declarations
#ifdef TAP_DANCE_ENABLE
enum tap_dance_codes {
    TD_LPRN,     // round brackets (parentheses)
    TD_LBRC,     // square brackets
    TD_LCBR,     // curly brackets
    TD_LABK,     // angling brackets
};
#endif

// logical variable to differentiate between the German and the English input mode
bool de_layout_active = false;

// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched = false;

bool caps_lock_on;
bool num_lock_on;
