#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" void* func_ov017_0218b5b0(void);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
void StoreVec3AsShortsAt0x5c(unsigned char* dst, int* src);

extern "C" void func_02036804(void* obj, void* params, int flag);
extern "C" int func_02036e34(void* obj, void* data, int mode);

extern char data_ov003_02180c1d;
extern char data_ov003_02180c23;

struct Vec3Words0217fb8c { unsigned int v[3]; };
extern struct Vec3Words0217fb8c data_ov003_0217fb8c;

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

// USA: func_ov003_0217c974  (semantic: LoadAndApplyNarcResource_0217c974)
extern "C" ARM void func_ov003_0217c974(char* self) {
    int list = GetData02104304Field4();
    int out1, out2;
    GetListEntryValues0202fec8((struct List0202fec8*)list, *(int*)(self + 0x130), &out1, &out2);

    void* mgr = func_ov017_0218b5b0();
    CopyInternalFields0207df50((struct Foo0207df50*)((char*)mgr + 0x2cc));
    RestorePairTables0207df90((char*)mgr + 0x2cc);

    unsigned int fileSize;
    const void* filePtr;
    if (FindFilesInNarcBySubstring((const void*)out1, &data_ov003_02180c1d, &filePtr, &fileSize, 1) == 0) {
        return;
    }

    unsigned int decompSize;
    void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)(self + 4), filePtr, decompSize);
    if (decompressed == 0) {
        return;
    }

    struct Params02036804 params;
    params.flag = 0;
    params.data = decompressed;
    params.pad18 = 0;
    params.pad1c = 0;
    params.pad20 = 0;
    params.alloc = self + 4;
    params.size = decompSize;
    params.one = 1;
    func_02036804(self + 0x80, &params, 0);

    BackupPairTables0207dfac((char*)mgr + 0x2cc);

    struct Vec3Words0217fb8c v = data_ov003_0217fb8c;
    *(int*)(self + 0xc4) = 0;
    *(int*)(self + 0xc8) = 0xfae;
    *(int*)(self + 0xcc) = 0;
    StoreVec3AsShortsAt0x5c((unsigned char*)(self + 0x80), (int*)&v);

    func_02036e34(self + 0x80, &data_ov003_02180c23, 0);
}
