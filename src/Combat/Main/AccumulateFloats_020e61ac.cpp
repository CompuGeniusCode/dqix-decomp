#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0ec8[8];
extern float data_02108e60[8];

// USA: func_020e61ac
extern "C" __declspec(initcode) ARM void AccumulateFloats_020e61ac(void) {
    float t;
    float a;
    float b;
    data_02108e60[5] = data_020f0ec8[0] + (data_020f0ec8[1] + (data_020f0ec8[3] + data_020f0ec8[2]));
    t = data_02108e60[4] + data_020f0ec8[3];
    a = data_020f0ec8[2];
    data_02108e60[3] = t;
    t = t + a;
    b = data_020f0ec8[1];
    data_02108e60[2] = t;
    t = t + b;
    data_02108e60[1] = t;
}
