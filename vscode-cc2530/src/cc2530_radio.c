#include "cc2530_radio.h"

void cc2530_radio_apply_default_config(const cc2530_radio_config_t *config)
{
  FRMFILT0 = 0x00u;
  FRMFILT1 = 0x00u;
  SRCMATCH = 0x00u;
  FRMCTRL0 = 0x60u;
  FRMCTRL1 = 0x00u;
  RXENABLE = 0x01u;
  FIFOPCTRL = 0x7Fu;

  FREQCTRL = config->channel;
  TXPOWER = config->tx_power;
  TXCTRL = 0x94u;
  FSMCTRL = 0x00u;
  CCACTRL0 = 0xF8u;
  CCACTRL1 = 0x14u;
  MDMCTRL0 = 0x85u;
  MDMCTRL1 = 0x14u;
  RXCTRL = 0x3Fu;
  FSCTRL = 0x5Au;
  FSCAL0 = 0x0Bu;
  FSCAL1 = 0x2Bu;
  FSCAL2 = 0x13u;
  FSCAL3 = 0x11u;
  AGCCTRL0 = 0x11u;
  AGCCTRL1 = 0x15u;
  AGCCTRL2 = 0xFEu;
  AGCCTRL3 = 0x31u;
}

void cc2530_radio_flush_rx(void)
{
  RFST = CC2530_RFST_SFLUSHRX;
  RFST = CC2530_RFST_SFLUSHRX;
}

void cc2530_radio_flush_tx(void)
{
  RFST = CC2530_RFST_SFLUSHTX;
  RFST = CC2530_RFST_SFLUSHTX;
}

void cc2530_radio_enable_rx(const cc2530_radio_config_t *config)
{
  cc2530_system_clock_use_32mhz_xosc();
  SLEEPCMD &= (unsigned char)~0x03u;

  cc2530_radio_apply_default_config(config);

  RFERRF = 0x00u;
  RFIRQF0 = 0x00u;
  RXFIFOCNT = 0x00u;
  TXFIFOCNT = 0x00u;

  RFST = CC2530_RFST_SRFOFF;
  cc2530_radio_flush_rx();
  cc2530_radio_flush_tx();
  RFST = CC2530_RFST_SRXON;
}

void cc2530_radio_write_tx_fifo(const unsigned char *data, unsigned char length)
{
  unsigned char i;

  cc2530_radio_flush_tx();
  RFD = length;
  for (i = 0u; i < length; ++i) {
    RFD = data[i];
  }
}

void cc2530_radio_strobe_tx(void)
{
  RFST = CC2530_RFST_STXON;
}
