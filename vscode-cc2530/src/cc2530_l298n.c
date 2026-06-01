#include "cc2530_l298n.h"

static void cc2530_l298n_pin_make_output(const cc2530_gpio_pin_t *pin)
{
  cc2530_gpio_select_gpio_function(pin->port, pin->mask);
  cc2530_gpio_set_output(pin->port, pin->mask);
}

static void cc2530_l298n_pin_write(const cc2530_gpio_pin_t *pin, unsigned char high)
{
  if (high) {
    cc2530_gpio_write_high(pin->port, pin->mask);
  } else {
    cc2530_gpio_write_low(pin->port, pin->mask);
  }
}

void cc2530_l298n_channel_init(const cc2530_l298n_channel_t *channel)
{
  cc2530_l298n_pin_make_output(&channel->in1);
  cc2530_l298n_pin_make_output(&channel->in2);

  if (channel->has_enable) {
    cc2530_l298n_pin_make_output(&channel->en);
    cc2530_l298n_pin_write(&channel->en, 1u);
  }

  cc2530_l298n_channel_set_direction(channel, CC2530_MOTOR_COAST);
}

void cc2530_l298n_channel_set_direction(const cc2530_l298n_channel_t *channel,
                                        cc2530_motor_direction_t direction)
{
  switch (direction) {
    case CC2530_MOTOR_FORWARD:
      cc2530_l298n_pin_write(&channel->in1, 1u);
      cc2530_l298n_pin_write(&channel->in2, 0u);
      break;
    case CC2530_MOTOR_BACKWARD:
      cc2530_l298n_pin_write(&channel->in1, 0u);
      cc2530_l298n_pin_write(&channel->in2, 1u);
      break;
    case CC2530_MOTOR_BRAKE:
      cc2530_l298n_pin_write(&channel->in1, 1u);
      cc2530_l298n_pin_write(&channel->in2, 1u);
      break;
    case CC2530_MOTOR_COAST:
    default:
      cc2530_l298n_pin_write(&channel->in1, 0u);
      cc2530_l298n_pin_write(&channel->in2, 0u);
      break;
  }
}

void cc2530_l298n_driver_init(const cc2530_l298n_driver_t *driver)
{
  cc2530_l298n_channel_init(&driver->channel_a);
  cc2530_l298n_channel_init(&driver->channel_b);
}

void cc2530_l298n_driver_stop(const cc2530_l298n_driver_t *driver)
{
  cc2530_l298n_channel_set_direction(&driver->channel_a, CC2530_MOTOR_COAST);
  cc2530_l298n_channel_set_direction(&driver->channel_b, CC2530_MOTOR_COAST);
}
