#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0(void);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
struct Obj0217e334;
void InitObj0217e334(struct Obj0217e334* self);
struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov003_0217e300  (semantic: InitAndAppendNode_0217e300)
extern "C" ARM void func_ov003_0217e300(char* obj) {
    GetCombatantAtField0x3ac(GetBattleStruct());
    GetGlobalField0x1c020421a0();
    InitObj0217e334(*(struct Obj0217e334**)(obj + 0x3000 + 0x730));
    AppendNodeToTail(*(struct TailList020469b4**)(obj + 0x3000 + 0x6fc), *(struct TailNode020469b4**)(obj + 0x3000 + 0x730));
}
