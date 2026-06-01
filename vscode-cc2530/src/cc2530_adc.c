#include "cc2530_adc.h"

unsigned int cc2530_adc_read_once(unsigned char channel)
{
  unsigned char low;
  unsigned char high;

  ADCCON3 = (unsigned char)(0x30u | (channel & 0x0Fu));
  while ((ADCCON1 & CC2530_ADCCON1_EOC_BIT) == 0u) {
  }
  low = ADCL;
  high = ADCH;
  return (unsigned int)(((unsigned int)high << 8) | low);
}

unsigned int cc2530_random16(void)
{
  unsigned char low = RNDL;
  unsigned char high = RNDH;
  return (unsigned int)(((unsigned int)high << 8) | low);
}
