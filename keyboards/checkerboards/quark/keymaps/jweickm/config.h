/* Copyright 2020 Nathan Spears
 * Copyright 2022 Jakob Weickmann
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

// settings for HOME ROW MODS
#define TAPPING_TERM 160 // 200 ms is the default value
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT // is now the default
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#define ACHORDION
// #define GETREUER_REP_KEY_ENABLE

// if defined, sets the layout to wide_layout.c, else it's the narrow_layout.c
#define WIDE_LAYOUT

// if defined, allows the usage of the non-dualfunction layers
// #define DUALFUNC

// CAPS WORD SETTINGS
/* #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD // works only on left shift */
#define CAPS_WORD_IDLE_TIMEOUT 0 // 5 seconds = default
// #define CAPS_WORD_INVERT_ON_SHIFT
#define ONESHOT_TIMEOUT 0 // Time in ms before the one shot key is released

// turns the lower and raise keys into oneshot shift keys 124-130 bytes
/* #define THUMB_SHIFT */
// adds a space before the thumb shift (only if space was not pressed before)
/* #define SPC_SFT // 66 bytes */

// settings for LEADER key
/* #define LEADER_PER_KEY_TIMING */
/* #define LEADER_TIMEOUT 280 */
/* #define LEADER_NO_TIMEOUT */

// settings for COMBOS
#define COMBO_TERM 35
// always checks for the combos on the base layer, even when using another layer
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_VARIABLE_LEN // for gboard combos
#define COMBO_SHOULD_TRIGGER // for selective combo activation

// Feature disable options
// These options are also useful to firmware size reduction.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define DYNAMIC_MACRO_SIZE 16

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
