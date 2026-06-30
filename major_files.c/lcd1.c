#include<lpc21xx.h>
//#include"lcd_defines.h"
#include"defines.h"
#include"delay.h"
#include"types.h"
void CmdLCD(u8 cmd);
//#include"fun.h"
#define LCD_DATA 16
#define RS 8
#define RW 10
#define EN 9										 
void IniLCD(void)
{
        WRITEBYTE(IODIR0,LCD_DATA,0XFF);
        SETBIT(IODIR0,RW);
        SETBIT(IODIR0,RS);
        SETBIT(IODIR0,EN);
        delay_ms(15);
        CmdLCD(0x30);
        delay_ms(5);
        CmdLCD(0x30);
        delay_us(100);
        CmdLCD(0x30);
        CmdLCD(0x38);
        //CmdLCD(DISP_ON_CUR_OFF);
		CmdLCD(0x0f);
        CmdLCD(0x01);
        CmdLCD(0x06);
}
void writeLCD(u8 data)
{
        SCLRBIT(IOCLR0,RW);
        WRITEBYTE(IOPIN0,LCD_DATA,data);
        SSETBIT(IOSET0,EN);
        delay_us(1);
        SCLRBIT(IOCLR0,EN);
        delay_ms(2);
}
void CharLCD( u8 ascii)
{
        SSETBIT(IOSET0,RS);
        writeLCD(ascii);
}
void CmdLCD(u8 cmd)
{
        SCLRBIT(IOCLR0,RS);
        writeLCD(cmd);
}
void strLCD(u8* str)
 {
        while(*str)
        {
		  CharLCD(*str++);

        }
 }
void u32LCD(u32 n)
{
	u8 a[10];
	s32 i=0;
	if(n==0)
	{
		CharLCD('0');
	}
	else
	{
		while(n)
		{
			a[i++]=(n%10)+'0';
			n/=10;
		}
		for(--i;i>=0;i--)
		{
			CharLCD(a[i]);
		}
	}
}
void s32LCD(s32 n)
{
	if(n<0)
	{
		n=-n;
		CharLCD('-');
		u32LCD(n);
	}
}
void BildCGRAM(u8* p,u8 n)
{
	s32 i;
	CmdLCD(0x40);
	for(i=0;i<n;i++)
	{
		CharLCD(p[i]);
	}
	CmdLCD(0xc0);
}
void f32LCD(f32 fn,u8 n)
{
	u32 in;
	if(fn<0.0)
	{
		CharLCD('-');
		fn=-fn;
	}
	in=fn;
	u32LCD(in);
	CharLCD('.');
	while(n)
	{
		fn=(fn-in)*10;
		in=fn;
		CharLCD(in+48);
		n--;
	}
}

