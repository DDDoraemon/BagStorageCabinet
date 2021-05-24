#ifndef __DEFINITION_H__
#define __DEFINITION_H__

/*!< Signed integer types  */
typedef signed char     int8_t;     /* -128~127 */
typedef signed short    int16_t;    /* -32768~32767 */
typedef signed int      int32_t;    /* -2147483648 ~ 2147483647*/
 
/*!< Unsigned integer types  */
typedef unsigned char   uint8_t;    /* 0 ~ 255 */
typedef unsigned short  uint16_t;   /* 0 ~ 65535 */
typedef unsigned int    uint32_t;   /* 0 ~ 4294967295*/

typedef uint16_t pwd_t;  /* 密码类型 */

/** 
 * @brief 定义布尔类型
 */
typedef enum Bool {
    false = 0,
    true = 1
}bool;



#endif // !__DEFINITION_H__
