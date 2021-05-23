#ifndef __AT24C02_H__
#define __AT24C02_H__

#include <REGX52.H>
#include "I2C.h"
#include "definition.h"


#define AT24C02_ADDRESS	0xA0 //EEPROM的地址 高4位厂家固定 

/**
  * @brief  AT24C02写入一个字节
  * @param  WordAddress 要写入字节的地址
  * @param  Data 要写入的数据
  * @retval 无
  */
void AT24C02_WriteByte(uint8_t WordAddress, uint8_t Data);

/**
  * @brief  AT24C02读取一个字节
  * @param  WordAddress 要读出字节的地址
  * @retval 读出的数据
  */
uint8_t AT24C02_ReadByte(uint8_t WordAddress);


#endif
