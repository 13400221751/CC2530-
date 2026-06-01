#include "cc2530_led.h"

void cc2530_led_init_open_drain(const cc2530_led_t *led)
{
  cc2530_gpio_select_gpio_function(led->port, led->mask);
  cc2530_gpio_write_low(led->port, led->mask);
  cc2530_gpio_set_input(led->port, led->mask);
}

void cc2530_led_write(const cc2530_led_t *led, unsigned char on)
{
  if (on) {
    cc2530_gpio_write_low(led->port, led->mask);
    cc2530_gpio_set_output(led->port, led->mask);
  } else {
    cc2530_gpio_set_input(led->port, led->mask);
  }
}

void cc2530_led_toggle(const cc2530_led_t *led, unsigned char *state)
{
  *state ^= led->mask;
  cc2530_led_write(led, (unsigned char)(*state & led->mask));
}
