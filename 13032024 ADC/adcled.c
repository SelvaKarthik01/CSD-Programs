#include<lpc214x.h>

int main()
{
	unsigned int val;
	val=0x000003ff;
	PINSEL1=0X01000000;
	SCS=0X02;
	FIO1MASK=0XFF00FFFF;
	FIO1DIR=0X00FF0000;
	FIO1PIN=0X00000000;
	AD0CR=0X00200E02;
	while(1)
	{
		AD0CR|=0X01000000;
		do
		{
		val=AD0DR1;
		}
		while((val&0X80000000)==0);
		FIO1PIN=(val<<8);
	}
	 return 0;
}