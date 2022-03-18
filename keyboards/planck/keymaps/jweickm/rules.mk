CONSOLE_ENABLE = no         # Console for debug
LEADER_ENABLE = yes 		# enable leader key functionality
TAP_DANCE_ENABLE = yes		# enable tap dance functionality
DYNAMIC_MACRO_ENABLE = yes 	# QMK support for temporary macros
SRC += muse.c
COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes
KEY_OVERRIDE_ENABLE = yes 	# Enable key override functionality
NKRO = yes 					# Enable n-key rollover

#ifdef NAGINATA_ENABLE 		# enabled in config.h
SRC += naginata_v14.c
#endif

#ifdef UNICODE_SELECTED_MODES 
#UNICODEMAP_ENABLE = yes 	# Enables unicode map
#endif
