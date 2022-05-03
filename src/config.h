#pragma once

#include "config_common.h"

// Device
#define VENDOR_ID 0xACDC
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0001
#define MANUFACTURER David Kosorin
#define PRODUCT Klave

// Matrix
#define MATRIX_ROWS (6*2)
#define MATRIX_COLS (6)
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7, F6 }
#define UNUSED_PINS { D2, D3 }
#define DIODE_DIRECTION COL2ROW

// Rotary encoder
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { F4 }
#define ENCODER_RESOLUTION 2
#define ENCODER_INDEX_LEFT 0
#define ENCODER_INDEX_RIGHT 1

// Communication
#define USE_I2C

// Debounce
#define DEBOUNCE 5

// Handedness
#define EE_HANDS
