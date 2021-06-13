#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
#define RS RB0
#define RW RB1
#define EN RB2
#define Data_line PORTC
#define sw1 RD0

int disp[4];
unsigned char lcd_out=0,l1,l2;
unsigned char data1;

int lcd_display(unsigned char dat,unsigned char cmnd);
int EEPROM_Write(unsigned char,unsigned char);
int EEPROM_Read(unsigned char);

int main()
{
TRISD0=1;
TRISB=0x00;
TRISC=0x00;
PORTD=0;
int count=EEPROM_Read(0x0A);

lcd_display(0x38,0);
lcd_display(0x01,0);
lcd_display(0x0C,0);
lcd_display(0x06,0);
lcd_display(0x80,0);

lcd_display('V',1);
lcd_display('a',1);
lcd_display('l',1);
lcd_display('u',1);
lcd_display('e',1);
lcd_display(':',1);
while(1)
{

if(sw1==0)
{
count++;
EEPROM_Write(count,0x0A);
__delay_ms(30);
while(sw1==0);
}
lcd_out=EEPROM_Read(0x0A);
__delay_ms(30);

disp[0]=lcd_out%10;
lcd_out=lcd_out/10;
disp[1]=lcd_out%10;
lcd_out=lcd_out/10;
disp[2]=lcd_out%10;
lcd_out=lcd_out/10;
disp[3]=lcd_out%10;

lcd_display(0x87,0);
lcd_display(disp[3]+0x30,1);
lcd_display(disp[2]+0x30,1);
lcd_display(disp[1]+0x30,1);
lcd_display(disp[0]+0x30,1);
}
}

int EEPROM_Write(unsigned char data,unsigned char address)
{
while(WR);
EEDATA=data;
EEADR=address;
EEPGD=0;
WREN=1;
EECON2=0x55;
EECON2=0xAA;
WR=1;
WREN=0;
}

int EEPROM_Read(unsigned char adr)
{
EEADR=adr;
EEPGD=0;
RD=1;
data1=EEDATA;
return data1;
}

int lcd_display(unsigned char dat,unsigned char cmnd)
{
RS=cmnd;
RW=0;
Data_line=dat;
EN=1;
__delay_ms(30);
EN=0;
}


