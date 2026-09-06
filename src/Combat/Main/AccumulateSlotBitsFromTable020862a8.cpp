#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern short data_020e8bec[];

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);

// USA: func_020862a8
ARM int AccumulateSlotBitsFromTable020862a8(unsigned char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int total = 0;
    unsigned char i;
    short idx;
    for (i = 0; (idx = data_020e8bec[i]) != -1; i++) {
        if (TestBitInArray0x8ec(obj, idx)) {
            total += GetSlotBits0201137c((char*)bs, idx);
        }
    }
    return total;
}
