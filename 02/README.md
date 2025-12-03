# 8 字型 LED 焊接

## 物料介绍

| 物料名称      | 数量 |
| ------------- | ---- |
| 8字型LED数码管 | 1    |
| 电阻（220Ω）  | 8    |
| 单片机开发板  | 1    |
| 面包板        | 1    |
| 杜邦线        | 若干 |

## 软件介绍

| 软件名称 |
| -------- |
| Keil C51 |
| STC-ISP  |

## 前置知识

1. [LED](../knowledge_base/led/README.md)
2. [电阻](../knowledge_base/resistor/README.md)

## 8字型LED 原理介绍

![原理介绍](img/001.jpg)

原理介绍：
我们将多个LED并联成一列，每个LED的阳极连接到一起，阴极的一端连接到单片机的IO口，那么我们就可以通过编程来自由控制LED所输出的数字的样式。

## 电路图

![电路图](img/002.svg)

## 焊接注意事项

1. 确保LED数码管的引脚方向正确，不要接反
2. 电阻的焊接要注意阻值匹配，避免电流过大损坏LED
3. 焊接时温度控制在300-350℃之间，避免长时间加热损坏元件
4. 焊接完成后检查是否有短路或虚焊现象

## 相关知识点

| 知识点   | 地址 |
| -------- | ---- |
| LED      | [../knowledge_base/led/README.md](../knowledge_base/led/README.md) |
| 电阻     | [../knowledge_base/resistor/README.md](../knowledge_base/resistor/README.md) |
