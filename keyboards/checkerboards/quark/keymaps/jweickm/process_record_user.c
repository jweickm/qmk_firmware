// QUARK
#include "features/getreuer/achordion.h"
#include "features/getreuer/layer_lock.h"
#include "features/getreuer/repeat_key.h"

// =============== HELPER VARIABLES
// logical variable to differentiate between the German and the English input mode
bool de_layout_active = false;
static bool caps_lock_on      = false;
static bool num_lock_on       = false;
bool        is_alt_tab_active = false;

static bool afk = false;

// initialize the mod_state and the oneshotmod_state variables
uint8_t mod_state;
uint8_t osmod_state;
bool    shifted;
bool    shifted_prev; // for the alt repeat key and umlauts
bool    key_tapped;
bool    dualf_is_off;

bool toggle_lock_layer(layer_state_t layer) {
    if (!IS_LAYER_ON(layer)) {
        layer_lock_on(layer); // locks and turns on layer
    } else {
        layer_lock_off(layer); // unlocks and turns off layer
    }
    return false;
}

void turn_num_lock_on(void) {
    // check the host_keybord's num_lock state and turn num_lock on if it is off
    if (!num_lock_on) {
        tap_code(KC_NUM_LOCK);
    }
}

bool register_unregister_key(keyrecord_t *record, uint16_t keycode) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
    return false;
}

bool register_unregister_double(keyrecord_t *record, uint16_t keycode1, uint16_t keycode2) {
    if (record->event.pressed) {
        tap_code16(keycode1);
    }
    return register_unregister_key(record, keycode2);
}

bool register_unregister_shifted_key(keyrecord_t *record, uint16_t keycode, uint16_t shifted_keycode) {
    if (shifted) {
        clear_mods();
        // clear_oneshot_mods();
        register_unregister_key(record, shifted_keycode);
        set_mods(mod_state);
    } else {
        register_unregister_key(record, keycode);
    }
    return false;
}

// Helper for implementing taps and long-press keys. Given a tap-hold key event,
// replaces the hold function with `long_press_keycode`.
static bool process_tap_long_press_key(keyrecord_t *record, uint16_t long_press_keycode) {
    if (record->tap.count < 1) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
#ifdef CAPS_WORD_ENABLE
        caps_word_off(); // break caps_word
#endif
        return false; // Skip default handling.
    }
    return true; // Continue default handling for tapped keys
}

bool process_tap_long_press_shifted_key(keyrecord_t *record, uint16_t long_press_keycode, uint16_t long_press_shifted_keycode) {
    if (shifted) {
        return process_tap_long_press_key(record, long_press_shifted_keycode);
    } else {
        return process_tap_long_press_key(record, long_press_keycode);
    }
}

bool my_tristate_update(keyrecord_t *record, layer_state_t layer) {
    if (record->event.pressed && IS_LAYER_ON(layer) && record->tap.count < 1) {
        layer_on(_ADJUST);
    } else if (!(record->event.pressed) && IS_LAYER_ON(layer)) {
        layer_off(_ADJUST);
        if (is_alt_tab_active) {
            unregister_mods(MOD_BIT(KC_LALT));
            is_alt_tab_active = false;
        }
    }
    return true;
}

bool process_unicode_alt(uint16_t keycode) {
    //  function to process the unicode characters using windows alt + numpad combos (doesn't work usually, hence switching to wincompose)
    bool processed = false;
    add_mods(MOD_BIT(KC_LALT));
    switch (keycode) {
        case DE_ADIA:
            if (shifted || caps_lock_on) {
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P9);
                tap_code(KC_P6); // Ä
            } else {
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P8); // ä
            }
            processed = true;
            break;
        case DE_UDIA:
            if (shifted || caps_lock_on) {
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P0); // Ü
            } else {
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2); // ü
            }
            processed = true;
            break;
        case DE_SCLN:
        case DE_ODIA:
            if (shifted || caps_lock_on) {
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P1);
                tap_code(KC_P4); // Ö
            } else {
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P4);
                tap_code(KC_P6); // ö
            }
            processed = true;
            break;
        // case DE_EURO:
        //     tap_code(KC_P0);
        //     tap_code(KC_P1);
        //     tap_code(KC_P2);
        //     tap_code(KC_P8);  // €
        //     processed = true;
        //     break;
        case SZ_KEY:
            tap_code(KC_P0);
            tap_code(KC_P2);
            tap_code(KC_P2);
            tap_code(KC_P3); // ß
            processed = true;
            break;
        // case KC_DEG:
        //     tap_code(KC_P2);
        //     tap_code(KC_P4);
        //     tap_code(KC_P8);
        //     processed = true;
        //     break;
        default:
            processed = false;
            break;
    }
    unregister_mods(MOD_LALT);
    return processed;
}

bool process_winc(uint16_t keycode) {
    //  function to process the unicode characters using wincompose
    bool processed = false;
    tap_code(KC_COMPOSE);
    switch (keycode) {
        case DE_ADIA:
            tap_code16(KC_DQUO);
            if (shifted) {
                tap_code16(S(KC_A)); // Ä
            } else {
                tap_code(KC_A); // ä
            }
            processed = true;
            break;
        case DE_UDIA:
            tap_code16(KC_DQUO);
            if (shifted) {
                tap_code16(S(KC_U)); // Ü
            } else {
                tap_code(KC_U); // ü
            }
            processed = true;
            break;
        case DE_SCLN:
        case DE_ODIA:
            tap_code16(KC_DQUO);
            if (shifted) {
                tap_code16(S(KC_O)); // Ö
            } else {
                tap_code(KC_O); // ö
            }
            processed = true;
            break;
        // case DE_EURO:
        //     tap_code(KC_EQL);
        //     tap_code(KC_E); // €
        //     processed = true;
        //     break;
        case SZ_KEY:
            tap_code(KC_S);
            tap_code(KC_S); // ß
            processed = true;
            break;
        // case KC_DEG:
        //     tap_code(KC_O);
        //     tap_code(KC_O);
        //     processed = true;
        //     break;
        default:
            processed = false;
            break;
    }
    return processed;
}

// define custom function for processing special characters and German Key overlay
bool process_german_keycode(keyrecord_t *record, uint16_t keycode) {
    bool processed = false;
    if (record->event.pressed && !(IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_LOWER))) {
        if (de_layout_active) {
            return true;
        }
        turn_num_lock_on();
        clear_mods();
        // clear_oneshot_mods();
        /* processed = process_unicode_alt(keycode); */
        processed = process_winc(keycode);
        set_mods(mod_state);
    } else {
        return true;
    }
    return !processed; // returns false when an umlaut was specially processed, else returns true and processing continues
}

// ================= TAP DANCE ===============================
// define the tap dance functions
#ifdef TAP_DANCE_ENABLE
void bracket_matching(qk_tap_dance_state_t *state, uint16_t de_key1, uint16_t en_key1, uint16_t de_key2, uint16_t en_key2) {
    if (de_layout_active) {
        tap_code16(de_key1);
    } else {
        tap_code16(en_key1);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(de_key2);
        } else {
            tap_code16(en_key2);
        }
        tap_code(KC_LEFT);
    }
}

void dance_lprn(qk_tap_dance_state_t *state, void *user_data) {
    bracket_matching(state, DE_LPRN, KC_LPRN, DE_RPRN, KC_RPRN);
}

void dance_lbrc(qk_tap_dance_state_t *state, void *user_data) {
    bracket_matching(state, DE_LBRC, KC_LBRC, DE_RBRC, KC_RBRC);
}

void dance_lcbr(qk_tap_dance_state_t *state, void *user_data) {
    bracket_matching(state, DE_LCBR, KC_LCBR, DE_RCBR, KC_RCBR);
}

void dance_labk(qk_tap_dance_state_t *state, void *user_data) {
    bracket_matching(state, DE_LABK, KC_LABK, DE_RABK, KC_RABK);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_LPRN] = ACTION_TAP_DANCE_FN(dance_lprn),
    [TD_LBRC] = ACTION_TAP_DANCE_FN(dance_lbrc),
    [TD_LCBR] = ACTION_TAP_DANCE_FN(dance_lcbr),
    [TD_LABK] = ACTION_TAP_DANCE_FN(dance_labk),
};
#endif

float thumb_factor  = 1.05;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
#ifdef TAP_DANCE_ENABLE
float td_factor = 1.10; // used to be 1.20
#endif

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case BS_KEY:
        case DEL_KEY:
        case LOWER:
        case RAISE:
        case LOWER_DE:
        case RAISE_DE:
        case TAB_KEY:
            return TAPPING_TERM * thumb_factor;
        case NAVSPACE:
            return TAPPING_TERM * (thumb_factor + 0.1);

        // index finger keys
        case G_KEY:
        case M_KEY:
        case P_KEY:
        case T_KEY:
        case V_KEY:
        case B_KEY:
        case J_KEY:
        case L_KEY:
        case N_KEY:
        case D_KEY:
        case H_KEY:
            return TAPPING_TERM * index_factor;

        // middle finger keys
        case F_KEY:
        case S_KEY:
        case C_KEY:
        case U_KEY:
        case E_KEY:
        case COMM_KEY:
            /* case NUM_2: */
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case W_KEY:
        case R_KEY:
        case X_KEY:
        case Y_KEY:
        case Y_KEY_DE:
        case I_KEY:
        case DOT_KEY:
        case ENT_KEY:
        case ESC_KEY:
            /* case NUM_3: */
            return TAPPING_TERM * ring_factor;

        // pinky keys
        /* case ESC_KEY: */
        case Q_KEY:
        case A_KEY:
        case O_KEY:
        case Z_KEY:
        case Z_KEY_DE:
        case SCLN_KEY:
        case SLSH_KEY:
            return TAPPING_TERM * pinky_factor;
        case CAPS_KEY:
#ifndef WIDE_LAYOUT
        case OSM(MOD_LSFT):
        case OSM(MOD_RSFT):
        case TAB_KEY:
        case BSLS_KEY:
        case UE_KEY:
#endif
        case QUOT_KEY:
            return TAPPING_TERM; // prefer these ones to be shorter

#ifdef TAP_DANCE_ENABLE
        case TD(TD_PRN):
        case TD(TD_BRC):
        case TD(TD_CBR):
        case TD(TD_ABK):
            return TAPPING_TERM * td_factor;
#endif

        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case E_KEY:
        case S_KEY:
        case LOWER:
        case LOWER_DE:
        case RAISE:
        case RAISE_DE:
        case D_KEY:
        case H_KEY:
            return 80; // force hold and disable key repeating
        default:
            return QUICK_TAP_TERM; // allow hold and key repeating by default
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { // allows hold + tap within the tapping term (but hold must be held longer than tap)
    switch (keycode) {
        case S_KEY:
        case E_KEY:
        case LOWER:
        case LOWER_DE:
        case RAISE:
        case RAISE_DE:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// ===================== CAPS WORD ================================
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case DE_UDIA: // DE_UDIA
        case DE_ADIA:
        case DE_ODIA:
            if (!de_layout_active) { // filter for other names in English
                return false;
            }
        case AE_KEY:
        case OE_KEY:
        case UE_KEY:
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_MINS:
        case KC_UNDS:
            if (de_layout_active) {
                return false;
            } else {
                if (!IS_LAYER_ON(_RAISE)) {
                    add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
                }
                return true;
            }
        case DE_MINS:
        case DE_UNDS:
            if (!de_layout_active) {
                return false;
            }
        case KC_1 ... KC_0:
        case KC_KP_1 ... KC_KP_0:
        case KC_BSPC:
        case KC_DEL:
        case QK_REPEAT_KEY:
        case QK_ALT_REPEAT_KEY:
            return true;

        default:
            // continue CAPS_WORD with shift
            /* if (shifted) { */
            /*     return true; */
            /* } */
            return false; // Deactivate Caps Word.
    }
}
#endif

// ===================== COMBOS ===================================
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    if (layer_state_is(_MOUSE)) {
        switch (combo_index) {
            case CD_ESC:
            case HCOMM_ENT:
            case LWR_D_MOUSE:
                return true;
            default:
                return false;
        }
#ifdef WIDE_LAYOUT
    } else if (layer_state_is(_LOWER) || layer_state_is(_LOWER_DE) || layer_state_is(_RAISE) || layer_state_is(_RAISE_DE)) {
        switch (combo_index) {
            case YQUOT:
            case QW_ESC:
                // case PB_DEL:
                // case JL_TAB:
                return false;
            default:
                return true;
        }
#endif
    } else if (layer_state_is(_NUM)) {
        switch (combo_index) {
            case HCOMM_ENT:
            case COMMDOT_CPSWRD:
            case HDOT_COMPOSE:
            case EDOT_BSPC:
                /* case NRAISE: */
                /* case ERAISE: */
                /* case RAISECOMM_TAB: */
                /* case RSE_H_NUM: // combo to disable num_layer */
                return false;
            default:
                return true; // keep the combos activated for these layers
        }
    } else {
        return true;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    switch (combo->keycode) {
#ifdef DH_ENT
        case DH_ENT:
            return 50;
#endif
    }
    return COMBO_TERM; // default value
}

// #ifdef WIDE_LAYOUT
// layer_state_t layer_state_set_user(layer_state_t state) {
// // custom implementation of the tristate update
//     if (
//     ( layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE) ) ||
//     ( layer_state_cmp(state, _LOWER_DE) && layer_state_cmp(state, _RAISE_DE) )
//     ) {
//         return state | (1UL<<_ADJUST);
//     } else {
//         return state & ~(1UL<<_ADJUST);
//     }
// }
// #endif

// ===================== ACHORDION ================================
#ifdef ACHORDION
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Colemak
    switch (tap_hold_keycode) {
        // define some exceptions here
    }

    // Also allow same-hand holds when the other key is in the rows below the
    // alphas.
    if (other_record->event.key.row % (MATRIX_ROWS) >= 3) {
        return true;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // add all keys here that should NOT be handled by ACHORDION
        case TAB_KEY:
        case NAVSPACE:
        case LOWER:
        case RAISE:
        case LOWER_DE:
        case RAISE_DE:
        case DEL_KEY:
        case BS_KEY:
        case CAPS_KEY:
        case ESC_KEY:
        case DOWN_KEY:
        case UP_KEY:
        case ENT_KEY:
        case KC_LCTL:
        case KC_LALT:
        case KC_LGUI:
        case KC_LBRC: 
        case KC_RBRC:
        case KC_BSLS:
        case KC_MINS:
        case KC_LEFT:
        case KC_RIGHT:
            return 0; // bypass Achordion for these keys

        case Z_KEY:
        case Z_KEY_DE:
        case COMM_KEY:
        case DOT_KEY:
        case SLSH_KEY:
        case SCLN_KEY:
        // case UE_KEY:
        case QUOT_KEY:
        case Q_KEY:
        case W_KEY:
        case F_KEY:
        case P_KEY:
        case B_KEY:
        case J_KEY:
        case L_KEY:
        case U_KEY:
        case Y_KEY:
        case Y_KEY_DE:
        case X_KEY:
        case C_KEY:
        case V_KEY:
            /* case NUM_2: */
            /* case NUM_3: */
            /* case G_KEY: */
            /* case M_KEY: */
            return TAPPING_TERM + 60; // return a shorter timeout for these keys (tap event when held) results in 220 ms with current tapping term of 160 ms
    }
    return 400; // otherwise use a timeout of 400 ms.
}


bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply Shift and Ctrl mods.

        default:
            return false; // Wait out the tapping term for the other mods.
    }
}

#endif

// =========================== REPEAT KEYS ==================================
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // only pass when key pressed alone or with shift
    if (!((mods & MOD_MASK_CTRL) || (mods & MOD_MASK_ALT) || (mods & MOD_MASK_GUI))) {
        shifted_prev = (mods & MOD_MASK_SHIFT); // was shift held?
        switch (keycode) {
            case A_KEY:
                return AE_KEY;
            case O_KEY:
                return OE_KEY;
            case U_KEY:
                return UE_KEY;
            case Z_KEY:
            case Z_KEY_DE:
            case S_KEY:
                return SZ_KEY;
        }
    }
    return KC_TRNS; // Defer to default definitions.
}

// =================================================================
// +++++++++++++++++++ PROCESS RECORD USER +++++++++++++++++++++++++
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Disable afk mode if it is on
    if (afk) {
        unregister_code(AFK_KEY);
        afk = false;
    }

    mod_state = get_mods();
    // osmod_state = get_oneshot_mods();
    shifted    = (mod_state & MOD_MASK_SHIFT); //|| (osmod_state & MOD_MASK_SHIFT);
    key_tapped = record->event.pressed && record->tap.count;

#ifdef ACHORDION
    // for the ACHORDION functionality
    if (!dualf_is_off) {
        if (!process_achordion(keycode, record)) {
            return false;
        }
    }
#endif
    // for the REPEAT_KEY feature
    // if (!process_repeat_key(keycode, record, REPEAT)) { return false; }
    if (!process_repeat_key_with_alt(keycode, record, QK_REPEAT_KEY, QK_ALT_REPEAT_KEY)) { return false; }
    // for the custom layer lock key from Getreuer
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

    // make sure that num_lock is turned on, when on the _NUM layer
    if (IS_LAYER_ON(_NUM)) {
        turn_num_lock_on();
    }

    switch (keycode) {
            // ------------------------------- LANGUAGES & LAYERS --------------------------
            // Custom cases to activate _ADJUST layer by pressing LOWER and RAISE together, but still allowing the access of _ADJUST layer directly
        case LOWER:
            return my_tristate_update(record, _RAISE);
            break;
        case RAISE:
            return my_tristate_update(record, _LOWER);
            break;
        case LOWER_DE:
            return my_tristate_update(record, _RAISE_DE);
            break;
        case RAISE_DE:
            return my_tristate_update(record, _LOWER_DE);
            break;

        case KB_LANG_SWITCH: // TG(_COLEMAK_DE): switches only kb lang
            if (record->event.pressed) {
                // invert the state of de_layout_active
                de_layout_active = !de_layout_active;
#ifdef DUALFUNC
                if (dualf_is_off) {
                    layer_invert(_DE_DUALF);
                    layer_invert(_EN_DUALF);
                }
#endif
            }
            return true;

        case LANG_SWITCH: // sends A(KC_LSFT) to change OS language
            if (record->event.pressed) {
                // change keyboard language
                layer_invert(_COLEMAK_DE);
                de_layout_active = !de_layout_active;
#ifdef DUALFUNC
                if (dualf_is_off) {
                    layer_invert(_DE_DUALF);
                    layer_invert(_EN_DUALF);
                }
#endif
            }
            return true;
#ifdef DUALFUNC
        case TOGGLE_DUALF: // toggle dual function keys on key release
            if (!record->event.pressed) {
                dualf_is_off = !dualf_is_off;
                if (de_layout_active) {
                    layer_invert(_DE_DUALF);
                } else {
                    layer_invert(_EN_DUALF);
                }
            }
            return false;
#endif

#ifndef WIDE_LAYOUT
        case UMLAUT_SWITCH: // switches the state of de_en_switched
            if (record->event.pressed) {
                de_en_switched = !de_en_switched;
            }
            return false;
            break;
#endif

            // ------------------------------- ACTION COMBOS --------------------
            // requires LAYER_LOCK by Getreuer
            // move to the _ADJUST LAYER and llock it
            // if it's already active deactivate it
            // case LLOCK_ADJUST:
            //     if (key_tapped) {
            //         return toggle_lock_layer(_ADJUST);
            //     }
            //     return true;
            //     break;

        // move to the _NUM LAYER and llock it
        // if it's already active deactivate it
        case LLOCK_NUM:
            if (key_tapped) {
                return toggle_lock_layer(_NUM);
            }
            return true;
            break;

        case LLOCK_MOUSE:
            if (key_tapped) {
                return toggle_lock_layer(_MOUSE);
            }
            return true;
            break;

// shift to osl(_adjust) when held
#ifndef WIDE_LAYOUT
        case OSL(_UMLAUTS):
            if (record->event.pressed) {
                if (record->tap.count < 1) {    // when key is held
                    add_mods(MOD_BIT(KC_LSFT)); // add the shift
                }
            } else {
                del_mods(MOD_BIT(KC_LSFT)); // release the shift
            }
            return true;
            break;
#endif
            // ------------------------ SPECIAL FUNCTION KEYS ------------------------------------
        case VIM_O:
            if (record->event.pressed) {
                if (shifted) {
                    clear_mods();
                    // clear_oneshot_mods();
                    tap_code(KC_HOME);
                    tap_code(KC_ENT);
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_END);
                    tap_code(KC_ENT);
                }
            }
            return false;
            break;

            /* case COPY_ALL: */
            /*     if (record->event.pressed) { */
            /*         tap_code16(C(KC_HOME)); // go to the beginning of the file */
            /*         tap_code16(C(S(KC_END))); // mark everything till the end of the file */
            /*         /1* tap_code16(C(KC_INS)); // send ctrl + ins -> copy to clipboard *1/ */
            /*     } */
            /*     return true; // registers and unregisters C(KC_INS) */
            /*     break; */

        case X_KEY:
            return process_tap_long_press_key(record, C(KC_X));
        case C_KEY:
            return process_tap_long_press_key(record, C(KC_INS));
        case V_KEY:
            return process_tap_long_press_key(record, S(KC_INS));

        case UNDO:
            if (de_layout_active) {
                return register_unregister_key(record, C(DE_Z));
            }
            return true;
            break;
        case REDO:
            if (de_layout_active) {
                return register_unregister_key(record, C(DE_Y));
            }
            return true;
            break;

        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    add_mods(MOD_BIT(KC_LALT));
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        // the next case allows us to use alt_tab without a timer
        case NAVSPACE:
        case TAB_KEY:
        case DEL_KEY:
            if (!record->event.pressed && is_alt_tab_active) {
                unregister_mods(MOD_BIT(KC_LALT));
                is_alt_tab_active = false;
            }
            return true;

            // make a rule so that we can use it for alt-tabbing without changing the language
        case OSM(MOD_LSFT):
            if (IS_LAYER_ON(_ADJUST)) { // using the add_mods function to not trigger the language change
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
            return true;
            break;

            // case KC_DEG:
            //     if (de_layout_active) {
            //         return register_unregister_key(record, DE_DEG);
            //     }
            // case DE_EURO:
            //     return process_german_keycode(record, keycode); // returns true for de_layout_active
            // ===== PROCESS_GERMAN_KEYCODE =======

        case KC_KP_EQUAL:
            if (de_layout_active) {
                return register_unregister_key(record, DE_EQL);
            } else {
                return register_unregister_key(record, KC_EQL);
            }
            break;

        case KC_KP_MINUS:
            if (shifted) {
                if (de_layout_active) {
                    return register_unregister_key(record, DE_UNDS);
                } else {
                    return register_unregister_key(record, KC_UNDS);
                }
            }
            return true;
            break;

        case KC_UNDS: // make underscore work for both layouts on the _NUM layer
            if (de_layout_active && !IS_LAYER_ON(_LOWER_DE)) {
                return register_unregister_key(record, DE_UNDS);
            }
            return true;

        case KC_HASH: // make hash work as a combo for both layouts
            if (de_layout_active && !IS_LAYER_ON(_LOWER_DE)) {
                return register_unregister_key(record, DE_HASH);
            }
            return true;

            /* case KC_COLN: */
            /*     if (IS_LAYER_ON(_NUM) && de_layout_active) { */
            /*         return register_unregister_key(record, DE_COLN); */
            /*     } */
            /*     return true; */

            // make dead keys send immediately on german keyboard when de_en_switched

            // sends Ralt + " für Umlaute mit Wincompose
            /* case UMLAUT_RALT: */
            /*     if (record->event.pressed) { */
            /*         tap_code16(KC_RALT); */
            /*         if (de_layout_active) { */
            /*             tap_code16(DE_DQUO); */
            /*         } else { */
            /*             tap_code16(KC_DQUO); */
            /*         } */
            /*     } */
            /*     return false; */

        // case KC_ACC_GRV:  // ` (dead)
        // case KC_ACC_ACUT: // ´ (dead)
        //     if (record->event.pressed) {
        //         tap_code(KC_COMPOSE); // using wincompose when on the English Layout
        //         switch (keycode) {
        //             case KC_ACC_ACUT: // ´ (dead)
        //                 tap_code(KC_QUOT);
        //                 break;
        //             case KC_ACC_GRV: // ` (dead)
        //                 tap_code(KC_GRV);
        //                 break;
        //             default:
        //                 break;
        //         }
        //     }
        //     return false;

            // ===== COMBOS ====
#ifndef WIDE_LAYOUT
        case AE_QUOT_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case AE_QUOT:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            } else {
                return process_german_keycode(record, DE_ADIA);
            }
            return false;
        case OE_SCLN_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case OE_SCLN:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_SCLN, DE_COLN);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            } else {
                return process_german_keycode(record, DE_ODIA);
            }
            return false;
        case UE_BSLS_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case UE_BSLS:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            } else {
                return process_german_keycode(record, DE_UDIA);
            }
            return false;
#endif

// ------------------------- GERMAN KEYMAP -----------------------------------------
#ifndef WIDE_LAYOUT
        case Z_KEY_DE:
            return process_tap_long_press_key(record, DE_SS);
        case Z_KEY: // Z - ß
            if (record->event.pressed && record->tap.count < 1) {
                return process_german_keycode(record, SZ_KEY);
            }
            return true;
            break;
#endif
        case S(KC_Z):
            if (IS_LAYER_ON(_NUM) && de_layout_active) {
                return register_unregister_key(record, (S(DE_Z)));
            }
            return true;
            break;

        case COMM_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_SCLN)) { // long press ;
                    return false;
                } else {
                    register_unregister_shifted_key(record, DE_COMM, DE_LABK);
#ifdef CAPS_WORD_ENABLE
                    caps_word_off(); // break caps_word
#endif
                    return false;
                }
            } else {
                return (process_tap_long_press_key(record, KC_SCLN)); // ;
            }
            break;

        case DOT_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_COLN)) { // long press ;
                    return false;
                } else {
                    register_unregister_shifted_key(record, DE_DOT, DE_RABK);
#ifdef CAPS_WORD_ENABLE
                    caps_word_off(); // break caps_word
#endif
                    return false;
                }
            } else {
                return (process_tap_long_press_key(record, KC_COLN)); // :
            }
            break;

#ifdef WIDE_LAYOUT
        case SLSH_KEY:
            if (de_layout_active && record->tap.count > 0) {
                register_unregister_shifted_key(record, DE_SLSH, DE_QUES);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            }
            return true;
            break;
#else
        case SLSH_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_MINS)) { // long press ;
                    return false;
                } else {
                    register_unregister_shifted_key(record, DE_SLSH, DE_QUES);
#    ifdef CAPS_WORD_ENABLE
                    caps_word_off(); // break caps_word
#    endif
                    return false;
                }
            } else {
                return (process_tap_long_press_key(record, KC_MINS)); // ?
            }
            break;
#endif

            /* case KC_MINS: // - */
            /*     if (de_layout_active) { */
            /*         return process_german_keycode(record, DE_QUOT); */
            /*     } */
            /*     return true; */

            // ------------------------- TOP ROW NUMBERS ---------------------------------
        case Q_KEY:
            return process_tap_long_press_key(record, KC_1);
        case W_KEY:
            return process_tap_long_press_key(record, KC_2);
        case F_KEY:
            return process_tap_long_press_key(record, KC_3);
        case P_KEY:
            return process_tap_long_press_key(record, KC_4);
        case B_KEY:
            return process_tap_long_press_key(record, KC_5);
        case J_KEY:
            return process_tap_long_press_key(record, KC_6);
        case L_KEY:
            return process_tap_long_press_key(record, KC_7);
        case U_KEY:
            return process_tap_long_press_key(record, KC_8);
        case Y_KEY_DE:
        case Y_KEY:
            return process_tap_long_press_key(record, KC_9);

#ifdef WIDE_LAYOUT
        case QUOT_KEY: // case for the base English Colemak Layer (continues in the next case)
            if (!process_tap_long_press_key(record, KC_0)) {
                return false;
            }
        case KC_QUOT: // case DE_ADIA:
            // first process the case in the _UMLAUTS layer
            // if (IS_LAYER_ON(_UMLAUTS)) {
            //     return process_german_keycode(record, keycode);
            // }
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            }
            return true;

        case KC_SCLN: // case DE_ODIA:
            // first process the case in the _UMLAUTS layer
            // if (IS_LAYER_ON(_UMLAUTS)) {
            //     return process_german_keycode(record, keycode);
            // }
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_SCLN, DE_COLN);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            }
            return true;

        // case DE_UDIA: // case KC_LBRC
        //     // first process the case in the _UMLAUTS layer
        //     if (IS_LAYER_ON(_UMLAUTS)) {
        //         return process_german_keycode(record, keycode);
        //     }
        //     return true;

        // keycodes to be used with the alternative repeat key
        case AE_KEY:
            if (!shifted) {
                shifted = shifted_prev || is_caps_word_on();
            }
            if (get_repeat_key_count() == -1 && record->event.pressed) { // first alt repeat
                tap_code(KC_BSPC);
            }
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_ADIA, S(DE_ADIA));
            }
            return process_german_keycode(record, DE_ADIA);
        case UE_KEY:
            if (!shifted) {
                shifted = shifted_prev || is_caps_word_on();
            }
            if (get_repeat_key_count() == -1 && record->event.pressed) { // first alt repeat
                tap_code(KC_BSPC);
            }
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_UDIA, S(DE_UDIA));
            }
            return process_german_keycode(record, DE_UDIA);
        case OE_KEY:
            if (!shifted) {
                shifted = shifted_prev || is_caps_word_on();
            }
            if (get_repeat_key_count() == -1 && record->event.pressed) { // first alt repeat
                tap_code(KC_BSPC);
            }
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_ODIA, S(DE_ODIA));
            }
            return process_german_keycode(record, DE_ODIA);

#else
        case SCLN_KEY: // case for the base English Colemak Layer (continues in the next case)
            if (!process_tap_long_press_key(record, KC_0)) {
                return false;
            }
        case KC_SCLN: // case DE_UDIA:
            // first process the DE_ODIA case in the _UMLAUTS layer
            if (IS_LAYER_ON(_UMLAUTS)) {
                return process_german_keycode(record, keycode);
            }
            // then process the key normally when de_en is not switched
            if (!de_en_switched) {
                if (de_layout_active) {
                    register_unregister_shifted_key(record, DE_SCLN, DE_COLN);
#    ifdef CAPS_WORD_ENABLE
                    caps_word_off(); // break caps_word
#    endif
                    return false;
                }
                return true;
            }
            return process_german_keycode(record, DE_UDIA); // sending Ü
            break;
        // ===== PROCESS_GERMAN_KEYCODE =======
        case DE_UDIA: //[ key
            if (IS_LAYER_ON(_UMLAUTS)) {
                return process_german_keycode(record, keycode);
            }
            return true;

#endif
        case SZ_KEY:
            if (get_repeat_key_count() == -1 && record->event.pressed) { // first alt repeat
                tap_code(KC_BSPC);
            }
            if (de_layout_active) {
                return register_unregister_key(record, DE_SS);
            }
            return process_german_keycode(record, keycode); // returns true for de_layout_active
            break;

        case DE_BSLS:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
#ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#endif
                return false;
            }
            return true;

        case DE_MINS:
            if (de_layout_active) {
                if (!IS_LAYER_ON(_RAISE_DE) && is_caps_word_on()) {
                    shifted = true;
                }
                register_unregister_shifted_key(record, DE_MINS, DE_UNDS);
                return false;
            }
            return true;

        case DE_LBRC:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_LBRC, DE_LCBR);
#ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#endif
                return false;
            }
            return true;

        case DE_RBRC:
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_RBRC, DE_RCBR);
#ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#endif
                return false;
            }
            return true;

#ifndef WIDE_LAYOUT
        case BSLS_KEY: // LALT when held LALT_T(KC_BSLS); only for English layout
            /* if (!process_tap_long_press_key(record, KC_APP)) { return false; } */
            if (!de_en_switched || !record->tap.count) {
                return true;
            }
            return process_german_keycode(record, DE_UDIA); // sending Ü
            break;

        case UE_KEY: // LALT when held LALT_T(DE_UDIA); only for German layout
            /* if (!process_tap_long_press_key(record, KC_APP)) { return false; } */
            if (!de_en_switched || !record->tap.count) {
                return true;
            }
            register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
#    ifdef CAPS_WORD_ENABLE
            caps_word_off(); // break caps_word
#    endif
            return false;
            break;

        case QUOT_KEY: // RCTL_T(KC_QUOT), RCTL_T(DE_ADIA)
            // normal processing, also when held
            if (!de_en_switched || !record->tap.count) {
                return true;
            }
            if (de_layout_active) {
                register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
#    ifdef CAPS_WORD_ENABLE
                caps_word_off(); // break caps_word
#    endif
                return false;
            }
            return process_german_keycode(record, DE_ADIA); // sending Ä
            break;
#endif

            // comma and dot for the num pad when held
        /* case NUM_2: */
        /*     return process_tap_long_press_key(record, KC_COMM); */
        /* case NUM_3: */
        /*     return process_tap_long_press_key(record, KC_DOT); */

        // these keys turn off caps lock, if it was active
        case ESC_KEY:
        case KC_ESC:
            /* case KC_ENT: */
            /* case ENT_KEY: */
            if (caps_lock_on && record->event.pressed) {
                tap_code(KC_CAPS);
            }
            return true;

        case KC_AFK: // moves mouse until next key is pressed
            if (!record->event.pressed) { // register on key release to only send one keyboard report to the host pc
                register_code16(AFK_KEY);
                afk = true;
            }
            return false;

        } // switch(keycode) 

    return true;
}
