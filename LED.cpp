#include "LED.h"

/* 按钮引脚号 */
uint8_t LED_PIN[LED_NUM] = {LED1,LED2};

/* 存放所有按钮信息的数组 */
LED_type led_list[LED_NUM];

/* 初始化LED对象 */
static void LEDx_Init(LED_type *LEDx, uint8_t pin_)
{
    LEDx->pin = pin_;
}

/* LED初始化 */
void LED_Init()
{
    for(int i=0;i<LED_NUM;i++)
    {
        LEDx_Init(&led_list[i],LED_PIN[i]);
        pinMode(led_list[i].pin,OUTPUT);
    }
}
/* 开启LED */
void LED_ON(int LEDx)
{
    digitalWrite(led_list[LEDx].pin,HIGH);
    led_list[LEDx].state = ON;
}

/* 关闭LED */
void LED_OFF(int LEDx)
{
    digitalWrite(led_list[LEDx].pin,LOW);
    led_list[LEDx].state = OFF;
}
