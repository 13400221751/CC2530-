#ifndef CC2530_L298N_H
#define CC2530_L298N_H

#include "cc2530_gpio.h"

typedef struct cc2530_gpio_pin {
  cc2530_port_id_t port;
  unsigned char mask;
} cc2530_gpio_pin_t;

typedef enum cc2530_motor_direction {
  CC2530_MOTOR_COAST = 0,
  CC2530_MOTOR_FORWARD,
  CC2530_MOTOR_BACKWARD,
  CC2530_MOTOR_BRAKE
} cc2530_motor_direction_t;

typedef struct cc2530_l298n_channel {
  cc2530_gpio_pin_t in1;
  cc2530_gpio_pin_t in2;
  cc2530_gpio_pin_t en;
  unsigned char has_enable;
} cc2530_l298n_channel_t;

typedef struct cc2530_l298n_driver {
  cc2530_l298n_channel_t channel_a;
  cc2530_l298n_channel_t channel_b;
} cc2530_l298n_driver_t;

void cc2530_l298n_channel_init(const cc2530_l298n_channel_t *channel);
void cc2530_l298n_channel_set_direction(const cc2530_l298n_channel_t *channel,
                                        cc2530_motor_direction_t direction);
void cc2530_l298n_driver_init(const cc2530_l298n_driver_t *driver);
void cc2530_l298n_driver_stop(const cc2530_l298n_driver_t *driver);

#endif
