#include "Remote_Keyboard.h"

/* 远程键盘初始化 */
void Remote_Keyboard_Init()
{
    Keyboard.begin();
}

/* 远程键盘按下 */
void Remote_Keyboard_Press_Down(uint8_t Buttonx)
{
    switch(Buttonx)
    {
        case 1:Keyboard.press(BUTTON_1_KEY);break;
        case 2:Keyboard.press(BUTTON_2_KEY);break;
        case 3:Keyboard.press(BUTTON_3_KEY);break;
        case 4:Keyboard.press(BUTTON_4_KEY);break;
    }
}

/* 远程键盘抬起 */
void Remote_Keyboard_Release(uint8_t Buttonx)
{
    switch(Buttonx)
    {
        case 1:Keyboard.release(BUTTON_1_KEY);break;
        case 2:Keyboard.release(BUTTON_2_KEY);break;
        case 3:Keyboard.release(BUTTON_3_KEY);break;
        case 4:Keyboard.release(BUTTON_4_KEY);break;
    }
}