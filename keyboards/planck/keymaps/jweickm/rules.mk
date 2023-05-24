CONSOLE_ENABLE 		= no        # Console for debug
LEADER_ENABLE 		= no 		# enable leader key functionality, use espanso instead
TAP_DANCE_ENABLE 	= no		# enable tap dance functionality
DYNAMIC_MACRO_ENABLE = yes 		# QMK support for temporary macros
KEY_OVERRIDE_ENABLE = no 		# Enable key override functionality
NKRO 				= yes 		# Enable n-key rollover
BOOTMAGIC_ENABLE 	= no		# Enable Bootmagic
COMMAND_ENABLE 		= no		# Enable Command/Magic
MIDI_ENABLE 		= no		# MIDI output
AUDIO_ENABLE 		= no		# Enables audio features
RGBLIGHT_ENABLE 	= no		# Enables RGB backlight
SWAP_HANDS_ENABLE 	= no 		# Allow swapping hands of keyboard
CAPS_WORD_ENABLE	= yes   	# Enables caps word (use with CAPS_WORD keycode)
SPACE_CADET_ENABLE 	= no		# save space, never used this
GRAVE_ESC_ENABLE 	= no		# save space, never used this
SEND_STRING_ENABLE  = no 		# Disable the String sending functionality to save space
UNICODE_ENABLE 		= no		# Enable "direct" unicode output using Wincompose, requires SEND_STRING_ENABLE

# SRC += muse.c

COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes
VPATH += keyboards/gboards/ # Enable gboard combo engine

#ifdef ACHORDION
SRC += features/getreuer/achordion.c # add the achordion feature # using legacy version
SRC += features/getreuer/layer_lock.c # add the layer lock feature
SRC += features/getreuer/repeat_key.c # add the repeat key feature
#endif

#ifdef NAGINATA_ENABLE 		# enabled in config.h
# SRC += features/naginata/naginata_v14.c
#endif

#ifdef UNICODE_SELECTED_MODES
#UNICODEMAP_ENABLE = yes 	# Enables unicode map
#endif

# reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto
