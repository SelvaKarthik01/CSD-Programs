#include<LPC21xx.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++){}
	}
}
int main()
{
	IODIR0 = 0x00000000;
	IODIR1 = 0x00ff0000;
	while(1)
	{
		if(IO0PIN & 0x00004000)
		{
			IOSET1 = 0x00550000;
			delay();
			IOCLR1 = 0x00550000;
			delay();
		}
		else
		{
			IOSET1 = 0x00aa0000;
			delay();
			IOCLR1 = 0x00aa0000;
			delay();
	 }
	}
}
		
  