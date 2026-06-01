#ifndef CC2530_ADC_H
#define CC2530_ADC_H

#include "cc2530_regs.h"

unsigned int cc2530_adc_read_once(unsigned char channel);
unsigned int cc2530_random16(void);

#endif
