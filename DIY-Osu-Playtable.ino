#include "include.h"

/* 程序延迟时间 */
#define DELAY_TIME 10

void setup()
{
    Button_Init();
    LED_Init();
    Remote_Keyboard_Init();
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
}

void loop()
{
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    for(int i=0;i<BUTTON_NUM;i++)
    {
        Refresh_Button_State(i);
        if(Get_Button_State(i) == PRESSED)
        {
            Remote_Keyboard_Press_Down(i);
            Button_Suspend(i);
            if(i < 2) LED_ON(0);
            else LED_ON(1);
        }
        else if(Get_Button_State(i) == RELEASED)
        {
            Remote_Keyboard_Release(i);
            Button_Suspend(i);
            if(i < 2) LED_OFF(0);
            else LED_OFF(1);
        }
    }
    //delayMicroseconds(DELAY_TIME);
}
