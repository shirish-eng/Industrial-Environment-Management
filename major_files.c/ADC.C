#include<lpc21xx.h>
#include"adc_defines.h"
#include"types.h"
//#include"lcd_defines.h"
#include"delay.h"
void initadc(void)
{
	PINSEL1 |=ACH0;//cnfg port pin p0.27 for ch1   LM35
	PINSEL1 |=ACH1;//confg port pin p0.28 for ch2	MQ2
	ADCR=PDN_BIT|CLK_DIV;
}
void read_adc(u32 chno,f32 *eAR,u32 *adcdval)
{
	ADCR&=~(255<<0);
	ADCR|=1<<chno|START_CON;
	delay_us(3);
	while(((ADDR>>DONBIT)&1)==0);
	ADCR&=~(START_CON);
	*adcdval=((ADDR>>RESULT)&1023);
	*eAR=(3.3/1023)*(*adcdval);
}
/*void read_adc1(u32 chno,f32 *eAR,u32 *adcdval)
{
	ADCR&=~(255<<0);
	ADCR|=1<<chno|START_CON;
	delay_us(3);
	while(((ADDR>>DONBIT)&1)==0);
	ADCR&=~(START_CON);
	*adcdval=((ADDR>>RESULT)&1023);
	*eAR=(3.3/1023)*(*adcdval);
} */


