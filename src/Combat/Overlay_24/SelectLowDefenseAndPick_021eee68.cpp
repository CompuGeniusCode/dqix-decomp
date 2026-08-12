#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "System/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Obj_021eee68 { int field0; };
struct Buf8_021eee68 { short v[8]; };
extern struct Buf8_021eee68 data_ov024_021fee9c;

// USA: func_ov024_021eee68  (semantic: SelectLowDefenseAndPick_021eee68)
extern "C" ARM int func_ov024_021eee68(struct Obj_021eee68* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Buf8_021eee68 buf = data_ov024_021fee9c;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        struct CombatantStruct* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (c->currentStats->primaryStats.defense >= 0xffff) continue;
        if (c->currentStats->defenseBuff >= 2) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)obj, outCount, outArray);
    return 1;
}
