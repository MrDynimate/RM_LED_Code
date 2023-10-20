#ifndef __WS2812_LED_H__
#define __WS2812_LED_H__

#include "tim.h"

#define ONE_PULSE 54
#define ZERO_PULSE 26                        

#define LED_NUM 8
#define LED_DATA_LEN 24
#define RESET_PULSE_LEN 80  
#define DATA_BUFFER_LEN RESET_PULSE_LEN+(LED_DATA_LEN*LED_NUM)

uint16_t static data_buffur[DATA_BUFFER_LEN] = { 0 };

void led_init(void);
void led_on(void);
void led_set(uint8_t led_id, uint8_t value_r, uint8_t value_g, uint8_t value_b);


#endif