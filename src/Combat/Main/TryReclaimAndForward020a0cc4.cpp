#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(struct Struct02012dd0* self);

int GetData02104304Field4();

extern "C" void func_0202f920(int val);

struct NitroHandle;
NitroHandle* NitroHandle_FindBySignature(const char* sig, int a);
void NitroHandle_ReleaseFileTables(NitroHandle* h);

void TailForward02012da4(AllocatorUnion* alloc, void* data);

struct Obj0202f9b4;
void HalveCounterField0x788(struct Obj0202f9b4* obj);

extern struct Struct02012dd0 data_02114e20;
extern void* data_02109d90;
extern const char data_020f18e8[];

// USA: func_020a0cc4  (semantic: TryReclaimAndForward020a0cc4)
extern "C" ARM int func_020a0cc4(int id) {
    if (id >= 0) {
        unsigned int max = GetMaxAlloc02012dd0(&data_02114e20);
        if (max >= id) goto fail;
    }
    if (data_02109d90 == NULL) goto fail;

    {
        int field4Val = GetData02104304Field4();
        if (field4Val != 0) {
            func_0202f920(field4Val);
        }

        NitroHandle_ReleaseFileTables(NitroHandle_FindBySignature(data_020f18e8, 3));
        TailForward02012da4((AllocatorUnion*)&data_02114e20, data_02109d90);
        data_02109d90 = NULL;

        if (field4Val != 0) {
            HalveCounterField0x788((struct Obj0202f9b4*)field4Val);
        }
    }
    return 1;
fail:
    return 0;
}
