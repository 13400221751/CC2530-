#ifndef CC2530_UART0_H
#define CC2530_UART0_H

#include "cc2530_gpio.h"

typedef struct cc2530_uart0_config {
  unsigned char baud_m;
  unsigned char baud_e;
} cc2530_uart0_config_t;

void cc2530_uart0_init(const cc2530_uart0_config_t *config);
void cc2530_uart0_write_byte(unsigned char value);
void cc2530_uart0_write_string(const char *text);
unsigned char cc2530_uart0_rx_ready(void);
unsigned char cc2530_uart0_read_byte(void);

#endif
