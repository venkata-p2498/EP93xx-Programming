#include<stdio.h>

//==========INITIALIZATION OF POWER CONTROL REGISTERS==========
#define powerctrl ((volatile unsigned *)(0x80930004))

//==========INITIALIZATION OF UART REGISTERS===================
#define uart1data ((volatile unsigned *)(0x808c0000))
#define uart1low ((volatile unsigned *)(0x808c0010))
#define uart1mid ((volatile unsigned *)(0x808c000c))
#define uart1high ((volatile unsigned *)(0x808c0008))
#define uart1ctrl ((volatile unsigned *)(0x808c0014))
#define uart1flag ((volatile unsigned *)(0x808c0018))
#define uart1intr ((volatile unsigned *)(0x808c001c))

//==========INITIALIZATION OF VIC REGISTERS===================
#define vic1intselect ((volatile unsigned *)(0x800b000c))
#define vic1intenable ((volatile unsigned *)(0x800b0010))
#define vic1vectaddr0 ((volatile unsigned *)(0x800b0100))
#define vic1vectaddr ((volatile unsigned  *)(0x800b0030))
#define vic1vectctrl0 ((volatile unsigned *)(0x800b0200))

void transmission_isr(void);

int enable_IRQ(void);

unsigned char s[30]={0x02,0x06,0x90,0x00,0x00,0x03};
unsigned int i=0;

int main()
{
	*powerctrl=0x00;
	*uart1low=0x2f;
	*uart1mid=0x00;
	*uart1high=0x60;
	*vic1intselect=0x00;
	
	*vic1vectaddr0=(unsigned)transmission_isr;
	*vic1vectctrl0=0x38;
	
	
	*uart1ctrl=0x21;
	*vic1intenable=0x1000000;
	enable_IRQ();
	*uart1data=s[i];
	while(1);
}

void transmission_isr()
{
	//unsigned int i=1;
	if(i<20)
	{
		*uart1data=s[i];
		i++;
	}
	else
	{
		*vic1intenable=0x00;
	}
}

__inline int enable_IRQ(void)
{
	int tmp;
	{
		__asm
		{
			MRS tmp,CPSR
			BIC tmp,tmp,#0x80
			MSR CPSR_c,tmp
		}
	}
}
