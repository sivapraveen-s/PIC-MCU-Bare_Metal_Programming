#include<pic.h>
#define _XTAL_FREQ 20000000

int data=3;

void main()
{
TRISA5=1;


ADCON0=0xC5;		// 11000101
ADCON1=0x8E;		// 10001110 (first pin analog 2 and 3 are digital switch)


TRISD=0x00;
PORTD=0x00;

CKE=1;
CKP=1;
SMP=0;
SSPEN=1;
SSPM0=0;
SSPM1=0;
SSPM2=1;
SSPM3=0;
GIE=1;
SSPIE=1;
PEIE=1;


TRISC3=1;
TRISC4=1;
TRISC5=0;

while(1)
{
PORTD=data;
__delay_ms(30);
}

}
void interrupt ISR()
{
if(SSPIF)
{
data=SSPBUF;
PORTD=data;
SSPIF=0;
BF=0;
SSPOV=0;

}
}
