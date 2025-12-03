# 第一个 51 程序

## 物料介绍

| 物料名称  | 数量 |
| --------- | ---- |
| STC12C052 | 1    |
| LED 8 个  | 1    |
| 面包板    | 1    |
| 杜邦线    | 若干 |

## 软件介绍

| 软件名称 |
| -------- |
| Keil C51 |
| STC-ISP  |

# 相关知识点

| 知识点 | 地址 |
| ------ | ---- |
| LED    | [../knowledknowledge_basege/led/README.md](../knowledge_base/led/README.md) |

## 编写 LED 常亮示例程序

```c
#include <reg52.h>
sbit LED = P0^0;
void main() {
    LED = 0;  // 点亮第一个 LED
    while(1);
}
```
