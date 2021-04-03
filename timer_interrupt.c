#include<stdio.h>
#define	led((volatile unsigned*)(0x80840020))
#define	leddir((volatile unsigned*)(0x80840024))
#define tmr1_con((volatile unsigned*) (0x80810008))
#define tmr1_load((volatile unsigned*)(0x80810000))
#define tmr1_val((volatile unsigned*)(0x80810004))
#define tmr1_clr((volatile unsigned*)(0x8081000C))
#define vic1_enbl((volatile unsigned*)(0x800b0010))
#define vic1_slct((volatile unsigned*)(0x800b000c))
#define vic1_vadrs0((volatile unsigned*)(0x800b0100))
#define vic1_vcntrl0((volatile unsigned*)(0x800b0200))
void timer_ISR(void)
{
	*led=~*led;
	*tmr1_clr=0x00;
//	*tmr1_load =2000; 
	
}
__inline void enable_IRQ(void)
{
	int temp;

	__asm
	{
		MRS		temp,CPSR
		BIC		temp,temp,#0x80
		MSR		CPSR_c,temp;
		
	}
}	
  void main(void)
 {	
   *leddir=0x03;
   *led=0x00;
   enable_IRQ();
   *vic1_slct= 0x00;
   *vic1_enbl= 0x10;
   *vic1_vadrs0= (unsigned)timer_ISR;
   *vic1_vcntrl0 = 0x24;
    *tmr1_load =2000; 
   *tmr1_con= 0xc0;
   *led = 0x01;
       while(1);
   
 	}
