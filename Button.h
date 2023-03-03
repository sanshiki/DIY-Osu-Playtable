#ifndef __BUTTON_H
#define __BUTTON_H

#include "Pin.h"
#include "Arduino.h"

#define FOUR_BUTTON_VERSION 1

/* 按钮个数 */
#define BUTTON_NUM          4

/* 按钮状态 */
enum Button_State{
    VOID,
    HOLDING,
    PRESSED,
    RELEASED
};

/* 按钮参数结构体 */
typedef struct Button_Param_Structure{
    uint8_t pin;
    uint8_t key;
    uint8_t state=RELEASED;
} button_type;

void Button_Init();
uint8_t Get_Button_State(uint8_t Buttonx);


#endif
