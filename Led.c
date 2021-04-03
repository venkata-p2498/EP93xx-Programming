#include<stdio.h>
#define	LED((volatile unsigned *)(0x80840020))
#define	DIRLED((volatile unsigned *)(0x80840024))

void delay(void);
int main(void)
{
*DIRLED=0x03;//configuring GPIO pins as output
while(1)
	{
		 delay();	
		*LED=0x01;	//switching GreenLED ON
		 delay();
		*LED=0x02;	//switching RedLED ON
		 delay();
		*LED=0x00;	//switching OFF
		 delay();
		*LED=0x02;	//switching RedLED ON
		 delay();
	}	
}

void delay(void)
{
long int i=0,j=0;
for(i=0;i<10000;i++)
	{
		for(j=0;j<1000;j++);	
	}
	
}
