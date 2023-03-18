// declaring several logical variables
bool is_alt_tab_active  = false;

// initialize the mod_state and the osmod_state variables
uint8_t mod_state;
uint8_t osmod_state;
bool shifted;
bool key_tapped;
bool dualf_is_off;

#ifdef THUMB_SHIFT
bool toggle_osm_shift(keyrecord_t* record) {
    if (key_tapped) {
        if (osmod_state & MOD_MASK_SHIFT) {
            clear_oneshot_mods();
        } else {
            set_oneshot_mods(MOD_BIT(KC_LSFT));
        }
        return false;
    }
    return true;
}
#endif

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
            clear_mods();
            clear_oneshot_mods();
            register_code16(shifted_keycode);
            set_mods(mod_state);
        } else {
            register_code16(keycode);
        }
    } else {
        unregister_code16(keycode);
        unregister_code16(shifted_keycode);
    }
#ifdef CAPS_WORD_ENABLE
    caps_word_off(); // break caps_word
#endif
    return false;
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
            if (shifted || caps_lock_on) {
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
            if (shifted || caps_lock_on) {
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
            tap_code(KC_P8);  // €
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
    return processed;
}

bool process_winc(uint16_t keycode) {
//  function to process the unicode characters using wincompose
    bool processed = false;
    tap_code(KC_RALT);
    switch (keycode) {
        case DE_ADIA:
            tap_code16(KC_DQUO);
            if (shifted || caps_lock_on) {
                tap_code16(S(KC_A)); // Ä
            } else {
                tap_code(KC_A); // ä
            }
            processed = true;
            break;
        case DE_UDIA:
            tap_code16(KC_DQUO);
            if (shifted || caps_lock_on) {
                tap_code16(S(KC_U)); // Ü
            } else {
                tap_code(KC_U); // ü
            }
            processed = true;
            break;
        case DE_SCLN:
        case DE_ODIA:
            tap_code16(KC_DQUO);
            if (shifted || caps_lock_on) {
                tap_code16(S(KC_O)); // Ö
            } else {
                tap_code(KC_O); // ö
            }
            processed = true;
            break;
        case DE_EURO:
            tap_code(KC_EQL);
            tap_code(KC_E); // €
            processed = true;
            break;
        case SZ_KEY:
            tap_code(KC_S);
            tap_code(KC_S); // ß
            processed = true;
            break;
        case KC_DEG:
            tap_code(KC_O);
            tap_code(KC_O);
            processed = true;
            break;
        default:
            processed = false;
            break;
    }
    return processed;
}

// define custom function for processing special characters
bool process_german_keycode(keyrecord_t* record, uint16_t keycode) {
    bool processed = false;
    if (record->event.pressed && !(IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_LOWER))) {
        if (de_layout_active) {
            return true;
        }
        turn_num_lock_on();
        clear_mods();
        clear_oneshot_mods();
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
    [TD_LPRN]    = ACTION_TAP_DANCE_FN(dance_lprn),
    [TD_LBRC]    = ACTION_TAP_DANCE_FN(dance_lbrc),
    [TD_LCBR]    = ACTION_TAP_DANCE_FN(dance_lcbr),
    [TD_LABK]    = ACTION_TAP_DANCE_FN(dance_labk),
};
#endif

// ===================================================

float thumb_factor  = 1.05;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
#ifdef TAP_DANCE_ENABLE
float td_factor     = 1.10; // used to be 1.20
#endif

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case BS_KEY:
        case DEL_KEY:
        case LOWER:
        case LOWER_DE:
        case RAISE:
        case RAISE_DE:
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
        case NUM_2:
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case W_KEY:
        case R_KEY:
        case X_KEY:
        case Y_KEY:
        case Y_KEY_DE:
        case I_KEY:
        case DOT_KEY:
        case NUM_3:
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
        case CAPS_KEY:
        case OSM(MOD_LSFT):
        case OSM(MOD_RSFT):
        case ENT_KEY:
        case BSLS_KEY:
        case UE_KEY:
        case QUOT_KEY:
        case TAB_KEY:
            return TAPPING_TERM; // prefer these ones to be shorter

        // tap dance actions
#ifdef TAP_DANCE_ENABLE
        case TD(TD_LPRN):
        case TD(TD_LBRC):
        case TD(TD_LCBR):
        case TD(TD_LABK):
            return TAPPING_TERM * td_factor;
#endif

        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_KEY:
        case E_KEY:
        case LOWER:
        case LOWER_DE:
        case RAISE:
        case RAISE_DE:
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

// ===================== CAPS WORD ================================
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case DE_UDIA: // DE_UDIA
        case DE_ADIA:
        case DE_ODIA:
            if (!de_layout_active) {
                return false;
            }
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_MINS:
        case KC_UNDS:
            if (de_layout_active) {
                return false;
            } else {
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
            return true;

        default:
            if (shifted) {
                return true;
            }
            return false;  // Deactivate Caps Word.
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
    } else if (layer_state_is(_NUM)) {
        switch (combo_index) {
            case HCOMM_ENT:
            case COMMDOT_CPSWRD:
            case HDOT_RALT:
            case EDOT_BSPC:
            case NRAISE:
            case ERAISE:
            case RAISECOMM_TAB:
            case RSE_H_NUM: // combo to disable num_layer
                return false;
            default:
                return true; // keep the combos activated for these layers
        }
    } else {
        return true;
    }
}

// ===================== ACHORDION ================================

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
        case TAB_KEY:
        case NAVSPACE:
        case LOWER:
        case RAISE:
        case LOWER_DE:
        case RAISE_DE:
        case DEL_KEY:
        case BS_KEY:
        case CAPS_KEY:
        case OSM(MOD_LSFT):
        case OSM(MOD_RSFT):
        case ESC_KEY:
        case DOWN_KEY:
        case UP_KEY:
        case ENT_KEY:
        case Z_KEY_DE:
        case KC_LCTL:
        case KC_LALT:
        case KC_LGUI:
            return 0; // bypass Achordion for these keys
        case Z_KEY:
        case COMM_KEY:
        case DOT_KEY:
        case SLSH_KEY:
        case SCLN_KEY:
        case BSLS_KEY:
        case UE_KEY:
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
        case NUM_2:
        case NUM_3:
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

// Helper for implementing taps and long-press keys. Given a tap-hold key event,
// replaces the hold function with `long_press_keycode`.
static bool process_tap_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
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

// =================================================================
// +++++++++++++++++++ PROCESS RECORD USER +++++++++++++++++++++++++
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();
    osmod_state = get_oneshot_mods();
    shifted = (mod_state & MOD_MASK_SHIFT) || (osmod_state & MOD_MASK_SHIFT);
    key_tapped = record->event.pressed && record->tap.count;

    // for the ACHORDION functionality
    if (!dualf_is_off) {
        if (!process_achordion(keycode, record)) { return false; }
    }
    // for the LAYER_LOCK feature
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

    // make sure that num_lock is turned on, when on the _NUM layer
    if (IS_LAYER_ON(_NUM)) {
        turn_num_lock_on();
    }

    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        case KB_LANG_SWITCH: // TG(_COLEMAK_DE): switches only kb lang
            if (record->event.pressed) {
                de_layout_active = !de_layout_active;
                if (dualf_is_off) {
                    layer_invert(_DE_DUALF);
                    layer_invert(_EN_DUALF);
                }
            }
            return true; // toggle _COLEMAK_DE

        case LANG_SWITCH: // sends A(LSFT): switches both system lang and kb lang
            if (record->event.pressed) {
                layer_invert(_COLEMAK_DE);
                de_layout_active = !de_layout_active;  // toggle bool
                if (dualf_is_off) {
                    layer_invert(_DE_DUALF);
                    layer_invert(_EN_DUALF);
                }
            }
            return true; //sends A(KC_LSFT) to change OS language

        /* case DUALF_ON: */
        /*     if (record->event.pressed) { */
        /*         dualf_is_off = 0; */
        /*         if (de_layout_active) { */
        /*             layer_on(_DE_DUALF); */
        /*         } else { */
        /*             layer_on(_EN_DUALF); */
        /*         } */
        /*     } */
        /*     return false; */
        /* case DUALF_OFF: */
        /*     if (record->event.pressed) { */
        /*         dualf_is_off = 1; */
        /*         if (de_layout_active) { */
        /*             layer_off(_DE_DUALF); */
        /*         } else { */
        /*             layer_off(_EN_DUALF); */
        /*         } */
        /*     } */
        /*     return false; */
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
// requires LAYER_LOCK by Getreuer
        // move to the _ADJUST LAYER and llock it
        // if it's already active deactivate it
        case LLOCK_ADJUST:
            if (key_tapped) {
                return toggle_lock_layer(_ADJUST);
            }
            return true;
            break;

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

// add shift to OSL(_UMLAUTS) when held
        case OSL(_UMLAUTS):
            if (record->event.pressed) {
                if (record->tap.count < 1) { // when key is held
                    add_mods(MOD_BIT(KC_LSFT)); // add the shift
                }
            } else {
                del_mods(MOD_BIT(KC_LSFT)); // release the shift
            }
            return true;
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

        /* case COPY_ALL: */
        /*     if (record->event.pressed) { */
        /*         tap_code16(C(KC_HOME)); // go to the beginning of the file */
        /*         tap_code16(C(S(KC_END))); // mark everything till the end of the file */
        /*         /1* tap_code16(C(KC_INS)); // send ctrl + ins -> copy to clipboard *1/ */
        /*     } */
        /*     return true; */
        /*     break; */

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
        case SCLN_KEY: // case for the base English Colemak Layer (continues in the next case)
            if (!process_tap_long_press_key(record, KC_0)) {
                return false;
            }
        case KC_SCLN: // case DE_ODIA:
            // first process the DE_ODIA case in the _UMLAUTS layer
            if (IS_LAYER_ON(_UMLAUTS)) {
                return process_german_keycode(record, keycode);
            }
            // then process the key normally when de_en is not switched
            if (!de_en_switched) {
                return true;
            }
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_SCLN, DE_COLN);
            }
            return process_german_keycode(record, DE_ODIA);// sending Ö
            break;

        case BSLS_KEY: // LALT when held LALT_T(KC_BSLS); only for English layout
            /* if (!process_tap_long_press_key(record, KC_APP)) { return false; } */
            if (!de_en_switched || !record->tap.count) { return true; }
            return process_german_keycode(record, DE_UDIA); // sending Ü
            break;

        case UE_KEY: // LALT when held LALT_T(DE_UDIA); only for German layout
            /* if (!process_tap_long_press_key(record, KC_APP)) { return false; } */
            if (!de_en_switched || !record->tap.count) { return true; }
            return register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
            break;

        case QUOT_KEY: // RCTL_T(KC_QUOT), RCTL_T(DE_ADIA)
            // normal processing, also when held
            if (!de_en_switched || !record->tap.count) { return true; }
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
            }
            return process_german_keycode(record, DE_ADIA); // sending Ä
            break;

// comma and dot for the num pad when held
        case NUM_2:
            return process_tap_long_press_key(record, KC_COMM);
        case NUM_3:
            return process_tap_long_press_key(record, KC_DOT);

// ================ FROM ADJUST LAYER =================
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
                unregister_mods(MOD_BIT(KC_LALT));
                is_alt_tab_active = false;
            }
            return true;

        case ESC_KEY:
            /* if (!process_tap_long_press_key(record, KC_LGUI)) { */
            /*     return false; */
            /* } */
        /* case KC_LEAD: */
        case KC_ESC:
        /* case KC_ENT: */
        /* case ENT_KEY: */
            if (caps_lock_on && record->event.pressed) {
                tap_code(KC_CAPS);
            }
            return true;

// ------------------------- UNICODE -----------------------------------------
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

        case KC_ACC_GRV: // ` (dead)
        case KC_ACC_ACUT: // ´ (dead)
            if (record->event.pressed) {
                tap_code(KC_RALT); // using wincompose when on the English Layout
                switch(keycode) {
                    case KC_ACC_ACUT: // ´ (dead)
                        tap_code(KC_QUOT);
                        break;
                    case KC_ACC_GRV: // ` (dead)
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
            if (record->event.pressed && record->tap.count < 1) { // key is held
                return process_german_keycode(record, SZ_KEY);
            }
            return true;
            break;
        case COMM_KEY:
            if (de_layout_active) {
                if (!process_tap_long_press_key(record, DE_SCLN)) { // long press ;
                    return false;
                } else {
                    return register_unregister_shifted_key(record, DE_COMM, DE_LABK);
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

#ifdef THUMB_SHIFT
        case LOWER:
        case LOWER_DE:
            return toggle_osm_shift(record);
#endif

            // make a rule so that we can use it for alt-tabbing without changing the language
        case OSM(MOD_RSFT):
        case OSM(MOD_LSFT):
            if (IS_LAYER_ON(_ADJUST)) { // using the add_mods function to not trigger the language change
                if (record->event.pressed) {
                    add_mods(MOD_BIT(KC_LSFT));
                } else {
                    del_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
#ifdef THUMB_SHIFT
            return toggle_osm_shift(record);
#else
            return true;
#endif

        // ===== PROCESS_GERMAN_KEYCODE =======
        case DE_ADIA:
        case DE_UDIA:
            if (IS_LAYER_ON(_UMLAUTS)) {
                return process_german_keycode(record, keycode);
            }
            return true;
        case KC_DEG:
            if (de_layout_active) {
                return register_unregister_key(record, DE_DEG);
            }
        case SZ_KEY:
            if (de_layout_active) {
                return register_unregister_key(record, DE_SS);
            }
        case DE_EURO:
            return process_german_keycode(record, keycode); // returns true for de_layout_active
        // ===== PROCESS_GERMAN_KEYCODE =======

        case KC_KP_EQUAL: // =
            if (de_layout_active) {
                return register_unregister_key(record, DE_EQL);
            } else {
                return register_unregister_key(record, KC_EQL);
            }
            break;
        case KC_UNDS: // make underscore work for both layouts on the _NUM layer
            if (de_layout_active && !IS_LAYER_ON(_LOWER_DE) ) {
                return register_unregister_key(record, DE_UNDS);
            }
            return true;

        case KC_HASH: // make hash work as a combo for both layouts
            if (de_layout_active && !IS_LAYER_ON(_LOWER_DE) ) {
                return register_unregister_key(record, DE_HASH);
            }
            return true;

        /* case KC_COLN: */
        /*     if (IS_LAYER_ON(_NUM) && de_layout_active) { */
        /*         return register_unregister_key(record, DE_COLN); */
        /*     } */
        /*     return true; */

            // ===== COMBOS ====
        case AE_QUOT_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case AE_QUOT:
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_QUOT, DE_DQUO);
            } else {
                return process_german_keycode(record, DE_ADIA);
            }
            return false;
        case OE_SCLN_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case OE_SCLN:
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_SCLN, DE_COLN);
            } else {
                return process_german_keycode(record, DE_ODIA);
            }
            return false;
        case UE_BSLS_CAPS: // for the combo with lower to produce capital letters
            shifted = true;
        case UE_BSLS:
            if (de_layout_active) {
                return register_unregister_shifted_key(record, DE_BSLS, DE_PIPE);
            } else {
                return process_german_keycode(record, DE_UDIA);
            }
            return false;

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
        case KC_TILD: // ~
            if (de_layout_active) {
                return register_unregister_key(record, DE_TILD);
            }
            return true;
        case KC_CIRC: // ^
            if (de_layout_active) {
                return register_unregister_key(record, DE_CIRC);
            }
            return true;
        case KC_AMPR: // &
            if (de_layout_active) {
                return register_unregister_key(record, DE_AMPR);
            }
            return true;
        case KC_ASTR: // *
            if (de_layout_active) {
                return register_unregister_key(record, DE_ASTR);
            }
            return true;
        case KC_LPRN: // (
            if (de_layout_active) {
                return register_unregister_key(record, DE_LPRN);
            }
            return true;
        case KC_RPRN: // )
            if (de_layout_active) {
                return register_unregister_key(record, DE_RPRN);
            }
            return true;
        case KC_MINS: // -
            if (de_layout_active) {
                return register_unregister_key(record, DE_MINS);
            }
            return true;
        case KC_HASH: // #
            if (de_layout_active) {
                return register_unregister_key(record, DE_HASH);
            }
            return true;
        case KC_EQL: // =
            if (de_layout_active) {
                return register_unregister_key(record, DE_EQL);
            }
            return true;
        case KC_PLUS: // +
            if (de_layout_active) {
                return register_unregister_key(record, DE_PLUS);
            }
            return true;
        case DE_QUOT: // S(KC_NUHS)
            if (!de_layout_active) {
                return register_unregister_key(record, KC_QUOT);
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
                return register_unregister_key(record, DE_DQUO);
            }
            return true;
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
