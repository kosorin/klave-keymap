#pragma once

#include <stdint.h>
#include "action.h"

// ========================================================================== //
// Course
// ========================================================================== //
#if defined(COURSE_ENABLE)
#include "features/course.h"

DEFINE_COURSE_HANDLER(secret);

#endif

// ========================================================================== //
// Tap Dance
// ========================================================================== //
#if defined(TAP_DANCE_ENABLE)
#include "process_tap_dance.h"

void tap_dance_secret1(tap_dance_state_t *state, void *user_data);
void tap_dance_secret2(tap_dance_state_t *state, void *user_data);
void tap_dance_secret3(tap_dance_state_t *state, void *user_data);
void tap_dance_secret4(tap_dance_state_t *state, void *user_data);
void tap_dance_secret5(tap_dance_state_t *state, void *user_data);
void tap_dance_secret6(tap_dance_state_t *state, void *user_data);
void tap_dance_secret7(tap_dance_state_t *state, void *user_data);
void tap_dance_secret8(tap_dance_state_t *state, void *user_data);
void tap_dance_secret9(tap_dance_state_t *state, void *user_data);
void tap_dance_secret10(tap_dance_state_t *state, void *user_data);
void tap_dance_secret11(tap_dance_state_t *state, void *user_data);
void tap_dance_secret12(tap_dance_state_t *state, void *user_data);

#endif
