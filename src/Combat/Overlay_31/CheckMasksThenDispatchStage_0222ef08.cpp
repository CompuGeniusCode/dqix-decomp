#include <globaldefs.h>

struct Inner0222ef08 {
    unsigned char pad0[0x38];
    int field38;
    unsigned char pad1[4];
    unsigned char field40;
    unsigned char pad2[4];
    unsigned char field45;
    unsigned char pad3;
    unsigned char field47;
};
struct HolderData0222ef08 {
    unsigned char idx;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned char pad1[2];
    struct Inner0222ef08* ptr;
};
extern struct HolderData0222ef08 data_ov031_02290ca0;

extern "C" int func_ov031_0222f188(void);
extern "C" void func_ov031_0222f20c(int idx);
int CheckMaskAgainstField32_0223d354(int mask);
int CheckMaskAgainstField36_0223d3d4(int mask);
extern "C" int func_ov031_02236878(int index);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222f68c(void);
extern "C" int func_ov031_0223d394(int mask);
void *CallWithZeroExtra_0223e218(void *a, void *b, void *c, int d);
extern "C" void func_ov031_022306d4(void);
extern "C" void func_ov031_0223060c(void);
extern "C" void func_ov031_022309b4(int v);

// USA: func_ov031_0222ef08
#pragma optimize_for_size off
extern "C" ARM void CheckMasksThenDispatchStage_0222ef08(void) {
    if (data_ov031_02290ca0.ptr->field38 != 0 || data_ov031_02290ca0.ptr->field45 != 0) return;
    if (func_ov031_0222f188() != 0) return;
    if (CheckMaskAgainstField32_0223d354(1) != 0) {
        func_ov031_0222f20c(data_ov031_02290ca0.idx);
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2) != 0) {
        func_ov031_02236878(7);
        data_ov031_02290ca0.ptr->field40 = 0xd;
        SetField_022274c0_022274c0((int)func_ov031_0222f68c);
        return;
    }
    if (func_ov031_0223d394(0x200) != 0) {
        if (data_ov031_02290ca0.field4 == 0x91) {
            if (data_ov031_02290ca0.ptr->field47 != 0) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.ptr->field47 = 1;
            return;
        }
        func_ov031_02236878(0x13);
        data_ov031_02290ca0.ptr->field38 = (int)CallWithZeroExtra_0223e218((void*)0, (void*)func_ov031_022306d4, (void*)0, 0x78);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x200) != 0) {
        data_ov031_02290ca0.ptr->field47 = 0;
        return;
    }
    if (func_ov031_0223d394(0x100) != 0) {
        if (data_ov031_02290ca0.field4 == 0) {
            if (data_ov031_02290ca0.ptr->field47 != 0) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.ptr->field47 = 1;
            return;
        }
        func_ov031_02236878(0x13);
        data_ov031_02290ca0.ptr->field38 = (int)CallWithZeroExtra_0223e218((void*)0, (void*)func_ov031_0223060c, (void*)0, 0x78);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x100) != 0) {
        data_ov031_02290ca0.ptr->field47 = 0;
        return;
    }
    if (func_ov031_0223d394(0x40) != 0) {
        func_ov031_022309b4(1);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x40) != 0) {
        data_ov031_02290ca0.ptr->field47 = 0;
        return;
    }
    if (func_ov031_0223d394(0x80) != 0) {
        func_ov031_022309b4(3);
        return;
    }
    if (CheckMaskAgainstField36_0223d3d4(0x80) != 0) {
        data_ov031_02290ca0.ptr->field47 = 0;
        return;
    }
    if (func_ov031_0223d394(0x20) != 0) {
        func_ov031_022309b4(0);
        return;
    }
    if (func_ov031_0223d394(0x10) != 0) {
        func_ov031_022309b4(2);
    }
}
