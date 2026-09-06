#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085f1c
ARM int AccumulateModeSlotBits02085f1c(unsigned char* actor, int mode) {
    struct BattleStruct* bs;
    int total;
    if (mode < 0) {
        short v = *(short*)(actor + 0x2ac);
        if (v > 0) {
            int x = *(int*)(actor + 0x29c);
            mode = (unsigned int)(x << 23) >> 27;
        } else {
            mode = 0x21;
        }
    }
    bs = GetBattleStruct();
    total = 0;
    if (mode == 3) {
        if (actor[0x8f2] & 0x80) {
            total += GetSlotBits0201137c((char*)bs, 0x37);
        }
        if (actor[0x8f3] & 0x8) {
            total += GetSlotBits0201137c((char*)bs, 0x3b);
        }
        if (actor[0x8f3] & 0x40) {
            total += GetSlotBits0201137c((char*)bs, 0x3e);
        }
    }
    return total;
}
