#include "include.h"

/* 程序延迟时间 */
#define DELAY_TIME 100

void setup()
{
    Button_Init();
    LED_Init();
    Remote_Keyboard_Init();
}

void loop()
{
    for(int i=0;i<BUTTON_NUM;i++)
    {
        if(Get_Button_State(i) == PRESSED)
        {
            Remote_Keyboard_Press_Down(i);
        }
        else if(Get_Button_State(i) == RELEASED)
        {
            Remote_Keyboard_Release(i);
        }
    }
    delayMicroseconds(DELAY_TIME);
}
