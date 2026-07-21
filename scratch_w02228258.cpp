#include <globaldefs.h>

struct RangeEntry_02228258 { unsigned short f0, f1, f2, f3; };
struct Stride8_02228258 { unsigned short v; unsigned char pad[6]; };

extern "C" int func_ov031_0223d49c(RangeEntry_02228258*);
ARM void SetField16IfMinusOne_02222e20(int v);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_022284ec(int);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
ARM int CheckMaskAgainstField32_0223d354(int mask);

extern RangeEntry_02228258 data_ov031_02248d8e;
extern Stride8_02228258 data_ov031_02248d9e[];
extern Stride8_02228258 data_ov031_02248da0[];
extern Stride8_02228258 data_ov031_02248da2[];
extern Stride8_02228258 data_ov031_02248da4[];
extern unsigned char data_ov031_02290c50;

// USA: func_ov031_02228258
extern "C" ARM void func_ov031_02228258(void) {
    unsigned int i = 0;
    RangeEntry_02228258* p = &data_ov031_02248d8e;
    do {
        if (func_ov031_0223d49c(p)) {
            SetField16IfMinusOne_02222e20(1);
            unsigned short a = data_ov031_02248d9e[(unsigned char)i].v;
            unsigned short b = data_ov031_02248da2[(unsigned char)i].v;
            unsigned short c = data_ov031_02248da0[(unsigned char)i].v;
            unsigned short d = data_ov031_02248da4[(unsigned char)i].v;
            data_ov031_02290c50 = i;
            func_ov031_022237dc(a, b, c, d);
            return;
        }
        i++;
        p++;
    } while (i < 2);
    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(1);
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_0223d394(0x40)) {
        func_ov031_022284ec(1);
        return;
    }
    if (func_ov031_0223d394(0x80)) {
        func_ov031_022284ec(3);
        return;
    }
    if (func_ov031_0223d394(0x20)) {
        func_ov031_022284ec(0);
        return;
    }
    if (func_ov031_0223d394(0x10)) {
        func_ov031_022284ec(2);
    }
}
