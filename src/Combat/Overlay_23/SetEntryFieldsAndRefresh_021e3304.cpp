#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0*, int, int);
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0*, int);
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330*, int);

unsigned int GetBattleScaleCount(struct BattleStruct*);

extern "C" void func_0205ae8c(void*);

// USA: func_ov023_021e3304  (semantic: SetEntryFieldsAndRefresh_021e3304)
extern "C" ARM void func_ov023_021e3304(void* obj, int b, int c) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    SetEntryByte14ByKey0205a42c(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0, 0);
    SetEntryFlag2ByKey0205a370(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    struct Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }
    int scaleCount = (int)GetBattleScaleCount(battleStruct);
    IterateEntries0205a330((struct Container0205a330*)(*(struct Container0205a3d0**)((char*)obj + 0xd0)), scaleCount);
    entry = FindEntryByHalfword0205a3d0(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = (short)b;
        *(short*)((char*)entry + 0x6) = (short)c;
    }
    func_0205ae8c(*(void**)((char*)obj + 0xc8));
}
