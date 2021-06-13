#include<pic.h>
#define _XTAL_FREQ 20000000
#define red_light RB0
#define yellow_light RB1
#define green_light RB2

int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int i=0,j=0,k=0,seg_count=0,count;
void display_green();

void main()
{
TRISB=0X00;
TRISC=0X00;
PORTB=0;
PORTC=0x40;

INTCON=0xE0;
OPTION=0x07; 

while(1)
{
if(i==1)
{
red_light=1;
yellow_light=0;
green_light=0;

}
if(j==10)
{
seg_count=0;
red_light=0;
yellow_light=1;

green_light=0;
}
if(k==15)
{
seg_count=0;
red_light=0;
yellow_light=0;
green_light=1;
}
if(i==25 & j==25 & k==25)
{
i=0;
j=0;
k=0;
seg_count=0;
}
 

PORTC=seg[seg_count];




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
seg_count=seg_count+1;
i=i+1;
j=j+1;
k=k+1;
count=0;
}
}
}

