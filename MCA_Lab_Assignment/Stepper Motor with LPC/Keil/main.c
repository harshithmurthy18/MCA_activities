#include <LPC213X.h>

void delay();
int i;
unsigned char direction;

int main()
{
		IODIR0 = 0XFFFFFFFF;
		direction = 0;
	
		while(1)
		{
			if(direction == 0) //clockwise direction
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
			
			else if(direction == 1) //anticlockwise direction
			{
				IOSET0 = 0x9;
				delay();
				IOCLR0 = 0x9;	

				IOSET0 = 0xC;
				delay();
				IOCLR0 = 0xC;

				IOSET0 = 0x6;
				delay(); 	
				IOCLR0 = 0x6;

				IOSET0 = 0x3;
				delay();
				IOCLR0 = 0x3;				
			}	
		}
}

void delay()
{
	for(i=0; i<=5000;i++)
		for(i=0; i<=150000; i++);
	
}