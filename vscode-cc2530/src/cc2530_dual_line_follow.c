#include "cc2530_dual_line_follow.h"

static const cc2530_line4_config_t *cc2530_dual_line_follow_select_sensor(
    const cc2530_dual_line_follow_t *follow,
    cc2530_motion_direction_t direction)
{
  return (direction == CC2530_MOTION_FORWARD) ? follow->forward_sensor : follow->backward_sensor;
}

static cc2530_follow_command_t cc2530_dual_line_follow_pattern_to_command(
    cc2530_motion_direction_t direction,
    cc2530_line4_pattern_t pattern)
{
  switch (pattern) {
    case CC2530_LINE4_PATTERN_CENTER:
      return (direction == CC2530_MOTION_FORWARD) ? CC2530_FOLLOW_FORWARD : CC2530_FOLLOW_BACKWARD;
    case CC2530_LINE4_PATTERN_SLIGHT_LEFT:
      return CC2530_FOLLOW_TURN_LEFT;
    case CC2530_LINE4_PATTERN_SLIGHT_RIGHT:
      return CC2530_FOLLOW_TURN_RIGHT;
    case CC2530_LINE4_PATTERN_HARD_LEFT:
      return CC2530_FOLLOW_HARD_LEFT;
    case CC2530_LINE4_PATTERN_HARD_RIGHT:
      return CC2530_FOLLOW_HARD_RIGHT;
    case CC2530_LINE4_PATTERN_NONE:
      return CC2530_FOLLOW_SEARCH;
    case CC2530_LINE4_PATTERN_CROSS:
    case CC2530_LINE4_PATTERN_WIDE:
    default:
      return (direction == CC2530_MOTION_FORWARD) ? CC2530_FOLLOW_FORWARD : CC2530_FOLLOW_BACKWARD;
  }
}

void cc2530_dual_line_follow_init(const cc2530_dual_line_follow_t *follow)
{
  cc2530_line4_init(follow->forward_sensor);
  cc2530_line4_init(follow->backward_sensor);
}

void cc2530_dual_line_follow_read(const cc2530_dual_line_follow_t *follow,
                                  cc2530_motion_direction_t direction,
                                  cc2530_dual_line_result_t *result)
{
  const cc2530_line4_config_t *sensor = cc2530_dual_line_follow_select_sensor(follow, direction);

  result->direction = direction;
  cc2530_line4_read_all(sensor, &result->sample);
  result->pattern = cc2530_line4_classify(&result->sample);
  result->command = cc2530_dual_line_follow_pattern_to_command(direction, result->pattern);
}
