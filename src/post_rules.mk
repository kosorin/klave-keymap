
CUSTOM_LEADER_ENABLE ?= no
ifeq ($(strip $(CUSTOM_LEADER_ENABLE)), yes)
	LEADER_ENABLE = no
    OPT_DEFS += -DCUSTOM_LEADER_ENABLE
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif
