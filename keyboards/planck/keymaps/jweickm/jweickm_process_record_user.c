// initialize the mod_state and the oneshotmod_state variables
uint8_t mod_state;
uint8_t osmod_state;

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
        case '-':
            if (de_layout_active) {
                tap_code(DE_MINS);
            } else {
                tap_code(KC_MINS);
            }
            break;
        case '/':
            if (de_layout_active) {
                tap_code16(DE_SLSH);
            } else {
                tap_code(KC_SLSH);
            }
            break;
    }
}

// define custom function for tapping umlaut keys
static bool process_umlaut_on = 0;
bool process_umlaut(uint16_t keycode) {
    process_umlaut_on = 0;
    if (de_layout_active) {
        switch (keycode) {
            case Z_KEY:
                tap_code16(DE_SS);
                return false;
                break;
            default:
                return true;
                break;
        }
    } else {
        bool num_lock_was_off;
        if (!num_lock_on) {
            num_lock_was_off = 1;
            tap_code(KC_NUM_LOCK);
        }
        bool shifted = (mod_state | osmod_state) & MOD_MASK_SHIFT;
        bool processed = false;
        clear_mods();
        clear_oneshot_mods();
        add_mods(MOD_BIT(KC_LALT));
        if (shifted) {
            switch (keycode) {
            case A_KEY:
            case QUOT_KEY:
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P9);
                tap_code(KC_P6);  // Ä
                processed = true;
                break;
            case U_KEY:
            case BSLS_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P0);  // Ü
                processed = true;
                break;
            case O_KEY:
            case SCLN_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P1);
                tap_code(KC_P4);  // Ö
                processed = true;
                break;
            case S_KEY:
            case E_KEY:
            case OSM(MOD_LSFT):
                // turn process_umlaut_on to 0 so we can distinguish and keep the boolean on for another round (s. l. 143)
                process_umlaut_on = 1;
                processed = false;
                break;
            default:
                processed = false;
                break;
            }
        } else {
            switch (keycode) {
            case A_KEY:
            case QUOT_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P8);  // ä
                processed = true;
                break;
            case U_KEY:
            case BSLS_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P5);
                tap_code(KC_P2);  // ü
                processed = true;
                break;
            case O_KEY:
            case SCLN_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P4);
                tap_code(KC_P6);  // ö
                processed = true;
                break;
            case Z_KEY:
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P3);  // ß
                processed = true;
                break;
            case S_KEY:
            case E_KEY:
            case OSM(MOD_LSFT):
                // turn process_umlaut_on to 0 so we can distinguish and keep the boolean on for another round (s. l. 143)
                process_umlaut_on = 1;
                processed = false;
                break;
            default:
                processed = false;
                break; 
            }
        }
        unregister_mods(MOD_LALT);
        set_mods(mod_state);

        if (num_lock_was_off) {
            tap_code(KC_NUM_LOCK);
            num_lock_was_off = 0;
        }
        return !processed; // returns false when an umlaut was specially processed, else returns true and processing continues 
    }
}

// define custom function for tapping umlaut keys
void SEND_UMLAUT(char umlaut) {
    bool num_lock_was_off;
    if (!num_lock_on) {
        num_lock_was_off = 1;
        tap_code(KC_NUM_LOCK);
    }
    clear_mods();
    clear_oneshot_mods();
    add_mods(MOD_BIT(KC_LALT));
    switch (umlaut) {
        /* case 'a': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P8);  // ä */
        /*     break; */
        /* case 'A': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P1); */
        /*     tap_code(KC_P9); */
        /*     tap_code(KC_P6);  // Ä */
        /*     break; */
        /* case 'u': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P5); */
        /*     tap_code(KC_P2);  // ü */
        /*     break; */
        /* case 'U': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P0);  // Ü */
        /*     break; */
        /* case 'o': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P4); */
        /*     tap_code(KC_P6);  // ö */
        /*     break; */
        /* case 'O': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P1); */
        /*     tap_code(KC_P4);  // Ö */
        /*     break; */
        /* case 's': */
        /*     tap_code(KC_P0); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P2); */
        /*     tap_code(KC_P3);  // ß */
        /*     break; */
        case 'e':
            tap_code(KC_P0);
            tap_code(KC_P1);
            tap_code(KC_P2);
            tap_code(KC_P8);  // €
            break;
        case 'y':
            tap_code(KC_P1);
            tap_code(KC_P5);
            tap_code(KC_P7);  // ¥
            break;
        default:
            break; 
    }
    unregister_mods(MOD_LALT);

    if (num_lock_was_off) {
        tap_code(KC_NUM_LOCK);
        num_lock_was_off = 0;
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
        /* case LTHUMB_KEY: */
        case BS_KEY:
        case DEL_KEY:
        case LOWER: 
        case RAISE:
            return TAPPING_TERM * thumb_factor;
        case NAVSPACE:
            return TAPPING_TERM * (thumb_factor + 0.1);

        // index finger keys
        case OSM(MOD_HYPR):
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
        case OSM(MOD_MEH):
        case F_KEY:
        case S_KEY:
        case C_KEY:
        case U_KEY:
        case E_KEY:
        case LT(0, KC_COMM):
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case W_KEY:
        case R_KEY:
        case X_KEY:
        case Y_KEY:
        case I_KEY:
        case LT(0, KC_DOT):
            return TAPPING_TERM * ring_factor;

        // pinky keys
        case Q_KEY:
        case A_KEY:
        case Z_KEY:
        case SCLN_KEY:
        case O_KEY:
        case ESC_KEY:
        case RSFT_T(KC_ENT):
        case LT(0, KC_SLSH):
        case LT(0, KC_MINS):
            return TAPPING_TERM * pinky_factor;
        case LCTL_T(KC_CAPS):
        case OSM(MOD_LSFT):
        case LT(0, KC_BSLS):
        case LT(0, KC_QUOT):
            return TAPPING_TERM; // prefer these ones to be shorter

        // tap-dance actions
        /* case TD(TD_CAPS): */
        case TD(TD_PRN):
        case TD(TD_BRC):
        case TD(TD_CBR):
        case TD(TD_VIM_GG):
        case TD(TD_F4):
            return TAPPING_TERM * td_factor;

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//      case LSFT_T(KC_F):
//      case RSFT_T(KC_U):
        //case S_KEY:
        //case E_KEY:
//        case LOWER:
//        case RAISE:
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
#if thumb != 2
        case LOWER:
        case RAISE:
#endif
            // Immediately select the hold action when another key is pressed.
            return true;
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
        /* case T_KEY: // T + A */
        /*     if (other_keycode == A_KEY) { return true; } */
        /*     break; */
      /* case HOME_S:  // S + H and S + G. */
      /*   if (other_keycode == HOME_H || other_keycode == KC_G) { return true; } */
      /*   break; */
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
        case NAVSFT:
        case NAVSPACE:
        case LOWER:
        case RAISE:
        case FN_KEY:
        case DEL_KEY:
        case BS_KEY:
        case LCTL_T(KC_CAPS):
        case OSM(MOD_LSFT):
        case ESC_KEY:
        case DOWN_KEY:
        case UP_KEY:
        case RSFT_T(KC_ENT):
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
        case X_KEY:
        case C_KEY:
        case V_KEY:
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

    // change the keycodes according to the keyboard language
    if (de_layout_active) {
        Y_CODE      = DE_Y;
        Z_CODE      = DE_Z;
        LABK_CODE   = DE_LABK;
        RABK_CODE   = DE_RABK;
        SCLN_CODE   = DE_SCLN;
        COLN_CODE   = DE_COLN;
        QUOT_CODE   = DE_QUOT;
        DQUO_CODE   = DE_DQUO;
        MINS_CODE   = DE_MINS;
        SLSH_CODE   = DE_SLSH;
        QUES_CODE   = DE_QUES;
    } else {
        Y_CODE      = KC_Y;
        Z_CODE      = KC_Z;
        LABK_CODE   = KC_LABK;
        RABK_CODE   = KC_RABK;
        SCLN_CODE   = KC_SCLN;
        COLN_CODE   = KC_COLN;
        QUOT_CODE   = KC_QUOT;
        DQUO_CODE   = KC_DQUO;
        MINS_CODE   = KC_MINS;
        SLSH_CODE   = KC_SLSH;
        QUES_CODE   = KC_QUES;
    }

    mod_state = get_mods();
    osmod_state = get_oneshot_mods();

    // for the ACHORDION functionality
    if (!process_achordion(keycode, record)) { return false; }
    // for the LAYER_LOCK feature
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    // for the osl umlauts feature
    if (process_umlaut_on && record->event.pressed) {
        if (!process_umlaut(keycode)) {return false;}
    }

    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        /* case QWERTY: */
        /*     if (record->event.pressed) { */
        /*         layer_invert(_QWERTY); */
        /*         // turn them back on when leaving the layer */
/* #ifdef AUDIO_ENABLE */
        /*         PLAY_SONG(gaming_song); */
/* #endif */
        /*     } */
        /*     return false; */
        /*     break; */
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
        case KC_DE_SWITCH: // switches only kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
                    layer_off(_COLEMAK_DE); // turn on the GERMAN layer
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
//                    set_single_persistent_default_layer(_COLEMAK);
//                    default_layer_set(1UL<<_COLEMAK); // reduce writing to eeprom
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
                    layer_off(_COLEMAK_DE);
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
                // "turn off" gaming layer to update the layer state and show
                // the led change
            }
            return false;

// ------------------------------- ACTION COMBOS --------------------
        case OS_UMLAUT:
            if (record->event.pressed) {
                process_umlaut_on = !process_umlaut_on;
            }
            return false;
            break;
        /* case OSL(_UMLAUTS): */
        /*     if (record->event.pressed) { */
        /*         process_umlaut_on = !process_umlaut_on; */
        /*     } */
        /*     return false; */
        /*     break; */
        case UMLAUT_RALT:
            if (record->event.pressed) {
                tap_code16(KC_RALT);
                tap_code16(DQUO_CODE);
                /* SEND_SPECIAL('"'); */
            }
            return false;
            break;
        /* case MN_LARROW: */
        /*     if (record->event.pressed) { */
        /*         if (de_layout_active) { */
        /*             tap_code(DE_LABK); */
        /*             tap_code(DE_MINS); */
        /*         } else { */
        /*             tap_code16(S(KC_COMM)); */
        /*             tap_code16(KC_MINS); */
        /*         } */
        /*     } */
        /*     return false; */
        /*     break; */
        /* case GM_PIPE: */
        /*     if (record->event.pressed) { */
        /*         tap_code16(KC_PERC); */
        /*         if (de_layout_active) { */
        /*             tap_code16(DE_RABK); */
        /*         } else { */
        /*             tap_code16(S(KC_DOT)); */
        /*         } */
        /*         tap_code16(KC_PERC); */
        /*     } */
        /*     return false; */
        /*     break; */
        // now defined in combos.def
        /* case ESCW_ALTF4: */
        /* case ESCBSLS_ALTF4: */
        /*     if (record->event.pressed) { */
        /*         tap_code16(A(KC_F4)); */
        /*     } */
        /*     return false; */
        /*     break; */
// ------------------------ SPECIAL FUNCTION KEYS ------------------------------------
        case VIM_O:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
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
        case Y_KEY:
            if (process_tap_long_press_key(record, KC_9)) {
                if (record->event.pressed) {
                    register_code16(Y_CODE); // is always a y, no matter the kb-lang
                } else {
                    unregister_code16(Y_CODE);
                }
            }
            return false;
        case SCLN_KEY:
            if (process_tap_long_press_key(record, KC_0)) {
                if (record->event.pressed) { // customize the tap action
                    if (!de_en_switched) {
                        return true;
                    } else if (de_en_switched) {
                        if (de_layout_active) {
                            if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                                register_code16(DE_COLN);
                            } else {
                                register_code16(DE_SCLN);
                            }
                        } else if (!de_layout_active) {
                            if (!process_umlaut(SCLN_KEY)) { return false; }
                        }
                        return false;
                    }
                } else { // key release
                    if (de_layout_active) {
                        unregister_code16(DE_COLN);
                        unregister_code16(DE_SCLN);
                    }
                    return true;
                }
            }
            /* if (record->tap.count && record->event.pressed) { */
            /*     if (!de_en_switched) { */
            /*         return true; */
            /*     } else if (de_en_switched) { */
            /*         if (de_layout_active) { */
            /*             if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
            /*                 register_code16(DE_COLN); // register : */
            /*             } else { */
            /*                 register_code16(DE_SCLN); // register ; */
            /*             } */
            /*         } else if (!de_layout_active) { */
            /*             if (!process_umlaut(KC_SCLN)) { return false; } */
            /*             /1* if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { *1/ */
            /*             /1*     SEND_UMLAUT('O'); // Ö *1/ */
            /*             /1* } else { *1/ */
            /*             /1*     SEND_UMLAUT('o'); // ö *1/ */
            /*             /1* } *1/ */
            /*             /1* set_mods(mod_state); *1/ */
            /*         } */
            /*         return false; */
            /*     } */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_0); */
            /*     return false; */
            /* } else { */
            /*     if (de_en_switched && de_layout_active) { */
            /*         unregister_code16(DE_COLN); */
            /*         unregister_code16(DE_SCLN); */
            /*     } */
            /*     return true; */
            /* } */
        case X_KEY:
            return process_tap_long_press_key(record, C(KC_X));
            break;
        case C_KEY:
            return process_tap_long_press_key(record, C(KC_INS));
            break;
        case V_KEY:
            return process_tap_long_press_key(record, S(KC_INS));
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
        case UNDO:
            if (record->event.pressed) {
                register_code16(C(Z_CODE));
                /* if (de_layout_active) { */
                /*     register_code16(C(KC_Y)); */
                /* } else { */
                /*     register_code16(C(KC_Z)); */
                /* } */
            } else {
                unregister_code16(C(Z_CODE));
                /* if (de_layout_active) { */
                /*     unregister_code16(C(KC_Y)); */
                /* } else { */
                /*     unregister_code16(C(KC_Z)); */
                /* } */
            }
            return false;
            break;
        case REDO:
            if (record->event.pressed) {
                register_code16(C(Y_CODE));
                /* if (de_layout_active) { */
                /*     register_code16(C(KC_Z)); */
                /* } else { */
                /*     register_code16(C(KC_Y)); */
                /* } */
            } else {
                unregister_code16(C(Y_CODE));
                /* if (de_layout_active) { */
                /*     unregister_code16(C(KC_Z)); */
                /* } else { */
                /*     unregister_code16(C(KC_Y)); */
                /* } */
            }
            return false;
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
            break;
        case CTL_TAB:
            if (record->event.pressed) {
                if (!is_ctl_tab_active) {
                    is_ctl_tab_active = true;
                    add_mods(MOD_BIT(KC_LCTL));
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
            break;
        /* case RAISE: */
        /* case LOWER: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*         if (osmod_state & MOD_MASK_SHIFT) { */
        /*             clear_oneshot_mods(); */
        /*         } else { */
        /*             set_oneshot_mods(MOD_BIT(KC_LSFT)); */
        /*         } */
        /*         return false; */
        /*     } */
        /*     return true; */
        // the next case allows us to use alt_tab without a timer
        case NAVSPACE: 
            if (!record->event.pressed && (is_alt_tab_active || is_ctl_tab_active)) {
                del_mods(MOD_BIT(KC_LALT));
                del_mods(MOD_BIT(KC_LCTL));
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
            }
            return true;
        case NAVSFT: 
            if (record->event.pressed) {
                add_mods(MOD_BIT(KC_LSFT));
            } else {
                del_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case LT(_NUM, KC_ESC):
        case KC_ESC:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            if (IS_LAYER_ON(_NUM)) {
                layer_off(_NUM);
            }
            return true;
        case ESC_KEY:
            if (record->tap.count && record->event.pressed) {
                if (caps_lock_on) {
                    tap_code(KC_CAPS);
                }
                if (IS_LAYER_ON(_NUM)) {
                    layer_off(_NUM);
                }
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_APP); // press menu button on hold
                return false;
            } else {
            }
            return true;
            break;
        case KC_ENT:
        case ENT_KEY:
        case KC_LEAD:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            return true;
            break;

// ------------------------- UNICODE ----------------------------------------- 
        case CODING_SW:
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

        /* case DE_SZ: */
        /*     if (record->event.pressed) { */
        /*         if (de_layout_active) { */
        /*             register_code(DE_SS); */
        /*             return false; */
        /*         } else { */
        /*             SEND_UMLAUT('s'); // ß */
        /*             set_mods(mod_state); */
        /*             return false; */
        /*             break; */
        /*         } */
        /*         return true; */
        /*     } else { */
        /*         if (de_layout_active) { */
        /*             unregister_code(DE_SS); */
        /*             return false; */
        /*         } */
        /*     } */ 

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
        case Z_KEY: // Z - ß
            if (record->tap.count && record->event.pressed) {
                register_code16(Z_CODE);
                return false;
                /* if (de_layout_active) { */
                /*     register_code(DE_Z);  // Z */
                /*     return false; */
                /* } */
                /* return true; */
            } else if (record->event.pressed) {
                if (!process_umlaut(Z_KEY)) { return false; }
                /* if (de_layout_active && !de_en_switched) { */
                /* if (de_layout_active) { */
                /*     tap_code16(DE_SS); // ß */
                /* } else if (de_layout_active && de_en_switched) { */
                /*     register_code(DE_Z); */
                    /* return false; */
                /* } else { */
                /* } else if (!de_layout_active && de_en_switched) { */
                    /* SEND_UMLAUT('s'); // ß */
                    /* set_mods(mod_state); */
                    /* return false; */
                /* } */ 
            } else {
                unregister_code16(Z_CODE);
                return false;
                /* if (de_layout_active) { */
                /*     unregister_code(DE_Z); */
                /* } else { */
                /*     unregister_code(KC_Z); */
                /* } */
                /* return true; */
            }
            break;
        case COMM_KEY:
            if (!process_tap_long_press_key(record, SCLN_CODE)) { return false; }
            if (record->event.pressed) {
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    clear_mods();
                    clear_oneshot_mods();
                    register_code16(LABK_CODE);
                    set_mods(mod_state);
                    return false;
                } else {
                    return true;
                }
            } else { // key release
                unregister_code16(LABK_CODE);
                return true;
            }
            break;
            /* if (record->tap.count && record->event.pressed) { */
            /*     if (de_layout_active) { */
            /*         if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
            /*             clear_mods(); */
            /*             clear_oneshot_mods(); */
            /*             register_code16(DE_LABK);  // < left angle bracket when shifted */
            /*             set_mods(mod_state); */
            /*         } else { */
            /*             return true; */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /* } else if (record->event.pressed) { // add semicolon as a held key */
            /*     if (de_layout_active) { */
            /*             tap_code16(DE_SCLN); */
            /*     } else { */
            /*         tap_code16(KC_SCLN); */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     if (de_layout_active) { */
            /*         unregister_code16(DE_LABK); */
            /*         unregister_code(KC_COMM); */
            /*         return false; */
            /*     } */
            /*     return true; */
            /* } */
        case DOT_KEY:
            if (!process_tap_long_press_key(record, COLN_CODE)) { return false; }
            if (record->event.pressed) {
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    register_code16(RABK_CODE);
                    return false;
                } else {
                    return true;
                }
            } else { // key relase
                unregister_code16(RABK_CODE);
                return true;
            }
            break;
            /* if (record->tap.count && record->event.pressed) { */
            /*     if (de_layout_active) { */
            /*         if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
            /*             register_code16(DE_RABK);  // > right angle bracket */ 
            /*         } else { */
            /*             return true; */
            /*         } */
            /*         return false; */
            /*     } */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     if (de_layout_active) { */
            /*             tap_code16(DE_COLN); */
            /*     } else { */
            /*         tap_code16(KC_COLN); */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     if (de_layout_active) { */
            /*         unregister_code16(DE_RABK); */
            /*     } */
            /*     return true; */
            /* } */
        /* case M_KEY: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*     } else if (record->event.pressed) { // send '-' on long press */
        /*         SEND_SPECIAL('-'); */
        /*         return false; */
        /*     } */
        /*     return true; */
        case SLSH_KEY: 
            if (!process_tap_long_press_key(record, QUES_CODE)) { return false; }
            if (record->event.pressed) { // tap event
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    register_code16(QUES_CODE); // register ?
                } else {
                    register_code16(SLSH_CODE); // register /
                }
            } else { // key release
                unregister_code16(SLSH_CODE);
                unregister_code16(QUES_CODE);
            }
            return false;
            break;
            /* if (record->tap.count && record->event.pressed) { */
            /*     if (de_layout_active) { */
            /*         if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
            /*             register_code16(DE_QUES); // register ? */
            /*         } else { */
            /*             register_code16(DE_SLSH); // register / */
            /*         } */
            /*         return false; */
            /*     } // process the key normally when English layout is active */
            /*         return true; */
            /* } else if (record->event.pressed) { // register - on hold */
            /*     if (de_layout_active) { */
            /*         tap_code16(DE_QUES); // register ? */
            /*     } else { */ 
            /*         tap_code16(KC_QUES); // register ? */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     if (de_layout_active) { */
            /*         unregister_code16(DE_QUES); // release ? */
            /*         unregister_code16(DE_SLSH); // release / */
            /*         return false; */
            /*     } */
            /*     return true; */
            /* } */
        case QUOT_KEY:
            if ((de_layout_active && de_en_switched) || (!de_layout_active && !de_en_switched)) {
                if (!process_tap_long_press_key(record, MINS_CODE)) { return false; } // send minus when long pressing in default
            } else if (!de_layout_active) {
                if (record->tap.count < 1 && record->event.pressed) { // if key is held when de_en_switched
                    tap_code(KC_QUOT); // sending quot
                    return false; 
                }
            } else if (de_layout_active) { // normal long-press de behaviour resulting in QUOTES
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    if (!process_tap_long_press_key(record, DE_DQUO)) { return false; }
                } else {
                    if (!process_tap_long_press_key(record, DE_QUOT)) { return false; }
                }
            }
            // handling of tapping event:
            if (record->event.pressed) {
                if (de_en_switched) {
                    if (de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            register_code16(DE_DQUO); // sending "
                        } else {
                            register_code16(DE_QUOT); // sending ' or "
                        }
                        return false;
                    } else if (!de_layout_active) {
                        if (!process_umlaut(QUOT_KEY)) { return false; } // sending ä
                    }
                } else if (!de_en_switched) {
                    return true; // return to normal handling for usual quot key
                }
            } else { // key release
                unregister_code16(QUOT_CODE); // releasing '
                unregister_code16(DQUO_CODE); // releasing "
            }
            return true;
            break;
        /* case QUOT_KEY: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*         // tap */
        /*         if (!de_en_switched) { */
        /*             return true; */
        /*         } else if (de_en_switched) { */
        /*             if (de_layout_active) { */
        /*                 if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                     register_code16(DE_DQUO);  // \" */
        /*                 } else { */
        /*                     register_code16(DE_QUOT);  // /' */
        /*                 } */
        /*             } else if (!de_layout_active) { */
        /*                 process_umlaut(A_KEY); */
        /*                 /1* if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { *1/ */
        /*                 /1*     SEND_UMLAUT('A'); // Ä *1/ */
        /*                 /1* } else { *1/ */
        /*                 /1*     SEND_UMLAUT('a'); // ä *1/ */
        /*                 /1* } *1/ */
        /*                 /1* set_mods(mod_state); *1/ */
        /*             } */
        /*             return false; */
        /*         } */
        /*         return false; */
        /*     } else if (record->event.pressed) { // long press */
        /*         if (de_layout_active) { */
        /*             if (!de_en_switched) { // send quotes on long press when in the german layout */
        /*                 if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                     tap_code16(DE_DQUO);  // \" */
        /*                 } else { */
        /*                     tap_code16(DE_QUOT);  // /' */
        /*                 } */
        /*             } else if (de_en_switched) { // send minus in german layout on long-press, when de_en_switched */
        /*                 tap_code(DE_MINS); */
        /*             } */
        /*             return false; */
        /*         } else if (!de_layout_active) { // in the English layout */
        /*             if (!de_en_switched) { // normal processing */
        /*                 tap_code16(KC_MINS); // send minus on long_press */
        /*             } else if (de_en_switched) { */ 
        /*                 tap_code(KC_QUOT); // otherwise send quotes when de_en_switched */
        /*             } */
        /*         return false; */
        /*         } */
        /*     } else { // key release */
        /*         if (de_layout_active) { */
        /*             if (!de_en_switched) { */
        /*                 unregister_mods(DE_ADIA); */
        /*             } else if (de_en_switched) { */
        /*                 unregister_code16(DE_QUOT); */
        /*                 unregister_code16(DE_DQUO); */
        /*             } */
        /*         } else if (!de_layout_active) { */
        /*         } */
        /*         return true; */
        /*     } */
        /*     break; */
        /* case DE_UE: */
        /*     if (!de_en_switched) { */
        /*         if (!process_tap_long_press_key(record, (((mod_state | osmod_state) & MOD_MASK_SHIFT) ? DE_PIPE :DE_BSLS))) { return false }; */
        /*     } else { */
        /*         if (!process_tap_long_press_key(record, DE_UNDS)) { return false }; */
        /*     } */
        /*     if (record->event.pressed) { */
        /*         if (!process_umlaut(BSLS_KEY)) { return false; } */
        /*     } else { */
        /*         return true; */
        /*     } */
        /*     return false; */
        /*     break; */
        case BSLS_KEY:
            if ((de_layout_active && de_en_switched) || (!de_layout_active && !de_en_switched)) {
                if (!process_tap_long_press_key(record, S(MINS_CODE))) { return false; } // send minus when long pressing in default
            } else if (!de_layout_active) {
                if (record->tap.count < 1 && record->event.pressed) { // if key is held when de_en_switched
                    tap_code(KC_BSLS); // sending BSLS
                    return false; 
                }
            } else if (de_layout_active) { // normal long-press de behaviour resulting in BSLS
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    if (!process_tap_long_press_key(record, DE_PIPE)) { return false; }
                } else {
                    if (!process_tap_long_press_key(record, DE_BSLS)) { return false; }
                }
            }
            // handling of tapping event:
            if (record->event.pressed) {
                if (de_en_switched) {
                    if (de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            register_code16(DE_PIPE); // sending |
                        } else {
                            register_code16(DE_BSLS); // sending bsls
                        }
                        return false;
                    } else if (!de_layout_active) {
                        if (!process_umlaut(BSLS_KEY)) { return false; } // sending ü
                    }
                } else if (!de_en_switched) {
                    if (de_layout_active) {
                        register_code(DE_UDIA); // sending Ü
                        return false;
                    } 
                    return true; // return to normal handling for usual bsls key
                }
            } else { // key release
                unregister_code(DE_UDIA);
                unregister_code16(DE_BSLS); // releasing bsls
                unregister_code16(DE_PIPE); // releasing pipe
            }
            return true;
            break;
        /* case BSLS_KEY: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*         // tap */
        /*         if (!de_layout_active) { // on the english layout */
        /*             if (!de_en_switched) { // Normal English functionality */
        /*                 return true; */
        /*             } else if (de_en_switched) { */
        /*                 if (!process_umlaut(BSLS_KEY)) { return false; } */
        /*                 /1* if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { *1/ */
        /*                 /1*     SEND_UMLAUT('U'); *1/ */
        /*                 /1* } else { *1/ */
        /*                 /1*     SEND_UMLAUT('u'); *1/ */
        /*                 /1* } *1/ */
        /*                 /1* set_mods(mod_state); *1/ */
        /*                 /1* return false; *1/ */
        /*             } */
        /*         } else if (de_layout_active) { */
        /*             if (!de_en_switched) { // Normal German functionality */
        /*                 register_code(DE_UDIA); */
        /*             } else if (de_en_switched) { */
        /*                 if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                     clear_oneshot_mods(); */
        /*                     clear_mods(); */
        /*                     register_code16(DE_PIPE); */
        /*                 } else { */
        /*                     register_code16(DE_BSLS); */
        /*                 } */
        /*                 set_mods(mod_state); */
        /*             } */
        /*             return false; */
        /*         } */
        /*     } else if (record->event.pressed) { // long press */
        /*         if (de_layout_active) { // german layout */
        /*             if (!de_en_switched) { // normal behaviour, send special characters on long press */
        /*                 if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                     clear_oneshot_mods(); */
        /*                     clear_mods(); */
        /*                     tap_code16(DE_PIPE); */
        /*                 } else { */
        /*                     tap_code16(DE_BSLS); */
        /*                 } */
        /*                 set_mods(mod_state); */
        /*             } else if (de_en_switched) { */
        /*                 tap_code16(DE_UNDS); */
        /*             } else { */
        /*                 if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                     clear_oneshot_mods(); */
        /*                     clear_mods(); */
        /*                     register_code16(DE_PIPE); */
        /*                 } else { */
        /*                     register_code16(DE_BSLS); */
        /*                 } */
        /*                 set_mods(mod_state); */
        /*             } */
        /*             return false; */
        /*         } else if (!de_layout_active) { */
        /*             if (!de_en_switched) { */
        /*                 tap_code16(KC_UNDS); // underscore */
        /*             } else if (de_en_switched) { */
        /*                 tap_code(KC_BSLS); */
        /*             } */
        /*         } */
        /*         return false; */
        /*     } else { // key release */
        /*         if (de_layout_active) { */
        /*             if (!de_en_switched) { */
        /*                 unregister_code(DE_UDIA); */
        /*             } else if (de_en_switched) { */
        /*                 unregister_code16(DE_PIPE); */
        /*                 unregister_code16(DE_BSLS); */
        /*             } */
        /*         } else if (!de_layout_active) { */
        /*             //unregister_code(KC_BSLS); */
        /*         } */
        /*         return true; */
        /*     } */
        /*     break; */

            // make a rule so that we can output shifted umlauts from the SPECIAL layer
        /* case OSM(MOD_LSFT): */
        /*     if (IS_LAYER_ON(_UMLAUTS)) { */
        /*         if (record->event.pressed) { */
        /*             set_oneshot_layer(_UMLAUTS, ONESHOT_START); */
        /*         } else { */
        /*             clear_oneshot_layer_state(ONESHOT_PRESSED); */
        /*         } */
        /*     } */
        /*     return true; */
        /* case DE_AE: */
        /*     if (record->event.pressed) { */
        /*         if (de_layout_active) { */
        /*             register_code(DE_ADIA); */
        /*             return false; */
        /*         } else { */
        /*             if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                 SEND_UMLAUT('A'); // Ä */
        /*             } else { */
        /*                 SEND_UMLAUT('a'); // ä */
        /*             } */
        /*             set_mods(mod_state); */
        /*             return false; */
        /*         } */
        /*         return true; */
        /*     } else { */
        /*         if (de_layout_active) { */
        /*             unregister_code(DE_ADIA); */
        /*             return false; */
        /*         } */
        /*     } */

        /* case DE_UE: */
        /*     if (record->event.pressed) { */
        /*         if (de_layout_active) { */
        /*             register_code(DE_UDIA); */
        /*             return false; */
        /*         } else { */
        /*             if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
        /*                 SEND_UMLAUT('U'); // Ü */
        /*             } else { */
        /*                 SEND_UMLAUT('u'); // ü */
        /*             } */
        /*             set_mods(mod_state); */
        /*             return false; */
        /*         } */  
        /*         return true; */
        /*     } else { */
        /*         if (de_layout_active) { */
        /*             unregister_code(DE_UDIA); */
        /*             return false; */
        /*         } */
        /*     } */

      /* case DE_OE: */
      /*     if (record->event.pressed) { */
      /*         if (de_layout_active) { */
      /*             register_code(DE_ODIA); */
      /*             return false; */
      /*         } else { */
      /*             if ((mod_state | osmod_state) & MOD_MASK_SHIFT) { */
      /*                 SEND_UMLAUT('O'); // Ö */
      /*             } else { */
      /*                 SEND_UMLAUT('o'); // ö */
      /*             } */
      /*             set_mods(mod_state); */
      /*             return false; */
      /*         } */
      /*         return true; */
      /*     } else { */
      /*         if (de_layout_active) { */
      /*             unregister_code(DE_ODIA); */
      /*             return false; */
      /*         } */
      /*     } */

#ifndef NO_SEPARATE_GERMAN_LAYERS
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
                if (mod_state & MOD_BIT(KC_LCTL)) {
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
#ifndef NO_SEPARATE_GERMAN_LAYERS
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
                      if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
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
            if (record->event.pressed) {
                register_code16(LABK_CODE);
            } else {
                unregister_code16(LABK_CODE);
            }
            return false;
            break;
            /* if (de_layout_active) { */
            /*     if (record->event.pressed) { */
            /*         register_code16(DE_LABK); */
            /*     } else { */
            /*         unregister_code16(DE_LABK); */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     return true; */
            /* } */
        case KC_RABK: // >
            if (record->event.pressed) {
                register_code16(RABK_CODE);
            } else {
                unregister_code16(RABK_CODE);
            }
            return false;
            break;
            /* if (de_layout_active) { */
            /*     if (record->event.pressed) { */
            /*         register_code16(DE_RABK); */
            /*     } else { */
            /*         unregister_code16(DE_RABK); */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     return true; */
            /* } */
        case KC_DQUO: // "
            if (record->event.pressed) {
                register_code16(DQUO_CODE);
            } else {
                unregister_code16(DQUO_CODE);
            }
            return false;
            break;
            /* if (de_layout_active) { */
            /*     if (record->event.pressed) { */
            /*             register_code16(DE_DQUO); */
            /*     } else { */
            /*             unregister_code16(DE_DQUO); */
            /*     } */
            /*     return false; */
            /* } else { */
            /*     return true; */
            /* } */
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
        case KC_MINS: // -
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_MINS);
                } else {
                    unregister_code16(DE_MINS);
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
