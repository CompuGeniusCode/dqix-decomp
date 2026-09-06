#include <globaldefs.h>

struct Triple02227cb0 { unsigned int v[3]; };
extern Triple02227cb0* data_ov031_02290c48;

extern "C" void* func_ov031_0223cf4c(int size, int align);
void CopyTriple_02227cb0(Triple02227cb0* src);
int TailCallWith32_02227cc8(int a);
extern "C" void func_ov031_02227cd8(void);
extern "C" void func_020c9be0(void);
extern void SleepCurrentContext(unsigned int milliseconds);

typedef void (*CopyFn02227b38)(void*);
typedef int (*TailFn02227b38)(int);
typedef void (*CbFn02227b38)(void);

extern "C" int func_ov031_02222928(int a, int b, CopyFn02227b38 cb1, TailFn02227b38 cb2, CbFn02227b38 cb3, int size);

// USA: func_ov031_02227b38
extern "C" ARM void func_ov031_02227b38(void) {
    data_ov031_02290c48 = (Triple02227cb0*)func_ov031_0223cf4c(0xc, 0xc - 0x10);
    int r = func_ov031_02222928(0xf, 0x40, (CopyFn02227b38)CopyTriple_02227cb0, (TailFn02227b38)TailCallWith32_02227cc8, func_ov031_02227cd8, 0x800);
    if (r != 1) {
        func_020c9be0();
    }
    SleepCurrentContext(0xa);
}
