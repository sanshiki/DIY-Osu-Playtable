#include "Button.h"
#include "Remote_Keyboard.h"

/* 按钮引脚号 */
uint8_t BUTTON_PIN[BUTTON_NUM] = {BUTTON1,BUTTON2,BUTTON3,BUTTON4};

/* 存放所有按钮信息的数组 */
button_type button_list[BUTTON_NUM];

/* 按钮状态存储 */
uint8_t Button_Press_Count[BUTTON_NUM+1] = {0};
uint8_t Button_Release_Count[BUTTON_NUM+1] = {0};

/* 防误触阈值 */
int Threshold = 14;

/* 初始化按钮对象 */
static void Buttonx_Init(button_type *buttonx, uint8_t pin_)
{
    buttonx->pin = pin_;
}

/* 按钮初始化 */
void Button_Init()
{
    if(FOUR_BUTTON_VERSION)//当前为四按钮版本
    {
        for(int i=0;i<BUTTON_NUM;i++)
        {
            Buttonx_Init(&button_list[i],BUTTON_PIN[i]);
            pinMode(button_list[i].pin,INPUT_PULLUP);
        }
        /* 提供标准低电平参考 */
        pinMode(STD_LOW1,OUTPUT);
        pinMode(STD_LOW2,OUTPUT);
        digitalWrite(STD_LOW1,LOW);
        digitalWrite(STD_LOW2,LOW);
    }
}

// /* 清空按钮按下计数 */
// // static void Clear_Button_Press_Count()
// // {
// //     for(int i=0;i<BUTTON_NUM;i++) Button_Press_Count[i] = 0;
// // }

// static void Clear_Button_Press_Count(int Buttonx)
// {
//     Button_Press_Count[Buttonx] = 0;
// }

// /* 清空按钮抬起计数 */
// // static void Clear_Button_Release_Count()
// // {
// //     for(int i=0;i<BUTTON_NUM;i++) Button_Release_Count[i] = 0;
// // }

// static void Clear_Button_Release_Count(int Buttonx)
// {
//     Button_Release_Count[int Buttonx] = 0;
// }

/* 设置按钮状态 */
void Set_Button_State(int Buttonx,uint8_t state_)
{
    button_list[Buttonx].state = state_;
}

/* 获取按钮状态 */
uint8_t Get_Button_State(int Buttonx)
{
    return button_list[Buttonx].state;
}

/* 刷新按钮状态，是被按下、被持续按下、被抬起还是空状态 */
void Refresh_Button_State(int Buttonx)
{
    if(Get_Button_State(Buttonx) != HOLDING && digitalRead(button_list[Buttonx].pin) == LOW)
    {
        button_list[Buttonx].release_cnt = 0;//清空抬起计数
        if(button_list[Buttonx].press_cnt < Threshold)
        {
            button_list[Buttonx].press_cnt++;
            Set_Button_State(Buttonx,VOID);
        }
        else if(button_list[Buttonx].press_cnt == Threshold)
        {
            Set_Button_State(Buttonx,PRESSED);
        }
    }
    else if(Get_Button_State(Buttonx) != VOID && digitalRead(button_list[Buttonx].pin) == HIGH)
    {
        button_list[Buttonx].press_cnt = 0;//清空按下计数
        if(button_list[Buttonx].release_cnt < Threshold)
        {
            button_list[Buttonx].release_cnt++;
            Set_Button_State(Buttonx,HOLDING);
        }
        else if(button_list[Buttonx].release_cnt == Threshold)
        {
            Set_Button_State(Buttonx,RELEASED);
        }
    }
}

// /* 检查按钮状态，是被按下、被持续按下、被抬起还是空状态 */
// uint8_t Get_Button_State(int Buttonx)
// {
//     if(digitalRead(Buttonx+1) == LOW)
//     {
//         Clear_Button_Release_Count();
//         if(Button_Press_Count[Buttonx]++ < Threshold)
//         {
//             return VOID;
//         }
//         else if(Button_Press_Count[Buttonx] == Threshold)
//         {
//             return PRESSED;
//         }
//         else return HOLDING;
//     }
//     else
//     {
//         Clear_Button_Press_Count();
//         if(Button_Release_Count[Buttonx]++ < Threshold)
//         {
//             return HOLDING;
//         }
//         else if(Button_Release_Count[Buttonx] == Threshold)
//         {
//             return RELEASED;
//         }
//         else return VOID;
//     }
// }

/* 按钮挂起 */
void Button_Suspend(int Buttonx)
{
    if(Get_Button_State(Buttonx) == PRESSED)
    {
        Set_Button_State(Buttonx,HOLDING);
    }
    else if(Get_Button_State(Buttonx) == RELEASED)
    {
        Set_Button_State(Buttonx,VOID);
    }
}
