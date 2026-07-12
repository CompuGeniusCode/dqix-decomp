#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085c08
ARM int AccumulateSlotBits02085c08(unsigned char* actor) {
    short v = *(short*)(actor + 0x2ac);
    int sel = 0x21;
    struct BattleStruct* bs;
    int total;
    if (v > 0) {
        int w = *(int*)(actor + 0x29c);
        sel = (unsigned int)(w << 23) >> 27;
    }
    bs = GetBattleStruct();
    total = 0;
    if (sel != 5) {
        if (sel == 0x21) {
            if (actor[0x8fd] & 1) {
                total += GetSlotBits0201137c((char*)bs, 0x88);
            }
        }
    } else {
        if (actor[0x8f5] & 1) {
            total += GetSlotBits0201137c((char*)bs, 0x48);
        }
    }
    return total;
}
