#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct StructA_021838c8 {
    float f0;
    float f4;
    float f8;
    float fc;
};

struct StructB_02184220 {
    char pad0[8];
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
};

extern struct StructA_021838c8 data_ov000_021838c8;
extern struct StructB_02184220 data_ov000_02184220;

// USA: func_ov000_02183710  (semantic: UpdateAccumulatorChain_02183710)
extern "C" __declspec(initcode) ARM void func_ov000_02183710(void) {
    float sum1a = data_ov000_021838c8.f0 + data_ov000_021838c8.f4;
    float sum1b = data_ov000_021838c8.fc + sum1a;
    float sum1 = data_ov000_021838c8.f8 + sum1b;
    data_ov000_02184220.f18 = sum1;

    float t1 = data_ov000_02184220.f14 + data_ov000_021838c8.f0;
    float a_f4 = data_ov000_021838c8.f4;
    data_ov000_02184220.f10 = t1;
    float t2 = t1 + a_f4;
    float a_fc = data_ov000_021838c8.fc;
    data_ov000_02184220.fc = t2;
    float t3 = t2 + a_fc;
    data_ov000_02184220.f8 = t3;
}
