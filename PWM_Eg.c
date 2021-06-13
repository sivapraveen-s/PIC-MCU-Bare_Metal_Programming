/*

Code: //continuous slow speed controlling.

#include<pic.h>
#define _XTAL_FREQ 20000000

char a;
int i;

int PWM_increment(unsigned int); 

void main()
{
TRISC=0x00;
PORTB=0;

CCP1CON=0X0C;

a=((20/(4*16*1))-1);	//calculation for PR2 value
PR2=a;					//load the value into PR2		

T2CON=0x03;				//set prescaler value to 16
TMR2ON=1;				//on the timer2
TMR2=0;					//set the initial value of timer2

while(1)
{
i=0;
PWM_increment(i);		//value for loading the i value into the CCPR1L
__delay_ms(30);
while(i<a)
{
i++;
PWM_increment(i);
__delay_ms(30);
}
}
}

int PWM_increment(unsigned int b)
{
 CCPR1L=b;
}

*/



















#include<pic.h>
#define _XTAL_FREQ 20000000

char a;
int i;

int PWM_increment(unsigned int); 

void main()
{
TRISC=0x00;
PORTB=0;

CCP1CON=0X0C;

a=((20/(4*16*1))-1);	//calculation for PR2 value
PR2=a;					//load the value into PR2		

T2CON=0x03;				//set prescaler value to 16
TMR2ON=1;				//on the timer2
TMR2=0;					//set the initial value of timer2

while(1)
{
i=0;
PWM_increment(i);		//value for loading the i value into the CCPR1L
__delay_ms(30);
while(i<a)
{
i++;
PWM_increment(i);
__delay_ms(30);
}
while(i>a)
{
i++;
PWM_increment(i);
__delay_ms(30);
}i=0;
}
}

int PWM_increment(unsigned int b)
{
 CCPR1L=b;
}
