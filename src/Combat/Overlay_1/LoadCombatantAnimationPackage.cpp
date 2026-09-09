#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct TaggedValue_021d60f4 { int type; union { int i; float f; } value; };
extern "C" int func_ov017_021d60f4(TaggedValue_021d60f4* a);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" struct CombatantStruct* func_0200fd70(struct BattleStruct* battleStruct, int combatantId);

struct SearchObj0202ff34;

struct Obj020363b4;
extern "C" void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(struct Obj020363b4* obj, SafeAllocator* alloc, void* header, int size);
extern "C" void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(struct Obj020363b4* obj, int key, SafeAllocator* alloc);

extern const char strDataStr_02165745[];
struct Global021658b8 { int field0; char pad[0x8c - 0x4]; unsigned char field8c; };
extern Global021658b8 data_ov001_021658b8;

// Event-script command: loads the animation package named by the command's first argument onto one
// combatant's Object3D. The name is pasted into "data/%s"; the second argument is a tagged
// int-or-float holding the combatant index, and negative values are folded to 0x9f + |n| by
// func_ov001_0215ad2c - presumably a second id space for actors that are not party members.
// A copy the background loader already has by that name is used in place of a fresh read.
// Only reference to it is the ov001 command table at data_ov001_02164d6c, so it is a table entry.
extern "C" ARM int LoadCombatantAnimationPackage(void* obj) {
    char buf[0x20];
    int out1;
    int out2;

    void* field4 = func_ov017_021d612c(obj);
    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return 0;
    sprintf(buf, strDataStr_02165745, field4);
    int idx = func_ov001_0215ad2c(func_ov017_021d60f4((TaggedValue_021d60f4*)((char*)obj + 8)));
    struct CombatantStruct* combatant = func_0200fd70(battle, idx);
    if (combatant == 0) return 0;
    SafeAllocator* alloc = (SafeAllocator*)data_ov001_021658b8.field0;
    ((BackgroundLoader*)((SearchObj0202ff34*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj((struct Obj020363b4*)combatant, alloc, (void*)out1, out2);
    } else {
        _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator((struct Obj020363b4*)combatant, (int)buf, alloc);
    }
    return 1;
}
