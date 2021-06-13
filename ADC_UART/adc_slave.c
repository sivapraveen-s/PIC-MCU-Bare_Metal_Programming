//#include<pic.h>
//#define _XTAL_FREQ  20000000
//__CONFIG(0x3F3A);
//#define RS RC0
//#define RW RC1
//#define EN RC2
//char y;
//char data_rx[4];
//void lcd_display(unsigned char,unsigned char);
//void receive();
//char data1;
//int i;
//int main()
//{
//TRISC6=0;
//TRISC7=1;
//TRISB=0x00;
//TRISC0=0;
//TRISC1=0;
//TRISC2=0;
//GIE=1;
//PEIE=1;
//TXEN=1;
//SYNC=0;
//TRMT=1;
//BRGH=1;
//SPEN=1;
//CREN=1;
//SPBRG=129;
//
//lcd_display(0x38,0);
//lcd_display(0x01,0);
//lcd_display(0x06,0);
//lcd_display(0x0C,0);
//lcd_display(0x80,0);
////lcd_display('P',1);
////lcd_display('O',1);
////lcd_display('T',1);
////lcd_display(':',1);
////lcd_display(0x84,0);
//
////while(1)
////{
////lcd_display('S',1);
////receive();
////lcd_display(data1,1);
////__delay_ms(30);__delay_ms(30);__delay_ms(30);
////receive();
////lcd_display(data1,1);
////__delay_ms(30);__delay_ms(30);__delay_ms(30);
////
////}
//
//while(1)
//{
//for(i=0;i<4;i++)
//{
//receive();
//lcd_display(data_rx[i],1);
//}
//
//}
//}
//
//void receive()
//{
//if(RCIF==0);
//RCIF=0;
//y=RCREG;
//data_rx[i]=y;
//}
//
//void lcd_display(unsigned char data,unsigned char cmd)
//{
//RS=cmd;
//RW=0;
//PORTB=data;
//EN=1;
//__delay_ms(20);
//EN=0;
//}






#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
#define RS RB0
#define RW RB1
#define E RB2
int count=0;
int i;
char rx,add,addr,value,data[4];
void lcd_cmd(char);
void lcd_data(char);
void receive();
void display(char,char);
void delay();

void main()
{
TRISB=0x00;
TRISD=0x00;
TRISC6=0;
TRISC7=1;
GIE=1;
TXSTA=0x26;
BRGH=1;
SPEN=1;
CREN=1;
RCIE=1;
SPBRG=129;
lcd_cmd(0x01);
lcd_cmd(0x0C);
lcd_cmd(0x06);
lcd_cmd(0x38);
lcd_cmd(0x80);
display(0x80,'U');
display(0x81,'A');
display(0x82,'R');
display(0x83,'T');
display(0x84,':');
display(0xC5,'T');
display(0xC6,'E');
display(0xC7,'M');
display(0xC8,'P');
display(0xC9,':');
display(0xCE,0xDF);
display(0xCF,'C');
while(1)
{
for(i=0;i<4;i++)
{
receive();
if(count==1 || count==2 || count==3 || count==4)
{
add=i+0xC0;
display(add,data[i]);
}
else if(count==5 || count==6 || count==7 || count==8)
{
add=i+0x85;
display(add,data[i]);
}
else if(count==9 || count==10 || count==11 || count==12 )
{
add=i+0xCA;
display(add,data[i]);
}
if(count==12)
count=0;

}
}
}

void lcd_cmd(char a)
{
RS=0;
RW=0;
E=1;
PORTD=a;
for(int k=0;k<=10;k++);
E=0;
delay();
}
void lcd_data(char b)
{
RS=1;
RW=0;
E=1;
PORTD=b;
for(int k=0;k<=10;k++);
E=0;
delay();
}
void receive()
{
while(RCIF!=1);
count++;
rx=RCREG;
RCIF=0;
data[i]=rx;
}

void display(char addr,char value)
{
lcd_cmd(addr);
lcd_data(value);
}
void delay()
{
for(int m=0;m<=500;m++);
}
