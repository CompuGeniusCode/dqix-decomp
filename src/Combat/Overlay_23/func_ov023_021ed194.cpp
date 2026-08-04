#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021ed254(void* obj, void* buf);
extern "C" ARM void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov023_021ed194
extern "C" ARM void func_ov023_021ed194(char* obj) {
    struct Bits0205de24_021ed194 { unsigned char low4 : 4; unsigned char high4 : 4; };
    unsigned char keyLow = ((struct Bits0205de24_021ed194*)(obj + 0xa0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x14;
    *(unsigned short*)(obj + 0x166) = 3;
    *(unsigned short*)(obj + 0x168) = 6;
    *(unsigned short*)(obj + 0x16a) = 5;
    *(unsigned short*)(obj + 0x16c) = 0;
    *(unsigned short*)(obj + 0x16e) = 6;
    *(unsigned short*)(obj + 0x170) = 0xc;
    *(unsigned short*)(obj + 0x172) = 0xe;
    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 0;
    *(unsigned char*)(obj + 0x179) = 1;
    *(unsigned char*)(obj + 0x17a) = 1;

    memset(*(void**)(obj + 0x1c), 0, 0x960);

    func_ov023_021ed254(obj, *(void**)(obj + 0x1c));

    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
}
