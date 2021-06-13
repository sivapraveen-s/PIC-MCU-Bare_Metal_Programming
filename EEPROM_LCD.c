#include<pic.h>
#define _XTAL_FREQ 20000000
#define RS RB0
#define RW RB1
#define EN RB2
int n=5;
int count=0,count1;
unsigned char byte;
void EEPROM_Write(unsigned char a,unsigned char b)
{
EEDATA=a;
EEADR=b;
EEPGD=0;
WREN=1;
EECON2=0x55;
EECON2=0xAA;
WR=1;
while(EEIF==0);
WREN=0;
EEIF=0;

}

void EEPROM_Read(unsigned char address)
{
EEADR=address;
EEPGD=0;
RD=1;
byte=EEDATA;	
}

lcd_disp(unsigned char l,unsigned char f)
{
RS=f;
RW=0;
PORTC=l;
EN=1;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
EN=0;
}
int main()
{
TRISB=0x00;
PORTB=0x00;
TRISC=0x00;
TRISD=0x00;
PORTD=0;
EEDATA=0x00;
EEADR=0x00;

EEPROM_Read(0x0A);
if(RD0==1)
{
count++;
count1=count;
EEPROM_Write(count,0x0A);
while(byte>0)
{
RB6=1;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
RB6=0;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
byte--; 
}
}
}

//lcd_di sp(0x38,0);
//lcd_disp(0x0c,0);
//lcd_disp(0x01,0);
//lcd_disp(0x06,0);
//for(int u=1;u<=2;u++)
//{
//EEPROM_Write(5,0x0A);
//EEPROM_Write('A',0x0B);
//EEPROM_Read(0x0B);
//lcd_disp(byte,1);
//__delay_ms(30);__delay_ms(30);
//EEPROM_Read(0x0A);
//lcd_disp(0xC0,0);
//lcd_disp(byte+0x30,1);
//__delay_ms(30);__delay_ms(30);
//
//
//EEPROM_Read(0x0B);
//lcd_disp(0x85,0);
//lcd_disp(byte,1);
//__delay_ms(30);__delay_ms(30);
//EEPROM_Read(0x0A);
//lcd_disp(0xC5,0);
//lcd_disp(byte+0x30,1);
//__delay_ms(30);__delay_ms(30);
//

