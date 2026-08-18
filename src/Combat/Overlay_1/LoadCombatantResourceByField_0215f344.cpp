#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct TaggedValue_021d60f4 { int type; union { int i; float f; } value; };
extern "C" int func_ov017_021d60f4(TaggedValue_021d60f4* a);
int AbsPlus159IfNegative0215ad2c(int x);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct SearchObj0202ff34;

struct Obj020363b4;
void LoadStreamIntoSlot020363b4(struct Obj020363b4* obj, SafeAllocator* alloc, void* header, int size);
void LoadResourceStreamByKey02036294(struct Obj020363b4* obj, int key, SafeAllocator* alloc);

extern const char data_ov001_02165745[];
struct Global021658b8 { int field0; char pad[0x8c - 0x4]; unsigned char field8c; };
extern Global021658b8 data_ov001_021658b8;

// USA: func_ov001_0215f344  (semantic: LoadCombatantResourceByField_0215f344)
extern "C" ARM int func_ov001_0215f344(void* obj) {
    char buf[0x20];
    int out1;
    int out2;

    void* field4 = func_ov017_021d612c(obj);
    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return 0;
    sprintf(buf, data_ov001_02165745, field4);
    int idx = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4((TaggedValue_021d60f4*)((char*)obj + 8)));
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, idx);
    if (combatant == 0) return 0;
    SafeAllocator* alloc = (SafeAllocator*)data_ov001_021658b8.field0;
    ((BackgroundLoader*)((SearchObj0202ff34*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        LoadStreamIntoSlot020363b4((struct Obj020363b4*)combatant, alloc, (void*)out1, out2);
    } else {
        LoadResourceStreamByKey02036294((struct Obj020363b4*)combatant, (int)buf, alloc);
    }
    return 1;
}
