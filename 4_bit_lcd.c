#include <pic.h>
#define _XTAL_FREQ 20000000

__CONFIG(0x3F3A);

#define RS RC0
#define RW RC1
#define EN RC2

void lcd_init();
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
//void lcd_delay();
 

unsigned char name[]={"Sivapraveen"};
unsigned char job_title[17]={"EmbeddedEngineer"};
void main()
{
 unsigned int i;
 TRISB=TRISC0=TRISC1=TRISC2=0x00;
PORTB=0x00;
TRISC=0x00;
 lcd_init();
 cmd(0x80);

 while(1)
 {
cmd(0x80);
for(int i=0;i<11;i++)
{
dat(name[i]);
__delay_ms(30);
}
cmd(0xC0);
for(int i=0;i<17;i++)
{
dat(job_title[i]);
}
while(1);
 } 
}
 
void lcd_init()
{
 cmd(0x02);
 cmd(0x28);
 cmd(0x0e);
 cmd(0x06);
 cmd(0x80);
}
 
void cmd(unsigned char a)
{
 RS=0;
 RW=0; 
 PORTB&=0x0F;
 PORTB|=(a&0xf0);
 EN=1;
 __delay_ms(30);
 EN=0;
__delay_ms(30);
 PORTB&=0x0f;
 PORTB|=(a<<4&0xf0);
 EN=1;
 __delay_ms(30);
 EN=0;
__delay_ms(30);
}
 
void dat(unsigned char b)
{
 RS=1;
 RW=0; 
 PORTB&=0x0F;
 PORTB|=(b&0xf0);
 EN=1;
 __delay_ms(30);
 EN=0;
 __delay_ms(30);
 PORTB&=0x0f;
 PORTB|=(b<<4&0xf0);
 EN=1;
 __delay_ms(30);
 EN=0;
 __delay_ms(30);
}
 

