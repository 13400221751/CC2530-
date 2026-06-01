#ifndef CC2530_LED_H
#define CC2530_LED_H

#include "cc2530_gpio.h"

typedef struct cc2530_led {
  cc2530_port_id_t port;
  unsigned char mask;
} cc2530_led_t;

void cc2530_led_init_open_drain(const cc2530_led_t *led);
void cc2530_led_write(const cc2530_led_t *led, unsigned char on);
void cc2530_led_toggle(const cc2530_led_t *led, unsigned char *state);

#endif
