#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d79c0[8];
extern float data_ov017_021d83d4[8];

// USA: func_ov017_021d6fe0  (semantic: AccumulateFloats_021d6fe0)
extern "C" __declspec(initcode) ARM void func_ov017_021d6fe0(void) {
    float t;
    float a;
    float b;
    data_ov017_021d83d4[5] = data_ov017_021d79c0[1] + (data_ov017_021d79c0[2] + (data_ov017_021d79c0[0] + data_ov017_021d79c0[3]));
    t = data_ov017_021d83d4[4] + data_ov017_021d79c0[0];
    a = data_ov017_021d79c0[3];
    data_ov017_021d83d4[3] = t;
    t = t + a;
    b = data_ov017_021d79c0[2];
    data_ov017_021d83d4[2] = t;
    t = t + b;
    data_ov017_021d83d4[1] = t;
}
