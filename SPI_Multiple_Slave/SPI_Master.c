#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
int count=0;
void send(int value);
void main()
{
TRISD=0xFF;
TRISB=0x00;
TRISC3=0;
TRISC4=1;
TRISC5=0;
TRISA=0x00;
ADCON1=0x07;

PORTB=0x00;

SSPM0=0;
SSPM1=0;
SSPM2=0;
SSPM3=0;
SSPEN=1;
CKP=1;
CKE=1;
SMP=0;
GIE=1;
SSPIE=1;
PORTA=0x00;

while(1)
{
if(RD0==0)
{
while(RD0==0);
count++;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
if(count==10)
{count=0;}
}
if(RD1==0)
{
RB0=0;
RB1=1;
	while(RD1==0);
	send(count);
__delay_ms(30);
}

if(RD2==0)
{
RB0=1;
RB1=0;
while(RD2==0);
send(count);
__delay_ms(30);
}



PORTA=count;
__delay_ms(30);
__delay_ms(30);
}

}

void send(int value)
{
SSPBUF=value;
while(!BF);
}
