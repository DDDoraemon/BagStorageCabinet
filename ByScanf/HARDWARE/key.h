#ifndef __KEY_H__
#define __KEY_H__

#include <regx52.h>
#include "definition.h"

//debug
#include "LCD1602.h"

#define pressed 0   //低电平按键有效
#define unpressed 1

/*行*/
#define row1 P1_0
#define row2 P1_1
#define row3 P1_2
#define row4 P1_3

/*列*/
#define col1 P1_4
#define col2 P1_5
#define col3 P1_6
#define col4 P1_7

/*
原键盘对应的返回值
********--1--2--3--4--*********
********--5--6--7--8--*********
********--9--10-11-12-*********
********--13-14-15-16-*********
修改后键盘值
********--1--2--3--13--********
********--4--5--6--14--********
********--7--8--9--15--********
********--11-10-12-16--********
键盘实际显示
********--1--2--3--$--*********
********--4--5--6--$--*********
********--7--8--9--$--*********
********-存--0-取--$--*********
*/

//行1
#define press1_1 1    
#define press1_2 2    
#define press1_3 3    
#define press1_4 13
//行2
#define press2_1 4   
#define press2_2 5   
#define press2_3 6    
#define press2_4 14  
//行3  
#define press3_1 7   
#define press3_2 8    
#define press3_3 9  
#define press3_4 15  
//行4
#define press4_1 11   
#define press4_2 10    
#define press4_3 12  
#define press4_4 16  
//键值
#define KEY_1 press1_1     
#define KEY_2 press1_2     
#define KEY_3 press1_3     
#define KEY_4 press2_1     
#define KEY_5 press2_2     
#define KEY_6 press2_3     
#define KEY_7 press3_1    
#define KEY_8 press3_2    
#define KEY_9 press3_3    
#define KEY_0 press4_2    
//功能键
#define KEY_S press4_1  //存
#define KEY_F press4_3  //取 
// #define KEY_     
// #define KEY_    
// #define KEY_   
// #define KEY_   
// #define KEY_   
// #define KEY_  
/**
 * @brief 静态函数 监测矩阵键盘
 * @param 无
 * @return 检测到的键值
 */
static int8_t getKeyState();

/**
 * @brief 中断循环检测键值
 * @param 无
 * @return 无
 */
void keyLoop();

/**
 * @brief 获取键值
 * @param 无
 * @return 键值
 */
int8_t getKey();

/**
 * @brief 非中断方式键值获取函数
 * @param 无
 * @return 键值
 */
//int getKey();

#endif // !__KEY_H__
