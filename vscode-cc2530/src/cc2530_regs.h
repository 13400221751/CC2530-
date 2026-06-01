#ifndef CC2530_REGS_H
#define CC2530_REGS_H

#include <intrinsics.h>

#pragma language=extended

__sfr __no_init volatile unsigned char P0         @ 0x80;
__sfr __no_init volatile unsigned char TCON       @ 0x88;
__sfr __no_init volatile unsigned char P0IFG      @ 0x89;
__sfr __no_init volatile unsigned char P1IFG      @ 0x8A;
__sfr __no_init volatile unsigned char P2IFG      @ 0x8B;
__sfr __no_init volatile unsigned char P1IEN      @ 0x8D;
__sfr __no_init volatile unsigned char U0CSR      @ 0x86;
__sfr __no_init volatile unsigned char P1         @ 0x90;
__sfr __no_init volatile unsigned char U0DBUF     @ 0xC1;
__sfr __no_init volatile unsigned char U0BAUD     @ 0xC2;
__sfr __no_init volatile unsigned char U0UCR      @ 0xC4;
__sfr __no_init volatile unsigned char U0GCR      @ 0xC5;
__sfr __no_init volatile unsigned char P2         @ 0xA0;
__sfr __no_init volatile unsigned char IEN0       @ 0xA8;
__sfr __no_init volatile unsigned char IP0        @ 0xA9;
__sfr __no_init volatile unsigned char P0IEN      @ 0xAB;
__sfr __no_init volatile unsigned char P2IEN      @ 0xAC;
__sfr __no_init volatile unsigned char T1STAT     @ 0xAF;
__sfr __no_init volatile unsigned char ADCCON1    @ 0xB4;
__sfr __no_init volatile unsigned char ADCCON2    @ 0xB5;
__sfr __no_init volatile unsigned char ADCCON3    @ 0xB6;
__sfr __no_init volatile unsigned char IEN1       @ 0xB8;
__sfr __no_init volatile unsigned char IP1        @ 0xB9;
__sfr __no_init volatile unsigned char ADCL       @ 0xBA;
__sfr __no_init volatile unsigned char ADCH       @ 0xBB;
__sfr __no_init volatile unsigned char RNDL       @ 0xBC;
__sfr __no_init volatile unsigned char RNDH       @ 0xBD;
__sfr __no_init volatile unsigned char CLKCONSTA  @ 0x9E;
__sfr __no_init volatile unsigned char SLEEPCMD   @ 0xBE;
__sfr __no_init volatile unsigned char IRCON      @ 0xC0;
__sfr __no_init volatile unsigned char CLKCONCMD  @ 0xC6;
__sfr __no_init volatile unsigned char T3CNT      @ 0xCA;
__sfr __no_init volatile unsigned char T3CTL      @ 0xCB;
__sfr __no_init volatile unsigned char T3CCTL0    @ 0xCC;
__sfr __no_init volatile unsigned char T3CC0      @ 0xCD;
__sfr __no_init volatile unsigned char T3CCTL1    @ 0xCE;
__sfr __no_init volatile unsigned char T3CC1      @ 0xCF;
__sfr __no_init volatile unsigned char TIMIF      @ 0xD8;
__sfr __no_init volatile unsigned char RFD        @ 0xD9;
__sfr __no_init volatile unsigned char T1CC0L     @ 0xDA;
__sfr __no_init volatile unsigned char T1CC0H     @ 0xDB;
__sfr __no_init volatile unsigned char T1CC1L     @ 0xDC;
__sfr __no_init volatile unsigned char T1CC1H     @ 0xDD;
__sfr __no_init volatile unsigned char T1CC2L     @ 0xDE;
__sfr __no_init volatile unsigned char T1CC2H     @ 0xDF;
__sfr __no_init volatile unsigned char T1CNTL     @ 0xE2;
__sfr __no_init volatile unsigned char T1CNTH     @ 0xE3;
__sfr __no_init volatile unsigned char T1CTL      @ 0xE4;
__sfr __no_init volatile unsigned char T1CCTL0    @ 0xE5;
__sfr __no_init volatile unsigned char T1CCTL1    @ 0xE6;
__sfr __no_init volatile unsigned char T1CCTL2    @ 0xE7;
__sfr __no_init volatile unsigned char IRCON2     @ 0xE8;
__sfr __no_init volatile unsigned char P0INP      @ 0x8F;
__sfr __no_init volatile unsigned char P0SEL      @ 0xF3;
__sfr __no_init volatile unsigned char APCFG      @ 0xF2;
__sfr __no_init volatile unsigned char P1SEL      @ 0xF4;
__sfr __no_init volatile unsigned char P2SEL      @ 0xF5;
__sfr __no_init volatile unsigned char P1INP      @ 0xF6;
__sfr __no_init volatile unsigned char P2INP      @ 0xF7;
__sfr __no_init volatile unsigned char PERCFG     @ 0xF1;
__sfr __no_init volatile unsigned char P0DIR      @ 0xFD;
__sfr __no_init volatile unsigned char P1DIR      @ 0xFE;
__sfr __no_init volatile unsigned char P2DIR      @ 0xFF;
__sfr __no_init volatile unsigned char RFST       @ 0xE1;
__sfr __no_init volatile unsigned char RFIRQF0    @ 0xE9;
__sfr __no_init volatile unsigned char RFERRF     @ 0xBF;

__xdata __no_init volatile unsigned char FRMFILT0 @ 0x6180;
__xdata __no_init volatile unsigned char FRMFILT1 @ 0x6181;
__xdata __no_init volatile unsigned char SRCMATCH @ 0x6182;
__xdata __no_init volatile unsigned char FRMCTRL0 @ 0x6189;
__xdata __no_init volatile unsigned char FRMCTRL1 @ 0x618A;
__xdata __no_init volatile unsigned char RXENABLE @ 0x618B;
__xdata __no_init volatile unsigned char FREQCTRL @ 0x618F;
__xdata __no_init volatile unsigned char TXPOWER  @ 0x6190;
__xdata __no_init volatile unsigned char TXCTRL   @ 0x6191;
__xdata __no_init volatile unsigned char FSMSTAT1 @ 0x6193;
__xdata __no_init volatile unsigned char FIFOPCTRL @ 0x6194;
__xdata __no_init volatile unsigned char FSMCTRL  @ 0x6195;
__xdata __no_init volatile unsigned char CCACTRL0 @ 0x6196;
__xdata __no_init volatile unsigned char CCACTRL1 @ 0x6197;
__xdata __no_init volatile unsigned char RSSISTAT @ 0x6199;
__xdata __no_init volatile unsigned char RXFIFOCNT @ 0x619B;
__xdata __no_init volatile unsigned char TXFIFOCNT @ 0x619C;
__xdata __no_init volatile unsigned char RXFIRST_PTR @ 0x619D;
__xdata __no_init volatile unsigned char RXLAST_PTR  @ 0x619E;
__xdata __no_init volatile unsigned char TXFIRST_PTR @ 0x61A1;
__xdata __no_init volatile unsigned char TXLAST_PTR  @ 0x61A2;
__xdata __no_init volatile unsigned char MDMCTRL0 @ 0x61A8;
__xdata __no_init volatile unsigned char MDMCTRL1 @ 0x61A9;
__xdata __no_init volatile unsigned char RXCTRL   @ 0x61AB;
__xdata __no_init volatile unsigned char FSCTRL   @ 0x61AC;
__xdata __no_init volatile unsigned char FSCAL0   @ 0x61AD;
__xdata __no_init volatile unsigned char FSCAL1   @ 0x61AE;
__xdata __no_init volatile unsigned char FSCAL2   @ 0x61AF;
__xdata __no_init volatile unsigned char FSCAL3   @ 0x61B0;
__xdata __no_init volatile unsigned char AGCCTRL0 @ 0x61B1;
__xdata __no_init volatile unsigned char AGCCTRL1 @ 0x61B2;
__xdata __no_init volatile unsigned char AGCCTRL2 @ 0x61B3;
__xdata __no_init volatile unsigned char AGCCTRL3 @ 0x61B4;
__xdata __no_init volatile unsigned char T1CCTL3  @ 0x62A3;
__xdata __no_init volatile unsigned char T1CCTL4  @ 0x62A4;
__xdata __no_init volatile unsigned char T1CC3L   @ 0x62AC;
__xdata __no_init volatile unsigned char T1CC3H   @ 0x62AD;
__xdata __no_init volatile unsigned char T1CC4L   @ 0x62AE;
__xdata __no_init volatile unsigned char T1CC4H   @ 0x62AF;

#define CC2530_BV(bit)                     (1u << (bit))
#define CC2530_CLKCON_OSC_BIT              CC2530_BV(6)
#define CC2530_IEN0_EA_BIT                 CC2530_BV(7)
#define CC2530_IEN0_URX0IE_BIT             CC2530_BV(2)
#define CC2530_IEN1_T1IE_BIT               CC2530_BV(1)
#define CC2530_IEN2_UTX0IE_BIT             CC2530_BV(2)
#define CC2530_TCON_URX0IF_BIT             CC2530_BV(3)
#define CC2530_IRCON_T1IF_BIT              CC2530_BV(1)
#define CC2530_IRCON2_UTX0IF_BIT           CC2530_BV(1)
#define CC2530_U0CSR_RE_BIT                CC2530_BV(6)
#define CC2530_U0CSR_MODE_BIT              CC2530_BV(7)
#define CC2530_U0UCR_FLUSH_BIT             CC2530_BV(7)
#define CC2530_U0UCR_STOP_BIT              CC2530_BV(1)
#define CC2530_U0UCR_START_BIT             CC2530_BV(0)
#define CC2530_ADCCON1_EOC_BIT             CC2530_BV(7)

#define CC2530_RFST_SRXON                  0xE3u
#define CC2530_RFST_STXON                  0xE9u
#define CC2530_RFST_SFLUSHRX               0xEDu
#define CC2530_RFST_SFLUSHTX               0xEEu
#define CC2530_RFST_SRFOFF                 0xEFu

#endif
