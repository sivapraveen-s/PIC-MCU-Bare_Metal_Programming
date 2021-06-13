#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3FA);

#define RS RC5
#define RW RC6
#define EN RC7
#define sw1 RA0
#define sw2 RA1
#define sw3 RA2
#define sw4 RA3
#define sw5 RA4
#define sw6 RA5
#define LED RC4


int seg[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int i=0,a,b,c,d,e,f,g,h;

int on=0,off=0,on_time1=0,off_time1=0,ontime_value=0,offtime_value=0,mode_count=0,total_time=0,Ledon_count=0,Ledoff_count=0;
int cycle_time=1,q=0,w=0;
//void send(unsigned char data);
void timer_delay();
void display(unsigned char,unsigned char);
void main()
{
TRISB=0x00;
TRISC=0x00;
TRISD=0x00;
TRISA=0xFF;
TXSTA=0x26;
SPBRG=129;
SPEN=1;

PORTB=0;
PORTC=0x00;
PORTD=0;
PORTA=0;

ADCON0=0x00;
ADCON1=0x07;
OPTION=0x07;

display(0x38,0);
display(0x01,0);
display(0x0C,0);
display(0x06,0);
display(0x80,0);
display('O',1);
display('N',1);
display(':',1);
display(0x85,0);
display('O',1);
display('F',1);
display('F',1);
display(':',1);
display(0xC0,0);
display('M',0);
display('O',0);
display('D',0);
display('E',0);
display(':',0);



while(1)   
{
display('s',1);
//mode_count=1; on time set
//mode_count=2; off time set
//mode_count=3; total time set

if(sw1==1)
{
mode_count++;
__delay_ms(30);
while(sw1==1);
}
if(mode_count==0)
{
i=0;
}

if(mode_count==1)	//seting on time
{
if(sw2==1)
{
ontime_value=++on_time1;
i=ontime_value;
__delay_ms(30);
while(sw2==1);
}
else if(sw3==1)
{
ontime_value=--on_time1;
i=ontime_value;
__delay_ms(30);
while(sw3==1);
}
}
if(mode_count==2)	//setting off time
{
if(sw2==1)
{
offtime_value=++off_time1;
i=offtime_value;
__delay_ms(30);
while(sw2==1);
}
else if(sw3==1)
{
offtime_value=--off_time1;
i=offtime_value;
__delay_ms(30);
while(sw3==1);
}
}
if(mode_count==3) // on time set
{
if(sw2==1)
{
++total_time;
i=total_time;
__delay_ms(30);
while(sw2==1);
}
else if(sw3==1)
{
--total_time;
i=total_time;
__delay_ms(30);
while(sw3==1);
}
}
if(mode_count==4)
{
mode_count=0;
}
on=ontime_value;
off=offtime_value;

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
__delay_ms(5);
RC0=0;

PORTB=seg[e];
RC1=1;
__delay_ms(5);
RC1=0;

PORTB=seg[c];
RC2=1;
__delay_ms(5);
RC2=0;

PORTB=seg[a];
RC3=1;
__delay_ms(5);
RC3=0;

//send(mode_count+0x30);

while(sw4==1)
{
//int q=on;
//int w=off;
for(q=on;q>0;q--)
{
LED=1;
timer_delay();
Ledon_count++;
//send(Ledon_count+0x30);
}

for(w=off;w>0;w--)
{
LED=0;
timer_delay();
Ledoff_count++;
//send(Ledoff_count+0x30);
}

//send(cycle_time+0x30);
cycle_time++;
q=on;
w=off;
}
}
}

void timer_delay()
{
for(int l=0;l<76;l++)
{
TMR0=0;
while(!T0IF);
T0IF=0;
}
}
void display(unsigned char lcd_data,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTD=lcd_data;
EN=1;
__delay_ms(7);
EN=0;
}


//void send(unsigned char data)
//{
//	TXREG=data;
//while(!TRMT);
//__delay_ms(30);
//}

//void timer_delay(int t)
//{
//for(int m=0;m<t;m++)
//{
//for(int l=0;l<76;l++)
//{
//TMR0=0;
//while(!T0IF);
//T0IF=0;
//}
//}
//}

