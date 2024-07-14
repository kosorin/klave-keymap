#include "dyn_macro.h"
#include "promicro_led.h"
#include <stdint.h>
#include "action.h"


static bool dynamic_macro_recording = false;


bool is_dynamic_macro_recording(void) {
    return dynamic_macro_recording;
}

void dynamic_macro_record_start_user(int8_t direction) {
    dynamic_macro_recording = true;

    led_blink_main(500, 1);
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro_recording = false;

    led_blink_main(200, 2);
}
