#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
extern int GetFieldByKey020e0434(struct Container020e0310*, int);

extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

// USA: func_ov023_021d9da4
ARM void SetupTag021d9da4(void* objRaw) {
    char* obj = (char*)objRaw;
    char* tag = obj + 0x2b4;
    *(unsigned short*)(tag + 0xa0) = 0xa;
    *(unsigned short*)(tag + 0xa2) = 2;
    *(unsigned short*)(tag + 0xa4) = 0xb;
    *(unsigned short*)(tag + 0xa6) = 4;
    *(unsigned short*)(tag + 0xa8) = 0;
    *(unsigned short*)(tag + 0xaa) = 2;
    *(unsigned short*)(tag + 0xac) = 0x11;
    *(unsigned short*)(tag + 0xae) = 0x10;
    tag[0xb1] = 3;
    tag[0xb7] = 0xa;
    tag[0xb5] = 1;
    tag[0xb6] = 1;
    void* buf = *(void**)(obj + 0xf8);
    memset(buf, 0, 0x960);
    int fmt = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xe0), 0x4274);
    sprintf((char*)buf, (const char*)(long)fmt);
    func_0205d304(tag, buf, 0, 0, 0, 0, 0, 0);
}
