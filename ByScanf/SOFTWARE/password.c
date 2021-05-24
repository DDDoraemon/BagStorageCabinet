#include "password.h"

extern door g_Cabinet[];
extern bool g_RecvFlag;
extern uint8_t g_RecvData[];

static pwd_t randomPassword() {
    return (rand() % 65530 + 10000); //取随机数(10000～65530)
}


#ifdef INPUT_KEY
static pwd_t inputPassword() {
    uint8_t row = 2, col = 1, num = 0, i = 0;
    pwd_t t_Password = 0;
    LCD_ShowString(1, 0 , "input password");
    for (i; i < PWDLENGTH; i++) {
        while ((num = getKey()) > 10); //判断键值 大于10则跳过
        LCD_ShowNum(row, col, num, 1);
        col++;
        t_Password *= 10;
        t_Password += num;
    }

    return t_Password;
}
#endif //INPUT_KEY

#ifdef INPUT_SCANF
static pwd_t inputPassword() {
    pwd_t pwd = 0;
    uint8_t i = 0;

    while (g_RecvFlag == false);
    g_RecvFlag = false;

    for (i; i < 5; i++) {
        if (i != 0) {
            pwd *= 10;
        }
        pwd += g_RecvData[i] - 48;
        //LCD_ShowNum(2, i+1, pwd,2);
    }
    // LCD_ShowNum(1, 1, g_RecvData[0] - 48,2);
    // LCD_ShowNum(1, 4, g_RecvData[1] - 48,2);
    // LCD_ShowNum(1, 7, g_RecvData[2] - 48,2);
    // LCD_ShowNum(1, 10, g_RecvData[3] - 48,2);
    // LCD_ShowNum(2, 1, g_RecvData[4] - 48,2);
    // LCD_ShowNum(2, 4, g_RecvData[5] - 48,2);
    // LCD_ShowNum(2, 7, g_RecvData[6] - 48,2);
    


    LCD_ShowNum(1, 1, pwd,6);

    return pwd;
}

#endif // INPUT_SCANF



pwd_t createPassword() {
    pwd_t t_Password = 0;
    bool t_Conflict = false; 
    do {
		int i = 1;
        t_Password = randomPassword();
        t_Conflict = false;
        
        //遍历数组
        for (i; i <= DOORNUM; i++) {
            if (t_Password == g_Cabinet[i].m_Password) {
                t_Conflict = true;
                break;
            }
        }
    }while (t_Conflict == true);

    return t_Password;
}

//判断密码
uint8_t passwordIsRight() {
    pwd_t t_Pwd = inputPassword();
    uint8_t i = 1;
    for (i; i <= DOORNUM; i++) {
        if (g_Cabinet[i].m_Password == t_Pwd) {
            return i;
        }
    }
    //密码不正确 
    return 0;
}