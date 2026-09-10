#include <globaldefs.h>

struct Object3DState {
    unsigned char storage[0xac];
};

struct ObjectArchiveLoadInfo {
    int unused0;
    void* data;
    unsigned int size;
    void* allocator;
    int copyIntoAllocation;
    int unknown14;
    int unknown18;
    int packageId;
};

struct ZoneModeFlags {
    unsigned char unknown0[0xc];
    unsigned char mode : 4;
    unsigned char high : 4;
};

struct ZoneState {
    unsigned char unknown0[8];
    struct ZoneModeFlags* flags;
};

struct ModelArchiveHolder {
    void* data;
    unsigned int size;
    struct Object3DState object;
    unsigned char loaded;
    unsigned char ready;
};

struct ArchivePath {
    char text[0x28];
};

extern const struct ArchivePath strDataCharaSubS202Chr;

extern "C" void _ZN8Object3D7DestroyEv(struct Object3DState* obj);
extern "C" void _ZN8Object3D10InitializeEv(struct Object3DState* obj);
extern "C" struct ZoneState* GetZoneState(void);
extern "C" void* _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(const char* path, void* allocator, unsigned int* outSize);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(struct Object3DState* obj, struct ObjectArchiveLoadInfo* info);
extern "C" void _ZN8Object3D10MakeHiddenEv(struct Object3DState* obj);

extern "C" void RestoreVramAllocatorCursors(char* obj);
extern "C" void SaveVramAllocatorState(char* obj);

// Loads data/chara_sub/s202.chr, the only path in the literal pool, into the Object3D held at +0x8
// and leaves it hidden for the caller to show later. It gives up unless the zone state's mode nibble
// is 0. Which character s202 is has not been established - the ROM holds 405 files in
// data/chara_sub, about half of them sNNN.chr. RestoreVramAllocatorCursors runs on the third argument's pair
// tables before the load and SaveVramAllocatorState after it; which way they move, and why, is not
// established. Its one caller is func_ov017_021a2fa0. The load info is the eight-word
// ObjectArchiveLoadInfo of include/World/Object3D.h and only the file, its length and the allocator
// are filled in: the copy-into-allocation word at +0x10 and the package id at +0x1c stay 0.
extern "C" ARM int LoadCharaSubS202Model(struct ModelArchiveHolder* self, void* allocator, char* pairObj) {
    unsigned int size;
    struct ArchivePath path;
    struct ObjectArchiveLoadInfo info;
    void* data;

    self->loaded = 0;
    _ZN8Object3D7DestroyEv(&self->object);
    _ZN8Object3D10InitializeEv(&self->object);
    if (GetZoneState()->flags->mode != 0) {
        return 0;
    }

    path = strDataCharaSubS202Chr;
    data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path.text, allocator, &size);
    if (data == 0) {
        return 0;
    }
    unsigned int length = size;
    self->data = data;
    self->size = length;
    self->loaded = 1;
    self->ready = 1;

    info.unused0 = 0;
    info.data = 0;
    info.size = 0;
    info.copyIntoAllocation = 0;
    info.unknown14 = 0;
    info.unknown18 = 0;
    info.packageId = 0;
    info.allocator = allocator;
    info.data = self->data;
    info.size = self->size;

    RestoreVramAllocatorCursors(pairObj);
    _ZN8Object3D10InitializeEv(&self->object);
    _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(&self->object, &info);
    _ZN8Object3D10MakeHiddenEv(&self->object);
    SaveVramAllocatorState(pairObj);
    return 1;
}
