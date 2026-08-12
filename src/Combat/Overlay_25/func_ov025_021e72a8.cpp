#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetActiveCombatWork(void);
int GetField0x3b0Value(struct BattleStruct* battleStruct);
int CallFunc020a0d6cAtField0x16c(char* obj, int a, int b, int c, int d);

struct Param021e72a8 {
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
};

// USA: func_ov025_021e72a8
extern "C" ARM int func_ov025_021e72a8(struct Param021e72a8* p) {
    void* w = GetActiveCombatWork();
    if (w != 0) {
        *(unsigned char*)((char*)w + 0x6000 + 0xfd5) = 1;
    }
    struct BattleStruct* bs = GetBattleStruct();
    int field = GetField0x3b0Value(bs);
    CallFunc020a0d6cAtField0x16c((char*)field, (int)((char*)p + 8), p->f14, p->f18, p->f1c);
    return 1;
}
