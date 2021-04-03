#include<stdio.h>
#define	led((volatile unsigned*)(0x80840020))
#define	leddir((volatile unsigned*)(0x80840024))
void main(void)
{  
  unsigned int	i,j;
	*led=0x00; 
   *leddir=0x03;
  while(1)
   { 
   // *led=0x00;
   // for(i=0;i<600;i++)
   // for(i=0;i<60000;i++);
      *led=0x02;
    for(j=0;j<600;j++)
    for(i=0;i<60000;i++);
    *led=0x01;
    for(j=0;j<600;j++)
   for(i=0;i<60000;i++);
   }
  }
