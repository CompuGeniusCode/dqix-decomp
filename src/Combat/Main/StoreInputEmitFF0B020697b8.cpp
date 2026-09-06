#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020696bc(int a, int* out, int c);
char* GetGlobalField0x1c020421a0();

struct Struct020697b8 { void* ptr; };

// USA: func_020697b8
ARM int StoreInputEmitFF0B020697b8(Struct020697b8* obj, int input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    GetGlobalField0x1c020421a0()[0x195e] = val;
    dst = obj->ptr;
    buf = 0xff0b;
    memcpy(dst, &buf, 2);
    return 2;
}
