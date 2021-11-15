// This file contains the tapping term timings as well as the
// process_record_user part of the keymap, where the custom key codes are
// defined. 
#pragma once

float thumb_factor  = 0.95;
float index_factor  = 1.15;
float middle_factor = 1.2;
float ring_factor   = 1.25;
float pinky_factor  = 1.15;
float td_factor     = 1.3;

// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false; 

// declaring several logical variables
bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;
bool win_unicode_enable= true;
bool tap_hold_active   = false;

#ifdef NAGINATA_ENABLE
bool naginata_active   = false;
bool come_from_naginata = false;
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t key_timer;
    switch (keycode) {

// ------------------------------- LANGUAGES & LAYERS --------------------------
        case COLEMAK:
            if (record->event.pressed) {
//                set_single_persistent_default_layer(_COLEMAK);
                default_layer_set(1UL<<_COLEMAK); // reduce writing to the eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_en_song);
#endif
            }
            return false;
            break;
        case COLEMAK_DE:
            if (record->event.pressed) {
//                set_single_persistent_default_layer(_COLEMAK_DE);
                default_layer_set(1UL<<_COLEMAK_DE); // reduce writing to the eeprom
#ifdef AUDIO_ENABLE
                PLAY_SONG(colemak_de_song);
#endif
            }
            return false;
            break;
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

// ------------------------ TABBING, VIM ----------------------------------------
        case VIM_O:
            if (record->event.pressed) {
                tap_code(KC_END);
                tap_code(KC_ENT);
            }
            return false;
            break;
        case VIM_V:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    clear_mods();
                } else {
                    register_mods(MOD_LSFT);
                }
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
            break;
        // the next case allows us to use alt_tab without a timer
        case LT(_NAV, KC_SPC):
            if (!record->event.pressed) {
                del_mods(MOD_BIT(KC_LALT));
                del_mods(MOD_BIT(KC_LCTL));
                is_alt_tab_active = false;
                is_ctl_tab_active = false;
                return true;
            }
            return true;

// ------------------------- UNICODE ----------------------------------------- 
        case UNICODE_ALT_SW:
            if (record->event.pressed) {
                win_unicode_enable = !win_unicode_enable;   
            }
            return false;
            break;
        case X(DE_SZ): 
            if (record->event.pressed) {
                if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods();
                    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                        clear_oneshot_mods();
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P1);
                        tap_code(KC_P7);
                        tap_code(KC_P6);  // °
                    } else {
                        clear_mods();
                        add_mods(MOD_BIT(KC_LALT));
                        tap_code(KC_P0);
                        tap_code(KC_P2);
                        tap_code(KC_P2);
                        tap_code(KC_P3);  // ß
                    }
                    unregister_mods(MOD_LALT);
                    set_mods(temp_mods);
                    return false;
                    break;
                }
                return true;
            } 
        case XP(DE_ae, DE_AE):
            if (record->event.pressed) {
                if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods();
                    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
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
                    set_mods(temp_mods);
                    return false;
                    break;
                }
                return true;
            }
        case X(DE_AE):
            if (record->event.pressed) {
                if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P9);
                    tap_code(KC_P6);  // Ä
                    unregister_mods(MOD_LALT);
                    set_mods(temp_mods);
                    return false;
                    break;
                }
                return true;
            }
        case XP(DE_oe, DE_OE):
            if (record->event.pressed) {
                if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods();
                    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
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
                    set_mods(temp_mods);
                    return false;
                    break;
                }
                return true;
            }
        case X(DE_OE):
            if (record->event.pressed) {
                if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P1);
                    tap_code(KC_P4);  // Ö
                    unregister_mods(MOD_LALT);
                    set_mods(temp_mods);
                    return false;
                    break;
                }
                return true;
            }
        case XP(DE_ue, DE_UE):
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(DE_UDIA);
                    return false;
                } else if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods();
                    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
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
                    set_mods(temp_mods);
                    return false;
                } 
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_UDIA);
                }
            }
        case X(DE_UE):
            if (record->event.pressed) {
                if (de_layout_active) {
                    register_code16(S(DE_UDIA));
                    return false;
                } else if (!win_unicode_enable) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P0);  // Ü
                    unregister_mods(MOD_LALT);
                    set_mods(temp_mods);
                    return false;
                }
                return true;
            } else {
                if (de_layout_active) {
                    unregister_code16(DE_UDIA);
                }
            }
        case DE_EGRAVE:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P0);
                    tap_code(KC_P0);  // È
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    tap_code(KC_P2);  // è
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case DE_EAIGU:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P0);
                    tap_code(KC_P1);  // É
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    tap_code(KC_P3);  // é
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;
        case KC_CURRENCY:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();
                if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                    clear_oneshot_mods();
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P1);
                    tap_code(KC_P5);
                    tap_code(KC_P7);  // ¥
                } else {
                    clear_mods();
                    add_mods(MOD_BIT(KC_LALT));
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    tap_code(KC_P8);  // €
                }
                unregister_mods(MOD_LALT);
                set_mods(temp_mods);
            }
            return false;
            break;

// ------------------------- GERMAN KEYMAP ----------------------------------------- 
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
        case KC_QUOT:
            if (de_layout_active) {
                if (record->event.pressed) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    if (temp_mods & MOD_MASK_SHIFT) {
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
        case KC_DOT:
            if (de_layout_active) {
                if (record->event.pressed) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    if (temp_mods & MOD_MASK_SHIFT) {
                        register_code16(DE_RABK);  // > right angle bracket 
                    } else {
                        register_code16(DE_DOT);  // .
                    }
                } else {
                    unregister_code16(DE_RABK);
                    unregister_code16(DE_DOT);
                }
                return false;
            } else {
                return true;
            }
        case KC_COMM:
            if (de_layout_active) {
                if (record->event.pressed) {
                    uint8_t temp_mods = get_mods() | get_oneshot_mods();
                    if (temp_mods & MOD_MASK_SHIFT) {
                        clear_mods();
                        clear_oneshot_mods();
                        register_code16(DE_LABK);  // < left angle bracket
                        set_mods(temp_mods);
                    } else {
                        register_code16(DE_COMM);  // ,
                    }
                } else {
                    unregister_code16(DE_LABK);
                    unregister_code16(DE_COMM);
                }
                return false;
            } else {
                return true;
            }
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
        case KC_ACUT: // ´
            if (de_layout_active) {
                if (record->event.pressed) {
                    register_code16(DE_ACUT);
                } else {
                    unregister_code16(DE_ACUT);    
                }
                return false;
            } else {
                if (record->event.pressed) {
                    send_unicode_hex_string("0xB4");
                }
                return false;
            }
// ------------------------- MOD-/LAYER-TAPS ---------------------------------
        case LT(_MOUSE, KC_Z):
            if (de_layout_active) {
                if (record->event.pressed) {
                    // if it's a hold check whether it's part of a tap-hold 
                    // (it can only be true, when key_timer has been recently set, i.e. by tapping once before)
                    if (timer_elapsed(key_timer) < (TAPPING_TERM * pinky_factor)) {
                        register_code16(DE_Z); // register Z
                        tap_hold_active = true; 
                        return false;
                    }
                    if (record->tap.count) { // changes the output for the tap key to work with the german layout
                        tap_code16(DE_Z); // tap Z
                        key_timer = timer_read(); // start a timer so that we can detect a quick tap-hold 
                        return false;
                    } 
                    return true;
                } else {
                    // when releasing, check whether tap_hold_active was true
                    // and disable it, no tapping of the GUI key in this case
                    if (tap_hold_active) {
                        unregister_code16(DE_Z); // release Z
                        tap_hold_active = false;
                        return false;
                    } else { // otherwise process the release normally and tap the gui key
                        return true;
                    }
                }
            } else { //process the key normally when the English layout is active
                return true;
            }
        case LT(_MOUSE, KC_SLSH):
            if (de_layout_active) {
                if (record->event.pressed) {
                    // get the status of the mods to differentiate shifted state
                    uint8_t temp_mods = get_mods() | get_oneshot_mods(); 
                    // if it's a hold check whether it's part of a tap-hold 
                    // (it can only be true, when key_timer has been recently set, i.e. by tapping once before)
                    if (timer_elapsed(key_timer) < (TAPPING_TERM * pinky_factor)) {
                        if (temp_mods & MOD_MASK_SHIFT) {
                            register_code16(DE_QUES); // register ?
                        } else {
                            register_code16(DE_SLSH); // register /
                        }
                        tap_hold_active = true; 
                        return false;
                    }
                    if (record->tap.count) { // changes the output for the tap key to work with the german layout
                        if (temp_mods & MOD_MASK_SHIFT) {
                            tap_code16(DE_QUES); // tap ?
                        } else {
                            tap_code16(DE_SLSH); // tap /
                        }
                        key_timer = timer_read(); // start a timer so that we can detect a quick tap-hold 
                        return false;
                    } 
                    return true;
                } else {
                    // when releasing, check whether tap_hold_active was true
                    // and disable it, no tapping of the GUI key in this case
                    if (tap_hold_active) {
                        unregister_code16(DE_QUES); // release ?
                        unregister_code16(DE_SLSH); // release /
                        tap_hold_active = false;
                        return false;
                    } else { // otherwise process the release normally and tap the gui key
                        return true;
                    }
                }
            } else { //process the key normally when the English layout is active
                return true;
            }
        case LALT_T(KC_Y):
            if (de_layout_active) {
                if (record->event.pressed) {
                    // if it's a hold check whether it's part of a tap-hold 
                    // (it can only be true, when key_timer has been recently set, i.e. by tapping once before)
                    if (timer_elapsed(key_timer) < (TAPPING_TERM * ring_factor)) {
                        register_code16(DE_Y); // register Y
                        tap_hold_active = true; 
                        return false;
                    }
                    if (record->tap.count) { // changes the output for the tap key to work with the german layout
                        tap_code16(DE_Y); // tap Y
                        key_timer = timer_read(); // start a timer so that we can detect a quick tap-hold 
                        return false;
                    } 
                    return true;
                } else {
                    // when releasing, check whether tap_hold_active was true
                    // and disable it, no tapping of the GUI key in this case
                    if (tap_hold_active) {
                        unregister_code16(DE_Y); // release Y
                        tap_hold_active = false;
                        return false;
                    } else { // otherwise process the release normally and tap the gui key
                        return true;
                    }
                }
            } else { //process the key normally when the English layout is active
                return true;
            }
        // switch multiplexing for escape, short tap for escape, long press for context menu
        case M_ESCM:
            if (record->event.pressed) {
                key_timer = timer_read();
            } else {
                if (timer_elapsed(key_timer) > TAPPING_TERM) {
                    tap_code(KC_APP);
                } else {
                    tap_code(KC_ESC);
                }
            }
            return false;
        case RGUI_T(KC_SCLN): // this key behaves as a gui mod tap for both german and english layout
            if (de_layout_active) {
                if (record->event.pressed) {
                    // get the status of the mods to differentiate shifted state
                    uint8_t temp_mods = get_mods() | get_oneshot_mods(); 
                    // if it's a hold check whether it's part of a tap-hold 
                    // (it can only be true, when key_timer has been recently set, i.e. by tapping once before)
                    if (timer_elapsed(key_timer) < (TAPPING_TERM * pinky_factor)) {
                        if (temp_mods & MOD_MASK_SHIFT) {
                            register_code16(DE_COLN); // register :
                        } else {
                            register_code16(DE_SCLN); // register ;
                        }
                        tap_hold_active = true; 
                        return false;
                    }
                    if (record->tap.count) { // changes the output for the tap key to work with the german layout
                        if (temp_mods & MOD_MASK_SHIFT) {
                            tap_code16(DE_COLN); // tap :
                        } else {
                            tap_code16(DE_SCLN); // tap ;
                        }
                        key_timer = timer_read(); // start a timer so that we can detect a quick tap-hold 
                        return false;
                    } 
                    return true;
                } else {
                    // when releasing, check whether tap_hold_active was true
                    // and disable it, no tapping of the GUI key in this case
                    if (tap_hold_active) {
                        unregister_code16(DE_COLN);
                        unregister_code16(DE_SCLN);
                        tap_hold_active = false;
                        return false;
                    } else { // otherwise process the release normally and tap the gui key
                        return true;
                    }
                }
            } else { //process the key normally when the English layout is active
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

