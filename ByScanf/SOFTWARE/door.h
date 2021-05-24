#ifndef __DOOR_H__
#define __DOOR_H__

#include "definition.h"
#include "password.h"
#include "LCD1602.h"

#define DOORNUM 24          /* 柜门总数 */
#define DEFAULTPWD 999    /* 默认密码 */
#define PWDLENGTH 5

/** 
 * @brief 柜门属性结构体
 */
typedef struct Door {
    uint8_t m_Number;     /* 编号 */
    pwd_t m_Password;  /* 密码 */
    bool m_Status;          /* 状态 */
}door;

/** 
 * @brief 存取状态码
 */
typedef enum Operate {
    store = 0,  /* 存操作 */
    fetch = 1   /* 取操作 */
}operate;

/**
 * @brief 静态函数 找到空柜编号
 * @param 无
 * @return 成功:柜门编号 失败0
 */
static uint8_t findEmpty();

/**
 * @brief 静态函数 根据操作修改柜门属性
 * @param num 柜门编号
 * @param opt 操作枚举
 * @param pwd 柜门密码赋值
 * @return 无
 */
static void modifyAttribute(uint8_t num, operate opt, pwd_t pwd);

/**
 * @brief 静态函数 开柜门
 * @param 无
 * @return 成功:柜门编号 失败0
 */
static void openDoor(uint8_t doorNum);

/**
 * @brief 柜门初始化函数
 * 编号从1开始 初始密码为0 状态为false 空柜数量为最大编号
 * @param 无
 * @return 无
 */
void cabinet_Init();

/** 
 * @brief 存操作
 * 先判断空柜的数量 若空柜为0 直接返回已满
 * 若不为0 再调用findEmpty函数 找到空柜编号
 * @param 无
 * @return true存成功 false存失败
 */
bool storeOperator();

/** 
 * @brief 取操作
 * 遍历数组密码是否和输入密码一致
 * @param 无
 * @return true取成功 false取失败
 */
bool fetchOperator();

#endif // !__DOOR_H__
