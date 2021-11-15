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
    _COLEMAK,
    _COLEMAK_DE,
    _GAMING,
#ifdef NAGINATA_ENABLE
    // 薙刀式
    _NAGINATA, // 薙刀式入力レイヤー
    // 薙刀式
#endif
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
#ifdef NAGINATA_ENABLE
    // 薙刀式: SAFE_RANGE -> NG_SAFE_RANGE
    COLEMAK = NG_SAFE_RANGE,
    EISU,
    KANA2,
    NG_DUMMY,
    // 薙刀式
#else
    COLEMAK = SAFE_RANGE,
#endif
    GAMING,
    COLEMAK_DE,
    VIM_O,
    VIM_V,
    ALT_TAB,
    CTL_TAB,
    DE_EGRAVE,
    DE_EAIGU,
    KC_CURRENCY,
    KC_DE_SWITCH,
    LANG_SWITCH,
    NAGINATA_SWITCH,
    DE_EN_BSLS,
    M_ESCM,
    UNICODE_ALT_SW,
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_PRN,     // round brackets (parentheses)
    TD_BRC,     // square brackets
    TD_CBR,     // curly brackets
    TD_VIM_GG,  // single tap to scroll down, double tap to scroll up
    TD_F4       // double tap F4 to alt-F4
};

#ifdef UNICODE_SELECTED_MODES
// unicodemap table
enum unicode_names {
    DE_ae,
    DE_AE,
    DE_oe,
    DE_OE,
    DE_ue,
    DE_UE,
    DE_SZ,
    UNI_GRV,
};
const uint32_t PROGMEM unicode_map[] = {
    [DE_ae]    = 0xE4, // ä
    [DE_AE]    = 0xC4, // Ä
    [DE_oe]    = 0xF6, // ö
    [DE_OE]    = 0xD6, // Ö
    [DE_ue]    = 0xFC, // ü
    [DE_UE]    = 0xDC, // Ü
    [DE_SZ]    = 0xDF, // ß
    [UNI_GRV]   = 0x60, // `
};
#endif

#define LOWER OSL(_LOWER)
#define LOWER_DE OSL(_LOWER_DE)
#define RAISE OSL(_RAISE)
#define RAISE_DE OSL(_RAISE_DE)
#define ADJUST OSL(_ADJUST)

#ifdef AUDIO_ENABLE
float macro_on_song[][2]        = SONG(SCROLL_LOCK_ON_SOUND);
float macro_off_song[][2]       = SONG(SCROLL_LOCK_OFF_SOUND);
float tone_caps_on[][2]         = SONG(CAPS_LOCK_ON_SOUND);
float tone_caps_off[][2]        = SONG(CAPS_LOCK_OFF_SOUND);
float colemak_de_song[][2]      = SONG(PLANCK_SOUND);
float colemak_en_song[][2]      = SONG(COLEMAK_SOUND);
float gaming_song[][2]          = SONG(CHROMATIC_SOUND);
float chat_song[][2]            = SONG(VOICE_CHANGE_SOUND);
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
    XD_MENU,
    BJ_NUM,
    VOLUTAB_MNXT,
    VOLDTAB_MPRV,
    DH_BSPC,
    XC_BSPC,
    COMMDOT_CAPS,
//    NRAISE,
//    NRAISE_DE,
    TLOWER, 
    TLOWER_DE,

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
// combos for lower and raise on german
    QLOWER_DE, 
    WLOWER_DE, 
    FLOWER_DE, 
    PLOWER_DE, 
    VOLLOWER_DE,
    BLOWER_DE, 
    JLOWER_DE, 
    LLOWER_DE, 
    ULOWER_DE, 
    UELOWER_DE,
    MLOWER_DE, 
    NLOWER_DE, 
    ELOWER_DE, 
    ILOWER_DE, 
    OLOWER_DE, 

    QRAISE_DE, 
    WRAISE_DE, 
    FRAISE_DE, 
    PRAISE_DE, 
    VOLRAISE_DE,
    BRAISE_DE, 
    JRAISE_DE, 
    LRAISE_DE, 
    URAISE_DE, 
    YRAISE_DE, 
    UERAISE_DE,
    MRAISE_DE, 
    NRAISE_DE, 
    ERAISE_DE, 
    IRAISE_DE, 
    ORAISE_DE, 

#ifdef NAGINATA_ENABLE
    ST_NAV,
#endif
};

const uint16_t PROGMEM hcomm_combo[]= {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM cd_combo[]   = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM hdot_combo[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM xd_combo[]   = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM num_combo[]  = {LT(_NUM, KC_B), LT(_NUM, KC_J), COMBO_END};
const uint16_t PROGMEM mnxt_combo[] = {LT(_MOUSE, KC_VOLU), KC_TAB, COMBO_END};
const uint16_t PROGMEM mprv_combo[] = {LT(_MOUSE, KC_VOLD), KC_TAB, COMBO_END};
const uint16_t PROGMEM dh_combo[]   = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM xc_combo[]   = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM commdot_combo[]      = {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM nraise_combo[]       = {KC_N, LT(_RAISE, KC_ENT), COMBO_END};
//const uint16_t PROGMEM nraise_de_combo[]    = {KC_N, LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM tlower_combo[]       = {KC_T, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM tlower_de_combo[]    = {KC_T, LT(_LOWER_DE, KC_BSPC), COMBO_END};
// combos for lower and raise
const uint16_t PROGMEM qlower_combo[]       = {LGUI_T(KC_Q), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM wlower_combo[]       = {LALT_T(KC_W), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM flower_combo[]       = {LSFT_T(KC_F), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM plower_combo[]       = {LCTL_T(KC_P), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM blower_combo[]       = {LT(_NUM, KC_B), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM vollower_combo[]     = {LT(_MOUSE, KC_VOLU), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM jlower_combo[]       = {LT(_NUM, KC_J), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM llower_combo[]       = {RCTL_T(KC_L), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ulower_combo[]       = {RSFT_T(KC_U), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ylower_combo[]       = {LALT_T(KC_Y), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM sclnlower_combo[]    = {RGUI_T(KC_SCLN), LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM uelower_combo[]      = {XP(DE_ue, DE_UE), LT(_LOWER, KC_BSPC), COMBO_END};

const uint16_t PROGMEM mlower_combo[]       = {KC_M, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM nlower_combo[]       = {KC_N, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM elower_combo[]       = {KC_E, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ilower_combo[]       = {KC_I, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM olower_combo[]       = {KC_O, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM quotlower_combo[]    = {KC_QUOT, LT(_LOWER, KC_BSPC), COMBO_END};

const uint16_t PROGMEM qraise_combo[]       = {LGUI_T(KC_Q), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM wraise_combo[]       = {LALT_T(KC_W), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM fraise_combo[]       = {LSFT_T(KC_F), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM praise_combo[]       = {LCTL_T(KC_P), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM braise_combo[]       = {LT(_NUM, KC_B), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM volraise_combo[]     = {LT(_MOUSE, KC_VOLU), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM jraise_combo[]       = {LT(_NUM, KC_J), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM lraise_combo[]       = {RCTL_T(KC_L), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM uraise_combo[]       = {RSFT_T(KC_U), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM yraise_combo[]       = {LALT_T(KC_Y), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM sclnraise_combo[]    = {RGUI_T(KC_SCLN), LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM ueraise_combo[]      = {XP(DE_ue, DE_UE), LT(_RAISE, KC_ENT), COMBO_END};

const uint16_t PROGMEM mraise_combo[]       = {KC_M, LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM nraise_combo[]       = {KC_N, LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM eraise_combo[]       = {KC_E, LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM iraise_combo[]       = {KC_I, LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM oraise_combo[]       = {KC_O, LT(_RAISE, KC_ENT), COMBO_END};
const uint16_t PROGMEM quotraise_combo[]    = {KC_QUOT, LT(_RAISE, KC_ENT), COMBO_END};

// combos for lower and raise german
const uint16_t PROGMEM qlower_de_combo[]       = {LGUI_T(KC_Q), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM wlower_de_combo[]       = {LALT_T(KC_W), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM flower_de_combo[]       = {LSFT_T(KC_F), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM plower_de_combo[]       = {LCTL_T(KC_P), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM blower_de_combo[]       = {LT(_NUM, KC_B), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM vollower_de_combo[]     = {LT(_MOUSE, KC_VOLU), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM jlower_de_combo[]       = {LT(_NUM, KC_J), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM llower_de_combo[]       = {RCTL_T(KC_L), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ulower_de_combo[]       = {RSFT_T(KC_U), LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM uelower_de_combo[]      = {DE_UDIA, LT(_LOWER_DE, KC_BSPC), COMBO_END};

const uint16_t PROGMEM mlower_de_combo[]       = {KC_M, LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM nlower_de_combo[]       = {KC_N, LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM elower_de_combo[]       = {KC_E, LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ilower_de_combo[]       = {KC_I, LT(_LOWER_DE, KC_BSPC), COMBO_END};
const uint16_t PROGMEM olower_de_combo[]       = {KC_O, LT(_LOWER_DE, KC_BSPC), COMBO_END};

const uint16_t PROGMEM qraise_de_combo[]       = {LGUI_T(KC_Q), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM wraise_de_combo[]       = {LALT_T(KC_W), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM fraise_de_combo[]       = {LSFT_T(KC_F), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM praise_de_combo[]       = {LCTL_T(KC_P), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM volraise_de_combo[]     = {LT(_MOUSE, KC_VOLU), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM braise_de_combo[]       = {LT(_NUM, KC_B), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM jraise_de_combo[]       = {LT(_NUM, KC_J), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM lraise_de_combo[]       = {RCTL_T(KC_L), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM uraise_de_combo[]       = {RSFT_T(KC_U), LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM ueraise_de_combo[]      = {DE_UDIA, LT(_RAISE_DE, KC_ENT), COMBO_END};

const uint16_t PROGMEM mraise_de_combo[]       = {KC_M, LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM nraise_de_combo[]       = {KC_N, LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM eraise_de_combo[]       = {KC_E, LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM iraise_de_combo[]       = {KC_I, LT(_RAISE_DE, KC_ENT), COMBO_END};
const uint16_t PROGMEM oraise_de_combo[]       = {KC_O, LT(_RAISE_DE, KC_ENT), COMBO_END};
#ifdef NAGINATA_ENABLE
const uint16_t PROGMEM stnav_combo[] = {NG_D, NG_F, COMBO_END};
#endif

combo_t key_combos[] = {  
//    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [CD_ESC]        = COMBO(cd_combo, KC_ESC),  
    [HDOT_RALT]     = COMBO(hdot_combo, KC_RALT),  
    [XD_MENU]       = COMBO(xd_combo, KC_APP),
    [BJ_NUM]        = COMBO_ACTION(num_combo),
    [VOLUTAB_MNXT]  = COMBO(mnxt_combo, KC_MNXT),
    [VOLDTAB_MPRV]  = COMBO(mprv_combo, KC_MPRV),
    [DH_BSPC]       = COMBO(dh_combo, KC_BSPC),
    [XC_BSPC]       = COMBO(xc_combo, KC_BSPC),
    [COMMDOT_CAPS]          = COMBO(commdot_combo, KC_CAPS),
//    [NRAISE]        = COMBO(nraise_combo, OSL(_RAISE)),
//    [NRAISE_DE]     = COMBO(nraise_de_combo, OSL(_RAISE_DE)),
    [TLOWER]        = COMBO(tlower_combo, OSL(_LOWER)),
    [TLOWER_DE]     = COMBO(tlower_de_combo, OSL(_LOWER_DE)),

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
    [UELOWER]       = COMBO(uelower_combo, X(DE_OE)),
    [MLOWER]        = COMBO(mlower_combo, X(DE_SZ)),
    [NLOWER]        = COMBO(nlower_combo, KC_UNDS),
    [ELOWER]        = COMBO(elower_combo, KC_PLUS),
    [ILOWER]        = COMBO(ilower_combo, KC_LCBR),
    [OLOWER]        = COMBO(olower_combo, KC_RCBR),
    [QUOTLOWER]     = COMBO(quotlower_combo, X(DE_AE)),

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
    [UERAISE]       = COMBO(ueraise_combo, XP(DE_oe, DE_OE)),
    [MRAISE]        = COMBO(mraise_combo, X(DE_SZ)),
    [NRAISE]        = COMBO(nraise_combo, KC_MINS),
    [ERAISE]        = COMBO(eraise_combo, KC_EQL),
    [IRAISE]        = COMBO(iraise_combo, KC_LBRC),
    [ORAISE]        = COMBO(oraise_combo, KC_RBRC),
    [QUOTRAISE]     = COMBO(quotraise_combo, XP(DE_ae, DE_AE)),

    // combos for the lower and raise keys German
    [QLOWER_DE]        = COMBO(qlower_de_combo, DE_EXLM),
    [WLOWER_DE]        = COMBO(wlower_de_combo, DE_AT),
    [FLOWER_DE]        = COMBO(flower_de_combo, DE_HASH),
    [PLOWER_DE]        = COMBO(plower_de_combo, DE_DLR),
    [BLOWER_DE]        = COMBO(blower_de_combo, DE_PERC),
    [VOLLOWER_DE]      = COMBO(vollower_de_combo, DE_TILD),
    [JLOWER_DE]        = COMBO(jlower_de_combo, DE_CIRC),
    [LLOWER_DE]        = COMBO(llower_de_combo, DE_AMPR),
    [ULOWER_DE]        = COMBO(ulower_de_combo, DE_ASTR),
    [UELOWER_DE]       = COMBO(uelower_de_combo, S(DE_ODIA)),
    [MLOWER_DE]        = COMBO(mlower_de_combo, DE_SS),
    [NLOWER_DE]        = COMBO(nlower_de_combo, DE_UNDS),
    [ELOWER_DE]        = COMBO(elower_de_combo, DE_PLUS),
    [ILOWER_DE]        = COMBO(ilower_de_combo, DE_LCBR),
    [OLOWER_DE]        = COMBO(olower_de_combo, DE_RCBR),

    [QRAISE_DE]        = COMBO(qraise_de_combo, DE_1),
    [WRAISE_DE]        = COMBO(wraise_de_combo, DE_2),
    [FRAISE_DE]        = COMBO(fraise_de_combo, DE_3),
    [PRAISE_DE]        = COMBO(praise_de_combo, DE_4),
    [BRAISE_DE]        = COMBO(braise_de_combo, DE_5),
    [VOLRAISE_DE]      = COMBO(volraise_de_combo, DE_GRV),
    [JRAISE_DE]        = COMBO(jraise_de_combo, DE_6),
    [LRAISE_DE]        = COMBO(lraise_de_combo, DE_7),
    [URAISE_DE]        = COMBO(uraise_de_combo, DE_8),
    [UERAISE_DE]       = COMBO(ueraise_de_combo, DE_ODIA),
    [MRAISE_DE]        = COMBO(mraise_de_combo, DE_SS),
    [NRAISE_DE]        = COMBO(nraise_de_combo, DE_MINS),
    [ERAISE_DE]        = COMBO(eraise_de_combo, DE_EQL),
    [IRAISE_DE]        = COMBO(iraise_de_combo, DE_LBRC),
    [ORAISE_DE]        = COMBO(oraise_de_combo, DE_RBRC),
#ifdef NAGINATA_ENABLE
    [ST_NAV]    = COMBO(stnav_combo, MO(_NAV)),
#endif
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

