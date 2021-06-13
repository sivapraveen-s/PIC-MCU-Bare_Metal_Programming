#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RB0
#define RW RB1
#define EN RB2
#define DATA PORTC
float disp_volt[4];
int disp_temp[4];
int a,b,c,d;
float temp_value;
int result;
int voltage;
int temp1;
float cel;
void lcd_display(unsigned char,unsigned char);
float result1;
char temp[]={"Temp:"};
char volt[]={"Voltage:"};

int main()
{
TRISB=0x00;
TRISC=0x00;
TRISD=0x00;
PORTB=0x00;
PORTC=0x00;
PORTD=0x00;
TRISA=0xFF;


lcd_display(0x38,0);
lcd_display(0x01,0);
lcd_display(0x06,0);
lcd_display(0x0C,0);
lcd_display(0x80,0);
for(int i=0;i<6;i++)
{
lcd_display(temp[i],1);
__delay_ms(30);
}
lcd_display(0xC0,0);
for(int j=0;j<8;j++)
{
lcd_display(volt[j],1);
__delay_ms(30);
}

while(1)
{

ADCON0=0xCD;
ADCON1=0x80;
ADGO=1;
while(ADGO==1);
__delay_ms(30);
result=ADRESH;
result=(ADRESH<<8)+ADRESL;
result1=result;
result1=result1*0.488;
voltage=result1;

temp_value=(result1/1024.0)*5000;
cel=temp_value/10;
temp1=cel;
//temp_value=result1/10.0;
//temp1=temp_value*100;

disp_temp[0]=temp1%10;
temp1=temp1/10;
disp_temp[1]=temp1%10;
temp1=temp1/10;
disp_temp[2]=temp1%10;
temp1=temp1/10;
disp_temp[3]=temp1%10;

lcd_display(0x85,0);
lcd_display(disp_temp[3]+0x30,1);
lcd_display(disp_temp[2]+0x30,1);
lcd_display('.',1);
lcd_display(disp_temp[1]+0x30,1);
lcd_display(disp_temp[0]+0x30,1);
lcd_display(0x85,0);

disp_volt[0]=voltage%10;
voltage=voltage/10;
disp_volt[1]=voltage%10;
voltage=voltage/10;
disp_volt[2]=voltage%10;
voltage=voltage/10;
disp_volt[3]=voltage%10;


lcd_display(0xC8,0);
lcd_display(disp_volt[3]+0x30,1);
lcd_display(disp_volt[2]+0x30,1);
lcd_display(disp_volt[1]+0x30,1);
lcd_display('.',1);
lcd_display(disp_volt[0]+0x30,1);
__delay_ms(30);
lcd_display(0xC8,0);
}
}


void lcd_display(unsigned char data,unsigned char cmd)
{
RS=cmd;
RW=0;
PORTC=data;
EN=1;
__delay_ms(30);
EN=0;
}




