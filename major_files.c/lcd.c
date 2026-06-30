#include<LPC21xx.h>													    

#include "delay.h"
#include "lcd.h"
#include "defines.h"

#define LCD_DAT 16
#define RS 8
#define RW 10
#define EN 9

void LCD_Init(void)
{
		/*WRITEBYTE(IODIR0,LCD_DAT,0xFF);
		SETBIT(IODIR0,RW);
        	SETBIT(IODIR0,RS);
        	SETBIT(IODIR0,EN);
		delay_ms(15);
    		Write_CMD_LCD(0x30);
    		delay_ms(5);
     		Write_CMD_LCD(0x30);
    		delay_us(100);
    		Write_CMD_LCD(0x30);
   		Write_CMD_LCD(0x38);//set 8-bit mode of operation with 2 lines
						// and 5X7 character font
		Write_CMD_LCD(0x0f);//Enabling the display with blinking cursor				 
		//Write_CMD_LCD(0x10);//Turning OFF the display
		Write_CMD_LCD(0x01);//clearing the display
    		Write_CMD_LCD(0x06);//Shifting the cursor to the right side
                        //after writing each byte onto the display
		    */
	  WRITEBYTE(IODIR0,LCD_DAT,0XFF);
        SETBIT(IODIR0,RW);
        SETBIT(IODIR0,RS);
        SETBIT(IODIR0,EN);
        delay_ms(15);
        Write_CMD_LCD(0X30);
		        delay_ms(5);
        Write_CMD_LCD(0X30);
        delay_us(100);
        Write_CMD_LCD(0X30);
        Write_CMD_LCD(0X38);
        Write_CMD_LCD(0X0C);
        Write_CMD_LCD(0X01);
        Write_CMD_LCD(0X06);

}
void Write_CMD_LCD(char cmd)
{
  	SCLRBIT(IOCLR0,RS);
	Write_LCD(cmd);
        
}
void Write_DAT_LCD(char dat)
{
	SSETBIT(IOSET0,RS);
	Write_LCD(dat);
}
void Write_LCD(char data)
{
	
	  SCLRBIT(IOCLR0,RW);
        WRITEBYTE(IOPIN0,LCD_DAT,data);
        SSETBIT(IOSET0,EN);
        delay_us(1);
        SCLRBIT(IOCLR0,EN);
        delay_ms(2);
}
void Write_str_LCD(char *p)
{
	while(*p)
	Write_DAT_LCD(*p++);
	
}
void Write_int_LCD(signed int n)
{
	char a[10],i=0;
    if(n<0)
	{
		Write_DAT_LCD('-');
		n=-n;
	}
	do                       
	{
		a[i++]=n%10+48;	
		n=n/10;
	}while(n);
  for(;i>0;i--)
		Write_DAT_LCD(a[i-1]);
}
void Write_float_LCD(float f,char i)
//1st arg(f) is the float number to be displayed  on LCD
//2nd arg(i) is number digits to be displayed after the dot('.')                      
{
  unsigned long int n=f;
	Write_int_LCD(n);
	Write_DAT_LCD('.');
  for(;i>0;i--)
	{
		f=f*10;
    n=f;	
		Write_DAT_LCD(n%10+48);
	}	
}
