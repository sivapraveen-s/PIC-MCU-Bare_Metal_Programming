#include<pic.h>
#define _XTAL_FREQ 20000000
#define inc RC1
#define dec RC2

int a=0,b=0;




int main()
{
TRISC=0xFF;
TRISB=0x00;
PORTB=0x00;
PORTC=0x00;




while(1)
{
if(RC0==1)
{
while(a>0)
{
PORTB=0xFF;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x00;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
a--;
}
}
while(inc==1)
{
a=++a;
while(inc==1);
}
while(dec==1)
{
a=--a;
while(dec==1);
}

}
}




