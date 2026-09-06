#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
void BuildStatusString_0215c178(void* a0, char* dst, int flag);
extern "C" void func_0205d304(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);

// USA: func_ov002_0215c0f8  (semantic: InitBattleTag0215c0f8)
extern "C" ARM void func_ov002_0215c0f8(unsigned char* obj) {
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1000 + 0xbd0), 0, 0x960);

    BuildStatusString_0215c178(obj, (char*)*(void**)(obj + 0x1000 + 0xbd0), 0);

    func_0205d304(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + 0xbd0), 0, 1, 0, 1, 0, 0);
}
