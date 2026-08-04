#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);

struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void InitObj021c2b28(void* objRaw, unsigned char a, unsigned char b);

struct Node021d24f0 {
    char pad0[4];
    unsigned char field4;
    char pad1[3];
    int field8;
};

// USA: func_ov017_021d24f0
extern "C" ARM void func_ov017_021d24f0(void* unused0, Node021d24f0* node, struct BattleStruct* battleStruct) {
    int base = func_ov017_0218b5b0();
    struct TailList020469b4* list = *(struct TailList020469b4**)((char*)base + 0x3000 + 0x6fc);
    if (ListContainsId((struct ListHead02046b60*)list, 0xa)) return;
    struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
    unsigned short u = GetU16At0x6((struct U16Field0x6_020375f8*)c);
    if (node->field8 != u) return;
    if (ListContainsId((struct ListHead02046b60*)list, 0x1a)) return;
    struct TailNode020469b4* n2 = *(struct TailNode020469b4**)((char*)base + 0x3000 + 0xbb0);
    if (*((unsigned char*)n2 + 2) != 0) return;
    InitObj021c2b28((void*)n2, 1, node->field4);
    AppendNodeToTail(list, n2);
}
