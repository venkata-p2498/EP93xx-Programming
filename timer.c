#include<stdio.h>
#define	led ((volatile unsigned*)(0x80840020))
#define	leddir ((volatile unsigned*)(0x80840024))
#define tmr1_con ((volatile unsigned*) (0x80810008))
#define tmr1_load ((volatile unsigned*)(0x80810000))
#define tmr1_val ((volatile unsigned*)(0x80810004))
#define tmr1_clr ((volatile unsigned*)(0x8081000C))

void main(void)
 {	
   *leddir=0x03;
   *led=0x00;   
   *tmr1_con= 0x80;
   
   while(1){  
   *tmr1_load =2000;	   
   
   while(*tmr1_val!=0);
        *led = 0x01;
    *tmr1_load =2000;
      while(*tmr1_val!=0);
     *led = 0x02;     
     
     }
 	}
