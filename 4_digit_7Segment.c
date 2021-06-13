#include<pic.h>
#define _XTAL_FREQ 20000000
#define sw RD0

int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int i=0,a,b,c,d,e,f,g,h;
int j=0;
int flag=0;
void main()
{
	TRISB=0x00;
	TRISC=0x00;
	TRISD=0x01;
	PORTC=0x00;
	PORTD=0x00;
	TRISA=0x00;
	PORTA=0x00;
while(1)
{


a=i%10; 
b=i/10;
c=b%10; 
d=b/10;
e=d%10; 
f=d/10;
g=f%10; 
h=f/10;

PORTB=seg[g];
RC0=1;
__delay_ms(7);
RC0=0;

PORTB=seg[e];
RC1=1;
__delay_ms(7);
RC1=0;

PORTB=seg[c];
RC2=1;
__delay_ms(7);
RC2=0;

PORTB=seg[a];
RC3=1;
__delay_ms(7);
RC3=0;
//if(j<=150 | j>=160)
//{
//RA0=1;
//RC4=1;
//__delay_ms(30);__delay_ms(30);__delay_ms(30);
//RA0=0;
//RC4=0;
//__delay_ms(30);__delay_ms(30);__delay_ms(30);
//j++;
//if(j==160)
//break;

if(flag>=10)
{
	i++;
	j++;
	flag=0;
}
flag++;
}
}
