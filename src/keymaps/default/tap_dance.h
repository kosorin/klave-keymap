#pragma once

enum tap_dance {
#if defined(SECRETS_ENABLE)
    TD_SECRET1,
    TD_SECRET2,
    TD_SECRET3,
    TD_SECRET4,
    TD_SECRET5,
    TD_SECRET6,
    TD_SECRET7,
    TD_SECRET8,
    TD_SECRET9,
    TD_SECRET10,
    TD_SECRET11,
    TD_SECRET12,
#endif
#if defined(COURSE_ENABLE)
    TD_SYSTEM_COURSE,
#endif
    TD_DECIMAL_POINT,
    tap_dance_COUNT,
};
