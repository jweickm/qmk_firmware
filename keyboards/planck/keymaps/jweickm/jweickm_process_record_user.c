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
        case NAVENT:
        case LT(_NUM, KC_ESC):
        case LT(_NUM, KC_BSPC):
        case LOWER: 
        case LSFT_T(KC_BSPC):
        case RAISE:
        case LT(_MOUSE, KC_DEL):
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
            return TAPPING_TERM * index_factor;
//      case KANA_K:
//          return TAPPING_TERM * (index_factor + 0.15);
 //     case LT(_MOUSE, KC_VOLU):
 //     case LT(_MOUSE, KC_VOLD):
 //         return TAPPING_TERM * td_factor;

        // middle finger keys
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
//        case LT(_MOUSE, KC_Z):
//        case LT(_MOUSE, KC_SLSH):
//        case LSFT_T(KC_Z):
//        case LT(0, KC_SCLN):
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

// initialize the mod_state and the oneshotmod_state variables
uint8_t mod_state;
uint8_t osmod_state;
uint16_t hold_duration;

#ifndef ACHORDION
// bools to show that the modifier that is NOT on the home row has been pressed
bool gui_pressed;
bool alt_pressed;
bool sft_pressed;
bool ctl_pressed;

// bools to record which of the home row modifiers has been pressed
bool lgui_held; // left gui     - A_KEY
bool lalt_held; // left alt     - R_KEY
bool lsft_held; // left shift   - S_KEY
bool lctl_held; // left ctrl    - T_KEY
bool rctl_held; // right ctrl   - N_KEY
bool rsft_held; // right shift  - E_KEY
bool ralt_held; // right alt    - I_KEY
bool rgui_held; // right gui    - O_KEY

// bool to see, whether a modifier has been activated on its own
bool modifier_solo_activation;

static uint16_t key_timer;
bool key_filter;

// ++++++++++++++++++++++++++++++ PROCESS_HOMEROW_MODS +++++++++++++++++++++++
bool process_homerow_mods(uint16_t keycode, keyrecord_t *record) {
    hold_duration = timer_elapsed(key_timer);
    switch (keycode) {
        // write keys that should not trigger left hand mods here
        case A_KEY:
        case R_KEY:
        case S_KEY:
        case T_KEY:
        case W_KEY:
            switch (keycode) {
                case A_KEY:
                case R_KEY:
                case S_KEY:
                case T_KEY:
                    key_filter = record->tap.count && record->event.pressed;
                    break;
                default:
                    key_filter = record->event.pressed;
                    break;
            }
            if (key_filter) {
                /* allow triggers for the other hand side */
                if (rctl_held && !(mod_state & MOD_BIT(KC_RCTL))) {
                    register_mods(MOD_BIT(KC_RCTL));
                    /* rctl_held = false; */
                }
                if (rsft_held && !(mod_state & MOD_BIT(KC_RSFT))) {
                    register_mods(MOD_BIT(KC_RSFT));
                    /* rsft_held = false; */
                }
                if (ralt_held && !(mod_state & MOD_BIT(KC_LALT))) {
                    register_mods(MOD_BIT(KC_LALT));
                    /* ralt_held = false; */
                }
                if (rgui_held && !(mod_state & MOD_BIT(KC_RGUI))) {
                    register_mods(MOD_BIT(KC_RGUI));
                    /* rgui_held = false; */
                }
                // check whether the modifier has been held longer than the predefined SAME_HAND_DELAY
                // when tapped and a home row state variable is active, tap the respective key instead of the corresponding mod this disables triggers on the same hand side
                if (lgui_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_LGUI));
                        /* lgui_held = false; */
                    } else {
                        tap_code(KC_A);
                        lgui_held = false;
                    }
                }
                if (lsft_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_LSFT));
                        /* lsft_held = false; */
                    } else {
                        tap_code(KC_S);
                        lsft_held = false;
                    }
                }
                if (lctl_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_LCTL));
                        /* lctl_held = false; */
                    } else {
                        tap_code(KC_T);
                        lctl_held = false;
                    }
                }
                if (lalt_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_LALT));
                        /* lalt_held = false; */
                    } else {
                        tap_code(KC_R);
                        lalt_held = false;
                    }
                }
                modifier_solo_activation = false;
            } else if (record->event.pressed) {
                key_timer = timer_read();
            } else {
            }
            return true;
        // write keys that should not trigger right hand mods here
        case N_KEY:
        case E_KEY:
        case I_KEY:
        case O_KEY:
        case U_KEY:
        case Y_KEY:
        case M_KEY:
        case L_KEY:
            switch (keycode) {
                case O_KEY:
                case I_KEY:
                case E_KEY:
                case N_KEY:
                    key_filter = record->tap.count && record->event.pressed;
                    break;
                default:
                    key_filter = record->event.pressed;
                    break;
            }
            if (key_filter) {
                /* allow triggers for the other hand side */
                if (lctl_held && !(mod_state & MOD_BIT(KC_LCTL))) {
                    register_mods(MOD_BIT(KC_LCTL));
                    /* lctl_held = false; */
                }
                if (lsft_held && !(mod_state & MOD_BIT(KC_LSFT))) {
                    register_mods(MOD_BIT(KC_LSFT));
                    /* lsft_held = false; */
                }
                if (lalt_held && !(mod_state & MOD_BIT(KC_LALT))) {
                    register_mods(MOD_BIT(KC_LALT));
                    /* lalt_held = false; */
                }
                if (lgui_held && !(mod_state & MOD_BIT(KC_LGUI))) {
                    register_mods(MOD_BIT(KC_LGUI));
                    /* lgui_held = false; */
                }
                // check whether the modifier has been held longer than the predefined SAME_HAND_DELAY
                if (rctl_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_RCTL));
                        /* rctl_held = false; */
                    } else {
                        tap_code(KC_N);
                        rctl_held = false;
                    }
                }
                if (rsft_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_RSFT));
                        /* rsft_held = false; */
                    } else {
                        tap_code(KC_E);
                        rsft_held = false;
                    }
                }
                if (ralt_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_LALT));
                        /* ralt_held = false; */
                    } else {
                        tap_code(KC_I);
                        ralt_held = false;
                    }
                }
                if (rgui_held) {
                    if (hold_duration > SAME_HAND_DELAY) {
                        register_mods(MOD_BIT(KC_RGUI));
                        /* rgui_held = false; */
                    } else {
                        tap_code(KC_O);
                        rgui_held = false;
                    }
                }
                modifier_solo_activation = false; // record that another key was pressed
                                                  // (cannot trigger for the same key)
            } else if (record->event.pressed) {
                key_timer = timer_read();
            } else {
            }
            return true;
        default:
            // for all other keys, register the respective mod just before
            // the key is processed in process_record_user
            if (record->event.pressed) {
                // gui mods
                if (lgui_held && !(mod_state & MOD_BIT(KC_LGUI))) {
                    register_mods(MOD_BIT(KC_LGUI));
                    /* lgui_held = false; */
                }
                if (rgui_held && !(mod_state & MOD_BIT(KC_RGUI))) {
                    register_mods(MOD_BIT(KC_RGUI));
                    /* rgui_held = false; */
                }
                // shift mods
                if (lsft_held && !(mod_state & MOD_BIT(KC_LSFT))) {
                    register_mods(MOD_BIT(KC_LSFT));
                    /* lsft_held = false; */
                }
                if (rsft_held && !(mod_state & MOD_BIT(KC_RSFT))) {
                    register_mods(MOD_BIT(KC_RSFT));
                    /* rsft_held = false; */
                }
                // ctrl mods
                if (lctl_held && !(mod_state & MOD_BIT(KC_LCTL))) {
                    register_mods(MOD_BIT(KC_LCTL));
                    /* rctl_held = false; */
                }
                if (rctl_held && !(mod_state & MOD_BIT(KC_RCTL))) {
                    register_mods(MOD_BIT(KC_RCTL));
                    /* rctl_held = false; */
                }
                // alt mods
                if (lalt_held || ralt_held) {
                    if (!(mod_state & MOD_BIT(KC_LALT))) { 
                        register_mods(MOD_BIT(KC_LALT));
                        /* lalt_held = false; */
                        /* ralt_held = false; */
                    }  
                }
                modifier_solo_activation = false;
            }
            return true;
    }
    return true;
}

#else 
#include "features/getreuer/achordion.h"
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
            return 220; // return a shorter timeout for these keys
    }
    return 400; // otherwise use a timeout of 800 ms.
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

// +++++++++++++++++++ PROCESS RECORD USER +++++++++++++++++++++++++
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifndef ACHORDION
    /* process the home row mod tags before anything else */
    mod_state = get_mods();
    if (!process_homerow_mods(keycode, record)) {
        return false;
    }
#else 
    // for the ACHORDION functionality
    if (!process_achordion(keycode, record)) { return false; }
#endif
    mod_state = get_mods();
    osmod_state = get_oneshot_mods();
    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        case QWERTY:
            if (record->event.pressed) {
                layer_invert(_QWERTY);
                // turn them back on when leaving the layer
#ifdef AUDIO_ENABLE
                PLAY_SONG(gaming_song);
#endif
            }
            return false;
            break;
        case GAMING:
            if (record->event.pressed) {
                layer_invert(_GAMING);
                combo_toggle(); // turns off combos when moving to _GAMING and 
                // turn them back on when leaving the layer
#ifdef AUDIO_ENABLE
                PLAY_SONG(gaming_song);
#endif
            }
            return false;
            break;
        case KC_DE_SWITCH: // switches only kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
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
//                    set_single_persistent_default_layer(_COLEMAK_DE);
//                    default_layer_set(1UL<<_COLEMAK_DE); // reduce writing to eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_de_song);
#endif
                }
                layer_off(_GAMING);
            }
            return false;
        case LANG_SWITCH: // switches both system lang and kb lang
            if (record->event.pressed) {
                if (de_layout_active) {
                    de_layout_active = false;  // deactivate German overlay
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
                layer_off(_GAMING);
            }
            return false;

// ------------------------------- ACTION COMBOS --------------------
        case MN_LARROW:
            if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code(DE_LABK);
                    tap_code(DE_MINS);
                } else {
                    tap_code16(S(KC_COMM));
                    tap_code16(KC_MINS);
                }
            }
            return false;
            break;
        case GM_PIPE:
            if (record->event.pressed) {
                tap_code16(KC_PERC);
                if (de_layout_active) {
                    tap_code16(DE_RABK);
                } else {
                    tap_code16(S(KC_DOT));
                }
                tap_code16(KC_PERC);
            }
            return false;
            break;
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
                tap_code(KC_END);
                tap_code(KC_ENT);
            }
            return false;
            break;
        case X_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send CTL-X
                return false;
            }
            return true;
        case C_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(C(KC_INS)); // Intercept hold function to send CTRL-INSERT
                return false;
            }
            return true;
        case V_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(S(KC_INS)); // Intercept hold function to send SHIFT-INSERT
                return false;
            }
            return true;
//      case KANA_K:
//          if (record->tap.count && record->event.pressed) {
//              return true;         // Return true for normal processing of tap keycode
//              break;
//          } else if (record->event.pressed) {
//              tap_code16(A(KC_GRV)); // Switch between Kana and Romaji
//              return false;
//          }
//          return true;
        case UNDO:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(C(KC_Y));
                } else {
                    register_code16(C(KC_Z));
                }
            } else {
                if (de_layout_active) {
                    unregister_code16(C(KC_Y));
                } else {
                    unregister_code16(C(KC_Z));
                }
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(C(KC_Z));
                } else {
                    register_code16(C(KC_Y));
                }
            } else {
                if (de_layout_active) {
                    unregister_code16(C(KC_Z));
                } else {
                    unregister_code16(C(KC_Y));
                }
            }
            return false;
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
        // the next case allows us to use alt_tab without a timer
        case NAVENT:
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
#if thumb == 2
        case LOWER:
#ifdef NAGINATA_ENABLE
            if (naginata_active) {
                return true;
            }
#endif
            if (record->tap.count && record->event.pressed) {
                if (osmod_state & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                } else {
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            } else if (record->event.pressed) {
                return true;
            } else {
                return true;
            }
//      case RAISE:
//          if (naginata_active) {
//              return true;
//          } else {
//              if (record->tap.count && record->event.pressed) {
//                  if (osmod_state & MOD_MASK_SHIFT) {
//                      clear_oneshot_mods();
//                  } else {
//                      set_oneshot_mods(MOD_BIT(KC_RSFT));
//                  }
//                  return false;
//              } else if (record->event.pressed) {
//                  return true;
//              } else {
//                  return true;
//              }
//          }
#endif
        // this esc turns off caps lock, if it was active
        case LT(_NUM, KC_ESC):
        case KC_ESC:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            if (IS_LAYER_ON(_NUM)) {
                layer_off(_NUM);
            }
            return true;
        case RAISE:
            if (record->tap.count && record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            } 
            return true;
        case KC_ENT:
        case ENT_KEY:
        case KC_LEAD:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            return true;

// ------------------------- UNICODE ----------------------------------------- 
#if homerow_mods == 1
        case UMLAUT_SW:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                if (umlaut_enable) {
                    PLAY_SONG(umlaut_off_song);
                } else {
                    PLAY_SONG(umlaut_on_song);
                }
#endif
                umlaut_enable = !umlaut_enable;   
            }
            return false;
            break;
#endif
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

        case DE_SZ: 
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code(DE_SS);
                    layer_off(_LOWER);
                    return false;
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    layer_off(_LOWER);
                    return false;
                    break;
                }
                layer_off(_LOWER);
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code(DE_SS);
                    return false;
                }
            } 

//      case DE_ae:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code(DE_ADIA);
//                  return false;
//              } else {
//                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      clear_oneshot_mods();
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P1);
//                      tap_code(KC_P9);
//                      tap_code(KC_P6);  // Ä
//                  } else {
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P2);
//                      tap_code(KC_P8);  // ä
//                  }
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//                  break;
//              }
//              return true;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_ADIA);
//                  return false;
//              }
//          }
//      case DE_AE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_ADIA));
//                  return false;
//              } else {
//                  clear_oneshot_mods();
//                  clear_mods();
//                  add_mods(MOD_BIT(KC_LALT));
//                  tap_code(KC_P0);
//                  tap_code(KC_P1);
//                  tap_code(KC_P9);
//                  tap_code(KC_P6);  // Ä
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//                  break;
//              }
//              return true;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_ADIA);
//                  return false;
//              }
//          }
#if homerow_mods == 1
        case A_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    if (umlaut_enable) {
                        register_code(DE_ADIA);
                    } else {
                        register_code(KC_A);
                    }
                    return false;
                } else if (!de_layout_active && umlaut_enable) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        clear_oneshot_mods();
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P1);
                        tap_code(KC_P9);
                        tap_code(KC_P6);  // Ä
                    } else {
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P2);
                        tap_code(KC_P8);  // ä
                    }
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                }
                register_code(KC_A);
                return false;
            } else {
                if (de_layout_active && umlaut_enable) {
                    unregister_code(DE_ADIA);
                }
                if (!umlaut_enable) {
                    unregister_code(KC_A);
                }
                return true;
            }
        case O_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    if (umlaut_enable) {
                        register_code(DE_ODIA);
                    } else {
                        register_code(KC_O);
                    }
                    return false;
                } else if (!de_layout_active && umlaut_enable) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        clear_oneshot_mods();
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P1);
                        tap_code(KC_P4);  // Ö
                    } else {
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P4);
                        tap_code(KC_P6);  // ö
                    }
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                }
                register_code(KC_O);
                return false;
            } else {
                if (de_layout_active && umlaut_enable) {
                    unregister_code(DE_ODIA);
                }
                if (!umlaut_enable) {
                    unregister_code(KC_O);
                }
                return true;
            }
#endif
//      case DE_oe:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code(DE_ODIA);
//                  return false;
//              } else {
//                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      clear_oneshot_mods();
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P1);
//                      tap_code(KC_P4);  // Ö
//                  } else {
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P4);
//                      tap_code(KC_P6);  // ö
//                  }
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//                  break;
//              }
//              return true;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_ODIA);
//                  return false;
//              }
//          }

//      case DE_OE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_ODIA));
//                  return false;
//              } else {
//                  clear_oneshot_mods();
//                  clear_mods();
//                  add_mods(MOD_BIT(KC_LALT));
//                  tap_code(KC_P0);
//                  tap_code(KC_P2);
//                  tap_code(KC_P1);
//                  tap_code(KC_P4);  // Ö
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//                  break;
//              }
//              return true;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_ODIA);
//                  return false;
//              }
//          }

        case BSLS_KEY:
            if (record->tap.count && record->event.pressed) {
                // tap
                if (!de_layout_active) { // on the english layout
                    if (!de_en_switched) { // Normal English functionality
                        return true;
                    } else if (de_en_switched) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P2);
                            tap_code(KC_P0);  // Ü
                        } else {
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P5);
                            tap_code(KC_P2);  // ü
                        }
                        unregister_mods(MOD_LALT);
                        set_mods(mod_state);
                        return false;
                    }
                } else if (de_layout_active) {
                    if (!de_en_switched) { // Normal German functionality
                        register_code(DE_UDIA);
                    } else if (de_en_switched) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            register_code16(DE_PIPE);
                        } else {
                            register_code16(DE_BSLS);
                        }
                        set_mods(mod_state);
                    }
                    return false;
                }
            } else if (record->event.pressed) { // long press
                if (de_layout_active) { // german layout
                    if (!de_en_switched) { // normal behaviour, send special characters on long press
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            tap_code16(DE_PIPE);
                        } else {
                            tap_code16(DE_BSLS);
                        }
                        set_mods(mod_state);
#if homerow_mods == 1
                    } else if (umlaut_enable) {
                        tap_code(DE_UDIA);
#endif
                    } else if (de_en_switched) {
                        tap_code16(DE_UNDS);
                    } else {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            register_code16(DE_PIPE);
                        } else {
                            register_code16(DE_BSLS);
                        }
                        set_mods(mod_state);
                    }
                    return false;
                } else if (!de_layout_active) {
                    if (!de_en_switched) {
#if homerow_mods == 1
                        if (umlaut_enable) {
                            if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                                clear_oneshot_mods();
                                clear_mods();
                                add_mods(MOD_BIT(KC_LALT));
                                tap_code(KC_P0);
                                tap_code(KC_P2);
                                tap_code(KC_P2);
                                tap_code(KC_P0);  // Ü
                            } else {
                                clear_mods();
                                add_mods(MOD_BIT(KC_LALT));
                                tap_code(KC_P0);
                                tap_code(KC_P2);
                                tap_code(KC_P5);
                                tap_code(KC_P2);  // ü
                            }
                            unregister_mods(MOD_LALT);
                            set_mods(mod_state);
                            return false;
                        } 
#endif
                        tap_code16(KC_UNDS);
                    } else if (de_en_switched) {
                        tap_code(KC_BSLS);
                    }
                }
                return false;
            } else { // key release
                if (de_layout_active) {
                    if (!de_en_switched) {
                        unregister_code(DE_UDIA);
                    } else if (de_en_switched) {
                        unregister_code16(DE_PIPE);
                        unregister_code16(DE_BSLS);
                    }
                } else if (!de_layout_active) {
                    //unregister_code(KC_BSLS);
                }
                return true;
            }
//      case LT(0, DE_UDIA):
//          if (record->tap.count && record->event.pressed) {
//              // tap
//              if (de_layout_active) {
//                  return true;
//              } else {
//                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      clear_oneshot_mods();
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P2);
//                      tap_code(KC_P0);  // Ü
//                  } else {
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P5);
//                      tap_code(KC_P2);  // ü
//                  }
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//              }
//          } else if (record->event.pressed) {
//              if (de_layout_active) {
//                  tap_code16(DE_ODIA);
//                  return false;
//              } else {
//                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      clear_oneshot_mods();
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P1);
//                      tap_code(KC_P4);  // Ö
//                  } else {
//                      clear_mods();
//                      add_mods(MOD_BIT(KC_LALT));
//                      tap_code(KC_P0);
//                      tap_code(KC_P2);
//                      tap_code(KC_P4);
//                      tap_code(KC_P6);  // ö
//                  }
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//              }
//          } else {
//              return true;
//          }

//        case DE_ue:
//            if (record->event.pressed) {
//                if (de_layout_active) {
//                    register_code(DE_UDIA);
//                    return false;
//                } else if (!win_unicode_enable) {
//                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        clear_oneshot_mods();
//                        clear_mods();
//                        add_mods(MOD_BIT(KC_LALT));
//                        tap_code(KC_P0);
//                        tap_code(KC_P2);
//                        tap_code(KC_P2);
//                        tap_code(KC_P0);  // Ü
//                    } else {
//                        clear_mods();
//                        add_mods(MOD_BIT(KC_LALT));
//                        tap_code(KC_P0);
//                        tap_code(KC_P2);
//                        tap_code(KC_P5);
//                        tap_code(KC_P2);  // ü
//                    }
//                    unregister_mods(MOD_LALT);
//                    set_mods(mod_state);
//                    return false;
//                }  
//                return true;
//            } else {
//                if (de_layout_active) {
//                    unregister_code(DE_UDIA);
//                    return false;
//                }
//            }

//      case DE_UE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_UDIA));
//                  return false;
//              } else {
//                  clear_oneshot_mods();
//                  clear_mods();
//                  add_mods(MOD_BIT(KC_LALT));
//                  tap_code(KC_P0);
//                  tap_code(KC_P2);
//                  tap_code(KC_P2);
//                  tap_code(KC_P0);  // Ü
//                  unregister_mods(MOD_LALT);
//                  set_mods(mod_state);
//                  return false;
//              }
//              return true;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_UDIA);
//                  return false;
//              }
//          }

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
                if (de_layout_active) {
                    register_code(DE_Z);  // Z
                    return false;
                }
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active && !de_en_switched) {
                    tap_code16(DE_SS); // ß
                    return false;
                } else if (de_layout_active && de_en_switched) {
                    register_code(DE_Z);
                    return false;
                } else if (!de_layout_active && de_en_switched) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                } 
                register_code(KC_Z);
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code(DE_Z);
                } else {
                    unregister_code(KC_Z);
                }
                return true;
            }
//      case KC_Z: // Z
//          if (de_layout_active) {
//              if (record->event.pressed) {
//                  register_code(DE_Z);
//              } else {
//                  unregister_code(DE_Z);
//              }
//              return false;
//          } else {
//              return true;
//          }
//      case KC_Y: // Y
//          if (de_layout_active) {
//              if (record->event.pressed) {
//                  register_code(DE_Y);
//              } else {
//                  unregister_code(DE_Y);
//              }
//              return false;
//          } else {
//              return true;
//          }

//      case LT(0, KC_SCLN): // this key behaves as a gui mod tap for both german and english layout
//          if (record->tap.count && record->event.pressed) {
//              if (de_layout_active) {
//                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      register_code16(DE_COLN); // register :
//                  } else {
//                      register_code16(DE_SCLN); // register ;
//                  }
//                  return false;
//              } else {
//                  return true;
//              }
//          } else if (record->event.pressed) {
//              if (de_layout_active) {
//                  tap_code16(DE_COLN); // :
//              } else {
//                  tap_code16(KC_COLN); // :
//              }
//              return false;
//          } else {
//              if (de_layout_active) {
//                  unregister_code16(DE_COLN);
//                  unregister_code16(DE_SCLN);
//                  return false;
//              } else {
//                  return true;
//              }
//          }
//      case KC_EXLM: 
//          if (de_layout_active && caps_lock_on) {
//              if (record->event.pressed) {
//                  register_code(DE_1);
//                  return false;
//              }
//              return true;
//          } else {
//              return true;
//          }
//      case KC_DLR: 
//          if (de_layout_active && caps_lock_on) {
//              if (record->event.pressed) {
//                  register_code(DE_4);
//                  return false;
//              }
//              return true;
//          } else {
//              return true;
//          }
//      case KC_PERC:
//          if (de_layout_active && caps_lock_on) {
//              if (record->event.pressed) {
//                  register_code(DE_5);
//                  return false;
//              }
//              return true;
//          } else {
//              return true;
//          }
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
//                  if (caps_lock_on) {
//                      register_code16(S(DE_HASH));
//                  } else {
                        register_code(DE_HASH);
//                  }
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
//                  if (caps_lock_on) {
//                      register_code(DE_6);
//                  } else {
                        register_code16(DE_AMPR);
//                  }
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
 //                 if (caps_lock_on) {
 //                     register_code(DE_PLUS);
 //                 } else {
                        register_code16(DE_ASTR);
 //                 }
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
//                  if (caps_lock_on) {
//                      register_code(DE_8);
//                  } else {
                        register_code16(DE_LPRN);
//                  }
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
 //                 if (caps_lock_on) {
 //                     register_code(DE_9);
 //                 } else {
                        register_code16(DE_RPRN);
 //                 }
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
        case KC_PLUS: // +
            if (de_layout_active) {
                if (record->event.pressed) {
//                  if (caps_lock_on) {
//                      register_code16(S(DE_PLUS));
//                  } else {
                        register_code16(DE_PLUS);
//                  }
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
        case QUOT_KEY:
            if (record->tap.count && record->event.pressed) {
                // tap
                if (!de_en_switched) {
                    return true;
                } else if (de_en_switched) {
                    if (de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                          if (caps_lock_on) {
//                              clear_oneshot_mods();
//                              clear_mods();
//                              register_code(DE_2); // \"
//                              set_mods(mod_state);
//                          } else {
                                register_code16(DE_DQUO);  // \"
//                          }
                        } else {
//                          if (caps_lock_on) {
//                              register_code(DE_HASH); // \'
//                          } else {
                                register_code16(DE_QUOT);  // /'
//                          }
                        }
                    } else if (!de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P1);
                            tap_code(KC_P9);
                            tap_code(KC_P6);  // Ä
                        } else {
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P2);
                            tap_code(KC_P8);  // ä
                        }
                        unregister_mods(MOD_LALT);
                        set_mods(mod_state);
                    }
                    return false;
                }
                return false;
            } else if (record->event.pressed) { // long press
                if (de_layout_active) {
                    if (!de_en_switched) { // send quotes on long press when in the german layout
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                          if (caps_lock_on) {
//                              clear_oneshot_mods();
//                              clear_mods();
//                              tap_code(KC_2); 
//                              set_mods(mod_state);
//                          } else {
                                tap_code16(DE_DQUO);  // \"
//                          }
                        } else {
 //                         if (caps_lock_on) {
 //                             tap_code(DE_HASH);
 //                         } else {
                                tap_code16(DE_QUOT);  // /'
 //                         }
                        }
#if homerow_mods == 1
                    } else if (umlaut_enable) {
                        tap_code(DE_ADIA);
#endif
                    } else if (de_en_switched) { // send minus in german layout on long-press, when de_en_switched
                        tap_code(DE_MINS);
                    }
                    return false;
                } else if (!de_layout_active) { // in the English layout
                    if (!de_en_switched) { // normal processing
#if homerow_mods == 1
                        if (umlaut_enable) {
                            if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                                clear_oneshot_mods();
                                clear_mods();
                                add_mods(MOD_BIT(KC_LALT));
                                tap_code(KC_P0);
                                tap_code(KC_P1);
                                tap_code(KC_P9);
                                tap_code(KC_P6);  // Ä
                            } else {
                                clear_mods();
                                add_mods(MOD_BIT(KC_LALT));
                                tap_code(KC_P0);
                                tap_code(KC_P2);
                                tap_code(KC_P2);
                                tap_code(KC_P8);  // ä
                            }
                            unregister_mods(MOD_LALT);
                            set_mods(mod_state);
                            return false ;
                        }
#endif
                        tap_code(KC_MINS); // send minus on long_press
                    } else if (de_en_switched) { 
                        tap_code(KC_QUOT); // otherwise send quotes when de_en_switched
                    }
                return false;
                }
            } else { // key release
                if (de_layout_active) {
                    if (!de_en_switched) {
                        unregister_mods(DE_ADIA);
                    } else if (de_en_switched) {
//                      if (caps_lock_on) {
//                          unregister_code(KC_2);
//                          unregister_code(DE_HASH);
//                      }
                        unregister_code16(DE_QUOT);
                        unregister_code16(DE_DQUO);
                    }
                } else if (!de_layout_active) {
                    //unregister_code(KC_QUOT);
                }
                return true;
            }

          case KC_QUOT:
              if (de_layout_active) {
                  if (record->event.pressed) {
                      if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        if (caps_lock_on) {
//                            clear_oneshot_mods();
//                            clear_mods();
//                            register_code(DE_2); // \"
//                            set_mods(mod_state);
//                        } else {
                              register_code16(DE_DQUO);  // \"
//                        } 
                      } else {
 //                       if (caps_lock_on) {
 //                           clear_mods();
 //                           register_code(DE_HASH); // \'
 //                       } else {
                              register_code16(DE_QUOT);  // /'
 //                       }
                      }
                  } else {
//                    if (caps_lock_on) {
//                        unregister_code(KC_2);
//                        unregister_code(DE_HASH);
//                    }
                      unregister_code16(DE_DQUO);
                      unregister_code16(DE_QUOT);
                  }
                  return false;
              } else {
                  return true;
              }
        case DOT_KEY:
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_RABK);  // > right angle bracket 
//                  } else if (caps_lock_on) {
//                      register_code16(S(KC_DOT));
                    } else {
                        return true;
                    }
                    return false;
                }
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active) {
//                  if (caps_lock_on) {
//                      tap_code16(S(DE_COLN));
//                  } else {
                        tap_code16(DE_COLN);
//                  }
                } else {
                    tap_code16(KC_COLN);
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_RABK);
                    unregister_code(KC_DOT);
                }
                return true;
            }
//        case KC_DOT:
//            if (de_layout_active) {
//                if (record->event.pressed) {
//                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        register_code16(DE_RABK);  // > right angle bracket 
//                    } else {
//                        register_code16(DE_DOT);  // .
//                    }
//                } else {
//                    unregister_code16(DE_RABK);
//                    unregister_code16(DE_DOT);
//                }
//                return false;
//            } else {
//                return true;
//            }
        case COMM_KEY:
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        clear_mods();
                        clear_oneshot_mods();
                        register_code16(DE_LABK);  // < left angle bracket when shifted
                        set_mods(mod_state);
//                  } else if (caps_lock_on) {
//                      register_code16(S(KC_COMM));
                    } else {
                        return true;
                    }
                    return false;
                }
                return true;
            } else if (record->event.pressed) { // add semicolon as a held key
                if (de_layout_active) {
//                  if (caps_lock_on) {
//                      tap_code16(S(DE_SCLN));
//                  } else {
                        tap_code16(DE_SCLN);
//                  }
                } else {
                    tap_code16(KC_SCLN);
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_LABK);
                    unregister_code(KC_COMM);
                    return false;
                }
                return true;
            }
//      case LT(0, KC_MINS):
//          if (record->tap.count && record->event.pressed) {
//              if (de_layout_active) {
//                  register_code(DE_MINS);  // - Bindestrich 
//                  return false;
//              }
//              return true;
//          } else if (record->event.pressed) { // add underscore as a shifted key
//              if (de_layout_active) {
//                  tap_code16(DE_UNDS);
//              } else {
//                  tap_code16(KC_UNDS);
//              }
//              return false;
//          } else {
//              if (de_layout_active) {
//                  unregister_code(DE_MINS);
//                  return false;
//              }
//              return true;
//          }
//        case KC_COMM:
//            if (de_layout_active) {
//                if (record->event.pressed) {
//                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        clear_mods();
//                        clear_oneshot_mods();
//                        register_code16(DE_LABK);  // < left angle bracket
//                        set_mods(mod_state);
//                    } else {
//                        register_code16(DE_COMM);  // ,
//                    }
//                } else {
//                    unregister_code16(DE_LABK);
//                    unregister_code16(DE_COMM);
//                }
//                return false;
//            } else {
//                return true;
//            }
        case S(KC_COMM): // <
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
        case S(KC_DOT): // >
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
        case S(KC_QUOT): // "
            if (de_layout_active) {
                if (record->event.pressed) {
//                  if (caps_lock_on) {
//                      clear_oneshot_mods();
//                      clear_mods();
//                      register_code(DE_2); // \"
//                      set_mods(mod_state);
//                  } else {
                        register_code16(DE_DQUO);
//                  }
                } else {
 //                 if (caps_lock_on) {
 //                     unregister_code(KC_2);
 //                 } else {
                        unregister_code16(DE_DQUO);
 //                 }
                }
                return false;
            } else {
                return true;
            }
        case SLSH_KEY: 
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      if (caps_lock_on) { 
//                          register_code(DE_SS); // register ?
//                      } else {
                            register_code16(DE_QUES); // register ?
//                      }
                    } else {
//                      if (caps_lock_on) { 
//                          register_code(DE_7); // register /
//                      } else {
                            register_code16(DE_SLSH); // register /
//                      }
                    }
                    return false;
                } // process the key normally when English layout is active
                    return true;
            } else if (record->event.pressed) { // register ? on hold
                if (de_layout_active) {
//                  if (caps_lock_on) { 
//                      tap_code(DE_SS); // register ?
//                  } else {
                        tap_code16(DE_QUES); // register ?
//                  }
                } else { // ?
                    tap_code16(KC_QUES);
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_QUES); // release ?
                    unregister_code16(DE_SLSH); // release /
                    return false;
                }
                return true;
            }
        case KC_SLSH:
            if (de_layout_active) {
                if (record->event.pressed) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                      if (caps_lock_on) {
//                          register_code(DE_SS);
//                      } else {
                            register_code16(DE_QUES); // register ?
//                      }
                    } else {
//                      if (caps_lock_on) {
//                          register_code(DE_7); // register /
//                      } else {
                            register_code16(DE_SLSH); // register /
//                      }
                    }
                    return false;
                } else {
                    unregister_code16(DE_QUES); // release ?
                    unregister_code16(DE_SLSH); // release /
                    return false;
                }
            } else { //process the key normally when the English layout is active
                return true;
            }
        case KC_NUBS: // "\"
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
//                  if (caps_lock_on) {
//                      register_code16(DE_0);
//                  } else {
                        register_code16(DE_EQL);
//                  } 
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

// ------------------------- TOP ROW NUMBERS ---------------------------------
#if homerow_mods == 2

        case Q_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_1);
                return false;
            }
            return true;
        case W_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_2);
                return false;
            }
            return true;
        case F_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_3);
                return false;
            }
            return true;
        case P_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_4);
                return false;
            }
            return true;
        case B_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_5);
                return false;
            }
            return true;
        case J_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_6);
                return false;
            }
            return true;
        case L_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_7);
                return false;
            }
            return true;
        case U_KEY:
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code(KC_8);
                return false;
            }
            return true;
        case Y_KEY:
            if (de_layout_active) {
                if (record->tap.count && record->event.pressed) {
                    register_code(DE_Y); // tap Y
                    return false;
                } else if (record->event.pressed) {
                } else {
                    unregister_code(DE_Y);
                    return false;
                }
            } else {
                if (record->tap.count && record->event.pressed) {
                    return true;
                } 
            }
            if (record->event.pressed) {
                tap_code(KC_9);
                return false;
            }
            return true;
        case SCLN_KEY:
            if (record->tap.count && record->event.pressed) {
                if (!de_en_switched) {
                    return true;
                } else if (de_en_switched) {
                    if (de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            register_code16(DE_COLN); // register :
                        } else {
                            register_code16(DE_SCLN); // register ;
                        }
                    } else if (!de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P1);
                            tap_code(KC_P4);  // Ö
                        } else {
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P4);
                            tap_code(KC_P6);  // ö
                        }
                        unregister_mods(MOD_LALT);
                        set_mods(mod_state);
                    }
                    return false;
                }
            } else if (record->event.pressed) {
                tap_code(KC_0);
                return false;
            } else {
                if (de_en_switched && de_layout_active) {
                    unregister_code16(DE_COLN);
                    unregister_code16(DE_SCLN);
                }
                return true;
            }
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
                if (de_layout_active) {
                    tap_code16(DE_TILD);
                } else {
                    tap_code16(KC_TILD);
                }
                return false;
            } else {
            }
            return true;
#ifndef ACHORDION

// ------------------------- IMPROVED ROLLS ON THE HOMEROW ------------------- {{{
            // roll compensation for the homerow modifiers
        case LCTL_T(KC_CAPS):
            if (record->tap.count && record->event.pressed) {
            } else if (record->event.pressed){
                ctl_pressed = true;
            } else {
                ctl_pressed = false;
            }
            return true;
        case OSM(MOD_LSFT):
            if (record->tap.count && record->event.pressed) {
            } else if (record->event.pressed){
                sft_pressed = true;
            } else {
                sft_pressed = false;
            }
            return true;
        case RSFT_T(KC_ENT):
            if (record->tap.count && record->event.pressed) {
                if (caps_lock_on) {
                    tap_code(KC_CAPS);
                }
            } else if (record->event.pressed){
                sft_pressed = true;
            } else {
                sft_pressed = false;
            }
            return true;
        case KC_LGUI:
            if (record->event.pressed) {
                gui_pressed = true;
            } else {
                gui_pressed = false;
            }
            return true;
        case KC_LALT:
            if (record->event.pressed) {
                alt_pressed = true;
            } else {
                alt_pressed = false;
            }
            return true;

        case A_KEY: 
            if (record->tap.count && record->event.pressed) {
            } else if (record->event.pressed) {
                lgui_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                lgui_held = false;
                if (!gui_pressed) { // check whether the non-homerow gui key is also held
                    unregister_mods(MOD_BIT(KC_LGUI));
                }
                // if no other key was pressed in the meantime
                // send a tap of the modifier (to open windows
                // startmenu or alt menu, etc.)
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_LGUI);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case R_KEY: // nullifies the effect of lgui when rolling from a to r
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_LGUI)) { */
                /*     if (!gui_pressed) { */
                /*         del_mods(MOD_BIT(KC_LGUI)); */
                /*         tap_code(KC_A); */
                /*         tap_code(KC_R); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                lalt_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                lalt_held = false;
                if (!alt_pressed && !ralt_held) { // check whether the non-homerow alt is also held
                    unregister_mods(MOD_BIT(KC_LALT));
                }
                // if no other key was pressed in the meantime
                // send a tap of the modifier (to open windows
                // startmenu or alt menu, etc.)
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_LALT);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case S_KEY: // nullifies the effect of lalt when rolling from R to S
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_LALT)) { */
                /*     if (!alt_pressed) { */
                /*         del_mods(MOD_BIT(KC_LALT)); */
                /*         tap_code(KC_R); */
                /*         tap_code(KC_S); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                lsft_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                lsft_held = false;
                if (!sft_pressed) { // check whether the non-homerow shift is also held
                    unregister_mods(MOD_BIT(KC_LSFT));
                }
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_LSFT);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case T_KEY: // nullifies the effect of lsft when rolling from s to t
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_LSFT)) { */
                /*     if (!sft_pressed) { */
                /*         del_mods(MOD_BIT(KC_LSFT)); */
                /*         tap_code(KC_S); */
                /*         tap_code(KC_T); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
                /* if (mod_state & MOD_BIT(KC_LALT)) { */
                /*     if (!alt_pressed) { */
                /*         del_mods(MOD_BIT(KC_LALT)); */
                /*         tap_code(KC_R); */
                /*         tap_code(KC_T); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                lctl_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                lctl_held = false;
                if (!ctl_pressed) { // check whether the non-homerow ctrl is also held
                    unregister_mods(MOD_BIT(KC_LCTL));
                }
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_LCTL);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case N_KEY: // nullifies the effect of rsft when rolling from e to n
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_RSFT)) { */
                /*     if (!sft_pressed) { */
                /*         del_mods(MOD_BIT(KC_RSFT)); */
                /*         tap_code(KC_E); */
                /*         tap_code(KC_N); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
                /* if (mod_state & MOD_BIT(KC_RALT)) { */
                /*     if (!alt_pressed) { */
                /*         del_mods(MOD_BIT(KC_RALT)); */
                /*         tap_code(KC_I); */
                /*         tap_code(KC_N); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
                /* if (mod_state & MOD_BIT(KC_RGUI)) { */
                /*     if (!gui_pressed) { */
                /*         del_mods(MOD_BIT(KC_RGUI)); */
                /*         tap_code(KC_O); */
                /*         tap_code(KC_N); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                rctl_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                rctl_held = false;
                unregister_mods(MOD_BIT(KC_RCTL));
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_RCTL);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case E_KEY: // nullifies the effect of alt when rolling from i to e, and the effect from ctrl when rolling from n to e
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_RCTL)) { */
                /*     if (!ctl_pressed) { */
                /*         del_mods(MOD_BIT(KC_RCTL)); */
                /*         tap_code(KC_N); */
                /*         tap_code(KC_E); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */ 
                /*     } */
                /* } */
                /* if (mod_state & MOD_BIT(KC_RALT)) { */
                /*     if (!alt_pressed) { */
                /*         del_mods(MOD_BIT(KC_RALT)); */
                /*         tap_code(KC_I); */
                /*         tap_code(KC_E); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                rsft_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                rsft_held = false;
                unregister_mods(MOD_BIT(KC_RSFT));
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_RSFT);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case I_KEY: // nullifies the effect of rsft when rolling from e to i
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_RSFT)) { */
                /*     if (!sft_pressed) { */
                /*         del_mods(MOD_BIT(KC_RSFT)); */
                /*         tap_code(KC_E); */
                /*         tap_code(KC_I); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
                /* if (mod_state & MOD_BIT(KC_RGUI)) { */
                /*     if (!gui_pressed) { */
                /*         del_mods(MOD_BIT(KC_RGUI)); */
                /*         tap_code(KC_O); */
                /*         tap_code(KC_I); */
                /*         // restore the mod state */
                /*         //add_mods(MOD_BIT(KC_RSFT)); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                ralt_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                ralt_held = false;
                if (!alt_pressed && !lalt_held) { // only unregister when the non-homerow mod is not held
                    unregister_mods(MOD_BIT(KC_LALT));
                }
                // if no other key was pressed in the meantime
                // send a tap of the modifier (to open windows
                // startmenu or alt menu, etc.)
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_RALT);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
        case O_KEY:
            if (record->tap.count && record->event.pressed) {
                /* if (mod_state & MOD_BIT(KC_RALT)) { */
                /*     if (!alt_pressed) { */
                /*         del_mods(MOD_BIT(KC_RALT)); */
                /*         tap_code(KC_I); */
                /*         tap_code(KC_O); */
                /*         //restore the mod state */
                /*         //set_mods(mod_state); */
                /*         return false; */
                /*     } */
                /* } */
            } else if (record->event.pressed) {
                rgui_held = true;
                modifier_solo_activation = true;
                return false;
            } else {
                rgui_held = false;
                unregister_mods(MOD_BIT(KC_RGUI));
                // if no other key was pressed in the meantime
                // send a tap of the modifier (to open windows
                // startmenu or alt menu, etc.)
#ifdef MODIFIER_SOLO_ACTIVATION
                if (modifier_solo_activation) {
                    tap_code(KC_RGUI);
                    modifier_solo_activation = false;
                }
#endif
            }
            return true;
// }}}
#endif

#elif homerow_mods == 1
// ------------------------- NUMBERS CAPS IMMUNITY----------------------------
//      case KC_0:
//      case KC_1:
//      case KC_2:
//      case KC_3:
//      case KC_4:
//      case KC_5:
//      case KC_6:
//      case KC_7:
//      case KC_8:
//      case KC_9:
//          if (record->event.pressed) {
//              if (de_layout_active && caps_lock_on) {
//                  register_code16(S(keycode));
//                  return false;
//              } else {
//                  return true;
//              }
//          } else {
//              return true;
//          }
// ------------------------- NUMBERS AUTOSHIFT -------------------------------
//      case LT(0, KC_1): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_EXLM);
//              return false;
//          }
//          return true;
//      case LT(0, KC_2): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_AT);
//              return false;
//          }
//          return true;
//      case LT(0, KC_3): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_HASH);
//              return false;
//          }
//          return true;
//      case LT(0, KC_4): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_DLR);
//              return false;
//          }
//          return true;
//      case LT(0, KC_5): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_PERC);
//              return false;
//          }
//          return true;
//      case LT(0, KC_6): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_CIRC);
//              return false;
//          }
//          return true;
//      case LT(0, KC_7): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_AMPR);
//              return false;
//          }
//          return true;
//      case LT(0, KC_8): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_ASTR);
//              return false;
//          }
//          return true;
//      case LT(0, KC_9): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_LPRN);
//              return false;
//          }
//          return true;
//      case LT(0, KC_0): 
//          if (record->tap.count && record->event.pressed) {
//              return true;
//          } else if (record->event.pressed) {
//              tap_code16(KC_RPRN);
//              return false;
//          }
//          return true;
          
// ------------------------- MOD-/LAYER-TAPS ---------------------------------
        case LALT_T(KC_Y):
            if (de_layout_active) {
                if (record->tap.count && record->event.pressed) {
                    register_code(DE_Y); // tap Y
                    return false;
                } else if (record->event.pressed) {
                    return true;
                } else {
                    unregister_code(DE_Y);
                    return true;
                }
            } else {
                return true;
            }

        case RGUI_T(KC_SCLN): // this key behaves as a gui mod tap for both german and english layout
            if (record->tap.count && record->event.pressed) {
                if (!de_en_switched) {
                    return true;
                } else if (de_en_switched) {
                    if (de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            register_code16(DE_COLN); // register :
                        } else {
                            register_code16(DE_SCLN); // register ;
                        }
                    } else if (!de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            clear_oneshot_mods();
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P1);
                            tap_code(KC_P4);  // Ö
                        } else {
                            clear_mods();
                            add_mods(MOD_BIT(KC_LALT));
                            tap_code(KC_P0);
                            tap_code(KC_P2);
                            tap_code(KC_P4);
                            tap_code(KC_P6);  // ö
                        }
                        unregister_mods(MOD_LALT);
                        set_mods(mod_state);
                    }
                    return false;
                }
            } else if (record->event.pressed) {
                return true;
            } else {
                if (de_en_switched && de_layout_active) {
                    unregister_code16(DE_COLN);
                    unregister_code16(DE_SCLN);
                }
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

