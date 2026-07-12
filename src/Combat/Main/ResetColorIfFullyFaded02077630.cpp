#include <globaldefs.h>

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char lo3 : 3;
    unsigned char hi5 : 5;
};
int GetField0x40Bits3To7(struct Bits40_37464* obj);

void CopyVec3(int* a, int* b);

struct Struct020372b8 {
    char pad[0x40];
    unsigned char lo3 : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short f70;
};
void ScaleColorChannel020372b8(struct Struct020372b8* obj, int a, int b);

void TrySetMode02076ccc(void*, int);

// USA: func_02077630
ARM void ResetColorIfFullyFaded02077630(void* obj) {
    if (GetField0x40Bits3To7((struct Bits40_37464*)obj) != 0 && GetField0x40Bits3To7((struct Bits40_37464*)obj) != 0x1f) {
        return;
    }
    if (GetField0x40Bits3To7((struct Bits40_37464*)obj) == 0) {
        CopyVec3((int*)((char*)obj + 0x44), (int*)((char*)obj + 0x158));
        ScaleColorChannel020372b8((struct Struct020372b8*)obj, 0x1f, 0xfa);
    }
    if (GetField0x40Bits3To7((struct Bits40_37464*)obj) != 0x1f) {
        return;
    }
    TrySetMode02076ccc(obj, 1);
}
