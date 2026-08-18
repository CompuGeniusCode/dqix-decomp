#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020ef378[8];
extern float data_020fdc20[8];

// USA: func_020e5a74
extern "C" __declspec(initcode) ARM void AccumulateFloats_020e5a74(void) {
    float t;
    float a;
    float b;
    data_020fdc20[7] = data_020ef378[1] + (data_020ef378[2] + (data_020ef378[0] + data_020ef378[3]));
    t = data_020fdc20[6] + data_020ef378[0];
    a = data_020ef378[3];
    data_020fdc20[5] = t;
    t = t + a;
    b = data_020ef378[2];
    data_020fdc20[4] = t;
    t = t + b;
    data_020fdc20[3] = t;
}
