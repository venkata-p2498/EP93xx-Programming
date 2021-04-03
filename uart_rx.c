#include<stdio.h>
#define	led ((volatile unsigned*)(0x80840020))
#define	leddir ((volatile unsigned*)(0x80840024))
#define powerctrl ((volatile unsigned *)(0x80930004))

#define uart1data ((volatile unsigned *)(0x808c0000))
#define uart1low ((volatile unsigned *)(0x808c0010))
#define uart1mid ((volatile unsigned *)(0x808c000c))
#define uart1high ((volatile unsigned *)(0x808c0008))
#define uart1ctrl ((volatile unsigned *)(0x808c0014))

#define vic1intselect ((volatile unsigned *)(0x800b000c))
#define vic1intenable ((volatile unsigned *)(0x800b0010))
#define vic1intenclr ((volatile unsigned *)(0x800b0014))
#define vic1vectaddr0 ((volatile unsigned *)(0x800b0100))
#define vic1vectctrl0 ((volatile unsigned *)(0x800b0200))

void receive_isr(void);
__inline int enable_IRQ(void);

int i=1;

 int x=0;
int main()
{	*leddir=0x03;
	*vic1intselect=0x00;
	*vic1intenable=0x00800000;
	*vic1vectaddr0=(unsigned)receive_isr;
	*vic1vectctrl0=0x37;
	
	*powerctrl=0x00;
	
	*uart1mid=0x00;
	*uart1low=0x2f;
	*uart1high=0x60;
	*uart1ctrl=0x11;	
	
	
	enable_IRQ();
	
	while(1);
}

void receive_isr(void)
{	
	x=*uart1data;
	
	
	printf("\n%x\n",x);
	
		//*vic1intenable = 0x00800000;

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
