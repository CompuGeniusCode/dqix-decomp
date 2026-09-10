#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" void* __clear(void* buffer, int count);
extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* object3D, void* params, int animCallback);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* object3D, int id, int flags);

struct TextureVramReservation;
extern "C" void RewindTextureVramReservation(struct TextureVramReservation* p);
extern "C" void RestoreVramAllocatorCursors(char* vramState);
extern "C" void SaveVramAllocatorState(char* vramState);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* object3D, int* scale);

struct Struct_203dafc;
extern "C" void ClearObjectArchiveLoadInfo(struct Struct_203dafc* loadInfo);

struct ObjectArchiveLoadInfo {
    int unknown0;
    void* data;
    unsigned int size;
    void* alloc;
    int unknown10;
    int unknown14;
    int unknown18;
    int packageId;
};

struct Vector3i { unsigned int components[3]; };

extern char strDataCharaSubStrChr_02194129;
extern struct Vector3i data_ov015_02193cfc;
extern int fileStagingBuffer;

// Loads data/chara_sub/<name>.chr into the viewer's Object3D, the name coming from the second word
// of the descriptor. The file lands in the shared staging buffer, so the read runs under the
// BackgroundLoader global lock, with RestoreVramAllocatorCursors called before it and
// SaveVramAllocatorState after. On success the descriptor's first word is stored at +0xc,
// presumably as the loaded id; a missing file leaves the object untouched and returns 0. The load
// info handed to Object3D is the eight-word ObjectArchiveLoadInfo of include/World/Object3D.h:
// +0x4 the file data, +0x8 its length, +0xc the allocator, +0x10 set to 1 here and +0x1c the
// package id, left at the zero ClearObjectArchiveLoadInfo wrote. ReloadEventChrAnimationPackage
// fills the same struct but puts 3 in the package id, matching the package it removes first, and
// still passes 0 to MaybeSetBCFGAnimation, so the package id does not pick the animation package.
extern "C" ARM int LoadCharaSubModel(void* self, int* desc) {
    if (desc[1] == 0) {
        return 0;
    }

    char buf[0x20];
    __clear(buf, 0x20);

    _ZN13SafeAllocator5ResetEv(*(void**)((char*)self + 8));

    int ok = 1;
    struct TextureVramReservation* mgr = *(struct TextureVramReservation**)*(void**)((char*)self + 4);
    RewindTextureVramReservation(mgr);
    RestoreVramAllocatorCursors((char*)mgr);

    sprintf(buf, &strDataCharaSubStrChr_02194129, desc[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    void* buffer = _Z18LoadFileIntoMemoryPKcPvPj(buf, &fileStagingBuffer, &length);

    if (buffer == 0) {
        ok = 0;
    } else {
        struct ObjectArchiveLoadInfo params;
        ClearObjectArchiveLoadInfo((struct Struct_203dafc*)&params);
        void* allocPtr = *(void**)((char*)self + 8);
        unsigned int sz = length;
        void* dataPtr = &fileStagingBuffer;
        int onePtr = ok;
        params.data = dataPtr;
        params.size = sz;
        params.alloc = allocPtr;
        params.unknown10 = onePtr;
        _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)((char*)self + 0x24), &params, 0);

        struct Vector3i scale = data_ov015_02193cfc;
        _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)*(void**)((char*)self + 0x24), (int*)&scale);

        _ZN8Object3D21MaybeSetBCFGAnimationEii(*(void**)((char*)self + 0x24), 0, *(int*)((char*)self + 0x44));
    }

    BackgroundLoader::RemoveLockGlobal();
    SaveVramAllocatorState((char*)mgr);

    int result;
    if (ok == 0) {
        result = 0;
    } else {
        *(int*)((char*)self + 0xc) = desc[0];
        result = 1;
    }
    return result;
}
