#include<pic.h>
#define _XTAL_FREQ 20000000

__CONFIG(0x3F72);




void main()
{
	OPTION=0x00;
	TRISB=0x01;
	TRISC=0x00;
	TRISD=0x00;

PORTB=0x00;

PORTD=0x00;

INTCON=0xD0;




	PORTD=0xFF;
	__delay_ms(30);
	PORTD=0x00;
	__delay_ms(30);



}

void interrupt ISR(void)
{
	if(INTF!=0)
	{
		RC0=~RC0;
		RC1=~RC1;
		INTF=0;
		while((PORTB & 0x01)==0);
	
	}
}
