#include <globaldefs.h>

extern "C" int func_ov031_0223d49c(void*);
extern "C" int func_ov031_0223d5ac(void*);
void SetField16IfMinusOne_02222e20(int);
extern "C" void func_ov031_0222c8cc(void);
int CheckMaskAgainstField32_0223d354(int);
void SetField1e_0223521c(void);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_0222cad8(void);
int CheckMaskAgainstField36_0223d3d4(int);
extern "C" void func_ov031_0222ca64(void);
extern "C" int func_ov031_02236878(int);
extern "C" void func_ov031_0222c918(int);

struct Inner_0222bb58 {
    unsigned char pad0[0x38];
    void* field0x38;
    unsigned char pad1[0x14];
    signed char field0x50;
    unsigned char field0x51;
    unsigned char pad2[5];
    unsigned char field0x57;
    unsigned char pad3;
    unsigned char field0x59;
};
struct Base_0222bb58 {
    unsigned char field0;
    unsigned char pad[3];
    Inner_0222bb58* inner;
};
extern Base_0222bb58 data_ov031_02290c8c;
extern unsigned char data_ov031_022493b8;
extern unsigned char data_ov031_02248e5c;

// USA: func_ov031_0222bb58  (semantic: CheckRangeAndDispatchState_0222bb58)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222bb58(void) {
    if (data_ov031_02290c8c.inner->field0x38 != 0 || data_ov031_02290c8c.inner->field0x57 != 0) {
        return;
    }

    if (func_ov031_0223d49c(&data_ov031_022493b8)) {
        data_ov031_02290c8c.inner->field0x50 = -1;
        int i = 0;
        unsigned char* p = &data_ov031_02248e5c;
        do {
            if (func_ov031_0223d49c(p)) {
                if (i < 4) {
                    data_ov031_02290c8c.inner->field0x50 = (signed char)i;
                    break;
                }
                SetField16IfMinusOne_02222e20(1);
                data_ov031_02290c8c.field0 = (unsigned char)i;
                func_ov031_0222c8cc();
                return;
            }
            i++;
            p += 8;
        } while ((unsigned int)i < 5);
    }

    if (func_ov031_0223d5ac(&data_ov031_022493b8)) {
        unsigned char* p = &data_ov031_02248e5c;
        int j = 0;
        do {
            if (func_ov031_0223d5ac(p)) {
                signed char v50 = data_ov031_02290c8c.inner->field0x50;
                if (v50 != j) break;
                unsigned char v51 = data_ov031_02290c8c.inner->field0x51;
                if (j >= v51) {
                    func_ov031_02236878(9);
                    break;
                }
                SetField16IfMinusOne_02222e20(1);
                data_ov031_02290c8c.field0 = (unsigned char)j;
                func_ov031_0222c8cc();
                return;
            }
            j++;
            p += 8;
        } while (j < 4);
    }

    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(1);
        SetField1e_0223521c();
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_0223d394(0x200)) {
        func_ov031_0222cad8();
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x200)) {
        data_ov031_02290c8c.inner->field0x59 = 0;
        return;
    }
    if (func_ov031_0223d394(0x100)) {
        func_ov031_0222ca64();
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x100)) {
        data_ov031_02290c8c.inner->field0x59 = 0;
        return;
    }
    if (func_ov031_0223d394(0x40)) {
        func_ov031_0222c918(1);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x40)) {
        data_ov031_02290c8c.inner->field0x59 = 0;
        return;
    }
    if (func_ov031_0223d394(0x80)) {
        func_ov031_0222c918(3);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x80)) {
        data_ov031_02290c8c.inner->field0x59 = 0;
    }
}
