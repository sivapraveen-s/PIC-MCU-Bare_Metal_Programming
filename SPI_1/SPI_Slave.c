#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
int data=0;

unsigned int SPI_Read();

int main()
{
TRISB=0x00;
TRISC3=0;
TRISC4=1;
TRISC5=0;

SSPM0=0;
SSPM1=0;
SSPM2=1;
SSPM3=0;

SSPEN=1;

CKP=0;
CKE=0;
SMP=0;

PCFG3=0;
PCFG2=1;
PCFG1=0;
PCFG0=0;

ADCON1=0x07;
TRISA5=1;

GIE=1;
PEIE=1;
SSPIE=1;

while(1)
{
PORTB=data;
__delay_ms(30);

}	
}

unsigned int SPI_Read()
{
int data;
if(BF)
{
data=SSPBUF;
BF=0;
SSPIF=0;
SSPOV=0;
return data;
}
}

void interrupt ISR(void)
{
if(SSPBUF)
{
data=SSPBUF;
SSPIF=0;
//BF=0;
}
}





