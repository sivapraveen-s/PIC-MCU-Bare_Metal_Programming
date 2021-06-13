#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);

void send(unsigned char);
int a,b,c,d,e,f,g,h,l,m,n,o,result,adc_value,temp;
int main()
{
TRISC6=0;
TRISC7=1;
TXSTA=0x26;
TXEN=1;
TRMT=1;
BRGH=1;
SPBRG=129;
SPEN=1;
while(1)
{
ADCON0=0xC5;
ADCON1=0x8E;
ADGO=1;
while(ADGO==1);
result=ADRESH;
result=(result<<8)+ADRESL;
result=result*0.48828125;

a=result%10;
result=result/10;
b=result%10;
result=result/10;
c=result%10;
result=result/10;
d=result%10;

send(d+0x30);
send(c+0x30);
send(b+0x30);
send(a+0x30);
//while(1);


if(1)
{
ADCON0=0xCD;
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

send(h+0x30);
send(g+0x30);
send(f+0x30);
send(e+0x30);


if(1)
{
ADCON0=0xD5;
ADCON1=0x80;
ADGO=1;
while(ADGO==1);
temp=ADRESH;
temp=(temp<<8)+ADRESL;
temp=(temp*0.48828125);

result=temp;
l=result%10;
result/=10;
m=result%10;
result/=10;
n=result%10;
result/=10;
o=result%10;

send(0+0x30);
send(n+0x30);
send(m+0x30);
send(l+0x30);
}
}
}
}

void send(unsigned char dat)
{
TXREG=dat;
while(!TRMT);
__delay_ms(30);
}
