#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
void main()
{
TRISC=0xFF;
TRISB=0x00;
PORTB=0x00;
PORTC=0x00;
while(RC0==1)
{
PORTB=0x80; //0x80
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x20; //0x20
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x08; //0x08
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x02; //0x02
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
}
while(RC1==1)
{
PORTB=0x40; //0x40
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x20; //0x20
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x04; //0x04
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
PORTB=0x01; //0x01
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
}
}
