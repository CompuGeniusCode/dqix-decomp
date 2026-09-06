#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int GetGlobalField0x1c020421a0();

extern "C" void func_ov017_021bac58(unsigned char* self);

struct TailNode020469b4 { unsigned char pad0[2]; unsigned char inList; unsigned char pad3; void* next; };
struct TailList020469b4 { void* head; void* tail; };
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021bac24  (semantic: InitAndAppendNode_021bac24)
extern "C" ARM void func_ov017_021bac24(unsigned char* base) {
    GetCombatantAtField0x397c(GetBattleStruct());
    GetGlobalField0x1c020421a0();
    func_ov017_021bac58(*(unsigned char**)(base + 0x3000 + 0x728));
    TailList020469b4* list = *(TailList020469b4**)(base + 0x3000 + 0x6fc);
    TailNode020469b4* node = *(TailNode020469b4**)(base + 0x3000 + 0x728);
    AppendNodeToTail(list, node);
}
