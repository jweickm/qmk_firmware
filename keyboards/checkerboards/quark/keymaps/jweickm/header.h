/* Copyright 2022 Jakob Weickmann
 * CHECKERBOARDS/QUARK
 */
#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum planck_layers {
    _COLEMAK = 0,
    _COLEMAK_DE,
    _GAMING,
    _UMLAUTS,
    _NUM,
    _RAISE,
    _RAISE_DE,
    _LOWER,
    _LOWER_DE,
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

#define G_KEY LT(_NUM, KC_G)
#define M_KEY LT(_MOUSE, KC_M)

#define A_KEY LGUI_T(KC_A)
#define R_KEY LALT_T(KC_R)
#define S_KEY LSFT_T(KC_S)
#define T_KEY LCTL_T(KC_T)
#define N_KEY LCTL_T(KC_N)
#define E_KEY RSFT_T(KC_E)
#define I_KEY LALT_T(KC_I)
#define O_KEY RGUI_T(KC_O)

#define D_KEY LT(_UMLAUTS, KC_D)
#define H_KEY LT(_UMLAUTS, KC_H)

#define X_KEY LT(0, KC_X)
#define C_KEY LT(0, KC_C)
#define V_KEY LT(0, KC_V)

#define K_KEY KC_K

#define KC_COMPOSE KC_RCTL
#define KC_MMIC KC_F20 // mute mic

// ==== LAYOUT-DEPENDENT KEY MAPPINGS
#ifdef WIDE_LAYOUT
#define QUOT_KEY    LT(0, KC_QUOT)
#define ESC_KEY     LSFT_T(KC_ESC)
#define ENT_KEY     LT(_UMLAUTS, KC_ENT)
#define GUI_KEY     KC_LGUI
#define FN_KEY      LT(_ADJUST, KC_APP)
#define TAB_KEY     LT(_ADJUST, KC_TAB)
#define SCLN_KEY    LT(0, KC_SCLN)
#define EQL_KEY     LT(0, KC_EQL)

#define LTHUMB      OSM(MOD_LSFT)
#define RTHUMB      LT(_UMLAUTS, KC_ESC)
// #define RTHUMB      OSL(_UMLAUTS)

// define the secondary function of the lower and raise keys here
#define LOWER       LT(_LOWER, KC_BSPC)
#define RAISE       LT(_RAISE, KC_SPC)
// GERMAN VERSIONS OF THE KEYS
#define LOWER_DE    LT(_LOWER_DE, KC_BSPC)
#define RAISE_DE    LT(_RAISE_DE, KC_SPC)

#define Z_KEY       LSFT_T(KC_Z)
#define Z_KEY_DE    LSFT_T(DE_Z)
// #define Z_KEY       LT(0, KC_Z)
// #define Z_KEY_DE    LT(1, DE_Z)

#define SLSH_KEY    RSFT_T(KC_SLSH)
#define DEL_KEY     LT(_ADJUST, KC_DEL)


// define the center column
#define CENT11   KC_MS_WH_DOWN
#define CENT12   KC_MS_WH_UP
#define CENT21   KC_LEFT
#define CENT22   KC_RIGHT
#define CENT31   KC_DOWN
#define CENT32   KC_UP

#else
    #define SCLN_KEY LT(0, KC_SCLN)
    #define EQL_KEY     LT(0, KC_EQL)
    #define BSLS_KEY    KC_BSLS
    #define ESC_KEY RALT_T(KC_ESC)
    #define ENT_KEY LT(_ADJUST, KC_ENT)
    #define QUOT_KEY LCTL_T(KC_QUOT)
    #define TAB_KEY    LT(_ADJUST, KC_TAB)

    #define MINS_KEY  LT(_MOUSE, KC_MINS)
    #define MINS_KEY_DE  LT(_MOUSE, DE_MINS)

    #define LTHUMB      OSM(MOD_LSFT)
    #define RTHUMB      OSM(MOD_RSFT)
    #define FN_KEY      LT(_ADJUST, KC_APP)
    #define RALT_KEY    OSM(MOD_RALT) // RALT

    // define the secondary function of the lower and raise keys here
    #define LOWER LT(_LOWER, KC_BSPC)
    #define RAISE LT(_RAISE, KC_SPC)

    // GERMAN VERSIONS OF THE KEYS
    #define LOWER_DE LT(_LOWER_DE, KC_BSPC)
    #define RAISE_DE LT(_RAISE_DE, KC_SPC)
    #define Z_KEY LT(0, KC_Z)
    #define Z_KEY_DE LT(1, DE_Z)
    #define SLSH_KEY    LT(0, KC_SLSH)
    #define DEL_KEY     LT(_ADJUST, KC_DEL)

    #define UDIA_KEY    LT(0, DE_UDIA) // sends ü and bsls when held
    #define ADIA_KEY    LT(0, DE_ADIA) // sends ä and quot

#endif

#define SZ_KEY      LSFT_T(DE_SS)
#define SS_KEY      RALT_T(DE_SS)

#define NAVSPACE LT(_ADJUST, KC_SPC)
#define NAVGUI   LT(_ADJUST, KC_LGUI)
//=====================================

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY LT(_LOWER, KC_UP)

#define DOT_KEY LT(0, KC_DOT)
#define COMM_KEY LT(0, KC_COMM)

#define CAPS_KEY LGUI_T(KC_CAPS)

#define BS_KEY KC_BSPC

#define UNDO C(KC_Z)
#define REDO C(KC_Y)

#define LLOCK_NUM LT(_NUM, KC_NO)
#define LLOCK_MOUSE LT(_MOUSE, KC_NO)

#define ADJUST MO(_ADJUST)

#define KB_LANG_SWITCH TG(_COLEMAK_DE)
#define LANG_SWITCH G(KC_SPC)

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    VIM_O,
    ALT_TAB,
    KC_ACC_GRV,
    KC_ACC_ACUT,
    LLOCK, // layer lock key
    //SZ_KEY,
#ifdef GETREUER_REP_KEY_ENABLE
    QK_REPEAT_KEY,
    QK_ALT_REPEAT_KEY,
#endif
    AE_KEY,
    UE_KEY,
    OE_KEY,
#ifdef DUALFUNC
    TOGGLE_DUALF,
#endif
    KC_AFK,
    TG_HRM, // toggle home row mods (dual func keys)
};

#define AFK_KEY KC_MS_D

// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
#ifndef WIDE_LAYOUT
bool de_en_switched = false;
#endif

// ============ TAP DANCE ================
// Tap Dance declarations
#ifdef TAP_DANCE_ENABLE
enum tap_dance_codes {
    TD_LPRN, // round brackets (parentheses)
    TD_LBRC, // square brackets
    TD_LCBR, // curly brackets
    TD_LABK, // angling brackets
};
#endif
