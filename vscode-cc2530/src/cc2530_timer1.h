#ifndef CC2530_TIMER1_H
#define CC2530_TIMER1_H

#include "cc2530_regs.h"

void cc2530_timer1_start_free_running(void);
unsigned int cc2530_timer1_get_count(void);
void cc2530_timer1_delay_ticks(unsigned int ticks);

#endif
