#include "cc2530_timer1.h"

void cc2530_timer1_start_free_running(void)
{
  T1CTL = 0x00u;
  T1STAT = 0x00u;
  T1CNTL = 0x00u;
  T1CNTH = 0x00u;
  T1CTL = 0x01u;
}

unsigned int cc2530_timer1_get_count(void)
{
  unsigned char low;
  unsigned char high;

  low = T1CNTL;
  high = T1CNTH;

  return (unsigned int)(((unsigned int)high << 8) | low);
}

void cc2530_timer1_delay_ticks(unsigned int ticks)
{
  unsigned int start = cc2530_timer1_get_count();

  while ((unsigned int)(cc2530_timer1_get_count() - start) < ticks) {
  }
}
