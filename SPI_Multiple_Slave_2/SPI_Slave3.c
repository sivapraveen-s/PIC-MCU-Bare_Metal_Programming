#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RC0
#define RW RC1
#define EN RC2
#define DATA PORTB

void display(unsigned char dat,unsigned char cmd);
int data=3;
char temp[5]={"Temp:"};
int result;
unsigned char disp[4];
void main()
{
TRISA0=1;
TRISB=0x00;
TRISC0=0;
TRISC1=0;
TRISC2=0;
TRISC3=1;
TRISC4=1;
TRISC5=0;
TRISD=0x00;
PORTB=0x00;
PORTC=0x00;
PORTD=0x00;
PORTA=0x00;

TRISA5=1;   //declare input for multiple slave  mode and clear the pin
CKE=1;
CKP=1;
SMP=0;
SSPEN=1;
SSPM0=0;
SSPM1=0;
SSPM2=1;
SSPM3=0;
GIE=1;
SSPIE=1;
PEIE=1;


ADCON0=0xC5;		// 11000101
ADCON1=0x8E;		// 10001110 (first pin analog 2 and 3 are digital switch)





display(0x38,0);
display(0x01,0);
display(0x06,0);
display(0x0C,0);
display(0x80,0);
for(int k=0;k<5;k++)
{
display(temp[k],1);
__delay_ms(30);
}
ADCON0=0xC5;				//1100 0101
ADCON1=0x80;				//1000 0000


while(1)
{
//ADCON0=0xC5;				//1100 0101
//ADCON1=0x80;				//1000 0000

if(1)
{
display(0x85,0);
ADGO=1;
while(ADGO==1);
result=ADRESH;
result=(result<<8)+ADRESL;
result=result*0.4887;
//SSPBUF=result;
disp[0]=(result/1000)%10;
disp[1]=(result/100)%10;
disp[2]=(result/10)%10;
disp[3]=result%10;

display(disp[1]+0x30,1);
display(disp[2]+0x30,1);
display(disp[3]+0x30,1);
display(0xDF,1);
display('C',1);
//display(0x86,0);
}

if(data=='A')
{
SSPBUF=result;
__delay_ms(30);
}

PORTD=data;
__delay_ms(30);

}
}


void display(unsigned char dat,unsigned char cmd)
{
RS=cmd;
RW=0;
DATA=dat;
EN=1;
__delay_ms(30);
EN=0;
}

void interrupt ISR()
{
if(SSPIF)
{
data=SSPBUF;
PORTD=data;
SSPIF=0;
BF=0;
SSPOV=0;
}
}
