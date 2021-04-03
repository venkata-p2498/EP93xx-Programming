#include<stdio.h>
#define	led ((volatile unsigned*)(0x80840020))
#define	leddir ((volatile unsigned*)(0x80840024))
void delay();
int main()
{
  *leddir=0x03;
  while(1)
  { //delay();
    *led=0x01;
    delay();
    *led=0x02;
    delay();
    //*led=0x00;
  }
}
void delay()
{
  int i;
  for(i=0;i<1000000;i++); 
}
