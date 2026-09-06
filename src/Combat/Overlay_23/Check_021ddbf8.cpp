#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetWord0x0(int* obj);
int CheckField0x20Positive(int* obj);
int CheckField0x14Positive(int* obj);

struct Obj021ddbf8 { char pad[0x77c]; signed char f77c; };

// USA: func_ov023_021ddbf8
ARM int Check_021ddbf8(Obj021ddbf8* arg) {
    int* p = (int*)GetWord0x0((int*)GetBattleStruct());
    int r;
    if (arg->f77c == 1) {
        r = CheckField0x20Positive(p);
    } else {
        r = CheckField0x14Positive(p);
    }
    return r != 0;
}
