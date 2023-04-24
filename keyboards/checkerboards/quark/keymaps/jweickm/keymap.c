 /* Copyright 2022 Jakob Weickmann
 * CHECKERBOARDS/QUARK
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
#include "jweickm_header.h"
#include "g/keymap_combo.h"

// =============== HELPER VARIABLES
// logical variable to differentiate between the German and the English input mode
bool de_layout_active  = false;

// declaring several logical variables
bool caps_lock_on;
bool num_lock_on;
// controls which of the two languages (en/ge) is used for coding and which is used for typing German
// English by default
bool de_en_switched     = false;


// ============ TAP DANCE ================
// Tap Dance declarations
#ifdef TAP_DANCE_ENABLE
enum tap_dance_codes {
    TD_LPRN,     // round brackets (parentheses)
    TD_LBRC,     // square brackets
    TD_LCBR,     // curly brackets
    TD_LABK,     // angling brackets
};
#endif

// ==== PROCESS RECORD USER
#include "jweickm_process_record_user.c"

// for leader functionality
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#endif
// ===============================================
void matrix_scan_user(void) {

#ifdef LEADER_ENABLE
#include "leader_dictionary.c"
#endif

#ifdef ACHORDION
    achordion_task();
#endif
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on  = led_state.num_lock;
    return true;
}

#ifdef WIDE_LAYOUT
#include "layouts/wide_layout.c"
#else
#include "layouts/narrow_layout.c"
#endif
