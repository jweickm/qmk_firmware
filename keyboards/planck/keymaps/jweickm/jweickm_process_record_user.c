// initialize the mod_state and the oneshotmod_state variables
uint8_t mod_state;
uint8_t osmod_state;
bool shifted;

// define custom function for sending special characters
void SEND_SPECIAL(char key) {
    switch (key) {
        case '@':
            if (de_layout_active) {
                tap_code16(DE_AT);
            } else {
                tap_code16(KC_AT);
            }
            break;
        case '+':
            if (de_layout_active) {
                tap_code(DE_PLUS);
            } else {
                tap_code16(KC_PLUS);
            }
            break;
        /* case '-': */
        /*     if (de_layout_active) { */
        /*         tap_code(DE_MINS); */
        /*     } else { */
        /*         tap_code(KC_MINS); */
        /*     } */
        /*     break; */
        case '/':
            if (de_layout_active) {
                tap_code16(DE_SLSH);
            } else {
                tap_code(KC_SLSH);
            }
            break;
    }
}

// define custom function for processing special characters and German Key overlay
bool process_german_keycode(keyrecord_t* record, uint16_t keycode) {
    if (de_layout_active) {
        switch (keycode) {
            case DE_Z:
            case DE_Y:
            case DE_MINS:
            case DE_ODIA:
            case DE_ADIA:
            case DE_UDIA:
                if (record->event.pressed) {
                    register_code16(keycode);
                } else {
                    unregister_code16(keycode);
                } 
                return false;
            case DE_QUOT:
                if (record->event.pressed) {
                    if (shifted) { 
                        register_code16(DE_DQUO);
                    } else {
                        register_code16(keycode);
                    }
                } else {
                    unregister_code16(DE_DQUO);
                    unregister_code16(keycode);
                }
                return false;
            case DE_SCLN: // sends ; or :
                if (record->event.pressed) {
                    if (shifted) { 
                        register_code16(DE_COLN);
                    } else {
                        register_code16(keycode);
                    }
                } else {
                    unregister_code16(DE_COLN);
                    unregister_code16(keycode);
                }
                return false;
            case DE_BSLS:
                if (record->event.pressed) {
                    if (shifted) { 
                        register_code16(DE_PIPE);
                    } else {
                        register_code16(keycode);
                    }
                } else {
                    unregister_code16(DE_PIPE);
                    unregister_code16(keycode);
                }
                return false;
            case DE_COMM:
                if (record->event.pressed) {
                    if (shifted) { 
                        clear_mods();
                        clear_oneshot_mods();
                        register_code16(DE_LABK);
                        set_mods(mod_state);
                        return false;
                    }
                } else {
                    unregister_code16(DE_LABK);
                }
                return true;
            case DE_DOT:
                if (record->event.pressed) {
                    if (shifted) { 
                        register_code16(DE_RABK);
                        return false;
                    }
                } else {
                    unregister_code16(DE_RABK);
                }
                return true;
            case DE_SLSH:
                if (record->event.pressed) {
                    if (shifted) { 
                        register_code16(DE_QUES);
                    } else {
                        register_code16(keycode);
                    }
                } else {
                    unregister_code16(DE_QUES);
                    unregister_code16(keycode);
                }
                return false;
            case SZ_KEY:
                tap_code(DE_SS);
                return false;
            default: 
                return true;
        } // end of switch statement
    } else {
        bool processed = false;
        if (record->event.pressed) {
            bool num_lock_was_off;
            if (!num_lock_on) {
                num_lock_was_off = 1;
                tap_code(KC_NUM_LOCK);
            }
            clear_mods();
            clear_oneshot_mods();
            add_mods(MOD_BIT(KC_LALT));
            switch (keycode) {
                case DE_ADIA:
                    if (shifted) {
                        tap_code(KC_P0);
                        tap_code(KC_P1);
                        tap_code(KC_P9);
                        tap_code(KC_P6);  // Ä
                    } else {
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P2);
                        tap_code(KC_P8);  // ä
                    } 
                    processed = true;
                    break;
                case DE_UDIA:
                    if (shifted) {
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P2);
                        tap_code(KC_P0);  // Ü
                    } else {
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P5);
                        tap_code(KC_P2);  // ü
                    }
                    processed = true;
                    break;
                case DE_SCLN:
                case DE_ODIA:
                    if (shifted) {
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P1);
                        tap_code(KC_P4);  // Ö
                    } else {
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P4);
                        tap_code(KC_P6);  // ö
                    }
                    processed = true;
                    break;
                case SZ_KEY:
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                    processed = true;
                    break;
                default:
                    processed = false;
                    break;
            }
            unregister_mods(MOD_LALT);
            set_mods(mod_state);

            if (num_lock_was_off) {
                tap_code(KC_NUM_LOCK);
                num_lock_was_off = 0;
            }
        }
        return !processed; // returns false when an umlaut was specially processed, else returns true and processing continues 
    }
}

float thumb_factor  = 1.05;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
float td_factor     = 1.2;

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case BS_KEY:
        case DEL_KEY:
        case LOWER: 
        case RAISE:
            return TAPPING_TERM * thumb_factor;
        case NAVSPACE:
            return TAPPING_TERM * (thumb_factor + 0.1);

        // index finger keys
        case P_KEY:
        case T_KEY:
        case G_KEY:
        case V_KEY:
        case B_KEY:
        case J_KEY:
        case L_KEY:
        case M_KEY:
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
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case W_KEY:
        case R_KEY:
        case X_KEY:
        case Y_KEY:
        case Y_KEY_DE:
        case I_KEY:
        case DOT_KEY:
            return TAPPING_TERM * ring_factor;

        // pinky keys
        case ESC_KEY:
        case Q_KEY:
        case A_KEY:
        case O_KEY:
        case Z_KEY:
        case Z_KEY_DE:
        case SCLN_KEY:
        case SLSH_KEY:
            return TAPPING_TERM * pinky_factor;
        case LCTL_T(KC_CAPS):
        case OSM(MOD_LSFT):
        case RSFT_T(KC_ENT):
        case BSLS_KEY:
        case QUOT_KEY:
            return TAPPING_TERM; // prefer these ones to be shorter

        // tap-dance actions
        /* case TD(TD_VIM_GG): */
        case TD(TD_PRN):
        case TD(TD_BRC):
        case TD(TD_CBR):
        case TD(TD_F4):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//        case LOWER:
//        case RAISE:
            /* return true; */
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
        /* case LOWER: */
        /* case RAISE: */
            // Immediately select the hold action when another key is pressed.
            /* return true; */
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

#include "features/getreuer/achordion.h"
#include "features/getreuer/layer_lock.h"
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Colemak
    switch (tap_hold_keycode) {
        // define some exceptions here
    }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) { return true; }
  /* if (other_record->event.key.row % (MATRIX_ROWS) >= 3) { return true; } */

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // add all keys here that should NOT be handled by ACHORDION
        case NAVSPACE:
        case LOWER:
        case RAISE:
        case LOWER_DE:
        case RAISE_DE:
        case FN_KEY:
        case DEL_KEY:
        case BS_KEY:
        case BS_KEY_DE:
        case LCTL_T(KC_CAPS):
        case OSM(MOD_LSFT):
        case ESC_KEY:
        case DOWN_KEY:
        case UP_KEY:
        case ENT_KEY:
            return 0; // bypass Achordion for these keys
        case COMM_KEY:
        case DOT_KEY:
        case SLSH_KEY:
        case SCLN_KEY:
        case BSLS_KEY:
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
        case Z_KEY:
        case Z_KEY_DE:
        case X_KEY:
        case C_KEY:
        case V_KEY:
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

// Helper for implementing taps and long-press keys. Given a tap-hold key event,
// replaces the hold function with `long_press_keycode`.
static bool process_tap_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count < 1) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling for tapped keys
}
        
// =================================================================
// +++++++++++++++++++ PROCESS RECORD USER +++++++++++++++++++++++++
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();
    osmod_state = get_oneshot_mods();
    shifted = (mod_state | osmod_state) & MOD_MASK_SHIFT;

    // for the ACHORDION functionality
    if (!process_achordion(keycode, record)) { return false; }
    // for the LAYER_LOCK feature
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        /* case GAMING: */
        /*     if (record->event.pressed) { */
        /*         layer_invert(_GAMING); */
        /*         combo_toggle(); // turns off combos when moving to _GAMING and */ 
        /*         // turn them back on when leaving the layer */
/* #ifdef AUDIO_ENABLE */
        /*         PLAY_SONG(gaming_song); */
/* #endif */
        /*     } */
        /*     return false; */
        /*     break; */
        case KB_LANG_SWITCH: // switches only kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    layer_off(_COLEMAK_DE); // turn off the GERMAN layer
//                    set_single_persistent_default_layer(_COLEMAK);
//                    default_layer_set(1UL<<_COLEMAK); // reduce writing to eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_en_song);
#endif
                } else {
#ifdef NAGINATA_ENABLE
                    if (naginata_active) {
                        naginata_off();
                    }
#endif
                    de_layout_active = true;  // activate German overlay
                    layer_on(_COLEMAK_DE); // turn on the GERMAN layer
//                    set_single_persistent_default_layer(_COLEMAK_DE);
//                    default_layer_set(1UL<<_COLEMAK_DE); // reduce writing to eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_de_song);
#endif
                }
            }
            return false;
        case LANG_SWITCH: // switches both system lang and kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    layer_off(_COLEMAK_DE);
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_en_song);
#endif
                } else {
#ifdef NAGINATA_ENABLE
                    come_from_naginata = naginata_active;
                    if (naginata_active) {
                        naginata_off();
                    }
#endif
                    de_layout_active = true;  // activate German overlay
                    layer_on(_COLEMAK_DE);
 //                   set_single_persistent_default_layer(_COLEMAK_DE);
 //                   default_layer_set(1UL<<_COLEMAK_DE); // reduce writing to eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_de_song);
#endif
                }
            } else {
                tap_code16(A(KC_LSFT));
#ifdef NAGINATA_ENABLE
                if (come_from_naginata && !de_layout_active) {
                    naginata_on();
                }
#endif
            }
            return false;

        case UMLAUT_SWITCH:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                if (de_en_switched) {
                    PLAY_SONG(coding_en_song);
                } else {
                    PLAY_SONG(coding_de_song);
                }
#endif
                de_en_switched = !de_en_switched;   
            }
            return false;
            break;
// ------------------------------- ACTION COMBOS --------------------
        case UMLAUT_RALT:
            if (record->event.pressed) {
                tap_code16(KC_RALT);
                if (de_layout_active) {
                    tap_code16(DE_DQUO);
                } else {
                    tap_code16(KC_DQUO);
                }
            }
            return false;
            break;
// ------------------------ SPECIAL FUNCTION KEYS ------------------------------------
        case VIM_O:
            if (record->event.pressed) {
                if (shifted) {
                    clear_mods();
                    clear_oneshot_mods();
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

        case COPY_ALL:
            if (record->event.pressed) {
                tap_code16(C(KC_HOME)); // go to the beginning of the file
                tap_code16(C(S(KC_END))); // mark everything till the end of the file
                /* tap_code16(C(KC_INS)); // send ctrl + ins -> copy to clipboard */
            }
            return true;
            break;

        case X_KEY:
            return process_tap_long_press_key(record, C(KC_X));
            break;
        case C_KEY:
            return process_tap_long_press_key(record, C(KC_INS));
            break;
        case V_KEY:
            return process_tap_long_press_key(record, S(KC_INS));
            break;
// ================ FROM BASE LAYER =================
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

        case SCLN_KEY:
            if (!process_tap_long_press_key(record, KC_0)) {
                return false;
            } else {
                if (!de_en_switched) { return true; 
                } else {
                return process_german_keycode(record, DE_SCLN);
                }
            }
            break;

        case BSLS_KEY:
            if (!de_layout_active) {
                if (!process_tap_long_press_key(record, KC_UNDS)) { return false; }
                if (!de_en_switched) { return true; } // normal English Layout
            } else {
                if (!process_tap_long_press_key(record, DE_UNDS)) { return false; } 
                    if (de_en_switched) { return 
                        process_german_keycode(record, DE_BSLS); // German layout switched
                    }
            }
            return process_german_keycode(record, DE_UDIA); // sending Ü
            break;

        case QUOT_KEY:
            if (!de_layout_active) {
                if (!process_tap_long_press_key(record, KC_MINS)) { return false; }
                if (!de_en_switched) { return true; }
            } else {
                if (!process_tap_long_press_key(record, DE_MINS)) {return false; }
                if (de_en_switched) { // " 
                    return process_german_keycode(record, DE_QUOT); // sending ' or "
                }
            }
            return process_german_keycode(record, DE_ADIA); // sending Ä
            break;

#ifndef KEY_OVERRIDE_ENABLE
        case K_KEY:
            if (record->event.pressed) {
              if (!de_layout_active && (mod_state == MOD_BIT(KC_LALT))) {
                  tap_code(KC_GRV);
                  return false;
              }
            }
            return true;
#endif
// ================ FROM ADJUST LAYER =================
        /* case CAPS_WORD: */
        /*     if (record->event.pressed) { */
        /*         if (caps_lock_on) { // let this combo turn off caps lock if it is on */
        /*             tap_code(KC_CAPS); */
        /*         } else { */
        /*             caps_word_on();  // Activate Caps Word! */
        /*         } */
        /*     } */
        /*     return false; */
        /*     break; */
        case UNDO:
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(C(DE_Z));
                } else {
                    unregister_code16(C(DE_Z));
                }
                return false;
            }
            return true;
            break;
        case REDO:
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(C(DE_Y));
                } else {
                    unregister_code16(C(DE_Y));
                }
                return false;
            }
            return true;
            break;

        case CTL_TAB:
        case ALT_TAB:
            if (record->event.pressed) {
                switch (keycode) {
                    case ALT_TAB:
                        if (!is_alt_tab_active) {
                            is_alt_tab_active = true;
                            add_mods(MOD_BIT(KC_LALT));
                        } break;
                    case CTL_TAB:
                        if (!is_ctl_tab_active) {
                            is_ctl_tab_active = true;
                            add_mods(MOD_BIT(KC_LCTL));
                        } break;
                    default:
                        break;
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        // the next case allows us to use alt_tab without a timer
        case NAVSPACE: 
            if (!record->event.pressed && (is_alt_tab_active || is_ctl_tab_active)) {
                del_mods(MOD_BIT(KC_LALT));
                del_mods(MOD_BIT(KC_LCTL));
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
            }
            return true;

        case KC_ESC:
        case KC_ENT:
        case ENT_KEY:
        case KC_LEAD:
            if (caps_lock_on && record->event.pressed) {
                tap_code(KC_CAPS);
            }
            return true;

        case ESC_KEY:
            if (caps_lock_on && record->event.pressed) {
                tap_code(KC_CAPS);
            }
            if (!process_tap_long_press_key(record, KC_APP)) {
                return false;
            }
            return true;

// ------------------------- UNICODE ----------------------------------------- 

        case DE_ACC_ACUT: // ´ (dead)
            if (!de_layout_active) {
                if (record->event.pressed) {
                    tap_code(KC_RALT);
                    tap_code(KC_QUOT);
                }
            } else {
                if (record->event.pressed) {
                    tap_code(DE_ACUT);
                }
            }
            return false;
        case DE_ACC_GRV: // ` (dead)
            if (!de_layout_active) {
                if (record->event.pressed) {
                    tap_code(KC_RALT);
                    tap_code(KC_GRV);
                }
            } else {
                if (record->event.pressed) {
                    tap_code16(DE_GRV);
                }
            }
            return false;

// ------------------------- GERMAN KEYMAP ----------------------------------------- 
        case Z_KEY_DE:
            return process_tap_long_press_key(record, DE_SS);
        case Z_KEY: // Z - ß
            if (record->event.pressed && record->tap.count < 1) {
                return process_german_keycode(record, SZ_KEY);
            } 
            return true;
            break;
        case COMM_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_SCLN)) { // long press ;
                    return false;
                } else {
                    return process_german_keycode(record, DE_COMM);
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
                    return process_german_keycode(record, DE_DOT);
                }
            } else {
                return (process_tap_long_press_key(record, KC_COLN)); // :
            }
            break;

        case SLSH_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_QUES)) { // long press ;
                    return false;
                } else {
                    return process_german_keycode(record, DE_SLSH);
                }
            } else {
                return (process_tap_long_press_key(record, KC_QUES)); // ?
            }
            break;
            
            // make a rule so that we can output shifted umlauts from the SPECIAL layer
        case OSM(MOD_LSFT):
            if (IS_LAYER_ON(_UMLAUTS)) {
                if (record->event.pressed) {
                    set_oneshot_layer(_UMLAUTS, ONESHOT_START);
                } else {
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                }
            } else if (IS_LAYER_ON(_ADJUST)) {
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
            return true;

        case SZ_KEY:
        case DE_ADIA:
        case DE_UDIA:
        case DE_ODIA:
            return process_german_keycode(record, keycode);
            break;

#ifdef NO_SEPARATE_GERMAN_LAYERS
        case KC_AT: // @
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_AT);
                } else {
                    unregister_code16(DE_AT);
                }
                return false;
            } else {
                return true;
            }
        case KC_HASH: // #
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code(DE_HASH);
                } else {
                    unregister_code(DE_HASH);
                }
                return false;
            } else {
                return true;
            }
        case KC_TILD: // ~
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_TILD);
                } else {
                    unregister_code16(DE_TILD);
                }
                return false;
            } else {
                return true;
            }
        case KC_CIRC: // ^
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_CIRC);
                } else {
                    unregister_code16(DE_CIRC);
                }
                return false;
            } else {
                return true;
            }
        case KC_AMPR: // &
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_AMPR);
                } else {
                    unregister_code16(DE_AMPR);
                }
                return false;
            } else {
                return true;
            }
        case KC_ASTR: // *
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_ASTR);
                } else {
                    unregister_code16(DE_ASTR);
                }
                return false;
            } else {
                return true;
            }
        case KC_LPRN: // (
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_LPRN);
                } else {
                    unregister_code16(DE_LPRN);
                }
                return false;
            } else {
                return true;
            }
        case KC_RPRN: // )
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_RPRN);
                } else {
                    unregister_code16(DE_RPRN);
                }
                return false;
            } else {
                return true;
            }
        case KC_UNDS: // _
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_UNDS);
                } else {
                    unregister_code16(DE_UNDS);
                }
                return false;
            } else {
                return true;
            }
#endif
        case KC_PLUS: // +
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_PLUS);
                } else {
                    unregister_code16(DE_PLUS);
                }
                return false;
            } else if (!de_layout_active) {
                if (shifted) {
                    if (record->event.pressed) {
                        register_code(KC_EQL);
                        return false;
                    } else {
                        unregister_code(KC_EQL);
                        return false;
                    }
                } 
            } 
            return true;
        case KC_MINS: // -
            if (de_layout_active) {
                return process_german_keycode(record, DE_MINS);
            }
            return true;

#ifdef NO_SEPARATE_GERMAN_LAYERS
        case KC_LCBR: // {
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_LCBR);
                } else {
                    unregister_code16(DE_LCBR);
                }
                return false;
            } else {
                return true;
            }
        case KC_RCBR: // }
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_RCBR);
                } else {
                    unregister_code16(DE_RCBR);
                }
                return false;
            } else {
                return true;
            }
          case KC_QUOT:
              if (de_layout_active) {
                  if (record->event.pressed) {
                      if (shifted) {
                              register_code16(DE_DQUO);  // \"
                      } else {
                              register_code16(DE_QUOT);  // /'
                      }
                  } else {
                      unregister_code16(DE_DQUO);
                      unregister_code16(DE_QUOT);
                  }
                  return false;
              } else {
                  return true;
              }
            break;
        case KC_LABK: // <
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_LABK);
                } else {
                    unregister_code16(DE_LABK);
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_RABK: // >
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_RABK);
                } else {
                    unregister_code16(DE_RABK);
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_DQUO: // "
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_DQUO);
                } else {
                    unregister_code16(DE_DQUO);
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_PIPE: // |
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_PIPE);
                } else {
                    unregister_code16(DE_PIPE);
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_BSLS: // "\"
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_BSLS);
                } else {
                    unregister_code16(DE_BSLS);
                }
                return false;
            } else {
                return true;
            }
        case KC_GRV: // `
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_GRV);
                } else {
                    unregister_code16(DE_GRV);
                }
                return false;
            } else {
                return true;
            }
        case KC_EQL: // =
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_EQL);
                } else {
                    unregister_code16(DE_EQL);
                }
                return false;
            } else {
                return true;
            }
        case KC_LBRC: // [
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_LBRC);
                } else {
                    unregister_code16(DE_LBRC);
                }
                return false;
            } else {
                return true;
            }
        case KC_RBRC: // ]
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_RBRC);
                } else {
                    unregister_code16(DE_RBRC);
                }
                return false;
            } else {
                return true;
            }
#endif


#ifdef NAGINATA_ENABLE
        // 薙刀式
        case EISU:
            if (record->event.pressed) {
//                if (!de_layout_active) {
                    if (naginata_active) {
#ifdef AUDIO_ENABLE
                        PLAY_SONG(naginata_off_sound);
#endif
                    }
                    naginata_off();
//                }
            }
            return false;
            break;

        case NAGINATA_SWITCH:
            if (record->event.pressed) {
                if (naginata_active) {
                    tap_code(KC_MHEN);
                    naginata_off();
                } else if (!de_layout_active){
                    if (caps_lock_on) {
                        tap_code(KC_CAPS);
                    }
                    naginata_on();
                    tap_code(KC_HENK);
                }
            }
            return false;
            break;
        case KANA2:
            if (record->event.pressed) {
                if (!de_layout_active) {
                    if (!naginata_active) {
#ifdef AUDIO_ENABLE
                        PLAY_SONG(naginata_on_sound);
#endif
                    }
                    naginata_on();
                }
            }
            return false;
            break;
#endif
    }
#ifdef NAGINATA_ENABLE
    // 薙刀式
    if (!process_naginata(keycode, record))
        return false;
    // 薙刀式
#endif

    return true;
}
