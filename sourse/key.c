#include "head.h"


unsigned char sw = 1;
unsigned char pwm_duty = 0;


void delay(unsigned int t)
{
	while(t--);
}

void pwm_led_sw()
{
	if(sw == 1)
		pwm_duty = 10;
	else if(sw == 2)
		pwm_duty = 50;
	else if(sw == 3)		
		pwm_duty = 90;

}





void SconKey()
{
	R1 = 0;
	R2 = R3 = R4 = 1;
	C1 = C2 = C3 = C4 = 1;
	
	if(C4 == 0)
	{
		delay(100);
		if(C4 == 0)
		{
			sw ++;
		}
		while(C4 == 0);
	}
	
	
	if(sw == 4)
		sw = 1;
}
