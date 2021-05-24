#include "administrator.h"

static const uint16_t s_AdminPwd = 88888; /* 管理员密码 */

static void openOne(uint8_t num) {
    modifyAttribute(num, fetch, DEFAULTPWD);
    openDoor(num);
}

static void clearAll(void) {
    int i = 1;
    for (i; i <= DOORNUM; i++) {
        openOne(i);
    }
}

static void changePwd(uint16_t newPwd) {
    uint16_t* p_AdminPwd = (uint16_t*)&s_AdminPwd;
    *p_AdminPwd = newPwd;
}
