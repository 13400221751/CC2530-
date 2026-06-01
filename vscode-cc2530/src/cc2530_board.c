#include "cc2530_board.h"

const cc2530_led_t cc2530_board_status_led = { CC2530_PORT_1, CC2530_BV(0) };

void cc2530_board_init(void)
{
  cc2530_led_init_open_drain(&cc2530_board_status_led);
}
