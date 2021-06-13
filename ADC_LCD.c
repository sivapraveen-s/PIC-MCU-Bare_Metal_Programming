#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);   // configuration bits setting
#define RS RB0		//defining LCD RS,RW,EN for RB0,RB1,RB2
#define RW RB1
#define EN RB2

int temp=0;
void lcd_display(unsigned char dat,unsigned char cmd);	//declaring function
unsigned char adc[11]={"ADC:"};


int result=0;
int a,b,c,d,disp[4];

void main()
{
TRISA=1;			//seting portA as input for adc(pot) input
TRISC=0x00;			
TRISB=0x00;
PORTA=PORTB=PORTC=0x00;

lcd_display(0x38,0);
lcd_display(0x01,0);
lcd_display(0x0C,0);
lcd_display(0x06,0);
lcd_display(0x80,0);
for(int i=0;i<4;i++)		// to display adc:
{
lcd_display(adc[i],1);
__delay_ms(30);
}

lcd_display(0x84,0);


ADCON0=0xC5;				// set the internal A/D module oscillator and set ADON bit and Go/Done to 1 to start the conversion
ADCON1=0x8E;				//Right justified and set RA0 to analog pin

while(1)
{
ADGO=1;					//start the ADC conversion
while(ADGO==1);
result=ADRESH;					//make the 8 bit to 10 bit conversion
result=(result<<8)+ADRESL;		//stored as 10bit

disp[0]=(result/1000)%10;
disp[1]=(result/100)%10;
disp[2]=(result/10)%10;
disp[3]=result%10;

lcd_display(0x84,0);			// lcd command to display in 6th poistion
lcd_display(disp[0]+'0',1);
lcd_display(disp[1]+'0',1);
lcd_display(disp[2]+'0',1);
lcd_display(disp[3]+'0',1);

}
}

void lcd_display(unsigned char dat,unsigned char cmd)  //Lcd Command & Data intilize
{
RS=cmd;
RW=0;
PORTC=dat;
EN=1;
__delay_ms(30);
EN=0;
}

