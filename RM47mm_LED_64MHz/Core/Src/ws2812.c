#include "ws2812.h"

void led_init(void)
{
    for(uint8_t i = 0; i < LED_NUM; i++)
    {
        led_set(i, 0x00, 0x00, 0x00);
    }
}

void led_set(uint8_t led_id, uint8_t value_r, uint8_t value_g, uint8_t value_b)
{
    uint16_t* p = (data_buffur + RESET_PULSE_LEN) + (LED_DATA_LEN * led_id);
    for (uint16_t i = 0; i < 8; i++)
    {
            p[i]      = (value_g << i) & (0x80)? ONE_PULSE: ZERO_PULSE;
            p[i + 8]  = (value_r << i) & (0x80)? ONE_PULSE: ZERO_PULSE;
            p[i + 16] = (value_b << i) & (0x80)? ONE_PULSE: ZERO_PULSE;
    }
}

void led_on(void)
{
     HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_2, (uint32_t *)data_buffur, DATA_BUFFER_LEN);
}