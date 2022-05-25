MOUSEKEY_ENABLE 	= yes
COMMAND_ENABLE		= no
RGBLIGHT_ENABLE		= no
UNICODE_ENABLE		= no
LEADER_ENABLE 		= yes
TAP_DANCE_ENABLE	= yes
COMBO_ENABLE 		= yes
VPATH				+= keyboards/gboards/

#ifdef ACHORDION
SRC += features/achordion.c
#endif

#reduce firmware size by enabling link time optimization
EXTRAFLAGS += -flto

