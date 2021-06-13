#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RB0
#define RW RB1
#define EN RB2

void lcd_display(unsigned char,unsigned char);
int result,a,b,c,d,e,f,g,h;
int temp,adc_value,adc_disp[4];
char temp_disp[5]={"Temp:"};
//char adc_disp[11]={"POTValue:"};
int main()
{
TRISB=0x00;
TRISC=0x00;
TRISA=0xFF;
PORTB=0x00;
PORTC=0x00;

lcd_display(0x38,0);
lcd_display(0x01,0);
lcd_display(0x06,0);
lcd_display(0x0C,0);
lcd_display(0x80,0);
for(int i=0;i<5;i++)
{
lcd_display(temp_disp[i],1);
__delay_ms(10);
}
lcd_display(0xC0,0);
lcd_display('P',1);
lcd_display('O',1);
lcd_display('T',1);
lcd_display(':',1);
while(1)
{
ADCON0=0xCD;
ADCON1=0x80;
ADGO=1;
while(ADGO==1);
temp=ADRESH;
temp=(temp<<8)+ADRESL;
temp=temp*0.48828125;

result=temp;
a=result%10;
result/=10;
b=result%10;
result/=10;
c=result%10;
result/=10;
d=result%10;

lcd_display(0x86,0);
lcd_display(d+0x30,1);
lcd_display(c+0x30,1);
lcd_display(b+0x30,1);
lcd_display(a+0x30,1);
lcd_display(0xDF,1);
lcd_display('C',1);
lcd_display(0x86,0);


if(1)
{
ADCON0=0xC5;
ADCON1=0x80;
ADGO=1;
while(ADGO==1);
adc_value=ADRESH;
adc_value=(adc_value<<8)+ADRESL;

e=adc_value%10;
adc_value=adc_value/10;
f=adc_value%10;
adc_value=adc_value/10;
g=adc_value%10;
adc_value=adc_value/10;
h=adc_value%10;

lcd_display(0xC4,0);
lcd_display(h+0x30,1);
lcd_display(g+0x30,1);
lcd_display(f+0x30,1);
lcd_display(e+0x30,1);
lcd_display(0xC4,0);
}
}
}

void lcd_display(unsigned char data,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTC=data;
EN=1;
__delay_ms(30);
EN=0;
}

