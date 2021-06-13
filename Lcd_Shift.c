#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
#define RS RB1
#define RW RB2
#define EN RB3

unsigned char first[]={"Welcome to embedded programming here im gng to develop"};
unsigned char second[]={"embedded job in automotive domain"};
//unsigned char sec[]={"embed"};


void delay()
{
__delay_ms(20);
__delay_ms(20);
__delay_ms(20);
}

void command(unsigned char a)
{
RS=0;
RW=0;
PORTC=a;
EN=1;
delay();
EN=0;
}

void data(long b)
{
RS=1;
RW=0;
PORTC=b;
EN=1;
delay();
EN=0;
}

void main()
{
TRISB=0x00;
TRISC=0x00;

command(0x38);
command(0x0c);
command(0x06);
command(0x01);
int size=sizeof first;
int size2=sizeof second;
while(1)
{
for(int i=0;i<=size;i++)
{
data(first[i]);
delay();
if(i>=15)
{
for(int k=1;k<=1;k++)
{
command(0x18);
}
if(i>=size)
{
command(0x85);
command(0x01);
__delay_ms(30);
for(int j=0;j<100;j++)
{
data(second[j]);
delay();
if(j>=15)
{
for(int k=1;k<=1;k++)
{
command(0x18);
}
delay();

}
}

}
}
}
//for(int h=1;h<=7;h++)
//{command(0x18);
//}
//
}
}
