#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"

struct Struct02012dd0;
extern "C" unsigned int func_02012dd0(struct Struct02012dd0* self);

struct NitroHandle;
NitroHandle* NitroHandle_FindBySignature(const char* sig, int a);
void NitroHandle_ReleaseFileTables(NitroHandle* h);

extern "C" void AllocatorUnionFreeVeneer(AllocatorUnion* alloc, void* data);

struct Obj0202f9b4;

extern struct Struct02012dd0 data_02114e20;
extern void* data_02109d90;
extern const char data_020f18e8[];

// Hands the ROM filesystem's FAT/FNT tables back to the heap: releases the archive whose "rom"
// signature is the literal at data_020f18e8, then frees the block func_020a0c0c parked in
// data_02109d90 and nulls the pointer. The argument is a byte count, not an index -- callers pass
// the size they are about to allocate, 0x6000 to 0x40400 -- and it returns without doing anything
// if func_02012dd0 says the heap can already supply that much; a negative argument skips the
// check. BackgroundLoader::MaybeWaitIdle takes a lock across the free, dropped after it.
extern "C" ARM int ReleaseROMFileTablesForAllocation(int id) {
    if (id >= 0) {
        unsigned int max = func_02012dd0(&data_02114e20);
        if (max >= id) goto fail;
    }
    if (data_02109d90 == NULL) goto fail;

    {
        int field4Val = (int)BackgroundLoader::GetInstance();
        if (field4Val != 0) {
            ((BackgroundLoader*)(field4Val))->MaybeWaitIdle();
        }

        NitroHandle_ReleaseFileTables(NitroHandle_FindBySignature(data_020f18e8, 3));
        AllocatorUnionFreeVeneer((AllocatorUnion*)&data_02114e20, data_02109d90);
        data_02109d90 = NULL;

        if (field4Val != 0) {
            ((BackgroundLoader*)((struct Obj0202f9b4*)field4Val))->RemoveLock();
        }
    }
    return 1;
fail:
    return 0;
}
