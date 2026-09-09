#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void func_0204719c(void* obj, int flag);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02047b40(void* obj, void* handle, void* extra);

extern "C" int func_020429d4(void);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outCount);

extern int strDataAniStr_020f0118;

struct Obj02047a78 {
    char pad0[0x84];
    unsigned char flag0 : 1;
    unsigned char flagRest : 7;
};

// Loads one file out of data/ani for this object. The name is rejected unless its last character is
// 'r', which in that directory means a .spr -- 1298 of its 1434 files -- so this is the sprite path,
// not a general loader. func_0204719c resets the object first, zeroing its fields and writing
// defaults, and it runs ahead of the 'r' check, so a rejected name still leaves the object reset.
// The destination handle from func_020429d4 seems to be shared, which would explain the
// BackgroundLoader::AddLockGlobal / RemoveLockGlobal bracket around the read.
extern "C" ARM void LoadAniSprFile(struct Obj02047a78* obj, const char* path, void* extra) {
    char buf[0x80];
    int flag;
    void* handle;

    if (path == 0) {
        return;
    }
    flag = obj->flag0;
    if (flag) {
        if (flag) {
            func_0204719c(obj, flag);
        }
        obj->flag0 = 0;
    }
    if ((path + strlen(path))[-1] != 'r') {
        return;
    }
    __clear(buf, 0x80);
    sprintf(buf, (const char*)&strDataAniStr_020f0118, path);
    handle = (void*)func_020429d4();
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(buf, handle, 0) != 0) {
        func_02047b40(obj, handle, extra);
    }
    BackgroundLoader::RemoveLockGlobal();
}
