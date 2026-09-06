#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov025_021ef464[8];
extern float data_ov025_021ef988[8];

// USA: func_ov025_021ef288  (semantic: AccumulateFloats_021ef288)
extern "C" __declspec(initcode) ARM void __sinit_ov025_021ef288(void) {
    float t;
    float a;
    float b;
    data_ov025_021ef988[0] = data_ov025_021ef464[1] + (data_ov025_021ef464[3] + (data_ov025_021ef464[2] + data_ov025_021ef464[4]));
    t = data_ov025_021ef988[5] + data_ov025_021ef464[2];
    a = data_ov025_021ef464[4];
    data_ov025_021ef988[6] = t;
    t = t + a;
    b = data_ov025_021ef464[3];
    data_ov025_021ef988[1] = t;
    t = t + b;
    data_ov025_021ef988[4] = t;
}
