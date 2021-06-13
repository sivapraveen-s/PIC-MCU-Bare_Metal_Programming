#include<pic.h>
#define _XTAL_FREQ 20000000
#define LED RC0

int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; 	
int i=0,l=20,count=0,n=1;	
int temp;
int main()
{
TRISB=0X00;
TRISC=0X00;
PORTB=0X40;
PORTC=0X00;

INTCON=0xE0;
OPTION=0x07;

while(1)
{
PORTB=seg[i];
while(temp<1)
{
for(int k=n;k>1;k--)
{

temp--;
LED=1;
__delay_ms(30);
LED=0;
__delay_ms(30);
}
}
while(i>=9 & l<=10)
{

PORTB=seg[l];

if(i==20 & l==0)
{
i=0;
l=20;
while(i>=10 & l<=10);
}
}

if(i==10)
{n=n++;
temp=n;
}
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
l=l--;

count=0;
}
}
}
