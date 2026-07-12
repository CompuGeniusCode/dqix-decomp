#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int TestBitInArray0x8ec(unsigned char* obj, int index);
int GetSlotBits0201137c(char* base, int id);
extern short data_020e8ae2[];

// USA: func_0208608c
ARM int AccumulateFlaggedSlotBits0208608c(unsigned char* actor) {
    short* list;
    struct BattleStruct* bs = GetBattleStruct();
    int total = 0;
    unsigned char i = 0;
    list = data_020e8ae2;
    short id;
    while ((id = list[i]) != -1) {
        if (TestBitInArray0x8ec(actor, id)) {
            total += GetSlotBits0201137c((char*)bs, id);
        }
        i = (i + 1) & 0xff;
    }
    return total;
}
