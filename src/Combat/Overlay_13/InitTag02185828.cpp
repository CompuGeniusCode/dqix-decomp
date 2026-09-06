#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void func_ov013_02185900(void* obj, void* buf);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

extern int data_ov013_02187d94;

// USA: func_ov013_02185828
ARM void InitTag02185828(unsigned char* obj) {
    unsigned char flags6bc = obj[0x6bc];
    obj[0x6bc] = flags6bc & ~1;

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0x38), 0, 2);

    *(unsigned short*)(obj + 0xd8) = 0x20;
    *(unsigned short*)(obj + 0xda) = 9;
    *(unsigned short*)(obj + 0xdc) = 0;
    *(unsigned short*)(obj + 0xde) = 0xf;
    *(unsigned short*)(obj + 0xe0) = 0xc;
    *(unsigned short*)(obj + 0xe2) = 0xa;
    *(unsigned short*)(obj + 0xe4) = 0xc;
    *(unsigned short*)(obj + 0xe6) = 0x14;
    obj[0xe9] = 2;

    if (obj[0x640] != 0) obj[0xed] = 0;
    else obj[0xed] = 1;

    obj[0x63a] = 0;

    memset(*(void**)(obj + 0x658), 0, 0x960);

    func_ov013_02185900(obj, *(void**)(obj + 0x658));

    func_0205d304(obj + 0x38, *(void**)(obj + 0x658), 0, 0, 0, 1, (int)&data_ov013_02187d94, 1);
}
