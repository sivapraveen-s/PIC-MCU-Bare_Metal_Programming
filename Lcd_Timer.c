#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
#define DATA PORTD
#define RS RC0
#define RW RC1
#define EN RC2

unsigned char first_line[]={"Sivapraveen"};
unsigned char second_line[]={"Embedded developer bosch"};
void delay();
void command(unsigned char a)
{
RS=0;
RW=0;

DATA=a;
EN=1;
__delay_ms(30);
EN=0;
}

void display(unsigned char b)
{
RS=1;
RW=0;

DATA=b;EN=1;
__delay_ms(30);
EN=0;
}

void main()
{
TRISD=0x00;
TRISC=0x00;
OPTION=0x07;
TMR0=44;


command(0x38);
command(0x0c);
command(0x06);
command(0x80);

for(int i=0;i<16;i++)
{
	display(first_line[i]);
}
command(0xC0);
for(int j=0;j<=31;j++)
{
	display(second_line[j]);
if(j==13)
{
for(int l=1;l<=9;l++)
{
command(0x18);
}
}
}


}


void delay()
{
	
	for(int k=0;k<92;k++)
	{
	
		while(!T0IF);
		T0IF=0;
}
}
		


