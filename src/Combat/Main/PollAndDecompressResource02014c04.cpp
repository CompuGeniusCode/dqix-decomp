#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"


struct List0202fe68;

struct List0202fec8;

extern "C" void _ZN6Zone3D11LoadMapAMDJEv(void* obj);

extern "C" int _ZN6Zone3D15ProcessBATSFileEPKvj(char* obj, const void* src);
// The real function only reads (obj, src); casting through a 3-arg function
// pointer type reproduces the target's dead load of the file size before the call.
typedef int (*DecompressAndInitFn3)(char*, const void*, unsigned int);

extern char data_020ef1d6[];

struct Ctx02014c04 {
    char pad0[0xc];
    char pathBuf[0x440 - 0xc];
    int handle; // 0x440
};

// USA: func_02014c04
extern "C" ARM int _ZN6Zone3D14UnpackATS_AMBLEv(Ctx02014c04* ctx) {
    int key;
    int result;
    int val1;
    int val2;
    void* fileData;
    unsigned int fileSize;
    char sprintfBuf[0x28];

    if (ctx->handle < 0) {
        return 1;
    }
    key = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(key))->GetTaskStatus((int)(ctx->handle))) {
        return 0;
    }
    result = ((BackgroundLoader*)((struct List0202fe68*)key))->GetDetailedTaskStatus((int)(ctx->handle));
    if (result != 2) {
        ((BackgroundLoader*)(key))->RemoveTask((int)(ctx->handle));
        ctx->handle = -1;
        _ZN6Zone3D11LoadMapAMDJEv(ctx);
        return 1;
    }
    ((BackgroundLoader*)((struct List0202fec8*)key))->GetLoadedFileByID((int)(ctx->handle), (void**)(&val1), (unsigned int*)(&val2));
    sprintf(sprintfBuf, data_020ef1d6, ctx->pathBuf);
    if (!GetFileInNarc((void*)val1, sprintfBuf, (const void**)&fileData, &fileSize, 0)) {
        ((BackgroundLoader*)(key))->RemoveTask((int)(ctx->handle));
        ctx->handle = -1;
        _ZN6Zone3D11LoadMapAMDJEv(ctx);
        return 1;
    }
    ((DecompressAndInitFn3)_ZN6Zone3D15ProcessBATSFileEPKvj)((char*)ctx, fileData, fileSize);
    ((BackgroundLoader*)(key))->RemoveTask((int)(ctx->handle));
    ctx->handle = -1;
    _ZN6Zone3D11LoadMapAMDJEv(ctx);
    return 1;
}
