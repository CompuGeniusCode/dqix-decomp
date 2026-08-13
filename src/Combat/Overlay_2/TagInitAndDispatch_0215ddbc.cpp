#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_02157030(void* obj, unsigned char flag, short* out16, short* out14, short* out12, short* out10);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215be00(void* obj, int a1, int a2, int a3);
extern "C" void func_ov004_0215de9c(void* obj, void* buf, int zero);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov002_0215ddbc  (semantic: TagInitAndDispatch_0215ddbc)
extern "C" ARM void func_ov002_0215ddbc(unsigned char* obj) {
    short vR2 = 0, vR3 = 0, vA8 = 1, vA9 = 1;
    unsigned char flagByte = (unsigned char)*(int*)(obj + 0x1000 + 0xbb8);
    func_ov002_02157030(obj, flagByte, &vR2, &vR3, &vA8, &vA9);
    vR2 = vR2 + vA8;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0x2c8 + 0xc00), 0, 3);
    func_ov002_0215be00(obj, 0xd, vR2, vR3);
    memset(*(void**)(obj + 0x1000 + 0xbd0), 0, 0x960);
    func_ov004_0215de9c(obj, *(void**)(obj + 0x1000 + 0xbd0), 0);
    func_0205d304(obj + 0x2c8 + 0xc00, *(void**)(obj + 0x1000 + 0xbd0), 0, 0, 0, 1, 0, 0);
}
