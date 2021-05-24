#ifndef __UART_H__
#define __UART_H__

#include <regx52.h>
#include "definition.h"

/**
 * @brief 串口初始化函数
 * @param 无
 * @return 无
 */
void UART_Init();

/**
 * @brief 串口发送函数
 * @param byte 一个待发送字节
 * @return 无
 */
void UART_SendByte(uint8_t byte);

#endif // !__UART_H__
 