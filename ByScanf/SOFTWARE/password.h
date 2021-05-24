#ifndef __PASSWORD_H__
#define __PASSWORD_H__

#include <string.h>
#include "definition.h"
#include "door.h"
#include "key.h"
#include "uart.h"
#include "LCD1602.h"

#define INPUT_SCANF 1
#define BAR_CODE_LEN 6

/**
 * @brief 静态函数 生成随机密码
 * @param 无
 * @return 随机数10000～65530
 */
static pwd_t randomPassword();


static uint8_t hexToDec(uint8_t hex);
/**
 * @brief 静态函数 输入密码
 * @param 无
 * @return 输入的密码
 */
static pwd_t inputPassword();

/**
 * @brief 生成不重复密码
 * @param 无
 * @return 生成的密码
 */
pwd_t createPassword();

/**
 * @brief 判断输入的密码是否正确
 * @param 无
 * @return 正确返回编号 失败返回0
 */
uint8_t passwordIsRight();

#endif // !__PASSWORD_H__