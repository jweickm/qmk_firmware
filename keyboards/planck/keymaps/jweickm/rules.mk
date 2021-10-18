CONSOLE_ENABLE = no         # Console for debug
LEADER_ENABLE = yes 		# enable leader key functionality
TAP_DANCE_ENABLE = yes		# enable tap dance functionality
DYNAMIC_MACRO_ENABLE = yes 	# QMK support for temporary macros
COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes

SRC += muse.c

#ifdef NAGINATA_ENABLE 		# enabled in config.h
UNICODE_ENABLE = yes 		# UNICODE SUPPORT, using Wincompose under Windows
SRC += naginata_v14.c
#endif
