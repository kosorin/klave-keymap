#include "dynamic_macro.km.h"


static bool dynamic_macro_recording = false;


bool is_dynamic_macro_recording(void) {
    return dynamic_macro_recording;
}

void dynamic_macro_record_start_user(void) {
    dynamic_macro_recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro_recording = false;
}
