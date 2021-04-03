#include<stdio.h>
#define led((volatile unsigned*)(0x80840020))
#define leddir((volatile unsigned*)(0x80840024))
#define	 t1load((volatile unsigned*)(0x80810000))
#define	  t1value((volatile unsigned*)(0x80810004))
#define t1control((volatile unsigned*)(0x80810008))
//#define t1clear((volatile unsigned*)(0x8081000c))

void delay();
int main()
{
  
  *leddir=0x03;
  
  while(1)
  { 
    *led=0x01;
    delay();
    *led=0x02;
    delay();
  }
}

void delay()
{ 
  *t1load=2000;
  *t1control=0x000000c0;
  while(*t1value!=0)
  {;}
 
}
