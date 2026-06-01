#ifndef CC2530_CAR4WD_H
#define CC2530_CAR4WD_H

#include "cc2530_l298n.h"

typedef struct cc2530_car4wd {
  const cc2530_l298n_channel_t *front_left;
  const cc2530_l298n_channel_t *front_right;
  const cc2530_l298n_channel_t *rear_left;
  const cc2530_l298n_channel_t *rear_right;
} cc2530_car4wd_t;

void cc2530_car4wd_init(const cc2530_car4wd_t *car);
void cc2530_car4wd_stop(const cc2530_car4wd_t *car);
void cc2530_car4wd_brake(const cc2530_car4wd_t *car);
void cc2530_car4wd_forward(const cc2530_car4wd_t *car);
void cc2530_car4wd_backward(const cc2530_car4wd_t *car);
void cc2530_car4wd_turn_left(const cc2530_car4wd_t *car);
void cc2530_car4wd_turn_right(const cc2530_car4wd_t *car);
void cc2530_car4wd_pivot_left(const cc2530_car4wd_t *car);
void cc2530_car4wd_pivot_right(const cc2530_car4wd_t *car);

#endif
