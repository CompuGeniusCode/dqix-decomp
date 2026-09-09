#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" void* __clear(void* dst, int count);
extern "C" void _ZN13SafeAllocator5ResetEv(void* thisPtr);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int id, int flags);

struct Foo0207df50;
extern "C" void RewindTextureVramReservation(struct Foo0207df50* p);
extern "C" void RestoreVramAllocatorCursors(char* obj);
extern "C" void SaveVramAllocatorState(char* obj);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);

struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

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

struct Vec3Words02193cfc { unsigned int v[3]; };

extern char strDataCharaSubStrChr_02194129;
extern struct Vec3Words02193cfc data_ov015_02193cfc;
extern int fileStagingBuffer;

// Loads data/chara_sub/<name>.chr into the viewer's Object3D, the name coming from the second word
// of the descriptor. The file lands in the shared staging buffer, so the read runs under the
// BackgroundLoader global lock, with RestoreVramAllocatorCursors called before it and SaveVramAllocatorState after. On
// success the descriptor's first word is stored at +0xc, presumably as the loaded id; a missing
// file leaves the object untouched and returns 0.
extern "C" ARM int LoadCharaSubModel(void* self, int* desc) {
    if (desc[1] == 0) {
        return 0;
    }

    char buf[0x20];
    __clear(buf, 0x20);

    _ZN13SafeAllocator5ResetEv(*(void**)((char*)self + 8));

    int ok = 1;
    struct Foo0207df50* mgr = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    RewindTextureVramReservation(mgr);
    RestoreVramAllocatorCursors((char*)mgr);

    sprintf(buf, &strDataCharaSubStrChr_02194129, desc[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    void* buffer = _Z18LoadFileIntoMemoryPKcPvPj(buf, &fileStagingBuffer, &length);

    if (buffer == 0) {
        ok = 0;
    } else {
        struct Params02036804 params;
        func_0203dafc((struct Struct_203dafc*)&params);
        void* allocPtr = *(void**)((char*)self + 8);
        unsigned int sz = length;
        void* dataPtr = &fileStagingBuffer;
        int onePtr = ok;
        params.data = dataPtr;
        params.size = sz;
        params.alloc = allocPtr;
        params.one = onePtr;
        _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)((char*)self + 0x24), &params, 0);

        struct Vec3Words02193cfc v = data_ov015_02193cfc;
        _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)*(void**)((char*)self + 0x24), (int*)&v);

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
