#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b0Value(struct BattleStruct* battleStruct);
int TestFlagMask(unsigned short* obj, int mask);
void SetField0x238True(void* obj);
void SetField0x238False(void* obj);

extern unsigned short data_02114e30;

// USA: func_ov015_021925a8  (semantic: UpdateField238FlagStateC00_021925a8)
extern "C" ARM int func_ov015_021925a8() {
    struct BattleStruct* battle = GetBattleStruct();
    if (!battle) return 0;
    int field = GetField0x3b0Value(battle);
    if (!field) return 0;
    if (TestFlagMask(&data_02114e30, 0xc00)) {
        SetField0x238True((void*)field);
        return 1;
    }
    SetField0x238False((void*)field);
    return 0;
}
