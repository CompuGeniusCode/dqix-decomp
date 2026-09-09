#include <globaldefs.h>

struct Object3DState0208f588 {
    unsigned char storage[0xac];
};

struct ObjectArchiveLoadInfo0208f588 {
    int unused0;
    void* data;
    unsigned int size;
    void* allocator;
    int flag;
    int pad14;
    int pad18;
    int pad1c;
};

struct ModeFlags02012fe4 {
    unsigned char pad0[0xc];
    unsigned char mode : 4;
    unsigned char high : 4;
};

struct Context02012fe4 {
    unsigned char pad0[8];
    struct ModeFlags02012fe4* flags;
};

struct ArchiveHolder0208f588 {
    void* data;
    unsigned int size;
    struct Object3DState0208f588 object;
    unsigned char loaded;
    unsigned char ready;
};

struct ArchivePath0208f588 {
    char text[0x28];
};

extern const struct ArchivePath0208f588 strDataCharaSubS202Chr;

extern "C" void _ZN8Object3D7DestroyEv(struct Object3DState0208f588* obj);
extern "C" void _ZN8Object3D10InitializeEv(struct Object3DState0208f588* obj);
extern "C" struct Context02012fe4* GetZoneState(void);
extern "C" void* _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(const char* path, void* allocator, unsigned int* outSize);
extern "C" void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(struct Object3DState0208f588* obj, struct ObjectArchiveLoadInfo0208f588* info);
extern "C" void _ZN8Object3D10MakeHiddenEv(struct Object3DState0208f588* obj);

extern "C" void RestoreVramAllocatorCursors(char* obj);
extern "C" void SaveVramAllocatorState(char* obj);

// Loads data/chara_sub/s202.chr, the only path in the literal pool, into the Object3D held at +0x8
// and leaves it hidden for the caller to show later. It gives up unless the zone state's mode nibble
// is 0. Which character s202 is has not been established - the ROM holds 405 files in
// data/chara_sub, about half of them sNNN.chr. RestoreVramAllocatorCursors runs on the third argument's pair
// tables before the load and SaveVramAllocatorState after it; which way they move, and why, is not
// established. Its one caller is func_ov017_021a2fa0.
extern "C" ARM int LoadCharaSubS202Model(struct ArchiveHolder0208f588* self, void* allocator, char* pairObj) {
    unsigned int size;
    struct ArchivePath0208f588 path;
    struct ObjectArchiveLoadInfo0208f588 info;
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
    info.flag = 0;
    info.pad14 = 0;
    info.pad18 = 0;
    info.pad1c = 0;
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
