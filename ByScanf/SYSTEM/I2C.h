#ifndef __I2C_H__
#define __I2C_H__

#include <REGX52.H>
#include "definition.h"

#define I2C_SCL P2_1
#define I2C_SDA P2_0

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start(void);

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void I2C_Stop(void);

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte);

/**
  * @brief  I2C接收一个字节
  * @param  无
  * @retval 接收到的一个字节数据
  */
unsigned char I2C_ReceiveByte(void);

/**
  * @brief  I2C发送应答
  * @param  AckBit 应答位，0为应答，1为非应答
  * @retval 无
  */
void I2C_SendAck(unsigned char AckBit);

/**
  * @brief  I2C接收应答位
  * @param  无
  * @retval 接收到的应答位，0为应答，1为非应答
  */
unsigned char I2C_ReceiveAck(void);


#endif
