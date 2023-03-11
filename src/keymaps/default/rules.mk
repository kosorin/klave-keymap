# HW feature options
ENCODER_ENABLE = no
OLED_ENABLE = no

# Base SW feature options
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = no

# SW feature options
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
SWAP_HANDS_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Custom SW feature options
SWITCHER_ENABLE = yes
CUSTOM_UNICODE_ENABLE = yes
KEY_CHAIN_ENABLE = yes
SECRETS_ENABLE = yes
USER_CONFIG_ENABLE = no
GAMING_ENABLE = no



# Custom SW feature options
SWITCHER_ENABLE ?= no
ifeq ($(strip $(SWITCHER_ENABLE)), yes)
    OPT_DEFS += -DSWITCHER_ENABLE
endif

CUSTOM_UNICODE_ENABLE ?= no
ifeq ($(strip $(CUSTOM_UNICODE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/uc.c
    OPT_DEFS += -DCUSTOM_UNICODE_ENABLE
    UNICODE_ENABLE := no
    UNICODEMAP_ENABLE := no
    UCIS_ENABLE := no
    UNICODE_COMMON := yes
endif

KEY_CHAIN_ENABLE ?= no
ifeq ($(strip $(KEY_CHAIN_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/key_chain.c
    SRC += $(KEYMAP_PATH)/key_chain.c
    OPT_DEFS += -DKEY_CHAIN_ENABLE
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

USER_CONFIG_ENABLE ?= no
ifeq ($(strip $(USER_CONFIG_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/user_config.c
    OPT_DEFS += -DUSER_CONFIG_ENABLE
endif

GAMING_ENABLE ?= no
ifeq ($(strip $(GAMING_ENABLE)), yes)
    OPT_DEFS += -DGAMING_ENABLE
endif


# SW feature options
CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/smart_case.c
endif

COMBO_ENABLE ?= no
ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/combos.c
endif

DYNAMIC_MACRO_ENABLE ?= no
ifeq ($(strip $(DYNAMIC_MACRO_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/dyn_macro.c
endif

TAP_DANCE_ENABLE ?= no
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/tap_dances.c
endif


# Other definitions
OPT_DEFS += -DPROCESS_HANDLED=false -DPROCESS_NOT_HANDLED=true
