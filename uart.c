#include<stdio.h>
#define	PWRCNT((volatile unsigned *)(0x80930004))
#define	UART_DATA((volatile unsigned *)(0x808C0000)) 		//DATA TO BE LOADED
#define	UART_CONTROL_HIGH((volatile unsigned *)(0x808C0008))	//LENGTH,FIFO..ETC.
#define	UART_CONTROL_MID((volatile unsigned *)(0x808C000C))	//BAUD RATE DIVISOR(MSB)
#define	UART_CONTROL_LOW((volatile unsigned *)(0x808C0010))	//BAUD RATE DIVISOR(LSB)
#define	UART_CONTROL((volatile unsigned *)(0x808C0014))		//INTERRUPT, "UART ENABLE"...ETC.
#define	UART_FLAG((volatile unsigned *)(0x808C0018))		//FLAGS
unsigned char s[]=“EP9315 UART";

int main(void)
{
unsigned int i;
*PWRCNT=0x00;
*UART_CONTROL_LOW=0x002F;	// BAUD RATE 9600
*UART_CONTROL_MID=0x0000;
*UART_CONTROL_HIGH=0x0060; // 8 bit frame 
*UART_CONTROL=0x0001;		// UART ENABLE
for(i=0;i<11;i++)
		{
		*UART_DATA=s[i];	
		while((*UART_FLAG & 0x08)!=0x00); // TXE not HIGH		
		
		}
}
