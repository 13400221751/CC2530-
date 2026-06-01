#ifndef CC2530_SYSTEM_H
#define CC2530_SYSTEM_H

#include "cc2530_regs.h"

void cc2530_system_delay_cycles(unsigned long cycles);
void cc2530_system_clock_use_32mhz_xosc(void);

#endif
