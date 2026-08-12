#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
ARM void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" int func_020420e8(char* str, int id);
extern "C" void func_ov003_02169a84(char* base, char* dst, int flag);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov003_0216997c
extern "C" ARM void func_ov003_0216997c(void* objRaw) {
    char* obj = (char*)objRaw;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xe4), 0, 2);

    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x64);
    short maxLen = 0;
    for (int i = 0; i < 3; i++) {
        int name = GetFieldByKey020e0434(c, (short)i);
        short len = (short)func_020420e8((char*)name, 0);
        if (maxLen < len) maxLen = len;
    }

    int v = ((maxLen + 0x18) << 13) >> 16;
    *(short*)(obj + 0x184) = v;
    *(short*)(obj + 0x186) = 6;
    *(short*)(obj + 0x188) = 0x1f - v;
    *(short*)(obj + 0x18a) = 2;
    *(short*)(obj + 0x18c) = 0xc;
    *(short*)(obj + 0x18e) = 8;
    *(short*)(obj + 0x190) = 0xa;
    *(short*)(obj + 0x192) = 0xe;

    *(unsigned char*)(obj + 0x195) = 1;
    *(unsigned char*)(obj + 0x199) = 1;
    *(unsigned char*)(obj + 0x4ed) = 0;

    memset(*(char**)(obj + 0x7c), 0, 0x960);
    func_ov003_02169a84(obj, *(char**)(obj + 0x7c), 0);
    func_0205d304(obj + 0xe4, *(char**)(obj + 0x7c), 0, 1, 0, 1, 0, 0);
}
