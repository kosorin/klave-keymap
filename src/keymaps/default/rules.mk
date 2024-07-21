# Base SW feature options
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = no

# SW feature options
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = yes

# Custom SW feature options
CUSTOM_UNICODE_ENABLE = yes
COURSE_ENABLE = yes
SECRETS_ENABLE = yes
GAMING_ENABLE = no



# Custom SW feature options
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
    SRC += $(KEYMAP_PATH)/course.c
    OPT_DEFS += -DCOURSE_ENABLE
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

GAMING_ENABLE ?= no
ifeq ($(strip $(GAMING_ENABLE)), yes)
    OPT_DEFS += -DGAMING_ENABLE
endif


# SW feature options
CAPS_WORD_ENABLE ?= no
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/smart_case.c
endif

DYNAMIC_MACRO_ENABLE ?= no
ifeq ($(strip $(DYNAMIC_MACRO_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/dyn_macro.c
endif

TAP_DANCE_ENABLE ?= no
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += $(KEYMAP_PATH)/features/tap_dance.c
endif


# Other definitions
OPT_DEFS += -DPROCESS_HANDLED=false -DPROCESS_NOT_HANDLED=true
