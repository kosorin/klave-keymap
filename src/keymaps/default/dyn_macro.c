#include "dyn_macro.h"
#include <stdint.h>
#include "gpio.h"
#include "action.h"
#include "wait.h"


static bool dynamic_macro_recording = false;


bool is_dynamic_macro_recording(void) {
    return dynamic_macro_recording;
}

void dynamic_macro_record_start_user(int8_t direction) {
    dynamic_macro_recording = true;

    writePinLow(B0);
    wait_ms(500);
    writePinHigh(B0);
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro_recording = false;

    writePinLow(B0);
    wait_ms(200);
    writePinHigh(B0);
    wait_ms(200);
    writePinLow(B0);
    wait_ms(200);
    writePinHigh(B0);
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    writePinLow(B0);
    wait_ms(50);
    writePinHigh(B0);

    writePinLow(D5);
    wait_ms(50);
    writePinHigh(D5);

    writePinLow(B0);
    wait_ms(50);
    writePinHigh(B0);

    writePinLow(D5);
    wait_ms(50);
    writePinHigh(D5);
}
