/* Copyright 2015-2017 Jack Humbert
 * Copyright 2023 Jakob Weickmann
 *
 This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "jweickm_header.h"
#if hand_position == 1
    #include "layouts/semi_wide_layout.h"
#elif hand_position == 2
    #include "layouts/wide_layout.h"
#elif hand_position == 3
    #include "layouts/narrow_layout.h"
#endif

#include "g/keymap_combo.h"

// =========================================================================================

#ifdef NAGINATA_ENABLE
// 薙刀式
void matrix_init_user(void) {
  uint16_t ngonkeys[]  = {NG_DUMMY, NG_DUMMY};
  uint16_t ngoffkeys[] = {NG_DUMMY, NG_DUMMY};
  set_naginata(_NAGINATA, ngonkeys, ngoffkeys);
// set_naginata(_NAGINATA);
}
// 薙刀式
#endif

// define the tap dance functions
void dance_prn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
//          if (caps_lock_on) {
//              tap_code(DE_8);
//          } else {
                tap_code16(DE_LPRN);
//          }
        } else {
            tap_code16(KC_LPRN);
        }
    } else {
        if (de_layout_active) {
//          if (caps_lock_on) {
//              tap_code(DE_8);
//              tap_code(DE_9);
//          } else {
                tap_code16(DE_LPRN);
                tap_code16(DE_RPRN);
//          }
            tap_code(KC_LEFT);
        } else {
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_LEFT);
        }
    }
}
void dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
            tap_code16(DE_LBRC);
        } else {
            tap_code(KC_LBRC);
        }
    } else {
        if (de_layout_active) {
            tap_code16(DE_LBRC);
            tap_code16(DE_RBRC);
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_LBRC);
            tap_code(KC_RBRC);
            tap_code(KC_LEFT);
        }
    }
}
void dance_cbr(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (de_layout_active) {
            tap_code16(DE_LCBR);
        } else {
            tap_code16(KC_LCBR);
        }
    } else {
        if (de_layout_active) {
            tap_code16(DE_LCBR);
            tap_code16(DE_RCBR);
            tap_code(KC_LEFT);
        } else {
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            tap_code(KC_LEFT);
        }
    }
}
void vim_gg(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(C(KC_END));
    } else {
        tap_code16(C(KC_HOME));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_PRN] = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC] = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR] = ACTION_TAP_DANCE_FN(dance_cbr), 
    [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg),
    [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4)),
};

#include "jweickm_process_record_user.c"

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (muse_mode) {
//         if (IS_LAYER_ON(_RAISE)) {
//             if (clockwise) {
//                 muse_offset++;
//             } else {
//                 muse_offset--;
//             }
//         } else {
//             if (clockwise) {
//                 muse_tempo += 1;
//             } else {
//                 muse_tempo -= 1;
//             }
//         }
//     } else {
//         if (clockwise) {
// #ifdef MOUSEKEY_ENABLE
//             tap_code(KC_MS_WH_DOWN);
// #else
//             tap_code(KC_PGDN);
// #endif
//         } else {
// #ifdef MOUSEKEY_ENABLE
//             tap_code(KC_MS_WH_UP);
// #else
//             tap_code(KC_PGUP);
// #endif
//         }
//     }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
//             if (active) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }

#ifdef KEY_OVERRIDE_ENABLE
    const key_override_t combo_delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
    const key_override_t ralt_esc_kana_override    = ko_make_basic(MOD_BIT(KC_RALT), KC_ESC, A(KC_GRV)); // this override allows us to switch kana by pressing ralt and esc

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &combo_delete_key_override,
    &ralt_esc_kana_override,
    NULL // Null terminate the array of overrides!
};
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {

    #include "leader_dictionary.c"

#ifdef ACHORDION
    achordion_task();
#endif
#ifdef AUDIO_ENABLE
    /* if (muse_mode) { */
    /*     if (muse_counter == 0) { */
    /*         uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()]; */
    /*         if (muse_note != last_muse_note) { */
    /*             stop_note(compute_freq_for_midi_note(last_muse_note)); */
    /*             play_note(compute_freq_for_midi_note(muse_note), 0xF); */
    /*             last_muse_note = muse_note; */
    /*         } */
    /*     } */
    /*     muse_counter = (muse_counter + 1) % muse_tempo; */
    /* } else { */
    /*     if (muse_counter) { */
    /*         stop_all_notes(); */
    /*         muse_counter = 0; */
    /*     } */
    /* } */
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

// Set RGB to change with layer changes
#define HSV_DARKORANGE 10, 255, 255
#define HSV_GRASS 57, 255, 100
#define HSV_OCEAN 148, 255, 100
#define HSV_DARKMAGENTA 201, 255, 255
#define HSV_DARKRED 0, 255, 100
#define HSV_EGGSHELL 30, 10, 255

// Light LEDs 1 to 10 in green when COLEMAK is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_OCEAN});
// Light LEDs 1 to 10 in green when de_layout_active is true
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_GRASS});
// Light LEDs 1 to 10 in darkorange when QWERTY layer is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKORANGE});
// Light LEDs 1 to 10 in red when GAMING layer is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKRED});
// Light LEDs 1 to 10 in goldenrod when _MOUSE is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_ORANGE});
// Light LEDs 1 to 10 in white when _NUM is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_DARKMAGENTA});
// Light bottom LEDs in eggshell when _ADJUST layer is active
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_EGGSHELL}, {7, 3, HSV_EGGSHELL});
// Light bottom LEDs and corner LEDs in darkorange when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_DARKORANGE}, {6, 3, HSV_DARKORANGE});
// Light LEDs 1 to 10 in green when recording a macro 
const rgblight_segment_t PROGMEM my_macro_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_GREEN}, {6, 3, HSV_GREEN});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_layer0_layer,   // 1 colemak 
                                                                               my_layer1_layer,   // 2 de_layout
                                                                               my_layer2_layer,   // 3 qwerty
                                                                               my_layer3_layer,   // 4 gaming
                                                                               my_layer4_layer,   // 5 mouse
                                                                               my_layer5_layer,   // 6 _num
                                                                               my_layer6_layer,   // 7 adjust
                                                                               my_capslock_layer, // 8 capslock
                                                                               my_macro_layer     // 9 recording macro
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

void led_set_user(uint8_t usb_led) {
#ifdef AUDIO_ENABLE
    static uint8_t old_usb_led = 0;
    if (!is_playing_notes()) {
        if ((usb_led & (1<<USB_LED_CAPS_LOCK)) && !(old_usb_led & (1<<USB_LED_CAPS_LOCK))) { 
                // If CAPS LK LED is turning on...
                PLAY_SONG(tone_caps_on);
        } else if (!(usb_led & (1<<USB_LED_CAPS_LOCK)) && (old_usb_led & (1<<USB_LED_CAPS_LOCK))) {
                // If CAPS LK LED is turning off...
                PLAY_SONG(tone_caps_off);
        }
    }
    old_usb_led = usb_led;
#endif

    // keep numlock turned on, i.e. turn it off everytime it is turned on
    if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
        tap_code(KC_NUMLOCK);
    }
}

#ifdef DYNAMIC_MACRO_ENABLE
    #ifdef AUDIO_ENABLE
bool isRecording = false;
void dynamic_macro_record_start_user(void) {
    isRecording = true;
    PLAY_SONG(macro_on_song);
}
void dynamic_macro_record_end_user(int8_t direction) {
    isRecording = false;
    PLAY_SONG(macro_off_song);
}
    #endif
#endif

bool led_update_user(led_t led_state) {
#ifdef DYNAMIC_MACRO_ENABLE
    rgblight_set_layer_state(8, isRecording); // turn on the adjust layer when recording otf macros
#endif
    rgblight_set_layer_state(7, led_state.caps_lock);
    rgblight_set_layer_state(1, de_layout_active);
    if (led_state.caps_lock) {
        caps_lock_on = TRUE;
    } else {
        caps_lock_on = FALSE;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, de_layout_active);
    rgblight_set_layer_state(2, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMING));
    rgblight_set_layer_state(4, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(5, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(6, layer_state_cmp(state, _ADJUST));
#ifdef NAGINATA_ENABLE
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAGINATA));
    if (layer_state_cmp(state, _NAGINATA)) {
        naginata_active = true;
    } else {
        naginata_active = false;
    }
#endif
    //if (layer_state_cmp(state, _LOWER) && layer_state_cmp(state, _RAISE))  {
    //    return state | (1UL << _ADJUST);
    //} else {
    //    return state & ~(1UL << _ADJUST);
    //}
    // state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    //rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    return state;
}

