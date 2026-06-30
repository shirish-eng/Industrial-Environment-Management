#define FOSC 12000000
#define CCLK 5*FOSC
#define PCLK CCLK/4
#define ADCLK 3000000
#define CLK_DIV ((PCLK/ADCLK)-1)<<8
#define CH0 1
#define CH1 2
#define CH2 4
#define CH3 8
#define PDN_BIT 1<<21
#define START_CON 1<<24
#define DONBIT 31
#define RESULT 6
#define ACH0 0x00400000
#define ACH1 0x01000000
#define ACH2 0x04000000
#define ACH3 0x10000000					                             



