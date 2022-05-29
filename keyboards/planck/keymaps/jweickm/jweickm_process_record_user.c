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
        case LTHUMB_KEY:
        case BS_KEY:
        case DEL_KEY:
        case LOWER: 
        case RAISE:
            return TAPPING_TERM * thumb_factor;
        case NAVSPACE:
            return TAPPING_TERM * (thumb_factor + 0.1);

        // index finger keys
        /* case TD(TD_BSPC): */
        /* case TD(TD_DEL): */
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
        case OSM(MOD_RSFT):
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
        case TD(TD_LARROW):
        case TD(TD_RARROW):
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

    // for the ACHORDION functionality
    if (!process_achordion(keycode, record)) { return false; }
    mod_state = get_mods();
    osmod_state = get_oneshot_mods();
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
            }
            return false;

// ------------------------------- ACTION COMBOS --------------------
        case UMLAUT_RALT:
            if (record->event.pressed) {
                tap_code16(KC_RALT);
                SEND_SPECIAL('"');
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
        case X_KEY:
            return process_tap_long_press_key(record, C(KC_X));
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true;         // Return true for normal processing of tap keycode */
            /*     break; */
            /* } else if (record->event.pressed) { */
            /*     tap_code16(C(KC_X)); // Intercept hold function to send CTL-X */
            /*     return false; */
            /* } */
            /* return true; */
        case C_KEY:
            return process_tap_long_press_key(record, C(KC_INS));
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true;         // Return true for normal processing of tap keycode */
            /*     break; */
            /* } else if (record->event.pressed) { */
            /*     tap_code16(C(KC_INS)); // Intercept hold function to send CTRL-INSERT */
            /*     return false; */
            /* } */
            /* return true; */
        case V_KEY:
            return process_tap_long_press_key(record, S(KC_INS));
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true;         // Return true for normal processing of tap keycode */
            /*     break; */
            /* } else if (record->event.pressed) { */
            /*     tap_code16(S(KC_INS)); // Intercept hold function to send SHIFT-INSERT */
            /*     return false; */
            /* } */
            /* return true; */
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
            if (!record->event.pressed && (is_alt_tab_active || is_ctl_tab_active)) {
                del_mods(MOD_BIT(KC_LALT));
                del_mods(MOD_BIT(KC_LCTL));
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
            }
            return true;
/* #ifdef NAGINATA_ENABLE */
/*             if (naginata_active) { */
/*                 return true; */
/*             } */
/* #endif */
/*             if (record->tap.count && record->event.pressed) { */
/*                 if (osmod_state & MOD_MASK_SHIFT) { */
/*                     clear_oneshot_mods(); */
/*                 } else { */
/*                     set_oneshot_mods(MOD_BIT(KC_LSFT)); */
/*                 } */
/*                 return false; */
/*             } */
/*             return true; */
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
        /* case RAISE: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*         if (osmod_state & MOD_MASK_SHIFT) { */
        /*             clear_oneshot_mods(); */
        /*         } else { */
        /*             set_oneshot_mods(MOD_BIT(KC_RSFT)); */
        /*         } */
        /*         return false; */
        /*     } */
        /*     return true; */
            /* if (record->tap.count && record->event.pressed && caps_lock_on) { */
            /*     tap_code(KC_CAPS); */
            /* } */ 
            /* return true; */
        case KC_ENT:
        case ENT_KEY:
        case KC_LEAD:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            return true;

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

        case DE_SZ: 
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code(DE_SS);
                    layer_off(_LOWER);
                    return false;
                } else {
                    SEND_UMLAUT('s'); // ß
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

        case BSLS_KEY:
            if (record->tap.count && record->event.pressed) {
                // tap
                if (!de_layout_active) { // on the english layout
                    if (!de_en_switched) { // Normal English functionality
                        return true;
                    } else if (de_en_switched) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            SEND_UMLAUT('U');
                        } else {
                            SEND_UMLAUT('u');
                        }
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
                        tap_code(KC_PSCR); // print screen
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

            // make a rule so that we can output shifted umlauts from the SPECIAL layer
        case OSM(MOD_LSFT):
            if (record->tap.count && record->event.pressed) {
            } else if (record->event.pressed) {
                if (IS_LAYER_ON(_UMLAUTS)) {
                    set_oneshot_layer(_UMLAUTS, ONESHOT_START);
                }
            } else {
                if (IS_LAYER_ON(_UMLAUTS)) {
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                }
            }
            return true;
    case DE_AE:
        if (record->event.pressed) {
            if (de_layout_active) {
                register_code(DE_ADIA);
                return false;
            } else {
                if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                    SEND_UMLAUT('A'); // Ä
                } else {
                    SEND_UMLAUT('a'); // ä
                }
                set_mods(mod_state);
                return false;
            }
            return true;
        } else {
            if (de_layout_active) {
                unregister_code(DE_ADIA);
                return false;
            }
        }
//      case DE_AE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_ADIA));
//                  return false;
//              } else {
//                  SEND_UMLAUT('A'); // Ä
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
        case DE_UE:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code(DE_UDIA);
                    return false;
                } else {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        SEND_UMLAUT('U'); // Ü
                    } else {
                        SEND_UMLAUT('u'); // ü
                    }
                    set_mods(mod_state);
                    return false;
                }  
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code(DE_UDIA);
                    return false;
                }
            }

//      case DE_UE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_UDIA));
//                  return false;
//              } else {
//                  SEND_UMLAUT('U'); // Ü
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

      case DE_OE:
          if (record->event.pressed) {
              if (de_layout_active) {
                  register_code(DE_ODIA);
                  return false;
              } else {
                  if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                      SEND_UMLAUT('O'); // Ö
                  } else {
                      SEND_UMLAUT('o'); // ö
                  }
                  set_mods(mod_state);
                  return false;
              }
              return true;
          } else {
              if (de_layout_active) {
                  unregister_code(DE_ODIA);
                  return false;
              }
          }

//      case DE_OE:
//          if (record->event.pressed) {
//              if (de_layout_active) {
//                  register_code16(S(DE_ODIA));
//                  return false;
//              } else {
//                  SEND_UMLAUT('O'); // Ö
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
                /* if (de_layout_active && !de_en_switched) { */
                if (de_layout_active) {
                    tap_code16(DE_SS); // ß
                    return false;
                /* } else if (de_layout_active && de_en_switched) { */
                /*     register_code(DE_Z); */
                /*     return false; */
                } else if (!de_layout_active) {
                /* } else if (!de_layout_active && de_en_switched) { */
                    SEND_UMLAUT('s'); // ß
                    set_mods(mod_state);
                    return false;
                } 
                /* register_code(KC_Z); */
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
                            register_code16(DE_DQUO);  // \"
                        } else {
                            register_code16(DE_QUOT);  // /'
                        }
                    } else if (!de_layout_active) {
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            SEND_UMLAUT('A'); // Ä
                        } else {
                            SEND_UMLAUT('a'); // ä
                        }
                        set_mods(mod_state);
                    }
                    return false;
                }
                return false;
            } else if (record->event.pressed) { // long press
                if (de_layout_active) {
                    if (!de_en_switched) { // send quotes on long press when in the german layout
                        if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                            tap_code16(DE_DQUO);  // \"
                        } else {
                            tap_code16(DE_QUOT);  // /'
                        }
                    } else if (de_en_switched) { // send minus in german layout on long-press, when de_en_switched
                        tap_code(DE_MINS);
                    }
                    return false;
                } else if (!de_layout_active) { // in the English layout
                    if (!de_en_switched) { // normal processing
                        tap_code16(KC_UNDS); // send minus on long_press
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
                        unregister_code16(DE_QUOT);
                        unregister_code16(DE_DQUO);
                    }
                } else if (!de_layout_active) {
                }
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
        case DOT_KEY:
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_RABK);  // > right angle bracket 
                    } else {
                        return true;
                    }
                    return false;
                }
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active) {
                        tap_code16(DE_COLN);
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
        /* case M_KEY: */
        /*     if (record->tap.count && record->event.pressed) { */
        /*     } else if (record->event.pressed) { // send '-' on long press */
        /*         SEND_SPECIAL('-'); */
        /*         return false; */
        /*     } */
        /*     return true; */
        case COMM_KEY:
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        clear_mods();
                        clear_oneshot_mods();
                        register_code16(DE_LABK);  // < left angle bracket when shifted
                        set_mods(mod_state);
                    } else {
                        return true;
                    }
                    return false;
                }
                return true;
            } else if (record->event.pressed) { // add semicolon as a held key
                if (de_layout_active) {
                        tap_code16(DE_SCLN);
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
                        register_code16(DE_DQUO);
                } else {
                        unregister_code16(DE_DQUO);
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
            } else if (record->event.pressed) { // register - on hold
                if (de_layout_active) {
//                  if (caps_lock_on) { 
//                      tap_code(DE_SS); // register ?
//                  } else {
                        tap_code(DE_MINS); // register ?
//                  }
                } else { // ?
                    tap_code(KC_MINS);
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
        case Q_KEY:
            return process_tap_long_press_key(record, KC_1);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_1); */
            /*     return false; */
            /* } */
            /* return true; */
        case W_KEY:
            return process_tap_long_press_key(record, KC_2);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_2); */
            /*     return false; */
            /* } */
            /* return true; */
        case F_KEY:
            return process_tap_long_press_key(record, KC_3);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_3); */
            /*     return false; */
            /* } */
            /* return true; */
        case P_KEY:
            return process_tap_long_press_key(record, KC_4);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_4); */
            /*     return false; */
            /* } */
            /* return true; */
        case B_KEY:
            return process_tap_long_press_key(record, KC_5);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_5); */
            /*     return false; */
            /* } */
            /* return true; */
        case J_KEY:
            return process_tap_long_press_key(record, KC_6);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_6); */
            /*     return false; */
            /* } */
            /* return true; */
        case L_KEY:
            return process_tap_long_press_key(record, KC_7);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_7); */
            /*     return false; */
            /* } */
            /* return true; */
        case U_KEY:
            return process_tap_long_press_key(record, KC_8);
            /* if (record->tap.count && record->event.pressed) { */
            /*     return true; */
            /* } else if (record->event.pressed) { */
            /*     tap_code(KC_8); */
            /*     return false; */
            /* } */
            /* return true; */
        case Y_KEY:
            if (de_layout_active) {
                if (record->tap.count && record->event.pressed) {
                    register_code(DE_Y); // tapping Y
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
                            SEND_UMLAUT('O'); // Ö
                        } else {
                            SEND_UMLAUT('o'); // ö
                        }
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
                tap_code16(KC_APP); // press menu button on hold
                return false;
            } else {
            }
            return true;

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
