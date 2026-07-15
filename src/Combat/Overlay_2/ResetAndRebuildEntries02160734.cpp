#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_021607cc(void* obj, void* ptr, int flag);
extern "C" void func_0205d304(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);

// USA: func_ov002_02160734
ARM void ResetAndRebuildEntries02160734(unsigned char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0x2c8 + 0xc00), 0, 2);

    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1000 + 0xbd0), 0, 0x960);

    func_ov002_021607cc(obj, *(void**)(obj + 0x1000 + 0xbd0), 0);

    func_0205d304(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + 0xbd0), 0, 0, 0, 1, 0, 0);
}
