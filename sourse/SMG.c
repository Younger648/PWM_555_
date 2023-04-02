#include "head.h"

unsigned char adr_1;
unsigned char dat_1;

/************************************数码管选值**********************************/
unsigned char code SMG_duanma[22] ={	
	0xc0,//0
	0xf9,//1
	0xa4,//2
	0xb0,//3
	0x99,//4
	0x92,//5
	0x82,//6
	0xf8,//7
	0x80,//8
	0x90,//9
	0x88,//A
	0x83,//B
	0xc6,//C
	0xa1,//D
	0x86,//E
	0x8e, //F
	0x8c,//P
	0xc1,//U
	0x91,//Y,L
	0xbf,//-
	0x7f,
  0xff};


/*********************************数码管位置***************************************/
unsigned char code SMG_weizhi[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void SMG_config(unsigned char adr,unsigned char dat)
{
	SelectHC138(6);
	P0 = adr;
	delay(1);
	SelectHC138(7);
	P0 = dat;

}

void SMG_show()
{
	static unsigned char i;
	i ++;
	if(i == 8)
		i = 0;
	
	switch(i)
	{
		case 0:
			adr_1 = 0;
		  dat_1 = 0;
		break;
			
		case 1:
			adr_1 = 1;
		  dat_1 = 1;
		break;
			
		case 2:
			adr_1 = 2;
		  dat_1 = 2;
		break;
					
		case 3:
			adr_1 = 3;
		  dat_1 = 3;
		break;
							
		case 4:
			adr_1 = 4;
		  dat_1 = 4;
		break;
									
		case 5:
			adr_1 = 5;
		  dat_1 = 5;
		break;
											
		case 6:
			adr_1 = 6;
		  dat_1 = 6;
		break;
		
		case 7:
			adr_1 = 7;
		  dat_1 = 7;
		break;
	
	}
	SMG_config(SMG_weizhi[adr_1],SMG_duanma[dat_1]);
}



