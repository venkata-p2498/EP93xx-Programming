#include<stdio.h>
#define	led ((volatile unsigned*)(0x80840020))
#define	leddir ((volatile unsigned*)(0x80840024))
#define	t1load ((volatile unsigned*)(0x80810000))
#define	t1value ((volatile unsigned*)(0x80810004))
#define	t1control ((volatile unsigned*)(0x80810008))
#define	t1clear ((volatile unsigned*)(0x8081000c))
#define vic1irq ((volatile unsigned*)(0x800b0000))
#define vic1intselect ((volatile unsigned*)(0x800b000c))
#define vic1intenable ((volatile unsigned*)(0x800b0010))
#define vic1vectaddr0 ((volatile unsigned*)(0x800b0100))
#define vic1vectctrl0 ((volatile unsigned*)(0x800b0200))
void timer_isr(void);
__inline void enable_irq(void);
int main()
{
  *leddir=0x03;
  *led=0x01;
   *vic1intselect=0x00;
  *vic1intenable=0x10;
  *vic1vectaddr0=(unsigned)timer_isr;
  *vic1vectctrl0=0x24;
  *t1load=0x07d0;
  *t1control=0xc0;
  enable_irq();
  while(1);
  
}
__inline void enable_irq(void)
{
  int temp;
  __asm
  {
    MRS  temp,CPSR
    BIC  temp,temp,#0x80
    MSR  CPSR_c,temp
  }
}
void timer_isr(void)
{
  
  *led=~*led;
  *t1clear=0x00;
}
