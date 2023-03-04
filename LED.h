#ifndef __LED_H
#define __LED_H

#include "Pin.h"
#include "Arduino.h"

#define LED_NUM 2

enum LED_state{
    OFF,
    ON
};

/* LED参数结构体 */
typedef struct LED_Param_Structure{
    uint8_t pin;
    uint8_t state=OFF;
} LED_type;

void LED_Init();
void LED_ON(int LEDx);
void LED_OFF(int LEDx);

#endif
