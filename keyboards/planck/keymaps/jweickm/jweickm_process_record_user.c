float thumb_factor  = 0.95;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
float td_factor     = 1.3;

// define the per_key_tapping_term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // thumb keys
        case LT(_NUM, KC_ESC):
        case LOWER: 
        case LSFT_T(KC_BSPC):
        case RAISE:
        case LT(_MOUSE, KC_DEL):
            return TAPPING_TERM * thumb_factor;
        case NAVSPACE:
        case NAVENT:
            return TAPPING_TERM * 1.1;

        // index finger keys
        case PASTE_V:
        case LCTL_T(KC_P):
            return TAPPING_TERM * index_factor;
        case RCTL_T(KC_L):
            return TAPPING_TERM * (index_factor + 0.1);
        case LT(_MOUSE, KC_VOLU):
        case LT(_MOUSE, KC_VOLD):
            return TAPPING_TERM * td_factor;

        // middle finger keys
        case LSFT_T(KC_F):
        case LSFT_T(KC_R):
        case RSFT_T(KC_U):
        case RSFT_T(KC_E):
        case LT(0, KC_COMM):
        case COPY_C:
            return TAPPING_TERM * middle_factor;

        // ring finger keys
        case LALT_T(KC_W):
        case LALT_T(KC_R):
        case LALT_T(KC_Y):
        case LALT_T(KC_I):
        case LGUI_T(KC_TAB):
        case LT(0, KC_DOT):
        case CUT_X:
            return TAPPING_TERM * ring_factor;

        // pinky keys
        case LGUI_T(KC_Q):
        case LGUI_T(KC_A):
        case RGUI_T(KC_SCLN):
        case RGUI_T(KC_O):
        case LT(_MOUSE, KC_Z):
        case LT(_MOUSE, KC_SLSH):
        case LSFT_T(KC_Z):
        case LT(0, KC_Z):
        case LT(0, KC_SLSH):
        case LT(0, KC_MINS):
        case LT(0, KC_SCLN):
            return TAPPING_TERM * pinky_factor;
        case RSFT_T(KC_RALT):
        case LCTL_T(KC_CAPS):
        case LT(0, DE_UDIA):
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
        case LSFT_T(KC_S):
        case RSFT_T(KC_E):
            return true;
//      case LOWER:
//            return true;
//      case LT(_LOWER, KC_BSPC):
//            return true;
        default:
            return false;
    }
}

uint8_t mod_state;
uint8_t osmod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    osmod_state = get_oneshot_mods();
    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        case GAMING:
            if (record->event.pressed) {
                layer_invert(_GAMING);
                combo_toggle(); // turns off combos when moving to _GAMING
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
                return false;
            }
            break;
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
            }
            return false;

// ------------------------ SPECIAL FUNCTION KEYS ------------------------------------
        case VIM_O:
            if (record->event.pressed) {
                tap_code(KC_END);
                tap_code(KC_ENT);
            }
            return false;
            break;
        case CUT_X:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send CTL-C
                return false;
            }
            return true;
        case COPY_C:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(C(KC_INS)); // Intercept hold function to send CTRL-INSERT
                return false;
            }
            return true;
        case PASTE_V:
            if (record->tap.count && record->event.pressed) {
                return true;         // Return true for normal processing of tap keycode
                break;
            } else if (record->event.pressed) {
                tap_code16(S(KC_INS)); // Intercept hold function to send SHIFT-INSERT
                return false;
            }
            return true;
        case UNDO:
            if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_Z));
                }
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
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
        case NAVENT:
        case LOWER:
            if (!record->event.pressed && (is_alt_tab_active || is_ctl_tab_active)) {
                del_mods(MOD_BIT(KC_LALT));
                del_mods(MOD_BIT(KC_LCTL));
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
            }
            return true;
        // this esc turns off caps lock, if it was active
        case KC_ESC:
            if (record->event.pressed && caps_lock_on) {
                tap_code(KC_CAPS);
            }
            return true;


// ------------------------- UNICODE ----------------------------------------- 
        case UNICODE_ALT_SW:
            if (record->event.pressed) {
                win_unicode_enable = !win_unicode_enable;   
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
        case DE_ae:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(DE_ADIA);
                    return false;
                } else {
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
                    break;
                }
                return true;
            } else {
                unregister_code16(DE_ADIA);
                return false;
            }
        case DE_AE:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(S(DE_ADIA));
                    return false;
                } else {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P9);
                    tap_code(KC_P6);  // Ä
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                    break;
                }
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_ADIA);
                    return false;
                }
            }
        case DE_oe:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(DE_ODIA);
                    return false;
                } else {
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
                    break;
                }
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_ODIA);
                    return false;
                }
            }
        case DE_OE:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(S(DE_ODIA));
                    return false;
                } else {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P1);
                    tap_code(KC_P4);  // Ö
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                    break;
                }
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_ODIA);
                    return false;
                }
            }
        case LT(0, DE_UDIA):
            if (record->tap.count && record->event.pressed) {
                // tap
                if (de_layout_active) {
                    return true;
                } else {
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
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(DE_ODIA);
                    return false;
                } else {
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
            } else {
                return true;
            }
//        case DE_ue:
//            if (record->event.pressed) {
//                if (de_layout_active) {
//                    register_code16(DE_UDIA);
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
//                    unregister_code16(DE_UDIA);
//                    return false;
//                }
//            }
        case DE_UE:
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(S(DE_UDIA));
                    return false;
                } else {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P0);  // Ü
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                    return false;
                }
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_UDIA);
                    return false;
                }
            }
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
        case LT(0, KC_Z): // Z - ß
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    register_code(DE_Z);  // Z
                    return false;
                }
                return true;
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(DE_SS); // ß
                } else {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P3);  // ß
                    unregister_mods(MOD_LALT);
                    set_mods(mod_state);
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_Z);
                    return false;
                }
                return true;
            }
        case KC_Z: // Z
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code(DE_Z);
                } else {
                    unregister_code(DE_Z);
                }
                return false;
            } else {
                return true;
            }
        case KC_Y: // Y
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code(DE_Y);
                } else {
                    unregister_code(DE_Y);
                }
                return false;
            } else {
                return true;
            }
        case LT(0, KC_SCLN): // this key behaves as a gui mod tap for both german and english layout
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_COLN); // register :
                    } else {
                        register_code16(DE_SCLN); // register ;
                    }
                    return false;
                } else {
                    return true;
                }
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(DE_COLN); // :
                } else {
                    tap_code16(KC_COLN); // :
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_COLN);
                    unregister_code16(DE_SCLN);
                    return false;
                } else {
                    return true;
                }
            }
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
                    register_code16(DE_HASH);
                } else {
                    unregister_code16(DE_HASH);
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
        case KC_PLUS: // +
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_PLUS);
                } else {
                    unregister_code16(DE_PLUS);
                }
                return false;
            } else {
                return true;
            }
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
        case LT(0, KC_QUOT):
            if (record->tap.count && record->event.pressed) {
                // tap
                if (!de_layout_active) {
                    return true;
                } else {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_DQUO);  // \"
                    } else {
                        register_code16(DE_QUOT);  // /'
                    }
                }
                return false;
            } else if (record->event.pressed) {
                if (de_layout_active) {
                    tap_code16(DE_ADIA);
                    return false;
                } else {
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
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_DQUO);
                    unregister_code16(DE_QUOT);
                    return false;
                }
                return true;
            }
//        case KC_QUOT:
//            if (de_layout_active) {
//                if (record->event.pressed) {
//                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        register_code16(DE_DQUO);  // \"
//                    } else {
//                        register_code16(DE_QUOT);  // /'
//                    }
//                } else {
//                    unregister_code16(DE_DQUO);
//                    unregister_code16(DE_QUOT);
//                }
//                return false;
//            } else {
//                return true;
//            }
        case LT(0, KC_DOT):
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_RABK);  // > right angle bracket 
                        return false;
                    }
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
                    unregister_code(DE_DOT);
                    return false;
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
        case LT(0, KC_COMM):
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        clear_mods();
                        clear_oneshot_mods();
                        register_code16(DE_LABK);  // < left angle bracket when shifted
                        set_mods(mod_state);
                    return false;
                    }
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
                    unregister_code(DE_COMM);
                    return false;
                }
                return true;
            }
        case LT(0, KC_MINS):
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    register_code(DE_MINS);  // - Bindestrich 
                    return false;
                }
                return true;
            } else if (record->event.pressed) { // add underscore as a shifted key
                if (de_layout_active) {
                    tap_code16(DE_UNDS);
                } else {
                    tap_code16(KC_UNDS);
                }
                return false;
            } else {
                if (de_layout_active) {
                    unregister_code(DE_MINS);
                    return false;
                }
                return true;
            }
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
//        case KC_SLSH:
//            if (de_layout_active) {
//                if (record->event.pressed) {
//                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
//                        register_code16(DE_QUES); // register ?
//                    } else {
//                        register_code16(DE_SLSH); // register /
//                    }
//                    return false;
//                } else {
//                    unregister_code16(DE_QUES); // release ?
//                    unregister_code16(DE_SLSH); // release /
//                    return false;
//                }
//            } else { //process the key normally when the English layout is active
//                return true;
//            }
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

// ------------------------- NUMBERS AUTOSHIFT -------------------------------
        case LT(0, KC_1): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;
            }
            return true;
        case LT(0, KC_2): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_AT);
                return false;
            }
            return true;
        case LT(0, KC_3): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_HASH);
                return false;
            }
            return true;
        case LT(0, KC_4): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_DLR);
                return false;
            }
            return true;
        case LT(0, KC_5): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_PERC);
                return false;
            }
            return true;
        case LT(0, KC_6): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            return true;
        case LT(0, KC_7): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_AMPR);
                return false;
            }
            return true;
        case LT(0, KC_8): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_ASTR);
                return false;
            }
            return true;
        case LT(0, KC_9): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            return true;
        case LT(0, KC_0): 
            if (record->tap.count && record->event.pressed) {
                return true;
            } else if (record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            return true;
        case LT(0, KC_SLSH): 
            if (record->tap.count && record->event.pressed) {
                if (de_layout_active) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_QUES); // register ?
                    } else {
                        register_code16(DE_SLSH); // register /
                    }
                    return false;
                } // process the key normally when English layout is active
                    return true;
            } else if (record->event.pressed) { // add minus on hold
                if (de_layout_active) {
                    tap_code16(DE_QUES); // ?
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
        // switch multiplexing for escape, short tap for escape, long press for context menu
        case RGUI_T(KC_SCLN): // this key behaves as a gui mod tap for both german and english layout
            if (de_layout_active) {
                if (record->tap.count && record->event.pressed) {
                    if ((mod_state | osmod_state) & MOD_MASK_SHIFT) {
                        register_code16(DE_COLN); // register :
                    } else {
                        register_code16(DE_SCLN); // register ;
                    }
                    return false;
                } else if (record->event.pressed) {
                    return true;
                } else {
                    unregister_code16(DE_COLN);
                    unregister_code16(DE_SCLN);
                    return true;
                }
            } else {
                return true;
            }
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

