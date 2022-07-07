// initialize the mod_state and the oneshotmod_state variables
uint8_t mod_state;
uint8_t osmod_state;
bool shifted;

void turn_num_lock_on(void) {
    // check the host_keybord's num_lock state and turn num_lock on if it is off
    if (!num_lock_on) {
        tap_code(KC_NUM_LOCK);
    }
}

bool register_unregister_key(keyrecord_t* record, uint16_t keycode) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    } 
    return false;
}

bool register_unregister_shifted_key(keyrecord_t* record, uint16_t keycode, uint16_t shifted_keycode) {
    if (record->event.pressed) {
        if (shifted) {
            register_code16(shifted_keycode);
        } else {
            register_code16(keycode);
        }
    } else {
        unregister_code16(keycode);
        unregister_code16(shifted_keycode);
    }
    return false;
}

// define custom function for processing special characters and German Key overlay
bool process_german_keycode(keyrecord_t* record, uint16_t keycode) {
    if (de_layout_active) {
        switch (keycode) {
            case DE_ODIA:
            case DE_ADIA:
            case DE_UDIA:
                return register_unregister_key(record, keycode);
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
            case SZ_KEY:
                if (record->event.pressed) {
                    tap_code(DE_SS);
                }
                return false;
            default: 
                return true;
        } // end of switch statement
    } else {
        bool processed = false;
        if (record->event.pressed) {
            turn_num_lock_on();
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
                case DE_EURO:
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    tap_code(KC_P8);  // ß
                    processed = true;
                    break;
                case SZ_KEY:
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                    processed = true;
                    break;
                case KC_DEG:
                    tap_code(KC_P2);
                    tap_code(KC_P4);
                    tap_code(KC_P8);
                    processed = true;
                    break;
                default:
                    processed = false;
                    break;
            }
            unregister_mods(MOD_LALT);
            set_mods(mod_state);

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
        case LOWER: 
        case RAISE:
        case LOWER_DE: 
        case RAISE_DE:
        case DEL_KEY:
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
        /* case TD(TD_LARROW): */
        /* case TD(TD_VIM_GG): */
        /* case TD(TD_F4): */
        case TD(TD_PRN):
        case TD(TD_BRC):
        case TD(TD_CBR):
        case TD(TD_ABK):
        case TD(TD_RARROW):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case S_KEY:
        case E_KEY:
        case LOWER:
        case LOWER_DE:
            return true; // force hold and disable key repeating for homerow shift
        default:
            return false; // allow hold and key repeating by default
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

// ===================== ACHORDION ================================
#ifdef ACHORDION
#include "features/achordion.h"
#include "features/layer_lock.h"
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
  if (other_record->event.key.row % (MATRIX_ROWS) >= 3) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // add all keys here that should NOT be handled by ACHORDION
        /* case NAVSFT: */
        case NAVSPACE:
        case LOWER:
        case RAISE:
        case LOWER_DE:
        case RAISE_DE:
        case FN_KEY:
        case DEL_KEY:
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
        case Z_KEY:
        case Y_KEY_DE:
        case Z_KEY_DE:
        case X_KEY:
        case C_KEY:
        case V_KEY:
        case G_KEY:
        case M_KEY:
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
        
// Helper for implementing taps and long-press keys. Given a tap-hold key event,
// replaces the hold function with `long_press_keycode`.
static bool process_tap_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count < 1) { // Key is being held.
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
            /* register_code16(long_press_keycode); */
        /* } else { */
            /* unregister_code16(long_press_keycode); */
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

#ifdef ACHORDION
    // for the ACHORDION functionality
    if (!process_achordion(keycode, record)) { return false; }
    // for the custom layer lock key from Getreuer
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
#endif
    
    // make sure that num_lock is turned on, when on the _NUM layer
    if (IS_LAYER_ON(_NUM)) {
        turn_num_lock_on();
    }

    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        case LANG_SWITCH: // switches both system lang and kb lang
        case KB_LANG_SWITCH: // switches only kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    layer_off(_COLEMAK_DE);
                } else {
                    de_layout_active = true;  // activate German overlay
                    layer_on(_COLEMAK_DE);
                }
            } else {
                switch (keycode) {
                    case LANG_SWITCH:
                        tap_code16(A(KC_LSFT));
                        break;
                }
            }
            return false;

        case UMLAUT_SWITCH: // switches the state of de_en_switched
            if (record->event.pressed) {
                de_en_switched = !de_en_switched;   
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
            return true; // registers and unregisters C(KC_INS)
            break;

        case X_KEY:
            return process_tap_long_press_key(record, C(KC_X));
        case C_KEY:
            return process_tap_long_press_key(record, C(KC_INS));
        case V_KEY:
            return process_tap_long_press_key(record, S(KC_INS));
        case K_KEY:
            if (record->event.pressed) {
              if (mod_state == MOD_BIT(KC_LALT)) {
                  tap_code(KC_GRV);
                  return false;
              }
            }
            return true;

        /* case CAPS_WORD: // keycode to toggle caps_word as a combo */
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
            if (!record->event.pressed && is_alt_tab_active) {
                del_mods(MOD_BIT(KC_LALT));
                is_alt_tab_active = false;
            }
            return true;


            // make a rule so that we can output shifted umlauts from the _UMLAUTS layer and we can use it for alt-tabbing without changing the language
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
        case KC_DEG:
        case DE_EURO:
            return process_german_keycode(record, keycode);
            break;

        case KC_KP_EQUAL:
            if (de_layout_active) {
                return register_unregister_key(record, DE_EQL);
            } else {
                return register_unregister_key(record, KC_EQL);
            }
            break;

        case UMLAUT_RALT:
        case DE_ACC_GRV: // ` (dead)
        case DE_ACC_ACUT: // ´ (dead)
            if (record->event.pressed) {
                tap_code(KC_RALT);
                switch(keycode) {
                    case UMLAUT_RALT:
                        tap_code16(S(KC_QUOT));
                        break;
                    case DE_ACC_ACUT: // ´ (dead)
                        tap_code(KC_QUOT);
                        break;
                    case DE_ACC_GRV: // ` (dead)
                        tap_code(KC_GRV);
                        break;
                    default:
                        break;
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
                    return register_unregister_shifted_key(record, DE_DOT, DE_RABK);
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
                    return register_unregister_shifted_key(record, DE_SLSH, DE_QUES);
                }
            } else {
                return (process_tap_long_press_key(record, KC_QUES)); // ?
            }
            break;

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

        case SCLN_KEY:
            if (!process_tap_long_press_key(record, KC_0)) {
                return false;
            } else {
                if (!de_en_switched) { return true; 
                } else {
                    return register_unregister_shifted_key(record, DE_SCLN, DE_COLN); // ö for English and " for German
                }
            }
            break;

        case BSLS_KEY:
            if (!de_layout_active) {
                if (!process_tap_long_press_key(record, KC_UNDS)) { return false; }
                if (!de_en_switched) { return true; } // normal English Layout
            } else {
                if (!process_tap_long_press_key(record, DE_UNDS)) { return false; } 
                    if (de_en_switched) { 
                        return register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
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
                    return register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
                }
            }
            return process_german_keycode(record, DE_ADIA); // sending Ä
            break;

        // these keys turn off caps lock, if it was active
        case KC_ESC:
        case KC_ENT:
        case ENT_KEY:
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
    } // switch(keycode)
    return true;
}

