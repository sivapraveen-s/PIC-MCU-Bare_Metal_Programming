#include<pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F3A);
char data,rx;
void receive();
int main()
{
TRISB=0x00;
PORTB=0x00;
TRISC6=0;
TRISC7=1;
GIE=1;
TXSTA=0x26;
BRGH=1;
SPEN=1;
CREN=1;
RCIE=1;
SPBRG=129;

while(1)
{
receive();
while(data=='1')
{
PORTB=0xFF;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
}
while(data=='0')
{
PORTB=0x00;
__delay_ms(30);__delay_ms(30);__delay_ms(30);__delay_ms(30);
}
}
}

void receive()
{
while(RCIF!=1);
rx=RCREG;
RCIF=0;
data=rx;
}
