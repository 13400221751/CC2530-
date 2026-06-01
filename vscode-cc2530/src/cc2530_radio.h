#ifndef CC2530_RADIO_H
#define CC2530_RADIO_H

#include "cc2530_system.h"

typedef struct cc2530_radio_config {
  unsigned char channel;
  unsigned char tx_power;
} cc2530_radio_config_t;

void cc2530_radio_apply_default_config(const cc2530_radio_config_t *config);
void cc2530_radio_enable_rx(const cc2530_radio_config_t *config);
void cc2530_radio_flush_rx(void);
void cc2530_radio_flush_tx(void);
void cc2530_radio_write_tx_fifo(const unsigned char *data, unsigned char length);
void cc2530_radio_strobe_tx(void);

#endif
