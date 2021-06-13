#include<pic.h>
#define _XTAL_FREQ 20000000
int flag=0;
int value=0;
int i;
int count=0;
int seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};





void interrupt ISR()
{  
    if(T0IF==1)
    {
		count++;
		T0IF=0; 
		if(count==92)
	{
		value=~value;
       count=0;
              
    }
	if(INTF==1)
	{
INTF=0;
for(int s=i;s>1;s--)
{
	RC0=1;
	__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
	PORTD=seg[i];
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
RC0=0;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
i--;
if(i>=1)
{
	RC0=0;
	PORTD=0xC0;
}
}
}
}
}
void main()
{    
    TRISC=0x00;   
	TRISD=0x00;
	TRISB=0xFF;
PORTD=0xc0;
PORTC=0;
OPTION=0x07;
T1CON=0x01;



 TMR0=44;
    T0IE=1;     
    GIE=1;         
    PEIE=1; 
	INTE=1;
       
while(1)
{
if(RB1==1)
{
PORTD=seg[i];
__delay_ms(30);__delay_ms(30);__delay_ms(30);
i++;                       
while(RB1==1);
if(i==10)
{
i=9;
}
}
}
}

















































//#include<pic.h>
//#define _XTAL_FREQ 20000000
//#define sw1 RB1
//
//__CONFIG(0x3F72);
//int seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
//
//int i=0;
//int count=0;
//
//
//
//
//void main()
//{
//	TRISC=TRISD=0x00;
//	TRISB=0b00000011;
//PORTC=0x00;
//	OPTION=0x07;
//PORTD=0xC0;
//INTCON=0xF0;
//TMR0=44;
//
//
//while(1)
//{
//if(RB1==1)
//{
//
//PORTD=seg[i];
//__delay_ms(30);
// i++;                       
//while(RB1==1);
//if(i==10)
//{
//i=9;
//	
//
//}
//
//}
//}
//}
//
//
//
//void interrupt ISR(void)
//{
//	if(INTF!=0)
//	{	
//		INTF=0;
//		while(!T0IF);
//		T0IF=0;
//		count++;
//		if(count==92)
//		{
//		while(1)
//		{	
//			PORTD=seg[i];
//			RC0=0xFF;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
//			__delay_ms(30);
//			RC0=0X00;
//			i--;	
//			if(i==0)
//			{
//			i=0;
//			PORTD=seg[i];
//			PORTC=0x00;
//			}	
//	}
//}
//}
//}
