#include "cc2530_system.h"

void cc2530_system_delay_cycles(unsigned long cycles)
{
  while (cycles-- > 0u) {
    __no_operation();
  }
}

void cc2530_system_clock_use_32mhz_xosc(void)
{
  CLKCONCMD &= (unsigned char)~CC2530_CLKCON_OSC_BIT;
  while (CLKCONSTA & CC2530_CLKCON_OSC_BIT) {
  }
}
