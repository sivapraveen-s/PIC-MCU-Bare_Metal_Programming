#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);

#define RS RC0
#define RW RC1
#define EN RC2

int data=0;
void lcd_display(unsigned char dat,unsigned char cmd);

void main()
{
TRISB=0x00;
TRISD=0x00;
PORTB=0x00;
PORTD=0x00;
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

TRISC0=0;
TRISC1=0;
TRISC2=0;

TRISC3=1;
TRISC4=1;
TRISC5=0;





lcd_display(0x80,0);
lcd_display(0x06,0);
lcd_display(0x01,0);
lcd_display(0x38,0);
lcd_display(0x0C,0);
lcd_display('C',1);
lcd_display('O',1);
lcd_display('U',1);
lcd_display('N',1);
lcd_display('T',1);
lcd_display(':',1);

while(1)
{
lcd_display(0x86,0);
lcd_display(data+0x30,1);
__delay_ms(30);
}

}


void lcd_display(unsigned char dat,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTB=dat;
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
