#include "cc2530_line4.h"

static void cc2530_line4_init_channel(const cc2530_line4_channel_t *channel)
{
  cc2530_gpio_select_gpio_function(channel->port, channel->mask);
  cc2530_gpio_set_input(channel->port, channel->mask);
}

void cc2530_line4_init(const cc2530_line4_config_t *config)
{
  cc2530_line4_init_channel(&config->s1);
  cc2530_line4_init_channel(&config->s2);
  cc2530_line4_init_channel(&config->s3);
  cc2530_line4_init_channel(&config->s4);
}

unsigned char cc2530_line4_read_raw_channel(const cc2530_line4_channel_t *channel)
{
  return (unsigned char)(cc2530_gpio_read(channel->port, channel->mask) ? 1u : 0u);
}

unsigned char cc2530_line4_read_logic_channel(const cc2530_line4_config_t *config, const cc2530_line4_channel_t *channel)
{
  unsigned char value = cc2530_line4_read_raw_channel(channel);
  return config->active_low ? (unsigned char)(value ? 0u : 1u) : value;
}

void cc2530_line4_read_all(const cc2530_line4_config_t *config, cc2530_line4_sample_t *sample)
{
  sample->s1 = cc2530_line4_read_logic_channel(config, &config->s1);
  sample->s2 = cc2530_line4_read_logic_channel(config, &config->s2);
  sample->s3 = cc2530_line4_read_logic_channel(config, &config->s3);
  sample->s4 = cc2530_line4_read_logic_channel(config, &config->s4);
  sample->packed = (unsigned char)((sample->s1 << 0) |
                                   (sample->s2 << 1) |
                                   (sample->s3 << 2) |
                                   (sample->s4 << 3));
}

cc2530_line4_pattern_t cc2530_line4_classify(const cc2530_line4_sample_t *sample)
{
  switch (sample->packed) {
    case 0x00u:
      return CC2530_LINE4_PATTERN_NONE;
    case 0x06u:
      return CC2530_LINE4_PATTERN_CENTER;
    case 0x04u:
    case 0x0Cu:
      return CC2530_LINE4_PATTERN_SLIGHT_LEFT;
    case 0x02u:
    case 0x03u:
      return CC2530_LINE4_PATTERN_SLIGHT_RIGHT;
    case 0x08u:
      return CC2530_LINE4_PATTERN_HARD_LEFT;
    case 0x01u:
      return CC2530_LINE4_PATTERN_HARD_RIGHT;
    case 0x0Fu:
      return CC2530_LINE4_PATTERN_CROSS;
    default:
      return CC2530_LINE4_PATTERN_WIDE;
  }
}
