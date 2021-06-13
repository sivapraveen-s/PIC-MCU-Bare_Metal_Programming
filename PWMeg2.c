#include<pic.h>
#define _XTAL_FREQ 20000000

void InitPwm(void);
void SetPwm(unsigned int);
int Adc_result;
int main()
{
//TRISA=0xFF;
TRISC2=0;

InitPwm();

while(1)
{
for(int i=0;i<1024;i++)
{
SetPwm(i);
__delay_ms(30);
}
}
}
void InitPwm(void)
{
TRISC2=0;
CCP1CON=0x0C;
PR2=0xff;
T2CON=0x01;
SetPwm(0);
T2CON |=0x04;
}
void SetPwm(unsigned int dutycycle)
{
CCPR1L=dutycycle>>2;
CCP1CON &=0xCF;
CCP1CON |=(0x30&(dutycycle<<4));
}


