#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RC2
#define RW RC1
#define EN RC0
#define DATA PORTB
int i;
int count=0;
int result1,result2;
void display(unsigned char dat,unsigned char cmd);
void receive();
unsigned char adc[5]={"MAdc:"};
int data=0;
int result_adc;
int result;
int data_lcd;
int data_disp[4];
void main()
{
TRISA5=1;


TRISB=0x00;
PORTB=0x00;
TRISC0=0;
TRISC1=0;
TRISC2=0;
TRISC3=1;
TRISC4=1;
TRISC5=0;

//spi slave intilization

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


display(0x38,0);
display(0x01,0);
display(0x06,0);
display(0x0C,0);
display(0x80,0);


for(int k=0;k<5;k++)
{
display(adc[k],1);
}
display(0x85,0);
display(data_disp[0]+0x30,1);
display(data_disp[1]+0x30,1);
display(data_disp[2]+0x30,1);
display(data_disp[3]+0x30,1);
while(1)
{
//display(0x85,0);
//data=result1;
//data=(data<<8)+result2;
//
//data_disp[0]=(data/1000)%10;
//data_disp[1]=(data/100)%10;
//data_disp[2]=(data/10)%10;
//data_disp[3]=data%10;


result_adc=result1;
result_adc=(result_adc<<8)+result2;
data_disp[0]=(result_adc/1000)%10;
data_disp[1]=(result_adc/100)%10;
data_disp[2]=(result_adc/10)%10;
data_disp[3]=result_adc%10;
display(0x85,0);
display(data_disp[0]+0x30,1);
display(data_disp[1]+0x30,1);
display(data_disp[2]+0x30,1);
display(data_disp[3]+0x30,1);
display(0x85,0);

if(count==1)
{
result1=data;
__delay_ms(30);
}
if(count==2)
{
result2=data;
__delay_ms(30);
}

if(count==2)
count=0;


//display(0x85,0);
//data_disp[0]=(data/1000)%10;
//data_disp[1]=(data/100)%10;
//data_disp[2]=(data/10)%10;
//data_disp[3]=data%10;
//
//display(0x85,0);
//display(data_disp[0]+0x30,1);
//display(data_disp[1]+0x30,1);
//display(data_disp[2]+0x30,1);
//display(data_disp[3]+0x30,1);
//display(0x85,0);
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

//void receive()
//{
//while(!SSPIF);
////count++;
//result=SSPBUF;
//
//data_disp[i]=result;
//BF=0;
//SSPOV=0;
//SSPIF=0;
//}
//
void interrupt ISR()
{
if(SSPIF)
{
count++;
data=SSPBUF;
//PORTD=data;
SSPIF=0;
BF=0;
SSPOV=0;

}
}

