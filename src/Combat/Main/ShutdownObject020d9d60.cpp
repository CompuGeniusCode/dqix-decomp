#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
extern "C" int func_ov017_0218b5b0(void);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

struct Obj020d9d60 {
    char pad[0x58];
    SafeAllocator allocator;   // 0x58
};

// USA: func_020d9d60
ARM void ShutdownObject020d9d60(struct Obj020d9d60* self) {
    SetByteField0x253((void*)GetCombatantAtField0x397c(GetBattleStruct()));
    ClearBitsInWord((unsigned int*)func_ov017_0218b5b0(), 0x10);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xe);
    void* p = self->allocator.GetSignedAllocator();
    if (p == NULL) return;
    self->allocator.Destroy();
    TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
}
