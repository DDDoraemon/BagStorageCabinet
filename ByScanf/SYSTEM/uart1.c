#include "uart.h"

bool g_RecvFlag = false;
uint8_t g_RecvData[10];
static uint8_t s_DataLength = 0;

// void UART_Init() {  //9600bps@11.0592MHz
//     PCON &= 0x7F;		//波特率不倍速
//     SCON = 0x50;		//8位数据,可变波特率
    
//     TMOD &= 0x0F;		//清除定时器1模式位
//     TMOD |= 0x20;		//设定定时器1为8位自动重装方式
//     TL1 = 0xFA;		//设定定时初值
//     TH1 = 0xFA;		//设定定时器重装值
//     ET1 = 0;		//禁止定时器1中断
//     TR1 = 1;		//启动定时器1

//     EA = 1;
//     ES = 1;
// }

void UART_Init(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率

	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1

    EA = 1;
    ES = 1;
}

void UART_SendByte(uint8_t byte) {
    SBUF = byte;
    while (TI == 0);
    TI = 0;
}

/**
 * @brief 串口中断函数 用于接收数据
 * @param 无
 * @return 无
 */
void UART_Routine() interrupt 4 {  //uart中断函数
    if (RI == 1) { //接收中断
        //uint8_t byte;

        RI = 0; //中断请求标志位清零

        //byte = SBUF;

        if (SBUF == 0x0D || SBUF == 0x0A) {
            g_RecvFlag = true;
            s_DataLength = 0;
        }
        else {
            g_RecvData[s_DataLength++] = SBUF;
        }
    }
}
