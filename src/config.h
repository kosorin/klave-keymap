#pragma once

// Unused pins:
// - D0 (SCL) - used for SOFT_SERIAL_PIN
// - D1 (SDA)
// - D2
// - D3

// LEDs
// - B0 Left
// - D5 Right
// writePinHigh(D5) - turn off
// writePinLow(D5) - turn on

// Matrix
#define MATRIX_ROWS (6*2)
#define MATRIX_COLS (6)
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }
#define MATRIX_ROW_PINS { B6, B2, B3, B1, F7, F6 }
#define DIODE_DIRECTION COL2ROW

// Rotary encoder
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTIONS { 2 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { F4 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }

// Communication
#define SOFT_SERIAL_PIN D0

// Handedness
#define EE_HANDS

// Debounce
#define DEBOUNCE 5
