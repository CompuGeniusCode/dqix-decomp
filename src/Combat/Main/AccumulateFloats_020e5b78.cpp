#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020efaa8[8];
extern float data_02104b18[8];

// USA: func_020e5b78
extern "C" __declspec(initcode) ARM void AccumulateFloats_020e5b78(void) {
    float t;
    float a;
    float b;
    data_02104b18[3] = data_020efaa8[1] + (data_020efaa8[2] + (data_020efaa8[3] + data_020efaa8[0]));
    t = data_02104b18[1] + data_020efaa8[3];
    a = data_020efaa8[0];
    data_02104b18[4] = t;
    t = t + a;
    b = data_020efaa8[2];
    data_02104b18[2] = t;
    t = t + b;
    data_02104b18[0] = t;
}
