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
#include "g/keymap_combo.h"

// ============================================================================
#include "jweickm_process_record_user.c"

void matrix_scan_user(void) {

#ifdef ACHORDION
    achordion_task();
#endif
}

void keyboard_post_init_user(void) {
}

bool led_update_user(led_t led_state) {
    caps_lock_on    = led_state.caps_lock;
    num_lock_on     = led_state.num_lock;
    return true;
}

void led_set_user(uint8_t usb_led) {
}

#ifdef WIDE_LAYOUT
#include "layouts/wide_layout.c"
#else
#include "layouts/narrow_layout.c"
#endif
