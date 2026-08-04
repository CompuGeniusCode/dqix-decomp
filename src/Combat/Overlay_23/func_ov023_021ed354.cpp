#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
int GetGlobalField0x1c020421a0(void);
extern "C" ARM void func_02046608(void* a, int b, int c, void* d, int e, int f, int g);
extern "C" ARM void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov023_021ed354
extern "C" ARM void func_ov023_021ed354(char* obj) {
    struct Bits0205de24 { unsigned char low4 : 4; unsigned char high4 : 4; };
    unsigned char keyLow = ((Bits0205de24*)(obj + 0xa0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x1e;
    *(unsigned short*)(obj + 0x166) = 0xa;
    *(unsigned short*)(obj + 0x168) = 0x1;
    *(unsigned short*)(obj + 0x16a) = 0xd;
    *(unsigned short*)(obj + 0x16c) = 0x7;
    *(unsigned short*)(obj + 0x16e) = 0x8;
    *(unsigned short*)(obj + 0x170) = 0xc;
    *(unsigned short*)(obj + 0x172) = 0xc;
    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 0x1;
    *(unsigned char*)(obj + 0x179) = 0;
    *(unsigned char*)(obj + 0x17a) = 0;

    void* g = (void*)GetGlobalField0x1c020421a0();
    memset(*(void**)(obj + 0x1c), 0, 0x960);

    void* base = *(void**)(obj + 0x20);
    unsigned char idx = *(unsigned char*)(obj + 0x28);
    int c = *(int*)((char*)base + idx * 0x244 + 4);
    func_02046608(g, 1, c, *(void**)(obj + 0x1c), 0xe3, 0, 1);

    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
}
