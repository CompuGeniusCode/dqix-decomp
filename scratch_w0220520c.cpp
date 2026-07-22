#include <globaldefs.h>

struct InitData020c7de4 { int a; int b; int c; int d; int e; int f; int g; int h; };
void InitStruct020c7de4(InitData020c7de4* s, int e, int f);
extern "C" int func_ov031_022051a8(void* a, void* b);
extern "C" int func_020c7ea0(void* data, int* out, int count);

struct CtxStruct0220520c {
    unsigned char pad0[8];
    void* field8;
    unsigned char pad1;
    signed char flagsByte;
};

// USA: func_ov031_0220520c
ARM void* func_ov031_0220520c(void* a0, CtxStruct0220520c* b0) {
    int resultB;
    int localA;
    if (b0->flagsByte == 1) {
        InitData020c7de4 s;
        InitStruct020c7de4(&s, (int)&localA, 1);
        b0->field8 = &s;
        func_ov031_022051a8(a0, b0);
        func_020c7ea0(&s, &resultB, 1);
    } else {
        b0->field8 = 0;
        resultB = func_ov031_022051a8(a0, b0);
    }
    return (void*)resultB;
}
