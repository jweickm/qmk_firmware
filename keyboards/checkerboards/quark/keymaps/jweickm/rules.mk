MOUSEKEY_ENABLE 	= yes
COMMAND_ENABLE		= no
CONSOLE_ENABLE 		= no        # Console for debug
RGBLIGHT_ENABLE		= no
UNICODE_ENABLE		= no
LEADER_ENABLE 		= no
TAP_DANCE_ENABLE	= no
NKRO_ENABLE			= no	# 334 bytes
DYNAMIC_MACRO_ENABLE = no 	# QMK support for temporary macros
KEY_LOCK_ENABLE 	= no    # enables the use of KC_LOCK
CAPS_WORD_ENABLE 	= yes	# 446 bytes
SPACE_CADET_ENABLE 	= no
GRAVE_ESC_ENABLE 	= no
SEND_STRING_ENABLE  = no 		# Disable the String sending functionality to save space

COMBO_ENABLE 		= yes
VPATH				+= keyboards/gboards/

#ifdef ACHORDION
SRC += features/getreuer/achordion.c # use older version saved locally
SRC += features/getreuer/layer_lock.c
#endif

#reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

