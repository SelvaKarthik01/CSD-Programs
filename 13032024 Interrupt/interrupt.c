#include<lpc214x.h>
void delay(void);
void ext_int_init();
void Ext_ISR(void);
int main(void)
{
IODIR0=0X00000000;
IO1DIR=0X00FF0000;
ext_int_init();
while(1)
{
IO1SET=0X00FF0000;
delay();
IO1CLR=0X00FF0000;
delay();
}
}
void ext_int_init()
{
EXTMODE=0X2;
EXTPOLAR&=~(0X2);
PINSEL0=0X20000000;
VICIntSelect &= ~(1<<15);
VICVectAddr5=(unsigned int)Ext_ISR;
VICVectCntl5=(1<<5)|15;
VICIntEnable=(1<<5);
}
void Ext_ISR(void)
{
IO1SET=0X00550000;
delay();
IO1CLR=0X00550000;
EXTINT |=0X2;
VICVectAddr=0;
}
void delay()
{
int i,j;
for(i=0;i<4000;i++)
{
for(j=0;j<4000;j++)
{
}
}
}