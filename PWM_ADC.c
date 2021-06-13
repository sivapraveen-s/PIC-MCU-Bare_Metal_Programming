#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
void InitPwm(void);
void SetPwm(unsigned int);
int Adc_result;
int main()
{
TRISA=0xFF;
TRISC2=0;

ADCON0=0xC5;
ADCON1=0x8E;

InitPwm();

while(1)
{
ADGO=1;
while(ADGO==1);
Adc_result=ADRESH;
Adc_result=(ADRESH<<8)+ADRESL;

SetPwm(Adc_result);
__delay_ms(33);
}
}
//while(1)
//{
//for(int i=0;i<1024;i++)
//{
//SetPwm(i);
//__delay_ms(30);
//}
//}

void InitPwm(void)
{
TRISC2=0;
CCP1CON=0x0C;    //00001100
PR2=0xff;
T2CON=0x01;
T2CON |=0x04;
SetPwm(0);
}
void SetPwm(unsigned int dutycycle)  //duty cycle is 10 bit
{
CCPR1L=dutycycle>>2;		//pulling LSB of adc 10bit value will be shifted out bcoz the lsb bit of ADRESH+ADRESL value will be stored in 5,4 bit of CCP1CON
CCP1CON &=0xCF;		//11001111
CCP1CON |=(0x30&(dutycycle<<4));	00110000 & (11 1111 1111<<4) == (00110000 &11 1111 0000) and OR with CCP1CON 11001111 || 11 1111 0000== CCP1CON= 1111 0000
}


