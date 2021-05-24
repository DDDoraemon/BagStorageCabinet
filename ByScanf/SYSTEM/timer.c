#include "timer.h"

unsigned int seed;

void Timer0_Init() {  //1豪秒@11.0592MHz
    TMOD &= 0xF0;		//设置定时器模式
    TMOD |= 0x01;		//设置定时器模式
    TL0 = 0x66;		//设置定时初值  64535/256
    TH0 = 0xFC;		//设置定时初值  64535%256 + 1
    TF0 = 0;		//清除TF0标志
    TR0 = 1;		//定时器0开始计时

    ET0 = 1;  //设置中断
    EA = 1;   
    PT0 = 0;  //中断优先级
    
}

/**
 * @brief 定时器0中断函数
 * @param 无
 * @return 无
 */
void Timer0_Rountine() interrupt 1 {
    static unsigned int T0Count;
    TL0 = 0x66;	
	TH0 = 0xFC;

    T0Count++;
    if (T0Count == 30) {
        keyLoop();
		T0Count = 0;
        P2_3 = ~P2_3;
    }
    if (T0Count >= 1000) {  //1s
        //中断执行内容
    } 
}

//随机数种子
// void randSeed() {
//     TMOD=0x02; //设置定时器0为工作方式2
//     TH0=7; //装初值
//     TL0=7;
//     EA=1; //开总中断
//     ET0=1; //开定时器0中断
//     TR0=1; //启动定时0

//     delay(10);
//     srand(seed);
// }

// void time0() interrupt 1 //定时器0中断
// {
//     seed++; //时间加1
//     if(seed == 100) {
//         seed=0;
//     }
// }
