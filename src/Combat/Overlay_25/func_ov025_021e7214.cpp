#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetActiveCombatWork(void);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
extern "C" void _Z33SetField0x7cClearFields0x1ec0x1eePht(unsigned char* obj, short val);

struct Param021e7214 { char pad[8]; short field8; };

// USA: func_ov025_021e7214  (semantic: SetActiveFlagAndField_021e7214)
extern "C" ARM int func_ov025_021e7214(struct Param021e7214* p) {
    void* w = GetActiveCombatWork();
    if (w != 0) {
        *(unsigned char*)((char*)w + 0x6000 + 0xfd5) = 1;
    }
    struct BattleStruct* bs = GetBattleStruct();
    int f = GetField0x3b0Value(bs);
    _Z33SetField0x7cClearFields0x1ec0x1eePht((unsigned char*)f, p->field8);
    return 1;
}
