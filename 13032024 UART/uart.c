#include<LPC214X.h>
void pll()
{
 PLL0CON=0X01;
 PLL0CFG=0X24;
 PLL0FEED=0XAA;
 PLL0FEED=0X55;
 while(!(PLL0STAT & (1<<10)));
 PLL0CON=0X03;
 PLL0FEED=0XAA;
 PLL0FEED=0X55;
 VPBDIV=0X01;
 }
 
 int main()
 {
  int C;
  PINSEL0=0X00000005;
  U0LCR=0X83;
  U0DLL=0X87;
  U0DLM=0X01;
  U0LCR=0X03;
  pll();
  while(1)
  {
   while(! (U0LSR & 0X01));
   C=U0RBR;
   C=C+5;
   while(! (U0LSR & 0X20));
   U0THR=C;
   }
 }
