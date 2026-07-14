#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(int a, int b);

struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);

struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);

extern "C" void func_020301c8(int a, int b);
extern "C" void func_020145a8(void* obj);

int DecompressAndInitAt0x10c_02014414(char* obj, const void* src);
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
ARM int PollAndDecompressResource02014c04(Ctx02014c04* ctx) {
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
    key = GetData02104304Field4();
    if (!func_0202fdd0(key, ctx->handle)) {
        return 0;
    }
    result = LookupListValueByKey((struct List0202fe68*)key, ctx->handle);
    if (result != 2) {
        func_020301c8(key, ctx->handle);
        ctx->handle = -1;
        func_020145a8(ctx);
        return 1;
    }
    GetListEntryValues0202fec8((struct List0202fec8*)key, ctx->handle, &val1, &val2);
    sprintf(sprintfBuf, data_020ef1d6, ctx->pathBuf);
    if (!GetFileInNarc((void*)val1, sprintfBuf, (const void**)&fileData, &fileSize, 0)) {
        func_020301c8(key, ctx->handle);
        ctx->handle = -1;
        func_020145a8(ctx);
        return 1;
    }
    ((DecompressAndInitFn3)DecompressAndInitAt0x10c_02014414)((char*)ctx, fileData, fileSize);
    func_020301c8(key, ctx->handle);
    ctx->handle = -1;
    func_020145a8(ctx);
    return 1;
}
