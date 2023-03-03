#include "Button.h"

/* 存放所有按钮信息的数组 */
button_type button_list[BUTTON_NUM];

/* 按钮状态存储 */
uint8_t Button_Press_Count[BUTTON_NUM+1] = {0};
uint8_t Button_Release_Count[BUTTON_NUM+1] = {0};

/* 防误触阈值 */
int Threshold = 2;

/* 创建按钮对象 */
static button_type Create_Button(uint8_t pin_,uint8_t key_)
{
    button_type new_button;
    new_button.pin = pin_;
    new_button.key = key_;
    return new_button;
}

/* 按钮初始化 */
void Button_Init()
{
    if(FOUR_BUTTON_VERSION)//当前为四按钮版本
    {
        pinMode(BUTTON1,INPUT_PULLUP);
        pinMode(BUTTON2,INPUT_PULLUP);
        pinMode(BUTTON3,INPUT_PULLUP);
        pinMode(BUTTON4,INPUT_PULLUP);
    }
}

/* 清空按钮按下计数 */
static void Clear_Button_Press_Count()
{
    for(int i=0;i<BUTTON_NUM;i++) Button_Press_Count[i] = 0;
}

/* 清空按钮抬起计数 */
static void Clear_Button_Release_Count()
{
    for(int i=0;i<BUTTON_NUM;i++) Button_Release_Count[i] = 0;
}

/* 检查按钮状态，是被按下、被持续按下、被抬起还是空状态 */
uint8_t Get_Button_State(uint8_t Buttonx)
{
    if(digitalRead(Buttonx) == LOW)
    {
        Clear_Button_Release_Count();
        if(Button_Press_Count[Buttonx]++ < Threshold)
        {
            return VOID;
        }
        else if(Button_Press_Count[Buttonx]++ == Threshold)
        {
            return PRESSED;
        }
        else return HOLDING;
    }
    else
    {
        Clear_Button_Press_Count();
        if(Button_Release_Count[Buttonx]++ < Threshold)
        {
            return HOLDING;
        }
        else if(Button_Release_Count[Buttonx]++ == Threshold)
        {
            return RELEASED;
        }
        else return VOID;
    }
}
