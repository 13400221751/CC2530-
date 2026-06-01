#include "cc2530_car4wd.h"

static void cc2530_car4wd_set_left(const cc2530_car4wd_t *car, cc2530_motor_direction_t direction)
{
  cc2530_l298n_channel_set_direction(car->front_left, direction);
  cc2530_l298n_channel_set_direction(car->rear_left, direction);
}

static void cc2530_car4wd_set_right(const cc2530_car4wd_t *car, cc2530_motor_direction_t direction)
{
  cc2530_l298n_channel_set_direction(car->front_right, direction);
  cc2530_l298n_channel_set_direction(car->rear_right, direction);
}

void cc2530_car4wd_init(const cc2530_car4wd_t *car)
{
  cc2530_l298n_channel_init(car->front_left);
  cc2530_l298n_channel_init(car->front_right);
  cc2530_l298n_channel_init(car->rear_left);
  cc2530_l298n_channel_init(car->rear_right);
}

void cc2530_car4wd_stop(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_COAST);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_COAST);
}

void cc2530_car4wd_brake(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_BRAKE);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_BRAKE);
}

void cc2530_car4wd_forward(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_FORWARD);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_FORWARD);
}

void cc2530_car4wd_backward(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_BACKWARD);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_BACKWARD);
}

void cc2530_car4wd_turn_left(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_COAST);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_FORWARD);
}

void cc2530_car4wd_turn_right(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_FORWARD);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_COAST);
}

void cc2530_car4wd_pivot_left(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_BACKWARD);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_FORWARD);
}

void cc2530_car4wd_pivot_right(const cc2530_car4wd_t *car)
{
  cc2530_car4wd_set_left(car, CC2530_MOTOR_FORWARD);
  cc2530_car4wd_set_right(car, CC2530_MOTOR_BACKWARD);
}
