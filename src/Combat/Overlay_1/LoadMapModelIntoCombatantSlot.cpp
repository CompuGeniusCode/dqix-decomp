#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void* argument);
extern "C" extern int func_ov001_0215ad2c(int x);
extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bbbe4(void* p);
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern SafeAllocator* data_ov001_021658b8[8];
extern char strDataMapStrChr[];
extern "C" void _ZN8Object3D10InitializeEv(void* object);
extern "C" int _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(int object, int loadInfo);
extern "C" void RegisterCombatant(struct BattleStruct* battleStruct, int id, struct CombatantStruct* combatant);
struct Object3DState;
extern "C" void _ZN8Object3D8SetScaleEiii(struct Object3DState* object, short scaleX, short scaleY, short scaleZ);
extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void* self, int animationIndex, int animationFlags);

struct ObjectArchiveLoadInfo {
    int unused0;
    void* dataPtr;
    unsigned int size;
    SafeAllocator* allocator;
    int copyIntoAllocation;
    char unknown14[0xc];
};

// Builds an Object3D out of data/map/<name>.chr and registers it in battleStruct->combatantList at
// the slot the script argument names; data/map holds eighteen such archives named by zone code
// (M01I00, C01I00, T01I00). The name is not passed in but read out of game-main state through
// ov017's +0x3000+0x734 pointer, which presumably makes it the current map's model, though nothing
// shows that field holds the current zone code. Negative ids fold to 159 + |id| by
// func_ov001_0215ad2c; the loader lock is held across the read and the object is scaled to 0x10a.
// The load record is the eight-word ObjectArchiveLoadInfo of include/World/Object3D.h and the
// object is the 0xac bytes taken from the allocator. Only the file, its length, the allocator and
// the copy-into-allocation word at +0x10 are filled in, and unlike LoadCharaSubS202Model this one
// never clears the record first, so +0 and +0x14 through +0x1c, the last of which is the package
// id, go in holding whatever the stack held.
extern "C" ARM int LoadMapModelIntoCombatantSlot(void* command) {
    char path[0x50];
    struct ObjectArchiveLoadInfo loadInfo;
    void* outPtr;
    unsigned int size;
    struct BattleStruct* battle;
    SafeAllocator* allocator;
    void* mapModel;
    int base;
    int id;

    battle = GetBattleStruct();
    (int)BackgroundLoader::GetInstance();
    allocator = data_ov001_021658b8[0];
    id = func_ov001_0215ad2c(func_ov017_021d60f4(command));
    base = func_ov017_0218b5b0();
    base = *(int*)((char*)base + 0x3000 + 0x734);
    base = func_ov017_021bbbe4((void*)base);
    sprintf(path, strDataMapStrChr, base + 0x4);
    BackgroundLoader::AddLockGlobal();
    size = func_ov001_0215a750(path, &outPtr);
    if (size == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    mapModel = allocator->Allocate(0xac);
    _ZN8Object3D10InitializeEv(mapModel);
    loadInfo.dataPtr = outPtr;
    loadInfo.allocator = allocator;
    loadInfo.size = size;
    loadInfo.copyIntoAllocation = 1;
    _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo((int)mapModel, (int)&loadInfo);
    BackgroundLoader::RemoveLockGlobal();
    RegisterCombatant(battle, id, (struct CombatantStruct*)mapModel);
    _ZN8Object3D8SetScaleEiii((struct Object3DState*)mapModel, 0x10a, 0x10a, 0x10a);
    _ZN8Object3D21MaybeSetBCFGAnimationEii(mapModel, 0, 0);
    return 1;
}
