BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
COMMAND_ENABLE = no        # Commands for debug and configuration
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
UNICODE_ENABLE = no        # Unicode
LEADER_ENABLE = yes 		# enable leader key functionality
DYNAMIC_MACRO_ENABLE = yes 	# QMK support for temporary macros

TAP_DANCE_ENABLE = yes		# enable tap dance functionality
COMBO_ENABLE = yes 			# Enable Keyboard Combos 1,764 bytes
VPATH += keyboards/gboards/ # Enable gboard combo engine

# LOCKING_SUPPORT_ENABLE 	= no
# LOCKING_RESYNC_ENABLE	= no
# NO_DEBUG				= yes
# NO_PRING				= yes

#ifdef ACHORDION
SRC += features/getreuer/achordion.c # add the achordion feature
#endif

# reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

# Disable unsupported hardware
# AUDIO_SUPPORTED = no
# BACKLIGHT_SUPPORTED = no

LAYOUTS = ortho_4x12 planck_mit
