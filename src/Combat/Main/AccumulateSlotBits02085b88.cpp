#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetSlotBits0201137c(char* base, int id);

// USA: func_02085b88
ARM int AccumulateSlotBits02085b88(unsigned char* actor) {
    struct BattleStruct* bs;
    int total;
    if (*(short*)(actor + 0x2cc) <= 0) {
        return 0;
    }
    bs = GetBattleStruct();
    total = 0;
    if (actor[0x8f0] & 4) {
        total += GetSlotBits0201137c((char*)bs, 0x22);
    }
    if (actor[0x8f0] & 0x10) {
        total += GetSlotBits0201137c((char*)bs, 0x24);
    }
    if (actor[0x8f0] & 0x40) {
        total += GetSlotBits0201137c((char*)bs, 0x26);
    }
    return total;
}
