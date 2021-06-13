#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RB0
#define RW RB1
#define EN RB2
#define DATA PORTD

int send_count=0;
int result1,result2;
int led_count=0;
int temp_value;
int l,value[4];
void display(unsigned char dat,unsigned char cmd);
int result;
int count=0;
int temp_data;
int disp[4]={1,2,3,4};
unsigned char temp[5]={"Temp:"};
int a,b,c,d;
void spi_send(int value);
//int count=5;
int led_count2=0;
void main()
{
TRISA=0xFF;
PORTA=0x00;
	
TRISB0=0;		//RS 
TRISB1=0;		//RW
TRISB2=0;		//EN
TRISB4=1;		//Slave 1 send
TRISB5=1;		//Slave 2 send
TRISB6=1;		//Slave 3 send

TRISC0=0;		//slave 1 chip select
TRISC1=0;		//slave 2 chip select
TRISC2=0;		//slave 3 chip select
TRISC3=0;		//spi clk pin
TRISC4=1;		//spi SDI data input pin
TRISC5=0;		//spi SDO data output pin

PORTB=0x00;
PORTC=0x00;
PORTD=0x00;
PORTA=0x00;

TRISD=0x00;
PORTD=0x00;

ADCON0=0xC5;		// 11000101
ADCON1=0x8E;		// 10001110 (first pin analog 2 and 3 are digital switch)

//spi configuration

SSPM3=0;
SSPM2=0;
SSPM1=0;
SSPM0=0;
SSPEN=1;
CKP=1;
SMP=0;
CKE=1;

GIE=1;		 	//enable interrupt for SPI recieve
SSPIE=1;		//spi interrupt enable
PEIE=1;

RC1=1;
RC2=1;
RC3=1;


display(0x38,0);
display(0x01,0);
display(0x06,0);
display(0x0C,0);
display(0x80,0);

for(int k=0;k<5;k++)
{
display(temp[k],1);
__delay_ms(7);
}
display(0xC0,0);
display('C',1);
display('O',1);
display('U',1);
display('N',1);
display('T',1);
display(':',1);
display(led_count+0x30,1);
display(0xC8,0);
display('C',1);
display('O',1);
display('U',1);
display('N',1);
display('T',1);
display('2',1);
display(':',1);
display(led_count2+0x30,1);


display(0x85,0);
display(disp[0]+0x30,1);
display(disp[1]+0x30,1);
display(disp[2]+0x30,1);
display(disp[3]+0x30,1);
display(0xDF,1);
display('C',1);

while(1)
{
disp[0]=(temp_data/1000)%10;
disp[1]=(temp_data/100)%10;
disp[2]=(temp_data/10)%10;
disp[3]=temp_data%10;

display(0x85,0);
display(disp[0]+0x30,1);
display(disp[1]+0x30,1);
display(disp[2]+0x30,1);
display(disp[3]+0x30,1);
display(0xDF,1);
display('C',1);
if(1)
{
ADGO=1;
while(ADGO==1);
result1=ADRESH;
result2=ADRESL;
result=ADRESH;
result=(result<<8)+ADRESL;
temp_value=result;
a=(result/1000)%10;
b=(result/100)%10;
c=(result/10)%10;
d=result%10;

value[0]=a;
value[1]=b;
value[2]=c;
value[3]=d;

}

if(RB4==1)		//slave 1 sending
{
while(RB4==1);
send_count++;
RC0=0;
RC1=1;
RC2=1;
if(send_count==1)
{
spi_send(result1);
__delay_ms(30);
}
if(send_count==2)
{
spi_send(result2);
__delay_ms(30);
}
if(send_count==2)
send_count=0;

//for(l=0;l<4;l++)      //sending split data
//{
//spi_send(value[l]);
//__delay_ms(30);
//}
}
if(RA1==1)    //slave 2 led_count value
{
while(RA1==1);
led_count++;
__delay_ms(30);
display(0xC6,0);
display(led_count+0x30,1);
__delay_ms(30);
display(0xC6,0);
}
if(RB5==1)		//slave 2 sending
{
while(RB5==1);
RC0=1;
RC1=0;
RC2=1;
spi_send(led_count);
__delay_ms(11);
}
if(RE0==1)			//count 2 seting
{
while(RE0==1);
led_count2++;
__delay_ms(30);
display(0xCF,0);
display(led_count2+0x30,1);
__delay_ms(30);
display(0xCF,0);
}

if(RB6==1)			//slave 3 sending
{
while(RB6==1);
RC0=1;
RC1=1;
RC2=0;
spi_send(led_count2);
__delay_ms(11);
}
if(RB7==1)
{
while(RB7==1);
RC0=1;
RC1=1;
RC2=0;
spi_send('A');
__delay_ms(30);
}
//temp_data=SSPBUF;
//__delay_ms(30);



}
}

//if(RA1==1)
//{
//while(RA1==1);
//count++;
//if(count==1)
//{
//RC0=0;
//RC1=1;
//RC2=1;
//spi_send(result1);
//__delay_ms(30);
//}
//if(count==2)
//{
//RC0=0;
//RC1=1;
//RC2=1;
//spi_send(result2);
//__delay_ms(30);
//
//if(count==3)
//count=0;
//}
//}



void display(unsigned char dat,unsigned char cmd)
{
RS=cmd;
RW=0;
DATA=dat;
EN=1;
__delay_ms(30);
EN=0;
}

void spi_send(int value)
{

SSPBUF=value;
while(!BF);
__delay_ms(30);
temp_data=SSPBUF;
__delay_ms(30);
}
//
//void interrupt ISR()
//{
//if(SSPIF)
//{
//temp_data=SSPBUF;
////PORTD=data;
//SSPIF=0;
//BF=0;
//SSPOV=0;
//}
//}
