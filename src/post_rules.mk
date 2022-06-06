SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

CUSTOM_LEADER_ENABLE ?= no
ifeq ($(strip $(CUSTOM_LEADER_ENABLE)), yes)
	LEADER_ENABLE = no
    OPT_DEFS += -DCUSTOM_LEADER_ENABLE
endif

USER_CONFIG_ENABLE ?= no
ifeq ($(strip $(USER_CONFIG_ENABLE)), yes)
    OPT_DEFS += -DUSER_CONFIG_ENABLE
endif
