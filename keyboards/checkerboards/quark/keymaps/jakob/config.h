/* Copyright 2020 Nathan Spears
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

#define TAPPING_TOGGLE 2

// settings for HOME ROW MODS
#define TAPPING_TERM 160 // 200 ms is the default value
#define TAPPING_TERM_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* #define ACHORDION */

// settings for LEADER key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 280
#define LEADER_NO_TIMEOUT

// settings for COMBOS
#define COMBO_TERM 35 
// always checks for the combos on the base layer, even when using another layer
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_VARIABLE_LEN // for gboard combos


// Feature disable options
// These options are also useful to firmware size reduction.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
