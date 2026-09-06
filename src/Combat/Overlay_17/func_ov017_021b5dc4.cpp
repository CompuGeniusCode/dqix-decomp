#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" char* func_ov017_0218b5b0(void);

struct Struct0218d618;
int IsField10Eq2_0218d618(struct Struct0218d618* p);

extern "C" void* func_02012fe4(void);
int GetField0x3acValue(struct BattleStruct* battleStruct);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct Struct02047230;
void MaybeInvoke0204719c(struct Struct02047230* obj);
extern "C" void func_0204719c(struct Struct02047230* obj);

struct State0207dfc8;
void CopyState0207dfc8(struct State0207dfc8* src, struct State0207dfc8* dst);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
void Forward02047b30(void* a, int b, int c, int d);

// USA: func_ov017_021b5dc4
extern "C" ARM int func_ov017_021b5dc4(char* self) {
    if (*(unsigned char*)(self + 0x54) != 0) {
        if (!IsField10Eq2_0218d618((struct Struct0218d618*)func_ov017_0218b5b0()))
            return 3;
    } else {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(self + 0x28)) != 0) {
            if (loader->GetDetailedTaskStatus(*(int*)(self + 0x28)) == BackgroundLoader::TaskStatus_Complete) {
                void* outPtr;
                unsigned int outSize;
                loader->GetLoadedFileByID(*(int*)(self + 0x28), &outPtr, &outSize);
                void* allocated = AllocateAligned4(&data_02114e20, 0x100);
                if (outSize != 0 && allocated != 0) {
                    ((SafeAllocator*)(self + 0x40))->CreateTypeA(allocated, 0x100);
                    struct BattleStruct* battle = GetBattleStruct();
                    char* base = (char*)func_02012fe4();
                    int idx = GetField0x3acValue(battle);
                    char* p = base + 0x600 + idx * 0x88;
                    *(int*)(self + 0x20) = (int)p;
                    MaybeInvoke0204719c((struct Struct02047230*)*(int*)(self + 0x20));
                    func_0204719c((struct Struct02047230*)*(int*)(self + 0x20));
                    unsigned char local[0x70];
                    short* mid = (short*)(func_ov017_0218b5b0() + 0x2cc);
                    CopyState0207dfc8((struct State0207dfc8*)((char*)mid + 0x230), (struct State0207dfc8*)local);
                    RestorePairTables0207df90((char*)local);
                    Forward02047b30((void*)*(int*)(self + 0x20), (int)outPtr, (int)outSize, (int)(self + 0x40));
                    BackupPairTables0207dfac((char*)local);
                }
            }
            loader->RemoveTask(*(int*)(self + 0x28));
            *(int*)(self + 0x28) = -1;
        }
    }
    return (*(int*)(self + 0x28) < 0) ? 4 : 3;
}
