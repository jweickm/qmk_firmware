CONSOLE_ENABLE = no         # Console for debug
LEADER_ENABLE = yes 		# enable leader key functionality
TAP_DANCE_ENABLE = yes		# enable tap dance functionality
DYNAMIC_MACRO_ENABLE = yes 	# QMK support for temporary macros
KEY_OVERRIDE_ENABLE = yes 	# Enable key override functionality
NKRO = yes 					# Enable n-key rollover
BOOTMAGIC_ENABLE = no		# Enable Bootmagic
COMMAND_ENABLE = no			# Disable Command/Magic 
UNICODE_ENABLE = no
MIDI_ENABLE = no
AUDIO_ENABLE = yes
SWAP_HANDS_ENABLE = no 		# Allow swapping hands of keyboard

# SRC += muse.c

COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes
VPATH += keyboards/gboards/ # Enable gboard combo engine

#ifdef ACHORDION
SRC += features/getreuer/achordion.c # add the achordion feature
#endif

#ifdef NAGINATA_ENABLE 		# enabled in config.h
SRC += features/naginata/naginata_v14.c
#endif

#ifdef UNICODE_SELECTED_MODES 
#UNICODEMAP_ENABLE = yes 	# Enables unicode map
#endif

# reduce firmware size by enabling link time optimization
# EXTRAFLAGS += -flto
