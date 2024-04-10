#include<lpc214x.h>
unsigned long i;
void delay(unsigned int);
int main()
{
	int a=250;
	IO1DIR = 0x00ff0000;
	i = 0x00008000;
	while(a)
	{
		IO1SET = i;
		delay(250);
		IO1CLR = 0x00ff0000;
		i = i<<1;
		if(i==0x00100000)
		{
			i=0x00008000;
		}
		a = a-1;
	}
}
void delay(unsigned int count)
{
 unsigned int i,j=0;
 for(i=0;i<=count;i++)
 {
	 for(j=0;j<=69;j++)
	 {
	 }
 }
}