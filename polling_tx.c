#include<stdio.h>
#define uart1data ((volatile unsigned *)(0x808c0000))
#define powerctrl ((volatile unsigned *)(0x80930004))
#define uart1low ((volatile unsigned *)(0x808c0010))
#define uart1mid ((volatile unsigned *)(0x808c000c))
#define uart1high ((volatile unsigned *)(0x808c0008))
#define uart1ctrl ((volatile unsigned *)(0x808c0014))
#define uart1flag ((volatile unsigned *)(0x808c0018))
unsigned char s[30]="Programming with ARM";
unsigned int i;
unsigned char b;

int main()
{
	
	*powerctrl=0x00;
	*uart1low=0x2f;
	*uart1mid=0x00;
	*uart1high=0x60;
	*uart1ctrl=0x01;
	
	for(i=0;i<21;i++)
	{
		*uart1data=s[i];
		next:
		b=*uart1flag & 0x80;
		if(b!=0x80)
		goto next;

	}
}
