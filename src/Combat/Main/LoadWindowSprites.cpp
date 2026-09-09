#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/NarcHandle.h"

extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_0202f310(char*, void*);

extern AllocatorUnion data_02114e20;
extern char strDataBinIconNsarc[];
extern char fileStagingBuffer[];
extern char data_020ef7c0[];

struct EntryTable0202f24c {
    char pad0[0x444];
    class SafeAllocator* alloc;
};

// Builds the eight 0x88-byte sprite slots at the head of the object, presumably window frames --
// "window" expands "win", corroborated by the loose data/ani win0..win7.spr and waku.spr beside
// them but not proved. data/bin/icon.nsarc is read into the staging buffer, under the
// BackgroundLoader lock, and opened as a NARC under the tag "ARC" at data_020ef7c0; func_0202f310
// then pulls "ARC:win%d.spr" for i = 0..7, and the archive holds exactly win0.spr .. win7.spr,
// which is where the loop count comes from. The 0xf08 heap behind obj->alloc is only reset after.
extern "C" ARM void LoadWindowSprites(struct EntryTable0202f24c* obj) {
    if (obj->alloc == 0) {
        obj->alloc = (class SafeAllocator*)AllocateRoundedToWord(&data_02114e20, 0x14);
        obj->alloc->ResetAllocatorPointer();
        void* buf = AllocateRoundedToWord(&data_02114e20, 0xf08);
        obj->alloc->CreateTypeA(buf, 0xf08);
        obj->alloc->Reset();
    } else {
        obj->alloc->Reset();
    }
    BackgroundLoader::AddLockGlobal();

    unsigned int size;
    void* fileData = LoadFileIntoMemory(strDataBinIconNsarc, fileStagingBuffer, &size);
    if (fileData != 0) {
        NarcHandle handle;
        if (handle.Initialize(data_020ef7c0, (const unsigned char*)fileData)) {
            ((void (*)(char*, void*, void*))func_0202f310)((char*)obj, obj->alloc, fileData);
            handle.Destroy();
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
