#include "head.h"

unsigned P0_DAT = 0xff;
unsigned char count = 0;
unsigned char stat = 0;




void LED_config(unsigned char ledx,unsigned char ledx_en)
{
	if(ledx_en == 0)
		P0_DAT |= 0x01<<(ledx-1);
	else
		P0_DAT &= ~(0x01<<(ledx-1));
	
	P0 = P0_DAT;
}


void led_pwm()
{
	pwm_led_sw();
	count ++;
	if(count == pwm_duty)
	{
		LED_config(1,1);
	}
	else if(count == 100)
	{
		LED_config(1,0);
		count = 0;
	}
	

}