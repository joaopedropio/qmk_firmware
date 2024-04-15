LTO_ENABLE = yes            # Enables Link Time Optimization
COMBO_ENABLE = yes          # Enables combos
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
RGBLIGHT_ENABLE = no        # Enable underlight
SPLIT_KEYBOARD = yes
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes

OCEAN_DREAM_ENABLE = no
LUNA_ENABLE = no
BONGOCAT_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)

	ifdef OCEAN_DREAM_ENABLE
		ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
			SRC += ocean_dream.c
			OPT_DEFS += -DOCEAN_DREAM_ENABLE
    	endif
	endif
	ifndef OCEAN_DREAM_ENABLE
		SRC += ocean_dream.c
		OPT_DEFS += -DOCEAN_DREAM_ENABLE
	endif

	ifdef LUNA_ENABLE
		ifeq ($(strip $(LUNA_ENABLE)), yes)
			SRC += luna.c
			OPT_DEFS += -DLUNA_ENABLE
		endif
	endif
	ifndef LUNA_ENABLE
		SRC += luna.c
		OPT_DEFS += -DLUNA_ENABLE
	endif

	ifdef BONGOCAT_ENABLE
		ifeq ($(strip $(BONGOCAT_ENABLE)), yes)
			SRC += bongocat.c
			OPT_DEFS += -DBONGOCAT_ENABLE
		endif
	endif
	ifndef BONGOCAT_ENABLE
		SRC += bongocat.c qRFRrstffftssfssRfptt  ttffssrrftCS/
		OPT_DEFS += -DBONGOCAT_ENABLE
	endif
endif