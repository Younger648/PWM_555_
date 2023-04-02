#include "head.h"


void Timer0Init()		//100微秒@12.000MHz
{

	TMOD = 0x01;		//设置定时器模式
	TL0 = (65535 - 100) % 256;
	TH0 = (65535 - 100) / 256;

	ET0 = 1;
	EA = 1;
  TR0 = 1;

}


void ServiceTimer0() interrupt 1
{
  static unsigned char ms_100 = 0;
	static unsigned char ms_1000 = 0;
	
	TL0 = (65535 - 10) % 256;
	TH0 = (65535 - 10) / 256;
	
	ms_100 ++;
	ms_1000 ++;
	
	if(ms_100 == 10)
	{
		
		led_pwm();
		ms_100 = 0;
	}
	
	
	
	if(ms_1000 == 100)
	{
		SMG_show();
		ms_1000 = 0;
	}
	


}








void main()
{
	SelectHC138(4);
	Timer0Init();
	while(1)
	{
		
		SconKey();
	}
}



