#include "cc2530_gpio.h"

void cc2530_gpio_set_output(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      P0DIR |= mask;
      break;
    case CC2530_PORT_1:
      P1DIR |= mask;
      break;
    default:
      P2DIR |= mask;
      break;
  }
}

void cc2530_gpio_set_input(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      P0DIR &= (unsigned char)~mask;
      break;
    case CC2530_PORT_1:
      P1DIR &= (unsigned char)~mask;
      break;
    default:
      P2DIR &= (unsigned char)~mask;
      break;
  }
}

void cc2530_gpio_write_low(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      P0 &= (unsigned char)~mask;
      break;
    case CC2530_PORT_1:
      P1 &= (unsigned char)~mask;
      break;
    default:
      P2 &= (unsigned char)~mask;
      break;
  }
}

void cc2530_gpio_write_high(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      P0 |= mask;
      break;
    case CC2530_PORT_1:
      P1 |= mask;
      break;
    default:
      P2 |= mask;
      break;
  }
}

void cc2530_gpio_select_gpio_function(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      P0SEL &= (unsigned char)~mask;
      break;
    case CC2530_PORT_1:
      P1SEL &= (unsigned char)~mask;
      break;
    default:
      P2SEL &= (unsigned char)~mask;
      break;
  }
}

unsigned char cc2530_gpio_read(cc2530_port_id_t port, unsigned char mask)
{
  switch (port) {
    case CC2530_PORT_0:
      return (unsigned char)(P0 & mask);
    case CC2530_PORT_1:
      return (unsigned char)(P1 & mask);
    default:
      return (unsigned char)(P2 & mask);
  }
}
