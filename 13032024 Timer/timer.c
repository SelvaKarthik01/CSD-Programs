#include<lpc214x.h>
void delay(unsigned int a);
void pll();
int main(void)
{
IO1DIR=0XFFFFFFFF;
pll();
while(1)
{
IO1SET=0XFFFFFFFF;
delay(1000);
IO1CLR=0XFFFFFFFF;
delay(1000);
}
}
void pll()
{
	PLL0CON=0X01;
	PLL0CFG=0X24;
	PLL0FEED=0Xaa;
	PLL0FEED=0X55;
	while(!PLL0STAT & (1<<10));
	PLL0CON=0X03;
	PLL0FEED=0Xaa;
	PLL0FEED=0X55;
	VPBDIV=0X01;
}
void delay(unsigned int x)
{
	T0CTCR=0X0;
	T0TCR=0X00;
	T0PR=59999;
	T0TCR=0X02;
	T0TCR=0X01;
	while(T0TC<x);
	T0TCR=0X00;
	T0TC=0;
}