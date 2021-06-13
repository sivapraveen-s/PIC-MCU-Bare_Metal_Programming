#include<pic.h>
#define _XTAL_FREQ 20000000
#define red_light RD2
#define yellow_light RD1
#define green_light RD0

int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int i=0,j=120,count=0,count2=0;
char seg1,seg2;
int main()
{
TRISB=0x00;
TRISC=0x00;
TRISD=0x00;
PORTB=0x40;
PORTD=0x00;
PORTC=0x00;


INTCON=0xE0;
OPTION=0x07;
T1CON=0x01;

while(1)
{
if(i==1)
{
red_light=1;
}
if(i==40)
{
red_light=0;
yellow_light=1;
}
if(i==60)
{
red_light=0;
yellow_light=0;
green_light=1;
i=0;
while(1)
{
	seg1=i/10;
	seg2=i%10;

	PORTB=seg[seg1];
	RC0=1;
	__delay_ms(7);
	RC0=0;

	PORTB=seg[seg2];
	RC1=1;
	__delay_ms(7);
	RC1=0;
if(i==40)
break;
}
}


seg1=i/10;
seg2=i%10;

PORTB=seg[seg1];
RC0=1;
__delay_ms(7);
RC0=0;

PORTB=seg[seg2];
RC1=1;
__delay_ms(7);
RC1=0;
}

}

void interrupt ISR()
{

if(T0IF==1)
{
TMR0=46;	
T0IF=0;
count++;
if(count==93)
{
i=i+1;
//j=j--;
count=0;
}
}
//if(TMR1IF==1)
//{
//TMR1H=0;
//TMR1L=0;
//TMR1IF=0;
//count2++;
//if(count2==42)
//{
//k=k++;
//count2=0;
//if(j==60)
//
//}
//}
}

