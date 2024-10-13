# QMK features
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = yes
OS_DETECTION_ENABLE = yes

# Custom features
CUSTOM_UNICODE_ENABLE = yes
COURSE_ENABLE = yes
SECRETS_ENABLE = yes
GAMING_ENABLE = no

# Other definitions
OPT_DEFS += -DPROCESS_HANDLED=false -DPROCESS_NOT_HANDLED=true

# Configure all features
CUSTOM_UNICODE_ENABLE ?= no
ifeq ($(strip $(CUSTOM_UNICODE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/custom_unicode.c
    OPT_DEFS += -DCUSTOM_UNICODE_ENABLE
    UNICODE_ENABLE := no
    UNICODEMAP_ENABLE := no
    UCIS_ENABLE := no
    UNICODE_COMMON := yes
endif

COURSE_ENABLE ?= no
ifeq ($(strip $(COURSE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/course.c
    OPT_DEFS += -DCOURSE_ENABLE
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/keymap_secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

GAMING_ENABLE ?= no
ifeq ($(strip $(GAMING_ENABLE)), yes)
    OPT_DEFS += -DGAMING_ENABLE
endif

CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/smart_case.c
endif

TAP_DANCE_ENABLE ?= no
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/tap_dance.c
endif
