#include <regx52.h>
#include "door.h"
#include "password.h"
#include "LCD1602.h"
#include "key.h"
#include "timer.h"

int main() {
    int8_t key;
    bool ret;
    // /* 初始化 */
     cabinet_Init();
	 LCD_Init();
	// Timer0_Init();

     UART_Init();

	// LCD_ShowString(1,1,"initial succss");

    // while (1) {
	//     key = getKey();
    //     if (key == KEY_S) {
    //         ret = storeOperator();
    //         if (ret == false) {
    //             //存满了
    //         }
    //     }
    //     if (key == KEY_F) {
    //         ret = fetchOperator();
    //         if (ret == false) {
    //             //密码错误
    //             LCD_ShowString(2,1,"error!");
    //         }
    //         else {
	//             LCD_ShowString(2,1,"fetch!");
    //         }
    //     }

    // }

    while (1) {
       fetchOperator();
    }

    return 0;
}