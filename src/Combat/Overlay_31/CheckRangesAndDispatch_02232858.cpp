#include <globaldefs.h>

struct RangeParam_02232858 { unsigned short f0, f1, f2, f3; };

extern "C" int func_ov031_0223d49c(RangeParam_02232858*);
extern "C" void func_ov031_02232ce8(void);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_02232d64(int);
void SetField16IfMinusOne_02222e20(int);
int CheckMaskAgainstField32_0223d354(int);

extern RangeParam_02232858 data_ov031_0224909a[7];
extern unsigned char data_ov031_02290cc0;

// USA: func_ov031_02232858  (semantic: CheckRangesAndDispatch_02232858)
extern "C" ARM void func_ov031_02232858(void) {
    unsigned int i = 0;
    RangeParam_02232858* p = data_ov031_0224909a;
    do {
        if (func_ov031_0223d49c(p)) {
            SetField16IfMinusOne_02222e20(1);
            data_ov031_02290cc0 = i;
            func_ov031_02232ce8();
            return;
        }
        i++;
        p++;
    } while (i < 7);
    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(1);
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_0223d394(0x40)) {
        func_ov031_02232d64(1);
        return;
    }
    if (func_ov031_0223d394(0x80)) {
        func_ov031_02232d64(3);
        return;
    }
    if (func_ov031_0223d394(0x20)) {
        func_ov031_02232d64(0);
        return;
    }
    if (func_ov031_0223d394(0x10)) {
        func_ov031_02232d64(2);
    }
}
