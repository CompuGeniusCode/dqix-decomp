#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* command);
struct ScriptArgument { int type; union { int asInt; float asFloat; } value; };
extern "C" int func_ov017_021d60f4(ScriptArgument* argument);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct BackgroundLoaderInstance;

struct Object3D;
extern "C" void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj(struct Object3D* object3D, SafeAllocator* alloc, void* header, int size);
extern "C" void _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator(struct Object3D* object3D, int key, SafeAllocator* alloc);

extern const char strDataStr_02165745[];
struct EventOverlayState { int allocator; char unknown4[0x8c - 0x4]; unsigned char unknown8c; };
extern EventOverlayState data_ov001_021658b8;

// Event-script command: loads the animation package named by the command's first argument onto one
// combatant's Object3D. The name is pasted into "data/%s"; the second argument is the tagged
// int-or-float at command+0x8, holding the combatant index, and negative values are folded to
// 0x9f + |n| by func_ov001_0215ad2c - presumably the second id space for actors that are not party
// members. The allocator handed to Object3D is the first of the eight SafeAllocator slots at
// data_ov001_021658b8. Whatever copy the background loader already holds under that name is used
// in place of re-reading the file. Only reference to it is the ov001 command table at
// data_ov001_02164d6c, so it is one table entry.
extern "C" ARM int LoadCombatantAnimationPackage(void* command) {
    char buf[0x20];
    int out1;
    int out2;

    void* packageName = func_ov017_021d612c(command);
    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return 0;
    sprintf(buf, strDataStr_02165745, packageName);
    int idx = func_ov001_0215ad2c(func_ov017_021d60f4((ScriptArgument*)((char*)command + 8)));
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, idx);
    if (combatant == 0) return 0;
    SafeAllocator* alloc = (SafeAllocator*)data_ov001_021658b8.allocator;
    ((BackgroundLoader*)((BackgroundLoaderInstance*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 != 0) {
        _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEP13SafeAllocatorPKvj((struct Object3D*)combatant, alloc, (void*)out1, out2);
    } else {
        _ZN8Object3D39LoadType0AnimationPackageFromBCFGScriptEPKcP13SafeAllocator((struct Object3D*)combatant, (int)buf, alloc);
    }
    return 1;
}
