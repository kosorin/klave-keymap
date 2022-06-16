#pragma once


typedef union {
    uint32_t raw;
    struct {
    };
} user_config_t;

extern user_config_t user_config;
