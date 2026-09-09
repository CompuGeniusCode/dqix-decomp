#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" void func_020d3c84(struct HandlerSlotArray020d3c84*, struct StreamHeader*, int);
#include "std_library_functions.h"

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

extern int strDataBinAttnpcGp2;
extern int strAttnpcLgBin;

struct Obj020d3c28 {
    unsigned char pad[0xb4];
    int fieldB4;
};

// USA: func_020d3c28
// The file paths in this function's literal pool are "data/bin/attnpc.gp2" and "attnpc_<LG>.bin".
extern "C" ARM void RunAttnpcScript(struct Obj020d3c28* obj) {
    int localVar;
    int result;
    memset(obj, 0, 0xb4);
    obj->fieldB4 = 0;
    BackgroundLoader::AddLockGlobal();
    result = (int)ExtractFileFromGP2((const char*)&strDataBinAttnpcGp2, (const char*)&strAttnpcLgBin, (unsigned int*)&localVar);
    if (result != 0) {
        func_020d3c84((struct HandlerSlotArray020d3c84*)(obj), (struct StreamHeader*)(result), (int)(localVar));
    }
    BackgroundLoader::RemoveLockGlobal();
}
