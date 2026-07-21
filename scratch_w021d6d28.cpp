#include <globaldefs.h>

struct Src021d6d28 {
    float f0;
    int f4;
    int f8;
    float fc;
    float f10;
    float f14;
};
struct Dst021d6d28 {
    char pad[8];
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
};

extern struct Src021d6d28 data_ov017_021d7340;
extern struct Dst021d6d28 data_ov017_021d82e0;

// USA: func_ov017_021d6d28
extern "C" ARM void func_ov017_021d6d28(void) {
    float t1 = data_ov017_021d7340.fc + data_ov017_021d7340.f10;
    float t2 = data_ov017_021d7340.f0 + t1;
    float t3 = data_ov017_021d7340.f14 + t2;
    data_ov017_021d82e0.f18 = t3;

    float t4 = data_ov017_021d82e0.f14 + data_ov017_021d7340.fc;
    data_ov017_021d82e0.f10 = t4;

    float t5 = t4 + data_ov017_021d7340.f10;
    data_ov017_021d82e0.f8 = t5;

    float t6 = t5 + data_ov017_021d7340.f0;
    data_ov017_021d82e0.fc = t6;

    data_ov017_021d7340.f4 = data_ov017_021d7340.f8 + 0xb;
}
