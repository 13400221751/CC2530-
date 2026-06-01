#include "cc2530_adc.h"
#include "cc2530_board.h"
#include "cc2530_led.h"
#include "cc2530_radio.h"
#include "cc2530_system.h"
#include "cc2530_timer1.h"
#include "cc2530_uart0.h"

__root int main(void)
{
  static const cc2530_radio_config_t radio = { 11u, 0xD5u };
  static const cc2530_uart0_config_t uart0 = { 216u, 11u };
  unsigned char led_state = 0u;
  unsigned int entropy;

  cc2530_board_init();
  cc2530_uart0_init(&uart0);
  cc2530_timer1_start_free_running();
  cc2530_radio_enable_rx(&radio);
  cc2530_uart0_write_string("CC2530 library ready\r\n");
  entropy = cc2530_random16();
  if (entropy == 0u) {
    entropy = cc2530_adc_read_once(0u);
  }

  for (;;) {
    cc2530_led_toggle(&cc2530_board_status_led, &led_state);
    cc2530_timer1_delay_ticks((unsigned int)(12000u + (entropy & 0x0FFFu)));
  }
}
