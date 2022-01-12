#include <LPC213X.h>
#define sw (1<<10)

void delay();
int i;
unsigned char interrupt;

int main()
{
		IODIR0 = 0XFFFFFFFF;
		IODIR0 |= (~sw);
		interrupt = 0;
	
		while(1)
		{
			interrupt = IOPIN0 & sw;
			
			if(interrupt == sw) //clockwise direction
			{
				IOCLR0 = 0x9;	
				IOCLR0 = 0xC;	
				IOCLR0 = 0x6;
				IOCLR0 = 0x3;	
			}
			
			else //Stops when interrupt is encountered 
			{
				IOSET0 = 0x3; //0011
				delay();
				IOCLR0 = 0x3;
				
				IOSET0 = 0x6; //0110
				delay(); 	
				IOCLR0 = 0x6;
				
				IOSET0 = 0xC; //1100
				delay();
				IOCLR0 = 0xC;
				
				IOSET0 = 0x9; //1001s
				delay();
				IOCLR0 = 0x9;						
			}	
		}
}

void delay()
{
	for(i=0; i<=5000;i++)
		for(i=0; i<=150000; i++);
	
}