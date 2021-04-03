#include<stdio.h>
#define i2stx0lt ((volatile unsigned*)(0x80820010))
#define i2stx0rt ((volatile unsigned*)(0x80820014))
#define i2stxctrl ((volatile unsigned*)(0x8082002c))
#define i2stx0enb ((volatile unsigned*)(0x80820034))
#define i2stxclk_cfg ((volatile unsigned*)(0x80820000))
#define i2sglob_sts ((volatile unsigned*)(0x80820008))
#define i2stxlncon ((volatile unsigned*)(0x80820028))
#define i2stx_wdlen ((volatile unsigned*)(0x80820030))
#define i2stx_globcon ((volatile unsigned*)(0x8082000c))

int data[30] = {0x20,0x28,0x30,0x37,0x3c,0x3f,0x40,0x3f,0x3c,0x37,0x30,0x28,0x20,0x18,0x10,0x09,0x04,0x01,0x00,0x01,0x04,0x09,0x10,0x18,0x20};
int i,j=0;

void main()
{
    	*i2stx0enb  = 0x00;
	*i2stxctrl = 0x00;
	*i2stxlncon=0x04;
	*i2stx_wdlen = 0x00;
	*i2stxclk_cfg = 0x0e;
	*i2stx_globcon = 0x01;
	
	while(1)
	{  if(j>25)
	    {j=0;}
	  for(i=j;i<(j+8);i++)
	{ 
	  *i2stx0lt = data[i];
	  *i2stx0rt = data[i];
	  j++;
	 }  
	*i2stx0enb  = 0x01;
	while((*i2sglob_sts&0x01)!=0x01);
	*i2stx0enb  = 0x00;
    }	 
	
}
