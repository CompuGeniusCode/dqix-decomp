#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Container02037364;
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(struct Container02037364* obj, int key);

extern "C" void _ZN8Object3D20StopCurrentAnimationEv(unsigned char* obj);

extern "C" void* __clear(void* dst, int count);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int id, int flags);

struct Struct_203dafc;
extern "C" void ClearObjectArchiveLoadInfo(struct Struct_203dafc* obj);

struct Params02036804 {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int pad18;
    int pad1c;
    int pad20;
};

extern char strDataEventLv5StrChr;
extern int fileStagingBuffer;

// Swaps the viewer's animation package for an event one: drops package 3 off the Object3D at
// +0x24, then loads data/event_lv5/<name>.chr through the shared staging buffer and installs it as
// a CCHR/CMOT archive. The ROM ships 565 files in that directory. The second parameter is typed
// int but is really the name string; zero means just drop the package and stop. func_ov015_0218f308
// dispatches here for kinds 2 and 3 of its +0x1c selector and, for kind 0, to func_ov015_0218c538,
// which pulls from data/chara, data/event_lv5 and data/pack_lv5/chara_mp.gp2 alike.
extern "C" ARM void ReloadEventChrAnimationPackage(void* self, int val) {
    unsigned char* base = (unsigned char*)self;
    _ZN8Object3D26RemoveAnimationPackageByIDEi((struct Container02037364*)*(void**)(base + 0x24), 3);
    if (val != 0) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(*(void**)(base + 0x14), *(unsigned int*)(base + 0x18));
        allocator.Reset();

        char buf[0x80];
        __clear(buf, 0x80);

        BackgroundLoader::AddLockGlobal();

        unsigned int length = 0;
        sprintf(buf, &strDataEventLv5StrChr, val);
        void* buffer = _Z18LoadFileIntoMemoryPKcPvPj(buf, &fileStagingBuffer, &length);

        if (buffer != 0) {
            struct Params02036804 params;
            ClearObjectArchiveLoadInfo((struct Struct_203dafc*)&params);
            params.alloc = &allocator;
            params.data = &fileStagingBuffer;
            params.size = length;
            params.one = 1;
            params.pad20 = 3;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)(base + 0x24), &params, 0);
        }

        BackgroundLoader::RemoveLockGlobal();
        allocator.Destroy();
    }
    _ZN8Object3D20StopCurrentAnimationEv(*(unsigned char**)(base + 0x24));
    _ZN8Object3D21MaybeSetBCFGAnimationEii(*(void**)(base + 0x24), 0, *(int*)(base + 0x44));
}
