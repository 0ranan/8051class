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