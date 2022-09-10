 /* Copyright 2022 Jakob Weickmann
 * PLANCK/REV6
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
/* #include "layouts/narrow_layout.c" */
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
    if (de_layout_active) {
        tap_code16(DE_LPRN);
    } else {
        tap_code16(KC_LPRN);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RPRN);
        } else {
            tap_code16(KC_RPRN);
        }
        tap_code(KC_LEFT);
    }
}
void dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LBRC);
    } else {
        tap_code(KC_LBRC);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RBRC);
        } else {
            tap_code(KC_RBRC);
        }
        tap_code(KC_LEFT);
    }
}
void dance_cbr(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LCBR);
    } else {
        tap_code16(KC_LCBR);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RCBR);
        } else {
            tap_code16(KC_RCBR);
        }
        tap_code(KC_LEFT);
    }
}
/* void vim_gg(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         tap_code16(C(KC_END)); */
/*     } else { */
/*         tap_code16(C(KC_HOME)); */
/*     } */
/* } */

void dance_abk(qk_tap_dance_state_t *state, void *user_data) {
    if (de_layout_active) {
        tap_code16(DE_LABK);
    } else {
        tap_code16(KC_LABK);
    }
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code16(DE_RABK);
        } else {
            tap_code16(KC_RABK);
        }
        tap_code(KC_LEFT);
    }
}

/* void dance_larrow(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (de_layout_active) { */
/*         tap_code16(DE_LABK); */
/*     } else { */
/*         tap_code16(S(KC_COMM)); */
/*     } */
/*     if (state->count == 1) { */
/*     } else { */
/*         if (de_layout_active) { */
/*             tap_code(DE_MINS); */
/*         } else { */
/*             tap_code16(KC_MINS); */
/*         } */
/*     } */
/* } */
void dance_rarrow(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 1) {
        if (de_layout_active) {
            tap_code(DE_MINS);
        } else {
            tap_code16(KC_MINS);
        }
    } 
    if (de_layout_active) {
        tap_code16(DE_RABK);
    } else {
        tap_code16(S(KC_DOT));
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // declare tap dance actions here
    [TD_PRN]    = ACTION_TAP_DANCE_FN(dance_prn), 
    [TD_BRC]    = ACTION_TAP_DANCE_FN(dance_brc), 
    [TD_CBR]    = ACTION_TAP_DANCE_FN(dance_cbr), 
    /* [TD_VIM_GG] = ACTION_TAP_DANCE_FN(vim_gg), */
    /* [TD_F4]     = ACTION_TAP_DANCE_DOUBLE(KC_F4, A(KC_F4)), */
    /* [TD_LARROW] = ACTION_TAP_DANCE_FN(dance_larrow), */
    [TD_RARROW] = ACTION_TAP_DANCE_FN(dance_rarrow),
    [TD_ABK]    = ACTION_TAP_DANCE_FN(dance_abk),
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
    const key_override_t combo_delete_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
    const key_override_t lalt_k_kana_override       = ko_make_with_layers_and_negmods(
            MOD_BIT(KC_LALT),   // Trigger mods: LALT
            K_KEY,              // Trigger key: K
            A(KC_GRV),          // Replacement key: A(KC_GRV)
            ~0,                 // Activate on all layers
            MOD_MASK_CSG        // Do not activate when Ctrl, Shift or GUI are pressed
            ); // this override allows us to switch kana by pressing ralt and esc

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &lalt_k_kana_override,
    /* &combo_delete_key_override, */
    /* &lalt_esc_kana_override, */
    NULL // Null terminate the array of overrides!
};
#endif

#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#endif

void matrix_scan_user(void) {

#ifdef LEADER_ENABLE
#include "leader_dictionary.c"
#endif

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

#ifdef AUDIO_ENABLE
bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
#endif

#ifdef RGBLIGHT_ENABLE
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

#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
#endif
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
#ifdef DYNAMIC_MACRO_ENABLE
    rgblight_set_layer_state(8, isRecording); // turn on the adjust layer when recording otf macros
#endif
    rgblight_set_layer_state(7, led_state.caps_lock);
    rgblight_set_layer_state(1, de_layout_active);
#endif
    caps_lock_on    = led_state.caps_lock;
    num_lock_on     = led_state.num_lock;
    return true;
}

#ifdef RGBLIGHT_ENABLE
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
#endif

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
    // keep numlock turned on, i.e. turn it on everytime it is turned off
    /* if (!(usb_led & (1<<USB_LED_NUM_LOCK))) { */
    /*     tap_code(KC_NUM_LOCK); */
    /* } */
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ================================================================================================
*  ================================================================================================
* NARROW HAND POSITION (3) for MT3 SUSUWATARI
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |  __  |      |      |  __  |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      | 
     * `-----------------------------------------------------------------------------------'
     */

/* ----------------------------------------------------------------------------------------
* _COLEMAK
     * ,-----------------------------------------------------------------------------------.
     * | ESC  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |  ;:  |  \|  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | TAB  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '"  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | Mo ↓ | Mo ↑ |A_RALT| 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_planck_mit(
        ESC_KEY, Q_KEY, W_KEY, F_KEY, P_KEY, B_KEY, J_KEY, L_KEY, U_KEY, Y_KEY, SCLN_KEY, BSLS_KEY, // LT(0, DE_UDIA), 
        TAB_KEY, A_KEY, R_KEY, S_KEY, T_KEY, G_KEY, M_KEY, N_KEY, E_KEY, I_KEY, O_KEY, QUOT_KEY, // KC_QUOT, 
        OSM(MOD_LSFT), Z_KEY, X_KEY, C_KEY, D_KEY, V_KEY, K_KEY, H_KEY, COMM_KEY, DOT_KEY, SLSH_KEY, OSM(MOD_RSFT)/*ENT_KEY*/, 
        LCTL_T(KC_CAPS), OSM(MOD_LGUI), OSM(MOD_LALT), BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY/*FN_KEY*/
        /* LCTL_T(KC_CAPS), KC_LGUI, KC_LALT, BS_KEY, LOWER, NAVSPACE, RAISE, DEL_KEY, DOWN_KEY, UP_KEY, ENT_KEY */
    ),

/* ----------------------------------------------------------------------------------------
* _COLEMAK_DE
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Y  |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  | ____ | ____ | ____ | ____ | ____ | ____ |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ |LWR_DE|     ____    |RSE_DE| ____ | ____ | ____ | ____ | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK_DE] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, Y_KEY_DE, KC_TRNS, KC_TRNS, //DE_UDIA_DE, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, Z_KEY_DE, KC_TRNS, KC_TRNS, KC_TRNS/*D_KEY_DE*/, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS/*BS_KEY_DE*/, LOWER_DE,     KC_TRNS,     RAISE_DE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

#ifdef QWERTY_LAYER
/* _QWERTY without homerow mods so that it can be used with AHK-Naginata 薙刀式
     * ,-----------------------------------------------------------------------------------.
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [] |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '" |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |C-CAPS|  WIN |  LALT|  BS  |LOWER |   NAV-SPC   | RAISE|  DEL | DOWN |  UP  |  ENT | 1x2uC 
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_BRC), 
        KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS/*FN_KEY*/
    ),
#endif 

/* ----------------------------------------------------------------------------------------
* _UMLAUTS
     * ,-----------------------------------------------------------------------------------.
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ö  |   Ü  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |   Ä  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | ____ |     ____    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_UMLAUTS] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, DE_ODIA, DE_UDIA, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_ADIA, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),

// ----------------------------------------------------------------------------------------
#ifdef NAGINATA_ENABLE
/* 薙刀式
     * ,----------------------------------------------------------------------------------.
     * | ____ |  小  |き  ぬ|て  り|し  む|  <-  |  ->  |さ  え|う　わ|す  ゆ|へ  ：| TATE |
     * +------|------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |あ  せ|け  め|と  に|か゛ま|っ  ち|く  や|の゛ー|る　も|い　よ|お  つ| KOTI |
     * +------|------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |  ほ  |  ひ  |は  を|こ゜、|そ  み|た  ろ|な゜。|ん  ね|ら  ふ|れ　ふ| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | EISU | ____ | ____ | ____ | ____ |   NGSHFT    | ____ | ____ | ____ | ____ | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_NAGINATA] = LAYOUT_planck_mit(
       KC_TRNS, NG_Q, NG_W, NG_E, NG_R, NG_T, NG_Y, NG_U, NG_I, NG_O, NG_P, NG_TAYO,
       KC_TRNS, NG_A, NG_S, NG_D, NG_F, NG_G, NG_H, NG_J, NG_K, NG_L, NG_SCLN, NG_KOTI,
       KC_TRNS, NG_Z, NG_X, NG_C, NG_V, NG_B, NG_N, NG_M, NG_COMM, NG_DOT, NG_SLSH, KC_TRNS,
        EISU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        EISU, KC_TRNS, KC_TRNS, KC_TRNS, NG_SHFT2, NG_SHFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
// 薙刀式
#endif

/* ----------------------------------------------------------------------------------------
* _LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   (  |   )  |   [  |   ]  |C-HOME|   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   %  |   ^  |   {  |   }  | C-END|   ~  |   '  |   <  |   >  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |  ENT | ____ | LEFT | RIGHT| ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER] = LAYOUT_planck_mit(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_PRN), KC_RPRN, KC_PIPE,
        KC_TRNS, TD(TD_PRN), KC_RPRN, TD(TD_BRC), KC_RBRC, C(KC_HOME), KC_DQUO, KC_UNDS, KC_PLUS, TD(TD_CBR), KC_RCBR, KC_DQUO, 
        KC_TRNS, KC_PERC, KC_CIRC, TD(TD_CBR), KC_RCBR, C(KC_END), KC_TILD, QUOT_KEY, TD(TD_ABK), KC_RABK, KC_BSLS, DE_ACC_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _LOWER_DE
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   (  |   )  |   [  |   ]  |C-HOME|   "  |   _  |   +  |   {  |   }  |   "  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |   %  |   ^  |   {  |   }  | C-END|   ~  |   '  |   <  |   >  |   \  |   `  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | ____ |     ____    |  ENT | ____ | LEFT | RIGHT| ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_LOWER_DE] = LAYOUT_planck_mit(
        DE_GRV, DE_EXLM, DE_AT, DE_HASH, DE_DLR, DE_PERC, DE_CIRC, DE_AMPR, DE_ASTR, TD(TD_PRN), DE_RPRN, DE_PIPE,
        KC_TRNS, TD(TD_PRN), DE_RPRN, TD(TD_BRC), DE_RBRC, C(KC_HOME), DE_DQUO, DE_UNDS, DE_PLUS, TD(TD_CBR), DE_RCBR, DE_DQUO, 
        KC_TRNS, DE_PERC, DE_CIRC, TD(TD_CBR), DE_RCBR, C(KC_END), DE_TILD, DE_QUOT, TD(TD_ABK), DE_RABK, DE_BSLS, DE_GRV, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   [  |   ]  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   /  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | BSPC |     ____    | ____ | MAIL | <<|  |  |>> | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4/*TD(TD_F4)*/, KC_F5, KC_LABK, KC_MINS, KC_EQL, TD(TD_BRC), KC_RBRC, QUOT_KEY, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, TD(TD_RARROW), KC_TRNS, KC_TRNS, KC_TRNS, DE_ACC_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _RAISE_DE
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F6  |  F1  |  F2  |  F3  |  F4  |  F5  |   <  |   -  |   =  |   [  |   ]  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  F12 |  F7  |  F8  |  F9  |  F10 |  F11 |   `  |   >  |   ,  |   .  |   /  |   ´  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |ADJUST| ____ | BSPC |     ____    | ____ | MAIL | <<|  |  |>> | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE_DE] = LAYOUT_planck_mit(
        DE_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, DE_BSLS, 
        KC_F6, KC_F1, KC_F2, KC_F3, KC_F4/*TD(TD_F4)*/, KC_F5, DE_LABK, DE_MINS, DE_EQL, TD(TD_BRC), DE_RBRC, DE_QUOT, 
        KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, DE_GRV, TD(TD_RARROW), KC_TRNS, KC_TRNS, KC_TRNS, DE_ACUT, 
        KC_TRNS, KC_TRNS, OSL(_ADJUST), KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_MAIL, KC_MPRV, KC_MNXT, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _NUM
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK|   A  |   B  |   C  |   D  |   E  |   F  |   7  |   8  |   9  |   0  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LGUI | LALT | LSFT | LCTL | ____ |   +  |   4  |   5  |   6  |   *  |   ,  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ |   °  |   €  | ____ | ____ |   -  |   1  |   2  |   3  |   /  |   _  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | ____ | BSPC |     ____    |   0  |   .  |   ,  |   =  | ____ | 1x2uC
     * `-----------------------------------------------------------------------------------'
     */ 
    [_NUM] = LAYOUT_planck_mit(
        LLOCK, KC_A, KC_B, KC_C, D_KEY, KC_E, KC_F, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_EQUAL,
        KC_TRNS, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRNS, KC_KP_PLUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_COMM,
        KC_TRNS, KC_TRNS, KC_DEG, DE_EURO, KC_TRNS, KC_TRNS, KC_KP_MINUS, KC_KP_1, NUM_2, NUM_3, KC_KP_SLASH, KC_UNDS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_KP_0, DOT_KEY, COMM_KEY, KC_KP_EQUAL, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _MOUSE
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK|C-HOME| BTN4 | M ↑  | BTN5 | C-END|  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |DESK<-| M <- | M ↓  | M -> |DESK->|  F15 | RCTL | RSFT | LALT | RGUI | ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | LSFT |WHL <-|WHL ↑ |WHL ↓ |WHL ->|  F14 |  F13 | BTN4 | BTN5 |SCRLCK| ____ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ | ____ | ____ | BTN 3| BTN 2|    BTN 1    | LLOCK|  SPC | Bri- | Bri+ | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_mit(
        LLOCK, C(KC_HOME), KC_BTN4, KC_MS_U, KC_BTN5, C(KC_END), KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21,
        KC_TRNS, C(G(KC_LEFT)), KC_MS_L, KC_MS_D, KC_MS_R, C(G(KC_RIGHT)), KC_F15, KC_RCTL, OSM(MOD_RSFT), OSM(MOD_LALT), OSM(MOD_RGUI), KC_TRNS, 
        KC_TRNS, KC_LSFT, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_F14, KC_F13, KC_BTN4, KC_BTN5, KC_SCROLL_LOCK, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, LLOCK, KC_SPC, KC_BRID, KC_BRIU, KC_TRNS
    ),

/* ----------------------------------------------------------------------------------------
* _ADJUST
     * ,-----------------------------------------------------------------------------------.
     * | LLOCK| PRINT| C(->)|  MEH | HYPR | C(<-)| KANA | REDO | UNDO | !LANG|KBLANG|G(SPC)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |A(TAB)| LGUI | LALT | LSFT | LCTL |CPYALL| LEFT | DOWN |  UP  | RIGHT| VIM_O|  INS |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ____ |NUMLCK|DESK<-| WHLUP| WHLDN|DESK->| HOME | PGDN | PGUP |  END |UML_SW| MUTE |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |EEPRST| FLASH|REBOOT| ____ | ____ |     ____    | ____ | ____ | VOLD | VOLU | ____ | 2x2uC
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_mit(
        LLOCK, KC_PSCR, C(KC_RIGHT), OSM(MOD_MEH), OSM(MOD_HYPR), C(KC_LEFT), A(KC_GRV), REDO, UNDO, LANG_SWITCH, KB_LANG_SWITCH, G(KC_SPC), 
        ALT_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, COPY_ALL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, VIM_O, KC_INS, 
        OSM(MOD_LSFT), KC_NUM_LOCK, C(G(KC_LEFT)), KC_WH_U, KC_WH_D, C(G(KC_RIGHT)), KC_HOME, KC_PGDN, KC_PGUP, KC_END, UMLAUT_SWITCH, KC_MUTE,
        QK_CLEAR_EEPROM, QK_BOOT, QK_REBOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS
    ),
};
