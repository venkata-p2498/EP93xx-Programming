#include<stdio.h>

#define powerctrl ((volatile unsigned *)(0x80930004))

#define uart1data ((volatile unsigned *)(0x808c0000))
#define uart1low ((volatile unsigned *)(0x808c0010))
#define uart1mid ((volatile unsigned *)(0x808c000c))
#define uart1high ((volatile unsigned *)(0x808c0008))
#define uart1ctrl ((volatile unsigned *)(0x808c0014))
#define uart1flag ((volatile unsigned *)(0x808c0018))

unsigned int i=0,b=0;
unsigned int x[10] ;
char a[10];
int main()
{
	*powerctrl=0x00;
	*uart1mid=0x00;
	*uart1low=0x2f;
	*uart1high=0x60;
	*uart1ctrl=0x01;	
	
	for(i=0;i<10;i++)
	{
	x[i]=*uart1data;
	a[i]=x[i];
	printf("%d\n",a[i]);
	/*next:
	b=(*uart1flag&0x10);
	if(b!=0x10)
	goto next;*/
	while((*uart1flag&0x10)==0x10);
	}
}
