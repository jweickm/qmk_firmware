# MCU name
MCU = atmega32u2

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = no        # Unicode
LEADER_ENABLE = yes 		# enable leader key functionality
DYNAMIC_MACRO_ENABLE = yes 	# QMK support for temporary macros
MIDI_ENABLE = no			# MIDI output

TAP_DANCE_ENABLE = yes		# enable tap dance functionality
COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes
VPATH += keyboards/gboards/ # Enable gboard combo engine

LOCKING_SUPPORT_ENABLE 	= no
LOCKING_RESYNC_ENABLE	= no
NO_DEBUG				= yes
NO_PRING				= yes

#ifdef ACHORDION
SRC += features/getreuer/achordion.c # add the achordion feature
#endif

# reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

LAYOUTS = ortho_4x12 planck_mit
