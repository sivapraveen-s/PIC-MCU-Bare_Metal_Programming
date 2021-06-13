#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);

#define RS RC0
#define RW RC1
#define EN RC2

int data=0;
int seg[10]={0xBF,0x86,0xDB,0xCF,0xe6,0xED,0xFD,0x87,0xFF,0xEF}; //command for commmon cathode
void main()
{
TRISB=0x00;
PORTB=0x00;
TRISA5=1;   //declare input for multiple slave  mode and clear the pin
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
int a=0;
//while(1)
//{
//while(a<10)
//{
//PORTB=seg[a];
//__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
//__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
//__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
//__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
//__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
//a++;
//if(a==10)
//a=0;
//}
//}



while(1)
{
//PORTB=seg[data];
//__delay_ms(30);
}

}


void lcd_display(unsigned char dat,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTB=dat;
EN=1;
__delay_ms(30);
EN=0;	
}


void interrupt ISR()
{
if(SSPIF)
{
data=SSPBUF;
PORTB=seg[data];
SSPIF=0;
BF=0;
SSPOV=0;

}
}
