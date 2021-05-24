#include "door.h"

door g_Cabinet[DOORNUM + 1]; //全局变量 柜门数组
static uint8_t s_EmptyNumber;  //静态变量 空柜数量

static uint8_t findEmpty() {
    int i = 1;
    for (i; i <= DOORNUM; i++) {
        if (g_Cabinet[i].m_Status == false) {
            return i;
        }
    }
    return 0;
}

static void modifyAttribute(uint8_t num, operate opt, pwd_t pwd) {
    if (store == opt) {
        g_Cabinet[num].m_Password = pwd;
        g_Cabinet[num].m_Status = true;
        s_EmptyNumber--;
    }
    if (fetch == opt) {
        g_Cabinet[num].m_Password = DEFAULTPWD;
        g_Cabinet[num].m_Status = false;
        s_EmptyNumber++;
    }
}

static void openDoor(uint8_t doorNum) {

}

void cabinet_Init() {
    int i = 0;
    for (i; i <= DOORNUM; i++) {
        g_Cabinet[i].m_Number = i;
        g_Cabinet[i].m_Password = DEFAULTPWD;
        g_Cabinet[i].m_Status = false;
    }
    s_EmptyNumber = DOORNUM;
}

bool storeOperator() {
	uint8_t foundNum;
    pwd_t pwd;

    if (s_EmptyNumber == 0) {
        return false;
    }
    
	foundNum = findEmpty();
    pwd = createPassword();
    modifyAttribute(foundNum, store, pwd);

    openDoor(foundNum);
    LCD_ShowString(1, 1, "door has open");
    LCD_ShowString(2, 1, "pwd is ");
    LCD_ShowNum(2, 8, g_Cabinet[foundNum].m_Password, 5);
    return true;
}

bool fetchOperator() {
    uint8_t doorNum = 0;
    doorNum = passwordIsRight();
    if (0 == doorNum) {
        //密码错误
        return false;
    }
    modifyAttribute(doorNum, fetch, DEFAULTPWD);
    openDoor(doorNum);
    return true;
}