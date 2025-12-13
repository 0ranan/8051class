# 关于按钮

## 相关知识点

| 知识点 | 地址 |
| ------ | ---- |
| LED    | [../knowledge_base/led/README.md](../knowledge_base/led/README.md) |
| 按钮    | [../knowledge_base/button/README.md](../knowledge_base/button/README.md) |
| 延时    | [../knowledge_base/delay/README.md](../knowledge_base/delay/README.md) |


## 物料介绍

| 物料名称  | 数量 |
| --------- | ---- |
| STC12C052 | 1    |
| LED 8 个  | 1    |
| 面包板    | 1    |
| 杜邦线    | 若干 |
| 按钮 1 个 | 1    |


## 程序1

按下按钮时，LED 点亮

```c
// 按一下切换一下LED状态
#include <reg52.h>

// 定义按钮引脚
// 按钮默认为电平，另一端接在gnd上，当电压被拉低时代表按钮被触发
sbit Button = P1^7;
//LED 另一端接在vcc,输出低电平代表点亮
sbit LED = P1^6;

void main() {
	Button = 1;
	LED = 1 ; 
	while(1) {
			LED = Button;
    }
}

```

## 程序2

任务：按下按钮时，LED 状态切换

软件去抖原理讲解：

- 按键抖动：当按钮按下或松开时，由于机械原因，会产生短暂的电压波动，导致检测到多个信号。
- 软件去抖：通过在检测到按键按下或松开后，延时一定时间，再判断是否真的发生了变化，从而过滤掉抖动信号。

```c
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
```

## 程序3

按下按钮时，LED 闪烁

``` c
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
```