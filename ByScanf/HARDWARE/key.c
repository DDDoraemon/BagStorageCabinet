#include "key.h"

static int8_t s_KeyNum;

static int8_t getKeyState() {
    int8_t keyState = -1;

    row1 = pressed;
    row2 = row3 = row4 = unpressed;
    if (row1 == pressed && col1 == pressed) {
        return keyState = press1_1;
    }
    else if (row1 == pressed && col2 == pressed) {
        return keyState = press1_2;
    }
    else if (row1 == pressed && col3 == pressed) {
        return keyState = press1_3;
    }
    else if (row1 == pressed && col4 == pressed) {
        return keyState = press1_4;
    }

    row2 = pressed;
    row1 = row3 = row4 = unpressed;
    if (row2 == pressed && col1 == pressed) {
        return keyState = press2_1;
    }
    else if (row2 == pressed && col2 == pressed) {
        return keyState = press2_2;
    }
    else if (row2 == pressed && col3 == pressed) {
        return keyState = press2_3;
    }
    else if (row2 == pressed && col4 == pressed) {
        return keyState = press2_4;
    }

    row3 = pressed;
    row1 = row2 = row4 = unpressed;
    if (row3 == pressed && col1 == pressed) {
        return keyState = press3_1;
    }
    else if (row3 == pressed && col2 == pressed) {
        return keyState = press3_2;
    }
    else if (row3 == pressed && col3 == pressed) {
        return keyState = press3_3;
    }
    else if (row3 == pressed && col4 == pressed) {
        return keyState = press3_4;
    }

    row4 = pressed;
    row1 = row2 = row3 = unpressed;
    if (row4 == pressed && col1 == pressed) {
        return keyState = press4_1;
    }
    else if (row4 == pressed && col2 == pressed) {
        return keyState = press4_2;
    }
    else if (row4 == pressed && col3 == pressed) {
        return keyState = press4_3;
    }
    else if (row4 == pressed && col4 == pressed) {
        return keyState = press4_4;
    }

    return keyState;
}

void keyLoop() {
    static int8_t nowState, LastState;
    
    LastState = nowState;
    nowState = getKeyState();

    if (LastState == press1_1 && nowState == -1) {
        s_KeyNum = press1_1;
    }
    else if (LastState == press1_2 && nowState == -1) {
        s_KeyNum = press1_2;
    }
    else if (LastState == press1_3 && nowState == -1) {
        s_KeyNum = press1_3;
    }
    else if (LastState == press1_4 && nowState == -1) {
        s_KeyNum = press1_4;
    }
    else if (LastState == press2_1 && nowState == -1) {
        s_KeyNum = press2_1;
    }
    else if (LastState == press2_2 && nowState == -1) {
        s_KeyNum = press2_2;
    }
    else if (LastState == press2_3 && nowState == -1) {
        s_KeyNum = press2_3;
    }
    else if (LastState == press2_4 && nowState == -1) {
        s_KeyNum = press2_4;
    }
    else if (LastState == press3_1 && nowState == -1) {
        s_KeyNum = press3_1;
    }
    else if (LastState == press3_2 && nowState == -1) {
        s_KeyNum = press3_2;
    }
    else if (LastState == press3_3 && nowState == -1) {
        s_KeyNum = press3_3;
    }
    else if (LastState == press3_4 && nowState == -1) {
        s_KeyNum = press3_4;
    }
    else if (LastState == press4_1 && nowState == -1) {
        s_KeyNum = press4_1;
    }
    else if (LastState == press4_2 && nowState == -1) {
        s_KeyNum = press4_2;
    }
    else if (LastState == press4_3 && nowState == -1) {
        s_KeyNum = press4_3;
    }
    else if (LastState == press4_4 && nowState == -1) {
        s_KeyNum = press4_4;
    }
}

int8_t getKey() {
    int8_t t_Num = s_KeyNum;
    s_KeyNum = -1;
    return t_Num;
}


//不使用中断的方式获得key值
#ifdef NoInterruptKey
int getKey() {
    int keyNumber = -1;

    do {
        row1 = pressed;
        row2 = row3 = row4 = unpressed;
        if (row1 == pressed && col1 == pressed) {
            delay(30);
            while (col1 == pressed);
            delay(30);
            return keyNumber = 1;
        }
        else if (row1 == pressed && col2 == pressed) {
            delay(30);
            while (col2 == pressed);
            delay(30);
            return keyNumber = 2;
        }
        else if (row1 == pressed && col3 == pressed) {
            delay(30);
            while (col3 == pressed);
            delay(30);
            return keyNumber = 3;
        }
        else if (row1 == pressed && col4 == pressed) {
            delay(30);
            while (col4 == pressed);
            delay(30);
            return keyNumber = 4;
        }

        row2 = pressed;
        row1 = row3 = row4 = unpressed;
        if (row2 == pressed && col1 == pressed) {
            delay(30);
            while (col1 == pressed);
            delay(30);
            return keyNumber = 5;
        }
        else if (row2 == pressed && col2 == pressed) {
            delay(30);
            while (col2 == pressed);
            delay(30);
            return keyNumber = 6;
        }
        else if (row2 == pressed && col3 == pressed) {
            delay(30);
            while (col3 == pressed);
            delay(30);
            return keyNumber = 7;
        }
        else if (row2 == pressed && col4 == pressed) {
            delay(30);
            while (col4 == pressed);
            delay(30);
            return keyNumber = 8;
        }

        row3 = pressed;
        row1 = row2 = row4 = unpressed;
        if (row3 == pressed && col1 == pressed) {
            delay(30);
            while (col1 == pressed);
            delay(30);
            return keyNumber = 9;
        }
        else if (row3 == pressed && col2 == pressed) {
            delay(30);
            while (col2 == pressed);
            delay(30);
            return keyNumber = 10;
        }
        else if (row3 == pressed && col3 == pressed) {
            delay(30);
            while (col3 == pressed);
            delay(30);
            return keyNumber = 11;
        }
        else if (row3 == pressed && col4 == pressed) {
            delay(30);
            while (col4 == pressed);
            delay(30);
            return keyNumber = 0;
        }

        row4 = pressed;
        row1 = row2 = row3 = unpressed;
        if (row4 == pressed && col1 == pressed) {
            delay(30);
            while (col1 == pressed);
            delay(30);
            return keyNumber = 13;
        }
        else if (row4 == pressed && col2 == pressed) {
            delay(30);
            while (col2 == pressed);
            delay(30);
            return keyNumber = 14;
        }
        else if (row4 == pressed && col3 == pressed) {
            delay(30);
            while (col3 == pressed);
            delay(30);
            return keyNumber = 15;
        }
        else if (row4 == pressed && col4 == pressed) {
            delay(30);
            while (col4 == pressed);
            delay(30);
            return keyNumber = 16;
        }
    }while (keyNumber == -1);

    row1 = row2 = row3 = row4 = unpressed;
	return keyNumber;
}

#endif

