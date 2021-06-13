#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);

int data=0;
char count=0;
void SPI_Write(char dat);
void main()
{
TRISD=0x00;
TRISB=0xFF;
TRISC3=0;	//sck as output
TRISC4=1;	//SDI as input
TRISC5=0;	//SDO as output

PORTB=0x00;
PORTD=0x00;

SSPM0=0;	//seting fosc/ dividing range
SSPM1=0;
SSPM2=0;
SSPM3=0;
SSPSTAT=0x00;
SSPEN=1;	//enable series enable
CKP=0;	
CKE=0;
SMP=0;

//SSPIE=1;
//GIE=1;
//PEIE=1;

//completion of spi enable master

while(1)
{
if(RB0==1)
{
while(RB0==1);
data++;
__delay_ms(30);

}
if(RB1==1)
{
while(RB1==1);
data--;
__delay_ms(30);

}
if(RB2==1)
{
while(RB2==1);
SPI_Write(data);
__delay_ms(30);

}
PORTD=data;
__delay_ms(30);
}
}
void SPI_Write(char count)
{

SSPBUF=count;
while(!BF);
__delay_ms(30);
//while(SSPSTAT==0x01);

}
