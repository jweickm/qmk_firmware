#pragma once

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_german.h"

#ifdef NAGINATA_ENABLE
// 薙刀式
#include "naginata.h"
NGKEYS naginata_keys;
// 薙刀式
#endif

enum planck_layers {
    _COLEMAK = 0,
    _GAMING,
#ifdef NAGINATA_ENABLE
    // 薙刀式
    _NAGINATA, // 薙刀式入力レイヤー
    // 薙刀式
#endif
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
    _NAV,
    _MOUSE,
};

// IMPORTANT: DEFINE THE LAYOUT FOR THE KEYBOARD HERE
#define hand_position 3 // 1: semi-wide, 2: wide, 3: narrow
#if hand_position == 1
    #define layout 1 // 1: with OSM, 2: with OSL
#elif hand_position == 2
    #define layout 1 // 1: 1x2uC, 2: 2x2u, 3: grid
#elif hand_position == 3 
    #define layout 1 // 1: 1x2uC, 2: grid
    #define thumb 2 // 1: backspace, 2: osm_shift
#endif

// define the position of the homerow_mods: 1-top row, 2-mod row, 3-bottom row
#define homerow_mods 1

#if homerow_mods == 1
    #define E_KEY KC_E
    #define S_KEY KC_S
#else 
    #define E_KEY RSFT_T(KC_E)
    #define S_KEY LSFT_T(KC_S)
#endif

// define the secondary function of the lower and raise keys here
#if hand_position == 1 && layout == 2
    #define LOWER OSL(_LOWER)
    #define RAISE OSL(_RAISE)
#else
    #define LOWER LT(_LOWER, KC_BSPC)
    #define RAISE LT(_RAISE, KC_ENT)
#endif

#define NAVSPACE LT(_NAV, KC_SPC)
#define NAVENT LT(_NAV, KC_ENT)
#define CUT_X LT(0, KC_X)
#define COPY_C LT(0, KC_C)
#define PASTE_V LT(0, KC_V)

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
    VIM_V,
    ALT_TAB,
    CTL_TAB,
    REDO, 
    UNDO, 
    DE_ACC_GRV,
    DE_ACC_ACUT,
    KC_DE_SWITCH,
    LANG_SWITCH,
    UMLAUT_SW,
    CODING_SW,
    DE_UE,  // Ü
    DE_OE,  // Ö
    DE_AE,  // Ä
    DE_ue,  // ü
    DE_oe,  // ö
    DE_ae,  // ä
    DE_SZ,   // ß
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_CBR,     // curly brackets
    TD_VIM_GG,  // single tap to scroll down, double tap to scroll up
    TD_F4       // double tap F4 to alt-F4
};

// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool is_alt_tab_active  = false;
bool is_ctl_tab_active  = false;
// controls, whether long pressing A, O, Z results in Ä, Ö, ß
bool umlaut_enable      = false; 
// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_coding_active   = false; 
bool caps_lock_on       = false;

#ifdef NAGINATA_ENABLE
bool naginata_active    = false;
bool come_from_naginata = false;
#endif

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

//#ifdef UNICODE_SELECTED_MODES
//// unicodemap table
//enum unicode_names {
//    DE_ae,
//    DE_AE,
//    DE_oe,
//    DE_OE,
//    DE_ue,
//    DE_UE,
//    DE_SZ,
//};
//const uint32_t PROGMEM unicode_map[] = {
//    [DE_ae]    = 0xE4, // ä
//    [DE_AE]    = 0xC4, // Ä
//    [DE_oe]    = 0xF6, // ö
//    [DE_OE]    = 0xD6, // Ö
//    [DE_ue]    = 0xFC, // ü
//    [DE_UE]    = 0xDC, // Ü
//    [DE_SZ]    = 0xDF, // ß
//};
//#endif

#ifdef AUDIO_ENABLE
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

// Combo Declarations
enum combos {
    HCOMM_ENT,
    CD_ESC,
    HDOT_RALT,
    XD_APP,
    BJ_NUM,
    LR_ADJ,
    BSR_ADJ,
    DOWNRALT_MPRV,
    UPRALT_MNXT,
    DH_ROW,
    XC_CAPS,
    COMMDOT_LEAD,
    XS_TAB, 
    ZS_SZ,
    EDOT_BSPC,
//    NRAISE,
    TLOWER, 
    EO_OE,
    EA_AE,
    EU_UE,
    SPC_U,
    SPC_O, 
    SPC_A, 
    SPC_S,

    // combos for the lower and raise keys
    QLOWER, 
    WLOWER, 
    FLOWER, 
    PLOWER, 
    BLOWER, 
    VOLLOWER,
    JLOWER, 
    LLOWER, 
    ULOWER, 
    YLOWER, 
    SCLNLOWER, 
    UELOWER,
    MLOWER, 
    NLOWER, 
    ELOWER, 
    ILOWER, 
    OLOWER, 
    QUOTLOWER,
    HLOWER, 
    SLOWER,

    QRAISE, 
    WRAISE, 
    FRAISE, 
    PRAISE, 
    BRAISE, 
    VOLRAISE,
    JRAISE, 
    LRAISE, 
    URAISE, 
    YRAISE, 
    SCLNRAISE, 
    UERAISE,
    MRAISE, 
    NRAISE, 
    ERAISE, 
    IRAISE, 
    ORAISE, 
    QUOTRAISE,
    HRAISE,
    RST_OS, 
    NEI_OS,

#ifdef NAGINATA_ENABLE
    ST_NAV,
#endif
};

const uint16_t PROGMEM hcomm_combo[]        = {KC_H, LT(0, KC_COMM),       COMBO_END}; 
const uint16_t PROGMEM cd_combo[]           = {COPY_C, KC_D,               COMBO_END}; 
const uint16_t PROGMEM hdot_combo[]         = {KC_H, LT(0, KC_DOT),        COMBO_END}; 
const uint16_t PROGMEM xd_combo[]           = {CUT_X, KC_D,                COMBO_END};
const uint16_t PROGMEM num_combo[]          = {LT(_NUM, KC_B), LT(_NUM, KC_J), COMBO_END};
const uint16_t PROGMEM adj_combo[]          = {LOWER, RAISE,               COMBO_END};
const uint16_t PROGMEM bs_adj_combo[]       = {LT(_NUM, KC_BSPC), RAISE,   COMBO_END};
const uint16_t PROGMEM upmnxt_combo[]       = {LT(_ADJUST, KC_RALT), LT(_NAV, KC_UP),COMBO_END};
const uint16_t PROGMEM downmprv_combo[]     = {LT(_ADJUST, KC_RALT), LT(_NAV, KC_DOWN),COMBO_END};
const uint16_t PROGMEM dh_combo[]           = {KC_D, KC_H,                 COMBO_END};
const uint16_t PROGMEM xc_combo[]           = {CUT_X, COPY_C,              COMBO_END};
const uint16_t PROGMEM commdot_combo[]      = {LT(0, KC_COMM), LT(0, KC_DOT), COMBO_END};
const uint16_t PROGMEM xs_combo[]           = {CUT_X, S_KEY,        COMBO_END};
const uint16_t PROGMEM zs_combo[]           = {LT(0, KC_Z), S_KEY,  COMBO_END};
const uint16_t PROGMEM edot_combo[]         = {E_KEY, LT(0, KC_DOT),COMBO_END};

//const uint16_t PROGMEM nraise_combo[]       = {KC_N, RAISE, COMBO_END};

// combos for lower and raise
const uint16_t PROGMEM qlower_combo[]       = {LOWER, LGUI_T(KC_Q),        COMBO_END};
const uint16_t PROGMEM wlower_combo[]       = {LOWER, LALT_T(KC_W),        COMBO_END};
const uint16_t PROGMEM flower_combo[]       = {LOWER, LSFT_T(KC_F),        COMBO_END};
const uint16_t PROGMEM plower_combo[]       = {LOWER, LCTL_T(KC_P),        COMBO_END};
const uint16_t PROGMEM blower_combo[]       = {LOWER, LT(_NUM, KC_B),      COMBO_END};
const uint16_t PROGMEM vollower_combo[]     = {LOWER, LT(_MOUSE, KC_VOLU), COMBO_END};
const uint16_t PROGMEM jlower_combo[]       = {LOWER, LT(_NUM, KC_J),      COMBO_END};
const uint16_t PROGMEM llower_combo[]       = {LOWER, RCTL_T(KC_L),        COMBO_END};
const uint16_t PROGMEM ulower_combo[]       = {LOWER, RSFT_T(KC_U),        COMBO_END};
const uint16_t PROGMEM ylower_combo[]       = {LOWER, LALT_T(KC_Y),        COMBO_END};
const uint16_t PROGMEM sclnlower_combo[]    = {LOWER, RGUI_T(KC_SCLN),     COMBO_END};
const uint16_t PROGMEM uelower_combo[]      = {LOWER, LT(0, DE_UDIA),      COMBO_END};

const uint16_t PROGMEM mlower_combo[]       = {LOWER, KC_M,                COMBO_END};
const uint16_t PROGMEM nlower_combo[]       = {LOWER, KC_N,                COMBO_END};
const uint16_t PROGMEM elower_combo[]       = {LOWER, E_KEY,               COMBO_END};
const uint16_t PROGMEM ilower_combo[]       = {LOWER, KC_I,                COMBO_END};
const uint16_t PROGMEM olower_combo[]       = {LOWER, KC_O,                COMBO_END};
const uint16_t PROGMEM quotlower_combo[]    = {LOWER, LT(0, KC_QUOT),      COMBO_END};
const uint16_t PROGMEM hlower_combo[]       = {LOWER, KC_H,                COMBO_END};
const uint16_t PROGMEM slower_combo[]       = {LOWER, S_KEY,               COMBO_END};

const uint16_t PROGMEM qraise_combo[]       = {RAISE, LGUI_T(KC_Q),        COMBO_END};
const uint16_t PROGMEM wraise_combo[]       = {RAISE, LALT_T(KC_W),        COMBO_END};
const uint16_t PROGMEM fraise_combo[]       = {RAISE, LSFT_T(KC_F),        COMBO_END};
const uint16_t PROGMEM praise_combo[]       = {RAISE, LCTL_T(KC_P),        COMBO_END};
const uint16_t PROGMEM braise_combo[]       = {RAISE, LT(_NUM, KC_B),      COMBO_END};
const uint16_t PROGMEM volraise_combo[]     = {RAISE, LT(_MOUSE, KC_VOLU), COMBO_END};
const uint16_t PROGMEM jraise_combo[]       = {RAISE, LT(_NUM, KC_J),      COMBO_END};
const uint16_t PROGMEM lraise_combo[]       = {RAISE, RCTL_T(KC_L),        COMBO_END};
const uint16_t PROGMEM uraise_combo[]       = {RAISE, RSFT_T(KC_U),        COMBO_END};
const uint16_t PROGMEM yraise_combo[]       = {RAISE, LALT_T(KC_Y),        COMBO_END};
const uint16_t PROGMEM sclnraise_combo[]    = {RAISE, RGUI_T(KC_SCLN),     COMBO_END};
const uint16_t PROGMEM ueraise_combo[]      = {RAISE, LT(0, DE_UDIA),      COMBO_END};

const uint16_t PROGMEM mraise_combo[]       = {RAISE, KC_M,                COMBO_END};
const uint16_t PROGMEM nraise_combo[]       = {RAISE, KC_N,                COMBO_END};
const uint16_t PROGMEM eraise_combo[]       = {RAISE, E_KEY,               COMBO_END};
const uint16_t PROGMEM iraise_combo[]       = {RAISE, KC_I,                COMBO_END};
const uint16_t PROGMEM oraise_combo[]       = {RAISE, KC_O,                COMBO_END};
const uint16_t PROGMEM quotraise_combo[]    = {RAISE, LT(0, KC_QUOT),      COMBO_END};
const uint16_t PROGMEM hraise_combo[]       = {RAISE, KC_H,                COMBO_END};

const uint16_t PROGMEM rst_combo[]          = {KC_R, KC_S, KC_T,           COMBO_END};
const uint16_t PROGMEM nei_combo[]          = {KC_N, KC_E, KC_I,           COMBO_END};

#ifdef NAGINATA_ENABLE
const uint16_t PROGMEM stnav_combo[] = {NG_D, NG_F, COMBO_END};
#endif

combo_t key_combos[] = {  
//    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [CD_ESC]        = COMBO(cd_combo, KC_ESC),  
    [HDOT_RALT]     = COMBO(hdot_combo, KC_RALT),  
    [XD_APP]        = COMBO(xd_combo, KC_APP),
    [LR_ADJ]        = COMBO(adj_combo, MO(_ADJUST)),
    [BSR_ADJ]        = COMBO(bs_adj_combo, MO(_ADJUST)),
    [DOWNRALT_MPRV] = COMBO(downmprv_combo, KC_MPRV),
    [UPRALT_MNXT]   = COMBO(upmnxt_combo, KC_MNXT),
    [XC_CAPS]       = COMBO(xc_combo, KC_CAPS),
    [COMMDOT_LEAD]  = COMBO(commdot_combo, KC_LEAD),
    [XS_TAB]        = COMBO(xs_combo, KC_TAB),      
    [ZS_SZ]         = COMBO(zs_combo, DE_SZ),      
    [EDOT_BSPC]     = COMBO(edot_combo, C(KC_BSPC)),

    [DH_ROW]        = COMBO_ACTION(dh_combo),
    [BJ_NUM]        = COMBO_ACTION(num_combo),

//    [NRAISE]        = COMBO(nraise_combo, OSL(_RAISE)),
//    [TLOWER]        = COMBO(tlower_combo, OSL(_LOWER)),
//    [EO_OE]         = COMBO(oe_combo, DE_oe),
//    [EA_AE]         = COMBO(ae_combo, DE_ae),
//    [EU_UE]         = COMBO(ue_combo, DE_ue),
//    [SPC_U]         = COMBO(spcu_combo, DE_ue),
//    [SPC_O]         = COMBO(spco_combo, DE_oe),
//    [SPC_A]         = COMBO(spca_combo, DE_ae),
//    [SPC_S]         = COMBO(spcs_combo, DE_SZ),

    // combos for the lower and raise keys
    [QLOWER]        = COMBO(qlower_combo, KC_EXLM),
    [WLOWER]        = COMBO(wlower_combo, KC_AT),
    [FLOWER]        = COMBO(flower_combo, KC_HASH),
    [PLOWER]        = COMBO(plower_combo, KC_DLR),
    [BLOWER]        = COMBO(blower_combo, KC_PERC),
    [VOLLOWER]      = COMBO(vollower_combo, KC_TILD),
    [JLOWER]        = COMBO(jlower_combo, KC_CIRC),
    [LLOWER]        = COMBO(llower_combo, KC_AMPR),
    [ULOWER]        = COMBO(ulower_combo, KC_ASTR),
    [YLOWER]        = COMBO(ylower_combo, KC_LPRN),
    [SCLNLOWER]     = COMBO(sclnlower_combo, KC_RPRN),
    [UELOWER]       = COMBO(uelower_combo, DE_OE), 
    [MLOWER]        = COMBO(mlower_combo, S(KC_QUOT)),
    [NLOWER]        = COMBO(nlower_combo, KC_UNDS),
    [ELOWER]        = COMBO(elower_combo, KC_PLUS),
    [ILOWER]        = COMBO(ilower_combo, KC_LCBR),
    [OLOWER]        = COMBO(olower_combo, KC_RCBR),
    [QUOTLOWER]     = COMBO(quotlower_combo, DE_AE), 
    [HLOWER]        = COMBO(hlower_combo, KC_GRV),
    [SLOWER]        = COMBO(slower_combo, DE_SZ),

    [QRAISE]        = COMBO(qraise_combo, KC_1),
    [WRAISE]        = COMBO(wraise_combo, KC_2),
    [FRAISE]        = COMBO(fraise_combo, KC_3),
    [PRAISE]        = COMBO(praise_combo, KC_4),
    [VOLRAISE]      = COMBO(volraise_combo, KC_GRV),
    [BRAISE]        = COMBO(braise_combo, KC_5),
    [JRAISE]        = COMBO(jraise_combo, KC_6),
    [LRAISE]        = COMBO(lraise_combo, KC_7),
    [URAISE]        = COMBO(uraise_combo, KC_8),
    [YRAISE]        = COMBO(yraise_combo, KC_9),
    [SCLNRAISE]     = COMBO(sclnraise_combo, KC_0),
    [UERAISE]       = COMBO(ueraise_combo, DE_oe),
    [MRAISE]        = COMBO(mraise_combo, S(KC_COMM)),
    [NRAISE]        = COMBO(nraise_combo, KC_MINS),
    [ERAISE]        = COMBO(eraise_combo, KC_EQL),
    [IRAISE]        = COMBO(iraise_combo, KC_LBRC),
    [ORAISE]        = COMBO(oraise_combo, KC_RBRC),
    [QUOTRAISE]     = COMBO(quotraise_combo, DE_ae),
    [HRAISE]        = COMBO(hraise_combo, S(KC_DOT)), 

    [RST_OS]        = COMBO(rst_combo, OSM(_NAV)),
    [NEI_OS]        = COMBO(nei_combo, TG(_NUM)),

#ifdef NAGINATA_ENABLE
    [ST_NAV]    = COMBO(stnav_combo, MO(_NAV)),
#endif
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case BJ_NUM:
            if (pressed) {
                layer_invert(_NUM);
            }
            break;
        case DH_ROW:
            if (pressed) {
                tap_code(KC_END);
                tap_code(KC_RIGHT);
                tap_code16(S(KC_UP));
            }
            break;
    }
}
