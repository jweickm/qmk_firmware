/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
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
#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(STARTUP_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(PLANCK_SOUND),\
                                  SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND), \
                                  SONG(WORKMAN_SOUND), \
                                  SONG(PLOVER_SOUND), \
                                  SONG(STARTUP_SOUND), \
                                  SONG(PREONIC_SOUND), \
                                  SONG(GOODBYE_SOUND), \
                                }
    #define AUDIO_DAC_SAMPLE_WAVEFORM_SQUARE
    #define AUDIO_DAC_SAMPLE_MAX 423U // define the volume: 65535U is standard
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// settings for HOME ROW MODS
#define TAPPING_TERM 160 // 200 ms is the default value
#define TAPPING_TERM_PER_KEY
//#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

// settings for LEADER key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 280
#define LEADER_NO_TIMEOUT

// settings for COMBOS
#define COMBO_TERM 40

#define RGBLIGHT_SLEEP // RGB lighting will switch off when the host goes to sleep
#define RGBLIGHT_LAYERS

// 薙刀式の設定
//#define NAGINATA_ENABLE // requires 10,560 bytes

// for unicode support in windows using wincompose
#define UNICODE_SELECTED_MODES UC_WINC
