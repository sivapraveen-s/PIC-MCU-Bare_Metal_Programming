#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);

int a,b,c,d,result;
void send(unsigned char data);


int main()
{
TRISA=0xff;
TRISB=0x00;
PORTB=0;
TRISC6=0;
TRISC7=1;
TXSTA=0x26;
TXEN=1;
TRMT=1;
BRGH=1;
SPBRG=129;
SPEN=1;

while(1)
{
ADCON0=0xC5;
ADCON1=0x8E;
ADGO=1;
while(ADGO==1);
result=ADRESH;
result=(result<<8)+ADRESL;

a=result%10;
result=result/10;
b=result%10;
result=result/10;
c=result%10;
result=result/10;
d=result%10;

//while(RB0==1)
//{
//send(1);
//__delay_ms(30);
//}
//while(RB0==0)
//{
send(d+0x30);
send(c+0x30);
send(b+0x30);
send(a+0x30);
__delay_ms(30);
}

}

void send(unsigned char data)
{
	TXREG=data;
while(!TRMT);
__delay_ms(30);
}



