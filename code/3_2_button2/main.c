// 按一下切换一下LED状态
#include <reg52.h>

// 定义按钮引脚
sbit Button = P1^7;
sbit LED = P1^6;


// 延时函数
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = ms; i > 0; i--)
        for (j = 110; j > 0; j--);
}

// 按键检测函数（带延时去抖）
unsigned char button_check(void) {
    if (Button == 0) {  // 检测到按键按下
        delay(10);      // 延时10ms消除抖动
        if (Button == 0) {  // 再次检测确认
            while (Button == 0);  // 等待按键松开
            delay(10);  // 延时10ms消除松开时的抖动
            return 1;   // 返回按键有效
        }
    }
    return 0;   // 返回按键无效
}

void main() {
	Button = 1;
	LED = 1 ; 
	while(1) {
        if (button_check()) {
            // 执行按键功能
					LED = !LED ; 
        }
    }
}