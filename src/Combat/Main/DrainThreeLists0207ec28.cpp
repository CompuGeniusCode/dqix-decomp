#include <globaldefs.h>

extern "C" void func_020b2dd4(void* p, int node);

struct List0207ec28 {
    char pad0[8];
    int field8;
    int pad_c;
    int field10;
    int pad_14;
    int field18;
};

// USA: func_0207ec28
ARM void DrainThreeLists0207ec28(struct List0207ec28* p) {
    while (p->field8 != 0) func_020b2dd4(p, p->field8);
    while (p->field10 != 0) func_020b2dd4(p, p->field10);
    while (p->field18 != 0) func_020b2dd4(p, p->field18);
}
