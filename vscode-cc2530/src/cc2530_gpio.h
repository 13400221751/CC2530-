#ifndef CC2530_GPIO_H
#define CC2530_GPIO_H

#include "cc2530_regs.h"

typedef enum cc2530_port_id {
  CC2530_PORT_0 = 0,
  CC2530_PORT_1 = 1,
  CC2530_PORT_2 = 2
} cc2530_port_id_t;

void cc2530_gpio_set_output(cc2530_port_id_t port, unsigned char mask);
void cc2530_gpio_set_input(cc2530_port_id_t port, unsigned char mask);
void cc2530_gpio_write_low(cc2530_port_id_t port, unsigned char mask);
void cc2530_gpio_write_high(cc2530_port_id_t port, unsigned char mask);
void cc2530_gpio_select_gpio_function(cc2530_port_id_t port, unsigned char mask);
unsigned char cc2530_gpio_read(cc2530_port_id_t port, unsigned char mask);

#endif
