#ifndef CC2530_DUAL_LINE_FOLLOW_H
#define CC2530_DUAL_LINE_FOLLOW_H

#include "cc2530_line4.h"

typedef enum cc2530_motion_direction {
  CC2530_MOTION_FORWARD = 0,
  CC2530_MOTION_BACKWARD = 1
} cc2530_motion_direction_t;

typedef enum cc2530_follow_command {
  CC2530_FOLLOW_STOP = 0,
  CC2530_FOLLOW_FORWARD,
  CC2530_FOLLOW_BACKWARD,
  CC2530_FOLLOW_TURN_LEFT,
  CC2530_FOLLOW_TURN_RIGHT,
  CC2530_FOLLOW_HARD_LEFT,
  CC2530_FOLLOW_HARD_RIGHT,
  CC2530_FOLLOW_SEARCH
} cc2530_follow_command_t;

typedef struct cc2530_dual_line_follow {
  const cc2530_line4_config_t *forward_sensor;
  const cc2530_line4_config_t *backward_sensor;
} cc2530_dual_line_follow_t;

typedef struct cc2530_dual_line_result {
  cc2530_motion_direction_t direction;
  cc2530_line4_sample_t sample;
  cc2530_line4_pattern_t pattern;
  cc2530_follow_command_t command;
} cc2530_dual_line_result_t;

void cc2530_dual_line_follow_init(const cc2530_dual_line_follow_t *follow);
void cc2530_dual_line_follow_read(const cc2530_dual_line_follow_t *follow,
                                  cc2530_motion_direction_t direction,
                                  cc2530_dual_line_result_t *result);

#endif
