#include <reg52.h>
#include <intrins.h>

// 定义按钮引脚
sbit Button = P1^7;
sbit LED = P1^6;


// 延时函数(软延时代码可以在stc-isp中计算得到)
void Delay1000ms(void)	//@5.5296MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do{
		do{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay10ms(void)	//@5.5296MHz
{
	unsigned char data i, j;

	_nop_();
	_nop_();
	i = 54;
	j = 198;
	do
	{
		while (--j);
	} while (--i);
}


// 按键检测函数（带延时去抖）
unsigned char button_check(void) {
    if (Button == 0) {  // 检测到按键按下
        Delay10ms();      // 延时10ms消除抖动
			return 0;   // 返回按键无效
    }
		return 1;
}

void main() {
	Button = 1;
	LED = 1 ; 
	while(1) {
        if (!button_check()) {
					while(1){
							// 执行按键功能
						LED = !LED ; 
						//一秒后改变状态
						Delay1000ms();
						if(Button==1){//当按钮被松开后终止闪烁
							break ; 
						}
					}
				}
    }
}