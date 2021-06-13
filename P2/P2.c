#include<pic.h>
#define _XTAL_FREQ 20000000
#define led1 RD0
#define led2 RD1
#define led3 RD2
#define led4 RD3
#define sw1 RB0
#define sw2 RB1
#define sw3 RB2
#define sw4 RB3

void timer_delay(void);

void main()
{
TRISB=0xFF;
TRISD=0x00;
PORTD=0x00;
T1CON=0x01;
TMR0=0;
if(sw1==1)
{
	led1=1;
	timer_delay();
	
	led1=0;
	timer_delay();

}
else if(sw2==1)
{
	led2=1;
	timer_delay();
	led2=0;
	timer_delay();
}
else if(sw3==1)
{
	led3=1;
	timer_delay();
	led3=0;
	timer_delay();

}
else if(sw4==1)
{
	led4=1;
	timer_delay();
	led4=0;
	timer_delay();
}
}

void timer_delay()
{
for(int i=0;i<76;i++)
{
	TMR1H=0;
	TMR1L=0;
	while(!TMR1IF);
	TMR1IF=0;
}
	
}
