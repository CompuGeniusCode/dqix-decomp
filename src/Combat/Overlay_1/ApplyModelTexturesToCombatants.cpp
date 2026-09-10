#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* param);
extern "C" int func_ov017_021d60f4(void* param);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

struct BackgroundLoaderInstance;

extern "C" void _ZN7Model3D5ClearEv(unsigned char* self);
struct Model3D;
extern "C" void _ZN7Model3D21CopyAndProcessRawFileEP14AllocatorUnionPKvjNS_18TextureStagingModeE(struct Model3D*, void*, void*, unsigned int, int);
extern "C" ARM void _ZN7Model3D12LoadFromFileEPKcP14AllocatorUnionNS_18TextureStagingModeE(void* self, void* path, void* allocator, int stagingMode);

extern "C" void _ZN7Model3D22ApplyTexturesFromModelEPS_(void* self, void* sourceModel);

extern const char strDataStr_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// Script opcode 0x219, from the table entry at 0x02165198. Loads the model named by the first
// parameter out of "data/%s" and copies its textures onto the models of every combatant named by
// the parameters after it, taking the file from the background loader's cache when it is already
// resident. The parameters are 8-byte tagged slots, an int type followed by an int/float union,
// which func_ov017_021d612c and func_ov017_021d60f4 read; func_ov001_0215ad2c folds any negative
// combatant number to 0x9f plus its magnitude, so the two signs address two different id ranges,
// and which is which is not established. The 0xac-byte Model3D it allocates is never released here,
// so it seems to sit in an arena somebody else resets.
extern "C" ARM int ApplyModelTexturesToCombatants(char* params, int count) {
    void* nameParam = params;
    params += 0x8;
    void* modelName = func_ov017_021d612c(nameParam);
    struct BattleStruct* battle = GetBattleStruct();
    if (battle == 0) return 0;

    char modelPath[0x20];
    sprintf(modelPath, strDataStr_02165745, modelName);

    SafeAllocator* alloc = data_ov001_021658b8[0];
    void* model = alloc->Allocate(0xac);
    if (model == 0) return 0;
    _ZN7Model3D5ClearEv((unsigned char*)model);

    int fileData;
    int fileSize;
    ((BackgroundLoader*)((BackgroundLoaderInstance*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(modelPath), (void**)(&fileData), (unsigned int*)(&fileSize));
    if (fileData != 0) {
        _ZN7Model3D21CopyAndProcessRawFileEP14AllocatorUnionPKvjNS_18TextureStagingModeE((struct Model3D*)model, (char*)alloc + 4, (void*)fileData, fileSize, 0);
    } else {
        _ZN7Model3D12LoadFromFileEPKcP14AllocatorUnionNS_18TextureStagingModeE(model, modelPath, (char*)alloc + 4, 0);
    }

    for (int paramIndex = 1; paramIndex < count; paramIndex++) {
        int rawCombatantId = func_ov017_021d60f4(params);
        params += 0x8;
        int idx = func_ov001_0215ad2c(rawCombatantId);
        struct CombatantStruct* combatant = GetCombatantUnchecked(battle, idx);
        if (combatant != 0 && *(void**)((char*)combatant + 0x8) != 0) {
            _ZN7Model3D22ApplyTexturesFromModelEPS_(*(void**)((char*)combatant + 0x8), model);
        }
    }
    return 1;
}
