#include "cc2530_uart0.h"

void cc2530_uart0_init(const cc2530_uart0_config_t *config)
{
  PERCFG &= (unsigned char)~CC2530_BV(0);
  P0SEL |= (CC2530_BV(2) | CC2530_BV(3));
  P0DIR |= CC2530_BV(3);
  P0DIR &= (unsigned char)~CC2530_BV(2);

  U0CSR |= CC2530_U0CSR_MODE_BIT;
  U0UCR = 0x02u;
  U0GCR = (unsigned char)(config->baud_e & 0x1Fu);
  U0BAUD = config->baud_m;
  U0CSR |= CC2530_U0CSR_RE_BIT;
  U0UCR |= CC2530_U0UCR_FLUSH_BIT;
  IRCON2 &= (unsigned char)~CC2530_IRCON2_UTX0IF_BIT;
}

void cc2530_uart0_write_byte(unsigned char value)
{
  U0DBUF = value;
  while ((IRCON2 & CC2530_IRCON2_UTX0IF_BIT) == 0u) {
  }
  IRCON2 &= (unsigned char)~CC2530_IRCON2_UTX0IF_BIT;
}

void cc2530_uart0_write_string(const char *text)
{
  while (*text != '\0') {
    cc2530_uart0_write_byte((unsigned char)*text);
    ++text;
  }
}

unsigned char cc2530_uart0_rx_ready(void)
{
  return (unsigned char)(TCON & CC2530_TCON_URX0IF_BIT);
}

unsigned char cc2530_uart0_read_byte(void)
{
  while ((TCON & CC2530_TCON_URX0IF_BIT) == 0u) {
  }
  TCON &= (unsigned char)~CC2530_TCON_URX0IF_BIT;
  return U0DBUF;
}
