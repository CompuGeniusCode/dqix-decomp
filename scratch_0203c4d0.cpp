#include <globaldefs.h>

struct Source0203c05c {
    char pad[0x22];
    short f22;
};

struct Entry0203c05c {
    unsigned int w;
    unsigned short h;
    unsigned short pad;
};

extern "C" void _Z26BuildPackedEntries0203c05cP14Source0203c05cP13Entry0203c05ciiii(
    struct Source0203c05c* p, struct Entry0203c05c* out, int a3, int a4, int a5, int a6);

// USA: func_0203c4d0
ARM void func_0203c4d0(char* self, short index, int a3, int a4, int p5, unsigned int p6) {
    if (index < 0) return;
    if (*(struct Entry0203c05c**)self == 0) return;
    unsigned int stack0 = p5;
    unsigned int combined = p6 + (*(unsigned int*)(self + 0x50c) >> 5);
    unsigned int stack1 = combined & 0xf;
    struct Source0203c05c* p = (struct Source0203c05c*)(self + 4 + index * 0x28);
    struct Entry0203c05c* out = *(struct Entry0203c05c**)self + *(unsigned short*)(self + 0x500 + 0x10);
    _Z26BuildPackedEntries0203c05cP14Source0203c05cP13Entry0203c05ciiii(p, out, a3, a4, stack0, stack1);
    unsigned short idx510 = *(unsigned short*)(self + 0x500 + 0x10);
    idx510 += 4;
    *(unsigned short*)(self + 0x500 + 0x10) = idx510;
    idx510 = *(unsigned short*)(self + 0x500 + 0x10);
    idx510 &= 0x7f;
    *(unsigned short*)(self + 0x500 + 0x10) = idx510;
}
