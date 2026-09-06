#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* dst, int size);
extern "C" int func_02001aec(const void* a, const void* b, unsigned int length);
extern "C" int func_0205a658(void* obj, void* data, int arg2, int arg3);
extern "C" int func_0205a984(void* obj, void* data, int arg2, int arg3);
extern "C" int _Z27ValidateAndDispatchResourceP11Obj0205aaf8Pvi(void* obj, void* data, int arg2);
extern "C" int func_0205ab78(void* obj, void* data, int arg2);

extern char data_020f0504[];
extern char data_020f0509[];
extern char data_020f050e[];
extern char data_020f0513[];

// USA: func_0205a528
extern "C" ARM int func_0205a528(void* obj, void* data, int arg2, int arg3) {
    char magic[5];

    __clear(magic, 5);
    memcpy(magic, data, 4);

    if (func_02001aec(magic, data_020f0504, 4) == 0 && func_0205a658(obj, data, arg2, arg3)) {
        return 1;
    } else if (func_02001aec(magic, data_020f0509, 4) == 0) {
        if (func_0205a984(obj, data, arg2, arg3)) {
            return 1;
        }
    } else if (func_02001aec(magic, data_020f050e, 4) == 0) {
        if (_Z27ValidateAndDispatchResourceP11Obj0205aaf8Pvi(obj, data, arg2)) {
            return 1;
        }
    } else if (func_02001aec(magic, data_020f0513, 4) == 0) {
        if (func_0205ab78(obj, data, arg2)) {
            return 1;
        }
    }
    return 0;
}
