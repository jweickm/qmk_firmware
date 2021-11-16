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
    VIM_O,
    VIM_V,
    ALT_TAB,
    CTL_TAB,
    DE_EGRAVE,
    DE_EAIGU,
    KC_CURRENCY,
    KC_DE_SWITCH,
    KC_ACUT,
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
#define RAISE OSL(_RAISE)
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
    XD_LEAD,
    BJ_NUM,
    LOWER_RAISE_ADJUST,
    VOLUTAB_MNXT,
    VOLDTAB_MPRV,
    DH_BSPC,
    XC_APP,
    COMMDOT_CAPS,
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

#ifdef NAGINATA_ENABLE
    ST_NAV,
#endif
};

const uint16_t PROGMEM hcomm_combo[]        = {KC_H, KC_COMM, COMBO_END}; 
const uint16_t PROGMEM cd_combo[]           = {KC_C, KC_D, COMBO_END}; 
const uint16_t PROGMEM hdot_combo[]         = {KC_H, KC_DOT, COMBO_END}; 
const uint16_t PROGMEM xd_combo[]           = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM num_combo[]          = {LT(_NUM, KC_B), LT(_NUM, KC_J), COMBO_END};
const uint16_t PROGMEM adj_combo[]          = {LT(_LOWER, KC_BSPC), LT(_RAISE, KC_DEL), COMBO_END};
const uint16_t PROGMEM mnxt_combo[]         = {LT(_MOUSE, KC_VOLU), KC_TAB, COMBO_END};
const uint16_t PROGMEM mprv_combo[]         = {LT(_MOUSE, KC_VOLD), KC_TAB, COMBO_END};
const uint16_t PROGMEM dh_combo[]           = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM xc_combo[]           = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM commdot_combo[]      = {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM nraise_combo[]       = {KC_N, LT(_RAISE, KC_DEL), COMBO_END};
const uint16_t PROGMEM tlower_combo[]       = {KC_T, LT(_LOWER, KC_BSPC), COMBO_END};
const uint16_t PROGMEM ae_combo[]           = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM oe_combo[]           = {KC_E, KC_O, COMBO_END};
const uint16_t PROGMEM ue_combo[]           = {KC_E, RSFT_T(KC_U), COMBO_END};
const uint16_t PROGMEM spcu_combo[]         = {LT(_NAV, KC_SPC), RSFT_T(KC_U), COMBO_END};
const uint16_t PROGMEM spco_combo[]         = {LT(_NAV, KC_SPC), KC_O, COMBO_END};
const uint16_t PROGMEM spca_combo[]         = {LT(_NAV, KC_SPC), KC_A, COMBO_END};
const uint16_t PROGMEM spcs_combo[]         = {LT(_NAV, KC_SPC), KC_S, COMBO_END};

// combos for lower and raise
const uint16_t PROGMEM qlower_combo[]       = {LT(_LOWER, KC_BSPC), LGUI_T(KC_Q),       COMBO_END};
const uint16_t PROGMEM wlower_combo[]       = {LT(_LOWER, KC_BSPC), LALT_T(KC_W),       COMBO_END};
const uint16_t PROGMEM flower_combo[]       = {LT(_LOWER, KC_BSPC), LSFT_T(KC_F),       COMBO_END};
const uint16_t PROGMEM plower_combo[]       = {LT(_LOWER, KC_BSPC), LCTL_T(KC_P),       COMBO_END};
const uint16_t PROGMEM blower_combo[]       = {LT(_LOWER, KC_BSPC), LT(_NUM, KC_B),     COMBO_END};
const uint16_t PROGMEM vollower_combo[]     = {LT(_LOWER, KC_BSPC), LT(_MOUSE, KC_VOLU),COMBO_END};
const uint16_t PROGMEM jlower_combo[]       = {LT(_LOWER, KC_BSPC), LT(_NUM, KC_J),     COMBO_END};
const uint16_t PROGMEM llower_combo[]       = {LT(_LOWER, KC_BSPC), RCTL_T(KC_L),       COMBO_END};
const uint16_t PROGMEM ulower_combo[]       = {LT(_LOWER, KC_BSPC), RSFT_T(KC_U),       COMBO_END};
const uint16_t PROGMEM ylower_combo[]       = {LT(_LOWER, KC_BSPC), LALT_T(KC_Y),       COMBO_END};
const uint16_t PROGMEM sclnlower_combo[]    = {LT(_LOWER, KC_BSPC), RGUI_T(KC_SCLN),    COMBO_END};
const uint16_t PROGMEM uelower_combo[]      = {LT(_LOWER, KC_BSPC), XP(DE_ue, DE_UE),   COMBO_END};

const uint16_t PROGMEM mlower_combo[]       = {LT(_LOWER, KC_BSPC), KC_M,               COMBO_END};
const uint16_t PROGMEM nlower_combo[]       = {LT(_LOWER, KC_BSPC), KC_N,               COMBO_END};
const uint16_t PROGMEM elower_combo[]       = {LT(_LOWER, KC_BSPC), KC_E,               COMBO_END};
const uint16_t PROGMEM ilower_combo[]       = {LT(_LOWER, KC_BSPC), KC_I,               COMBO_END};
const uint16_t PROGMEM olower_combo[]       = {LT(_LOWER, KC_BSPC), KC_O,               COMBO_END};
const uint16_t PROGMEM quotlower_combo[]    = {LT(_LOWER, KC_BSPC), KC_QUOT,            COMBO_END};

const uint16_t PROGMEM qraise_combo[]       = {LT(_RAISE, KC_DEL), LGUI_T(KC_Q),        COMBO_END};
const uint16_t PROGMEM wraise_combo[]       = {LT(_RAISE, KC_DEL), LALT_T(KC_W),        COMBO_END};
const uint16_t PROGMEM fraise_combo[]       = {LT(_RAISE, KC_DEL), LSFT_T(KC_F),        COMBO_END};
const uint16_t PROGMEM praise_combo[]       = {LT(_RAISE, KC_DEL), LCTL_T(KC_P),        COMBO_END};
const uint16_t PROGMEM braise_combo[]       = {LT(_RAISE, KC_DEL), LT(_NUM, KC_B),      COMBO_END};
const uint16_t PROGMEM volraise_combo[]     = {LT(_RAISE, KC_DEL), LT(_MOUSE, KC_VOLU), COMBO_END};
const uint16_t PROGMEM jraise_combo[]       = {LT(_RAISE, KC_DEL), LT(_NUM, KC_J),      COMBO_END};
const uint16_t PROGMEM lraise_combo[]       = {LT(_RAISE, KC_DEL), RCTL_T(KC_L),        COMBO_END};
const uint16_t PROGMEM uraise_combo[]       = {LT(_RAISE, KC_DEL), RSFT_T(KC_U),        COMBO_END};
const uint16_t PROGMEM yraise_combo[]       = {LT(_RAISE, KC_DEL), LALT_T(KC_Y),        COMBO_END};
const uint16_t PROGMEM sclnraise_combo[]    = {LT(_RAISE, KC_DEL), RGUI_T(KC_SCLN),     COMBO_END};
const uint16_t PROGMEM ueraise_combo[]      = {LT(_RAISE, KC_DEL), XP(DE_ue, DE_UE),    COMBO_END};

const uint16_t PROGMEM mraise_combo[]       = {LT(_RAISE, KC_DEL), KC_M,                COMBO_END};
const uint16_t PROGMEM nraise_combo[]       = {LT(_RAISE, KC_DEL), KC_N,                COMBO_END};
const uint16_t PROGMEM eraise_combo[]       = {LT(_RAISE, KC_DEL), KC_E,                COMBO_END};
const uint16_t PROGMEM iraise_combo[]       = {LT(_RAISE, KC_DEL), KC_I,                COMBO_END};
const uint16_t PROGMEM oraise_combo[]       = {LT(_RAISE, KC_DEL), KC_O,                COMBO_END};
const uint16_t PROGMEM quotraise_combo[]    = {LT(_RAISE, KC_DEL), KC_QUOT,             COMBO_END};

#ifdef NAGINATA_ENABLE
const uint16_t PROGMEM stnav_combo[] = {NG_D, NG_F, COMBO_END};
#endif

combo_t key_combos[] = {  
//    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [HCOMM_ENT]     = COMBO(hcomm_combo, KC_ENT),  
    [CD_ESC]        = COMBO(cd_combo, KC_ESC),  
    [HDOT_RALT]     = COMBO(hdot_combo, KC_RALT),  
    [XD_LEAD]       = COMBO(xd_combo, KC_LEAD),
    [BJ_NUM]        = COMBO_ACTION(num_combo),
    [LOWER_RAISE_ADJUST] = COMBO(adj_combo, MO(_ADJUST)),
    [VOLUTAB_MNXT]  = COMBO(mnxt_combo, KC_MNXT),
    [VOLDTAB_MPRV]  = COMBO(mprv_combo, KC_MPRV),
    [DH_BSPC]       = COMBO(dh_combo, KC_BSPC),
    [XC_APP]        = COMBO(xc_combo, KC_APP),
    [COMMDOT_CAPS]  = COMBO(commdot_combo, KC_CAPS),
//    [NRAISE]        = COMBO(nraise_combo, OSL(_RAISE)),
    [TLOWER]        = COMBO(tlower_combo, OSL(_LOWER)),
    [EO_OE]         = COMBO(oe_combo, XP(DE_oe, DE_OE)),
    [EA_AE]         = COMBO(ae_combo, XP(DE_ae, DE_AE)),
    [EU_UE]         = COMBO(ue_combo, XP(DE_ue, DE_UE)),
    [SPC_U]         = COMBO(spcu_combo, XP(DE_ue, DE_UE)),
    [SPC_O]         = COMBO(spco_combo, XP(DE_oe, DE_OE)),
    [SPC_A]         = COMBO(spca_combo, XP(DE_ae, DE_AE)),
    [SPC_S]         = COMBO(spcs_combo, X(DE_SZ)),

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
    }
}
