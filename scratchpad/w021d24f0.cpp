#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void InitObj021c2b28(void* objRaw, unsigned char a, unsigned char b);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_021d24f0
ARM void DispatchIfListedAndFlagged_021d24f0(int unused0, void* arg1, struct BattleStruct* battleStruct) {
    int base = func_ov017_0218b5b0();
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)(long)base + 0x3000 + 0x6fc);
    if (ListContainsId((struct ListHead02046b60*)list, 0xa)) return;
    struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
    unsigned short u = GetU16At0x6((struct U16Field0x6_020375f8*)c);
    if (*(int*)((char*)arg1 + 8) != u) return;
    if (ListContainsId((struct ListHead02046b60*)list, 0x1a)) return;
    struct TailNode020469b4* obj = *(struct TailNode020469b4**)((char*)(long)base + 0x3000 + 0xbb0);
    if (*((unsigned char*)obj + 2) != 0) return;
    InitObj021c2b28(obj, 1, *((unsigned char*)arg1 + 4));
    AppendNodeToTail(list, obj);
}
