
#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
#define RS RC0
#define RW RC1
#define E RC2
int count=0;
int i;
char rx,add,addr,value,data;
void lcd_cmd(char);
void lcd_data(char);
void receive();
void display(char,char);
void delay();

void main()
{
TRISB=0x00;
TRISC=0x00;
TRISC6=0;
TRISC7=1;
GIE=1;
TXSTA=0x26;
BRGH=1;
SPEN=1;
CREN=1;
RCIE=1;
SPBRG=129;
lcd_cmd(0x01);
lcd_cmd(0x0C);
lcd_cmd(0x06);
lcd_cmd(0x38);
lcd_cmd(0x80);
display(0x80,'O');
display(0x81,'N');
display(0x82,':');

display(0x85,'O');
display(0x86,'F');
display(0x87,'F');
display(0x88,':');
display(0xC2,'s');
display(0xC3,'t');
display(0xC4,' ');
display(0xC5,'C');
display(0xC6,'Y');
display(0xC7,'C');
display(0xC8,'L');
display(0xC9,'E');

while(1)
{
receive();
//display(0x85,data);
if(count==1)
{
display(0x83,data);
}
if(count==2)
{
display(0x89,data);
}
if(count==3)
{
display(0xC0,data);
count==0;
}
//if(count==3)
//{
//count=0;
//}
}
}

void lcd_cmd(char a)
{
RS=0;
RW=0;
E=1;
PORTB=a;
for(int k=0;k<=10;k++);
E=0;
delay();
}
void lcd_data(char b)
{
RS=1;
RW=0;
E=1;
PORTB=b;
for(int k=0;k<=10;k++);
E=0;
delay();
}
void receive()
{
while(RCIF!=1);
count++;
rx=RCREG;
RCIF=0;
data=rx;
}

void display(char addr,char value)
{
lcd_cmd(addr);
lcd_data(value);
}
void delay()
{
for(int m=0;m<=500;m++);
}
