# Build options
LTO_ENABLE = yes

# HW feature options
ENCODER_ENABLE = yes
OLED_ENABLE = yes

# Base SW feature options
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = no

# SW feature options
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_LOCK_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = yes
UNICODEMAP_ENABLE = yes

# Custom SW feature options
KEY_CHAIN_ENABLE = yes
SECRETS_ENABLE = yes
USER_CONFIG_ENABLE = no



ENCODER_ENABLE ?= no
ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/encoder.km.c
endif

OLED_ENABLE ?= no
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/oled.km.c
endif


KEY_CHAIN_ENABLE ?= no
ifeq ($(strip $(KEY_CHAIN_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/key_chain.f.c
    SRC += $(KEYMAP_PATH)/key_chain.km.c
    OPT_DEFS += -DKEY_CHAIN_ENABLE
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/secrets.km.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

USER_CONFIG_ENABLE ?= no
ifeq ($(strip $(USER_CONFIG_ENABLE)), yes)
    OPT_DEFS += -DUSER_CONFIG_ENABLE
endif


CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/caps_word.km.c
endif

COMBO_ENABLE ?= no
ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/combo.km.c
endif

DYNAMIC_MACRO_ENABLE ?= no
ifeq ($(strip $(DYNAMIC_MACRO_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/dynamic_macro.km.c
endif

KEY_OVERRIDE_ENABLE ?= no
ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/key_override.km.c
endif

TAP_DANCE_ENABLE ?= no
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/tap_dance.km.c
endif

UNICODEMAP_ENABLE ?= no
ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/unicode_map.km.c
endif
