# CC2530 VS Code Workspace

This workspace builds bare-metal `CC2530` firmware in `VS Code` with the local
`IAR Embedded Workbench 6.0 Evaluation` toolchain.

## Build

Run the default build task in VS Code or execute:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build.ps1
```

Clean and rebuild:

```powershell
powershell -ExecutionPolicy Bypass -File .\scripts\build.ps1 -Clean
```

## Library layout

The current project is organized as a small reusable development library:

- `src/cc2530_board.[ch]`
  Board-level defaults, current status LED mapping.
- `src/cc2530_regs.h`
  Raw `CC2530` register definitions and common bit constants.
- `src/cc2530_irq.[ch]`
  Global interrupt enable / disable helpers.
- `src/cc2530_system.[ch]`
  Delay and system clock helpers.
- `src/cc2530_gpio.[ch]`
  Basic GPIO direction / value / function selection helpers.
- `src/cc2530_led.[ch]`
  LED helpers. The default implementation uses high-Z off and output-low on.
- `src/cc2530_uart0.[ch]`
  UART0 initialization and blocking TX/RX helpers.
- `src/cc2530_timer1.[ch]`
  Timer1 free-running counter and tick delay helpers.
- `src/cc2530_adc.[ch]`
  Single-shot ADC read and random source helpers.
- `src/cc2530_line4.[ch]`
  4-channel line-tracking sensor GPIO driver.
- `src/cc2530_dual_line_follow.[ch]`
  Upper-layer helper for forward/backward line-follow using two 4-channel modules.
- `src/cc2530_l298n.[ch]`
  Configurable `L298N` motor-driver framework.
- `src/cc2530_car4wd.[ch]`
  4WD vehicle control framework built on top of `L298N`.
- `src/cc2530_radio.[ch]`
  Minimal `802.15.4` radio bring-up, FIFO flush, and basic TX helpers.
- `src/main.c`
  Example application using the library.

## Example usage

```c
#include "cc2530_board.h"
#include "cc2530_radio.h"
#include "cc2530_uart0.h"

static const cc2530_radio_config_t radio = { 11u, 0xD5u };
static const cc2530_uart0_config_t uart0 = { 216u, 11u };

cc2530_board_init();
cc2530_uart0_init(&uart0);
cc2530_radio_enable_rx(&radio);
```

## Current example behavior

- Initializes the `CC2530` radio on channel `11`
- Initializes UART0
- Starts Timer1
- Enables RF receive mode
- Flashes the `P1.0` LED continuously

## Notes

- The current radio module is still a minimal bare-metal layer, not Zigbee.
- If you later add `Z-Stack`, keep this library as the board / register layer.
- The generated firmware image is written to `build/app.hex`.
