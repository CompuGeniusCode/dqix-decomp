#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

// USA: func_ov011_02184fb0  (semantic: AllocateAndRestorePairTables_02184fb0)
extern "C" ARM int func_ov011_02184fb0(struct TaggedNumber02184c30* p) {
    int v = GetTaggedValueAsInt_02184c30(p);
    GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)p + 8));
    GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)p + 0x10));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021845f8(ctx, v);
    if (obj == 0) return 0;
    SafeAllocator* allocator = (SafeAllocator*)((char*)obj + 4);
    void* mem = allocator->Allocate(0x7c);
    if (mem == 0) return 0;
    RestorePairTables0207df90((char*)mem + 4);
    BackupPairTables0207dfac((char*)mem + 4);
    return 1;
}
