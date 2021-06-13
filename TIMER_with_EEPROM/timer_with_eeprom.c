#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RC0
#define RW RC1
#define EN RC2
int read_data;
void display(unsigned char,unsigned char);
void eeprom_write(unsigned char a,unsigned char b);
int i,j,k;
int EEPROM_Read(unsigned int adress)
{
EEADR=adress;
EEPGD=0;
RD=1;
read_data=EEDATA;
return read_data;
}


void main()
{
TRISC=0x00;
TRISB=0x00;
PORTC=0x00;
PORTB=0x00;
TRISD=0xFF;
PORTD=0x00;

EEDATA=0x00;
EEADR=0x00;
display(0x38,0);
display(0x0C,0);
display(0x06,0);
display(0x01,0);
display(0x80,0);
display('C',1);
display('O',1);
display('U',1);
display('N',1);
display('T',1);
display(':',1);
display(0x86,0);

int count=eeprom_read(0x0A);
i=(count/100)%10;
j=(count/10)%10;
k=count%10;

display(i+0x30,1);
display(j+0x30,1);
display(k+0x30,1);
while(1)
{
if(RD0==1)
{
display(0x86,0);
while(RD0==1);
count++;
eeprom_write(count,0x0A);
i=(count/100)%10;
j=(count/10)%10;
k=count%10;

display(i+0x30,1);
display(j+0x30,1);
display(k+0x30,1);
__delay_ms(30);
}
}
}

void display(unsigned char data,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTB=data;
EN=1;
__delay_ms(30);
EN=0;
}

void eeprom_write(unsigned char a,unsigned char b)
{
while(WR);
EEDATA=a;
EEADR=b;
EEPGD=0;
WREN=1;
EECON2=0x55;
EECON2=0xAA;
WR=1;
WREN=0;
}


