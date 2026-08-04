#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* a);
int AbsPlus159IfNegative0215ad2c(int x);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

int GetData02104304Field4();
struct SearchObj0202ff34;
int FindTableEntryByFormattedName(SearchObj0202ff34*, char*, int*, int*);

void ResetTimersAndBuffers0207e264(unsigned char* self);
struct Obj0207e378;
void SetBufferAndFlushCache0207e378(struct Obj0207e378*, void*, void*, unsigned int, int);
ARM void LoadResourceIntoAllocatedBuffer(void* a, void* b, void* c, int d);

extern "C" void func_0207ea8c(void* obj, void* p);

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215ef54  (semantic: AllocateAndFlagCombatantResources_0215ef54)
extern "C" ARM int func_ov001_0215ef54(char* obj, int count) {
    void* rawArg = obj;
    obj += 0x8;
    void* field4 = func_ov017_021d612c(rawArg);
    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return 0;

    char buf[0x20];
    sprintf(buf, data_ov001_02165745, field4);

    SafeAllocator* alloc = data_ov001_021658b8[0];
    void* newBuf = alloc->Allocate(0xac);
    if (newBuf == 0) return 0;
    ResetTimersAndBuffers0207e264((unsigned char*)newBuf);

    int out1;
    int out2;
    FindTableEntryByFormattedName((SearchObj0202ff34*)GetData02104304Field4(), buf, &out1, &out2);
    if (out1 != 0) {
        SetBufferAndFlushCache0207e378((struct Obj0207e378*)newBuf, (char*)alloc + 4, (void*)out1, out2, 0);
    } else {
        LoadResourceIntoAllocatedBuffer(newBuf, buf, (char*)alloc + 4, 0);
    }

    for (int i = 1; i < count; i++) {
        int t = func_ov017_021d60f4(obj);
        obj += 0x8;
        int idx = AbsPlus159IfNegative0215ad2c(t);
        struct CombatantStruct* combatant = GetCombatantUnchecked(battle, idx);
        if (combatant != 0 && *(void**)((char*)combatant + 0x8) != 0) {
            func_0207ea8c(*(void**)((char*)combatant + 0x8), newBuf);
        }
    }
    return 1;
}
