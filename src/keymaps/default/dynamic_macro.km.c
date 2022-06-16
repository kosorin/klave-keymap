#include <stdbool.h>


bool dynamic_macro_recording = false;


void dynamic_macro_record_start_user(void) {
    dynamic_macro_recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    dynamic_macro_recording = false;
}
