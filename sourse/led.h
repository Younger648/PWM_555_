#ifndef __LED_H_
#define __LED_H_

extern unsigned P0_DAT;
extern unsigned char count;
extern unsigned char stat;


void LED_config(unsigned char ledx,unsigned char ledx_en);
void led_pwm();

#endif



