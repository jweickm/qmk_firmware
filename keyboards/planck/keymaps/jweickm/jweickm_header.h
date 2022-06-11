#pragma once

#include QMK_KEYBOARD_H
/* #include "muse.h" */
#include "keymap_german.h"

enum planck_layers {
    _COLEMAK = 0,
    _COLEMAK_DE,
    _COLEMAK_EN,
    _COLEMAK_EN_DE,
    _UMLAUTS, 
    /* _GAMING, */
#ifdef NAGINATA_ENABLE
    // 薙刀式
    _NAGINATA, // 薙刀式入力レイヤー
    // 薙刀式
#endif
    _LOWER,
    _LOWER_DE,
    _RAISE,
    _RAISE_DE,
    _NUM,
    _NUM_DE,
    /* _NAV, */
    _MOUSE,
    _ADJUST,
};

#ifdef NAGINATA_ENABLE
// 薙刀式
#include "features/naginata/naginata.h"
NGKEYS naginata_keys;
// 薙刀式
#endif

// IMPORTANT: DEFINE THE LAYOUT FOR THE KEYBOARD HERE
/* #define hand_position 3 // 1: semi-wide, 2: wide, 3: narrow */
/* #define layout 1 // 1: 1x2uC, 2: 2x2u, 3: grid */
/* #define thumb 2 // 1: backspace, 2: osm_shift */

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

// define the secondary function of the lower and raise keys here
#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_SPC)

#define DOWN_KEY LT(_LOWER, KC_DOWN)
#define UP_KEY   LT(_LOWER, KC_UP)
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

// ======================================================
// GERMAN VERSIONS OF THE KEYS
#define LOWER_DE    LT(_LOWER_DE, KC_BSPC)
#define RAISE_DE    LT(_RAISE_DE, KC_SPC)
#define BS_KEY_DE   LT(_NUM_DE, KC_BSPC)

#define Z_KEY_DE    LT(1, DE_Z)
#define Y_KEY_DE    LT(1, DE_Y)

#define REDO C(KC_Y)
#define UNDO C(KC_Z)

#define COPY_ALL    C(KC_INS)

enum planck_keycodes {
#ifdef NAGINATA_ENABLE
    // 薙刀式: SAFE_RANGE -> NG_SAFE_RANGE
    COLEMAK = NG_SAFE_RANGE,
    EISU,
    KANA2,
    NG_DUMMY,
    NAGINATA_SWITCH,
    // 薙刀式
#else
    COLEMAK = SAFE_RANGE,
#endif
    GAMING,
    VIM_O,
    ALT_TAB,
    CTL_TAB,
    DE_ACC_GRV,
    DE_ACC_ACUT,
    KB_LANG_SWITCH,
    LANG_SWITCH,
    UMLAUT_SWITCH,
    UMLAUT_RALT,
    LLOCK, // layer lock key
    SZ_KEY
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_CBR,     // curly brackets
    /* TD_VIM_GG,  // single tap to scroll down, double tap to scroll up */
    TD_F4,      // double tap F4 to alt-F4
    TD_LARROW,  // double tap left-angling bracket to get left arrow 
    TD_RARROW,  // double tap right-angling bracket to get right arrow
};

// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

bool caps_lock_on;
bool num_lock_on;

// declaring several logical variables
bool is_alt_tab_active  = false;
bool is_ctl_tab_active  = false;

// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched     = false; 

// NAGINATA AND AUDIO STUFF

#ifdef NAGINATA_ENABLE
bool naginata_active    = false;
bool come_from_naginata = false;
#endif

#ifdef AUDIO_ENABLE
bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

float macro_on_song[][2]        = SONG(SCROLL_LOCK_ON_SOUND);
float macro_off_song[][2]       = SONG(SCROLL_LOCK_OFF_SOUND);
float tone_caps_on[][2]         = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]        = SONG(CAPS_LOCK_OFF_SOUND);
float colemak_de_song[][2]      = SONG(PLANCK_SOUND);
float colemak_en_song[][2]      = SONG(COLEMAK_SOUND);
float gaming_song[][2]          = SONG(CHROMATIC_SOUND);
float chat_song[][2]            = SONG(VOICE_CHANGE_SOUND);

float coding_de_song[][2]       = SONG(PLOVER_SOUND);
float coding_en_song[][2]       = SONG(PLOVER_GOODBYE_SOUND);
float umlaut_on_song[][2]       = SONG(DVORAK_SOUND);
float umlaut_off_song[][2]      = SONG(WORKMAN_SOUND);

#ifdef NAGINATA_ENABLE
float naginata_on_sound[][2]    = SONG(PLOVER_SOUND);
float naginata_off_sound[][2]   = SONG(PLOVER_GOODBYE_SOUND);
#endif
#endif

