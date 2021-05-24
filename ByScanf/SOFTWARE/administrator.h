#ifndef __ADMINISTRATOR_H__
#define __ADMINISTRATOR_H__

#include "definition.h"
#include "door.h"

/**
 * @brief 静态函数 管理员开一个门
 * @param num 要打开的门编号
 * @return 无
 */
static void openOne(uint8_t num);

/**
 * @brief 静态函数 管理员打开所有的门 
 * @param 无
 * @return 无 
 */
static void clearAll();

/**
 * @brief 静态函数 修改管理员密码
 * @param newPwd 新5位密码
 * @return 无 
 */
static void changePwd(uint16_t newPwd);


#endif // !__ADMINISTRATOR_H__
