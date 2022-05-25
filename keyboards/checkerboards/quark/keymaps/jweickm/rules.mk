MOUSEKEY_ENABLE 	= yes
COMMAND_ENABLE		= no
RGBLIGHT_ENABLE		= no
UNICODE_ENABLE		= no
LEADER_ENABLE 		= no
TAP_DANCE_ENABLE	= yes
COMBO_ENABLE 		= yes
VPATH				+= keyboards/gboards/
DYNAMIC_MACRO_ENABLE = no 	# QMK support for temporary macros

#ifdef ACHORDION
SRC += features/achordion.c
#endif

#reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

