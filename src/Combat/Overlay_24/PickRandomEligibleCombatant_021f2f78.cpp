#include <globaldefs.h>
#include "System/Random.h"

extern "C" int func_ov000_0215eb1c(struct Random* rand, short* buf, int count, int flag);
extern "C" int func_ov024_021edcc8(void* obj, int id);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Obj_021f2f78 { int field0; };
struct Buf8_021f2f78 { short v[8]; };
extern struct Buf8_021f2f78 data_ov024_021fed5c;

// USA: func_ov024_021f2f78  (semantic: PickRandomEligibleCombatant_021f2f78)
extern "C" ARM int func_ov024_021f2f78(struct Obj_021f2f78* obj, int unused1, int unused2, int* outCount, short* outArr) {
    struct Buf8_021f2f78 buf = data_ov024_021fed5c;
    int count = func_ov000_0215eb1c((struct Random*)obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        if (!func_ov024_021edcc8(obj, buf.v[i])) continue;
        int n = *outCount;
        *outCount = n + 1;
        outArr[n] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)obj, outCount, outArr);
    return 1;
}
