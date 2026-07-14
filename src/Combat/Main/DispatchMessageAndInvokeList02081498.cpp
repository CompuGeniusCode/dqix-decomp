#include <globaldefs.h>

struct Params02081498 {
    char pad0[0xa];
    short f_a;
    short f_c;
    short f_e;
    short f_10;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    char pad1[2];
    unsigned char f_15;
};

extern "C" void func_0204f174(void* target, short a, short b, short c, int d, int e, int f, int g, int h);
extern "C" void func_0204fae8(void* target);

struct ShortList02081530 {
    char pad[4];
    short* entries;
    char pad2[0x14 - 8];
    unsigned char count;
};
void ForEachShortInvoke0204f3bc(void* unused, void* ctx, struct ShortList02081530* list);

// USA: func_02081498
ARM void DispatchMessageAndInvokeList02081498(void* obj, void* ctx, struct Params02081498* p) {
    int hasBit1 = (p->f_15 & 2) != 0;
    func_0204f174(ctx, p->f_a, p->f_c, p->f_e, p->f_10, p->lowNibble, p->highNibble, hasBit1, 0);
    if (p->f_15 & 1) {
        func_0204fae8(ctx);
    }
    ForEachShortInvoke0204f3bc(obj, ctx, (struct ShortList02081530*)p);
}
