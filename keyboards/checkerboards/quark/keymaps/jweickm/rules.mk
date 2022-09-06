MOUSEKEY_ENABLE 	= yes
COMMAND_ENABLE		= no
RGBLIGHT_ENABLE		= no
UNICODE_ENABLE		= no
LEADER_ENABLE 		= no
TAP_DANCE_ENABLE	= yes
NKRO_ENABLE			= no	# 334 bytes
DYNAMIC_MACRO_ENABLE = no 	# QMK support for temporary macros
KEY_LOCK_ENABLE 	= no    # enables the use of KC_LOCK
CAPS_WORD_ENABLE 	= yes	# 446 bytes
SPACE_CADET_ENABLE 	= no
GRAVE_ESC_ENABLE 	= no

COMBO_ENABLE 		= yes
VPATH				+= keyboards/gboards/

#ifdef ACHORDION
SRC += features/achordion.c
SRC += features/layer_lock.c
#endif

#reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

