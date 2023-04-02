#include "head.h"


void TimerInit()		//100微秒@12.000MHz
{

	TMOD = 0x01;		//设置定时器模式
	TL0 = (65535 - 100) % 256;
	TH0 = (65535 - 100) / 256;
	
	TL1 = (65535 - 100) % 256;
	TH1 = (65535 - 100) / 256;
	
	ET0 = 1;
	ET1 = 1;
	
	EA = 1;
	
	TR0 = 1;
	TR1 = 1;

}




void ServiceTimer0() interrupt 1
{
	static unsigned char ms_10 = 0;
	
	TL0 = (65535 - 10) % 256;
	TH0 = (65535 - 10) / 256;
		
	ms_10 ++;
	if(ms_10 >= 10)
	{
		led_pwm();
		ms_10 = 0;
	}

}





void ServiceTimer1() interrupt 3
{
	static unsigned char ms_100 = 0;
	
	TL1 = (65535 - 10) % 256;
	TH1 = (65535 - 10) / 256;
	
	
	ms_100 ++;
	if(ms_100 >= 200)
	{
		SMG_show();
		ms_100 = 0;
	}

	
}





void main()
{
	SelectHC138(4);
	TimerInit();
	while(1)
	{

		SconKey();
	}
}



