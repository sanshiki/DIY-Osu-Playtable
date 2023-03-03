#ifndef __REMOTE_KEYBOARD_H
#define __REMOTE_KEYBOARD_H

#include "Pin.h"
#include "Arduino.h"
#include <Keyboard.h>

/* 按钮对应键盘按键 */
#define BUTTON_1_KEY        'S'
#define BUTTON_2_KEY        'D'
#define BUTTON_3_KEY        'K'
#define BUTTON_4_KEY        'L'

void Remote_Keyboard_Init();
void Remote_Keyboard_Press_Down(uint8_t Buttonx);
void Remote_Keyboard_Release(uint8_t Buttonx);

#endif
