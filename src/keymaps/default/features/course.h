// Modified version of https://github.com/andrewjrae/kyria-keymap/blob/e3ad77dc4d48b8e6a842c9136c76c1021ab5976b/README.org#userspace-leader-sequences

#pragma once

#include "action.h"


#define COURSE_HANDLER(name) _course_handle_##name
#define DEFINE_COURSE_HANDLER(name) void *COURSE_HANDLER(name)(uint8_t keycode)

typedef void *(*course_handler_t)(uint8_t keycode);


bool process_course(uint16_t keycode, const keyrecord_t *record);
bool is_course_active(void);
void course_start(course_handler_t handler);
void course_stop(void);

course_handler_t course_done(void);
course_handler_t course_cancel(void);
course_handler_t course_bad_key(void);
course_handler_t course_again(void);

DEFINE_COURSE_HANDLER(main);
