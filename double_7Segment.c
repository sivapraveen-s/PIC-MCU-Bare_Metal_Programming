#include<pic.h>
#define _XTAL_FREQ 20000000
#define sw RD0

int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int i=0;
char seg1,seg2;

void main()
{
	TRISB=0x00;
	TRISC=0x00;
	TRISD=0x01;
	PORTC=0x00;
	PORTD=0x00;
while(1)
{
	if(sw==1)
	{
		while(sw==1);
		i++;
	}
	if(i==100)
		i=0;
seg1=i/10;
seg2=i%10;

PORTB=seg[seg1];
RC0=1;
__delay_ms(10);
RC0=0;

PORTB=seg[seg2];
RC1=1;
__delay_ms(10);
RC1=0;

}
}
