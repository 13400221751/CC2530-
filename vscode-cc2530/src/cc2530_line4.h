#ifndef CC2530_LINE4_H
#define CC2530_LINE4_H

#include "cc2530_gpio.h"

typedef struct cc2530_line4_channel {
  cc2530_port_id_t port;
  unsigned char mask;
} cc2530_line4_channel_t;

typedef struct cc2530_line4_config {
  cc2530_line4_channel_t s1;
  cc2530_line4_channel_t s2;
  cc2530_line4_channel_t s3;
  cc2530_line4_channel_t s4;
  unsigned char active_low;
} cc2530_line4_config_t;

typedef struct cc2530_line4_sample {
  unsigned char s1;
  unsigned char s2;
  unsigned char s3;
  unsigned char s4;
  unsigned char packed;
} cc2530_line4_sample_t;

typedef enum cc2530_line4_pattern {
  CC2530_LINE4_PATTERN_NONE = 0,
  CC2530_LINE4_PATTERN_CENTER,
  CC2530_LINE4_PATTERN_SLIGHT_LEFT,
  CC2530_LINE4_PATTERN_SLIGHT_RIGHT,
  CC2530_LINE4_PATTERN_HARD_LEFT,
  CC2530_LINE4_PATTERN_HARD_RIGHT,
  CC2530_LINE4_PATTERN_CROSS,
  CC2530_LINE4_PATTERN_WIDE
} cc2530_line4_pattern_t;

void cc2530_line4_init(const cc2530_line4_config_t *config);
unsigned char cc2530_line4_read_raw_channel(const cc2530_line4_channel_t *channel);
unsigned char cc2530_line4_read_logic_channel(const cc2530_line4_config_t *config, const cc2530_line4_channel_t *channel);
void cc2530_line4_read_all(const cc2530_line4_config_t *config, cc2530_line4_sample_t *sample);
cc2530_line4_pattern_t cc2530_line4_classify(const cc2530_line4_sample_t *sample);

#endif
