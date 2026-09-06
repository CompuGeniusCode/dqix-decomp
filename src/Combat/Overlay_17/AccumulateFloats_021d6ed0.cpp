#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d75b8[8];
extern float data_ov017_021d837c[8];

// USA: func_ov017_021d6ed0  (semantic: AccumulateFloats_021d6ed0)
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6ed0(void) {
    float t;
    float a;
    float b;
    data_ov017_021d837c[5] = data_ov017_021d75b8[4] + (data_ov017_021d75b8[5] + (data_ov017_021d75b8[2] + data_ov017_021d75b8[3]));
    t = data_ov017_021d837c[4] + data_ov017_021d75b8[2];
    a = data_ov017_021d75b8[3];
    data_ov017_021d837c[3] = t;
    t = t + a;
    b = data_ov017_021d75b8[5];
    data_ov017_021d837c[1] = t;
    t = t + b;
    data_ov017_021d837c[2] = t;
}
