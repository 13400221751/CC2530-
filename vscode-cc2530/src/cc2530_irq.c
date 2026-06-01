#include "cc2530_irq.h"

void cc2530_irq_enable_global(void)
{
  IEN0 |= CC2530_IEN0_EA_BIT;
}

void cc2530_irq_disable_global(void)
{
  IEN0 &= (unsigned char)~CC2530_IEN0_EA_BIT;
}
